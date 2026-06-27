#include "windowInit.h"
#include "Game/GameEngine/io_wad.h"

// TODO: should we set this as a struct???
// GLOBAL: STUNTGP_D3D 0x4754d0
errorMessage errorMessages[] = {
    {"No Error", DD_OK},
    {" This object is already initialised", DDERR_ALREADYINITIALIZED},
    {" This surface can not be attached to the requested surface.", DDERR_CANNOTATTACHSURFACE},
    {" This surface can not be detached from the requested surface.", DDERR_CANNOTDETACHSURFACE},
    {" Support is currently not available.", DDERR_CURRENTLYNOTAVAIL},
    {" An exception was encountered while performing the requested operation", DDERR_EXCEPTION},
    {"Generic failure.", DDERR_GENERIC},
    {" Height of rectangle provided is not a multiple of reqd alignment", DDERR_HEIGHTALIGN},
    {" Unable to match primary surface creation request with existing primary surface.", DDERR_INCOMPATIBLEPRIMARY},
    {" One or more of the caps bits passed to the callback are incorrect.", DDERR_INVALIDCAPS},
    {" DirectDraw does not support provided Cliplist.", DDERR_INVALIDCLIPLIST},
    {" DirectDraw does not support the requested mode", DDERR_INVALIDMODE},
    {" DirectDraw received a pointer that was an invalid DIRECTDRAW object.", DDERR_INVALIDOBJECT},
    {"One or more of the parameters passed to the callback function are incorrect.", DDERR_INVALIDPARAMS},
    {" pixel format was invalid as specified", DDERR_INVALIDPIXELFORMAT},
    {" Rectangle provided was invalid.", DDERR_INVALIDRECT},
    {" Operation could not be carried out because one or more surfaces are locked", DDERR_LOCKEDSURFACES},
    {" There is no 3D present.", DDERR_NO3D},
    {" Operation could not be carried out because there is no alpha accleration hardware present or available.",
     DDERR_NOALPHAHW},
    {" no clip list available", DDERR_NOCLIPLIST},
    {" Operation could not be carried out because there is no color conversion hardware present or available.",
     DDERR_NOCOLORCONVHW},
    {" Create function called without DirectDraw object method SetCooperativeLevel being called.",
     DDERR_NOCOOPERATIVELEVELSET},
    {" Surface doesn't currently have a color key", DDERR_NOCOLORKEY},
    {" Operation could not be carried out because there is no hardware support of the dest color key.",
     DDERR_NOCOLORKEYHW},
    {" No DirectDraw support possible with current display driver", DDERR_NODIRECTDRAWSUPPORT},
    {" Operation requires the application to have exclusive mode but the application does not have exclusive mode.",
     DDERR_NOEXCLUSIVEMODE},
    {" Flipping visible surfaces is not supported.", DDERR_NOFLIPHW},
    {" There is no GDI present.", DDERR_NOGDI},
    {" Operation could not be carried out because there is no hardware present or available.", DDERR_NOMIRRORHW},
    {" Requested item was not found", DDERR_NOTFOUND},
    {" Operation could not be carried out because there is no overlay hardware present or available.",
     DDERR_NOOVERLAYHW},
    {" Operation could not be carried out because there is no appropriate raster op hardware present or available.",
     DDERR_NORASTEROPHW},
    {" Operation could not be carried out because there is no rotation hardware present or available.",
     DDERR_NOROTATIONHW},
    {" Operation could not be carried out because there is no hardware support for stretching", DDERR_NOSTRETCHHW},
    {" DirectDrawSurface is not in 4 bit color palette and the requested operation requires 4 bit color palette.",
     DDERR_NOT4BITCOLOR},
    {" DirectDrawSurface is not in 4 bit color index palette and the requested operation requires 4 bit color index "
     "palette.",
     DDERR_NOT4BITCOLORINDEX},
    {" DirectDraw Surface is not in 8 bit color mode and the requested operation requires 8 bit color.",
     DDERR_NOT8BITCOLOR},
    {" Operation could not be carried out because there is no texture mapping hardware present or available.",
     DDERR_NOTEXTUREHW},
    {" Operation could not be carried out because there is no hardware support for vertical blank synchronized "
     "operations.",
     DDERR_NOVSYNCHW},
    {" Operation could not be carried out because there is no hardware support for zbuffer blting.", DDERR_NOZBUFFERHW},
    {" Overlay surfaces could not be z layered based on their BltOrder because the hardware does not support z "
     "layering of overlays.",
     DDERR_NOZOVERLAYHW},
    {" The hardware needed for the requested operation has already been allocated.", DDERR_OUTOFCAPS},
    {"DirectDraw does not have enough memory to perform the operation.", DDERR_OUTOFMEMORY},
    {" DirectDraw does not have enough memory to perform the operation.", DDERR_OUTOFVIDEOMEMORY},
    {" hardware does not support clipped overlays", DDERR_OVERLAYCANTCLIP},
    {" Can only have ony color key active at one time for overlays", DDERR_OVERLAYCOLORKEYONLYONEACTIVE},
    {" Access to this palette is being refused because the palette is already locked by another thread.",
     DDERR_PALETTEBUSY},
    {" No src color key specified for this operation.", DDERR_COLORKEYNOTSET},
    {" This surface is already attached to the surface it is being attached to.", DDERR_SURFACEALREADYATTACHED},
    {" This surface is already a dependency of the surface it is being made a dependency of.",
     DDERR_SURFACEALREADYDEPENDENT},
    {" Access to this surface is being refused because the surface is already locked by another thread.",
     DDERR_SURFACEBUSY},
    {"Access to this surface is being refused because no driver existswhich can supply a pointer to the surface.This "
     "is most likely to happen when attempting to lock the primarysurface when no DCI provider is present.",
     DDERR_CANTLOCKSURFACE},
    {" Access to Surface refused because Surface is obscured.", DDERR_SURFACEISOBSCURED},
    {" Access to this surface is being refused because the surface is gone.The DIRECTDRAWSURFACE object representing "
     "this surface should have Restore called on it.",
     DDERR_SURFACELOST},
    {" The requested surface is not attached.", DDERR_SURFACENOTATTACHED},
    {" Height requested by DirectDraw is too large.", DDERR_TOOBIGHEIGHT},
    {" Size requested by DirectDraw is too large --  The individual height and width are OK.", DDERR_TOOBIGSIZE},
    {" Width requested by DirectDraw is too large.", DDERR_TOOBIGWIDTH},
    {"Action not supported.", DDERR_UNSUPPORTED},
    {" FOURCC format requested is unsupported by DirectDraw", DDERR_UNSUPPORTEDFORMAT},
    {" Bitmask in the pixel format requested is unsupported by DirectDraw", DDERR_UNSUPPORTEDMASK},
    {" vertical blank is in progress", DDERR_VERTICALBLANKINPROGRESS},
    {" Informs DirectDraw that the previous Blt which is transfering information to or from this Surface is "
     "incomplete.",
     DDERR_WASSTILLDRAWING},
    {" Rectangle provided was not horizontally aligned on reqd. boundary", DDERR_XALIGN},
    {" The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.", DDERR_INVALIDDIRECTDRAWGUID},
    {" A DirectDraw object representing this driver has already been created for this process.",
     DDERR_DIRECTDRAWALREADYCREATED},
    {" A hardware only DirectDraw object creation was attempted but the driver did not support any hardware.",
     DDERR_NODIRECTDRAWHW},
    {" this process already has created a primary surface", DDERR_PRIMARYSURFACEALREADYEXISTS},
    {" software emulation not available.", DDERR_NOEMULATION},
    {" region passed to Clipper::GetClipList is too small.", DDERR_REGIONTOOSMALL},
    {" an attempt was made to set a clip list for a clipper objec that is already monitoring an hwnd.",
     DDERR_CLIPPERISUSINGHWND},
    {" No clipper object attached to surface object", DDERR_NOCLIPPERATTACHED},
    {" Clipper notification requires an HWND or no HWND has previously been set as the CooperativeLevel HWND.",
     DDERR_NOHWND},
    {" HWND used by DirectDraw CooperativeLevel has been subclassed, this prevents DirectDraw from restoring state.",
     DDERR_HWNDSUBCLASSED},
    {" The CooperativeLevel HWND has already been set. It can not be reset while the process has surfaces or palettes "
     "created.",
     DDERR_HWNDALREADYSET},
    {" No palette object attached to this surface.", DDERR_NOPALETTEATTACHED},
    {" No hardware support for 16 or 256 color palettes.", DDERR_NOPALETTEHW},
    {" If a clipper object is attached to the source surface passed into a BltFast call.", DDERR_BLTFASTCANTCLIP},
    {" No blter.", DDERR_NOBLTHW},
    {" No DirectDraw ROP hardware.", DDERR_NODDROPSHW},
    {" returned when GetOverlayPosition is called on a hidden overlay", DDERR_OVERLAYNOTVISIBLE},
    {" returned when GetOverlayPosition is called on a overlay that UpdateOverlay has never been called on to "
     "establish a destionation.",
     DDERR_NOOVERLAYDEST},
    {" returned when the position of the overlay on the destionation is no Sint32er legal for that destionation.",
     DDERR_INVALIDPOSITION},
    {" returned when an overlay member is called for a non-overlay surface", DDERR_NOTAOVERLAYSURFACE},
    {" An attempt was made to set the cooperative level when it was already set to exclusive.",
     DDERR_EXCLUSIVEMODEALREADYSET},
    {" An attempt has been made to flip a surface that is not flippable.", DDERR_NOTFLIPPABLE},
    {" Can't duplicate primary & 3D surfaces, or surfaces that are implicitly created.", DDERR_CANTDUPLICATE},
    {" Surface was not locked.  An attempt to unlock a surface that was not locked at all, or by this process, has "
     "been attempted.",
     DDERR_NOTLOCKED},
    {" Windows can not create any more DCs", DDERR_CANTCREATEDC},
    {" No DC was ever created for this surface.", DDERR_NODC},
    {" This surface can not be restored because it was created in a different mode.", DDERR_WRONGMODE},
    {" This surface can not be restored because it is an implicitly created surface.", DDERR_IMPLICITLYCREATED},
    {" The surface being used is not a palette-based surface", DDERR_NOTPALETTIZED},
    {" The display is currently in an unsupported mode", DDERR_UNSUPPORTEDMODE},
    {" Operation could not be carried out because there is no mip-map texture mapping hardware present or available.",
     DDERR_NOMIPMAPHW},
    {" The requested action could not be performed because the surface was of the wrong type.",
     DDERR_INVALIDSURFACETYPE},
    {" A DC has already been returned for this surface. Only one DC can be retrieved per surface.",
     DDERR_DCALREADYCREATED},
    {" The attempt to page lock a surface failed.", DDERR_CANTPAGELOCK},
    {" The attempt to page unlock a surface failed.", DDERR_CANTPAGEUNLOCK},
    {" An attempt was made to page unlock a surface with no outstanding page locks.", DDERR_NOTPAGELOCKED},
    {" An attempt was made to invoke an interface member of a DirectDraw object created by CoCreateInstance(), before "
     "it was initialized.",
     DDERR_NOTINITIALIZED},
    {NULL, NULL}};

