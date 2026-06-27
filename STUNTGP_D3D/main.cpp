#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <ddraw.h>
#include <mmsystem.h>
#include <tchar.h>
#include <windows.h>

#include "Game/GameEngine/Engine_LevelScript.h"
#include "Game/GameEngine/Game.h"
#include "windowInit.h"

#include "globals.h"

#include "common.h"
// #include "pure.h"

static BOOL SHOULD_STOP = {false};

void FUN_44ea10();

void FUN_44ea50();

void FUN_42bf00();

void FUN_4411c0();

void FUN_4320c0(float value);

void FUN_4320a0();

void __stdcall FUN_44e5a0(DWORD value);

void FUN_44e6c0();

DWORD __fastcall FUN_42e980(void *entry);

void __stdcall FUN_432180(DWORD value);

void FUN_460330();

void FUN_460bc0();

void FUN_443bd0();

void FUN_445620();

void FUN_445610();

void FUN_446a70();

void FUN_446a90();

void FUN_446ac0();

void FUN_460ca0();

void __fastcall FUN_460cb0(DWORD value);

void FUN_460ce0();

DWORD FUN_43d420();

DWORD FUN_43d1f0();

// FUNCTION: STUNTGP_D3D 0x44e490
void FUN_44e490()
{
    g_612994 = 0;
}

// FUNCTION: STUNTGP_D3D 0x44e4b0
void __fastcall FUN_44e4b0(BOOL windowMessage)
{
    DDSCAPS2 caps = {0};
    if (windowMessage == 1)
    {
        if (g_WindowMessage == 0)
        {
            traceLog("FUN_44e4b0 called with windowMessage=%d g_WindowMessage=0", windowMessage);
            g_WindowMessage = windowMessage;
            if (g_surface)
            {
                g_surface->GetCaps(&caps);
                if (caps.dwCaps & DDSCAPS_MODEX)
                {
                    traceLog("FUN_44e4b0 restoring mode-x surfaces");
                    FUN_422f30(g_dd4, &g_surface, &g_surface2, g_DISPLAYRESWIDTH, g_DISPLAYRESHEIGHT, g_DISPLAYRESDEPTH);
                }
            }
            int primaryRes = g_surface ? restoreAndClearSurface(g_surface) : DDERR_INVALIDPARAMS;
            int secondaryRes = g_surface2 ? restoreAndClearSurface(g_surface2) : DDERR_INVALIDPARAMS;
            traceLog("restore results primary=0x%08x secondary=0x%08x", primaryRes, secondaryRes);
            if ((primaryRes == DD_OK) && (secondaryRes == DD_OK) && g_dd4)
            {
                g_dd4->FlipToGDISurface();
            }
            DrawMenuBar(g_Hwnd);
            RedrawWindow(g_Hwnd, NULL, NULL, RDW_FRAME);
            FUN_44e490();
            return;
        }
    }
    else
    {
        g_WindowMessage = 0;
        FUN_44ea50();
        FUN_44ea10();
        FUN_4411c0();
        g_6244f4 = 0;
        FUN_4320c0(1.0f);
    }
}

// FUNCTION: STUNTGP_D3D 0x44e570
__declspec(naked) HRESULT CALLBACK FUN_44e570(LPDDSURFACEDESC2, LPVOID)
{
    __asm
    {
        mov eax, 1
        ret 8
    }
}

// FUNCTION: STUNTGP_D3D 0x44e580
__declspec(naked) HRESULT FUN_44e580()
{
    __asm
    {
        mov eax, dword ptr [g_dd4]
        push OFFSET FUN_44e570
        push 0
        push 0
        mov ecx, dword ptr [eax]
        push 0
        push eax
        call dword ptr [ecx + 20h]
        ret
    }
}

void *g_reverseEngineeringAnchors[] = {
    (void *)FUN_44e570,
    (void *)FUN_44e580,
    (void *)FUN_4320a0,
    (void *)FUN_44e5a0,
    (void *)FUN_44e6c0,
    (void *)FUN_42e980,
    (void *)FUN_432180,
    (void *)FUN_446a70,
    (void *)FUN_446a90,
    (void *)FUN_446ac0,
    (void *)FUN_460bc0,
    (void *)FUN_460ca0,
    (void *)FUN_460cb0,
    (void *)FUN_460ce0,
    (void *)FUN_43d420,
    (void *)FUN_43d1f0,
};

