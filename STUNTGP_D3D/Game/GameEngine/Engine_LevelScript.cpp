#include "Engine_LevelScript.h"

static char *trimLeft(char *text)
{
    while ((*text == ' ') || (*text == '\t'))
    {
        text++;
    }
    return text;
}

static void trimRight(char *text)
{
    int len = strlen(text);
    while ((len > 0) && ((text[len - 1] == '\n') || (text[len - 1] == '\r') || (text[len - 1] == ' ') ||
                         (text[len - 1] == '\t')))
    {
        text[len - 1] = '\0';
        len--;
    }
}

static BOOL readConfigValue(const char *path, const char *key, char *out, int outSize)
{
    FILE *file = fopen(path, "rt");
    if (!file)
    {
        return FALSE;
    }

    char line[256] = {0};
    int keyLen = strlen(key);
    while (fgets(line, sizeof(line), file))
    {
        char *cursor = trimLeft(line);
        if (strncmp(cursor, key, keyLen) != 0)
        {
            continue;
        }

        cursor += keyLen;
        cursor = trimLeft(cursor);
        if (*cursor != '=')
        {
            continue;
        }

        cursor++;
        cursor = trimLeft(cursor);
        trimRight(cursor);
        strncpy(out, cursor, outSize - 1);
        out[outSize - 1] = '\0';
        fclose(file);
        return TRUE;
    }

    fclose(file);
    return FALSE;
}

static BOOL readConfigInt(const char *path, const char *key, int *out)
{
    char value[64] = {0};
    if (!readConfigValue(path, key, value, sizeof(value)))
    {
        return FALSE;
    }

    *out = atoi(value);
    return TRUE;
}

static void copyString(char *out, int outSize, const char *in)
{
    strncpy(out, in, outSize - 1);
    out[outSize - 1] = '\0';
}

static BOOL findLevelScriptSection(char *script, const char *sectionName)
{
    char sectionHeader[96] = {0};
    sprintf(sectionHeader, "%s =", sectionName);
    return strstr(script, sectionHeader) != NULL;
}

static char *findLevelScriptSectionStart(char *script, const char *sectionName)
{
    char sectionHeader[96] = {0};
    sprintf(sectionHeader, "%s =", sectionName);
    return strstr(script, sectionHeader);
}

static BOOL readSectionValue(char *sectionStart, const char *key, char *out, int outSize)
{
    char *sectionEnd = strstr(sectionStart, "-END");
    if (!sectionEnd)
    {
        return FALSE;
    }

    int keyLen = strlen(key);
    char *cursor = sectionStart;
    while (cursor < sectionEnd)
    {
        char *lineEnd = strchr(cursor, '\n');
        if (!lineEnd || lineEnd > sectionEnd)
        {
            lineEnd = sectionEnd;
        }

        char lineBuffer[256] = {0};
        int lineLen = lineEnd - cursor;
        if (lineLen >= (int)sizeof(lineBuffer))
        {
            lineLen = sizeof(lineBuffer) - 1;
        }
        strncpy(lineBuffer, cursor, lineLen);
        lineBuffer[lineLen] = '\0';

        char *line = trimLeft(lineBuffer);
        if (strncmp(line, key, keyLen) == 0)
        {
            line += keyLen;
            line = trimLeft(line);
            if (*line == '=')
            {
                line++;
                line = trimLeft(line);
                char *comment = strstr(line, "/*");
                if (comment)
                {
                    *comment = '\0';
                }
                trimRight(line);
                strncpy(out, line, outSize - 1);
                out[outSize - 1] = '\0';
                return TRUE;
            }
        }

        cursor = lineEnd;
        if (*cursor == '\n')
        {
            cursor++;
        }
    }

    return FALSE;
}

