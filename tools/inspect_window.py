import ctypes
import subprocess
import time
from ctypes import wintypes
user32 = ctypes.WinDLL('user32')
EnumWindows = user32.EnumWindows
EnumWindowsProc = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)
GetWindowTextW = user32.GetWindowTextW
IsWindowVisible = user32.IsWindowVisible
GetWindowRect = user32.GetWindowRect
GetWindowThreadProcessId = user32.GetWindowThreadProcessId

proc = subprocess.Popen(['./build/StuntGP_D3D.exe'])
time.sleep(0.5)
print('PID', proc.pid)

windows = []
def callback(hwnd, lParam):
    pid = wintypes.DWORD()
    GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
    if pid.value == proc.pid:
        title = ctypes.create_unicode_buffer(256)
        GetWindowTextW(hwnd, title, 256)
        rect = wintypes.RECT()
        GetWindowRect(hwnd, ctypes.byref(rect))
        visible = bool(IsWindowVisible(hwnd))
        windows.append((hwnd, title.value, visible, rect.left, rect.top, rect.right, rect.bottom))
    return True

EnumWindows(EnumWindowsProc(callback), 0)
for w in windows:
    print(w)
proc.kill()
