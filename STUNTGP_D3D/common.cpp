#include "common.h"

void traceLog(const char *fmt, ...)
{
    static bool firstOpen = true;
    FILE *file = fopen("regp_trace.txt", firstOpen ? "w" : "a");
    if (!file)
    {
        return;
    }
    firstOpen = false;

    va_list args;
    va_start(args, fmt);
    vfprintf(file, fmt, args);
    va_end(args);
    fprintf(file, "\n");
    fclose(file);
}

// FUNCTION: STUNTGP_D3D 0x44e4a0
void exitError(LPCTSTR msg)
{
#if defined(SGP_DEBUG)
    OutputDebugString(msg);
#endif
    exit(1);
}
