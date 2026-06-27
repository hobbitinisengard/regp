// StuntGP.cpp : Defines the class behaviors for the application.
//
#include "stdafx.h"

#include "StuntGP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static TCHAR THIS_FILE[] = _T(__FILE__);
#endif

// STRING: STUNTGP 0x004130b0
#define EXE_STUNTGP_D3D _T("StuntGP_D3D.exe")

// STRING: STUNTGP 0x0004130c0
#define EXE_STUNTGP_GLIDE _T("StuntGP_Glide.exe")

// STRING: STUNTGP 0x0004130d4
#define CONFIG_GLIDE _T("GLIDE")

// STRING: STUNTGP 0x004130dc
#define CONFIG_END _T("-END")

// STRING: STUNTGP 0x004130e4
#define FILE_GAME_CFG _T("GAME.CFG")

// STRING: STUNTGP 0x0004130f0
#define FILE_READ_TEXT _T("rt")

// STRING: STUNTGP 0x004130f4
#define EXE_CONFIG _T("Config.exe")

// STRING: STUNTGP 0x00413100
#define FILE_CONFIG_CFG _T("config.cfg")

// STRING: STUNTGP 0x0041310c
#define FILE_READ_BINARY _T("rb")

/////////////////////////////////////////////////////////////////////////////
// CStuntGPApp

BEGIN_MESSAGE_MAP(CStuntGPApp, CWinApp)
//{{AFX_MSG_MAP(CStuntGPApp)
// NOTE - the ClassWizard will add and remove mapping macros here.
//    DO NOT EDIT what you see in these blocks of generated code!
//}}AFX_MSG
ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// The one and only CStuntGPApp object

CStuntGPApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CStuntGPApp initialization

// FUNCTION: STUNTGP 0x004010a0
BOOL CStuntGPApp::InitInstance()
{
    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.

    LPCTSTR exePath = {NULL};
    TCHAR buffer[200] = {0};
    BOOL glideMode = {false};

    FILE *configFile = _tfopen(FILE_CONFIG_CFG, FILE_READ_BINARY);
    if (!configFile)
    {
        exePath = EXE_CONFIG;
        // exeName = EXE_CONFIG;
    }
    else
    {
        fclose(configFile);

        FILE *gameConfigFile = _tfopen(FILE_GAME_CFG, FILE_READ_TEXT);
        if (!gameConfigFile)
        {
            return FALSE;
        }

        // line by line search for -END,
        int found = {0};
        do
        {
            do
            {
                TCHAR *line = _fgetts(buffer, BUFFER_SIZE, gameConfigFile);
                if (!line)
                {
                    // TOOD: find code that doesn't use goto
                    goto end;
                }
                found = _tcsncmp(buffer, CONFIG_END, 4);
            } while (!found);
            TCHAR *line = _fgetts(buffer, BUFFER_SIZE, gameConfigFile);
            if (!line)
            {
                goto end;
            }
            found = _tcsncmp(buffer, CONFIG_GLIDE, 5);
        } while (!found);
        glideMode = 1;
    end:
        fclose(gameConfigFile);
        if (glideMode)
        {
            exePath = EXE_STUNTGP_GLIDE;
        }
        else
        {
            exePath = EXE_STUNTGP_D3D;
        }
    }

    const TCHAR *argv[] = {exePath, NULL};
    _tspawnv(_P_NOWAIT, exePath, argv);
    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE;
}

// FUNCTION: STUNTGP 0x004090bf
CStuntGPApp::CStuntGPApp(LPCTSTR lpszAppName) : CWinApp(lpszAppName)
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance

    //   FUN_40893e((int)this);
    // *(undefined ***)this = &PTR_LAB_0040fc80;
    // _memset(this + 0x1c,0,0x20);
    // *(undefined4 *)(this + 0x1c) = param_1;
    // return this;
}
