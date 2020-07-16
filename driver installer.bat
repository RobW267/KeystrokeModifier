reg add "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Services\kbddrive" /f
reg add "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Services\kbddrive" /f /v "DisplayName" /t "REG_SZ" /d "Keyboard Driver"
reg add "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Services\kbddrive" /f /v "ErrorControl" /t "REG_DWORD" /d 0x0
reg add "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Services\kbddrive" /f /v "ImagePath" /t "REG_EXPAND_SZ" /d "\SystemRoot\System32\drivers\kbddrive.sys"
reg add "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Services\kbddrive" /f /v "Start" /t "REG_DWORD" /d 0x2
reg add "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Services\kbddrive" /f /v "Type" /t "REG_DWORD" /d 0x1