int DAT_CAPS = {0};

// FUNCTION: STUNTGP_D3D 0x422700
HWND windowCreateInternal(HINSTANCE hInstance, LPCTSTR className, LPCTSTR windowName)
{
    int height = GetSystemMetrics(SM_CYFULLSCREEN);
    int width = GetSystemMetrics(SM_CXFULLSCREEN);
    HWND wHandle = CreateWindowEx(WS_EX_APPWINDOW, className, windowName, WS_POPUP, 0, 0, width, height, NULL, NULL,
                                  hInstance, NULL);
    if (!wHandle)
    {
        return NULL;
    }
    ShowWindow(wHandle, SW_NORMAL);
    UpdateWindow(wHandle);
    return wHandle;
}

// FUNCTION: STUNTGP_D3D 0x422690
LPCTSTR ddGetErrMessage(int res)
{
    int elements = {0};
    // GLOBAL: STUNTGP_D3D 0x572ae4
    static TCHAR message[256] = {0};

    if (errorMessages[0].message)
    {
        errorMessage *errorMessagePtr = errorMessages;
        for (; errorMessagePtr != NULL; errorMessagePtr++)
        {
            if (errorMessagePtr->code == res)
            {
                // STRING: STUNTGP_D3D 0x477570
#if defined(UNICODE)
                MultiByteToWideChar(CP_ACP, 0, errorMessagePtr->message, -1, message, 255);
                _tcscat(message, _T("\n"));
#else
                sprintf(message, "%s\n", errorMessagePtr->message);
#endif
                return message;
            }
        }
        elements++;
    }
    // STRING: STUNTGP_D3D 0x477574
    _stprintf(message, _T("No Text For Error : %.8x\n"), res);
    return message;
    // TODO
}

// // STUB: STUNTGP_D3D 0x422780
// void FUN_422780()
// {
// }

// // STUB: STUNTGP_D3D 0x4227b0
// void FUN_4227b0()
// {
// }

// TODO: move to another file, this shouldn't inline at all
// FUNCTION: STUNTGP_D3D 0x422780
int ddSetCoopLevel(LPDIRECTDRAW lplpDD, HWND hWnd)
{
    int res = lplpDD->SetCooperativeLevel(hWnd, DDSCL_FULLSCREEN | DDSCL_ALLOWREBOOT | DDSCL_EXCLUSIVE);
    if (res != DD_OK)
    {
        exitError(ddGetErrMessage(res));
    }
    return res;
}

// FUNCTION: STUNTGP_D3D 0x4227e0
int windowDDCreate(LPDIRECTDRAW *lplpDD, GUID *lpGUID, HWND hWnd)
{
    int res = {0};
    res = DirectDrawCreate(lpGUID, lplpDD, NULL);
    if (res != DD_OK)
    {
        exitError(ddGetErrMessage(res));
    }
    ddSetCoopLevel(*lplpDD, hWnd);
    return res;
}

// FUNCTION: STUNTGP_D3D 0x4227b0
int dd4SetCoopLevel(LPDIRECTDRAW4 ppvObj, HWND hWnd)
{
    // TODO; move the last parameter to define and use in both SetCooperativeLevel?
    int res = ppvObj->SetCooperativeLevel(hWnd, DDSCL_FULLSCREEN | DDSCL_ALLOWREBOOT | DDSCL_EXCLUSIVE);
    if (res != DD_OK)
    {
        exitError(ddGetErrMessage(res));
    }
    return res;
}

// STUB: STUNTGP_D3D 0x422820
int ddGetDD4(LPDIRECTDRAW lplpDD, LPDIRECTDRAW4 *ppvObj, HWND hWnd)
{
    int res = lplpDD->QueryInterface(IID_IDirectDraw4, (LPVOID *)ppvObj);
    if (res != DD_OK)
    {
        exitError(ddGetErrMessage(res));
    }
    dd4SetCoopLevel(*ppvObj, hWnd);
    return res;
}

// // STUB: STUNTGP_D3D 0x422860
// void FUN_422860()
// {
// }

// // STUB: STUNTGP_D3D 0x422880
// void FUN_422880()
// {
// }

// // STUB: STUNTGP_D3D 0x4228a0
// void FUN_4228a0()
// {
// }

// // STUB: STUNTGP_D3D 0x4228c0
// void FUN_4228c0()
// {
// }

// // STUB: STUNTGP_D3D 0x4228e0
// void FUN_4228e0()
// {
// }

// // STUB: STUNTGP_D3D 0x422910 - unused
// void FUN_422910()
// {
// }

// // STUB: STUNTGP_D3D 0x422930
// void FUN_422930()
// {
// }

