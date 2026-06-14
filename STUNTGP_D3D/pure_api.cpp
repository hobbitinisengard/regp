/*
 * Header file of Pure API function declarations.
 *
 * Explicitly no copyright.
 * You may recompile and redistribute these definitions as required.
 *
 * NOTE1: In some situations when compiling with MFC, you should
 *        enable the setting 'Not using precompiled headers' in Visual C++
 *        to avoid a compiler diagnostic.
 *
 * NOTE2: This file works through the use of deep magic.  Calls to functions
 *        in this file are replaced with calls into the OCI runtime system
 *        when an instrumented version of this program is run.
 *
 * NOTE3: The static vars avoidGy_n (where n is a unique number) are used
 *        to prevent optimizing the functions away when compiler option
 *        /Gy is set. This is needed so that NOTE2 works properly.
 */

// GLOBAL: STUNTGP_D3D 0x62de18
static int avoidGy_1;

// GLOBAL: STUNTGP_D3D 0x62de1c
static int avoidGy_2;

// GLOBAL: STUNTGP_D3D 0x62de20
static int avoidGy_3;

// GLOBAL: STUNTGP_D3D 0x62de24
static int avoidGy_4;

// GLOBAL: STUNTGP_D3D 0x62de04
static int avoidGy_5;

// GLOBAL: STUNTGP_D3D 0x62de08
static int avoidGy_6;

// GLOBAL: STUNTGP_D3D 0x62de0c
static int avoidGy_7;

// GLOBAL: STUNTGP_D3D 0x62de10
static int avoidGy_8;

// GLOBAL: STUNTGP_D3D 0x62de14
static int avoidGy_9;

// GLOBAL: STUNTGP_D3D 0x62de60
static int avoidGy_10;

// GLOBAL: STUNTGP_D3D 0x62de5c
static int avoidGy_11;

// GLOBAL: STUNTGP_D3D 0x62de58
static int avoidGy_12;

// GLOBAL: STUNTGP_D3D 0x62decc
static int avoidGy_13;

// GLOBAL: STUNTGP_D3D 0x62dec8
static int avoidGy_14;

// GLOBAL: STUNTGP_D3D 0x62dec0
static int avoidGy_15;

// GLOBAL: STUNTGP_D3D 0x62deb8
static int avoidGy_16;

// GLOBAL: STUNTGP_D3D 0x62def4
static int avoidGy_17;

// GLOBAL: STUNTGP_D3D 0x62deec
static int avoidGy_18;

// GLOBAL: STUNTGP_D3D 0x62dee0
static int avoidGy_19;

// GLOBAL: STUNTGP_D3D 0x62dec4
static int avoidGy_20;

// GLOBAL: STUNTGP_D3D 0x62debc
static int avoidGy_21;

// GLOBAL: STUNTGP_D3D 0x62deb4
static int avoidGy_22;

// GLOBAL: STUNTGP_D3D 0x62def0
static int avoidGy_23;

// GLOBAL: STUNTGP_D3D 0x62dee8
static int avoidGy_24;

// GLOBAL: STUNTGP_D3D 0x62dedc
static int avoidGy_25;

// GLOBAL: STUNTGP_D3D 0x62ded4
static int avoidGy_26;

// GLOBAL: STUNTGP_D3D 0x62de88
static int avoidGy_27;

// GLOBAL: STUNTGP_D3D 0x62de80
static int avoidGy_28;

// GLOBAL: STUNTGP_D3D 0x62de74
static int avoidGy_29;

// GLOBAL: STUNTGP_D3D 0x62dee4
static int avoidGy_30;

// GLOBAL: STUNTGP_D3D 0x62ded8
static int avoidGy_31;

// GLOBAL: STUNTGP_D3D 0x62ded0
static int avoidGy_32;

// GLOBAL: STUNTGP_D3D 0x62de84
static int avoidGy_33;

// GLOBAL: STUNTGP_D3D 0x62de7c
static int avoidGy_34;

// GLOBAL: STUNTGP_D3D 0x62de70
static int avoidGy_35;

// GLOBAL: STUNTGP_D3D 0x62de68
static int avoidGy_36;

// GLOBAL: STUNTGP_D3D 0x62deb0
static int avoidGy_37;

// GLOBAL: STUNTGP_D3D 0x62de64
static int avoidGy_38;

// GLOBAL: STUNTGP_D3D 0x62deac
static int avoidGy_39;

// GLOBAL: STUNTGP_D3D 0x62dea4
static int avoidGy_40;

// GLOBAL: STUNTGP_D3D 0x62de98
static int avoidGy_41;

// GLOBAL: STUNTGP_D3D 0x62de90
static int avoidGy_42;

// GLOBAL: STUNTGP_D3D 0x62de48
static int avoidGy_43;

// GLOBAL: STUNTGP_D3D 0x62de40
static int avoidGy_44;

// GLOBAL: STUNTGP_D3D 0x62de30
static int avoidGy_45;

// GLOBAL: STUNTGP_D3D 0x62de34
static int avoidGy_46;

