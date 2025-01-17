#ifndef _SHELLAPI_H
#define _SHELLAPI_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows Shell API definitions */

#ifndef WINSHELLAPI
#define WINSHELLAPI  DECLSPEC_IMPORT
#endif /* WINSHELLAPI */

#ifndef SHSTDAPI
#define SHSTDAPI  EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define SHSTDAPI_(type)  EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
#endif /* SHSTDAPI */

#ifndef SHDOCAPI
#define SHDOCAPI  EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define SHDOCAPI_(type)  EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
#endif /* SHDOCAPI */

#ifndef LWSTDAPIV_
#define LWSTDAPIV_(type)  EXTERN_C DECLSPEC_IMPORT type STDAPIVCALLTYPE
#endif /* LWSTDAPIV_ */

#if !defined(_WIN64)
#include <pshpack1.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2185)  /* Alignment of field 'x' can be less than the natural alignment */
#pragma warn(disable:2198)  /* Nameless field is not standard */
#endif

#define ABM_NEW  0x00000000
#define ABM_REMOVE  0x00000001
#define ABM_QUERYPOS  0x00000002
#define ABM_SETPOS  0x00000003
#define ABM_GETSTATE  0x00000004
#define ABM_GETTASKBARPOS  0x00000005
#define ABM_ACTIVATE  0x00000006
#define ABM_GETAUTOHIDEBAR  0x00000007
#define ABM_SETAUTOHIDEBAR  0x00000008
#define ABM_WINDOWPOSCHANGED  0x00000009
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define ABM_SETSTATE  0x0000000A
#endif /* (NTDDI_VERSION >= NTDDI_WINXP) */
#if (NTDDI_VERSION >= NTDDI_WIN8)
#define ABM_GETAUTOHIDEBAREX  0x0000000b
#define ABM_SETAUTOHIDEBAREX  0x0000000c
#endif /* NTDDI_VERSION >= NTDDI_WIN8 */

#define ABN_STATECHANGE  0x00000000
#define ABN_POSCHANGED  0x00000001
#define ABN_FULLSCREENAPP  0x00000002
#define ABN_WINDOWARRANGE  0x00000003

#define ABS_AUTOHIDE  0x00000001
#define ABS_ALWAYSONTOP  0x00000002

#define ABE_LEFT  0
#define ABE_TOP  1
#define ABE_RIGHT  2
#define ABE_BOTTOM  3

#define EIRESID(x)  ((-1)*(int)(x))

#define SE_ERR_FNF  2
#define SE_ERR_PNF  3
#define SE_ERR_ACCESSDENIED  5
#define SE_ERR_OOM  8
#define SE_ERR_DLLNOTFOUND  32

#define SE_ERR_SHARE  26
#define SE_ERR_ASSOCINCOMPLETE  27
#define SE_ERR_DDETIMEOUT  28
#define SE_ERR_DDEFAIL  29
#define SE_ERR_DDEBUSY  30
#define SE_ERR_NOASSOC  31

#define SEE_MASK_DEFAULT  0x00000000
#define SEE_MASK_CLASSNAME  0x00000001
#define SEE_MASK_CLASSKEY  0x00000003
#define SEE_MASK_IDLIST  0x00000004
#define SEE_MASK_INVOKEIDLIST  0x0000000C
#if (NTDDI_VERSION < NTDDI_VISTA)
#define SEE_MASK_ICON  0x00000010
#endif /* (NTDDI_VERSION < NTDDI_VISTA) */
#define SEE_MASK_HOTKEY  0x00000020
#define SEE_MASK_NOCLOSEPROCESS  0x00000040
#define SEE_MASK_CONNECTNETDRV  0x00000080
#define SEE_MASK_NOASYNC  0x00000100  /* secret, added by Bill G. */
#define SEE_MASK_FLAG_DDEWAIT  0x00000100
#define SEE_MASK_DOENVSUBST  0x00000200
#define SEE_MASK_FLAG_NO_UI  0x00000400
#define SEE_MASK_UNICODE  0x00004000
#define SEE_MASK_NO_CONSOLE  0x00008000
#define SEE_MASK_ASYNCOK  0x00100000
#if (NTDDI_VERSION >= NTDDI_WIN2K)
#define SEE_MASK_HMONITOR  0x00200000
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */
#if (NTDDI_VERSION >= NTDDI_WINXPSP1)
#define SEE_MASK_NOZONECHECKS  0x00800000
#endif /* (NTDDI_VERSION >= NTDDI_WINXPSP1) */
#if (NTDDI_VERSION >= NTDDI_WIN2K)
#define SEE_MASK_NOQUERYCLASSSTORE  0x01000000
#define SEE_MASK_WAITFORINPUTIDLE  0x02000000
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define SEE_MASK_FLAG_LOG_USAGE  0x04000000
#endif /* (NTDDI_VERSION >= NTDDI_WINXP) */
#if (NTDDI_VERSION >= NTDDI_WIN8)
#define SEE_MASK_FLAG_HINST_IS_SITE  0x08000000
#endif /* NTDDI_VERSION >= NTDDI_WIN8 */

#if (NTDDI_VERSION >= NTDDI_WIN2K)
#define SHERB_NOCONFIRMATION  0x00000001
#define SHERB_NOPROGRESSUI  0x00000002
#define SHERB_NOSOUND  0x00000004
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */

