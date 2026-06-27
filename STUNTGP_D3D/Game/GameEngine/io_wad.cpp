#include "io_wad.h"
#include "../../common.h"

struct WadPathMap
{
    const char *root;
    const char *wad;
};

static WadPathMap g_wadPathMap[] = {
    {"sound\\sfx", "sfx.wad"},
    {"graphics24\\overlays", "overlay.wad"},
    {"graphics24\\misc", "misc.wad"},
    {"graphics24\\trackset00", "tset00.wad"},
    {"graphics24\\trackset01", "tset01.wad"},
    {"graphics24\\trackset02", "tset02.wad"},
    {"graphics24\\trackset03", "tset03.wad"},
    {"graphics24\\trackset04", "tset04.wad"},
    {"graphics24\\trackset05", "tset05.wad"},
    {"graphics24\\trackset06", "tset06.wad"},
    {"graphics24\\cars\\misc", "carmisc.wad"},
    {"graphics24\\cars\\car1", "car01.wad"},
    {"graphics24\\cars\\car2", "car02.wad"},
    {"graphics24\\cars\\car3", "car03.wad"},
    {"graphics24\\cars\\car4", "car04.wad"},
    {"graphics24\\cars\\car5", "car05.wad"},
    {"graphics24\\cars\\car6", "car06.wad"},
    {"graphics24\\cars\\car7", "car07.wad"},
    {"graphics24\\cars\\car8", "car08.wad"},
    {"graphics24\\cars\\car9", "car09.wad"},
    {"graphics24\\cars\\car10", "car10.wad"},
    {"graphics24\\cars\\car11", "car11.wad"},
    {"graphics24\\cars\\car12", "car12.wad"},
    {"graphics24\\cars\\car13", "car13.wad"},
    {"graphics24\\cars\\car14", "car14.wad"},
    {"graphics24\\cars\\car15", "car15.wad"},
    {"graphics24\\cars\\car16", "car16.wad"},
    {"graphics24\\cars\\car17", "car17.wad"},
    {"graphics24\\cars\\car18", "car18.wad"},
    {"graphics24\\cars\\car19", "car19.wad"},
    {"graphics24\\cars\\car20", "car20.wad"},
    {"graphics24\\level1", "level1.wad"},
    {"graphics24\\level2", "level2.wad"},
    {"graphics24\\level3", "level3.wad"},
    {"graphics24\\level4", "level4.wad"},
    {"graphics24\\level5", "level5.wad"},
    {"graphics24\\level6", "level6.wad"},
    {"graphics24\\level7", "level7.wad"},
    {"graphics24\\level8", "level8.wad"},
    {"graphics24\\challenge3", "chall3.wad"},
    {"graphics24\\frontend\\dialog", "dialog.wad"},
    {"graphics24\\frontend\\tiles", "tiles.wad"},
    {"graphics24\\frontend\\logos", "logos.wad"},
    {"graphics24\\frontend\\icons", "icons.wad"},
    {"graphics24\\frontend\\pads\\pc", "pads_pc.wad"},
    {"graphics24\\frontend\\pads\\dc", "pads_dc.wad"},
    {"graphics24\\frontend\\pads\\ps", "pads_ps.wad"},
    {"graphics24\\fonts", "fonts.wad"},
    {"graphics24\\boot", "boot.wad"},
    {"graphics24\\loading", "loading.wad"},
    {"setup", "setup.wad"},
    {"replays", "replays.wad"},
    {"config", "config.wad"},
    {"config\\cams", "config.wad"},
    {"config\\levels", "config.wad"},
    {"config\\vehicles", "config.wad"},
    {NULL, NULL},
};

static int stricmp_local(const char *a, const char *b)
{
    while (*a || *b)
    {
        char ca = *a++;
        char cb = *b++;
        if ((ca >= 'A') && (ca <= 'Z'))
        {
            ca += ' ';
        }
        if ((cb >= 'A') && (cb <= 'Z'))
        {
            cb += ' ';
        }
        if (ca != cb)
        {
            return ca - cb;
        }
    }
    return 0;
}

