#ifndef GLOBALS_H
#define GLOBALS_H
#define WIN32_LEAN_AND_MEAN
#include <ddraw.h>
#include <windows.h>

extern BOOL g_612994;

extern void *g_571fd4;

extern int g_DISPLAYRESWIDTH;

extern int g_DISPLAYRESHEIGHT;

extern int g_DISPLAYRESDEPTH;

extern BOOL g_WindowMessage;

extern HWND g_Hwnd;

extern int g_6244f4;

extern DWORD g_61c37c;
extern DWORD g_61c394;
extern DWORD g_61c390;
extern DWORD g_61c370;
extern DWORD g_61c388;

extern DWORD g_61c35c;
extern float g_61c36c;
extern DWORD g_61c39c;

extern char g_62ddfc;
extern WPARAM g_61c374;

extern BYTE g_62d480[11][256];

extern LPDIRECTDRAWSURFACE4 g_surface;
extern LPDIRECTDRAWSURFACE4 g_surface2;

extern LPDIRECTDRAW g_dd;
extern LPDIRECTDRAW4 g_dd4;

extern LPDIRECTDRAWPALETTE g_61c384;

struct SurfaceResourceEntry
{
    LPDIRECTDRAWSURFACE4 surfaceA;
    DWORD flagsA;
    LPDIRECTDRAWSURFACE4 surfaceB;
    DWORD flagsB;
};

extern DWORD g_SurfaceResourceCount;
extern SurfaceResourceEntry g_SurfaceResources[64];

extern DWORD g_612cf8;
extern DWORD g_61297c;
extern DWORD g_60df9c;

extern DWORD g_589e10;
extern DWORD g_589e14;
extern DWORD g_589e18;
extern DWORD g_589e1c;
extern DWORD g_589e20;
extern DWORD g_589e24;
extern DWORD g_589e28;
extern DWORD g_589e2c[0x900];

extern DWORD g_62d580[0x1de];

extern DWORD g_612d00;
extern DWORD g_612d04;
extern DWORD g_612d08;
extern DWORD g_612d0c;
extern DWORD g_4835e0;
extern DWORD g_612944;

extern DWORD g_489d40[0xd8];
extern DWORD g_4899e0[0xd8];
extern DWORD g_62f128[0x120];
extern DWORD g_62e0f0;
extern DWORD *g_62f118;
extern DWORD g_62f120;
extern DWORD g_4897b0;
extern DWORD g_4897ac;
extern DWORD g_489790;
extern DWORD g_48979c;
extern DWORD g_62e0ac;
extern DWORD g_62e0a8;
extern DWORD g_62e0f8;
extern void *g_62e0b0;
extern void *g_62e114;
extern void *g_62f11c;
extern DWORD g_62f5ac;
extern DWORD g_489798;
extern DWORD g_482718;
extern DWORD g_482f38;
extern DWORD g_4d5b20;
extern DWORD g_612be8;
extern DWORD g_60d61c;
extern DWORD g_60d73c;
extern DWORD g_60d734;
extern DWORD g_60d738;
extern DWORD g_5fd248;
extern DWORD g_5fd24c;
extern DWORD g_6087a8[0x25];
extern DWORD g_60883c[0x12d];
extern DWORD g_608cf0[0x25];
extern void *g_5da1dc;

struct LevelCarInfo
{
    char mesh[64];
    char shadow[64];
    int livery;
    int tyre;
    int config;
    int replay;
    int aiSkill;
    int aiMode;
};

extern char g_GameDirectory[128];
extern char g_LevelScript[64];
extern char g_LevelSky[64];
extern char g_LevelTrack[64];
extern char g_LevelTrackTexSet[64];
extern int g_LevelMusicTrack;
extern int g_LevelLapCount;
extern LevelCarInfo g_LevelCars[3];
extern int g_LevelFogR;
extern int g_LevelFogG;
extern int g_LevelFogB;

extern int g_DD_DISPLAYRESWIDTH;
extern int g_DD_DISPLAYRESHEIGHT;
extern int g_DD_DISPLAYRESDEPTH;
extern int g_005728d8_dd;
#endif /* GLOBALS_H */