#define NIM_ADD  0x00000000
#define NIM_MODIFY  0x00000001
#define NIM_DELETE  0x00000002
#if (_WIN32_IE >= 0x0500)
#define NIM_SETFOCUS  0x00000003
#define NIM_SETVERSION  0x00000004
#define NOTIFYICON_VERSION  3
#endif /* _WIN32_IE >= 0x0500 */
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define NOTIFYICON_VERSION_4  4
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#define NIF_MESSAGE  0x00000001
#define NIF_ICON  0x00000002
#define NIF_TIP  0x00000004
#if (_WIN32_IE >= 0x0500)
#define NIF_STATE  0x00000008
#define NIF_INFO  0x00000010
#endif /* _WIN32_IE >= 0x0500 */
#if (_WIN32_IE >= 0x0600)
#define NIF_GUID  0x00000020
#endif /* _WIN32_IE >= 0x0600 */
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define NIF_REALTIME  0x00000040
#define NIF_SHOWTIP  0x00000080
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#if (_WIN32_IE >= 0x0500)
#define NIN_SELECT  (WM_USER+0)
#define NINF_KEY  0x1
#define NIN_KEYSELECT  (NIN_SELECT|NINF_KEY)
#endif /* _WIN32_IE >= 0x0500 */

#if (_WIN32_IE >= 0x0501)
#define NIN_BALLOONSHOW  (WM_USER+2)
#define NIN_BALLOONHIDE  (WM_USER+3)
#define NIN_BALLOONTIMEOUT  (WM_USER+4)
#define NIN_BALLOONUSERCLICK  (WM_USER+5)
#endif /* _WIN32_IE >= 0x0501 */
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define NIN_POPUPOPEN  (WM_USER+6)
#define NIN_POPUPCLOSE  (WM_USER+7)
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#if (_WIN32_IE >= 0x0500)
#define NIS_HIDDEN  0x00000001
#define NIS_SHAREDICON  0x00000002

#define NIIF_NONE  0x00000000
#define NIIF_INFO  0x00000001
#define NIIF_WARNING  0x00000002
#define NIIF_ERROR  0x00000003
#if (NTDDI_VERSION >= NTDDI_XPSP2)
#define NIIF_USER  0x00000004
#endif /* (NTDDI_VERSION >= NTDDI_XPSP2) */
#define NIIF_ICON_MASK  0x0000000F
#if (_WIN32_IE >= 0x0501)
#define NIIF_NOSOUND  0x00000010
#endif /* _WIN32_IE >= 0x0501 */
#endif /*NTDDI_VERSION >= NTDDI_XPSP2 */
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define NIIF_LARGE_ICON  0x00000020
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */
#if (NTDDI_VERSION >= NTDDI_WIN7)
#define NIIF_RESPECT_QUIET_TIME  0x00000080
#endif /* NTDDI_VERSION >= NTDDI_WIN7 */

#define SHGFI_ICON  0x000000100
#define SHGFI_DISPLAYNAME  0x000000200
#define SHGFI_TYPENAME  0x000000400
#define SHGFI_ATTRIBUTES  0x000000800
#define SHGFI_ICONLOCATION  0x000001000
#define SHGFI_EXETYPE  0x000002000
#define SHGFI_SYSICONINDEX  0x000004000
#define SHGFI_LINKOVERLAY  0x000008000
#define SHGFI_SELECTED  0x000010000
#if (NTDDI_VERSION >= NTDDI_WIN2K)
#define SHGFI_ATTR_SPECIFIED  0x000020000
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */
#define SHGFI_LARGEICON  0x000000000
#define SHGFI_SMALLICON  0x000000001
#define SHGFI_OPENICON  0x000000002
#define SHGFI_SHELLICONSIZE  0x000000004
#define SHGFI_PIDL  0x000000008
#define SHGFI_USEFILEATTRIBUTES  0x000000010
#if (_WIN32_IE >= 0x0500)
#define SHGFI_ADDOVERLAYS  0x000000020
#define SHGFI_OVERLAYINDEX  0x000000040
#endif

#define SHGNLI_PIDL  0x000000001
#define SHGNLI_PREFIXNAME  0x000000002
#define SHGNLI_NOUNIQUE  0x000000004
#if (_WIN32_IE >= 0x0501)
#define SHGNLI_NOLNK  0x000000008
#endif /* _WIN2_IE >= 0x0501 */
#if (_WIN32_IE >= 0x0600)
#define SHGNLI_NOLOCNAME  0x000000010
#endif /* _WIN32_IE >= 0x0600 */
#if (NTDDI_VERSION >= NTDDI_WIN7)
#define SHGNLI_USEURLEXT  0x000000020
#endif /* NTDDI_VERSION >= NTDDI_WIN7 */

#define SFGAO_LINK  0x00010000L
#define SFGAO_READONLY  0x00040000L
#define SFGAO_FOLDER  0x20000000L

#define CSIDL_DESKTOP  0x0000
#define CSIDL_PROGRAMS  0x0002
#define CSIDL_PERSONAL  0x0005
#define CSIDL_STARTUP  0x0007
#define CSIDL_RECENT  0x0008
#define CSIDL_FONTS  0x0014
#define CSIDL_FAVORITES  0x0006
#define CSIDL_WINDOWS  0x0024
#define CSIDL_PROGRAM_FILES  0x0026

#if (NTDDI_VERSION >= NTDDI_WIN2K)
#define PRINTACTION_OPEN  0
#define PRINTACTION_PROPERTIES  1
#define PRINTACTION_NETINSTALL  2
#define PRINTACTION_NETINSTALLLINK  3
#define PRINTACTION_TESTPAGE  4
#define PRINTACTION_OPENNETPRN  5
#ifdef WINNT
#define PRINTACTION_DOCUMENTDEFAULTS  6
#define PRINTACTION_SERVERPROPERTIES  7
#endif /* WINNT */
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */

#define FO_MOVE  0x0001
#define FO_COPY  0x0002
#define FO_DELETE  0x0003
#define FO_RENAME  0x0004

#define PO_DELETE  0x0013
#define PO_RENAME  0x0014
#define PO_PORTCHANGE  0x0020
#define PO_REN_PORT  0x0034

