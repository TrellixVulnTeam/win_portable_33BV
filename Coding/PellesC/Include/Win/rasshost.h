#ifndef _RASSHOST_H
#define _RASSHOST_H

#if __POCC__ >= 500
#pragma once
#endif

/* Remote Access Server and third party security DLL definitions */

#include <mprapi.h>

#define SECURITYMSG_SUCCESS  1
#define SECURITYMSG_FAILURE  2
#define SECURITYMSG_ERROR  3

typedef DWORD HPORT;

typedef struct _SECURITY_MESSAGE {
    DWORD dwMsgId;
    HPORT hPort;
    DWORD dwError;
    CHAR UserName[UNLEN+1];
    CHAR Domain[DNLEN+1];

} SECURITY_MESSAGE, *PSECURITY_MESSAGE;

typedef struct _RAS_SECURITY_INFO {
    DWORD LastError;
    DWORD BytesReceived;
    CHAR DeviceName[MAX_DEVICE_NAME+1];
} RAS_SECURITY_INFO, *PRAS_SECURITY_INFO;

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2027 2028)  /* Missing prototype */
#endif
typedef DWORD (WINAPI *RASSECURITYPROC)();
#if __POCC__ >= 290
#pragma warn(pop)
#endif

VOID WINAPI RasSecurityDialogComplete(SECURITY_MESSAGE*);
DWORD WINAPI RasSecurityDialogBegin(HPORT,PBYTE,DWORD,PBYTE,DWORD,VOID (WINAPI *)(SECURITY_MESSAGE*));
DWORD WINAPI RasSecurityDialogEnd(HPORT);
DWORD WINAPI RasSecurityDialogSend(HPORT,PBYTE,WORD);
DWORD WINAPI RasSecurityDialogReceive(HPORT,PBYTE,PWORD,DWORD,HANDLE);
DWORD WINAPI RasSecurityDialogGetInfo(HPORT,RAS_SECURITY_INFO*);

#endif /* _RASSHOST_H */