static BOOL readTextValue(char *text, const char *key, char *out, int outSize)
{
    int keyLen = strlen(key);
    char *cursor = text;
    while (*cursor)
    {
        char *lineEnd = strchr(cursor, '\n');
        if (!lineEnd)
        {
            lineEnd = cursor + strlen(cursor);
        }

        char lineBuffer[256] = {0};
        int lineLen = lineEnd - cursor;
        if (lineLen >= (int)sizeof(lineBuffer))
        {
            lineLen = sizeof(lineBuffer) - 1;
        }
        strncpy(lineBuffer, cursor, lineLen);
        lineBuffer[lineLen] = '\0';

        char *line = trimLeft(lineBuffer);
        if (strncmp(line, key, keyLen) == 0)
        {
            line += keyLen;
            line = trimLeft(line);
            if (*line == '=')
            {
                line++;
                line = trimLeft(line);
                trimRight(line);
                copyString(out, outSize, line);
                return TRUE;
            }
        }

        cursor = lineEnd;
        if (*cursor == '\n')
        {
            cursor++;
        }
    }

    return FALSE;
}

static char *findNextTopLevelBlock(char *cursor)
{
    char *next = strchr(cursor, '\n');
    while (next)
    {
        next++;
        if (*next == '-')
        {
            return next;
        }
        next = strchr(next, '\n');
    }
    return cursor + strlen(cursor);
}

static BOOL readBlockValue(char *text, const char *blockName, const char *key, char *out, int outSize)
{
    char *block = strstr(text, blockName);
    if (!block)
    {
        return FALSE;
    }

    char *blockEnd = findNextTopLevelBlock(block);
    int keyLen = strlen(key);
    char *cursor = block;
    while (cursor < blockEnd)
    {
        char *lineEnd = strchr(cursor, '\n');
        if (!lineEnd || lineEnd > blockEnd)
        {
            lineEnd = blockEnd;
        }

        char lineBuffer[256] = {0};
        int lineLen = lineEnd - cursor;
        if (lineLen >= (int)sizeof(lineBuffer))
        {
            lineLen = sizeof(lineBuffer) - 1;
        }
        strncpy(lineBuffer, cursor, lineLen);
        lineBuffer[lineLen] = '\0';

        char *line = trimLeft(lineBuffer);
        if (strncmp(line, key, keyLen) == 0)
        {
            line += keyLen;
            line = trimLeft(line);
            if (*line == '=')
            {
                line++;
                line = trimLeft(line);
                trimRight(line);
                copyString(out, outSize, line);
                return TRUE;
            }
        }

        cursor = lineEnd;
        if (*cursor == '\n')
        {
            cursor++;
        }
    }

    return FALSE;
}

static unsigned short readLE16(unsigned char *bytes)
{
    return bytes[0] | (bytes[1] << 8);
}

static unsigned int readLE32(unsigned char *bytes)
{
    return bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24);
}

static void tracePmdHeader(const char *label, char *path)
{
    unsigned char header[128] = {0};
    int bytesRead = bload(path, (char *)header, sizeof(header));
    if (bytesRead < 80)
    {
        traceLog("pmd %s %s headerRead %d", label, path, bytesRead);
        return;
    }

    char magic[10] = {0};
    memcpy(magic, header, 9);
    traceLog("pmd %s %s magic '%s' type %u offA %u offB %u offC %u offD %u offE %u",
             label,
             path,
             magic,
             readLE32(header + 24),
             readLE32(header + 32),
             readLE32(header + 36),
             readLE32(header + 40),
             readLE32(header + 44),
             readLE32(header + 48));
}

static void tracePcHeader(const char *label, char *path)
{
    unsigned char header[16] = {0};
    int bytesRead = bload(path, (char *)header, sizeof(header));
    if (bytesRead < 10)
    {
        traceLog("pc %s %s headerRead %d", label, path, bytesRead);
        return;
    }

    traceLog("pc %s %s magic %02x%02x%02x%02x fmt %u width %u height %u",
             label,
             path,
             header[0],
             header[1],
             header[2],
             header[3],
             readLE16(header + 4),
             readLE16(header + 6),
             readLE16(header + 8));
}