// FUNCTION: STUNTGP_D3D 0x422950
int ddGetMemory(LPDIRECTDRAW4 lpDD4, LPDWORD totalVideoMem, LPDWORD totalTextureMem, LPDWORD freeMem)
{
    DWORD dwTotal = {0};
    DWORD dwFree = {0};

    DDSCAPS2 ddsCaps2 = {0};
    ddsCaps2.dwCaps = DDSCAPS_VIDEOMEMORY;
    int res = lpDD4->GetAvailableVidMem(&ddsCaps2, &dwTotal, &dwFree);
    if (res == DD_OK)
    {
        *totalVideoMem = dwTotal;
        *freeMem = dwFree;
#if defined(SGP_DEBUG)
        TCHAR buffer[256] = {0};
        _stprintf(buffer, _T("Free/Total video mem: %lu/%lu MB"), dwFree / 1024 / 1024, dwTotal / 1024 / 1024);
        OutputDebugString(buffer);
#endif
        DDSCAPS2 textureCaps = {0};
        textureCaps.dwCaps = DDSCAPS_TEXTURE;
        res = lpDD4->GetAvailableVidMem(&textureCaps, &dwTotal, &dwFree);
        if (res == DD_OK)
        {
            *totalTextureMem = dwTotal;
            res = DD_OK;
#if defined(SGP_DEBUG)
            _stprintf(buffer, _T("Free/total texture mem: %lu/%lu MB"), dwFree / 1024 / 1024, dwTotal / 1024 / 1024);
            OutputDebugString(buffer);
#endif
        }
    }
    return res;
}

// // STUB: STUNTGP_D3D 0x4229e0
// void FUN_4229e0()
// {
// }

// // STUB: STUNTGP_D3D 0x422a00
// void FUN_422a00()
// {
// }

// // STUB: STUNTGP_D3D 0x422a20
// void FUN_422a20()
// {
// }

// // STUB: STUNTGP_D3D 0x422a60
// void FUN_422a60()
// {
// }

// // STUB: STUNTGP_D3D 0x422a80
// void FUN_422a80()
// {
// }

// // STUB: STUNTGP_D3D 0x422ac0
// void FUN_422ac0()
// {
// }

// // STUB: STUNTGP_D3D 0x422b50
// void FUN_422b50()
// {
// }

// // STUB: STUNTGP_D3D 0x422ba0
// void FUN_422ba0()
// {
// }

// // STUB: STUNTGP_D3D 0x422bb0
// void FUN_422bb0()
// {
// }

// // STUB: STUNTGP_D3D 0x422bf0
// void FUN_422bf0()
// {
// }

// // STUB: STUNTGP_D3D 0x422c60
// void FUN_422c60()
// {
// }

// // STUB: STUNTGP_D3D 0x422d50
// void FUN_422d50()
// {
// }

// // STUB: STUNTGP_D3D 0x422df0
// void FUN_422df0()
// {
// }

// // STUB: STUNTGP_D3D 0x422ea0
// void FUN_422ea0()
// {
// }

// STUB: STUNTGP_D3D 0x422a00
void FUN_422a00(LPDIRECTDRAWSURFACE4 *surface)
{
    if (!surface || !*surface)
    {
        return;
    }

    (*surface)->Release();
    *surface = NULL;
}

static int clearSurface(LPDIRECTDRAWSURFACE4 surface, DWORD color)
{
    if (!surface)
    {
        return DDERR_INVALIDPARAMS;
    }

    DDBLTFX bltFx = {0};
    bltFx.dwSize = sizeof(bltFx);
    bltFx.dwFillColor = color;
    return surface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &bltFx);
}

static int fillSurfaceRect(LPDIRECTDRAWSURFACE4 surface, RECT *rect, DWORD color)
{
    if (!surface)
    {
        return DDERR_INVALIDPARAMS;
    }

    DDBLTFX bltFx = {0};
    bltFx.dwSize = sizeof(bltFx);
    bltFx.dwFillColor = color;
    return surface->Blt(rect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &bltFx);
}

int clearSurfaceBlack(LPDIRECTDRAWSURFACE4 surface)
{
    return clearSurface(surface, 0);
}

static DWORD rgbToDisplayColor(int red, int green, int blue)
{
    if (g_DISPLAYRESDEPTH == 16)
    {
        return ((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3);
    }
    if (g_DISPLAYRESDEPTH == 15)
    {
        return ((red >> 3) << 10) | ((green >> 3) << 5) | (blue >> 3);
    }
    if ((g_DISPLAYRESDEPTH == 24) || (g_DISPLAYRESDEPTH == 32))
    {
        return (red << 16) | (green << 8) | blue;
    }
    return 0;
}

static DWORD rgb565ToDisplayColor(unsigned short color)
{
    int red = ((color >> 11) & 0x1f) << 3;
    int green = ((color >> 5) & 0x3f) << 2;
    int blue = (color & 0x1f) << 3;
    return rgbToDisplayColor(red, green, blue);
}

static DWORD rgb555ToDisplayColor(unsigned short color)
{
    int red = ((color >> 10) & 0x1f) << 3;
    int green = ((color >> 5) & 0x1f) << 3;
    int blue = (color & 0x1f) << 3;
    return rgbToDisplayColor(red, green, blue);
}

static unsigned short readWord(unsigned char *bytes)
{
    return bytes[0] | (bytes[1] << 8);
}

static int readInt(unsigned char *bytes)
{
    return bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24);
}

static float readFloat(unsigned char *bytes)
{
    float value = 0.0f;
    memcpy(&value, bytes, sizeof(value));
    return value;
}

static int align32(int value)
{
    int padding = 32 - (value % 32);
    if (padding < 32)
    {
        value += padding;
    }
    return value;
}

static void drawLockedLine(unsigned char *destBase, int pitch, int width, int height, int x0, int y0, int x1, int y1,
                           WORD color);

static void normalizePmdTexturePath(char *out, int outSize, const char *name)
{
    char fixed[128] = {0};
    int outPos = 0;
    for (int i = 0; name[i] && (outPos < (int)sizeof(fixed) - 1); i++)
    {
        if ((name[i] == '\\') && (name[i + 1] == '\\'))
        {
            fixed[outPos++] = '\\';
            i++;
        }
        else
        {
            fixed[outPos++] = name[i];
        }
    }
    fixed[outPos] = '\0';
    sprintf(out, "graphics24\\%s.pc", fixed);
    out[outSize - 1] = '\0';
}

static BOOL readPmdMaterialUvProbe(char *texturePath, int texturePathSize, float *uvU, float *uvV, int *uvCount,
                                   int *materialIndex)
{
    char meshPath[128] = {0};
    sprintf(meshPath, "meshdata\\%s.PMD", g_LevelCars[0].mesh);
    int meshSize = size_of_file(meshPath);
    if (meshSize <= 0)
    {
        return FALSE;
    }

    unsigned char *meshBytes = (unsigned char *)malloc(meshSize);
    if (!meshBytes)
    {
        return FALSE;
    }

    BOOL result = FALSE;
    int bytesRead = bload(meshPath, (char *)meshBytes, meshSize);
    if ((bytesRead >= 480) && (memcmp(meshBytes, "PMD", 3) == 0))
    {
        int sizesOffset = 0xb0;
        int faceBytes = readInt(meshBytes + sizesOffset + (5 * 4));
        int vertexBytes = readInt(meshBytes + sizesOffset + (4 * 4));
        int verts2Bytes = readInt(meshBytes + sizesOffset + (1 * 4));
        int uvBytes = readInt(meshBytes + sizesOffset + (3 * 4));
        int polygonBytes = readInt(meshBytes + sizesOffset + (2 * 4));
        int transformBytes = readInt(meshBytes + sizesOffset + (10 * 4));
        int surfaceBytes = readInt(meshBytes + sizesOffset + (11 * 4));
        int someCoordsBytes = readInt(meshBytes + sizesOffset + (8 * 4));
        int someArrayBytes = readInt(meshBytes + sizesOffset + (9 * 4));
        int textureBytes = readInt(meshBytes + sizesOffset + (6 * 4));
        int vertexOffset = align32(480 + faceBytes);
        int uvOffset = align32(vertexOffset + vertexBytes + verts2Bytes);
        int polyOffset = align32(uvOffset + uvBytes);
        int transformOffset = align32(polyOffset + polygonBytes);
        int surfaceOffset = align32(transformOffset + transformBytes);
        int textureOffset = align32(align32(surfaceOffset + surfaceBytes) + someCoordsBytes);
        textureOffset = align32(textureOffset + someArrayBytes);
        int polygonCount = polygonBytes / 8;
        int faceCount = faceBytes / 2;
        int uvCountTotal = uvBytes / 16;

        if ((polygonCount > 0) && (polyOffset + polygonBytes <= bytesRead) && (textureOffset + textureBytes <= bytesRead))
        {
            unsigned char *poly = meshBytes + polyOffset;
            int count = poly[0];
            int mat = poly[1];
            int faceStart = readWord(poly + 6);
            if ((count >= 3) && (count <= 4) && (faceStart + count <= faceCount))
            {
                *uvCount = count;
                *materialIndex = mat;
                for (int i = 0; i < count; i++)
                {
                    int uvIndex = (short)readWord(meshBytes + 480 + ((faceStart + i) * 2));
                    if ((uvIndex < 0) || (uvIndex >= uvCountTotal))
                    {
                        result = FALSE;
                        break;
                    }
                    unsigned char *uv = meshBytes + uvOffset + (uvIndex * 16);
                    uvU[i] = readFloat(uv);
                    uvV[i] = -readFloat(uv + 4);
                    result = TRUE;
                }

                char *name = (char *)(meshBytes + textureOffset);
                int currentMaterial = 0;
                while ((currentMaterial < mat) && (name < (char *)(meshBytes + textureOffset + textureBytes)))
                {
                    name += strlen(name) + 1;
                    currentMaterial++;
                }
                if (result && (name < (char *)(meshBytes + textureOffset + textureBytes)) && *name)
                {
                    normalizePmdTexturePath(texturePath, texturePathSize, name);
                }
                else
                {
                    result = FALSE;
                }
            }
        }
    }

    free(meshBytes);
    return result;
}