#define FOF_MULTIDESTFILES  0x0001
#define FOF_CONFIRMMOUSE  0x0002
#define FOF_SILENT  0x0004
#define FOF_RENAMEONCOLLISION  0x0008
#define FOF_NOCONFIRMATION  0x0010
#define FOF_WANTMAPPINGHANDLE  0x0020
#define FOF_ALLOWUNDO  0x0040
#define FOF_FILESONLY  0x0080
#define FOF_SIMPLEPROGRESS  0x0100
#define FOF_NOCONFIRMMKDIR  0x0200
#define FOF_NOERRORUI  0x0400
#if (_WIN32_IE >= 0x0500)
#define FOF_NOCOPYSECURITYATTRIBS  0x0800
#define FOF_NORECURSION  0x1000
#define FOF_NO_CONNECTED_ELEMENTS  0x2000
#define FOF_WANTNUKEWARNING  0x4000
#endif /* _WIN32_IE >= 0x500 */
#if (_WIN32_WINNT >= 0x0501)
#define FOF_NORECURSEREPARSE  0x8000
#endif /* _WIN32_WINNT >= 0x501 */
#define FOF_NO_UI  (FOF_SILENT|FOF_NOCONFIRMATION|FOF_NOERRORUI|FOF_NOCONFIRMMKDIR)

typedef WORD FILEOP_FLAGS;
typedef WORD PRINTEROP_FLAGS;

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_WINDOWS >= 0x0500)
#define OFFLINE_STATUS_LOCAL  0x0001
#define OFFLINE_STATUS_REMOTE  0x0002
#define OFFLINE_STATUS_INCOMPLETE  0x0004
#endif

#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME   u
#define DUMMYUNIONNAME2  u2
#define DUMMYUNIONNAME3  u3
#define DUMMYUNIONNAME4  u4
#define DUMMYUNIONNAME5  u5
#else
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#endif
#endif /* DUMMYUNIONNAME */

DECLARE_HANDLE(HDROP);

typedef struct _DRAGINFOA {
    UINT uSize;
    POINT pt;
    BOOL fNC;
    LPSTR lpFileList;
    DWORD grfKeyState;
} DRAGINFOA, *LPDRAGINFOA;

typedef struct _DRAGINFOW {
    UINT uSize;
    POINT pt;
    BOOL fNC;
    LPWSTR lpFileList;
    DWORD grfKeyState;
} DRAGINFOW, *LPDRAGINFOW;

typedef struct _AppBarData {
    DWORD cbSize;
    HWND hWnd;
    UINT uCallbackMessage;
    UINT uEdge;
    RECT rc;
    LPARAM lParam;
} APPBARDATA, *PAPPBARDATA;

typedef struct _SHFILEOPSTRUCTA {
    HWND hwnd;
    UINT wFunc;
    LPCSTR pFrom;
    LPCSTR pTo;
    FILEOP_FLAGS fFlags;
    BOOL fAnyOperationsAborted;
    LPVOID hNameMappings;
    LPCSTR lpszProgressTitle;
} SHFILEOPSTRUCTA, *LPSHFILEOPSTRUCTA;

typedef struct _SHFILEOPSTRUCTW {
    HWND hwnd;
    UINT wFunc;
    LPCWSTR pFrom;
    LPCWSTR pTo;
    FILEOP_FLAGS fFlags;
    BOOL fAnyOperationsAborted;
    LPVOID hNameMappings;
    LPCWSTR lpszProgressTitle;
} SHFILEOPSTRUCTW, *LPSHFILEOPSTRUCTW;

typedef struct _SHNAMEMAPPINGA {
    LPSTR pszOldPath;
    LPSTR pszNewPath;
    int cchOldPath;
    int cchNewPath;
} SHNAMEMAPPINGA, *LPSHNAMEMAPPINGA;

typedef struct _SHNAMEMAPPINGW {
    LPWSTR pszOldPath;
    LPWSTR pszNewPath;
    int cchOldPath;
    int cchNewPath;
} SHNAMEMAPPINGW, *LPSHNAMEMAPPINGW;

typedef struct _SHELLEXECUTEINFOA {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpFile;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPVOID lpIDList;
    LPCSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    union {
        HANDLE hIcon;
#if (NTDDI_VERSION >= NTDDI_WIN2K)
        HANDLE hMonitor;
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */
    } DUMMYUNIONNAME;
    HANDLE hProcess;
} SHELLEXECUTEINFOA, *LPSHELLEXECUTEINFOA;

typedef struct _SHELLEXECUTEINFOW {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCWSTR lpVerb;
    LPCWSTR lpFile;
    LPCWSTR lpParameters;
    LPCWSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPVOID lpIDList;
    LPCWSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    union {
        HANDLE hIcon;
#if (NTDDI_VERSION >= NTDDI_WIN2K)
        HANDLE hMonitor;
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */
    } DUMMYUNIONNAME;
    HANDLE hProcess;
} SHELLEXECUTEINFOW, *LPSHELLEXECUTEINFOW;

#if (NTDDI_VERSION >= NTDDI_WIN2K)
typedef struct _SHCREATEPROCESSINFOW {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCWSTR pszFile;
    LPCWSTR pszParameters;
    LPCWSTR pszCurrentDirectory;
    HANDLE hUserToken;
    LPSECURITY_ATTRIBUTES lpProcessAttributes;
    LPSECURITY_ATTRIBUTES lpThreadAttributes;
    BOOL bInheritHandles;
    DWORD dwCreationFlags;
    LPSTARTUPINFOW lpStartupInfo;
    LPPROCESS_INFORMATION lpProcessInformation;
} SHCREATEPROCESSINFOW, *PSHCREATEPROCESSINFOW;
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */

#if (NTDDI_VERSION >= NTDDI_VISTA)
typedef enum ASSOCCLASS {
    ASSOCCLASS_SHELL_KEY = 0,
    ASSOCCLASS_PROGID_KEY,
    ASSOCCLASS_PROGID_STR,
    ASSOCCLASS_CLSID_KEY,
    ASSOCCLASS_CLSID_STR,
    ASSOCCLASS_APP_KEY,
    ASSOCCLASS_APP_STR,
    ASSOCCLASS_SYSTEM_STR,
    ASSOCCLASS_FOLDER,
    ASSOCCLASS_STAR,
#if (NTDDI_VERSION >= NTDDI_WIN8)
    ASSOCCLASS_FIXED_PROGID_STR,
    ASSOCCLASS_PROTOCOL_STR,
#endif /* NTDDI_VERSION >= NTDDI_WIN8 */
} ASSOCCLASS;

typedef struct ASSOCIATIONELEMENT_ {
    ASSOCCLASS ac;
    HKEY hkClass;
    PCWSTR pszClass;
} ASSOCIATIONELEMENT;

SHSTDAPI SHEvaluateSystemCommandTemplate(PCWSTR,PWSTR*,PWSTR*,PWSTR*);
SHSTDAPI AssocCreateForClasses(const ASSOCIATIONELEMENT*,ULONG,REFIID,void**);
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#if (NTDDI_VERSION >= NTDDI_WIN2K)
typedef struct _SHQUERYRBINFO {
    DWORD cbSize;
    __int64 i64Size;
    __int64 i64NumItems;
} SHQUERYRBINFO, *LPSHQUERYRBINFO;
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */

#if (NTDDI_VERSION >= NTDDI_VISTA)
typedef enum {
    QUNS_NOT_PRESENT = 1,
    QUNS_BUSY = 2,
    QUNS_RUNNING_D3D_FULL_SCREEN = 3,
    QUNS_PRESENTATION_MODE = 4,
    QUNS_ACCEPTS_NOTIFICATIONS = 5,
#if (NTDDI_VERSION >= NTDDI_WIN7)
    QUNS_QUIET_TIME = 6,
#endif /* NTDDI_VERSION >= NTDDI_WIN7 */
#if (NTDDI_VERSION >= NTDDI_WIN8)
    QUNS_APP = 7,
#endif /* NTDDI_VERSION >= NTDDI_WIN8 */
} QUERY_USER_NOTIFICATION_STATE;

SHSTDAPI SHQueryUserNotificationState(QUERY_USER_NOTIFICATION_STATE*);
#if (NTDDI_VERSION >= NTDDI_WIN7)
SHSTDAPI SHGetPropertyStoreForWindow(HWND,REFIID,void**);
#endif /* NTDDI_VERSION >= NTDDI_WIN7 */
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

typedef struct _NOTIFYICONDATAA {
    DWORD cbSize;
    HWND hWnd;
    UINT uID;
    UINT uFlags;
    UINT uCallbackMessage;
    HICON hIcon;
#if (NTDDI_VERSION < NTDDI_WIN2K)
    CHAR szTip[64];
#else
    CHAR szTip[128];
    DWORD dwState;
    DWORD dwStateMask;
    CHAR szInfo[256];
    union {
        UINT uTimeout;
        UINT uVersion;
    } DUMMYUNIONNAME;
    CHAR szInfoTitle[64];
    DWORD dwInfoFlags;
#endif /* NTDDI_VERSION >= NTDDI_WIN2K */
#if (NTDDI_VERSION >= NTDDI_WINXP)
    GUID guidItem;
#endif /* NTDDI_VERSION >= NTDDI_WINXP */
#if (NTDDI_VERSION >= NTDDI_VISTA)
    HICON hBalloonIcon;
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
} NOTIFYICONDATAA, *PNOTIFYICONDATAA;

typedef struct _NOTIFYICONDATAW {
    DWORD cbSize;
    HWND hWnd;
    UINT uID;
    UINT uFlags;
    UINT uCallbackMessage;
    HICON hIcon;
#if (NTDDI_VERSION < NTDDI_WIN2K)
    WCHAR szTip[64];
#else
    WCHAR szTip[128];
    DWORD dwState;
    DWORD dwStateMask;
    WCHAR szInfo[256];
    union {
        UINT uTimeout;
        UINT uVersion;
    } DUMMYUNIONNAME;
    WCHAR szInfoTitle[64];
    DWORD dwInfoFlags;
#endif/* NTDDI_VERSION >= NTDDI_WIN2K */
#if (NTDDI_VERSION >= NTDDI_WINXP)
    GUID guidItem;
#endif /* NTDDI_VERSION >= NTDDI_WINXP */
#if (NTDDI_VERSION >= NTDDI_VISTA)
    HICON hBalloonIcon;
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
} NOTIFYICONDATAW, *PNOTIFYICONDATAW;

#define NOTIFYICONDATAA_V1_SIZE  FIELD_OFFSET(NOTIFYICONDATAA,szTip[64])
#define NOTIFYICONDATAW_V1_SIZE  FIELD_OFFSET(NOTIFYICONDATAW,szTip[64])

#define NOTIFYICONDATAA_V2_SIZE  FIELD_OFFSET(NOTIFYICONDATAA,guidItem)
#define NOTIFYICONDATAW_V2_SIZE  FIELD_OFFSET(NOTIFYICONDATAW,guidItem)

#define NOTIFYICONDATAA_V3_SIZE  FIELD_OFFSET(NOTIFYICONDATAA,hBalloonIcon)
#define NOTIFYICONDATAW_V3_SIZE  FIELD_OFFSET(NOTIFYICONDATAW,hBalloonIcon)

#ifndef SHFILEINFO_DEFINED
#define SHFILEINFO_DEFINED

typedef struct _SHFILEINFOA {
    HICON hIcon;
    int iIcon;
    DWORD dwAttributes;
    CHAR szDisplayName[MAX_PATH];
    CHAR szTypeName[80];
} SHFILEINFOA;

typedef struct _SHFILEINFOW {
    HICON hIcon;
    int iIcon;
    DWORD dwAttributes;
    WCHAR szDisplayName[MAX_PATH];
    WCHAR szTypeName[80];
} SHFILEINFOW;