// FUNCTION: STUNTGP_D3D 0x45f250
__declspec(dllexport) int __cdecl PurePrintf(const char *fmt, ...)
{
    avoidGy_1++;
    fmt;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f260
__declspec(dllexport) int __cdecl PurifyIsRunning(void)
{
    avoidGy_2++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f270
__declspec(dllexport) int __cdecl PurifyPrintf(const char *fmt, ...)
{
    avoidGy_3++;
    fmt;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f280
__declspec(dllexport) int __cdecl PurifyNewInuse(void)
{
    avoidGy_4++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f290
__declspec(dllexport) int __cdecl PurifyAllInuse(void)
{
    avoidGy_5++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f2a0
__declspec(dllexport) int __cdecl PurifyClearInuse(void)
{
    avoidGy_6++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f2b0
__declspec(dllexport) int __cdecl PurifyNewLeaks(void)
{
    avoidGy_7++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f2c0
__declspec(dllexport) int __fastcall PurifyAllLeaks(void)
{
    avoidGy_8++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f2d0
__declspec(dllexport) int __cdecl PurifyClearLeaks(void)
{
    avoidGy_9++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f2e0
__declspec(dllexport) int __cdecl PurifyAllHandlesInuse(void)
{
    avoidGy_10++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f2f0
__declspec(dllexport) int __cdecl PurifyNewHandlesInuse(void)
{
    avoidGy_11++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f300
__declspec(dllexport) int __cdecl PurifyDescribe(void *addr)
{
    avoidGy_12++;
    addr;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f310
__declspec(dllexport) int __cdecl PurifyWhatColors(void *addr, int size)
{
    avoidGy_13++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f320
__declspec(dllexport) int __cdecl PurifyAssertIsReadable(const void *addr, int size)
{
    avoidGy_14++;
    addr;
    size;
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x45f340
__declspec(dllexport) int __cdecl PurifyAssertIsWritable(const void *addr, int size)
{
    avoidGy_15++;
    addr;
    size;
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x45f360
__declspec(dllexport) int __cdecl PurifyIsReadable(const void *addr, int size)
{
    avoidGy_16++;
    addr;
    size;
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x45f380
__declspec(dllexport) int __cdecl PurifyIsWritable(const void *addr, int size)
{
    avoidGy_17++;
    addr;
    size;
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x45f3a0
__declspec(dllexport) int __cdecl PurifyIsInitialized(const void *addr, int size)
{
    avoidGy_18++;
    addr;
    size;
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x45f3c0
__declspec(dllexport) int __cdecl PurifyRed(void *addr, int size)
{
    avoidGy_19++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f3d0
__declspec(dllexport) int __cdecl PurifyGreen(void *addr, int size)
{
    avoidGy_20++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f3e0
__declspec(dllexport) int __cdecl PurifyYellow(void *addr, int size)
{
    avoidGy_21++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f3f0
__declspec(dllexport) int __cdecl PurifyBlue(void *addr, int size)
{
    avoidGy_22++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f400
__declspec(dllexport) int __cdecl PurifyMarkAsInitialized(void *addr, int size)
{
    avoidGy_23++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f410
__declspec(dllexport) int __cdecl PurifyMarkAsUninitialized(void *addr, int size)
{
    avoidGy_24++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f420
__declspec(dllexport) int __cdecl PurifyMarkForTrap(void *addr, int size)
{
    avoidGy_25++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f430
__declspec(dllexport) int __cdecl PurifyMarkForNoTrap(void *addr, int size)
{
    avoidGy_26++;
    addr;
    size;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f440
__declspec(dllexport) int __cdecl PurifyHeapValidate(unsigned int hHeap, unsigned int dwFlags, const void *addr)
{
    avoidGy_27++;
    hHeap;
    dwFlags;
    addr;
    return 1;
}

// FUNCTION: STUNTGP_D3D 0x45f460
__declspec(dllexport) int __cdecl PurifySetLateDetectScanCounter(int counter)
{
    avoidGy_28++;
    counter;
    return 0;
};

// FUNCTION: STUNTGP_D3D 0x45f470
__declspec(dllexport) int __cdecl PurifySetLateDetectScanInterval(int seconds)
{
    avoidGy_29++;
    seconds;
    return 0;
};

// FUNCTION: STUNTGP_D3D 0x45f480
__declspec(dllexport) int __cdecl CoverageIsRunning(void)
{
    avoidGy_30++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f490
__declspec(dllexport) int __cdecl CoverageDisableRecordingData(void)
{
    avoidGy_31++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f4a0
__declspec(dllexport) int __cdecl CoverageStartRecordingData(void)
{
    avoidGy_32++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f4b0
__declspec(dllexport) int __cdecl CoverageStopRecordingData(void)
{
    avoidGy_33++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f4c0
__declspec(dllexport) int __cdecl CoverageClearData(void)
{
    avoidGy_34++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f4d0
__declspec(dllexport) int __cdecl CoverageIsRecordingData(void)
{
    avoidGy_35++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f4e0
__declspec(dllexport) int __cdecl CoverageAddAnnotation(char *str)
{
    avoidGy_36++;
    str;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f4f0
__declspec(dllexport) int __cdecl CoverageSaveData(void)
{
    avoidGy_37++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f500
__declspec(dllexport) int __cdecl QuantifyIsRunning(void)
{
    avoidGy_38++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f510
__declspec(dllexport) int __cdecl QuantifyDisableRecordingData(void)
{
    avoidGy_39++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f520
__declspec(dllexport) int __cdecl QuantifyStartRecordingData(void)
{
    avoidGy_40++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f530
__declspec(dllexport) int __cdecl QuantifyStopRecordingData(void)
{
    avoidGy_41++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f540
__declspec(dllexport) int __cdecl QuantifyClearData(void)
{
    avoidGy_42++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f550
__declspec(dllexport) int __cdecl QuantifyIsRecordingData(void)
{
    avoidGy_43++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f560
__declspec(dllexport) int __cdecl QuantifyAddAnnotation(char *str)
{
    avoidGy_44++;
    str;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f570
__declspec(dllexport) int __cdecl QuantifySaveData(void)
{
    avoidGy_45++;
    return 0;
}

// FUNCTION: STUNTGP_D3D 0x45f580
__declspec(dllexport) int __cdecl PurelockIsRunning(void)
{
    avoidGy_46++;
    return 0;
}