int clearSurfaceGameColor(LPDIRECTDRAWSURFACE4 surface)
{
    static BOOL logged = FALSE;
    DWORD color = rgbToDisplayColor(g_LevelFogR, g_LevelFogG, g_LevelFogB);
    if (!logged)
    {
        traceLog("clear color fog=%d,%d,%d depth=%d fill=0x%08x", g_LevelFogR, g_LevelFogG, g_LevelFogB, g_DISPLAYRESDEPTH,
                 color);
        logged = TRUE;
    }
    return clearSurface(surface, color);
}

static int decompressPcTexture(unsigned char *in, int inSize, unsigned short *out, int maxWords, int *underflowCount)
{
    int inPos = 0;
    int outPos = 0;
    *underflowCount = 0;
    if ((inSize < 2) || (maxWords <= 0))
    {
        return 0;
    }

    out[outPos++] = readWord(in + inPos);
    inPos += 2;
    while ((inPos + 1 < inSize) && (outPos < maxWords))
    {
        unsigned short word = readWord(in + inPos);
        while ((word & 0x8000) && (inPos + 1 < inSize) && (outPos < maxWords))
        {
            inPos += 2;
            out[outPos++] = word;
            if (inPos + 1 >= inSize)
            {
                break;
            }
            word = readWord(in + inPos);
        }
        if (inPos + 1 >= inSize)
        {
            break;
        }

        unsigned short token = readWord(in + inPos);
        inPos += 2;
        if (token & 0x4000)
        {
            int distance = (token & 0x07ff) + 1;
            int count = ((token >> 11) & 7) + 2;
            int source = outPos - distance;
            if (source < 0)
            {
                *underflowCount += 1;
            }
            for (int i = 0; (i < count) && (outPos < maxWords); i++)
            {
                int sourceIndex = source + i;
                out[outPos++] = (sourceIndex >= 0) && (sourceIndex < outPos) ? out[sourceIndex] : 0;
            }
        }
        else
        {
            int count = token & 0x3fff;
            if (count == 0)
            {
                break;
            }
            for (int i = 0; (i < count) && (outPos < maxWords); i++)
            {
                out[outPos++] = 0;
            }
        }
    }
    return outPos;
}

static float triangleEdge(float ax, float ay, float bx, float by, float px, float py)
{
    return ((px - ax) * (by - ay)) - ((py - ay) * (bx - ax));
}

static int drawTexturedUvTriangle(unsigned char *destBase, int pitch, int width, int height, int x0, int y0, int x1,
                                  int y1, int x2, int y2, float *uvU, float *uvV, unsigned short *pixels,
                                  int textureWidth, int textureHeight, int decodedWords)
{
    int minX = x0;
    int maxX = x0;
    int minY = y0;
    int maxY = y0;
    if (x1 < minX)
    {
        minX = x1;
    }
    if (x2 < minX)
    {
        minX = x2;
    }
    if (x1 > maxX)
    {
        maxX = x1;
    }
    if (x2 > maxX)
    {
        maxX = x2;
    }
    if (y1 < minY)
    {
        minY = y1;
    }
    if (y2 < minY)
    {
        minY = y2;
    }
    if (y1 > maxY)
    {
        maxY = y1;
    }
    if (y2 > maxY)
    {
        maxY = y2;
    }
    if (minX < 0)
    {
        minX = 0;
    }
    if (minY < 0)
    {
        minY = 0;
    }
    if (maxX >= width)
    {
        maxX = width - 1;
    }
    if (maxY >= height)
    {
        maxY = height - 1;
    }

    float area = triangleEdge((float)x0, (float)y0, (float)x1, (float)y1, (float)x2, (float)y2);
    if ((area > -0.001f) && (area < 0.001f))
    {
        return 0;
    }

    int drawn = 0;
    for (int y = minY; y <= maxY; y++)
    {
        WORD *dest = (WORD *)(destBase + (y * pitch));
        for (int x = minX; x <= maxX; x++)
        {
            float px = (float)x + 0.5f;
            float py = (float)y + 0.5f;
            float w0 = triangleEdge((float)x1, (float)y1, (float)x2, (float)y2, px, py) / area;
            float w1 = triangleEdge((float)x2, (float)y2, (float)x0, (float)y0, px, py) / area;
            float w2 = triangleEdge((float)x0, (float)y0, (float)x1, (float)y1, px, py) / area;
            if ((w0 >= 0.0f) && (w1 >= 0.0f) && (w2 >= 0.0f))
            {
                float u = (uvU[0] * w0) + (uvU[1] * w1) + (uvU[2] * w2);
                float v = (uvV[0] * w0) + (uvV[1] * w1) + (uvV[2] * w2);
                int sourceX = (int)(u * (float)textureWidth);
                int sourceY = (int)(v * (float)textureHeight);
                if (sourceX < 0)
                {
                    sourceX = 0;
                }
                if (sourceY < 0)
                {
                    sourceY = 0;
                }
                if (sourceX >= textureWidth)
                {
                    sourceX = textureWidth - 1;
                }
                if (sourceY >= textureHeight)
                {
                    sourceY = textureHeight - 1;
                }
                int sample = (sourceY * textureWidth) + sourceX;
                if (sample >= decodedWords)
                {
                    sample = sample % decodedWords;
                }
                dest[x] = (WORD)rgb555ToDisplayColor(pixels[sample]);
                drawn++;
            }
        }
    }
    return drawn;
}