// FUNCTION: STUNTGP_D3D 0x44e5a0
void __stdcall FUN_44e5a0(DWORD)
{
    DWORD endTime = GetTickCount() + 1000;
    while (GetTickCount() < endTime)
    {
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
__declspec(naked) void FUN_44e610()
{
    static const float frameScale = 0.06f;
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        mov eax, dword ptr [g_61c390]
        push esi
        push edi
        mov dword ptr [g_61c388], eax
        call dword ptr [GetTickCount]
        mov edi, eax
        mov eax, dword ptr [g_61c388]
        mov ecx, edi
        mov edx, dword ptr [g_61c370]
        sub ecx, eax
        mov dword ptr [ebp - 4], 0
        mov dword ptr [ebp - 8], ecx
        mov ecx, dword ptr [g_61c394]
        fild qword ptr [ebp - 8]
        mov esi, edi
        inc ecx
        sub esi, edx
        mov dword ptr [g_61c390], edi
        fmul dword ptr [frameScale]
        cmp esi, 3e8h
        mov dword ptr [g_61c394], ecx
        fstp dword ptr [g_61c36c]
        jbe done
        mov eax, dword ptr [g_61c35c]
        mov dword ptr [g_61c35c], ecx
        mov dword ptr [g_61c370], edi
        lea eax, [eax + eax * 4]
        lea eax, [eax + eax * 4]
        lea edx, [eax + eax * 4]
        lea eax, [ecx + ecx * 4]
        shl edx, 3
        lea eax, [eax + eax * 4]
        lea eax, [eax + eax * 4]
        shl eax, 3
        sub eax, edx
        xor edx, edx
        div esi
        mov dword ptr [g_61c39c], eax
    done:
        pop edi
        pop esi
        mov esp, ebp
        pop ebp
        ret
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

    if (uMsg == WM_DESTROY)
    {
        PostQuitMessage(0);
        return DefWindowProc(hWnd, WM_DESTROY, wParam, lParam);
    }

    if (uMsg == WM_ACTIVATEAPP)
    {
        traceLog("WM_ACTIVATEAPP wParam=%d g_WindowMessage=%d", (int)wParam, g_WindowMessage);
        g_61c374 = wParam;
        if (wParam == 0)
        {
            g_WindowMessage = 0;
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    if (uMsg == WM_ACTIVATE)
    {
        WORD activateState = LOWORD(wParam);
        BOOL isMinimized = HIWORD(wParam) != 0;
        traceLog("WM_ACTIVATE state=%d fMinimized=%d g_WindowMessage=%d", activateState, (int)isMinimized, g_WindowMessage);
        if ((activateState == WA_INACTIVE) || isMinimized)
        {
            g_WindowMessage = 0;
        }
        else if (g_WindowMessage == 0)
        {
            traceLog("calling FUN_44e4b0(1) from WM_ACTIVATE");
            FUN_44e4b0(1);
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    if (uMsg == WM_SIZE)
    {
        traceLog("WM_SIZE wParam=%d g_WindowMessage=%d", (int)wParam, g_WindowMessage);
        if (wParam == SIZE_MINIMIZED)
        {
            g_WindowMessage = 0;
        }
        else if (g_WindowMessage == 0)
        {
            traceLog("calling FUN_44e4b0(1) from WM_SIZE");
            FUN_44e4b0(1);
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

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
__declspec(naked) int FUN_44e9c0(LPDIRECTDRAWSURFACE4 *surface)
{
    __asm
    {
        mov eax, dword ptr [ecx]
        test eax, eax
        je noSurface
        mov ecx, dword ptr [eax]
        push eax
        call dword ptr [ecx + 6ch]
        ret
    noSurface:
        xor eax, eax
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x4294f0
void FUN_4294f0()
{
    _controlfp(0x10000, 0x30000);
    _controlfp(0, 0x300);
}

// FUNCTION: STUNTGP_D3D 0x429510
void FUN_429510()
{
    FUN_4294f0();
}

// FUNCTION: STUNTGP_D3D 0x42f190
void __fastcall FUN_42f190(unsigned int seed)
{
    srand(seed);
}

// FUNCTION: STUNTGP_D3D 0x42f1a0
void FUN_42f1a0()
{
    FUN_42f190((unsigned int)time(NULL));
}

// FUNCTION: STUNTGP_D3D 0x4411c0
void FUN_4411c0()
{
    for (int i = 0; i < 0x25; i++)
    {
        g_6087a8[i] = 0xffffffff;
    }
    for (int j = 0; j < 0x12d; j++)
    {
        g_60883c[j] = 0xffffffff;
    }
    for (int k = 0; k < 0x25; k++)
    {
        g_608cf0[k] = 0x10000;
    }
}

// STUB: STUNTGP_D3D 0x4320c0
void FUN_4320c0(float value)
{
    if (!g_5da1dc)
    {
        return;
    }
    g_6244f4 = *(DWORD *)&value;
}

// FUNCTION: STUNTGP_D3D 0x4320a0
__declspec(naked) void FUN_4320a0()
{
    __asm
    {
        mov eax, dword ptr [g_5da1dc]
        test eax, eax
        je done
        mov ecx, dword ptr [eax]
        push eax
        call dword ptr [ecx + 8]
        mov dword ptr [g_5da1dc], 0
    done:
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x432180
__declspec(naked) void __stdcall FUN_432180(DWORD)
{
    __asm
    {
        ret 4
    }
}

// STUB: STUNTGP_D3D 0x42bf00
void FUN_42bf00()
{
}

// FUNCTION: STUNTGP_D3D 0x42e980
__declspec(naked) DWORD __fastcall FUN_42e980(void *)
{
    __asm
    {
        push ebx
        xor ebx, ebx
        cmp ecx, ebx
        push esi
        je notFound
        mov esi, OFFSET g_589e2c
        xor eax, eax
    searchLoop:
        cmp ecx, dword ptr [esi]
        je found
        add esi, 18h
        inc eax
        cmp eax, 180h
        jb searchLoop
    notFound:
        pop esi
        xor eax, eax
        pop ebx
        ret
    found:
        mov eax, dword ptr [esi + 10h]
        cmp eax, 1
        jne releaseEntry
        cmp dword ptr [g_589e28], ebx
        jne releaseEntry
        mov eax, dword ptr [esi + 8]
        pop esi
        pop ebx
        ret
    releaseEntry:
        push edi
        mov edi, dword ptr [esi + 8]
        cmp eax, 1
        jne subtractNormal
        sub dword ptr [g_589e18], edi
        jmp freeBlock
    subtractNormal:
        sub dword ptr [g_589e14], edi
    freeBlock:
        mov eax, dword ptr [esi + 4]
        push eax
        call free
        mov dword ptr [esi], ebx
        mov dword ptr [esi + 4], ebx
        add esp, 4
        mov dword ptr [esi + 8], ebx
        mov dword ptr [esi + 0ch], ebx
        mov dword ptr [esi + 10h], ebx
        mov eax, edi
        mov dword ptr [esi + 14h], ebx
        pop edi
        pop esi
        pop ebx
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x434820
DWORD FUN_434820()
{
    LARGE_INTEGER counter = {0};
    QueryPerformanceCounter(&counter);
    return counter.LowPart;
}

// FUNCTION: STUNTGP_D3D 0x434840
void FUN_434840()
{
    LARGE_INTEGER frequency = {0};
    QueryPerformanceFrequency(&frequency);
    g_612d0c = frequency.LowPart;
    g_612d08 = frequency.LowPart / 60;
    g_612d00 = FUN_434820();
    g_612d04 = FUN_434820();
}

// FUNCTION: STUNTGP_D3D 0x42ea00
__declspec(naked) void FUN_42ea00()
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        cmp dword ptr [g_589e10], 1
        jne done
        push ebx
        push esi
        push edi
        xor edi, edi
        mov dword ptr [ebp - 4], edi
        mov dword ptr [ebp - 8], edi
        mov ebx, 180h
    outerLoop:
        dec ebx
        mov esi, OFFSET g_589e2c + 10h
    innerLoop:
        mov ecx, dword ptr [esi - 10h]
        test ecx, ecx
        je nextEntry
        mov eax, dword ptr [g_589e24]
        mov edx, dword ptr [esi + 4]
        add eax, ebx
        cmp edx, eax
        jne nextEntry
        cmp dword ptr [esi], 1
        jne releaseEntry
        mov eax, dword ptr [g_589e28]
        test eax, eax
        jne releaseEntry
        mov ecx, dword ptr [esi - 8]
        mov edx, dword ptr [ebp - 4]
        add edx, ecx
        mov dword ptr [ebp - 4], edx
        jmp countEntry
    releaseEntry:
        call FUN_42e980
        add dword ptr [ebp - 8], eax
    countEntry:
        inc edi
    nextEntry:
        add esi, 18h
        cmp esi, OFFSET g_589e2c + 2410h
        jl innerLoop
        test ebx, ebx
        jg outerLoop
        pop edi
        pop esi
        mov dword ptr [g_589e10], 0
        pop ebx
    done:
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x42ea80
void FUN_42ea80()
{
    FUN_42ea00();
    g_589e10 = 1;
    g_589e20 = 0;
    g_589e24 = 0;
}

// FUNCTION: STUNTGP_D3D 0x42eab0
__declspec(naked) void FUN_42eab0()
{
    __asm
    {
        push edi
        mov ecx, 900h
        xor eax, eax
        mov edi, OFFSET g_589e2c
        rep stosd
        mov dword ptr [g_589e10], eax
        mov dword ptr [g_589e14], eax
        mov dword ptr [g_589e18], eax
        mov dword ptr [g_589e1c], eax
        mov dword ptr [g_589e20], eax
        mov dword ptr [g_589e24], eax
        mov dword ptr [g_589e28], eax
        pop edi
        jmp FUN_42ea80
    }
}

// FUNCTION: STUNTGP_D3D 0x4624b0
void FUN_4624b0()
{
}

// STUB: STUNTGP_D3D 0x462090
__declspec(naked) int FUN_462090()
{
    __asm
    {
        push esi
        push edi
        mov ecx, 0d8h
        mov esi, OFFSET g_489d40
        mov edi, OFFSET g_4899e0
        xor eax, eax
        rep movsd
        mov ecx, 120h
        mov edi, OFFSET g_62f128
        rep stosd
        mov eax, dword ptr [g_62e0f0]
        xor esi, esi
        mov edi, 1
        cmp eax, esi
        mov dword ptr [g_62f118], OFFSET g_62f128
        mov dword ptr [g_62f120], esi
        mov dword ptr [g_4897b0], edi
        mov dword ptr [g_4897ac], edi
        mov dword ptr [g_62e0ac], esi
        mov dword ptr [g_62e0b0], esi
        mov dword ptr [g_62e114], esi
        mov dword ptr [g_62f11c], esi
        mov dword ptr [g_489798], 100h
        jne missingInitPath
        pop edi
        xor eax, eax
        pop esi
        ret
    missingInitPath:
        pop edi
        xor eax, eax
        pop esi
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x45ec30
__declspec(naked) void FUN_45ec30()
{
    __asm
    {
        push edi
        mov ecx, 1dch
        xor eax, eax
        mov edi, OFFSET g_62d580
        rep stosd
        mov eax, OFFSET g_62d580 + 8
        xor ecx, ecx
        mov edx, 0ffffh
        pop edi
    initLoop:
        mov dword ptr [eax - 8], ecx
        mov dword ptr [eax], ecx
        mov dword ptr [eax + 4], ecx
        mov dword ptr [eax + 0ch], ecx
        mov dword ptr [eax + 10h], edx
        mov dword ptr [eax + 14h], ecx
        mov dword ptr [eax + 18h], ecx
        mov dword ptr [eax + 1ch], ecx
        mov dword ptr [eax + 20h], ecx
        add eax, 1dch
        cmp eax, OFFSET g_62d580 + 778h
        jl initLoop
        ret
    }
}

// STUB: STUNTGP_D3D 0x445d70
void __fastcall FUN_445d70(DWORD index)
{
    g_612944 = index;
}

// FUNCTION: STUNTGP_D3D 0x445f80
void FUN_445f80()
{
    if (g_4835e0 != g_612944)
    {
        FUN_445d70(g_4835e0);
    }
}

// FUNCTION: STUNTGP_D3D 0x45f9d0
__declspec(naked) void FUN_45f9d0()
{
    __asm
    {
        mov eax, dword ptr [g_62f5ac]
        test eax, eax
        je done
        mov eax, dword ptr [g_62e0f8]
        test eax, eax
        je done
        call FUN_460330
        mov dword ptr [g_62f5ac], 0
    done:
        ret
    }
}

// STUB: STUNTGP_D3D 0x460330
void FUN_460330()
{
}

// STUB: STUNTGP_D3D 0x460dd0
void FUN_460dd0()
{
}

// FUNCTION: STUNTGP_D3D 0x460c90
void FUN_460c90()
{
    g_489798 = 0xff;
    g_48979c = 0xff;
}

// STUB: STUNTGP_D3D 0x445fa0
void FUN_445fa0()
{
}

// STUB: STUNTGP_D3D 0x42e6e0
void FUN_42e6e0()
{
}

// FUNCTION: STUNTGP_D3D 0x443d70
__declspec(naked) void FUN_443d70()
{
    __asm
    {
        mov eax, dword ptr [g_482718]
        test eax, eax
        je done
        jmp FUN_443bd0
    done:
        ret
    }
}

// STUB: STUNTGP_D3D 0x443bd0
void FUN_443bd0()
{
}

// FUNCTION: STUNTGP_D3D 0x4457e0
__declspec(naked) void FUN_4457e0()
{
    __asm
    {
        mov eax, dword ptr [g_482f38]
        test eax, eax
        je done
        call FUN_445620
        jmp FUN_445610
    done:
        ret
    }
}

// STUB: STUNTGP_D3D 0x445620
void FUN_445620()
{
}

// STUB: STUNTGP_D3D 0x445610
void FUN_445610()
{
}

// STUB: STUNTGP_D3D 0x4469f0
void FUN_4469f0()
{
}

// FUNCTION: STUNTGP_D3D 0x446a70
__declspec(naked) void FUN_446a70()
{
    __asm
    {
        mov eax, dword ptr [g_61297c]
        add eax, 0ah
        cmp eax, 64h
        mov dword ptr [g_61297c], eax
        jbe inRange
        xor eax, eax
        mov dword ptr [g_61297c], eax
    inRange:
        mov dword ptr [g_60d73c], eax
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x446a90
__declspec(naked) void FUN_446a90()
{
    __asm
    {
        mov eax, dword ptr [g_62e0f0]
        add eax, 0ah
        cmp eax, 64h
        mov dword ptr [g_62e0f0], eax
        jbe done
        mov dword ptr [g_62e0f0], 0
    done:
        jmp FUN_460bc0
    }
}

// FUNCTION: STUNTGP_D3D 0x446ac0
__declspec(naked) void FUN_446ac0()
{
    __asm
    {
        mov eax, dword ptr [g_62e0a8]
        add eax, 0ah
        cmp eax, 64h
        mov dword ptr [g_62e0a8], eax
        jbe done
        mov dword ptr [g_62e0a8], 0
    done:
        jmp FUN_460bc0
    }
}

// FUNCTION: STUNTGP_D3D 0x40e050
__declspec(naked) void FUN_40e050()
{
    __asm
    {
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x460bc0
__declspec(naked) void FUN_460bc0()
{
    __asm
    {
        mov ecx, dword ptr [g_489790]
        mov edx, dword ptr [g_62e0a8]
        mov eax, ecx
        mov dword ptr [g_60d734], edx
        imul eax, edx
        mov edx, eax
        push esi
        mov esi, dword ptr [g_62e0f0]
        shl edx, 8
        imul ecx, esi
        sub edx, eax
        mov eax, 0d1b71759h
        mul edx
        shr edx, 0dh
        mov dword ptr [g_62e0f8], edx
        mov edx, ecx
        shl edx, 8
        sub edx, ecx
        mov eax, 0d1b71759h
        mul edx
        shr edx, 0dh
        mov dword ptr [g_60d738], esi
        mov dword ptr [g_489798], edx
        mov dword ptr [g_48979c], edx
        pop esi
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x460ca0
__declspec(naked) void FUN_460ca0()
{
    __asm
    {
        mov dword ptr [g_48979c], 0
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x460cb0
__declspec(naked) void __fastcall FUN_460cb0(DWORD)
{
    __asm
    {
        cmp ecx, -1
        je keepCurrent
        mov dword ptr [g_489798], ecx
    keepCurrent:
        mov eax, dword ptr [g_489790]
        imul eax, dword ptr [g_62e0f0]
        mov ecx, eax
        shl ecx, 8
        sub ecx, eax
        mov eax, 0d1b71759h
        mul ecx
        shr edx, 0dh
        mov dword ptr [g_48979c], edx
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x460ce0
__declspec(naked) void FUN_460ce0()
{
    __asm
    {
        mov eax, dword ptr [g_489798]
        mov ecx, dword ptr [g_48979c]
        cmp eax, ecx
        je done
        jge fadeDown
        add eax, 4
        cmp eax, ecx
        mov dword ptr [g_489798], eax
        jle done
        mov dword ptr [g_489798], ecx
        ret
    fadeDown:
        sub eax, 4
        cmp eax, ecx
        mov dword ptr [g_489798], eax
        jge done
        mov dword ptr [g_489798], ecx
    done:
        ret
    }
}

// STUB: STUNTGP_D3D 0x40a2f0
void FUN_40a2f0()
{
}

// STUB: STUNTGP_D3D 0x401de0
void FUN_401de0()
{
}

// STUB: STUNTGP_D3D 0x413670
void FUN_413670()
{
}

// STUB: STUNTGP_D3D 0x422420
void FUN_422420()
{
}

// STUB: STUNTGP_D3D 0x4199a0
void FUN_4199a0()
{
}

// STUB: STUNTGP_D3D 0x40d500
void FUN_40d500()
{
}

// STUB: STUNTGP_D3D 0x424c30
void __fastcall FUN_424c30(int mode)
{
    (void)mode;
}

// STUB: STUNTGP_D3D 0x43d0b0
void FUN_43d0b0()
{
}

// FUNCTION: STUNTGP_D3D 0x43d420
__declspec(naked) DWORD FUN_43d420()
{
    __asm
    {
        xor eax, eax
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x43d1f0
__declspec(naked) DWORD FUN_43d1f0()
{
    __asm
    {
        jmp FUN_43d420
    }
}

// FUNCTION: STUNTGP_D3D 0x43d1d0
__declspec(naked) void FUN_43d1d0()
{
    __asm
    {
        call FUN_43d1f0
        mov dword ptr [g_5fd248], 0
        jmp FUN_4411c0
    }
}

// FUNCTION: STUNTGP_D3D 0x43d1b0
__declspec(naked) void FUN_43d1b0()
{
    __asm
    {
        mov dword ptr [g_5fd248], 1
        call FUN_43d420
        mov dword ptr [g_5fd24c], eax
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x442100
void FUN_442100()
{
    g_612d00 = FUN_434820();
    g_612d04 = FUN_434820();
}

// STUB: STUNTGP_D3D 0x4249b0
void FUN_4249b0()
{
}

// FUNCTION: STUNTGP_D3D 0x442030
void FUN_442030()
{
    g_4d5b20 = 0;
    FUN_45f9d0();
    FUN_460dd0();
    FUN_460c90();
    FUN_445fa0();
    FUN_42ea80();
    FUN_42e6e0();
    FUN_443d70();
    FUN_4457e0();
    if (g_612be8 == 1)
    {
        FUN_445f80();
        FUN_4469f0();
        FUN_40e050();
        FUN_40a2f0();
        FUN_401de0();
        FUN_413670();
        FUN_422420();
        FUN_4199a0();
        FUN_40d500();
    }
    if (g_612be8 == 2)
    {
        FUN_424c30(1);
        if (!g_60d61c)
        {
            g_60d61c = 1;
            FUN_43d0b0();
        }
        else
        {
            FUN_43d1d0();
        }
    }
    if (g_612be8 == 1)
    {
        FUN_43d1b0();
    }
    FUN_442100();
}

// FUNCTION: STUNTGP_D3D 0x442120
void FUN_442120()
{
    g_612cf8 = 0;
    g_61297c = 100;
    FUN_429510();
    FUN_42f1a0();
    FUN_434840();
    FUN_42eab0();
    FUN_4624b0();
    Script_ParseGameConfig();
    FUN_462090();
    FUN_45ec30();
    FUN_445f80();
    FUN_4249b0();
    g_60df9c = 0;
    FUN_442030();
}

// FUNCTION: STUNTGP_D3D 0x4314c0
BOOL FUN_4314c0()
{
    for (DWORD i = 0; i < g_SurfaceResourceCount; i++)
    {
        LPDIRECTDRAWSURFACE4 surfaceA = g_SurfaceResources[i].surfaceA;
        if (surfaceA && surfaceA->IsLost() != DD_OK)
        {
            return FALSE;
        }

        LPDIRECTDRAWSURFACE4 surfaceB = g_SurfaceResources[i].surfaceB;
        if (surfaceB && surfaceB->IsLost() != DD_OK)
        {
            return FALSE;
        }
    }
    return TRUE;
}

// FUNCTION: STUNTGP_D3D 0x431510
__declspec(naked) BOOL FUN_431510()
{
    __asm
    {
        mov eax, dword ptr [g_SurfaceResourceCount]
        push esi
        push edi
        xor edi, edi
        test eax, eax
        jbe success
        mov esi, OFFSET g_SurfaceResources + 8
    loopStart:
        mov eax, dword ptr [esi - 8]
        test eax, eax
        je checkSecond
        mov ecx, dword ptr [eax]
        push eax
        call dword ptr [ecx + 6ch]
        test eax, eax
        jne failure
    checkSecond:
        mov eax, dword ptr [esi]
        test eax, eax
        je nextEntry
        mov edx, dword ptr [eax]
        push eax
        call dword ptr [edx + 6ch]
        test eax, eax
        jne failure
    nextEntry:
        mov eax, dword ptr [g_SurfaceResourceCount]
        inc edi
        add esi, 10h
        cmp edi, eax
        jb loopStart
    success:
        pop edi
        mov eax, 1
        pop esi
        ret
    failure:
        pop edi
        xor eax, eax
        pop esi
        ret
    }
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
__declspec(naked) void FUN_44ea10()
{
    __asm
    {
        mov ecx, OFFSET g_surface
        call FUN_44e9c0
        test eax, eax
        jne fail
        mov ecx, OFFSET g_surface2
        call FUN_44e9c0
        test eax, eax
        jne fail
        call FUN_431510
        cmp eax, 1
        je ok
    fail:
        mov ecx, 1
        jmp FUN_44e4b0
    ok:
        jmp FUN_42bf00
    }
}

// FUNCTION: STUNTGP_D3D 0x44ea50
void FUN_44ea50()
{
    if (g_61c384)
    {
        g_61c384->Release();
        g_61c384 = NULL;
    }
    if (g_surface2)
    {
        g_surface2->Release();
        g_surface2 = NULL;
    }
    if (g_surface)
    {
        g_surface->Release();
        g_surface = NULL;
    }
    if (g_dd4)
    {
        g_dd4->Release();
        g_dd4 = NULL;
    }
    if (g_dd)
    {
        g_dd->Release();
        g_dd = NULL;
    }
    if (g_Hwnd)
    {
        DestroyWindow(g_Hwnd);
        g_Hwnd = NULL;
    }
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

    traceLog("=== FUN_442120 (bigger setup) ===");
    FUN_442120();
    traceLog("=== FUN_44e5d0 (timing init) ===");
    FUN_44e5d0();
    do
    {
        BOOL availableMessage = {PeekMessage(&uMsg, NULL, WM_NULL, WM_NULL, PM_REMOVE)};
        if (!availableMessage)
        {
            m_keyboard();
            if (!SHOULD_STOP)
            {
                thunk_FUN_44e6b0(); // frame timing
                FUN_44e9d0();
            }
            if ((g_61c394 % 600) == 0) // log every ~10 seconds at 60fps
            {
                traceLog("game loop alive: frame=%d tickDelta=%d", g_61c394, g_61c390 - g_61c37c);
            }
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

    DestroyWindow(g_Hwnd);
    // shutdowny();
    // fuckery();

    FUN_44ea50();
    return uMsg.wParam;
}
