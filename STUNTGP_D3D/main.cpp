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
#include "Game/GameEngine/io_wad.h"
#include "windowInit.h"

#include "globals.h"

#include "common.h"
// #include "pure.h"

extern "C" long __cdecl _ftol();

static BOOL SHOULD_STOP = {false};

static const char kPathJoinFormat[] = "%s\\%s";

void FUN_44ea10();

void FUN_44ea50();

void FUN_42bf00();

void FUN_4411c0();

void __stdcall FUN_4320c0(float value);

void __fastcall FUN_4316f0(DWORD value);

void __fastcall FUN_428f70(DWORD index);

void __fastcall FUN_428ee0(DWORD value);

void FUN_4320a0();

void __stdcall FUN_44e5a0(DWORD value);

void FUN_44e6c0();

DWORD __fastcall FUN_42e980(void *entry);

void __stdcall FUN_432180(DWORD value);

void FUN_460330();

int FUN_460200();

void __fastcall FUN_460af0(DWORD value);

void FUN_460760();

void FUN_460bc0();

void __fastcall FUN_460d60(DWORD index);

void FUN_443bd0();

int __fastcall FUN_445b40(char value);

int __fastcall FUN_445b60(char value);

DWORD __fastcall FUN_445ca0(void *value);

int __fastcall FUN_445b80(void *out, DWORD text);

void __fastcall FUN_445ae0(DWORD text, DWORD *offset);

int __fastcall FUN_443d50(char *text);

int __fastcall FUN_443ca0(void *left, void *right, DWORD count);

float __fastcall FUN_4457c0(char *text, DWORD *remaining);

int __fastcall FUN_4456f0(void *left, void *right, DWORD count);

int __fastcall FUN_445e60(void *left, void *right, DWORD count);

char *__fastcall FUN_445f10(char *text);

void FUN_445d10();

void FUN_445620();

void FUN_445610();

int FUN_445ad0();

void __fastcall FUN_445f70(DWORD value);

void FUN_446a70();

void FUN_446a90();

void FUN_446ac0();

void FUN_460ca0();

void __fastcall FUN_460cb0(DWORD value);

void FUN_460ce0();

DWORD FUN_43d420();

DWORD FUN_43d1f0();

void __fastcall FUN_44ee10(void *obj);

int __stdcall FUN_462030(const void *guid, const char *name, void *unused, void *out);

int __stdcall FUN_4627b6(void *callback, void *out);

int __stdcall FUN_4627b0(DWORD value, void *unknown, void *out);

int FUN_461cf0();

int FUN_461f50();

void __fastcall FUN_461e00(void *slot, char *path, DWORD flags);

int FUN_461a80();

void FUN_45fa60();

void FUN_45fac0();

void FUN_45fab0();

void FUN_45fb40();

