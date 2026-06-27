#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <ddraw.h>
#include <tchar.h>
#include <windows.h>

#include "Game/GameEngine/Engine_LevelScript.h"
#include "Game/GameEngine/Game.h"
#include "windowInit.h"

#include "globals.h"

#include "common.h"
// #include "pure.h"

static BOOL SHOULD_STOP = {false};

// FUNCTION: STUNTGP_D3D 0x44e490
void FUN_44e490()
{
    g_612994 = 0;
}

// FUNCTION: STUNTGP_D3D 0x44e4b0
void FUN_44e4b0(BOOL windowMessage)
{
    DDSCAPS2 caps = {0};
    if (windowMessage == 1)
    {
        if (g_WindowMessage == 0)
        {
            g_WindowMessage = windowMessage;
            g_surface->GetCaps(&caps);
            if (caps.dwCaps & DDSCAPS_MODEX)
            {
                FUN_422f30(g_dd4, &g_surface, &g_surface2, g_DISPLAYRESWIDTH, g_DISPLAYRESHEIGHT, g_DISPLAYRESDEPTH);
            }
            restoreAndClearSurface(g_surface);
            restoreAndClearSurface(g_surface2);
            g_dd4->FlipToGDISurface();
            DrawMenuBar(g_Hwnd);
            RedrawWindow(g_Hwnd, NULL, NULL, RDW_FRAME);
            FUN_44e490();
            return;
        }
    }
    else
    {
        g_WindowMessage = 0;
        // FUN_44ea10();
        // FUN_4411c0();
        // g_6244f4 = 0;
        // FUN_4320c0(1.0);
    }
}

// FUNCTION: STUNTGP_D3D 0x44e5d0
void FUN_44e5d0()
{
    g_61c37c = GetTickCount();
    g_61c394 = 0;
    g_61c390 = g_61c37c;
    g_61c370 = g_61c37c;
    g_61c388 = g_61c37c;
}

// FUNCTION: STUNTGP_D3D 0x44e610
void FUN_44e610()
{
    g_61c388 = g_61c390;
    g_61c390 = GetTickCount();
    g_61c394 = g_61c394 + 1;
    g_61c36c = (float)(g_61c390 - g_61c388) * 0.06;
    // if over a second?
    if (1000 < g_61c390 - g_61c370)
    {
        g_61c39c = (g_61c394 * 1000 + g_61c35c * -1000) / (g_61c390 - g_61c370);
        g_61c35c = g_61c394;
        g_61c370 = g_61c390;
    }
}

// thunk
// FUNCTION: STUNTGP_D3D 0x44e6b0
void thunk_FUN_44e6b0()
{
    FUN_44e610();
}

// FUNCTION: STUNTGP_D3D 0x44e6c0
void FUN_44e6c0()
{
    g_61c390 = GetTickCount();
}

// FUNCTION: STUNTGP_D3D 0x44e6d0
LRESULT WINAPI WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // #define WM_NULL                         0x0000
    // #define WM_CREATE                       0x0001
    // #define WM_DESTROY                      0x0002
    // #define WM_MOVE                         0x0003
    // #define WM_SIZE                         0x0005
    // #define WM_ACTIVATE                     0x0006
    BOOL windowMessage = {0};
    if (uMsg < WM_ACTIVATE)
    {
        if (uMsg != WM_SIZE)
        {
            if (uMsg == WM_DESTROY)
            {
                PostQuitMessage(0);
                return DefWindowProc(hWnd, WM_DESTROY, wParam, lParam);
            }
            if (uMsg != WM_MOVE)
            {
                return DefWindowProc(hWnd, uMsg, wParam, lParam);
            }
        }
        // TODO: what produces goto?
        if (!IsIconic(hWnd))
        {
            goto exit;
        }
        windowMessage = 1;
    }
    else
    {
        if (uMsg != WM_ACTIVATEAPP)
        {
            if ((uMsg == WM_KEYDOWN) && (wParam == VK_ESCAPE))
            {
                PostQuitMessage(0);
                return 0;
            }
            if ((uMsg == WM_CHAR) && (g_62ddfc == '\0'))
            {
                g_62ddfc = wParam;
                // TODO: save wparam to static
                return DefWindowProc(hWnd, WM_CHAR, wParam, lParam);
            }
            goto exit;
        }
        // TODO wparam blah
        g_61c374 = wParam;
        if ((wParam == 0) || (!g_WindowMessage))
        {
            goto exit;
        }
        windowMessage = 0;
    }
    FUN_44e4b0(windowMessage);
exit:
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// unused: STUNTGP_D3D 0x44e7a0

// TODO: is this even correct? check assembly
// STUB: STUNTGP_D3D 0x44e870
void m_keyboard()
{
    int i = {10};
    for (i = 10; i >= 0; i--)
    {
        GetKeyboardState(g_62d480[i]);
    }
    if (g_62d480[0][VK_ESCAPE] & 0x80)
    {
        SHOULD_STOP = true;
        PostQuitMessage(0);
    }
}

