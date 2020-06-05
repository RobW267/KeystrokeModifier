#include "main.h"
#include "keyboardGeometry.h"
#include <winuser.h>
#include <ctime>

KeyboardGeometry app;
HHOOK hKeyboardHook;

#define programsExtraInfo 0x77196848

LRESULT WINAPI HookedCode(int nCode, WPARAM wParam, LPARAM lParam)
{
	char currentDirectory[260];
	char * workFullPath;


	if ((nCode == HC_ACTION))
	{
		KBDLLHOOKSTRUCT* hooked_key = ((KBDLLHOOKSTRUCT*)lParam);
		unsigned char map;
		switch (wParam) {
		case WM_SYSKEYDOWN:
		case WM_KEYDOWN:
			if (hooked_key->dwExtraInfo == programsExtraInfo) {
				return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
			}
			hooked_key->flags;
			map = app.getMap(hooked_key->vkCode);
			sendKeyStroke(map, hooked_key->flags, 0);
			while (drand() < 0.0625) {
				sendKeyStroke(map, 0, 0);
			}
			return 1;
		case WM_SYSKEYUP:
		case WM_KEYUP:
			if (hooked_key->dwExtraInfo == programsExtraInfo) {
				return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
			}
			map = app.getMap(hooked_key->vkCode);
			switch (map) {
			case VK_SPACE:
			case VK_BACK:
				while (drand() < 0.125) {
					sendKeyStroke(map, 0, 0);
				}
			}
			sendKeyStroke(map, hooked_key->flags, KEYEVENTF_KEYUP);
			app.endMap(hooked_key->vkCode);
			return 1;
		}
	}
	return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
}


int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpszCmdLine, int nCmdShow) {
	srand(time(NULL));
	int frameCount = 0;
	MSG msg;
	BOOL bRet;
	std::clock_t start = std::clock();
	HINSTANCE hins;
	hins = GetModuleHandle(NULL);
	hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)HookedCode, hins, 0);
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bRet != -1)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	UnhookWindowsHookEx(hKeyboardHook);
	LocalFree(argv);
	return 0;
}