#ifdef UNICODE
typedef SHFILEINFOW SHFILEINFO;
#else
typedef SHFILEINFOA SHFILEINFO;
#endif

#endif /* SHFILEINFO_DEFINED */

#if (NTDDI_VERSION >= NTDDI_WIN2K)

#define SHGNLI_PIDL  0x000000001
#define SHGNLI_PREFIXNAME  0x000000002
#define SHGNLI_NOUNIQUE  0x000000004
#if (_WIN32_IE >= 0x0501)
#define SHGNLI_NOLNK  0x000000008
#endif /* _WIN32_IE >= 0x0501 */
#if (_WIN32_IE >= 0x0600)
#define SHGNLI_NOLOCNAME  0x000000010
#endif /* _WIN32_IE >= 0x0600 */

SHSTDAPI_(BOOL) SHGetDiskFreeSpaceExA(LPCSTR,ULARGE_INTEGER*,ULARGE_INTEGER*,ULARGE_INTEGER*);
SHSTDAPI_(BOOL) SHGetDiskFreeSpaceExW(LPCWSTR,ULARGE_INTEGER*,ULARGE_INTEGER*,ULARGE_INTEGER*);
SHSTDAPI_(BOOL) SHGetNewLinkInfoA(LPCSTR,LPCSTR,LPSTR,BOOL*,UINT);
SHSTDAPI_(BOOL) SHGetNewLinkInfoW(LPCWSTR,LPCWSTR,LPWSTR,BOOL*,UINT);

#ifdef UNICODE
#define SHGetDiskFreeSpaceEx  SHGetDiskFreeSpaceExW
#define SHGetNewLinkInfo  SHGetNewLinkInfoW
#else
#define SHGetDiskFreeSpaceEx  SHGetDiskFreeSpaceExA
#define SHGetNewLinkInfo  SHGetNewLinkInfoA
#endif /* !UNICODE */

#define SHGetDiskFreeSpace  SHGetDiskFreeSpaceEx

#endif /* NTDDI_VERSION >= NTDDI_WIN2K */

#if (NTDDI_VERSION >= NTDDI_VISTA)
typedef struct _SHSTOCKICONINFO {
    DWORD cbSize;
    HICON hIcon;
    int iSysImageIndex;
    int iIcon;
    WCHAR szPath[MAX_PATH];
} SHSTOCKICONINFO;

#define SHGSI_ICONLOCATION  0
#define SHGSI_ICON  SHGFI_ICON
#define SHGSI_SYSICONINDEX  SHGFI_SYSICONINDEX
#define SHGSI_LINKOVERLAY  SHGFI_LINKOVERLAY
#define SHGSI_SELECTED  SHGFI_SELECTED
#define SHGSI_LARGEICON  SHGFI_LARGEICON
#define SHGSI_SMALLICON  SHGFI_SMALLICON
#define SHGSI_SHELLICONSIZE  SHGFI_SHELLICONSIZE

typedef enum SHSTOCKICONID {
    SIID_DOCNOASSOC = 0,
    SIID_DOCASSOC = 1,
    SIID_APPLICATION = 2,
    SIID_FOLDER = 3,
    SIID_FOLDEROPEN = 4,
    SIID_DRIVE525 = 5,
    SIID_DRIVE35 = 6,
    SIID_DRIVEREMOVE = 7,
    SIID_DRIVEFIXED = 8,
    SIID_DRIVENET = 9,
    SIID_DRIVENETDISABLED = 10,
    SIID_DRIVECD = 11,
    SIID_DRIVERAM = 12,
    SIID_WORLD = 13,
    SIID_SERVER = 15,
    SIID_PRINTER = 16,
    SIID_MYNETWORK = 17,
    SIID_FIND = 22,
    SIID_HELP = 23,
    SIID_SHARE = 28,
    SIID_LINK = 29,
    SIID_SLOWFILE = 30,
    SIID_RECYCLER = 31,
    SIID_RECYCLERFULL = 32,
    SIID_MEDIACDAUDIO = 40,
    SIID_LOCK = 47,
    SIID_AUTOLIST = 49,
    SIID_PRINTERNET = 50,
    SIID_SERVERSHARE = 51,
    SIID_PRINTERFAX = 52,
    SIID_PRINTERFAXNET = 53,
    SIID_PRINTERFILE = 54,
    SIID_STACK = 55,
    SIID_MEDIASVCD = 56,
    SIID_STUFFEDFOLDER = 57,
    SIID_DRIVEUNKNOWN = 58,
    SIID_DRIVEDVD = 59,
    SIID_MEDIADVD = 60,
    SIID_MEDIADVDRAM = 61,
    SIID_MEDIADVDRW = 62,
    SIID_MEDIADVDR = 63,
    SIID_MEDIADVDROM = 64,
    SIID_MEDIACDAUDIOPLUS = 65,
    SIID_MEDIACDRW = 66,
    SIID_MEDIACDR = 67,
    SIID_MEDIACDBURN = 68,
    SIID_MEDIABLANKCD = 69,
    SIID_MEDIACDROM = 70,
    SIID_AUDIOFILES = 71,
    SIID_IMAGEFILES = 72,
    SIID_VIDEOFILES = 73,
    SIID_MIXEDFILES = 74,
    SIID_FOLDERBACK = 75,
    SIID_FOLDERFRONT = 76,
    SIID_SHIELD = 77,
    SIID_WARNING = 78,
    SIID_INFO = 79,
    SIID_ERROR = 80,
    SIID_KEY = 81,
    SIID_SOFTWARE = 82,
    SIID_RENAME = 83,
    SIID_DELETE = 84,
    SIID_MEDIAAUDIODVD = 85,
    SIID_MEDIAMOVIEDVD = 86,
    SIID_MEDIAENHANCEDCD = 87,
    SIID_MEDIAENHANCEDDVD = 88,
    SIID_MEDIAHDDVD = 89,
    SIID_MEDIABLURAY = 90,
    SIID_MEDIAVCD = 91,
    SIID_MEDIADVDPLUSR = 92,
    SIID_MEDIADVDPLUSRW = 93,
    SIID_DESKTOPPC = 94,
    SIID_MOBILEPC = 95,
    SIID_USERS = 96,
    SIID_MEDIASMARTMEDIA = 97,
    SIID_MEDIACOMPACTFLASH = 98,
    SIID_DEVICECELLPHONE = 99,
    SIID_DEVICECAMERA = 100,
    SIID_DEVICEVIDEOCAMERA = 101,
    SIID_DEVICEAUDIOPLAYER = 102,
    SIID_NETWORKCONNECT = 103,
    SIID_INTERNET = 104,
    SIID_ZIPFILE = 105,
    SIID_SETTINGS = 106,
    SIID_MAX_ICONS = 107,
} SHSTOCKICONID;

