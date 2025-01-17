#ifndef _BASETSD_H
#define _BASETSD_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows Basic sized type definitions (01-05-29) */

#if (__POCC__ >= 1500) && (defined(_M_MRX000) || defined(_M_AMD64) || defined(_M_IA64))
#define POINTER_64 __ptr64
typedef unsigned __int64 POINTER_64_INT;
#if defined(_WIN64)
#define POINTER_32  __ptr32
#else /* !_WIN64 */
#define POINTER_32
#endif /* !_WIN64 */
#else /* __POCC__ < 600 ... */
#if __POCC__ >= 1500
#define POINTER_64 __ptr64
#else /* __POCC__ < 600 */
#define POINTER_64
#endif /* __POCC__ < 600 */
typedef unsigned long POINTER_64_INT;
#define POINTER_32
#endif /* __POCC__ < 600 ... */

#if defined(_IA64_) || defined(_AMD64_)
#define FIRMWARE_PTR
#else
#define FIRMWARE_PTR  POINTER_32
#endif

#define POINTER_SIGNED
#define POINTER_UNSIGNED

#define SPOINTER_32 POINTER_SIGNED POINTER_32
#define UPOINTER_32 POINTER_UNSIGNED POINTER_32

#ifdef __cplusplus
extern "C" {
#endif

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2006)  /* Conversion from 'type1' to 'type2' is not portable */
#pragma warn(disable:2052)  /* Conversion from 'type1' to 'type2' is undefined */
#pragma warn(disable:2215)  /* possible loss of data */
#endif

typedef signed char INT8, *PINT8;
typedef signed short INT16, *PINT16;
typedef signed int INT32, *PINT32;
typedef signed __int64 INT64, *PINT64;
typedef unsigned char UINT8, *PUINT8;
typedef unsigned short UINT16, *PUINT16;
typedef unsigned int UINT32, *PUINT32;
typedef unsigned __int64 UINT64, *PUINT64;

typedef int LONG32, *PLONG32;

typedef unsigned int ULONG32, *PULONG32;
typedef unsigned int DWORD32, *PDWORD32;

#if !defined(_W64)
#define _W64
#endif

#ifdef _WIN64

typedef __int64 INT_PTR, *PINT_PTR;
typedef unsigned __int64 UINT_PTR, *PUINT_PTR;
typedef __int64 LONG_PTR, *PLONG_PTR;
typedef unsigned __int64 ULONG_PTR, *PULONG_PTR;

typedef __int64 SHANDLE_PTR;
typedef unsigned __int64 HANDLE_PTR;
typedef unsigned int UHALF_PTR, *PUHALF_PTR;
typedef int HALF_PTR, *PHALF_PTR;
#define __int3264  __int64

#define ADDRESS_TAG_BIT  0x40000000000ULL

static inline unsigned long HandleToUlong(const void *h)  { return (unsigned long)(ULONG_PTR)h; }
static inline long HandleToLong(const void *h)  { return (long)(LONG_PTR)h; }
static inline void *ULongToHandle(const unsigned long ul)  { return ((void *)(UINT_PTR)ul ); }
static inline void *LongToHandle(const long h)  { return (void *)(INT_PTR)h; }
static inline unsigned long PtrToUlong(const void *p)  { return (unsigned long)(ULONG_PTR)p; }
static inline unsigned int PtrToUint(const void *p)  { return (unsigned int)(UINT_PTR)p; }
static inline unsigned short PtrToUshort(const void *p)  { return (unsigned short)(ULONG_PTR)p; }
static inline long PtrToLong(const void *p)  { return (long)(LONG_PTR)p; }
static inline int PtrToInt(const void *p)  { return (int)(INT_PTR)p; }
static inline short PtrToShort(const void *p)  { return (short)(LONG_PTR)p; }
static inline void *IntToPtr(const int i)  { return (void *)(INT_PTR)i; }
static inline void *UIntToPtr(const unsigned int ui)  { return (void *)(UINT_PTR)ui; }
static inline void *LongToPtr(const long l)  { return (void *)(LONG_PTR)l; }
static inline void *ULongToPtr(const unsigned long ul)  { return (void *)(ULONG_PTR)ul; }

#define PtrToPtr64(p)  ((void * POINTER_64)p)
#define Ptr64ToPtr(p)  ((void *)p)
#define HandleToHandle64(h)  (PtrToPtr64(h))
#define Handle64ToHandle(h)  (Ptr64ToPtr(h))

static inline void *Ptr32ToPtr(const void *POINTER_32 p) { return ((void *)(ULONG_PTR)(unsigned long)p); }
static inline void *Handle32ToHandle(const void *POINTER_32 h) { return ((void *)(LONG_PTR)(long)h); }
static inline void *POINTER_32 PtrToPtr32(const void *p) { return ((void *POINTER_32)(unsigned long)(ULONG_PTR)p); }

#define HandleToHandle32(h)  (PtrToPtr32(h))

#else /* _WIN64 */

typedef _W64 int INT_PTR, *PINT_PTR;
typedef _W64 unsigned int UINT_PTR, *PUINT_PTR;
typedef _W64 long LONG_PTR, *PLONG_PTR;
typedef _W64 unsigned long ULONG_PTR, *PULONG_PTR;

typedef _W64 long SHANDLE_PTR;
typedef _W64 unsigned long HANDLE_PTR;
typedef unsigned short UHALF_PTR, *PUHALF_PTR;
typedef short HALF_PTR, *PHALF_PTR;
#define __int3264  __int32

#define ADDRESS_TAG_BIT  0x80000000UL