static void traceLevelConfigSummary(char *path)
{
    int size = size_of_file(path);
    if (size <= 0)
    {
        return;
    }

    char *text = (char *)malloc(size + 1);
    if (!text)
    {
        traceLog("levelCfg parse alloc failed");
        return;
    }

    int bytesRead = bload(path, text, size);
    text[bytesRead] = '\0';

    char ambI[32] = {0};
    char ambR[32] = {0};
    char ambG[32] = {0};
    char ambB[32] = {0};
    char fogR[32] = {0};
    char fogG[32] = {0};
    char fogB[32] = {0};
    readBlockValue(text, "-Ambience[]", "I", ambI, sizeof(ambI));
    readBlockValue(text, "-Ambience[]", "R", ambR, sizeof(ambR));
    readBlockValue(text, "-Ambience[]", "G", ambG, sizeof(ambG));
    readBlockValue(text, "-Ambience[]", "B", ambB, sizeof(ambB));
    readBlockValue(text, "-FogColour[]", "R", fogR, sizeof(fogR));
    readBlockValue(text, "-FogColour[]", "G", fogG, sizeof(fogG));
    readBlockValue(text, "-FogColour[]", "B", fogB, sizeof(fogB));
    g_LevelFogR = atoi(fogR);
    g_LevelFogG = atoi(fogG);
    g_LevelFogB = atoi(fogB);
    traceLog("levelCfg summary ambience=%s,%s,%s,%s fog=%s,%s,%s", ambI, ambR, ambG, ambB, fogR, fogG, fogB);

    free(text);
}

static void traceCameraSummary(char *path)
{
    int size = size_of_file(path);
    if (size <= 0)
    {
        return;
    }

    char *text = (char *)malloc(size + 1);
    if (!text)
    {
        traceLog("camera parse alloc failed");
        return;
    }

    int bytesRead = bload(path, text, size);
    text[bytesRead] = '\0';

    char cameraCount[32] = {0};
    char posX[32] = {0};
    char posY[32] = {0};
    char posZ[32] = {0};
    readTextValue(text, "TotalCameraCnt", cameraCount, sizeof(cameraCount));
    char *firstPosition = strstr(text, "-Position[]");
    if (firstPosition)
    {
        readBlockValue(firstPosition, "-Position[]", "x", posX, sizeof(posX));
        readBlockValue(firstPosition, "-Position[]", "y", posY, sizeof(posY));
        readBlockValue(firstPosition, "-Position[]", "z", posZ, sizeof(posZ));
    }
    traceLog("camera summary count=%s firstPos=%s,%s,%s", cameraCount, posX, posY, posZ);

    free(text);
}

static void traceVehicleConfigSummary(char *path)
{
    int size = size_of_file(path);
    if (size <= 0)
    {
        return;
    }

    char *text = (char *)malloc(size + 1);
    if (!text)
    {
        traceLog("vehicleCfg parse alloc failed");
        return;
    }

    int bytesRead = bload(path, text, size);
    text[bytesRead] = '\0';

    char mass[32] = {0};
    char wheelBase[32] = {0};
    char rpmLimit[32] = {0};
    char maxTorque[32] = {0};
    readBlockValue(text, "-DIMENSIONS[]", "Mass", mass, sizeof(mass));
    readBlockValue(text, "-DIMENSIONS[]", "WheelBase", wheelBase, sizeof(wheelBase));
    readBlockValue(text, "-ENGINE[]", "RpmLimit", rpmLimit, sizeof(rpmLimit));
    readBlockValue(text, "-ENGINE[]", "MaxTorque", maxTorque, sizeof(maxTorque));
    traceLog("vehicleCfg summary mass=%s wheelBase=%s rpmLimit=%s maxTorque=%s", mass, wheelBase, rpmLimit, maxTorque);

    free(text);
}