#define SIID_INVALID  ((SHSTOCKICONID)-1)

SHSTDAPI SHGetStockIconInfo(SHSTOCKICONID,UINT,SHSTOCKICONINFO*);

#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#if (NTDDI_VERSION >= NTDDI_VISTA)
#define PRINT_PROP_FORCE_NAME  0x01

typedef struct _OPEN_PRINTER_PROPS_INFOA {
    DWORD dwSize;
    LPSTR pszSheetName;
    UINT uSheetIndex;
    DWORD dwFlags;
    BOOL bModal;
} OPEN_PRINTER_PROPS_INFOA, *POPEN_PRINTER_PROPS_INFOA;

typedef struct _OPEN_PRINTER_PROPS_INFOW {
    DWORD dwSize;
    LPWSTR pszSheetName;
    UINT uSheetIndex;
    DWORD dwFlags;
    BOOL bModal;
} OPEN_PRINTER_PROPS_INFOW, *POPEN_PRINTER_PROPS_INFOW;

#ifdef UNICODE
typedef OPEN_PRINTER_PROPS_INFOW OPEN_PRINTER_PROPS_INFO;
typedef POPEN_PRINTER_PROPS_INFOW POPEN_PRINTER_PROPS_INFO;
#else
typedef OPEN_PRINTER_PROPS_INFOA OPEN_PRINTER_PROPS_INFO;
typedef POPEN_PRINTER_PROPS_INFOA POPEN_PRINTER_PROPS_INFO;
#endif /* !UNICODE */

#endif /* NTDDI_VERSION >= NTDDI_VISTA */

LWSTDAPIV_(int) ShellMessageBoxA(HINSTANCE,HWND,LPCSTR,LPCSTR,UINT, ...);
LWSTDAPIV_(int) ShellMessageBoxW(HINSTANCE,HWND,LPCWSTR,LPCWSTR,UINT, ...);

#if (NTDDI_VERSION >= NTDDI_WIN2K)
SHSTDAPI_(BOOL) IsLFNDriveA(LPCSTR);
SHSTDAPI_(BOOL) IsLFNDriveW(LPCWSTR);
#ifdef UNICODE
#define IsLFNDrive  IsLFNDriveW
#else
#define IsLFNDrive  IsLFNDriveA
#endif /* !UNICODE */
#endif /* NTDDI_VERSION >= NTDDI_WIN2K */

#if _WIN32_IE >= 0x0600
STDAPI SHEnumerateUnreadMailAccountsA(HKEY,DWORD,LPSTR,int);
STDAPI SHEnumerateUnreadMailAccountsW(HKEY,DWORD,LPWSTR,int);
STDAPI SHGetUnreadMailCountA(HKEY,LPCSTR,DWORD*,FILETIME*,LPSTR,int);
STDAPI SHGetUnreadMailCountW(HKEY,LPCWSTR,DWORD*,FILETIME*,LPWSTR,int);
STDAPI SHSetUnreadMailCountA(LPCSTR,DWORD,LPCSTR);
STDAPI SHSetUnreadMailCountW(LPCWSTR,DWORD,LPCWSTR);
#ifdef UNICODE
#define SHEnumerateUnreadMailAccounts  SHEnumerateUnreadMailAccountsW
#define SHGetUnreadMailCount  SHGetUnreadMailCountW
#define SHSetUnreadMailCount  SHSetUnreadMailCountW
#else
#define SHEnumerateUnreadMailAccounts  SHEnumerateUnreadMailAccountsA
#define SHGetUnreadMailCount  SHGetUnreadMailCountA
#define SHSetUnreadMailCount  SHSetUnreadMailCountA
#endif /* UNICODE */
#endif /* _WIN32_IE >= 0x0600 */

#if (_WIN32_IE >= 0x0601)
STDAPI_(BOOL) SHTestTokenMembership(HANDLE,ULONG);
#endif /* _WIN32_IE >= 0x0601 */

#if _WIN32_IE >= 0x0600

#if (NTDDI_VERSION >= NTDDI_WINXP)
SHSTDAPI SHGetImageList(int,REFIID,void **);
#endif /* NTDDI_VERSION >= NTDDI_WINXP */

#if (NTDDI_VERSION >= NTDDI_WINXP)
#define SHIL_LARGE  0
#define SHIL_SMALL  1
#define SHIL_EXTRALARGE  2
#define SHIL_SYSSMALL  3
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define SHIL_JUMBO  4
#define SHIL_LAST  SHIL_JUMBO
#else
#define SHIL_LAST  SHIL_SYSSMALL
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
#endif /* NTDDI_VERSION >= NTDDI_WINXP */

typedef HRESULT (STDMETHODCALLTYPE *PFNCANSHAREFOLDERW)(LPCWSTR);
typedef HRESULT (STDMETHODCALLTYPE *PFNSHOWSHAREFOLDERUIW)(HWND,LPCWSTR);

#endif /* _WIN32_IE >= 0x0600 */