#define HandleToULong(h)  ((ULONG)(ULONG_PTR)(h))
#define HandleToLong(h)  ((LONG)(LONG_PTR)(h))
#define ULongToHandle(ul)  ((HANDLE)(ULONG_PTR)(ul))
#define LongToHandle(h)  ((HANDLE)(LONG_PTR)(h))
#define PtrToUlong(p)  ((ULONG)(ULONG_PTR)(p))
#define PtrToLong(p)  ((LONG)(LONG_PTR)(p))
#define PtrToUint(p)  ((UINT)(UINT_PTR)(p))
#define PtrToInt(p)  ((INT)(INT_PTR)(p))
#define PtrToUshort(p)  ((unsigned short)(ULONG_PTR)(p))
#define PtrToShort(p)  ((short)(LONG_PTR)(p))
#define IntToPtr(i)  ((void*)(INT_PTR)((int)i))
#define UIntToPtr(ui)  ((void*)(UINT_PTR)((unsigned int)ui))
#define LongToPtr(l)  ((void*)(LONG_PTR)((long)l))
#define ULongToPtr(ul)  ((void*)(ULONG_PTR)((unsigned long)ul))

#define Ptr32ToPtr(p)  ((void *) p)
#define Handle32ToHandle(h)  (Ptr32ToPtr(h))
#define PtrToPtr32(p)  ((void * POINTER_32)p)
#define HandleToHandle32(h)  (PtrToPtr32(h))

#if !defined(__midl)
static inline void *POINTER_64 PtrToPtr64(const void *p) { return ((void *POINTER_64)(unsigned __int64)(ULONG_PTR)p); }
static inline void *Ptr64ToPtr(const void *POINTER_64 p) { return ((void *)(ULONG_PTR) (unsigned __int64)p); }
static inline void *POINTER_64 HandleToHandle64(const void *h) { return ((void *POINTER_64)(__int64) (LONG_PTR)h); }
static inline void *Handle64ToHandle(const void *POINTER_64 h) { return ((void *)(ULONG_PTR) (unsigned __int64)h); }
#endif /* __midl */

#endif /* _WIN64 */

#define HandleToUlong(h)  HandleToULong(h)
#define UlongToHandle(ul)  ULongToHandle(ul)
#define UlongToPtr(ul)  ULongToPtr(ul)
#define UintToPtr(ui)  UIntToPtr(ui)

#define MAXUINT_PTR  (~((UINT_PTR)0))
#define MAXINT_PTR  ((INT_PTR)(MAXUINT_PTR>>1))
#define MININT_PTR  (~MAXINT_PTR)

#define MAXULONG_PTR  (~((ULONG_PTR)0))
#define MAXLONG_PTR  ((LONG_PTR)(MAXULONG_PTR>>1))
#define MINLONG_PTR  (~MAXLONG_PTR)

#define MAXUHALF_PTR  ((UHALF_PTR)~0)
#define MAXHALF_PTR  ((HALF_PTR)(MAXUHALF_PTR>>1))
#define MINHALF_PTR  (~MAXHALF_PTR)

#if _WIN32_WINNT >= 0x0600

#define MAXUINT8  ((UINT8)~((UINT8)0))
#define MAXINT8  ((INT8)(MAXUINT8 >> 1))
#define MININT8  ((INT8)~MAXINT8)

#define MAXUINT16  ((UINT16)~((UINT16)0))
#define MAXINT16  ((INT16)(MAXUINT16 >> 1))
#define MININT16  ((INT16)~MAXINT16)

#define MAXUINT32  ((UINT32)~((UINT32)0))
#define MAXINT32  ((INT32)(MAXUINT32 >> 1))
#define MININT32  ((INT32)~MAXINT32)

#define MAXUINT64  ((UINT64)~((UINT64)0))
#define MAXINT64  ((INT64)(MAXUINT64 >> 1))
#define MININT64  ((INT64)~MAXINT64)

#define MAXULONG32  ((ULONG32)~((ULONG32)0))
#define MAXLONG32  ((LONG32)(MAXULONG32 >> 1))
#define MINLONG32  ((LONG32)~MAXLONG32)

#define MAXULONG64  ((ULONG64)~((ULONG64)0))
#define MAXLONG64  ((LONG64)(MAXULONG64 >> 1))
#define MINLONG64  ((LONG64)~MAXLONG64)

#define MAXULONGLONG  ((ULONGLONG)~((ULONGLONG)0))
#define MINLONGLONG  ((LONGLONG)~MAXLONGLONG)

#define MAXSIZE_T  ((SIZE_T)~((SIZE_T)0))
#define MAXSSIZE_T  ((SSIZE_T)(MAXSIZE_T >> 1))
#define MINSSIZE_T  ((SSIZE_T)~MAXSSIZE_T)

#define MAXUINT  ((UINT)~((UINT)0))
#define MAXINT  ((INT)(MAXUINT >> 1))
#define MININT  ((INT)~MAXINT)

#define MAXDWORD32  ((DWORD32)~((DWORD32)0))
#define MAXDWORD64  ((DWORD64)~((DWORD64)0))

#endif /* _WIN32_WINNT >= 0x0600 */

typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef LONG_PTR SSIZE_T, *PSSIZE_T;

typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;

typedef __int64 LONG64, *PLONG64;

typedef unsigned __int64 ULONG64, *PULONG64;
typedef unsigned __int64 DWORD64, *PDWORD64;

typedef ULONG_PTR KAFFINITY;
typedef KAFFINITY *PKAFFINITY;

#if __POCC__ >= 290
#pragma warn(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _BASETSD_H */