static void traceLevelCarProbe()
{
    for (int i = 0; i < 3; i++)
    {
        LevelCarInfo *car = &g_LevelCars[i];
        char path[128] = {0};

        traceLog("car%d script mesh=%s shadow=%s livery=%d tyre=%d config=%d replay=%d skill=%d mode=%d",
                 i + 1,
                 car->mesh,
                 car->shadow,
                 car->livery,
                 car->tyre,
                 car->config,
                 car->replay,
                 car->aiSkill,
                 car->aiMode);

        sprintf(path, "meshdata\\%s.PMD", car->mesh);
        traceLog("asset car%dMesh %s size %d", i + 1, path, size_of_file(path));
        if (i == 0)
        {
            tracePmdHeader("car1", path);
        }

        sprintf(path, "meshdata\\%s.PMD", car->shadow);
        traceLog("asset car%dShadow %s size %d", i + 1, path, size_of_file(path));

        sprintf(path, "config\\vehicles\\car%d.cfg", car->config);
        traceLog("asset car%dCfg %s size %d", i + 1, path, size_of_file(path));
        if (i == 0)
        {
            traceVehicleConfigSummary(path);
        }

        sprintf(path, "graphics24\\cars\\car%d\\b%dgrid1.pc", car->config, car->config);
        traceLog("asset car%dTex %s size %d", i + 1, path, size_of_file(path));
        if (i == 0)
        {
            tracePcHeader("car1Tex", path);
        }
    }
}

static void traceLevelAssetProbe()
{
    char path[128] = {0};
    char texSetLower[64] = {0};
    tolower(texSetLower, g_LevelTrackTexSet);

    sprintf(path, "meshdata\\%s.PMD", g_LevelTrack);
    traceLog("asset trackMesh %s size %d", path, size_of_file(path));
    tracePmdHeader("track", path);

    sprintf(path, "meshdata\\%s.PMD", g_LevelSky);
    traceLog("asset skyMesh %s size %d", path, size_of_file(path));
    tracePmdHeader("sky", path);

    sprintf(path, "config\\levels\\%s.cfg", g_LevelTrack);
    traceLog("asset levelCfg %s size %d", path, size_of_file(path));
    traceLevelConfigSummary(path);

    sprintf(path, "config\\cams\\%s.cam", g_LevelTrack);
    traceLog("asset camera %s size %d", path, size_of_file(path));
    traceCameraSummary(path);

    sprintf(path, "sound\\Music\\Track%d.wav", g_LevelMusicTrack);
    traceLog("asset music %s size %d", path, size_of_file(path));

    sprintf(path, "graphics24\\%s\\trk_startline.pc", texSetLower);
    traceLog("asset trackTex %s size %d", path, size_of_file(path));
    tracePcHeader("trackTex", path);

    sprintf(path, "replays\\%s.rpl", g_LevelTrack);
    traceLog("asset trackReplay %s size %d", path, size_of_file(path));

    traceLevelCarProbe();
}