static void drawTextureDecodedSwatch(LPDIRECTDRAWSURFACE4 surface)
{
    static BOOL loaded = FALSE;
    static BOOL logged = FALSE;
    static unsigned short *pixels = NULL;
    static int textureSize = 0;
    static int textureWidth = 0;
    static int textureHeight = 0;
    static int decodedWords = 0;
    static int underflowCount = 0;
    static int texturedTrianglePixels = 0;
    static float probeU[4] = {0.0f};
    static float probeV[4] = {0.0f};
    static int probeUvCount = 0;
    static int probeMaterial = 0;
    static char texturePath[128] = {0};

    if (!loaded)
    {
        if (!readPmdMaterialUvProbe(texturePath, sizeof(texturePath), probeU, probeV, &probeUvCount, &probeMaterial))
        {
            int fallbackLivery = g_LevelCars[0].livery > 0 ? g_LevelCars[0].livery : 1;
            sprintf(texturePath, "graphics24\\cars\\car%d\\b%dgrid%d.pc", g_LevelCars[0].config, g_LevelCars[0].config, fallbackLivery);
        }
        textureSize = size_of_file(texturePath);
        if (textureSize > 0)
        {
            unsigned char *textureBytes = (unsigned char *)malloc(textureSize);
            if (textureBytes)
            {
                int bytesRead = bload(texturePath, (char *)textureBytes, textureSize);
                if (bytesRead != textureSize)
                {
                    textureSize = bytesRead;
                }
                if (textureSize >= 10)
                {
                    textureWidth = textureBytes[6] | (textureBytes[7] << 8);
                    textureHeight = textureBytes[8] | (textureBytes[9] << 8);
                    pixels = (unsigned short *)malloc(textureWidth * textureHeight * sizeof(unsigned short));
                    if (pixels)
                    {
                        decodedWords =
                            decompressPcTexture(textureBytes + 10, textureSize - 10, pixels, textureWidth * textureHeight,
                                                &underflowCount);
                    }
                }
                free(textureBytes);
            }
        }
        loaded = TRUE;
    }

    if (!pixels || (decodedWords <= 0) || (GetAsyncKeyState(VK_ESCAPE) & 0x8000))
    {
        return;
    }

    int drawSize = 128;
    int startX = g_DISPLAYRESWIDTH - (drawSize + 48);
    int startY = 48;
    if (startX < 0)
    {
        startX = 0;
    }

    int probeGap = 24;
    int probeSize = 112;
    int panelHeight = drawSize + probeGap + probeSize;

    RECT rect = {0};
    rect.left = startX;
    rect.top = startY;
    rect.right = startX + drawSize;
    rect.bottom = startY + panelHeight;

    DDSURFACEDESC2 desc = {0};
    desc.dwSize = sizeof(desc);
    int lockRes = surface->Lock(&rect, &desc, DDLOCK_WAIT, NULL);
    if (lockRes == DD_OK)
    {
        unsigned char *destBase = (unsigned char *)desc.lpSurface;
        WORD bgColor = (WORD)rgbToDisplayColor(20, 28, 36);
        for (int panelY = 0; panelY < panelHeight; panelY++)
        {
            WORD *dest = (WORD *)(destBase + (panelY * desc.lPitch));
            for (int panelX = 0; panelX < drawSize; panelX++)
            {
                dest[panelX] = bgColor;
            }
        }
        for (int y = 0; y < drawSize; y++)
        {
            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            {
                break;
            }
            WORD *dest = (WORD *)(destBase + (y * desc.lPitch));
            int sourceY = (y * textureHeight) / drawSize;
            for (int x = 0; x < drawSize; x++)
            {
                int sourceX = (x * textureWidth) / drawSize;
                int sample = (sourceY * textureWidth) + sourceX;
                if (sample >= decodedWords)
                {
                    sample = sample % decodedWords;
                }
                dest[x] = (WORD)rgb555ToDisplayColor(pixels[sample]);
            }
        }
        if (probeUvCount >= 3)
        {
            WORD uvColor = (WORD)rgbToDisplayColor(255, 255, 255);
            for (int edge = 0; edge < probeUvCount; edge++)
            {
                int next = (edge + 1) % probeUvCount;
                int x0 = (int)(probeU[edge] * (float)drawSize);
                int y0 = (int)(probeV[edge] * (float)drawSize);
                int x1 = (int)(probeU[next] * (float)drawSize);
                int y1 = (int)(probeV[next] * (float)drawSize);
                drawLockedLine(destBase, desc.lPitch, drawSize, drawSize, x0, y0, x1, y1, uvColor);
            }
            int triY = drawSize + probeGap;
            int triX0 = 12;
            int triY0 = triY + probeSize - 10;
            int triX1 = drawSize - 12;
            int triY1 = triY + probeSize - 10;
            int triX2 = drawSize / 2;
            int triY2 = triY + 8;
            texturedTrianglePixels =
                drawTexturedUvTriangle(destBase, desc.lPitch, drawSize, panelHeight, triX0, triY0, triX1, triY1, triX2,
                                       triY2, probeU, probeV, pixels, textureWidth, textureHeight, decodedWords);
            drawLockedLine(destBase, desc.lPitch, drawSize, panelHeight, triX0, triY0, triX1, triY1, uvColor);
            drawLockedLine(destBase, desc.lPitch, drawSize, panelHeight, triX1, triY1, triX2, triY2, uvColor);
            drawLockedLine(destBase, desc.lPitch, drawSize, panelHeight, triX2, triY2, triX0, triY0, uvColor);
        }
        surface->Unlock(&rect);
    }

    if (!logged)
    {
        traceLog("texture decoded swatch path=%s size=%d headerWidth=%d headerHeight=%d decodedWords=%d expectedWords=%d underflows=%d drawSize=%d origin=%d,%d lock=0x%08x uvMat=%d uvCount=%d uv0=%.3f,%.3f texturedTriPixels=%d",
                 texturePath,
                 textureSize,
                 textureWidth,
                 textureHeight,
                 decodedWords,
                 textureWidth * textureHeight,
                 underflowCount,
                 drawSize,
                 startX,
                 startY,
                 lockRes,
                 probeMaterial,
                 probeUvCount,
                 probeU[0],
                 probeV[0],
                 texturedTrianglePixels);
        logged = TRUE;
    }
}

struct PmdVertex2D
{
    float x;
    float z;
};

struct PmdPolyLine
{
    unsigned char count;
    unsigned char material;
    int surfaceOrdinal;
    float x[4];
    float z[4];
    float u[4];
    float v[4];
};

struct PmdUvRef
{
    short vertexIndex;
};

static void fillSmallPoint(LPDIRECTDRAWSURFACE4 surface, int x, int y, DWORD color)
{
    RECT point = {x, y, x + 2, y + 2};
    fillSurfaceRect(surface, &point, color);
}

static void drawLine2D(LPDIRECTDRAWSURFACE4 surface, int x0, int y0, int x1, int y1, DWORD color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx);
    if (abs(dy) > steps)
    {
        steps = abs(dy);
    }
    if (steps <= 0)
    {
        fillSmallPoint(surface, x0, y0, color);
        return;
    }

    for (int i = 0; i <= steps; i++)
    {
        int x = x0 + ((dx * i) / steps);
        int y = y0 + ((dy * i) / steps);
        fillSmallPoint(surface, x, y, color);
    }
}

static void plotLockedPixel(unsigned char *destBase, int pitch, int x, int y, int width, int height, WORD color)
{
    if ((x < 0) || (x >= width) || (y < 0) || (y >= height))
    {
        return;
    }
    WORD *dest = (WORD *)(destBase + (y * pitch));
    dest[x] = color;
}

static void drawLockedLine(unsigned char *destBase, int pitch, int width, int height, int x0, int y0, int x1, int y1,
                           WORD color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx);
    if (abs(dy) > steps)
    {
        steps = abs(dy);
    }
    if (steps <= 0)
    {
        plotLockedPixel(destBase, pitch, x0, y0, width, height, color);
        return;
    }

    for (int lineStep = 0; lineStep <= steps; lineStep++)
    {
        int x = x0 + ((dx * lineStep) / steps);
        int y = y0 + ((dy * lineStep) / steps);
        plotLockedPixel(destBase, pitch, x, y, width, height, color);
    }
}