static const char *findWadForRoot(const char *root)
{
    for (WadPathMap *map = g_wadPathMap; map->root; map++)
    {
        if (stricmp_local(root, map->root) == 0)
        {
            return map->wad;
        }
    }
    return NULL;
}

static void splitPathRoot(const char *path, char *root, int rootSize)
{
    int len = strlen(path);
    int slash = -1;
    for (int i = len - 1; i >= 0; i--)
    {
        if ((path[i] == '\\') || (path[i] == '/'))
        {
            slash = i;
            break;
        }
    }

    if (slash < 0)
    {
        root[0] = '\0';
        return;
    }

    int copyLen = slash;
    if (copyLen >= rootSize)
    {
        copyLen = rootSize - 1;
    }
    strncpy(root, path, copyLen);
    root[copyLen] = '\0';
}

static unsigned int readLE32(unsigned char *bytes)
{
    return bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24);
}

struct WadEntryInfo
{
    char wadPath[260];
    unsigned int offset;
    unsigned int size;
};

static BOOL findFileInWad(const char *wadName, const char *path, WadEntryInfo *entry)
{
    char wadPath[260] = {0};
    strcpy(wadPath, g_GameDirectory);
    if ((wadPath[0] != '\0') && (wadPath[strlen(wadPath) - 1] != '\\'))
    {
        strcat(wadPath, "\\");
    }
    strcat(wadPath, "wads\\");
    strcat(wadPath, wadName);

    FILE *file = fopen(wadPath, "rb");
    if (!file)
    {
        return FALSE;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    long scanStart = fileSize > 262144 ? fileSize - 262144 : 0;
    int scanSize = fileSize - scanStart;
    fseek(file, scanStart, SEEK_SET);

    unsigned char *buffer = (unsigned char *)malloc(scanSize);
    if (!buffer)
    {
        fclose(file);
        return FALSE;
    }

    fread(buffer, 1, scanSize, file);
    fclose(file);

    int pathLen = strlen(path);
    for (int i = 8; i < scanSize - pathLen - 1; i++)
    {
        char *name = (char *)(buffer + i);
        if ((buffer[i + pathLen] == '\0') && (stricmp_local(name, path) == 0) && (i >= 8))
        {
            unsigned int offset = readLE32(buffer + i - 8);
            unsigned int size = readLE32(buffer + i - 4);
            if ((offset < (unsigned int)fileSize) && (offset + size <= (unsigned int)fileSize))
            {
                strcpy(entry->wadPath, wadPath);
                entry->offset = offset;
                entry->size = size;
                free(buffer);
                return TRUE;
            }
        }
    }

    free(buffer);
    return FALSE;
}

static int sizeOfFileInWad(const char *wadName, const char *path)
{
    WadEntryInfo entry = {{0}, 0, 0};
    if (findFileInWad(wadName, path, &entry))
    {
        return entry.size;
    }
    return 0;
}

// TODO: should it be here?
// FUNCTION: STUNTGP_D3D 0x44b170
int FUN_44b170(char *in)
{
    // start in from the end of GameDirectory and return position of first non '\\' char
    int len = strlen(g_GameDirectory);
    char tmp = in[len];
    int a = len;
    while (tmp == '\\')
    {
        a = len + 1;
        tmp = in[a];
        len++;
    }
    return len;
}

// TODO: should it be here?
// FUNCTION: STUNTGP_D3D 0x44b140
void FUN_44b140(char *out, char *in)
{
    // get buffer and return filename without doubled '\\\\'
    char tmp = *in;
    while (tmp != '\0')
    {
        if ((tmp == '\\') && (in[1] == '\\'))
        {
            in++;
        }
        tmp = *in;
        in++;
        *out = tmp;
        out++;
        tmp = *in;
    }
    *out = '\0';
    return;
}

// inline int findLast(char *buffer, int len)
// {
//     char tmp = buffer[len];
//     while ((tmp != '\\') && (len > 0))
//     {
//         len--;
//         tmp = buffer[len];
//     }
//     return len;
// }

// inline void skipDoubled(char *buffer, int last)
// {
//     char tmp = buffer[last];
//     int len2 = last;
//     // skip doubled '\\'
//     while (tmp == '\\')
//     {
//         len2++;
//         tmp = buffer[len2];
//     }
//     // return len2;
// }

// TODO: shitty 38%
// FUNCTION: STUNTGP_D3D 0x44b050
void WAD_SplitFileName(char *in, char *a, char *filename)
{
    char buffer[128];
    // char *dwojeczka = a;

    strcpy(buffer, in);
    int len = strlen(buffer) - 1; //-1/-2?

    char tmp = buffer[len];

    // find last '\\'
    while ((tmp != '\\') && (0 < len))
    {
        len--;
        tmp = buffer[len];
    }

    tmp = buffer[len];
    int len2 = len;

    // skip doubled '\\'
    while (tmp == '\\')
    {
        len2++;
        tmp = buffer[len2];
    }

    // tmp = buffer[len2]; // ???? whyy, useless?

    int afterGameDir = FUN_44b170(buffer);
    FUN_44b140(filename, buffer + afterGameDir);

    char *orig = a;
    if (len < 0)
    {
        *a = '\0';
    }
    else
    {
        buffer[len] = '\0';
        FUN_44b140(orig, buffer + afterGameDir);
    }
    orig = a;

    tolower(filename, filename);
    tolower(orig, orig);
    return;
}

// FUNCTION: STUNTGP_D3D 0x44b260
int bload(char *path, char *out, int maxBytes)
{
    FILE *file = fopen(path, "rb");
    if (!file && g_GameDirectory[0] != '\0')
    {
        char fullPath[260] = {0};
        strcpy(fullPath, g_GameDirectory);
        if ((fullPath[strlen(fullPath) - 1] != '\\') && (path[0] != '\\'))
        {
            strcat(fullPath, "\\");
        }
        strcat(fullPath, path);
        file = fopen(fullPath, "rb");
    }
    if (file)
    {
        int bytesRead = fread(out, 1, maxBytes, file);
        fclose(file);
        return bytesRead;
    }

    char wadRoot[128] = {0};
    splitPathRoot(path, wadRoot, sizeof(wadRoot));
    const char *wadName = findWadForRoot(wadRoot);
    if (!wadName)
    {
        return 0;
    }

    WadEntryInfo entry = {{0}, 0, 0};
    if (!findFileInWad(wadName, path, &entry))
    {
        return 0;
    }

    file = fopen(entry.wadPath, "rb");
    if (!file)
    {
        return 0;
    }

    int bytesToRead = entry.size;
    if (bytesToRead > maxBytes)
    {
        bytesToRead = maxBytes;
    }
    fseek(file, entry.offset, SEEK_SET);
    int bytesRead = fread(out, 1, bytesToRead, file);
    fclose(file);
    return bytesRead;
}

// FUNCTION: STUNTGP_D3D 0x44b3b0
int size_of_file(char *path)
{

    char root[64];
    char filename[64];
    WAD_SplitFileName(path, root, filename);
    char wadRoot[128] = {0};
    splitPathRoot(path, wadRoot, sizeof(wadRoot));
    const char *wadName = findWadForRoot(wadRoot);
    if (wadName)
    {
        int wadSize = sizeOfFileInWad(wadName, path);
        if (wadSize != 0)
        {
            return wadSize;
        }
    }
    // strcmpi(root, point);
    //  array of pointers to strings
    //  pairs of pointers and {NULL, NULL} at the end?
    /*
"sound\\sfx"
"sfx.wad"
"graphics24\\overlays"
"overlay.wad"
"graphics24\\misc"
"misc.wad"
"graphics24\\trackset00"
"tset00.wad"
"graphics24\\trackset01"
"tset01.wad"
"graphics24\\trackset02"
"tset02.wad"
"graphics24\\trackset03"
"tset03.wad"
"graphics24\\trackset04"
"tset04.wad"
"graphics24\\trackset05"
"tset05.wad"
"graphics24\\trackset06"
"tset06.wad"
"graphics24\\cars\\misc"
"carmisc.wad"
"graphics24\\cars\\car1"
"car01.wad"
"graphics24\\cars\\car2"
"car02.wad"
"graphics24\\cars\\car3"
"car03.wad"
"graphics24\\cars\\car4"
"car04.wad"
"graphics24\\cars\\car5"
"car05.wad"
"graphics24\\cars\\car6"
"car06.wad"
"graphics24\\cars\\car7"
"car07.wad"
"graphics24\\cars\\car8"
"car08.wad"
"graphics24\\cars\\car9"
"car09.wad"
"graphics24\\cars\\car10"
"car10.wad"
"graphics24\\cars\\car11"
"car11.wad"
"graphics24\\cars\\car12"
"car12.wad"
"graphics24\\cars\\car13"
"car13.wad"
"graphics24\\cars\\car14"
"car14.wad"
"graphics24\\cars\\car15"
"car15.wad"
"graphics24\\cars\\car16"
"car16.wad"
"graphics24\\cars\\car17"
"car17.wad"
"graphics24\\cars\\car18"
"car18.wad"
"graphics24\\cars\\car19"
"car19.wad"
"graphics24\\cars\\car20"
"car20.wad"
"graphics24\\level1"
"level1.wad"
"graphics24\\level2"
"level2.wad"
"graphics24\\level3"
"level3.wad"
"graphics24\\level4"
"level4.wad"
"graphics24\\level5"
"level5.wad"
"graphics24\\level6"
"level6.wad"
"graphics24\\level7"
"level7.wad"
"graphics24\\level8"
"level8.wad"
"graphics24\\challenge3"
"chall3.wad"
"graphics24\\frontend\\dialog"
"dialog.wad"
"graphics24\\frontend\\tiles"
"tiles.wad"
"graphics24\\frontend\\logos"
"logos.wad"
"graphics24\\frontend\\icons"
"icons.wad"
"graphics24\\frontend\\pads\\pc"
"pads_pc.wad"
"graphics24\\frontend\\pads\\dc"
"pads_dc.wad"
"graphics24\\frontend\\pads\\ps"
"pads_ps.wad"
"graphics24\\frontend\\pages\\
"p_carsa.wad"
"graphics24\\frontend\\pages\\
"p_carsb.wad"
"graphics24\\frontend\\pages\\
"p_catal.wad"
"graphics24\\frontend\\pages\\
"p_spons.wad"
"graphics24\\frontend\\pages\\
"p_title.wad"
"graphics24\\frontend\\pages\\
"p_tracka.wad"
"graphics24\\frontend\\pages\\
"p_trackb.wad"
"graphics24\\frontend\\pages\\
"p_lang.wad"
"graphics24\\frontend\\pages\\
"p_single.wad"
"graphics24\\fonts"
"fonts.wad"
"graphics24\\boot"
"boot.wad"
"graphics24\\loading"
"loading.wad"
"setup"
"setup.wad"
"replays"
"replays.wad"
"config"
"config.wad"
"config\\cams"
"config.wad"
"config\\levels"
"config.wad"
"config\\vehicles"
"config.wad"
*/
    // auto uh = PTR_;

    FILE *file = fopen(path, "rb");
    if (!file && g_GameDirectory[0] != '\0')
    {
        char fullPath[260] = {0};
        strcpy(fullPath, g_GameDirectory);
        if ((fullPath[strlen(fullPath) - 1] != '\\') && (path[0] != '\\'))
        {
            strcat(fullPath, "\\");
        }
        strcat(fullPath, path);
        file = fopen(fullPath, "rb");
    }
    if (!file)
    {
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);
    return size;
}

// FUNCTION: STUNTGP_D3D 0x44b470
void tolower(char *out, char *in)
{
    char tmp;

    tmp = *in;
    while (tmp != '\0')
    {
        in++;
        if ((tmp >= 'A') && (tmp <= 'Z'))
        {
            tmp += ' ';
        }
        *out = tmp;
        out++;
        tmp = *in;
    }
    *out = '\0';

    return;
}
