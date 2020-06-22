#include <ntddk.h>

typedef struct { PDEVICE_OBJECT LowerKbdDevice; } DEVICE_EXTENSION, *PDEVICE_EXTENSION;

typedef struct _KEYBOARD_INPUT_DATA {
	USHORT UnitId;
	USHORT MakeCode;
	USHORT Flags;
	USHORT Reserved;
	ULONG ExtraInformation;
} KEYBOARD_INPUT_DATA, *PKEYBOARD_INPUT_DATA;

#define programsExtraInfo 0x77196848

PDEVICE_OBJECT myKbdDevice = NULL;
ULONG pendingCount = 0;


VOID DriverUnload(PDRIVER_OBJECT DriverObject) {
	LARGE_INTEGER interval = { 0 };
	PDEVICE_OBJECT DeviceObject = DriverObject->DeviceObject;
	interval.QuadPart = -10 * 1000 * 1000;
	IoDetachDevice(((PDEVICE_EXTENSION)DeviceObject->DeviceExtension)->LowerKbdDevice);
	while (pendingCount) {
		KeDelayExecutionThread(KernelMode, FALSE, &interval);
	};
	IoDeleteDevice(myKbdDevice);
}


NTSTATUS DispatchPass(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
	IoCopyCurrentIrpStackLocationToNext(Irp);
	return IoCallDriver(((PDEVICE_EXTENSION)DeviceObject->DeviceExtension)->LowerKbdDevice, Irp);
}


NTSTATUS ReadComplete(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
	PKEYBOARD_INPUT_DATA Keys = (PKEYBOARD_INPUT_DATA)Irp->AssociatedIrp.SystemBuffer;
	unsigned int structnum = Irp->IoStatus.Information / sizeof(KEYBOARD_INPUT_DATA);

	if (Irp->IoStatus.Status == STATUS_SUCCESS) {
		for (unsigned int i = 0; i < structnum; i++) {
			Keys[i].ExtraInformation = programsExtraInfo;
		}
	}

	if (Irp->PendingReturned) {
		IoMarkIrpPending(Irp);
	}

	pendingCount--;

	return Irp->IoStatus.Status;
}


NTSTATUS DispatchRead(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
	IoCopyCurrentIrpStackLocationToNext(Irp);

	IoSetCompletionRoutine(Irp, ReadComplete, NULL, TRUE, TRUE, TRUE);

	pendingCount++;

	return IoCallDriver(((PDEVICE_EXTENSION)DeviceObject->DeviceExtension)->LowerKbdDevice, Irp);
}


NTSTATUS MyAttachDevice(PDRIVER_OBJECT DriverObject) {
	NTSTATUS status;
	UNICODE_STRING TargetDevice = RTL_CONSTANT_STRING(L"\\Device\\KeyboardClass0");
	status = IoCreateDevice(DriverObject, sizeof(DEVICE_EXTENSION), NULL, FILE_DEVICE_KEYBOARD, 0, FALSE, &myKbdDevice);
	if (!NT_SUCCESS(status)) {
		return status;
	}

	myKbdDevice->Flags |= DO_BUFFERED_IO;
	myKbdDevice->Flags &= ~DO_DEVICE_INITIALIZING;

	RtlZeroMemory(myKbdDevice->DeviceExtension, sizeof(DEVICE_EXTENSION));

	status = IoAttachDevice(myKbdDevice, &TargetDevice, &((PDEVICE_EXTENSION)myKbdDevice->DeviceExtension)->LowerKbdDevice);
	if (!NT_SUCCESS(status)) {
		IoDeleteDevice(myKbdDevice);
		return status;
	}
	return STATUS_SUCCESS;
}

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
	DriverObject->DriverUnload = DriverUnload;

	for (unsigned int i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++) {
		DriverObject->MajorFunction[i] = DispatchPass;
	}

	DriverObject->MajorFunction[IRP_MJ_READ] = DispatchRead;

	while (!NT_SUCCESS(MyAttachDevice(DriverObject))) {
		
	}
	return 0;
}