SHSTDAPI_(UINT) DragQueryFileA(HDROP,UINT,LPSTR,UINT);
SHSTDAPI_(UINT) DragQueryFileW(HDROP,UINT,LPWSTR,UINT);
SHSTDAPI_(BOOL) DragQueryPoint(HDROP,LPPOINT);
SHSTDAPI_(void) DragFinish(HDROP);
SHSTDAPI_(void) DragAcceptFiles(HWND,BOOL);
SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR,LPCSTR,LPSTR);
SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR,LPCWSTR,LPWSTR);
SHSTDAPI_(LPWSTR *) CommandLineToArgvW(LPCWSTR,int*);
SHSTDAPI_(INT) ShellAboutA(HWND,LPCSTR,LPCSTR,HICON);
SHSTDAPI_(INT) ShellAboutW(HWND,LPCWSTR,LPCWSTR,HICON);
SHSTDAPI_(HICON) DuplicateIcon(HINSTANCE,HICON);
SHSTDAPI_(HICON) ExtractAssociatedIconA(HINSTANCE,LPSTR,LPWORD);
SHSTDAPI_(HICON) ExtractAssociatedIconW(HINSTANCE,LPWSTR,LPWORD);
SHSTDAPI_(HICON) ExtractAssociatedIconExA(HINSTANCE,LPSTR,LPWORD,LPWORD);
SHSTDAPI_(HICON) ExtractAssociatedIconExW(HINSTANCE,LPWSTR,LPWORD,LPWORD);
SHSTDAPI_(HICON) ExtractIconA(HINSTANCE,LPCSTR,UINT);
SHSTDAPI_(HICON) ExtractIconW(HINSTANCE,LPCWSTR,UINT);
SHSTDAPI_(UINT_PTR) SHAppBarMessage(DWORD,PAPPBARDATA);
SHSTDAPI_(DWORD) DoEnvironmentSubstA(LPSTR,UINT);
SHSTDAPI_(DWORD) DoEnvironmentSubstW(LPWSTR,UINT);
SHSTDAPI_(UINT) ExtractIconExA(LPCSTR,int,HICON*,HICON*,UINT);
SHSTDAPI_(UINT) ExtractIconExW(LPCWSTR,int,HICON*,HICON*,UINT);
SHSTDAPI_(int) SHFileOperationA(LPSHFILEOPSTRUCTA);
SHSTDAPI_(int) SHFileOperationW(LPSHFILEOPSTRUCTW);
SHSTDAPI_(void) SHFreeNameMappings(HANDLE);
SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND,LPCSTR,LPCSTR,LPCSTR,LPCSTR,INT);
SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND,LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR,INT);
SHSTDAPI_(BOOL) ShellExecuteExA(LPSHELLEXECUTEINFOA);
SHSTDAPI_(BOOL) ShellExecuteExW(LPSHELLEXECUTEINFOW);
SHSTDAPI_(void) WinExecErrorA(HWND,int,LPCSTR,LPCSTR);
SHSTDAPI_(void) WinExecErrorW(HWND,int,LPCWSTR,LPCWSTR);
#if (NTDDI_VERSION >= NTDDI_WIN2K)
SHSTDAPI_(BOOL) SHCreateProcessAsUserW(PSHCREATEPROCESSINFOW);
SHSTDAPI SHQueryRecycleBinA(LPCSTR,LPSHQUERYRBINFO);
SHSTDAPI SHQueryRecycleBinW(LPCWSTR,LPSHQUERYRBINFO);
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */
SHSTDAPI SHEmptyRecycleBinA(HWND,LPCSTR,DWORD);
SHSTDAPI SHEmptyRecycleBinW(HWND,LPCWSTR,DWORD);
SHSTDAPI_(BOOL) Shell_NotifyIconA(DWORD,PNOTIFYICONDATAA);
SHSTDAPI_(BOOL) Shell_NotifyIconW(DWORD,PNOTIFYICONDATAW);
SHSTDAPI_(DWORD_PTR) SHGetFileInfoA(LPCSTR,DWORD,SHFILEINFOA*,UINT,UINT);
SHSTDAPI_(DWORD_PTR) SHGetFileInfoW(LPCWSTR,DWORD,SHFILEINFOW*,UINT,UINT);
SHSTDAPI_(BOOL) SHGetDiskFreeSpaceExA(LPCSTR,ULARGE_INTEGER*,ULARGE_INTEGER*,ULARGE_INTEGER*);
SHSTDAPI_(BOOL) SHGetDiskFreeSpaceExW(LPCWSTR,ULARGE_INTEGER*,ULARGE_INTEGER*,ULARGE_INTEGER*);
SHSTDAPI_(BOOL) SHGetNewLinkInfoA(LPCSTR,LPCSTR,LPSTR,BOOL*,UINT);
SHSTDAPI_(BOOL) SHGetNewLinkInfoW(LPCWSTR,LPCWSTR,LPWSTR,BOOL*,UINT);
#if (NTDDI_VERSION >= NTDDI_WIN2K)
SHSTDAPI_(BOOL) SHInvokePrinterCommandA(HWND,UINT,LPCSTR,LPCSTR,BOOL);
SHSTDAPI_(BOOL) SHInvokePrinterCommandW(HWND,UINT,LPCWSTR,LPCWSTR,BOOL);
#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */
#if (_WIN32_WINNT >= 0x0500) || (_WIN32_WINDOWS >= 0x0500)
SHSTDAPI SHLoadNonloadedIconOverlayIdentifiers(void);
SHSTDAPI SHIsFileAvailableOffline(LPCWSTR,PDWORD);
#endif
#if (NTDDI_VERSION >= NTDDI_WINXP)
SHSTDAPI SHSetLocalizedName(LPCWSTR,LPCWSTR,int);
#endif /* (NTDDI_VERSION >= NTDDI_WINXP) */
#if (NTDDI_VERSION >= NTDDI_VISTA)
SHSTDAPI SHRemoveLocalizedName(LPCWSTR);
SHSTDAPI SHGetLocalizedName(LPCWSTR,LPWSTR,UINT,int*);
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#ifdef UNICODE
typedef DRAGINFOW DRAGINFO;
typedef LPDRAGINFOW LPDRAGINFO;
typedef SHFILEOPSTRUCTW SHFILEOPSTRUCT;
typedef LPSHFILEOPSTRUCTW LPSHFILEOPSTRUCT;
typedef SHNAMEMAPPINGW SHNAMEMAPPING;
typedef LPSHNAMEMAPPINGW LPSHNAMEMAPPING;
typedef SHELLEXECUTEINFOW SHELLEXECUTEINFO;
typedef LPSHELLEXECUTEINFOW LPSHELLEXECUTEINFO;
typedef NOTIFYICONDATAW NOTIFYICONDATA;
typedef PNOTIFYICONDATAW PNOTIFYICONDATA;
#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAW_V1_SIZE
#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAW_V2_SIZE
#define NOTIFYICONDATA_V3_SIZE NOTIFYICONDATAW_V3_SIZE
#define DragQueryFile DragQueryFileW
#define FindExecutable FindExecutableW
#define ShellAbout ShellAboutW
#define ExtractAssociatedIcon ExtractAssociatedIconW
#define ExtractIcon ExtractIconW
#define DoEnvironmentSubst DoEnvironmentSubstW
#define ExtractIconEx ExtractIconExW
#define SHFileOperation SHFileOperationW
#define WinExecError WinExecErrorW
#define SHQueryRecycleBin SHQueryRecycleBinW
#define SHEmptyRecycleBin SHEmptyRecycleBinW
#define Shell_NotifyIcon Shell_NotifyIconW
#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExW
#define SHGetNewLinkInfo SHGetNewLinkInfoW
#define SHInvokePrinterCommand SHInvokePrinterCommandW
#define ShellMessageBox  ShellMessageBoxW
#define ShellExecute ShellExecuteW
#define ShellExecuteEx ShellExecuteExW
#define SHGetFileInfo SHGetFileInfoW
#else
typedef DRAGINFOA DRAGINFO;
typedef LPDRAGINFOA LPDRAGINFO;
typedef SHFILEOPSTRUCTA SHFILEOPSTRUCT;
typedef LPSHFILEOPSTRUCTA LPSHFILEOPSTRUCT;
typedef SHNAMEMAPPINGA SHNAMEMAPPING;
typedef LPSHNAMEMAPPINGA LPSHNAMEMAPPING;
typedef SHELLEXECUTEINFOA SHELLEXECUTEINFO;
typedef LPSHELLEXECUTEINFOA LPSHELLEXECUTEINFO;
typedef NOTIFYICONDATAA NOTIFYICONDATA;
typedef PNOTIFYICONDATAA PNOTIFYICONDATA;
#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAA_V1_SIZE
#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAA_V2_SIZE
#define NOTIFYICONDATA_V3_SIZE NOTIFYICONDATAA_V3_SIZE
#define DragQueryFile DragQueryFileA
#define FindExecutable FindExecutableA
#define ShellAbout ShellAboutA
#define ExtractAssociatedIcon ExtractAssociatedIconA
#define ExtractIcon ExtractIconA
#define DoEnvironmentSubst DoEnvironmentSubstA
#define ExtractIconEx ExtractIconExA
#define SHFileOperation SHFileOperationA
#define WinExecError WinExecErrorA
#define SHQueryRecycleBin SHQueryRecycleBinA
#define SHEmptyRecycleBin SHEmptyRecycleBinA
#define Shell_NotifyIcon Shell_NotifyIconA
#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExA
#define SHGetNewLinkInfo SHGetNewLinkInfoA
#define SHInvokePrinterCommand SHInvokePrinterCommandA
#define ShellMessageBox  ShellMessageBoxA
#define ShellExecute ShellExecuteA
#define ShellExecuteEx ShellExecuteExA
#define SHGetFileInfo SHGetFileInfoA
#endif /* UNICODE */

