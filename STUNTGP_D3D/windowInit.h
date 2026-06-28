#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include <ddraw.h>
#include <tchar.h>
#include <windows.h>

#include "common.h"
#include "globals.h"

struct errorMessage
{
    const char *message;
    int code;
};

HWND windowCreateInternal(HINSTANCE hInstance, LPCTSTR className, LPCTSTR windowName);

LPCTSTR ddGetErrMessage(int res);
void FUN_422780();
void FUN_4227b0();
int __fastcall ddSetCoopLevel(LPDIRECTDRAW lplpDD, HWND hWnd);
int __fastcall windowDDCreate(LPDIRECTDRAW *lplpDD, GUID *lpGUID, HWND hWnd);
int __fastcall dd4SetCoopLevel(LPDIRECTDRAW4 ppvObj, HWND hWnd);
int __fastcall ddGetDD4(LPDIRECTDRAW lplpDD, LPDIRECTDRAW4 *ppvObj, HWND hWnd);
void __fastcall FUN_422860(LPUNKNOWN *value);
void __fastcall FUN_422880(LPUNKNOWN *value);
void __fastcall FUN_4228a0(LPUNKNOWN *value);
void __fastcall FUN_4228c0(LPUNKNOWN *value);
void FUN_4228e0();
void FUN_422910();
void FUN_422930();
int __fastcall ddGetMemory(LPDIRECTDRAW4 lpDD4, LPDWORD totalVideoMem, LPDWORD totalTextureMem, LPDWORD freeMem);
void FUN_4229e0();
void __fastcall FUN_422a00(LPDIRECTDRAWSURFACE4 *surface);
void FUN_422a20();
void FUN_422a60();
int __fastcall FUN_422a80(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, LPDDSURFACEDESC2 surfaceDescriptor, int unk);
int __fastcall FUN_422ac0(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, int width, int height, int caps);
void FUN_422b50();
void FUN_422ba0();
void FUN_422bb0();
void FUN_422bf0();
int __fastcall FUN_422c60(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, void *surface2, int width, int height, int depth);
int __fastcall FUN_422d50(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, LPDIRECTDRAWSURFACE4 *surface2, int width,
                          int height);
int __fastcall FUN_422df0(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, LPDIRECTDRAWSURFACE4 *surface2, int width,
                          int height);
int __fastcall FUN_422ea0(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, LPDIRECTDRAWSURFACE4 *surface2, int width,
                          int height);
int __fastcall FUN_422f30(LPDIRECTDRAW4 lpDD4, LPDIRECTDRAWSURFACE4 *surface, LPDIRECTDRAWSURFACE4 *surface2, int width,
               int height, int depth);
int clearSurfaceBlack(LPDIRECTDRAWSURFACE4 surface);
int clearSurfaceGameColor(LPDIRECTDRAWSURFACE4 surface);
void drawLevelProbeOverlay(LPDIRECTDRAWSURFACE4 surface);
int restoreAndClearSurface(LPDIRECTDRAWSURFACE4 surface);
void FUN_423070();
int FUN_4230b0(LPDIRECTDRAWPALETTE *outPalette, void *sth);

// GLOBAL: STUNTSP_D3D 0x5728dc
extern int DAT_CAPS;
