#include "Game.h"

// TODO: update this based on currrent date and a compile-time define?

#if !defined(REGP_FIXES)
// GLOBAL: STUNTGP_D3D 0x4826a4
const TCHAR g_VERSION_DATE[] = _T("Nov 21 2000");

// GLOBAL: STUNTGP_D3D 0x482698
const TCHAR g_VERSION_TIME[] = _T("16:26:50");
#else
const TCHAR g_VERSION_DATE[] = _T(__DATE__);

const TCHAR g_VERSION_TIME[] = _T(__TIME__);
#endif

// GLOBAL: STUNTGP_D3D 0x4826b0
const TCHAR g_VERSION_FORMAT[] = _T("Version: %s - %s");

// GLOBAL: STUNTGP_D3D 0x612bf8
static TCHAR g_VERSION_STRING[255] = {0};

// FUNCTION: STUNTGP_D3D 0x442010
void GetGameBuildVersion()
{
    _stprintf(g_VERSION_STRING, g_VERSION_FORMAT, g_VERSION_DATE, g_VERSION_TIME);
#if defined(SGP_DEBUG)
    OutputDebugString(g_VERSION_STRING);
#endif
    return;
}
