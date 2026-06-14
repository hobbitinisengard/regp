#include "common.h"

// FUNCTION: STUNTGP_D3D 0x44e4a0
void exitError(LPCTSTR msg)
{
#if defined(SGP_DEBUG)
    OutputDebugString(msg);
#endif
    exit(1);
}