// FUNCTION: STUNTGP_D3D 0x44e890
BOOL windowCreate(HINSTANCE hInstance, HINSTANCE hPrevInstance)
{

    // TODO: global?
    static HINSTANCE g_HINSTANCE = hInstance;

    DWORD totalVideoMem = {0};
    DWORD totalTextureMem = {0};
    DWORD freeMem = {0};

    const TCHAR menuName[] = _T("AppMenu");
    const TCHAR className[] = _T("Stunt GP");
    if (!hPrevInstance)
    {
        WNDCLASS windowInfo = {0};
        windowInfo.style = CS_OWNDC;
        windowInfo.lpfnWndProc = WndProc;
        windowInfo.hInstance = hInstance;
        windowInfo.hIcon = LoadIcon(hInstance, IDC_ARROW);
        windowInfo.hCursor = NULL;
        windowInfo.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
        windowInfo.lpszMenuName = menuName;
        windowInfo.lpszClassName = className;
        if (!RegisterClass(&windowInfo))
        {
            return FALSE;
        }
    }
    g_Hwnd = windowCreateInternal(hInstance, _T("Stunt GP"), _T("Stunt GP"));
    if (!g_Hwnd)
    {
        return FALSE;
    }

    //  TODO: DirectX init
    traceLog("windowDDCreate");
    windowDDCreate(&g_dd, NULL, g_Hwnd);
    traceLog("ddGetDD4");
    ddGetDD4(g_dd, &g_dd4, g_Hwnd);
    traceLog("ddGetMemory");
    ddGetMemory(g_dd4, &totalVideoMem, &totalTextureMem, &freeMem);
    // FUN_4229e0();
    traceLog("FUN_422f30 %d %d %d", g_DISPLAYRESWIDTH, g_DISPLAYRESHEIGHT, g_DISPLAYRESDEPTH);
    FUN_422f30(g_dd4, &g_surface, &g_surface2, g_DISPLAYRESWIDTH, g_DISPLAYRESHEIGHT, g_DISPLAYRESDEPTH);
    m_keyboard();
    int paletteRes = FUN_4230b0(&g_61c384, g_571fd4);
    traceLog("FUN_4230b0 result 0x%08x", paletteRes);
    return TRUE;
}

// FUNCTION: STUNTGP_D3D 0x44e9b0
int surfaceExists(LPDIRECTDRAWSURFACE4 surface)
{
    if (surface)
    {
        int res = surface->IsLost();
        if (res == DDERR_SURFACELOST)
        {
            res = restoreAndClearSurface(surface);
        }
        return res;
    }
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x44e9c0
int *FUN_44e9c0(int *param_1)
{
    if (param_1)
    {
        // TODO: objects
    }
    return NULL;
}

// STUB: STUNTGP_D3D 0x4314c0
BOOL FUN_4314c0()
{
    if (false)
    {
    }
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x44e9d0
void FUN_44e9d0()
{
    if (surfaceExists(g_surface) == DD_OK)
    {
        if (surfaceExists(g_surface2) == DD_OK)
        {
            clearSurfaceGameColor(g_surface2);
            drawLevelProbeOverlay(g_surface2);
            static BOOL loggedPresent = FALSE;
            int presentRes = g_surface->Blt(NULL, g_surface2, NULL, DDBLT_WAIT, NULL);
            if (!loggedPresent)
            {
                traceLog("present blit result 0x%08x", presentRes);
                loggedPresent = TRUE;
            }
            if (FUN_4314c0())
            {
                return;
            }
        }
    }
    FUN_44e4b0(1);

    return;
}

// FUNCTION: STUNTGP_D3D 0x44ea10

// FUNCTION: STUNTGP_D3D 0x44ea50
void FUN_44ea50()
{
}

// FUNCTION: STUNTGP_D3D 0x44ea60
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    MSG uMsg = {0};
    g_DISPLAYRESWIDTH = 640;
    g_DISPLAYRESHEIGHT = 480;
    g_DISPLAYRESDEPTH = 8;
    traceLog("WinMain start");
    Script_ParseGameConfig();
    traceLog("config %s %d %d %d", g_GameDirectory, g_DISPLAYRESWIDTH, g_DISPLAYRESHEIGHT, g_DISPLAYRESDEPTH);

    BOOL windowCreated = {windowCreate(hInstance, hPrevInstance)};
    traceLog("windowCreate result %d", windowCreated);
    if (!windowCreated)
    {
        return 0;
    }

#if defined(SGP_DEBUG)
    OutputDebugString(_T("Woo, window created!"));
#endif

#if !defined(SGP_DEBUG)
    ShowCursor(false);
#endif

    GetGameBuildVersion();

    // srand(time(NULL));

    static HINSTANCE uwu = hInstance;
    static HINSTANCE owo = hPrevInstance;

    static int mode_current = 2;

    // FUN_442120();  // bigger setup
    // FUN_44e5d0(); // some variables setup?
    do
    {
        BOOL availableMessage = {PeekMessage(&uMsg, NULL, WM_NULL, WM_NULL, PM_REMOVE)};
        if (!availableMessage)
        {
            m_keyboard();
            if (!SHOULD_STOP)
            {
                FUN_44e9d0();
            }
            // if ((false) && (false))
            // {
            //     // TODO: replace with switch?
            //     if (mode_current == 1)
            //     {
            //         OutputDebugString(_T("Game logic"));
            //         printf("game logic");
            //     }
            //     else if (mode_current == 2)
            //     {
            //         OutputDebugString(_T("Frontend logic"));
            //         printf("Frontend logic");
            //     }
            //     // thunk
            // }
        }
        else
        {
            if (uMsg.message == WM_QUIT)
            {
                break;
            }
            TranslateMessage(&uMsg);
            DispatchMessage(&uMsg);
        }

    } while (!SHOULD_STOP);

    DestroyWindow(NULL);
    // shutdowny();
    // fuckery();

    FUN_44ea50();
    return uMsg.wParam;
}