static void drawPmdVertexPreview(LPDIRECTDRAWSURFACE4 surface)
{
    static BOOL loaded = FALSE;
    static BOOL logged = FALSE;
    static PmdVertex2D *vertices = NULL;
    static PmdPolyLine *polyLines = NULL;
    static int vertexCount = 0;
    static int faceCount = 0;
    static int polygonCount = 0;
    static int polyLineCount = 0;
    static int surfaceCount = 0;
    static unsigned short *texturePixels = NULL;
    static int textureWidth = 0;
    static int textureHeight = 0;
    static int textureDecodedWords = 0;
    static int textureUnderflows = 0;
    static int texturedPolyCount = 0;
    static int texturedPixelsDrawn = 0;
    static float minX = 0.0f;
    static float maxX = 0.0f;
    static float minZ = 0.0f;
    static float maxZ = 0.0f;
    static char meshPath[128] = {0};
    static char texturePath[128] = {0};

    if (!loaded)
    {
        float unusedU[4] = {0.0f};
        float unusedV[4] = {0.0f};
        int unusedUvCount = 0;
        int unusedMaterial = 0;
        if (readPmdMaterialUvProbe(texturePath, sizeof(texturePath), unusedU, unusedV, &unusedUvCount, &unusedMaterial))
        {
            int textureSize = size_of_file(texturePath);
            if (textureSize > 0)
            {
                unsigned char *textureBytes = (unsigned char *)malloc(textureSize);
                if (textureBytes)
                {
                    int textureBytesRead = bload(texturePath, (char *)textureBytes, textureSize);
                    if (textureBytesRead > 10)
                    {
                        textureWidth = textureBytes[6] | (textureBytes[7] << 8);
                        textureHeight = textureBytes[8] | (textureBytes[9] << 8);
                        texturePixels = (unsigned short *)malloc(textureWidth * textureHeight * sizeof(unsigned short));
                        if (texturePixels)
                        {
                            textureDecodedWords = decompressPcTexture(textureBytes + 10, textureBytesRead - 10,
                                                                      texturePixels, textureWidth * textureHeight,
                                                                      &textureUnderflows);
                        }
                    }
                    free(textureBytes);
                }
            }
        }
        sprintf(meshPath, "meshdata\\%s.PMD", g_LevelCars[0].mesh);
        int meshSize = size_of_file(meshPath);
        if (meshSize > 0)
        {
            unsigned char *meshBytes = (unsigned char *)malloc(meshSize);
            if (meshBytes)
            {
                int bytesRead = bload(meshPath, (char *)meshBytes, meshSize);
                if ((bytesRead >= 480) && (memcmp(meshBytes, "PMD", 3) == 0))
                {
                    int sizesOffset = 0xb0;
                    int faceBytes = readInt(meshBytes + sizesOffset + (5 * 4));
                    int vertexBytes = readInt(meshBytes + sizesOffset + (4 * 4));
                    int polygonBytes = readInt(meshBytes + sizesOffset + (2 * 4));
                    int transformBytes = readInt(meshBytes + sizesOffset + (10 * 4));
                    int surfaceBytes = readInt(meshBytes + sizesOffset + (11 * 4));
                    faceCount = faceBytes / 2;
                    vertexCount = vertexBytes / 16;
                    polygonCount = polygonBytes / 8;
                    surfaceCount = surfaceBytes / 64;

                    int vertexOffset = align32(480 + faceBytes);
                    if ((vertexCount > 0) && (vertexOffset + vertexBytes <= bytesRead))
                    {
                        vertices = (PmdVertex2D *)malloc(vertexCount * sizeof(PmdVertex2D));
                        if (vertices)
                        {
                            for (int i = 0; i < vertexCount; i++)
                            {
                                unsigned char *cursor = meshBytes + vertexOffset + (i * 16);
                                vertices[i].x = readFloat(cursor);
                                vertices[i].z = readFloat(cursor + 8);
                                if (i == 0)
                                {
                                    minX = maxX = vertices[i].x;
                                    minZ = maxZ = vertices[i].z;
                                }
                                else
                                {
                                    if (vertices[i].x < minX)
                                    {
                                        minX = vertices[i].x;
                                    }
                                    if (vertices[i].x > maxX)
                                    {
                                        maxX = vertices[i].x;
                                    }
                                    if (vertices[i].z < minZ)
                                    {
                                        minZ = vertices[i].z;
                                    }
                                    if (vertices[i].z > maxZ)
                                    {
                                        maxZ = vertices[i].z;
                                    }
                                }
                            }
                        }
                    }
                    int verts2Bytes = readInt(meshBytes + sizesOffset + (1 * 4));
                    int uvBytes = readInt(meshBytes + sizesOffset + (3 * 4));
                    int uvOffset = align32(vertexOffset + vertexBytes + verts2Bytes);
                    int polyOffset = align32(uvOffset + uvBytes);
                    int transformOffset = align32(polyOffset + polygonBytes);
                    int surfaceOffset = align32(transformOffset + transformBytes);
                    int uvCount = uvBytes / 16;
                    PmdUvRef *uvRefs = NULL;
                    if ((uvCount > 0) && (uvOffset + uvBytes <= bytesRead))
                    {
                        uvRefs = (PmdUvRef *)malloc(uvCount * sizeof(PmdUvRef));
                        if (uvRefs)
                        {
                            for (int i = 0; i < uvCount; i++)
                            {
                                unsigned char *cursor = meshBytes + uvOffset + (i * 16);
                                uvRefs[i].vertexIndex = (short)readWord(cursor + 8);
                            }
                        }
                    }
                    if ((polygonCount > 0) && (polyOffset + polygonBytes <= bytesRead) && uvRefs &&
                        (surfaceCount > 0) && (surfaceOffset + surfaceBytes <= bytesRead))
                    {
                        polyLines = (PmdPolyLine *)malloc(polygonCount * sizeof(PmdPolyLine));
                        if (polyLines)
                        {
                            BOOL haveTransformedBounds = FALSE;
                            int drawableSurfaceOrdinal = 0;
                            for (int surfaceIndex = 0; surfaceIndex < surfaceCount; surfaceIndex++)
                            {
                                unsigned char *surfaceCursor = meshBytes + surfaceOffset + (surfaceIndex * 64);
                                int transformIndex = (short)readWord(surfaceCursor + 8);
                                int surfacePolyCount = (short)readWord(surfaceCursor + 36);
                                int surfaceUvCount = (short)readWord(surfaceCursor + 38);
                                int surfaceVertexCount = readInt(surfaceCursor + 40);
                                int surfaceUvStart = readInt(surfaceCursor + 44);
                                int surfaceVertexStart = readInt(surfaceCursor + 48);
                                int surfacePolyStart = readInt(surfaceCursor + 52);
                                if ((surfacePolyCount < 1) || (surfaceUvCount < 1) || (surfaceVertexCount < 1))
                                {
                                    continue;
                                }
                                int currentSurfaceOrdinal = drawableSurfaceOrdinal;
                                drawableSurfaceOrdinal++;
                                float translateX = 0.0f;
                                float translateZ = 0.0f;
                                BOOL isPmd182 = (meshBytes[8] == '2');
                                int transformStride = isPmd182 ? 72 : 80;
                                if ((transformIndex >= 0) && (transformOffset + ((transformIndex + 1) * transformStride) <= bytesRead))
                                {
                                    unsigned char *transformCursor = meshBytes + transformOffset + (transformIndex * transformStride);
                                    // 4x4 row-major matrix: translation is at matrix[12]=tx, matrix[14]=tz
                                    translateX = readFloat(transformCursor + 48);
                                    translateZ = readFloat(transformCursor + 56);
                                }
                                for (int i = 0; i < surfacePolyCount; i++)
                                {
                                    int polyIndex = surfacePolyStart + i;
                                    if ((polyIndex < 0) || (polyIndex >= polygonCount))
                                    {
                                        continue;
                                    }
                                    unsigned char *cursor = meshBytes + polyOffset + (polyIndex * 8);
                                    int count = cursor[0];
                                    int material = cursor[1];
                                    int faceStart = readWord(cursor + 6);
                                    if ((count >= 3) && (count <= 4) && (faceStart + count <= faceCount) &&
                                        (polyLineCount < polygonCount))
                                    {
                                        BOOL valid = TRUE;
                                        polyLines[polyLineCount].count = (unsigned char)count;
                                        polyLines[polyLineCount].material = (unsigned char)material;
                                        polyLines[polyLineCount].surfaceOrdinal = currentSurfaceOrdinal;
                                        for (int j = 0; j < count; j++)
                                        {
                                            int uvLocalIndex = (short)readWord(meshBytes + 480 + ((faceStart + j) * 2));
                                            int uvIndex = surfaceUvStart + uvLocalIndex;
                                            if ((uvLocalIndex < 0) || (uvLocalIndex >= surfaceUvCount) ||
                                                (uvIndex < 0) || (uvIndex >= uvCount))
                                            {
                                                valid = FALSE;
                                                break;
                                            }
                                            int vertexLocalIndex = uvRefs[uvIndex].vertexIndex;
                                            int vertexIndex = surfaceVertexStart + vertexLocalIndex;
                                            if ((vertexLocalIndex < 0) || (vertexLocalIndex >= surfaceVertexCount) ||
                                                (vertexIndex < 0) || (vertexIndex >= vertexCount))
                                            {
                                                valid = FALSE;
                                                break;
                                            }
                                            unsigned char *uvCursor = meshBytes + uvOffset + (uvIndex * 16);
                                            polyLines[polyLineCount].x[j] = vertices[vertexIndex].x + translateX;
                                            polyLines[polyLineCount].z[j] = vertices[vertexIndex].z + translateZ;
                                            polyLines[polyLineCount].u[j] = readFloat(uvCursor);
                                            polyLines[polyLineCount].v[j] = -readFloat(uvCursor + 4);
                                            if (!haveTransformedBounds)
                                            {
                                                minX = maxX = polyLines[polyLineCount].x[j];
                                                minZ = maxZ = polyLines[polyLineCount].z[j];
                                                haveTransformedBounds = TRUE;
                                            }
                                            else
                                            {
                                                if (polyLines[polyLineCount].x[j] < minX)
                                                {
                                                    minX = polyLines[polyLineCount].x[j];
                                                }
                                                if (polyLines[polyLineCount].x[j] > maxX)
                                                {
                                                    maxX = polyLines[polyLineCount].x[j];
                                                }
                                                if (polyLines[polyLineCount].z[j] < minZ)
                                                {
                                                    minZ = polyLines[polyLineCount].z[j];
                                                }
                                                if (polyLines[polyLineCount].z[j] > maxZ)
                                                {
                                                    maxZ = polyLines[polyLineCount].z[j];
                                                }
                                            }
                                        }
                                        if (valid)
                                        {
                                            polyLineCount++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (uvRefs)
                    {
                        free(uvRefs);
                    }
                    (void)transformBytes;
                }
                free(meshBytes);
            }
        }
        loaded = TRUE;
    }

    if (!vertices || (vertexCount <= 0) || (GetAsyncKeyState(VK_ESCAPE) & 0x8000))
    {
        return;
    }

    int drawSize = 256;
    int startX = 48;
    int startY = 48;
    float width = maxX - minX;
    float depth = maxZ - minZ;
    if ((width <= 0.001f) || (depth <= 0.001f))
    {
        return;
    }
    float scale = (float)(drawSize - 2) / depth;
    if ((width * scale) > (float)(drawSize - 2))
    {
        scale = (float)(drawSize - 2) / width;
    }
    int offsetX = (drawSize - (int)(width * scale)) / 2;
    int offsetY = (drawSize - (int)(depth * scale)) / 2;

    RECT previewRect = {startX, startY, startX + drawSize, startY + drawSize};
    int maxLines = polyLineCount;
    DDSURFACEDESC2 desc = {0};
    desc.dwSize = sizeof(desc);
    int lockRes = surface->Lock(&previewRect, &desc, DDLOCK_WAIT, NULL);
    if (lockRes == DD_OK)
    {
        unsigned char *destBase = (unsigned char *)desc.lpSurface;
        WORD bgColor = (WORD)rgbToDisplayColor(20, 28, 36);
        WORD lineColor = (WORD)rgbToDisplayColor(150, 230, 255);
        WORD pointColor = (WORD)rgbToDisplayColor(255, 255, 255);
        for (int yFill = 0; yFill < drawSize; yFill++)
        {
            WORD *dest = (WORD *)(destBase + (yFill * desc.lPitch));
            for (int xFill = 0; xFill < drawSize; xFill++)
            {
                dest[xFill] = bgColor;
            }
        }

        if (texturePixels && (textureDecodedWords > 0))
        {
            texturedPixelsDrawn = 0;
            texturedPolyCount = 0;
            for (int textureLine = 0; textureLine < maxLines; textureLine++)
            {
                if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
                {
                    break;
                }
                PmdPolyLine *poly = &polyLines[textureLine];
                if ((poly->surfaceOrdinal != 0) || (poly->material != 0) || (poly->count < 3))
                {
                    continue;
                }
                int x0 = offsetX + (int)((poly->x[0] - minX) * scale);
                int y0 = offsetY + (int)((poly->z[0] - minZ) * scale);
                int x1 = offsetX + (int)((poly->x[1] - minX) * scale);
                int y1 = offsetY + (int)((poly->z[1] - minZ) * scale);
                int x2 = offsetX + (int)((poly->x[2] - minX) * scale);
                int y2 = offsetY + (int)((poly->z[2] - minZ) * scale);
                texturedPixelsDrawn += drawTexturedUvTriangle(destBase, desc.lPitch, drawSize, drawSize, x0, y0, x1, y1,
                                                              x2, y2, poly->u, poly->v, texturePixels, textureWidth,
                                                              textureHeight, textureDecodedWords);
                if (poly->count == 4)
                {
                    float quadU[3] = {poly->u[0], poly->u[2], poly->u[3]};
                    float quadV[3] = {poly->v[0], poly->v[2], poly->v[3]};
                    int x3 = offsetX + (int)((poly->x[3] - minX) * scale);
                    int y3 = offsetY + (int)((poly->z[3] - minZ) * scale);
                    texturedPixelsDrawn += drawTexturedUvTriangle(destBase, desc.lPitch, drawSize, drawSize, x0, y0, x2,
                                                                  y2, x3, y3, quadU, quadV, texturePixels, textureWidth,
                                                                  textureHeight, textureDecodedWords);
                }
                texturedPolyCount++;
            }
        }

        for (int lineIndex = 0; lineIndex < maxLines; lineIndex++)
        {
            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            {
                break;
            }
            PmdPolyLine *poly = &polyLines[lineIndex];
            for (int edgeIndex = 0; edgeIndex < poly->count; edgeIndex++)
            {
                int next = (edgeIndex + 1) % poly->count;
                int x0 = offsetX + (int)((poly->x[edgeIndex] - minX) * scale);
                int y0 = offsetY + (int)((poly->z[edgeIndex] - minZ) * scale);
                int x1 = offsetX + (int)((poly->x[next] - minX) * scale);
                int y1 = offsetY + (int)((poly->z[next] - minZ) * scale);
                drawLockedLine(destBase, desc.lPitch, drawSize, drawSize, x0, y0, x1, y1, lineColor);
            }
        }

        int pointStep = polyLineCount / 256;
        if (pointStep < 1)
        {
            pointStep = 1;
        }
        for (int pointLine = 0; pointLine < polyLineCount; pointLine += pointStep)
        {
            PmdPolyLine *poly = &polyLines[pointLine];
            for (int pointIndex = 0; pointIndex < poly->count; pointIndex++)
            {
                int x = offsetX + (int)((poly->x[pointIndex] - minX) * scale);
                int y = offsetY + (int)((poly->z[pointIndex] - minZ) * scale);
                plotLockedPixel(destBase, desc.lPitch, x, y, drawSize, drawSize, pointColor);
                plotLockedPixel(destBase, desc.lPitch, x + 1, y, drawSize, drawSize, pointColor);
                plotLockedPixel(destBase, desc.lPitch, x, y + 1, drawSize, drawSize, pointColor);
                plotLockedPixel(destBase, desc.lPitch, x + 1, y + 1, drawSize, drawSize, pointColor);
            }
        }
        surface->Unlock(&previewRect);
    }

    if (!logged)
    {
        traceLog("pmd preview path=%s vertices=%d faces=%d polys=%d polyLines=%d drawnLines=%d surfaces=%d boundsX=%.3f..%.3f boundsZ=%.3f..%.3f drawSize=%d scale=%.3f offset=%d,%d lock=0x%08x texPath=%s texDecoded=%d texUnderflows=%d texturedSurface=%d texturedPolys=%d texturedPixels=%d",
                 meshPath,
                 vertexCount,
                 faceCount,
                 polygonCount,
                 polyLineCount,
                 maxLines,
                 surfaceCount,
                 minX,
                 maxX,
                 minZ,
                 maxZ,
                 drawSize,
                 scale,
                 offsetX,
                 offsetY,
                 lockRes,
                 texturePath,
                 textureDecodedWords,
                 textureUnderflows,
                 0,
                 texturedPolyCount,
                 texturedPixelsDrawn);
        logged = TRUE;
    }
}

void drawLevelProbeOverlay(LPDIRECTDRAWSURFACE4 surface)
{
    static BOOL logged = FALSE;
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        return;
    }

    int width = g_DISPLAYRESWIDTH;
    int height = g_DISPLAYRESHEIGHT;
    if ((width <= 0) || (height <= 0))
    {
        return;
    }

    int baseY = height - 96;
    int maxBarHeight = 72;
    int barWidth = width / 18;
    int gap = width / 48;
    int groupWidth = (barWidth * 3) + (gap * 2);
    int startX = (width - groupWidth) / 2;
    DWORD barColors[3] = {
        rgbToDisplayColor(80, 220, 120),
        rgbToDisplayColor(255, 220, 60),
        rgbToDisplayColor(220, 60, 60),
    };

    for (int i = 0; i < 3; i++)
    {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            return;
        }
        int skill = g_LevelCars[i].aiSkill;
        if (skill < 0)
        {
            skill = 0;
        }
        if (skill > 100)
        {
            skill = 100;
        }
        int barHeight = (maxBarHeight * skill) / 100;
        RECT rect = {0};
        rect.left = startX + (i * (barWidth + gap));
        rect.right = rect.left + barWidth;
        rect.top = baseY + (maxBarHeight - barHeight);
        rect.bottom = baseY + maxBarHeight;
        fillSurfaceRect(surface, &rect, barColors[i]);
    }
    drawTextureDecodedSwatch(surface);
    drawPmdVertexPreview(surface);

    if (!logged)
    {
        traceLog("probe bars skills=%d,%d,%d rectStart=%d,%d barWidth=%d maxHeight=%d",
                 g_LevelCars[0].aiSkill,
                 g_LevelCars[1].aiSkill,
                 g_LevelCars[2].aiSkill,
                 startX,
                 baseY,
                 barWidth,
                 maxBarHeight);
        logged = TRUE;
    }
}

int restoreAndClearSurface(LPDIRECTDRAWSURFACE4 surface)
{
    if (!surface)
    {
        return DDERR_INVALIDPARAMS;
    }

    int res = surface->Restore();
    if (res == DD_OK)
    {
        res = clearSurface(surface, 0);
    }
    return res;
}

// STUB: STUNTGP_D3D 0x422a80
int FUN_422a80(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, LPDDSURFACEDESC2 surfaceDescriptor, int unk)
{
    int res = dd->CreateSurface(surfaceDescriptor, surface, NULL);
    if (res != DD_OK)
    {
        FUN_422a00(surface);
    }
    else if (unk == 1)
    {
        exit(1);
    }
    return res;
}

// FUNCTION: STUNTGP_D3D 0x422ac0
void FUN_422ac0(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, int width, int height, int caps)
{
    int res;
    DDSURFACEDESC2 surfaceDescriptor = {0};
    surfaceDescriptor.dwWidth = width;
    surfaceDescriptor.dwHeight = height;
    surfaceDescriptor.dwSize = sizeof(surfaceDescriptor);
    surfaceDescriptor.ddsCaps.dwCaps = DAT_CAPS | caps | DDSCAPS_OFFSCREENPLAIN;
    surfaceDescriptor.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
    if (caps != DDSCAPS_VIDEOMEMORY || (res = FUN_422a80(dd, surface, &surfaceDescriptor, 2), res != DD_OK))
    {
        res = FUN_422a80(dd, surface, &surfaceDescriptor, 2);
    }
    if (res == DD_OK)
    {
        clearSurface(*surface, 0);
    }
}

// TODO: some kind of 640x480 fallback?
// FUNCTION: STUNTGP_D3D 0x422c60
int FUN_422c60(LPDIRECTDRAW4 dd, LPDIRECTDRAWSURFACE4 *surface, void *surface2, int width, int height, int depth)
{
    int res = dd->SetDisplayMode(640, 480, depth, 0, 0);
    if (res != DD_OK)
    {
        return -1;
    }

    // TODO blah blach blah
    DDSURFACEDESC2 surfaceDescriptor = {0};
    surfaceDescriptor.ddsCaps.dwCaps = DAT_CAPS | (DDSCAPS_VIDEOMEMORY | DDSCAPS_PRIMARYSURFACE);
    surfaceDescriptor.dwSize = sizeof(surfaceDescriptor);
    surfaceDescriptor.dwFlags = DDSD_CAPS;

    res = FUN_422a80(dd, surface, &surfaceDescriptor, 2);
    if (res != DD_OK)
    {
        return res;
    }
    clearSurface(*surface, 0);

    FUN_422ac0(dd, (LPDIRECTDRAWSURFACE4 *)surface2, 640, 480, DDSCAPS_VIDEOMEMORY);
    g_DD_DISPLAYRESWIDTH = 640;
    g_DD_DISPLAYRESHEIGHT = 480;
    g_DD_DISPLAYRESDEPTH = depth;
    return DD_OK;
}

// FUNCTION: STUNTGP_D3D 0x422f30
int FUN_422f30(LPDIRECTDRAW4 lpDD4, LPDIRECTDRAWSURFACE4 *surface, LPDIRECTDRAWSURFACE4 *surface2, int width,
               int height, int depth)
{
    // TODO
    if (((g_DD_DISPLAYRESWIDTH != width) || (g_DD_DISPLAYRESHEIGHT != height)) || (g_DD_DISPLAYRESDEPTH != depth))
    {
        g_005728d8_dd = 0;

        void *interesting = {NULL};
        interesting = surface;
        // TODO
        BOOL usedFallback = {FALSE};
        int res = {lpDD4->SetDisplayMode(width, height, depth, 0, 0)};
        if (res != DD_OK)
        {
            // Fallback to 640x480
            if (g_005728d8_dd == 0)
            {
                res = FUN_422c60(lpDD4, surface, surface2, width, height, depth);
                usedFallback = (res == DD_OK);
            }
            if (res != DD_OK)
            {
                // fallback to fallback? the heck
                res = lpDD4->SetDisplayMode(width, height, depth, 0, 0);
                if (res == DD_OK)
                {
                    return res;
                }
            }
        }
        if ((res == DD_OK) && !usedFallback)
        {
            DDSURFACEDESC2 surfaceDescriptor = {0};
            surfaceDescriptor.ddsCaps.dwCaps = DAT_CAPS | (DDSCAPS_VIDEOMEMORY | DDSCAPS_PRIMARYSURFACE);
            surfaceDescriptor.dwSize = sizeof(surfaceDescriptor);
            surfaceDescriptor.dwFlags = DDSD_CAPS;

            res = FUN_422a80(lpDD4, surface, &surfaceDescriptor, 2);
            if (res != DD_OK)
            {
                return res;
            }
            clearSurface(*surface, 0);

            FUN_422ac0(lpDD4, surface2, width, height, DDSCAPS_VIDEOMEMORY);
            g_DD_DISPLAYRESWIDTH = width;
            g_DD_DISPLAYRESHEIGHT = height;
            g_DD_DISPLAYRESDEPTH = depth;
        }
        int sth = {0};
    }
    return 0;
}

// // STUB: STUNTGP_D3D 0x423070
// void FUN_423070()
// {
// }

// STUB: STUNTGP_D3D 0x4230b0
int FUN_4230b0(LPDIRECTDRAWPALETTE *outPalette, void *sth)
{
    PALETTEENTRY pal[256] = {0};
    int res = {0};
    HDC hDC = GetDC(NULL);
    int rasterCaps = GetDeviceCaps(hDC, RASTERCAPS);
    if (rasterCaps & RC_PALETTE)
    {
        GetSystemPaletteEntries(hDC, 0, 256, pal);
    }
    else
    {
        for (int i = 0; i < 256; i++)
        {
            pal[i].peRed = (BYTE)i;
            pal[i].peGreen = (BYTE)i;
            pal[i].peBlue = (BYTE)i;
            pal[i].peFlags = 0;
        }
    }
    ReleaseDC(NULL, hDC);

    if (!g_dd4 || !outPalette)
    {
        return DDERR_INVALIDPARAMS;
    }

    res = g_dd4->CreatePalette(DDPCAPS_8BIT | DDPCAPS_INITIALIZE, pal, outPalette, NULL);
    if ((res == DD_OK) && g_surface)
    {
        res = g_surface->SetPalette(*outPalette);
    }
    return res;
}
