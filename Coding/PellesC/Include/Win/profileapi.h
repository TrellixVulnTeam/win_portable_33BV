#ifndef _PROFILEAPI_H
#define _PROFILEAPI_H

#if __POCC__ >= 500
#pragma once
#endif

/* ApiSet api-ms-win-core-profile-l1 */

/* #include <apiset.h> */
#include <apisetcconv.h>
#include <minwindef.h>

WINBASEAPI BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *);
WINBASEAPI BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *);

#endif /* _PROFILEAPI_H */