#define SHGetDiskFreeSpace  SHGetDiskFreeSpaceEx

#if __POCC__ >= 290
#pragma warn(pop)
#endif

#ifdef __cplusplus
}
#endif

#if !defined(_WIN64)
#include <poppack.h>
#endif

/* API for new Network Address Control */
#if (NTDDI_VERSION >= NTDDI_VISTA)

#define WC_NETADDRESS  L"msctls_netaddress"

SHSTDAPI_(BOOL) InitNetworkAddressControl(void);

typedef struct tagNC_ADDRESS {
   struct NET_ADDRESS_INFO_ *pAddrInfo;
   USHORT PortNumber;
   BYTE PrefixLength;
} NC_ADDRESS, *PNC_ADDRESS;

#define NCM_GETADDRESS  (WM_USER+1)
#define NCM_SETALLOWTYPE  (WM_USER+2)
#define NCM_GETALLOWTYPE  (WM_USER+3)
#define NCM_DISPLAYERRORTIP  (WM_USER+4)

#define NetAddr_GetAddress(hwnd,pv)  (HRESULT)SNDMSG(hwnd,NCM_GETADDRESS,0,(LPARAM)pv)
#define NetAddr_SetAllowType(hwnd,addrMask)  (HRESULT)SNDMSG(hwnd,NCM_SETALLOWTYPE,(WPARAM)addrMask,0)
#define NetAddr_GetAllowType(hwnd)  (DWORD)SNDMSG(hwnd,NCM_GETALLOWTYPE,0,0)
#define NetAddr_DisplayErrorTip(hwnd)  (HRESULT)SNDMSG(hwnd,NCM_DISPLAYERRORTIP,0,0)

#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#if (NTDDI_VERSION >= NTDDI_VISTA)
STDAPI SHGetDriveMedia(LPCWSTR,DWORD*);
#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */

#endif /* _SHELLAPI_H */