static void parseLevelScriptSummary(char *script, const char *sectionName)
{
    char *section = findLevelScriptSectionStart(script, sectionName);
    if (!section)
    {
        traceLog("section %s missing", sectionName);
        return;
    }

    char sky[64] = {0};
    char track[64] = {0};
    char trackTexSet[64] = {0};
    char music[64] = {0};
    char lapCount[64] = {0};
    readSectionValue(section, "L_SKY", sky, sizeof(sky));
    readSectionValue(section, "L_TRACK", track, sizeof(track));
    readSectionValue(section, "TRACKTEXSET", trackTexSet, sizeof(trackTexSet));
    readSectionValue(section, "MUS_TRACK", music, sizeof(music));
    readSectionValue(section, "LAPCOUNT", lapCount, sizeof(lapCount));
    traceLog("section %s sky=%s track=%s tex=%s music=%s laps=%s", sectionName, sky, track, trackTexSet, music, lapCount);

    copyString(g_LevelSky, sizeof(g_LevelSky), sky);
    copyString(g_LevelTrack, sizeof(g_LevelTrack), track);
    copyString(g_LevelTrackTexSet, sizeof(g_LevelTrackTexSet), trackTexSet);
    g_LevelMusicTrack = atoi(music);
    g_LevelLapCount = atoi(lapCount);

    for (int i = 0; i < 3; i++)
    {
        char key[32] = {0};
        char value[64] = {0};

        sprintf(key, "L_CAR%d", i + 1);
        readSectionValue(section, key, g_LevelCars[i].mesh, sizeof(g_LevelCars[i].mesh));

        sprintf(key, "L_CAR%dSHADOW", i + 1);
        readSectionValue(section, key, g_LevelCars[i].shadow, sizeof(g_LevelCars[i].shadow));

        sprintf(key, "L_CAR%d_LIVERY", i + 1);
        if (readSectionValue(section, key, value, sizeof(value)))
        {
            g_LevelCars[i].livery = atoi(value);
        }

        sprintf(key, "L_CAR%d_TYRE", i + 1);
        if (readSectionValue(section, key, value, sizeof(value)))
        {
            g_LevelCars[i].tyre = atoi(value);
        }

        sprintf(key, "L_CAR%d_CONFIG", i + 1);
        if (readSectionValue(section, key, value, sizeof(value)))
        {
            g_LevelCars[i].config = atoi(value);
        }

        sprintf(key, "L_CAR%d_REPLAY", i + 1);
        if (readSectionValue(section, key, value, sizeof(value)))
        {
            g_LevelCars[i].replay = atoi(value);
        }

        sprintf(key, "L_CAR%d_AISKILL", i + 1);
        if (readSectionValue(section, key, value, sizeof(value)))
        {
            g_LevelCars[i].aiSkill = atoi(value);
        }

        sprintf(key, "L_CAR%d_AIMODE", i + 1);
        if (readSectionValue(section, key, value, sizeof(value)))
        {
            g_LevelCars[i].aiMode = atoi(value);
        }
    }
    traceLevelAssetProbe();
}

// STUB: STUNTGP_D3D 0x42d660
void Script_ParseGameConfig()
{
    int size = {0};
    // char *filename;
    char path[128] = {0};
    sprintf(path, "Game.cfg");
    size = size_of_file(path);
    if (size == 0)
    {
        sprintf(path, "D:\\Game\\Game.cfg");
        size = size_of_file(path);
        if (size == 0)
        {
            sprintf(path, "C:\\Game\\Game.cfg");
            size_of_file(path);
        }
    }
    size = size_of_file(path);
    if (size != 0)
    {
        readConfigValue(path, "GAMELOCATION", g_GameDirectory, sizeof(g_GameDirectory));
        readConfigInt(path, "DISPLAYRESWIDTH", &g_DISPLAYRESWIDTH);
        readConfigInt(path, "DISPLAYRESHEIGHT", &g_DISPLAYRESHEIGHT);
        readConfigInt(path, "DISPLAYRESDEPTH", &g_DISPLAYRESDEPTH);
        readConfigValue(path, "LEVELSCRIPT", g_LevelScript, sizeof(g_LevelScript));

        int levelScriptSize = size_of_file("config\\lvscript.cfg");
        traceLog("level script %s, lvscript.cfg size %d", g_LevelScript, levelScriptSize);
        if (levelScriptSize > 0)
        {
            char *levelScript = (char *)malloc(levelScriptSize + 1);
            if (levelScript)
            {
                int bytesRead = bload("config\\lvscript.cfg", levelScript, levelScriptSize);
                levelScript[bytesRead] = '\0';
                traceLog("lvscript loaded %d, section %s present %d", bytesRead, g_LevelScript,
                         findLevelScriptSection(levelScript, g_LevelScript));
                parseLevelScriptSummary(levelScript, g_LevelScript);
                free(levelScript);
            }
            else
            {
                traceLog("lvscript alloc failed");
            }
        }
    }
    // TODO: mem alloc etc
    return;
}