void FUN_45fce0();

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
            g_WindowMessage = windowMessage;
            if (g_surface)
            {
                g_surface->GetCaps(&caps);
                if (caps.dwCaps & DDSCAPS_MODEX)
                {
                    FUN_422f30(g_dd4, &g_surface, &g_surface2, g_DISPLAYRESWIDTH, g_DISPLAYRESHEIGHT, g_DISPLAYRESDEPTH);
                }
            }
            int primaryRes = g_surface ? restoreAndClearSurface(g_surface) : DDERR_INVALIDPARAMS;
            int secondaryRes = g_surface2 ? restoreAndClearSurface(g_surface2) : DDERR_INVALIDPARAMS;
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

    g_WindowMessage = 0;
    FUN_44ea50();
    FUN_44ea10();
    FUN_4411c0();
    g_6244f4 = 0;
    FUN_4320c0(1.0f);
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
    if (uMsg == WM_DESTROY)
    {
        PostQuitMessage(0);
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    if (uMsg == WM_MOVE)
    {
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    if (uMsg == WM_SIZE)
    {
        if (IsIconic(hWnd))
        {
            g_61c374 = 1;
            if (g_WindowMessage == 1)
            {
                FUN_44e4b0(0);
            }
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    if (uMsg == WM_ACTIVATEAPP)
    {
        g_61c374 = wParam;
        if ((wParam != 0) && (g_WindowMessage == 1))
        {
            FUN_44e4b0(0);
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    if (uMsg == WM_CHAR)
    {
        if (g_62ddfc == '\0')
        {
            g_62ddfc = (char)wParam;
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// unused: STUNTGP_D3D 0x44e7a0

// FUNCTION: STUNTGP_D3D 0x44e870
__declspec(naked) void m_keyboard()
{
    __asm
    {
        push esi
        push edi
        mov edi, dword ptr [GetKeyboardState]
        mov esi, 0ah
    loopStart:
        push OFFSET g_62d480
        call edi
        dec esi
        jne loopStart
        pop edi
        pop esi
        ret
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
    traceLog("windowCreate enter hInstance=0x%p hPrevInstance=0x%p", hInstance, hPrevInstance);
    if (!hPrevInstance)
    {
        WNDCLASS windowInfo = {0};
        windowInfo.style = CS_OWNDC;
        windowInfo.lpfnWndProc = WndProc;
        windowInfo.hInstance = hInstance;
        windowInfo.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        windowInfo.hCursor = NULL;
        windowInfo.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
        windowInfo.lpszMenuName = menuName;
        windowInfo.lpszClassName = className;
        if (!RegisterClass(&windowInfo))
        {
            traceLog("RegisterClass failed error=0x%08x", GetLastError());
            return FALSE;
        }
    }
    g_Hwnd = windowCreateInternal(hInstance, _T("Stunt GP"), _T("Stunt GP"));
    traceLog("windowCreateInternal returned g_Hwnd=0x%p", g_Hwnd);
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

// FUNCTION: STUNTGP_D3D 0x4320c0
__declspec(naked) void __stdcall FUN_4320c0(float)
{
    __asm
    {
        push ebp
        mov ebp, esp
        push edi
        mov edi, dword ptr [g_5da1dc]
        test edi, edi
        je done
        fld dword ptr [ebp + 8]
        fsub dword ptr [g_6244f4]
        fabs
        fcomp qword ptr [g_46e748]
        fnstsw ax
        test ah, 1
        jne done
        fld dword ptr [ebp + 8]
        fsub qword ptr [g_46e2c8]
        mov eax, dword ptr [ebp + 8]
        mov dword ptr [g_6244f4], eax
        fmul qword ptr [g_46e740]
        fcom qword ptr [g_46e738]
        fnstsw ax
        test ah, 41h
        jne useComputed
        fstp st(0)
        fld dword ptr [g_46e730]
    useComputed:
        fld st(0)
        fmul st(0), st(1)
        push esi
        fmul dword ptr [g_46e668]
        call _ftol
        mov edx, eax
        mov ecx, OFFSET g_592180 + 200h
        shr edx, 6
        sub edx, eax
        mov esi, eax
        add edx, 0ff00h
        fstp st(0)
        shr edx, 8
    loopStart:
        cmp esi, 0fffeh
        mov eax, esi
        jbe storeValue
        mov eax, 0fffeh
    storeValue:
        mov word ptr [ecx - 200h], ax
        mov word ptr [ecx], ax
        mov word ptr [ecx + 200h], ax
        add ecx, 2
        add esi, edx
        cmp ecx, OFFSET g_592180 + 400h
        jl loopStart
        mov ecx, dword ptr [edi]
        push OFFSET g_592180
        push 0
        push edi
        call dword ptr [ecx + 10h]
        pop esi
    done:
        pop edi
        pop ebp
        ret 4
    }
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

// FUNCTION: STUNTGP_D3D 0x42bf00
__declspec(naked) void FUN_42bf00()
{
    __asm
    {
        mov edx, dword ptr [g_57e310]
        push ebx
        test edx, edx
        push esi
        je secondTable
        mov esi, OFFSET g_57e310
    firstLoop:
        mov ecx, dword ptr [esi + 4]
        call FUN_4316f0
        mov edx, dword ptr [esi + 8]
        add esi, 8
        test edx, edx
        jne firstLoop
    secondTable:
        mov eax, dword ptr [g_5895c0]
        xor ebx, ebx
        test eax, eax
        je done
        push edi
        mov edi, OFFSET g_5895c0
        mov esi, edi
    secondLoop:
        mov ecx, ebx
        call FUN_428f70
        mov ecx, dword ptr [edi]
        call FUN_428ee0
        mov eax, dword ptr [esi + 8]
        add esi, 8
        inc ebx
        mov edi, esi
        test eax, eax
        jne secondLoop
        pop edi
    done:
        pop esi
        pop ebx
        ret
    }
}

// STUB: STUNTGP_D3D 0x4316f0
void __fastcall FUN_4316f0(DWORD)
{
}

// FUNCTION: STUNTGP_D3D 0x428f70
__declspec(naked) void __fastcall FUN_428f70(DWORD)
{
    __asm
    {
        mov eax, dword ptr [g_57b314]
        cmp ecx, eax
        jb inRange
        lea ecx, [eax - 1]
    inRange:
        lea eax, [ecx + ecx * 4]
        lea eax, [ecx + eax * 2]
        lea edx, [eax + eax * 4]
        lea eax, [ecx + edx * 4]
        shl eax, 5
        add eax, OFFSET g_577bd0
        mov dword ptr [g_57b310], eax
        ret
    }
}

// STUB: STUNTGP_D3D 0x428ee0
void __fastcall FUN_428ee0(DWORD)
{
}

// TODO: STUNTGP_D3D 0x42e8d0
__declspec(naked) DWORD __fastcall FUN_42e8d0(DWORD, DWORD)
{
    __asm
    {
        push ebp
        mov ebp, esp
        push ecx
        push ebx
        push esi
        mov ebx, edx
        mov dword ptr [ebp - 4], ecx
        mov esi, OFFSET g_589e2c
        xor eax, eax
    searchLoop:
        mov edx, dword ptr [esi + 4]
        test edx, edx
        je foundSlot
        add esi, 18h
        inc eax
        cmp eax, 180h
        jb searchLoop
        pop esi
        xor eax, eax
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    foundSlot:
        push edi
        lea edi, [ecx + 24h]
        push edi
        call malloc
        mov ecx, dword ptr [ebp - 4]
        lea edx, [eax + 20h]
        and edx, 0ffffffe0h
        add esp, 4
        mov dword ptr [esi], edx
        mov dword ptr [esi + 4], eax
        mov dword ptr [esi + 8], edi
        mov dword ptr [esi + 0ch], ecx
        mov dword ptr [esi + 10h], ebx
        mov eax, dword ptr [g_589e20]
        mov dword ptr [esi + 14h], eax
        mov esi, dword ptr [g_589e20]
        inc esi
        cmp ebx, 1
        mov dword ptr [g_589e20], esi
        jne addNormal
        add dword ptr [g_589e18], edi
        jmp updatePeak
    addNormal:
        add dword ptr [g_589e14], edi
    updatePeak:
        mov eax, dword ptr [g_589e14]
        mov esi, dword ptr [g_589e18]
        add eax, esi
        mov esi, dword ptr [g_589e1c]
        cmp eax, esi
        jbe clearBlock
        mov dword ptr [g_589e1c], eax
    clearBlock:
        mov esi, ecx
        xor eax, eax
        mov edi, edx
        shr ecx, 2
        rep stosd
        mov ecx, esi
        and ecx, 3
        rep stosb
        pop edi
        pop esi
        mov eax, edx
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
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
__declspec(naked) DWORD FUN_434820()
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        lea eax, [ebp - 8]
        push eax
        call dword ptr [QueryPerformanceCounter]
        mov eax, dword ptr [ebp - 8]
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x434840
__declspec(naked) void FUN_434840()
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        lea eax, [ebp - 8]
        push eax
        call dword ptr [QueryPerformanceFrequency]
        mov ecx, dword ptr [ebp - 8]
        mov eax, 88888889h
        mul ecx
        shr edx, 5
        mov dword ptr [g_612d0c], ecx
        mov dword ptr [g_612d08], edx
        call FUN_434820
        mov dword ptr [g_612d00], eax
        call FUN_434820
        mov dword ptr [g_612d04], eax
        mov esp, ebp
        pop ebp
        ret
    }
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

// FUNCTION: STUNTGP_D3D 0x462030
__declspec(naked) int __stdcall FUN_462030(const void *, const char *, void *, void *)
{
    __asm
    {
        push ebp
        mov ebp, esp
        mov eax, dword ptr [ebp + 8]
        mov ecx, dword ptr [ebp + 14h]
        push esi
        push edi
        test eax, eax
        je copyName
        mov esi, dword ptr [eax]
        mov edx, ecx
        mov dword ptr [edx], esi
        mov esi, dword ptr [eax + 4]
        mov dword ptr [edx + 4], esi
        mov esi, dword ptr [eax + 8]
        mov eax, dword ptr [eax + 0ch]
        mov dword ptr [edx + 8], esi
        mov dword ptr [edx + 0ch], eax
    copyName:
        mov edi, dword ptr [ebp + 0ch]
        lea edx, [ecx + 10h]
        or ecx, 0ffffffffh
        xor eax, eax
        repne scasb
        not ecx
        sub edi, ecx
        mov eax, ecx
        mov esi, edi
        mov edi, edx
        shr ecx, 2
        rep movsd
        mov ecx, eax
        mov eax, 1
        and ecx, 3
        rep movsb
        pop edi
        pop esi
        pop ebp
        ret 10h
    }
}

// STUB: STUNTGP_D3D 0x4627b6
int __stdcall FUN_4627b6(void *, void *)
{
    return 1;
}

// STUB: STUNTGP_D3D 0x4627b0
int __stdcall FUN_4627b0(DWORD, void *, void *)
{
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x461cf0
__declspec(naked) int FUN_461cf0()
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8ch
        mov eax, dword ptr [g_62e0b0]
        push esi
        xor esi, esi
        lea edx, [ebp - 28h]
        push esi
        mov dword ptr [ebp - 28h], 14h
        mov dword ptr [ebp - 24h], 11h
        mov dword ptr [ebp - 1ch], esi
        mov dword ptr [ebp - 20h], esi
        mov dword ptr [ebp - 18h], esi
        mov ecx, dword ptr [eax]
        push OFFSET g_62e114
        push edx
        push eax
        call dword ptr [ecx + 0ch]
        test eax, eax
        je queryCaps
        xor eax, eax
        pop esi
        mov esp, ebp
        pop ebp
        ret
    queryCaps:
        mov eax, dword ptr [g_62e0b0]
        lea edx, [ebp - 8ch]
        mov dword ptr [ebp - 8ch], 60h
        push edx
        mov ecx, dword ptr [eax]
        push eax
        call dword ptr [ecx + 10h]
        test eax, eax
        je checkCaps
        xor eax, eax
        pop esi
        mov esp, ebp
        pop ebp
        ret
    checkCaps:
        cmp dword ptr [ebp - 60h], 8
        jae enumFormats
        mov dword ptr [g_4897ac], esi
        mov dword ptr [g_4897b0], esi
    enumFormats:
        mov eax, dword ptr [g_62e114]
        lea edx, [ebp - 2ch]
        push edx
        lea edx, [ebp - 14h]
        mov ecx, dword ptr [eax]
        push 12h
        push edx
        push eax
        call dword ptr [ecx + 14h]
        test eax, eax
        je createSurface
        xor eax, eax
        pop esi
        mov esp, ebp
        pop ebp
        ret
    createSurface:
        mov ecx, dword ptr [ebp - 88h]
        mov esi, dword ptr [g_489794]
        and cl, 8
        mov dword ptr [ebp - 10h], esi
        mov eax, dword ptr [ebp - 12h]
        mov word ptr [ebp - 14h], 1
        neg cl
        sbb ecx, ecx
        and eax, 0ffffh
        and ecx, 8
        add ecx, 8
        mov word ptr [ebp - 6], cx
        and ecx, 0ffffh
        imul eax, ecx
        cdq
        and edx, 7
        add eax, edx
        lea edx, [ebp - 14h]
        sar eax, 3
        mov word ptr [ebp - 8], ax
        mov eax, dword ptr [ebp - 8]
        and eax, 0ffffh
        push edx
        imul eax, esi
        mov dword ptr [ebp - 0ch], eax
        mov eax, dword ptr [g_62e114]
        push eax
        mov ecx, dword ptr [eax]
        call dword ptr [ecx + 38h]
        neg eax
        sbb eax, eax
        pop esi
        inc eax
        mov esp, ebp
        pop ebp
        ret
    }
}

// TODO: STUNTGP_D3D 0x461e00
void __fastcall FUN_461e00(void *, char *, DWORD)
{
}

// FUNCTION: STUNTGP_D3D 0x461f50
__declspec(naked) int FUN_461f50()
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 80h
        push ebx
        push esi
        push edi
        mov ecx, 400h
        xor eax, eax
        mov edi, OFFSET g_62e118
        rep stosd
        mov eax, dword ptr [g_4899ec]
        mov ebx, 1
        test eax, eax
        je done
        mov esi, OFFSET g_4899ec
        mov edi, OFFSET g_62e138
    firstLoop:
        mov eax, dword ptr [g_4897b0]
        test eax, eax
        jne firstCheckState
        mov dword ptr [esi + 8], ebx
        jmp firstNext
    firstCheckState:
        cmp dword ptr [esi + 8], 2
        jne firstNext
        mov eax, dword ptr [esi]
        lea ecx, [ebp - 80h]
        push eax
        push OFFSET g_SoundDirectory
        push OFFSET g_SfxPathFormatA
        push ecx
        call sprintf
        add esp, 10h
        lea edx, [ebp - 80h]
        mov ecx, edi
        push 20012h
        call FUN_461e00
    firstNext:
        mov eax, dword ptr [esi + 0ch]
        add esi, 0ch
        add edi, 20h
        test eax, eax
        jne firstLoop
        mov eax, dword ptr [g_4899ec]
        test eax, eax
        je done
        mov esi, OFFSET g_4899ec
        mov edi, OFFSET g_62e138
    secondLoop:
        cmp dword ptr [esi + 8], ebx
        jne secondNext
        mov edx, dword ptr [esi]
        lea eax, [ebp - 80h]
        push edx
        push OFFSET g_SoundDirectory
        push OFFSET g_SfxPathFormatB
        push eax
        call sprintf
        add esp, 10h
        lea edx, [ebp - 80h]
        mov ecx, edi
        push 2
        call FUN_461e00
    secondNext:
        mov eax, dword ptr [esi + 0ch]
        add esi, 0ch
        add edi, 20h
        test eax, eax
        jne secondLoop
    done:
        pop edi
        mov eax, ebx
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x461a80
__declspec(naked) int FUN_461a80()
{
    __asm
    {
        mov eax, dword ptr [g_62e114]
        test eax, eax
        jne query
        ret
    query:
        mov ecx, dword ptr [eax]
        push OFFSET g_62f11c
        push OFFSET g_46fe80
        push eax
        call dword ptr [ecx]
        test eax, eax
        je success
        xor eax, eax
        _emit 0c3h
    success:
    }
}

// FUNCTION: STUNTGP_D3D 0x45fac0
__declspec(naked) void FUN_45fac0()
{
    __asm
    {
        xor eax, eax
        mov dword ptr [g_62df0c], eax
        mov byte ptr [g_62df18], al
        mov dword ptr [g_62df1c], eax
        mov dword ptr [g_62df20], eax
        mov dword ptr [g_62df14], eax
        mov dword ptr [g_62df24], eax
        mov dword ptr [g_62df28], eax
        mov dword ptr [g_62df2c], eax
        mov dword ptr [g_62df30], eax
        mov dword ptr [g_62df34], eax
        mov dword ptr [g_62e084], eax
        mov dword ptr [g_62df38], eax
        mov dword ptr [g_62e090], eax
        mov dword ptr [g_62e098], eax
        mov dword ptr [g_62e09c], eax
        mov dword ptr [g_62e0a0], eax
        mov dword ptr [g_62df3c], eax
        mov dword ptr [g_62df40], eax
        mov dword ptr [g_62df50], eax
        mov byte ptr [g_62df54], al
        mov dword ptr [g_62e06c], eax
        mov dword ptr [g_62e088], eax
        mov dword ptr [g_62e08c], eax
        mov dword ptr [g_62df08], eax
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x45fa60
__declspec(naked) void FUN_45fa60()
{
    __asm
    {
        mov eax, dword ptr [g_62f5ac]
        push esi
        xor esi, esi
        cmp eax, esi
        jne done
        cmp dword ptr [g_62e0f8], esi
        je done
        call FUN_45fac0
        mov dword ptr [g_62e0f8], 66h
        mov dword ptr [g_62e10c], esi
        mov dword ptr [g_62e0fc], esi
        mov dword ptr [g_62e110], esi
        mov dword ptr [g_62e100], esi
        mov dword ptr [g_62e104], esi
        mov dword ptr [g_62e108], esi
        mov dword ptr [g_62f5ac], esi
    done:
        pop esi
        ret
    }
}

// Original: STUNTGP_D3D 0x460760
void FUN_460760()
{
    DWORD *entry = g_62e0b8;
    for (int i = 0x0e; i != 0; i--)
    {
        *entry = 0;
        entry++;
    }
    g_62e0b8[0] = 0xfffffc18;
    g_62e0b8[1] = 0xfffffce0;
    g_62e0b8[2] = 0;
    g_62e0b8[3] = 0x3fbeb852;
    g_62e0b8[4] = 0x3f2b851f;
    g_62e0b8[5] = 0xfffff71f;
    g_62e0b8[6] = 0x3be56042;
    g_62e0b8[7] = 0xfffff965;
    g_62e0b8[8] = 0x3c343958;
    g_62e0b8[9] = 0x10;
    g_62e0b8[10] = 0x40f00000;
    g_62e0b8[11] = 0x3f000000;
    g_62e0b8[12] = 0xc0a00000;
    g_62e0b8[13] = 0x2f;
}

// TODO: STUNTGP_D3D 0x460af0
__declspec(naked) void __fastcall FUN_460af0(DWORD)
{
    __asm
    {
        mov edx, dword ptr [g_62e0ac]
        mov eax, 1
        cmp edx, eax
        jne done
        cmp dword ptr [g_4897b0], eax
        jne done
        cmp ecx, 6
        ja done
        test ecx, ecx
        jne done
        call FUN_460760
    done:
        ret
    }
}

// TODO: STUNTGP_D3D 0x45fb40
__declspec(naked) void FUN_45fb40()
{
    __asm
    {
        jmp FUN_45fce0
    }
}

// TODO: STUNTGP_D3D 0x45fce0
__declspec(naked) void FUN_45fce0()
{
    __asm
    {
        mov eax, dword ptr [g_62e088]
        test eax, eax
        je done
        call FUN_460330
        mov eax, dword ptr [g_62df08]
        push eax
        mov ecx, dword ptr [eax]
        call dword ptr [ecx + 8]
        mov edx, dword ptr [g_62df4c]
        push edx
        call dword ptr [g_46e1a4]
        mov eax, dword ptr [g_62e06c]
        test eax, eax
        je clearState
        push 0
        push eax
        call dword ptr [g_46e1a0]
        mov dword ptr [g_62e06c], 0
    clearState:
        mov eax, dword ptr [g_62df38]
        mov dword ptr [g_62e088], 0
        and ah, 0bfh
        mov dword ptr [g_62df38], eax
    done:
        ret
    }
}

// TODO: STUNTGP_D3D 0x45fab0
__declspec(naked) void FUN_45fab0()
{
    __asm
    {
        mov eax, dword ptr [g_62e0f8]
        test eax, eax
        je done
        jmp FUN_45fb40
    done:
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x462090
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
        push OFFSET g_62f118
        push OFFSET FUN_462030
        call FUN_4627b6
        test eax, eax
        je openDevice
        pop edi
        xor eax, eax
        pop esi
        ret
    openDevice:
        mov ecx, dword ptr [g_62f118]
        mov eax, 38e38e39h
        sub ecx, OFFSET g_62f128
        push esi
        imul ecx
        sar edx, 5
        mov eax, edx
        push OFFSET g_62e0b0
        shr eax, 1fh
        add edx, eax
        push esi
        mov dword ptr [g_62f120], edx
        call FUN_4627b0
        test eax, eax
        je setCoop
        pop edi
        xor eax, eax
        pop esi
        ret
    setCoop:
        mov eax, dword ptr [g_62e0b0]
        mov edx, dword ptr [g_Hwnd]
        push 3
        push edx
        mov ecx, dword ptr [eax]
        push eax
        call dword ptr [ecx + 18h]
        call FUN_461cf0
        test eax, eax
        jne checkMode
        pop edi
        pop esi
        ret
    checkMode:
        cmp dword ptr [g_4897b4], esi
        jne restoreMode
        mov dword ptr [g_4897b0], esi
    createMode:
        call FUN_461f50
        test eax, eax
        jne success
        pop edi
        pop esi
        ret
    restoreMode:
        cmp dword ptr [g_4897b0], edi
        jne createMode
        call FUN_461a80
        test eax, eax
        jne createMode
        pop edi
        pop esi
        ret
    success:
        mov dword ptr [g_62e0ac], edi
        call FUN_45fa60
        call FUN_460bc0
        mov eax, dword ptr [g_4897b0]
        mov dword ptr [g_4897b4], eax
        mov eax, edi
        pop edi
        pop esi
        ret
        nop
        nop
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

// FUNCTION: STUNTGP_D3D 0x445d70
__declspec(naked) void __fastcall FUN_445d70(DWORD)
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 148h
        push ebx
        push esi
        mov ebx, ecx
        push edi
        mov ecx, 69h
        xor eax, eax
        mov edi, OFFSET g_6127a0
        xor esi, esi
        rep stosd
        mov dword ptr [ebp - 4], esi
        mov dword ptr [ebp - 8], esi
        call FUN_445d10
        mov eax, dword ptr [g_60f350]
        test eax, eax
        je loadFile
        mov eax, OFFSET g_60f350
    countLoop:
        mov ecx, dword ptr [eax + 8]
        add eax, 8
        inc esi
        test ecx, ecx
        jne countLoop
        mov dword ptr [ebp - 8], esi
    loadFile:
        mov ecx, OFFSET g_GameTextPath
        call FUN_445ca0
        mov esi, eax
        lea eax, [ebp - 4]
        push eax
        mov edx, esi
        lea ecx, [ebp - 48h]
        call FUN_445b80
        test eax, eax
        je cleanup
    parseEntry:
        xor edi, edi
        test ebx, ebx
        je lineScan
    skipEntry:
        lea ecx, [ebp - 4]
        mov edx, esi
        push ecx
        lea ecx, [ebp - 148h]
        call FUN_445b80
        test eax, eax
        je lineScan
        inc edi
        cmp edi, ebx
        jne skipEntry
    lineScan:
        mov ecx, dword ptr [ebp - 4]
        mov al, byte ptr [ecx + esi]
        test al, al
        je lineEnd
    lineLoop:
        cmp al, 0ah
        je lineEnd
        inc ecx
        mov dword ptr [ebp - 4], ecx
        mov al, byte ptr [ecx + esi]
        test al, al
        jne lineLoop
    lineEnd:
        lea edx, [ebp - 4]
        mov ecx, esi
        call FUN_445ae0
        mov edx, dword ptr [ebp - 8]
        lea ecx, [ebp - 48h]
        push edx
        lea edx, [ebp - 148h]
        call FUN_445e60
        mov dword ptr [ebp - 8], eax
        lea eax, [ebp - 4]
        push eax
        mov edx, esi
        lea ecx, [ebp - 48h]
        call FUN_445b80
        test eax, eax
        jne parseEntry
    cleanup:
        push esi
        call free
        add esp, 4
        mov dword ptr [g_612944], ebx
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x445d10
__declspec(naked) void FUN_445d10()
{
    __asm
    {
        mov eax, dword ptr [g_46e780]
        xor edx, edx
        test eax, eax
        je copyTail
        push esi
        xor eax, eax
        mov ecx, OFFSET g_46e780
    copyLoop:
        mov esi, dword ptr [ecx]
        mov ecx, dword ptr [ecx + 4]
        inc edx
        mov dword ptr [eax + g_60f350], esi
        mov dword ptr [eax + g_60f350 + 4], ecx
        lea eax, [edx*8]
        mov esi, dword ptr [eax + g_46e780]
        lea ecx, [eax + g_46e780]
        test esi, esi
        jne copyLoop
        pop esi
    copyTail:
        mov eax, dword ptr [edx*8 + g_46e780]
        mov ecx, dword ptr [edx*8 + g_46e780 + 4]
        mov dword ptr [edx*8 + g_60f350], eax
        mov dword ptr [edx*8 + g_60f350 + 4], ecx
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x445ad0
int FUN_445ad0()
{
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x445f70
void __fastcall FUN_445f70(DWORD value)
{
    g_4835e0 = value;
}

// FUNCTION: STUNTGP_D3D 0x445e60
__declspec(naked) int __fastcall FUN_445e60(void *, void *, DWORD)
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        mov eax, dword ptr [ebp + 8]
        push ebx
        push esi
        push edi
        xor edi, edi
        mov dword ptr [ebp - 8], edx
        test eax, eax
        mov dword ptr [ebp - 4], ecx
        jle done
        mov ecx, OFFSET g_60f350
    entryLoop:
        mov esi, dword ptr [ebp - 4]
        mov eax, dword ptr [ecx]
    compareLoop:
        mov dl, byte ptr [eax]
        mov bl, dl
        cmp dl, byte ptr [esi]
        jne compareDiff
        test bl, bl
        je compareSame
        mov dl, byte ptr [eax + 1]
        mov bl, dl
        cmp dl, byte ptr [esi + 1]
        jne compareDiff
        add eax, 2
        add esi, 2
        test bl, bl
        jne compareLoop
    compareSame:
        xor eax, eax
        jmp compareDone
    compareDiff:
        sbb eax, eax
        sbb eax, -1
    compareDone:
        test eax, eax
        je matched
        mov eax, dword ptr [ebp + 8]
        inc edi
        add ecx, 8
        cmp edi, eax
        jl entryLoop
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    matched:
        mov ecx, dword ptr [ebp - 8]
        call FUN_445f10
        mov ecx, dword ptr [edi*8 + g_60f350 + 4]
        mov edx, dword ptr [ebp + 8]
        mov dword ptr [ecx*4 + g_6127a0], eax
        lea eax, [edx - 1]
        cmp edi, eax
        jge done
        mov edx, eax
        lea ecx, [edi*8 + g_60f350]
        sub edx, edi
    shiftLoop:
        mov esi, dword ptr [ecx + 8]
        mov dword ptr [ecx], esi
        mov esi, dword ptr [ecx + 0ch]
        mov dword ptr [ecx + 4], esi
        add ecx, 8
        dec edx
        jne shiftLoop
    done:
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    }
}

// FUNCTION: STUNTGP_D3D 0x445f10
__declspec(naked) char *__fastcall FUN_445f10(char *)
{
    __asm
    {
        push esi
        mov esi, ecx
        push edi
        mov edi, esi
        or ecx, 0ffffffffh
        xor eax, eax
        repne scasb
        not ecx
        dec ecx
        or eax, 0ffffffffh
        sub eax, ecx
        mov ecx, dword ptr [g_4835dc]
        add ecx, eax
        mov dword ptr [g_4835dc], ecx
        jns copyString
        pop edi
        xor eax, eax
        pop esi
        ret
    copyString:
        mov ecx, dword ptr [g_4835dc]
        mov edi, esi
        xor eax, eax
        lea edx, [ecx + g_60f6a0]
        or ecx, 0ffffffffh
        repne scasb
        not ecx
        sub edi, ecx
        mov eax, ecx
        mov esi, edi
        mov edi, edx
        shr ecx, 2
        rep movsd
        mov ecx, eax
        mov eax, edx
        and ecx, 3
        rep movsb
        pop edi
        pop esi
        ret
    }
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

// FUNCTION: STUNTGP_D3D 0x460330
__declspec(naked) void FUN_460330()
{
    __asm
    {
        call FUN_460200
        test eax, eax
        jne success
        mov eax, 887800aah
        mov dword ptr [g_62e08c], eax
        ret
    success:
    }
}

// FUNCTION: STUNTGP_D3D 0x460200
int FUN_460200()
{
    if ((g_62e088 != 0) && ((g_62df38 & 0x4000) != 0))
    {
        return 1;
    }
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x460dd0
__declspec(naked) void FUN_460dd0()
{
    __asm
    {
        push esi
        xor esi, esi
    loopStart:
        mov ecx, esi
        call FUN_460d60
        inc esi
        cmp esi, 80h
        jb loopStart
        pop esi
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x460c90
void FUN_460c90()
{
    g_489798 = 0xff;
    g_48979c = 0xff;
}

// Original resets broad game/session state, clears car/player slot arrays, and
// calls several setup routines. This is live from FUN_442030, so keep disabled
// until the surrounding initializers are recovered.
// STUB: STUNTGP_D3D 0x445fa0
void FUN_445fa0()
{
}

// Original performs the main per-level setup chain, including object/track setup,
// camera/state setup, and several global flags. This is live from FUN_442030.
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

// TODO: STUNTGP_D3D 0x445ca0
__declspec(naked) DWORD __fastcall FUN_445ca0(void *)
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 100h
        push esi
        push ecx
        push OFFSET g_GameDirectory
        lea eax, [ebp - 100h]
        push OFFSET kPathJoinFormat
        push eax
        call sprintf
        add esp, 10h
        lea ecx, [ebp - 100h]
        push ecx
        call size_of_file
        add esp, 4
        mov esi, eax
        test esi, esi
        jg loadFile
        xor eax, eax
        pop esi
        mov esp, ebp
        pop ebp
        ret
    loadFile:
        lea ecx, [esi + 1]
        push edi
        push ecx
        call malloc
        add esp, 4
        mov edi, eax
        mov edx, edi
        lea ecx, [ebp - 100h]
        push esi
        push edx
        push ecx
        call bload
        add esp, 0ch
        mov byte ptr [edi + esi], 0
        mov eax, edi
        pop edi
        pop esi
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x445b40
__declspec(naked) int __fastcall FUN_445b40(char)
{
    __asm
    {
        cmp cl, 20h
        je match
        cmp cl, 9
        je match
        xor eax, eax
        ret
    match:
        mov eax, 1
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x445b60
__declspec(naked) int __fastcall FUN_445b60(char)
{
    __asm
    {
        cmp cl, 0dh
        je match
        cmp cl, 0ah
        je match
        xor eax, eax
        ret
    match:
        mov eax, 1
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x445b80
__declspec(naked) int __fastcall FUN_445b80(void *, DWORD)
{
    __asm
    {
        push ebp
        mov ebp, esp
        push ecx
        push ebx
        push esi
        mov esi, dword ptr [ebp + 8]
        push edi
        mov edi, edx
        xor ebx, ebx
        mov eax, dword ptr [esi]
        mov dword ptr [ebp - 4], ecx
        mov byte ptr [ecx], bl
        mov cl, byte ptr [eax + edi]
        call FUN_445b40
        test eax, eax
        je afterLeadingSpaces
    leadingSpaces:
        mov edx, dword ptr [esi]
        inc edx
        mov eax, edx
        mov dword ptr [esi], edx
        mov cl, byte ptr [eax + edi]
        call FUN_445b40
        test eax, eax
        jne leadingSpaces
    afterLeadingSpaces:
        mov eax, dword ptr [esi]
        mov cl, byte ptr [eax + edi]
        test cl, cl
        jne hasToken
        pop edi
        pop esi
        xor eax, eax
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    hasToken:
        cmp cl, 22h
        jne unquoted
        mov cl, byte ptr [eax + edi + 1]
        inc eax
        cmp cl, 22h
        mov dword ptr [esi], eax
        je quotedEnd
    quotedLoop:
        test cl, cl
        je quotedEnd
        mov edx, dword ptr [ebp - 4]
        inc ebx
        inc eax
        mov byte ptr [ebx + edx - 1], cl
        mov dword ptr [esi], eax
        mov cl, byte ptr [eax + edi]
        cmp cl, 22h
        jne quotedLoop
    quotedEnd:
        mov eax, dword ptr [esi]
        cmp byte ptr [eax + edi], 22h
        je quotedClose
        pop edi
        pop esi
        xor eax, eax
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    quotedClose:
        inc eax
        mov dword ptr [esi], eax
        jmp finishToken
    unquoted:
        cmp cl, 2ch
        je finishToken
    unquotedCheck:
        mov eax, dword ptr [esi]
        mov cl, byte ptr [eax + edi]
        call FUN_445b60
        test eax, eax
        jne finishToken
        mov eax, dword ptr [esi]
        mov cl, byte ptr [eax + edi]
        test cl, cl
        je finishToken
        mov edx, dword ptr [ebp - 4]
        inc ebx
        inc eax
        mov byte ptr [ebx + edx - 1], cl
        mov dword ptr [esi], eax
        cmp byte ptr [eax + edi], 2ch
        jne unquotedCheck
    finishToken:
        mov eax, dword ptr [ebp - 4]
        mov byte ptr [ebx + eax], 0
        mov eax, dword ptr [esi]
        cmp byte ptr [eax + edi], 2ch
        jne done
        inc eax
        mov dword ptr [esi], eax
    done:
        pop edi
        mov eax, ebx
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    }
}

// FUNCTION: STUNTGP_D3D 0x445ae0
__declspec(naked) void __fastcall FUN_445ae0(DWORD, DWORD *)
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        push ebx
        push esi
        push edi
        mov edi, edx
        mov dword ptr [ebp - 8], ecx
        mov dword ptr [ebp - 4], 0
    scan:
        mov esi, dword ptr [edi]
        mov eax, dword ptr [ebp - 8]
        mov bl, byte ptr [esi + eax]
        mov cl, bl
        call FUN_445b40
        test eax, eax
        jne whitespace
        mov cl, bl
        call FUN_445b60
        test eax, eax
        je done
    whitespace:
        mov cl, bl
        call FUN_445b60
        test eax, eax
        je advance
        mov dword ptr [ebp - 4], 1
    advance:
        inc esi
        mov dword ptr [edi], esi
        jmp scan
    done:
        mov eax, dword ptr [ebp - 4]
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x443ca0
__declspec(naked) int __fastcall FUN_443ca0(void *, void *, DWORD)
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        mov eax, dword ptr [ebp + 8]
        push ebx
        push esi
        push edi
        xor edi, edi
        mov dword ptr [ebp - 8], edx
        test eax, eax
        mov dword ptr [ebp - 4], ecx
        jle done
        mov ecx, OFFSET g_482720
    entryLoop:
        mov esi, dword ptr [ebp - 4]
        mov eax, dword ptr [ecx]
    compareLoop:
        mov dl, byte ptr [eax]
        mov bl, dl
        cmp dl, byte ptr [esi]
        jne compareDiff
        test bl, bl
        je compareSame
        mov dl, byte ptr [eax + 1]
        mov bl, dl
        cmp dl, byte ptr [esi + 1]
        jne compareDiff
        add eax, 2
        add esi, 2
        test bl, bl
        jne compareLoop
    compareSame:
        xor eax, eax
        jmp compareDone
    compareDiff:
        sbb eax, eax
        sbb eax, -1
    compareDone:
        test eax, eax
        je matched
        mov eax, dword ptr [ebp + 8]
        inc edi
        add ecx, 8
        cmp edi, eax
        jl entryLoop
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    matched:
        mov ecx, dword ptr [ebp - 8]
        call FUN_443d50
        mov ecx, dword ptr [edi*8 + g_482720 + 4]
        mov edx, dword ptr [ebp + 8]
        mov dword ptr [ecx*4 + g_60d688], eax
        lea eax, [edx - 1]
        cmp edi, eax
        jge done
        mov edx, eax
        lea ecx, [edi*8 + g_482720]
        sub edx, edi
    shiftLoop:
        mov esi, dword ptr [ecx + 8]
        mov dword ptr [ecx], esi
        mov esi, dword ptr [ecx + 0ch]
        mov dword ptr [ecx + 4], esi
        add ecx, 8
        dec edx
        jne shiftLoop
    done:
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    }
}

// FUNCTION: STUNTGP_D3D 0x443d50
__declspec(naked) int __fastcall FUN_443d50(char *)
{
    __asm
    {
        mov eax, dword ptr [g_48271c]
        sub eax, 4
        mov dword ptr [g_48271c], eax
        jns parse
        xor eax, eax
        ret
    parse:
        push ecx
        call atoi
        add esp, 4
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x443bd0
__declspec(naked) void FUN_443bd0()
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 144h
        push ebx
        push esi
        push edi
        mov ecx, 25h
        xor eax, eax
        mov edi, OFFSET g_60d688
        rep stosd
        mov eax, dword ptr [g_482720]
        xor ebx, ebx
        test eax, eax
        mov dword ptr [ebp - 4], 0
        je parseStart
        mov eax, OFFSET g_482720
    countLoop:
        mov ecx, dword ptr [eax + 8]
        add eax, 8
        inc ebx
        test ecx, ecx
        jne countLoop
    parseStart:
        mov ecx, OFFSET g_482b30
        call FUN_445ca0
        mov esi, eax
        lea eax, [ebp - 4]
        push eax
        mov edx, esi
        lea ecx, [ebp - 44h]
        call FUN_445b80
        test eax, eax
        je cleanup
    parseLoop:
        lea ecx, [ebp - 4]
        mov edx, esi
        push ecx
        lea ecx, [ebp - 144h]
        call FUN_445b80
        test eax, eax
        je cleanup
        mov ecx, dword ptr [ebp - 4]
        mov al, byte ptr [ecx + esi]
        test al, al
        je lineEnd
    scanLine:
        cmp al, 0ah
        je lineEnd
        inc ecx
        mov dword ptr [ebp - 4], ecx
        mov al, byte ptr [ecx + esi]
        test al, al
        jne scanLine
    lineEnd:
        lea edx, [ebp - 4]
        mov ecx, esi
        call FUN_445ae0
        lea edx, [ebp - 144h]
        lea ecx, [ebp - 44h]
        push ebx
        call FUN_443ca0
        lea edx, [ebp - 4]
        lea ecx, [ebp - 44h]
        push edx
        mov edx, esi
        mov ebx, eax
        call FUN_445b80
        test eax, eax
        jne parseLoop
    cleanup:
        push esi
        call free
        add esp, 4
        mov dword ptr [g_482718], 0
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
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

// FUNCTION: STUNTGP_D3D 0x4456f0
__declspec(naked) int __fastcall FUN_4456f0(void *, void *, DWORD)
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 8
        mov eax, dword ptr [ebp + 8]
        push ebx
        push esi
        push edi
        xor edi, edi
        mov dword ptr [ebp - 8], edx
        test eax, eax
        mov dword ptr [ebp - 4], ecx
        jle done
        mov ecx, OFFSET g_482f40
    entryLoop:
        mov esi, dword ptr [ebp - 4]
        mov eax, dword ptr [ecx]
    compareLoop:
        mov bl, byte ptr [eax]
        mov dl, bl
        cmp bl, byte ptr [esi]
        jne compareDiff
        test dl, dl
        je compareSame
        mov bl, byte ptr [eax + 1]
        mov dl, bl
        cmp bl, byte ptr [esi + 1]
        jne compareDiff
        add eax, 2
        add esi, 2
        test dl, dl
        jne compareLoop
    compareSame:
        xor eax, eax
        jmp compareDone
    compareDiff:
        sbb eax, eax
        sbb eax, -1
    compareDone:
        test eax, eax
        je matched
        mov eax, dword ptr [ebp + 8]
        inc edi
        add ecx, 0ch
        cmp edi, eax
        jl entryLoop
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    matched:
        mov ecx, dword ptr [ebp - 8]
        lea esi, [edi + edi*2]
        mov edx, OFFSET g_482f3c
        shl esi, 2
        call FUN_4457c0
        mov eax, dword ptr [esi + g_482f40 + 8]
        mov ecx, dword ptr [ebp + 8]
        fmul dword ptr [esi + g_482f40 + 4]
        fstp dword ptr [eax*4 + g_60f2d0]
        lea eax, [ecx - 1]
        cmp edi, eax
        jge done
        mov edx, eax
        lea ecx, [esi + g_482f40]
        sub edx, edi
    shiftLoop:
        lea esi, [ecx + 0ch]
        dec edx
        mov edi, esi
        mov ebx, dword ptr [edi]
        mov dword ptr [ecx], ebx
        mov ebx, dword ptr [edi + 4]
        mov dword ptr [ecx + 4], ebx
        mov edi, dword ptr [edi + 8]
        mov dword ptr [ecx + 8], edi
        mov ecx, esi
        jne shiftLoop
    done:
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 4
    }
}

// FUNCTION: STUNTGP_D3D 0x4457c0
__declspec(naked) float __fastcall FUN_4457c0(char *, DWORD *)
{
    __asm
    {
        mov eax, dword ptr [edx]
        add eax, -4
        mov dword ptr [edx], eax
        jns parse
        fld dword ptr [g_46e1ec]
        ret
    parse:
        push ecx
        call atof
        add esp, 4
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x445620
__declspec(naked) void FUN_445620()
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 144h
        push ebx
        push esi
        push edi
        mov ecx, 1fh
        xor eax, eax
        mov edi, OFFSET g_60f2d0
        rep stosd
        mov eax, dword ptr [g_482f40]
        xor ebx, ebx
        test eax, eax
        mov dword ptr [ebp - 4], 0
        je parseStart
        mov eax, OFFSET g_482f40
    countLoop:
        mov ecx, dword ptr [eax + 0ch]
        add eax, 0ch
        inc ebx
        test ecx, ecx
        jne countLoop
    parseStart:
        mov ecx, OFFSET g_483408
        call FUN_445ca0
        mov esi, eax
        lea eax, [ebp - 4]
        push eax
        mov edx, esi
        lea ecx, [ebp - 44h]
        call FUN_445b80
        test eax, eax
        je cleanup
    parseLoop:
        lea ecx, [ebp - 4]
        mov edx, esi
        push ecx
        lea ecx, [ebp - 144h]
        call FUN_445b80
        test eax, eax
        je cleanup
        mov ecx, dword ptr [ebp - 4]
        mov al, byte ptr [ecx + esi]
        test al, al
        je lineEnd
    scanLine:
        cmp al, 0ah
        je lineEnd
        inc ecx
        mov dword ptr [ebp - 4], ecx
        mov al, byte ptr [ecx + esi]
        test al, al
        jne scanLine
    lineEnd:
        lea edx, [ebp - 4]
        mov ecx, esi
        call FUN_445ae0
        lea edx, [ebp - 144h]
        lea ecx, [ebp - 44h]
        push ebx
        call FUN_4456f0
        lea edx, [ebp - 4]
        lea ecx, [ebp - 44h]
        push edx
        mov edx, esi
        mov ebx, eax
        call FUN_445b80
        test eax, eax
        jne parseLoop
    cleanup:
        push esi
        call free
        add esp, 4
        mov dword ptr [g_482f38], 0
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x445610
__declspec(naked) void FUN_445610()
{
    __asm
    {
        ret
    }
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

// FUNCTION: STUNTGP_D3D 0x460d60
__declspec(naked) void __fastcall FUN_460d60(DWORD)
{
    __asm
    {
        mov eax, dword ptr [g_62e0ac]
        test eax, eax
        je done
        shl ecx, 5
        mov ecx, dword ptr g_62e118[ecx]
        test ecx, ecx
        je decrementCount
        mov eax, dword ptr [ecx]
        push ecx
        call dword ptr [eax + 48h]
    decrementCount:
        dec dword ptr [g_62f5b4]
    done:
        ret
    }
}

// Original initializes the active vehicle config/state block and defaults. This is
// only reached when g_612be8 == 1 inside FUN_442030.
// STUB: STUNTGP_D3D 0x40a2f0
void FUN_40a2f0()
{
}

// FUNCTION: STUNTGP_D3D 0x44ee10
__declspec(naked) void __fastcall FUN_44ee10(void *)
{
    __asm
    {
        mov edx, 3f800000h
        xor eax, eax
        mov dword ptr [ecx], edx
        mov dword ptr [ecx + 4], eax
        mov dword ptr [ecx + 8], eax
        mov dword ptr [ecx + 0ch], eax
        mov dword ptr [ecx + 10h], eax
        mov dword ptr [ecx + 14h], edx
        mov dword ptr [ecx + 18h], eax
        mov dword ptr [ecx + 1ch], eax
        mov dword ptr [ecx + 20h], eax
        mov dword ptr [ecx + 24h], eax
        mov dword ptr [ecx + 28h], edx
        mov dword ptr [ecx + 2ch], eax
        mov dword ptr [ecx + 30h], eax
        mov dword ptr [ecx + 34h], eax
        mov dword ptr [ecx + 38h], eax
        mov dword ptr [ecx + 3ch], edx
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x401de0
__declspec(naked) void FUN_401de0()
{
    __asm
    {
        mov ecx, OFFSET g_472210
        mov dword ptr [g_497f20], 0
        mov dword ptr [g_497f24], 42fa0000h
        mov dword ptr [g_497f28], 0c6435000h
        mov dword ptr [g_497f70], 0
        mov dword ptr [g_497f74], 0
        mov dword ptr [g_497f78], 0
        mov dword ptr [g_497f80], 3f800000h
        mov dword ptr [g_497f84], 42c80000h
        call FUN_44ee10
        mov ecx, OFFSET g_472250
        call FUN_44ee10
        mov ecx, OFFSET g_472290
        jmp FUN_44ee10
    }
}

// Original builds default vehicle instances from the initialized vehicle config.
// This is only reached when g_612be8 == 1 inside FUN_442030.
// STUB: STUNTGP_D3D 0x413670
void FUN_413670()
{
}

// Original populates two 0x80-entry normalized float tables after FUN_422380.
// This is only reached when g_612be8 == 1 inside FUN_442030.
// STUB: STUNTGP_D3D 0x422420
void FUN_422420()
{
}

// FUNCTION: STUNTGP_D3D 0x4199a0
__declspec(naked) void FUN_4199a0()
{
    __asm
    {
        mov eax, OFFSET g_4d5cc0
    carLoop:
        mov word ptr [eax], 0
        add eax, 19d00h
        cmp eax, OFFSET g_570ac0
        jl carLoop
        mov eax, OFFSET g_4a1460
    objectLoop:
        mov dword ptr [eax], 0
        add eax, 7724h
        cmp eax, OFFSET g_4cdf38
        jl objectLoop
        ret
    }
}

// Original performs a large race/session reset, initializes AI/player data, then
// calls sound-state reset. This is only reached when g_612be8 == 1.
// STUB: STUNTGP_D3D 0x40d500
void FUN_40d500()
{
}

// STUB: STUNTGP_D3D 0x424c30
void __fastcall FUN_424c30(int mode)
{
    if (mode > 0x10)
    {
        mode = 1;
    }

    if (g_DD_LAYOUT_WIDTH == 0)
    {
        g_DD_LAYOUT_WIDTH = g_DD_DISPLAYRESWIDTH;
    }
    if (g_DD_LAYOUT_HEIGHT == 0)
    {
        g_DD_LAYOUT_HEIGHT = g_DD_DISPLAYRESHEIGHT;
    }

    if (mode == 1)
    {
        g_DD_DISPLAYRESWIDTH = g_DD_LAYOUT_WIDTH;
        g_DD_DISPLAYRESHEIGHT = g_DD_LAYOUT_HEIGHT;
        g_DD_SPLIT_VIEW = 0;
    }

    g_DD_VIEW_CENTER_X = g_DD_DISPLAYRESWIDTH / 2;
    g_DD_VIEW_CENTER_Y = g_DD_DISPLAYRESHEIGHT / 2;
    g_DD_VIEW_HALF_WIDTH = (float)g_DD_VIEW_CENTER_X + 0.5f;
    g_DD_VIEW_HALF_HEIGHT = (float)g_DD_VIEW_CENTER_Y + 0.5f;
    g_DD_VIEW_CENTER_XF = g_DD_VIEW_HALF_WIDTH - 0.5f;
    g_DD_VIEW_CENTER_YF = g_DD_VIEW_HALF_HEIGHT - 0.5f;
    g_DD_VIEW_MODE = mode;
    g_624988_VIEW_MODE_A = mode;
    g_62498c_VIEW_MODE_B = mode;
    g_624990_VIEW_SCALE_X = (float)g_DD_DISPLAYRESWIDTH * 0.0015625f;
    g_624994_VIEW_SCALE_Y = (float)g_DD_DISPLAYRESHEIGHT * 0.0020833334f;

    traceLog("view layout mode=%d size=%d,%d center=%d,%d half=%.1f,%.1f scale=%.3f,%.3f split=%d", mode,
             g_DD_DISPLAYRESWIDTH, g_DD_DISPLAYRESHEIGHT, g_DD_VIEW_CENTER_X, g_DD_VIEW_CENTER_Y,
             g_DD_VIEW_HALF_WIDTH, g_DD_VIEW_HALF_HEIGHT, g_624990_VIEW_SCALE_X, g_624994_VIEW_SCALE_Y,
             g_DD_SPLIT_VIEW);
}

// FUNCTION: STUNTGP_D3D 0x437360
DWORD __fastcall FUN_437360(DWORD value)
{
    switch (value)
    {
    case 1:
    case 8:
    case 0x10:
    case 0x13:
        return 2;
    case 2:
    case 3:
    case 9:
    case 0x0d:
        return 4;
    case 4:
    case 5:
    case 6:
    case 7:
    case 0x0a:
    case 0x0b:
    case 0x0e:
    case 0x0f:
    case 0x11:
    case 0x15:
    case 0x16:
        return 1;
    case 0x0c:
    case 0x12:
    case 0x14:
    case 0x17:
    case 0x18:
        return 3;
    case 0x19:
        return 5;
    default:
        return 0;
    }
}

// FUNCTION: STUNTGP_D3D 0x437da0
DWORD __fastcall FUN_437da0(DWORD value)
{
    switch (value)
    {
    case 1:
    case 2:
    case 3:
    case 8:
    case 9:
    case 0x0d:
    case 0x10:
    case 0x13:
        return 30000;
    default:
        return 0;
    }
}

// FUNCTION: STUNTGP_D3D 0x43d790
__declspec(naked) int __fastcall FUN_43d790(int, int, int)
{
    __asm
    {
        push ebp
        mov ebp, esp
        mov eax, edx
        cmp ecx, eax
        jl done
        mov eax, dword ptr [ebp + 8]
        cmp ecx, eax
        jg done
        mov eax, ecx
done:
        pop ebp
        ret 4
    }
}

// FUNCTION: STUNTGP_D3D 0x43dd10
__declspec(naked) void __fastcall FUN_43dd10(DWORD)
{
    __asm
    {
        push ebp
        mov ebp, esp
        push ecx
        mov edx, ecx
        mov dword ptr [ebp - 4], ecx
        xor eax, eax
        and edx, 0xff
        mov al, byte ptr [ebp - 2]
        and ecx, 0xff00
        shl edx, 0x10
        or eax, edx
        or eax, ecx
        mov dword ptr [g_5ff4b8], eax
        mov esp, ebp
        pop ebp
        ret
    }
}

// FUNCTION: STUNTGP_D3D 0x437e40
void FUN_437e40()
{
}

// FUNCTION: STUNTGP_D3D 0x43d430
void FUN_43d430()
{
    void **slotTable = g_5ff2e0;
    BYTE *slot = g_5fd258;
    do
    {
        *slotTable = slot;
        slotTable++;
        slot += 0x208;
    } while ((int)slot < (int)&g_5ff2d8);
    g_5ff2d8 = 0x10;
    g_5ff2dc = 0;
}

// Original: STUNTGP_D3D 0x43c060
// Partial recovery: clears the active setup block and seeds the scalar defaults
// currently required by the boot path. The original also initializes timing and
// wider state tables that are not wired yet.
void FUN_43c060()
{
    memset(g_5df560, 0, sizeof(g_5df560));
    g_5df560[28] = 0;
    g_5df560[29] = 0;
    g_5df560[30] = 1;
    g_5df5e0 = 100;
    g_5df5e4 = FUN_43d790(g_ConfigDetailLevel, 0, 100);
    g_5df5dc = 0x50;
    g_5df5e8 = 0;
    g_5df5ec = 0;
    g_5df5f0 = 0;
}

// FUNCTION: STUNTGP_D3D 0x439e30
void FUN_439e30()
{
    DWORD *entry = g_5df528;
    for (int i = 0x0d; i != 0; i--)
    {
        *entry = 0;
        entry++;
    }
}

// FUNCTION: STUNTGP_D3D 0x4408e0
void FUN_4408e0()
{
    g_5ff8c0 = 1;
}

// FUNCTION: STUNTGP_D3D 0x436eb0
void FUN_436eb0()
{
    DWORD *entry = g_5da2e8;
    for (int i = 0x1e; i != 0; i--)
    {
        *entry = 0;
        entry++;
    }
}

// Original: STUNTGP_D3D 0x43dee0
void FUN_43dee0()
{
    g_5ff3e8[34] = 0;
    g_5ff3e8[35] = 0;
    g_5ff3e8[36] = 0;
    g_5ff3e8[37] = 0;
    g_5ff3e8[38] = 0;
    g_5ff3e8[39] = 0;
    g_5ff3e8[40] = 0;
    g_5ff3e8[41] = 0;
    g_5ff3e8[42] = 0;
    g_5ff3e8[43] = 0;
    g_5ff3e8[44] = 0;
    g_5ff3e8[45] = 0;
}

// Original: STUNTGP_D3D 0x43dda0
void FUN_43dda0()
{
    DWORD *entry = g_5ff3e8;
    for (int i = 0x34; i != 0; i--)
    {
        *entry = 0;
        entry++;
    }
    g_5ff3e8[1] = 0x10000;
    g_5ff3e8[0] = 1;
    g_5ff3e8[2] = 0;
    g_5ff3e8[3] = 0;
    g_5ff3e8[4] = 0;
    g_5ff3e8[5] = 0;
    g_5ff3e8[22] = 0;
    g_5ff3e8[23] = 1;
    g_5ff3e8[24] = 0;
    g_5ff3e8[25] = 0;
    g_5ff3e8[26] = 0;
    g_5ff3e8[27] = 0;
    g_5ff3e8[28] = 0;
    g_5ff3e8[29] = 0;
    g_5ff3e8[30] = 0;
    g_5ff3e8[31] = 0;
    g_5ff3e8[32] = 0;
    g_5ff3e8[33] = 0;
    g_5ff3e8[46] = 0;
    g_5ff3e8[47] = 0;
    g_5ff3e8[48] = 0;
    g_5ff3e8[49] = 0;
    g_5ff3e8[51] = 0;
    FUN_43dee0();
}

// Original: STUNTGP_D3D 0x43c000
// Partial recovery: copies setup scalars into runtime globals and refreshes
// derived sound/detail values. Calls that touch broader timing systems are not
// enabled yet.
void FUN_43c000()
{
    g_62e0f0 = g_5df5e0;
    g_62e0a8 = g_5df5dc;
    if (g_5df5dc == 0)
    {
        g_62e0a8 = 1;
    }
    g_61297c = g_5df5e4;
    FUN_460bc0();
}

// Original: STUNTGP_D3D 0x440ae0
// Partial recovery: resets the resource-name table state. The original then
// parses a resource list into g_606838/g_5e38dc; keep that disabled until the
// parser helpers are recovered.
void FUN_440ae0()
{
    DWORD *entry = g_605cc8;
    int i;
    for (i = 0x2dc; i != 0; i--)
    {
        *entry = 0;
        entry++;
    }
    g_6087a0 = 0;

    void **resourceSlot = g_606838;
    for (i = 9; i != 0; i--)
    {
        *resourceSlot = &g_6087a4;
        resourceSlot++;
    }
    g_5e38dc = 0;
}

// FUNCTION: STUNTGP_D3D 0x43c580
int __fastcall FUN_43c580(char value)
{
    if ((value != ' ') && (value != '\t'))
    {
        return 0;
    }
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x43c5a0
int __fastcall FUN_43c5a0(char value)
{
    if ((value != '\r') && (value != '\n'))
    {
        return 0;
    }
    return 1;
}

// Original: STUNTGP_D3D 0x43c520
int __fastcall FUN_43c520(char *text, int *offset)
{
    int crossedLine = 0;
    for (;;)
    {
        int index = *offset;
        char value = text[index];
        if (FUN_43c580(value) == 0)
        {
            if (FUN_43c5a0(value) == 0)
            {
                return crossedLine;
            }
        }
        if (FUN_43c5a0(value) != 0)
        {
            crossedLine = 1;
        }
        *offset = index + 1;
    }
}

// Original: STUNTGP_D3D 0x43c5c0
void __fastcall FUN_43c5c0(char *text, int *offset)
{
    char value = text[*offset];
    while (value != '\0')
    {
        int index = *offset;
        if (FUN_43c5a0(value) != 0)
        {
            break;
        }
        value = text[index + 1];
        *offset = index + 1;
    }
    FUN_43c520(text, offset);
}

// Original: STUNTGP_D3D 0x43c680
int __fastcall FUN_43c680(char *out, char *text, int *offset)
{
    *out = 0;
    int outIndex = 0;
    while (FUN_43c580(text[*offset]) != 0)
    {
        *offset = *offset + 1;
    }

    int index = *offset;
    char value = text[index];
    if (value == '\0')
    {
        return 0;
    }

    if (value == '"')
    {
        index++;
        *offset = index;
        value = text[index];
        while ((value != '"') && (value != '\0'))
        {
            out[outIndex] = value;
            outIndex++;
            index++;
            *offset = index;
            value = text[index];
        }
        if (text[*offset] != '"')
        {
            return 0;
        }
        *offset = *offset + 1;
    }
    else
    {
        while ((value != ',') && (FUN_43c5a0(value) == 0))
        {
            value = text[*offset];
            if (value == '\0')
            {
                break;
            }
            out[outIndex] = value;
            outIndex++;
            *offset = *offset + 1;
            value = text[*offset];
        }
    }

    out[outIndex] = 0;
    while ((0 < outIndex) && (out[outIndex - 1] == ' '))
    {
        outIndex--;
        out[outIndex] = 0;
    }
    if (text[*offset] == ',')
    {
        *offset = *offset + 1;
    }
    return outIndex;
}

static int g_DebugParserTokenLen = 0;
static int g_DebugParserOffset = 0;
static char g_DebugParserToken[32] = {0};
static int g_DebugParserToken2Len = 0;
static int g_DebugParserLineOffset = 0;
static char g_DebugParserToken2[32] = {0};

void DebugProbeResourceParser()
{
    char sample[] = "  \"alpha\", beta\r\nnext";
    int offset = 0;
    g_DebugParserTokenLen = FUN_43c680(g_DebugParserToken, sample, &offset);
    g_DebugParserOffset = offset;
    g_DebugParserToken2Len = FUN_43c680(g_DebugParserToken2, sample, &offset);
    FUN_43c5c0(sample, &offset);
    g_DebugParserLineOffset = offset;
}

// Original: STUNTGP_D3D 0x43c400
// Partial recovery: snapshots the active flag bytes within g_5df560. The
// original also copies a wider block to 0x5e167c, which is not declared yet.
void FUN_43c400()
{
    DWORD *source = &g_5df560[2];
    DWORD *dest = &g_5df560[15];
    for (int i = 0x0d; i != 0; i--)
    {
        *dest = *source;
        source++;
        dest++;
    }
}

// Original: STUNTGP_D3D 0x43c370
// Partial recovery: initializes the setup flag block and mode classification
// flags. The original also snapshots this state through FUN_43c400.
void FUN_43c370()
{
    BYTE *setupFlags = (BYTE *)g_5df560;
    memset(setupFlags + 8, 0, 0x34);
    setupFlags[9] = 1;
    setupFlags[12] = 1;
    setupFlags[15] = 1;
    setupFlags[16] = 1;
    setupFlags[17] = 1;
    setupFlags[18] = 1;
    setupFlags[19] = 1;
    setupFlags[23] = 1;
    setupFlags[29] = 1;
    for (int i = 1; i < 0x19; i++)
    {
        DWORD kind = FUN_437360(i);
        g_ModeClass[i] = kind;
        g_ModeDuration[i] = FUN_437da0(i);
        setupFlags[0x20 + i] = ((kind < 1) || (kind > 2)) ? 1 : 0;
    }
    setupFlags[0x26] = 1;
    setupFlags[0x2b] = 1;
    setupFlags[0x37] = 1;
    FUN_43c400();
}

// Original: STUNTGP_D3D 0x43d280
// Partial recovery: applies the post-parse normalization from detail.cfg and
// language.cfg without enabling the original file parser path yet.
void FUN_43d280()
{
    int detail = FUN_43d790(g_5df5e4, 0, 100);
    g_5df5e4 = detail - (detail % 10);

    if ((g_5df5f0 < 1) || (8 < g_5df5f0))
    {
        g_5df5f0 = 0;
    }
}

// Original initializes track/render state and repeatedly advances setup helpers.
// Reached from FUN_442030 when g_612be8 == 2 and g_60d61c == 0.
// STUB: STUNTGP_D3D 0x43d0b0
void FUN_43d0b0()
{
    g_5fd254++;
    g_5fd248 = 0;
    g_5fd250 = 1;

    FUN_437e40();
    FUN_43d430();

    FUN_43c060();
    FUN_439e30();
    FUN_4408e0();
    FUN_436eb0();
    FUN_43dda0();
    FUN_43dd10(0);

    FUN_43c000();

    FUN_43c370();
    FUN_440ae0();
    int idleResult = FUN_445ad0();
    FUN_445f70(g_4835e0);
    FUN_43d280();
    DebugProbeResourceParser();

    BYTE *setupFlags = (BYTE *)g_5df560;
    traceLog("track init state seq=%d flag=%d mode=%d slots=%d active=%d table0=0x%p render=%d,%d,%d color=0x%06x audio=%d,%d detail=%d lang=%d derived=%d,%d,0x%08x cfgSound=%d,%d,%d,%d cfgD3D=%d,%d,%d,%d,%d ctrl=%s flags=%d,%d,%d flagSnap=0x%08x setup5df5d0=%d,%d,%d res=%d,0x%p idle=%d setter=%d parser=%s,%d,%d/%s,%d,%d class=%d,%d,%d dur=%d,%d",
             g_5fd254, g_5fd248, g_5fd250, g_5ff2d8, g_5ff8c0, g_5ff2e0[0], g_5ff3e8[0], g_5ff3e8[1],
             g_5ff3e8[23], g_5ff4b8, g_62e0f0, g_62e0a8, g_61297c, g_5df5f0, g_60d738, g_60d734, g_62e0f8,
             g_ConfigSoundQuality,
             g_ConfigMasterVolume, g_ConfigSfxVolume, g_ConfigMusicVolume, g_ConfigD3DDeviceIndex,
             g_ConfigD3DDriverIndex, g_ConfigD3DUvFix, g_ConfigFrameRateCorrectionDisabled, g_ConfigDisplayBootGfx,
             g_ConfigControlMethod, setupFlags[0x21], setupFlags[0x24], setupFlags[0x39], g_5df560[15],
             g_5df560[28], g_5df560[29], g_5df560[30], g_5e38dc, g_606838[0], idleResult, g_4835e0,
             g_DebugParserToken,
             g_DebugParserTokenLen, g_DebugParserOffset, g_DebugParserToken2, g_DebugParserToken2Len,
             g_DebugParserLineOffset, g_ModeClass[1], g_ModeClass[2], g_ModeClass[0x18],
             g_ModeDuration[1], g_ModeDuration[4]);
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

// Original seeds DirectInput object GUIDs used while enumerating devices.
// STUB: STUNTGP_D3D 0x4239b0
void FUN_4239b0()
{
    g_InputObjectGuids[0] = 0x13541c27;
    g_InputObjectGuids[1] = 0x11d08e33;
    g_InputObjectGuids[2] = 0xa000d09a;
    g_InputObjectGuids[3] = 0x356ea0c9;
    g_InputObjectGuids[4] = 0x13541c28;
    g_InputObjectGuids[5] = 0x11d08e33;
    g_InputObjectGuids[6] = 0xa000d09a;
    g_InputObjectGuids[7] = 0x356ea0c9;
    g_InputObjectGuids[8] = 0x13541c29;
    g_InputObjectGuids[9] = 0x11d08e33;
    g_InputObjectGuids[10] = 0xa000d09a;
    g_InputObjectGuids[11] = 0x356ea0c9;
    g_InputObjectGuids[12] = 0x13541c2a;
    g_InputObjectGuids[13] = 0x11d08e33;
    g_InputObjectGuids[14] = 0xa000d09a;
    g_InputObjectGuids[15] = 0x356ea0c9;
}

// Original initializes DirectInput state and enumerates devices. This is live from
// FUN_442120. Device creation/enumeration is still disabled while keyboard
// handling is custom/stable.
// STUB: STUNTGP_D3D 0x4249b0
void FUN_4249b0()
{
    memset(g_InputDeviceBlocks, 0, sizeof(g_InputDeviceBlocks));
    memset(g_InputDeviceState, 0, sizeof(g_InputDeviceState));
    g_InputDirectInput = NULL;
    g_InputDeviceCount = 0;
    g_InputActiveBlock = g_InputDeviceBlocks;
    g_InputDeviceState[0] = 1;
    g_InputDeviceState[1] = 1;
    g_InputDeviceList = &g_InputDeviceListStorage;
    FUN_4239b0();

    unsigned blockHeadsCleared = 0;
    for (DWORD *entry = g_InputDeviceBlocks; entry < g_InputDeviceBlocks + 0xe1a; entry += 0x169)
    {
        *entry = 0;
        blockHeadsCleared++;
    }

    traceLog("input init partial blocks=%u heads=%u stride=%u state=%u,%u active=0x%p devices=%u directInput=0x%p list=0x%p guid0=0x%08x",
             (unsigned)(sizeof(g_InputDeviceBlocks) / sizeof(g_InputDeviceBlocks[0])), blockHeadsCleared, 0x169,
             g_InputDeviceState[0], g_InputDeviceState[1], g_InputActiveBlock, g_InputDeviceCount,
             g_InputDirectInput, g_InputDeviceList, g_InputObjectGuids[0]);
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
    // intentionally empty; original binary contains only a return here
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

    BOOL windowCreated = windowCreate(hInstance, hPrevInstance);
    traceLog("windowCreate result %d", windowCreated);
    if (!windowCreated)
    {
        return 0;
    }

    ShowCursor(0);
    GetGameBuildVersion();

    // srand(time(NULL));

    static HINSTANCE uwu = hInstance;
    static HINSTANCE owo = hPrevInstance;

    static int mode_current = 2;

    g_612be8 = 2;
    g_612bec = 2;
    traceLog("setup state set to %d", g_612be8);
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
            if (g_62d480[0][VK_ESCAPE] & 0x80)
            {
                SHOULD_STOP = true;
                PostQuitMessage(0);
            }
            if (!SHOULD_STOP)
            {
                thunk_FUN_44e6b0(); // frame timing
                if (g_612be8 == 2)
                {
                    g_612984++;
                }
                FUN_44e9d0();
            }
            if ((g_61c394 % 600) == 0) // log every ~10 seconds at 60fps
            {
                traceLog("game loop alive: frame=%d tickDelta=%d state2Frames=%d", g_61c394, g_61c390 - g_61c37c,
                         g_612984);
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
