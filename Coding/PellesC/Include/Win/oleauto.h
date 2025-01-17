#ifndef _OLEAUTO_H
#define _OLEAUTO_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows OLE Automation support definitions */

#include <pshpack8.h>

#define WINOLEAUTAPI EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define WINOLEAUTAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE

EXTERN_C const IID IID_StdOle;

#define STDOLE_MAJORVERNUM  0x1
#define STDOLE_MINORVERNUM  0x0
#define STDOLE_LCID  0x0000

#define STDOLE2_MAJORVERNUM  0x2
#define STDOLE2_MINORVERNUM  0x0
#define STDOLE2_LCID  0x0000

#ifndef _LCID_DEFINED
typedef DWORD LCID;
#define _LCID_DEFINED
#endif

#ifndef BEGIN_INTERFACE
#define BEGIN_INTERFACE
#define END_INTERFACE
#endif

#include <oaidl.h>

#define VARIANT_NOVALUEPROP  0x01
#define VARIANT_ALPHABOOL  0x02
#define VARIANT_NOUSEROVERRIDE  0x04
#define VARIANT_CALENDAR_HIJRI  0x08
#define VARIANT_LOCALBOOL  0x10
#define VARIANT_CALENDAR_THAI  0x20
#define VARIANT_CALENDAR_GREGORIAN  0x40
#define VARIANT_USE_NLS  0x80

#define VAR_TIMEVALUEONLY  ((DWORD)0x00000001)
#define VAR_DATEVALUEONLY  ((DWORD)0x00000002)
#define VAR_VALIDDATE  ((DWORD)0x00000004)
#define VAR_CALENDAR_HIJRI  ((DWORD)0x00000008)
#define VAR_LOCALBOOL  ((DWORD)0x00000010)
#define VAR_FORMAT_NOSUBSTITUTE  ((DWORD)0x00000020)
#define VAR_FOURDIGITYEARS  ((DWORD)0x00000040)

#ifndef LOCALE_USE_NLS
#define LOCALE_USE_NLS  0x10000000
#endif

#define VAR_CALENDAR_THAI  ((DWORD)0x00000080)
#define	VAR_CALENDAR_GREGORIAN  ((DWORD)0x00000100)

#define VTDATEGRE_MAX  2958465
#define VTDATEGRE_MIN  -657434

#define NUMPRS_LEADING_WHITE  0x0001
#define NUMPRS_TRAILING_WHITE  0x0002
#define NUMPRS_LEADING_PLUS  0x0004
#define NUMPRS_TRAILING_PLUS  0x0008
#define NUMPRS_LEADING_MINUS  0x0010
#define NUMPRS_TRAILING_MINUS  0x0020
#define NUMPRS_HEX_OCT  0x0040
#define NUMPRS_PARENS  0x0080
#define NUMPRS_DECIMAL  0x0100
#define NUMPRS_THOUSANDS  0x0200
#define NUMPRS_CURRENCY  0x0400
#define NUMPRS_EXPONENT  0x0800
#define NUMPRS_USE_ALL  0x1000
#define NUMPRS_STD  0x1FFF
#define NUMPRS_NEG  0x10000
#define NUMPRS_INEXACT  0x20000

#define VTBIT_I1  (1<<VT_I1)
#define VTBIT_UI1  (1<<VT_UI1)
#define VTBIT_I2  (1<<VT_I2)
#define VTBIT_UI2  (1<<VT_UI2)
#define VTBIT_I4  (1<<VT_I4)
#define VTBIT_UI4  (1<<VT_UI4)
#define VTBIT_I8  (1<<VT_I8)
#define VTBIT_UI8  (1<<VT_UI8)
#define VTBIT_R4  (1<<VT_R4)
#define VTBIT_R8  (1<<VT_R8)
#define VTBIT_CY  (1<<VT_CY)
#define VTBIT_DECIMAL  (1<<VT_DECIMAL)

#define VARCMP_LT  0
#define VARCMP_EQ  1
#define VARCMP_GT  2
#define VARCMP_NULL  3

#define VT_HARDTYPE  VT_RESERVED

#define MEMBERID_NIL  DISPID_UNKNOWN
#define ID_DEFAULTINST  -2

#define DISPATCH_METHOD  0x1
#define DISPATCH_PROPERTYGET  0x2
#define DISPATCH_PROPERTYPUT  0x4
#define DISPATCH_PROPERTYPUTREF  0x8

#define ACTIVEOBJECT_STRONG  0x0
#define ACTIVEOBJECT_WEAK  0x1

#define VarUI4FromUI4(in,pout)  (*(pout)=(in))
#define VarI4FromI4(in,pout)  (*(pout)=(in))

#define VarUI8FromUI8(in,pOut)  (*(pOut)=(in))
#define VarI8FromI8(in,pOut)  (*(pOut)=(in))

#define VarUI1FromInt VarUI1FromI4
#define VarUI1FromUint VarUI1FromUI4
#define VarI2FromInt VarI2FromI4
#define VarI2FromUint VarI2FromUI4
#define VarI4FromInt VarI4FromI4
#define VarI4FromUint VarI4FromUI4
#define VarI8FromUint VarI8FromUI4
#define VarR4FromInt VarR4FromI4
#define VarR4FromUint VarR4FromUI4
#define VarR8FromInt VarR8FromI4
#define VarR8FromUint VarR8FromUI4
#define VarDateFromInt VarDateFromI4
#define VarDateFromUint VarDateFromUI4
#define VarCyFromInt VarCyFromI4
#define VarCyFromUint VarCyFromUI4
#define VarBstrFromInt VarBstrFromI4
#define VarBstrFromUint VarBstrFromUI4
#define VarBoolFromInt VarBoolFromI4
#define VarBoolFromUint VarBoolFromUI4
#define VarI1FromInt VarI1FromI4
#define VarI1FromUint VarI1FromUI4
#define VarUI2FromInt VarUI2FromI4
#define VarUI2FromUint VarUI2FromUI4
#define VarUI4FromInt VarUI4FromI4
#define VarUI4FromUint VarUI4FromUI4
#define VarDecFromInt VarDecFromI4
#define VarDecFromUint VarDecFromUI4
#define VarIntFromUI1 VarI4FromUI1
#define VarIntFromI2 VarI4FromI2
#define VarIntFromI4 VarI4FromI4
#define VarIntFromI8 VarI4FromI8
#define VarIntFromR4 VarI4FromR4
#define VarIntFromR8 VarI4FromR8
#define VarIntFromDate VarI4FromDate
#define VarIntFromCy VarI4FromCy
#define VarIntFromStr VarI4FromStr
#define VarIntFromDisp VarI4FromDisp
#define VarIntFromBool VarI4FromBool
#define VarIntFromI1 VarI4FromI1
#define VarIntFromUI2 VarI4FromUI2
#define VarIntFromUI4 VarI4FromUI4
#define VarIntFromUI8 VarI4FromUI8
#define VarIntFromDec VarI4FromDec
#define VarIntFromUint VarI4FromUI4
#define VarUintFromUI1 VarUI4FromUI1
#define VarUintFromI2 VarUI4FromI2
#define VarUintFromI4 VarUI4FromI4
#define VarUintFromI8 VarUI4FromI8
#define VarUintFromR4 VarUI4FromR4
#define VarUintFromR8 VarUI4FromR8
#define VarUintFromDate VarUI4FromDate
#define VarUintFromCy VarUI4FromCy
#define VarUintFromStr VarUI4FromStr
#define VarUintFromDisp VarUI4FromDisp
#define VarUintFromBool VarUI4FromBool
#define VarUintFromI1 VarUI4FromI1
#define VarUintFromUI2 VarUI4FromUI2
#define VarUintFromUI4 VarUI4FromUI4
#define VarUintFromUI8 VarUI4FromUI8
#define VarUintFromDec VarUI4FromDec
#define VarUintFromInt VarUI4FromI4

#define LHashValOfName(lcid,szName)  LHashValOfNameSys(SYS_WIN32,lcid,szName)
#define WHashValOfLHashVal(lhashval)  ((USHORT)(0x0000ffff&(lhashval)))
#define IsHashValCompatible(lhashval1,lhashval2)  ((BOOL)((0x00ff0000&(lhashval1))==(0x00ff0000&(lhashval2))))

#define LOAD_TLB_AS_32BIT  0x20
#define LOAD_TLB_AS_64BIT  0x40
#define MASK_TO_RESET_TLB_BITS  ~(LOAD_TLB_AS_32BIT|LOAD_TLB_AS_64BIT)

#if __STDC__ || defined(NONAMELESSUNION)
#define V_UNION(X,Y)  ((X)->n1.n2.n3.Y)
#define V_VT(X)  ((X)->n1.n2.vt)
#define V_RECORDINFO(X)  ((X)->n1.n2.n3.brecVal.pRecInfo)
#define V_RECORD(X)  ((X)->n1.n2.n3.brecVal.pvRecord)
#else
#define V_UNION(X,Y)  ((X)->Y)
#define V_VT(X)  ((X)->vt)
#define V_RECORDINFO(X)  ((X)->pRecInfo)
#define V_RECORD(X)  ((X)->pvRecord)
#endif

#define V_ISBYREF(X)  (V_VT(X)&VT_BYREF)
#define V_ISARRAY(X)  (V_VT(X)&VT_ARRAY)
#define V_ISVECTOR(X) (V_VT(X)&VT_VECTOR)
#define V_NONE(X)  V_I2(X)

#define V_UI1(X)  V_UNION(X,bVal)
#define V_UI1REF(X)  V_UNION(X,pbVal)
#define V_I2(X)  V_UNION(X,iVal)
#define V_I2REF(X)  V_UNION(X,piVal)
#define V_I4(X)  V_UNION(X,lVal)
#define V_I4REF(X)  V_UNION(X,plVal)
#define V_I8(X)  V_UNION(X,llVal)
#define V_I8REF(X)  V_UNION(X,pllVal)
#define V_R4(X)  V_UNION(X,fltVal)
#define V_R4REF(X)  V_UNION(X,pfltVal)
#define V_R8(X)  V_UNION(X,dblVal)
#define V_R8REF(X)  V_UNION(X,pdblVal)
#define V_I1(X)  V_UNION(X,cVal)
#define V_I1REF(X)  V_UNION(X,pcVal)
#define V_UI2(X)  V_UNION(X,uiVal)
#define V_UI2REF(X)  V_UNION(X,puiVal)
#define V_UI4(X)  V_UNION(X,ulVal)
#define V_UI4REF(X)  V_UNION(X,pulVal)
#define V_UI8(X)  V_UNION(X,ullVal)
#define V_UI8REF(X)  V_UNION(X,pullVal)
#define V_INT(X)  V_UNION(X,intVal)
#define V_INTREF(X)  V_UNION(X,pintVal)
#define V_UINT(X)  V_UNION(X,uintVal)
#define V_UINTREF(X)  V_UNION(X,puintVal)

#ifdef _WIN64
#define V_INT_PTR(X)  V_UNION(X,llVal)
#define V_UINT_PTR(X)  V_UNION(X,ullVal)
#define V_INT_PTRREF(X)  V_UNION(X,pllVal)
#define V_UINT_PTRREF(X)  V_UNION(X,pullVal)
#else /* _WIN64 */
#define V_INT_PTR(X)  V_UNION(X,lVal)
#define V_UINT_PTR(X)  V_UNION(X,ulVal)
#define V_INT_PTRREF(X)  V_UNION(X,plVal)
#define V_UINT_PTRREF(X)  V_UNION(X,pulVal)
#endif /* _WIN64 */

#define V_CY(X)  V_UNION(X,cyVal)
#define V_CYREF(X)  V_UNION(X,pcyVal)
#define V_DATE(X)  V_UNION(X,date)
#define V_DATEREF(X)  V_UNION(X,pdate)
#define V_BSTR(X)  V_UNION(X,bstrVal)
#define V_BSTRREF(X)  V_UNION(X,pbstrVal)
#define V_DISPATCH(X)  V_UNION(X,pdispVal)
#define V_DISPATCHREF(X)  V_UNION(X,ppdispVal)
#define V_ERROR(X)  V_UNION(X,scode)
#define V_ERRORREF(X)  V_UNION(X,pscode)
#define V_BOOL(X)  V_UNION(X,boolVal)
#define V_BOOLREF(X)  V_UNION(X,pboolVal)
#define V_UNKNOWN(X)  V_UNION(X,punkVal)
#define V_UNKNOWNREF(X)  V_UNION(X,ppunkVal)
#define V_VARIANTREF(X)  V_UNION(X,pvarVal)
#define V_ARRAY(X)  V_UNION(X,parray)
#define V_ARRAYREF(X)  V_UNION(X,pparray)
#define V_BYREF(X)  V_UNION(X,byref)

#define V_DECIMAL(X)  V_UNION(X,decVal)
#define V_DECIMALREF(X)  V_UNION(X,pdecVal)

typedef struct {
    INT cDig;
    ULONG dwInFlags;
    ULONG dwOutFlags;
    INT cchUsed;
    INT nBaseShift;
    INT nPwr10;
} NUMPARSE;

typedef struct {
    SYSTEMTIME st;
    USHORT wDayOfYear;
} UDATE;

typedef enum tagREGKIND {
    REGKIND_DEFAULT,
    REGKIND_REGISTER,
    REGKIND_NONE
} REGKIND;

typedef struct tagPARAMDATA {
    OLECHAR *szName;
    VARTYPE vt;
} PARAMDATA, *LPPARAMDATA;

typedef struct tagMETHODDATA {
    OLECHAR *szName;
    PARAMDATA *ppdata;
    DISPID dispid;
    UINT iMeth;
    CALLCONV cc;
    UINT cArgs;
    WORD wFlags;
    VARTYPE vtReturn;
} METHODDATA, *LPMETHODDATA;

typedef struct tagINTERFACEDATA {
    METHODDATA *pmethdata;
    UINT cMembers;
} INTERFACEDATA, *LPINTERFACEDATA;

typedef LONG DISPID;
typedef DISPID MEMBERID;

typedef ITypeLib *LPTYPELIB;
typedef ITypeInfo *LPTYPEINFO;
typedef ITypeComp *LPTYPECOMP;

typedef ICreateTypeLib *LPCREATETYPELIB;
typedef ICreateTypeInfo *LPCREATETYPEINFO;

typedef IDispatch *LPDISPATCH;

STDAPI VarAdd(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarAnd(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarCat(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarDiv(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarEqv(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarIdiv(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarImp(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarMod(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarMul(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarOr(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarPow(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarSub(LPVARIANT,LPVARIANT,LPVARIANT);
STDAPI VarXor(LPVARIANT,LPVARIANT,LPVARIANT);

STDAPI VarAbs(LPVARIANT,LPVARIANT);
STDAPI VarFix(LPVARIANT,LPVARIANT);
STDAPI VarInt(LPVARIANT,LPVARIANT);
STDAPI VarNeg(LPVARIANT,LPVARIANT);
STDAPI VarNot(LPVARIANT,LPVARIANT);

STDAPI VarRound(LPVARIANT,int,LPVARIANT);

STDAPI VarCmp(LPVARIANT,LPVARIANT,LCID,ULONG);

STDAPI VarDecAdd(LPDECIMAL,LPDECIMAL,LPDECIMAL);
STDAPI VarDecDiv(LPDECIMAL,LPDECIMAL,LPDECIMAL);
STDAPI VarDecMul(LPDECIMAL,LPDECIMAL,LPDECIMAL);
STDAPI VarDecSub(LPDECIMAL,LPDECIMAL,LPDECIMAL);

STDAPI VarDecAbs(LPDECIMAL,LPDECIMAL);
STDAPI VarDecFix(LPDECIMAL,LPDECIMAL);
STDAPI VarDecInt(LPDECIMAL,LPDECIMAL);
STDAPI VarDecNeg(LPDECIMAL,LPDECIMAL);

STDAPI VarDecRound(LPDECIMAL,int,LPDECIMAL);

STDAPI VarDecCmp(LPDECIMAL,LPDECIMAL);
STDAPI VarDecCmpR8(LPDECIMAL,double);

STDAPI VarCyAdd(CY,CY,LPCY);
STDAPI VarCyMul(CY,CY,LPCY);
STDAPI VarCyMulI4(CY,long,LPCY);
STDAPI VarCyMulI8(CY,LONG64,LPCY);
STDAPI VarCySub(CY,CY,LPCY);

STDAPI VarCyAbs(CY,LPCY);
STDAPI VarCyFix(CY,LPCY);
STDAPI VarCyInt(CY,LPCY);
STDAPI VarCyNeg(CY,LPCY);

STDAPI VarCyRound(CY,int,LPCY);

STDAPI VarCyCmp(CY,CY);
STDAPI VarCyCmpR8(CY,double);

STDAPI VarBstrCat(BSTR,BSTR,LPBSTR);
STDAPI VarBstrCmp(BSTR,BSTR,LCID,ULONG);
STDAPI VarR8Pow(double,double,double*);
STDAPI VarR4CmpR8(float,double);
STDAPI VarR8Round(double,int,double*);

// #ifdef __cplusplus
// extern "C++" { __inline HRESULT STDAPICALLTYPE VarCmp(LPVARIANT pvarLeft, LPVARIANT pvarRight, LCID lcid) { return VarCmp(pvarLeft,pvarRight,lcid,0); }}
// #endif

WINOLEAUTAPI_(BSTR) SysAllocString(const OLECHAR*);
WINOLEAUTAPI_(INT) SysReAllocString(BSTR*,const OLECHAR*);
WINOLEAUTAPI_(BSTR) SysAllocStringLen(const OLECHAR*,UINT);
WINOLEAUTAPI_(INT)  SysReAllocStringLen(BSTR*,const OLECHAR*,UINT);
WINOLEAUTAPI SysAddRefString(BSTR);
WINOLEAUTAPI_(void) SysReleaseString(BSTR);
WINOLEAUTAPI_(void) SysFreeString(BSTR);
WINOLEAUTAPI_(UINT) SysStringLen(BSTR);
WINOLEAUTAPI_(UINT) SysStringByteLen(BSTR);
WINOLEAUTAPI_(BSTR) SysAllocStringByteLen(LPCSTR,UINT);

WINOLEAUTAPI_(INT) DosDateTimeToVariantTime(USHORT,USHORT,DOUBLE*);
WINOLEAUTAPI_(INT) VariantTimeToDosDateTime(DOUBLE,USHORT*,USHORT*);
WINOLEAUTAPI_(INT) SystemTimeToVariantTime(LPSYSTEMTIME,DOUBLE*);
WINOLEAUTAPI_(INT) VariantTimeToSystemTime(DOUBLE,LPSYSTEMTIME);

WINOLEAUTAPI SafeArrayAllocDescriptor(UINT,SAFEARRAY**);
WINOLEAUTAPI SafeArrayAllocDescriptorEx(VARTYPE,UINT,SAFEARRAY**);
WINOLEAUTAPI SafeArrayAllocData(SAFEARRAY*);
WINOLEAUTAPI_(SAFEARRAY*) SafeArrayCreate(VARTYPE,UINT,SAFEARRAYBOUND*);
WINOLEAUTAPI_(SAFEARRAY*) SafeArrayCreateEx(VARTYPE,UINT,SAFEARRAYBOUND*,PVOID);
WINOLEAUTAPI SafeArrayCopyData(SAFEARRAY*,SAFEARRAY*);
WINOLEAUTAPI_(void) SafeArrayReleaseDescriptor(SAFEARRAY*);
WINOLEAUTAPI SafeArrayDestroyDescriptor(SAFEARRAY*);
WINOLEAUTAPI_(void) SafeArrayReleaseData(PVOID);
WINOLEAUTAPI SafeArrayDestroyData(SAFEARRAY*);
WINOLEAUTAPI SafeArrayAddRef(SAFEARRAY*,PVOID*);
WINOLEAUTAPI SafeArrayDestroy(SAFEARRAY*);
WINOLEAUTAPI SafeArrayRedim(SAFEARRAY*,SAFEARRAYBOUND*);
WINOLEAUTAPI_(UINT) SafeArrayGetDim(SAFEARRAY*);
WINOLEAUTAPI_(UINT) SafeArrayGetElemsize(SAFEARRAY*);
WINOLEAUTAPI SafeArrayGetUBound(SAFEARRAY*,UINT,LONG*);
WINOLEAUTAPI SafeArrayGetLBound(SAFEARRAY*,UINT,LONG*);
WINOLEAUTAPI SafeArrayLock(SAFEARRAY*);
WINOLEAUTAPI SafeArrayUnlock(SAFEARRAY*);
WINOLEAUTAPI SafeArrayAccessData(SAFEARRAY*,void**);
WINOLEAUTAPI SafeArrayUnaccessData(SAFEARRAY*);
WINOLEAUTAPI SafeArrayGetElement(SAFEARRAY*,LONG*,void*);
WINOLEAUTAPI SafeArrayPutElement(SAFEARRAY*,LONG*,void*);
WINOLEAUTAPI SafeArrayCopy(SAFEARRAY*,SAFEARRAY**);
WINOLEAUTAPI SafeArrayPtrOfIndex(SAFEARRAY*,LONG*,void**);
WINOLEAUTAPI SafeArraySetRecordInfo(SAFEARRAY*,IRecordInfo*);
WINOLEAUTAPI SafeArrayGetRecordInfo(SAFEARRAY*,IRecordInfo**);
WINOLEAUTAPI SafeArraySetIID(SAFEARRAY*,REFGUID);
WINOLEAUTAPI SafeArrayGetIID(SAFEARRAY*,GUID*);
WINOLEAUTAPI SafeArrayGetVartype(SAFEARRAY*,VARTYPE*);
WINOLEAUTAPI_(SAFEARRAY*) SafeArrayCreateVector(VARTYPE,LONG,ULONG);
WINOLEAUTAPI_(SAFEARRAY*) SafeArrayCreateVectorEx(VARTYPE,LONG,ULONG,PVOID);

WINOLEAUTAPI_(void) VariantInit(VARIANTARG*);
WINOLEAUTAPI VariantClear(VARIANTARG*);
WINOLEAUTAPI VariantCopy(VARIANTARG*,VARIANTARG*);
WINOLEAUTAPI VariantCopyInd(VARIANT*,VARIANTARG*);
WINOLEAUTAPI VariantChangeType(VARIANTARG*,VARIANTARG*,USHORT,VARTYPE);
WINOLEAUTAPI VariantChangeTypeEx(VARIANTARG*,VARIANTARG*,LCID,USHORT,VARTYPE);

WINOLEAUTAPI VectorFromBstr(BSTR,SAFEARRAY**);
WINOLEAUTAPI BstrFromVector(SAFEARRAY*,BSTR*);

WINOLEAUTAPI VarUI1FromI2(SHORT,BYTE*);
WINOLEAUTAPI VarUI1FromI4(LONG,BYTE*);
WINOLEAUTAPI VarUI1FromI8(LONG64,BYTE*);
WINOLEAUTAPI VarUI1FromR4(FLOAT,BYTE*);
WINOLEAUTAPI VarUI1FromR8(DOUBLE,BYTE*);
WINOLEAUTAPI VarUI1FromCy(CY,BYTE*);
WINOLEAUTAPI VarUI1FromDate(DATE,BYTE*);
WINOLEAUTAPI VarUI1FromStr(OLECHAR*,LCID,ULONG,BYTE*);
WINOLEAUTAPI VarUI1FromDisp(IDispatch*,LCID,BYTE*);
WINOLEAUTAPI VarUI1FromBool(VARIANT_BOOL,BYTE*);
WINOLEAUTAPI VarUI1FromI1(CHAR,BYTE*);
WINOLEAUTAPI VarUI1FromUI2(USHORT,BYTE*);
WINOLEAUTAPI VarUI1FromUI4(ULONG,BYTE*);
WINOLEAUTAPI VarUI1FromUI8(ULONG64,BYTE*);
WINOLEAUTAPI VarUI1FromDec(DECIMAL*,BYTE*);

WINOLEAUTAPI VarI2FromUI1(BYTE,SHORT*);
WINOLEAUTAPI VarI2FromI4(LONG,SHORT*);
WINOLEAUTAPI VarI2FromI8(LONG64,SHORT*);
WINOLEAUTAPI VarI2FromR4(FLOAT,SHORT*);
WINOLEAUTAPI VarI2FromR8(DOUBLE,SHORT*);
WINOLEAUTAPI VarI2FromCy(CY,SHORT*);
WINOLEAUTAPI VarI2FromDate(DATE,SHORT*);
WINOLEAUTAPI VarI2FromStr(OLECHAR*,LCID,ULONG,SHORT*);
WINOLEAUTAPI VarI2FromDisp(IDispatch*,LCID,SHORT*);
WINOLEAUTAPI VarI2FromBool(VARIANT_BOOL,SHORT*);
WINOLEAUTAPI VarI2FromI1(CHAR,SHORT*);
WINOLEAUTAPI VarI2FromUI2(USHORT,SHORT*);
WINOLEAUTAPI VarI2FromUI4(ULONG,SHORT*);
WINOLEAUTAPI VarI2FromUI8(ULONG64,SHORT*);
WINOLEAUTAPI VarI2FromDec(DECIMAL*,SHORT*);

WINOLEAUTAPI VarI4FromUI1(BYTE,LONG*);
WINOLEAUTAPI VarI4FromI2(SHORT,LONG*);
WINOLEAUTAPI VarI4FromI8(LONG64,LONG*);
WINOLEAUTAPI VarI4FromR4(FLOAT,LONG*);
WINOLEAUTAPI VarI4FromR8(DOUBLE,LONG*);
WINOLEAUTAPI VarI4FromCy(CY,LONG*);
WINOLEAUTAPI VarI4FromDate(DATE,LONG*);
WINOLEAUTAPI VarI4FromStr(OLECHAR*,LCID,ULONG,LONG*);
WINOLEAUTAPI VarI4FromDisp(IDispatch*,LCID,LONG*);
WINOLEAUTAPI VarI4FromBool(VARIANT_BOOL,LONG*);
WINOLEAUTAPI VarI4FromI1(CHAR,LONG*);
WINOLEAUTAPI VarI4FromUI2(USHORT,LONG*);
WINOLEAUTAPI VarI4FromUI4(ULONG,LONG*);
WINOLEAUTAPI VarI4FromUI8(ULONG64,LONG*);
WINOLEAUTAPI VarI4FromDec(DECIMAL*,LONG*);

WINOLEAUTAPI VarI8FromUI1(BYTE,LONG64*);
WINOLEAUTAPI VarI8FromI2(SHORT,LONG64*);
WINOLEAUTAPI VarI8FromR4(FLOAT,LONG64*);
WINOLEAUTAPI VarI8FromR8(DOUBLE,LONG64*);
WINOLEAUTAPI VarI8FromCy(CY,LONG64*);
WINOLEAUTAPI VarI8FromDate(DATE,LONG64*);
WINOLEAUTAPI VarI8FromStr(LPCOLESTR,LCID,ULONG,LONG64*);
WINOLEAUTAPI VarI8FromDisp(IDispatch*,LCID,LONG64*);
WINOLEAUTAPI VarI8FromBool(VARIANT_BOOL,LONG64*);
WINOLEAUTAPI VarI8FromI1(CHAR,LONG64*);
WINOLEAUTAPI VarI8FromUI2(USHORT,LONG64*);
WINOLEAUTAPI VarI8FromUI4(ULONG,LONG64*);
WINOLEAUTAPI VarI8FromUI8(ULONG64,LONG64*);
WINOLEAUTAPI VarI8FromDec(const DECIMAL*,LONG64*);

WINOLEAUTAPI VarR4FromUI1(BYTE,FLOAT*);
WINOLEAUTAPI VarR4FromI2(SHORT,FLOAT*);
WINOLEAUTAPI VarR4FromI4(LONG,FLOAT*);
WINOLEAUTAPI VarR4FromI8(LONG64,FLOAT*);
WINOLEAUTAPI VarR4FromR8(DOUBLE,FLOAT*);
WINOLEAUTAPI VarR4FromCy(CY,FLOAT*);
WINOLEAUTAPI VarR4FromDate(DATE,FLOAT*);
WINOLEAUTAPI VarR4FromStr(OLECHAR*,LCID,ULONG,FLOAT*);
WINOLEAUTAPI VarR4FromDisp(IDispatch*,LCID,FLOAT*);
WINOLEAUTAPI VarR4FromBool(VARIANT_BOOL,FLOAT*);
WINOLEAUTAPI VarR4FromI1(CHAR,FLOAT*);
WINOLEAUTAPI VarR4FromUI2(USHORT,FLOAT*);
WINOLEAUTAPI VarR4FromUI4(ULONG,FLOAT*);
WINOLEAUTAPI VarR4FromUI8(ULONG64,FLOAT*);
WINOLEAUTAPI VarR4FromDec(DECIMAL*,FLOAT*);

WINOLEAUTAPI VarR8FromUI1(BYTE,DOUBLE*);
WINOLEAUTAPI VarR8FromI2(SHORT,DOUBLE*);
WINOLEAUTAPI VarR8FromI4(LONG,DOUBLE*);
WINOLEAUTAPI VarR8FromI8(LONG64,DOUBLE*);
WINOLEAUTAPI VarR8FromR4(FLOAT,DOUBLE*);
WINOLEAUTAPI VarR8FromCy(CY,DOUBLE*);
WINOLEAUTAPI VarR8FromDate(DATE,DOUBLE*);
WINOLEAUTAPI VarR8FromStr(OLECHAR*,LCID,ULONG,DOUBLE*);
WINOLEAUTAPI VarR8FromDisp(IDispatch*,LCID,DOUBLE*);
WINOLEAUTAPI VarR8FromBool(VARIANT_BOOL,DOUBLE*);
WINOLEAUTAPI VarR8FromI1(CHAR,DOUBLE*);
WINOLEAUTAPI VarR8FromUI2(USHORT,DOUBLE*);
WINOLEAUTAPI VarR8FromUI4(ULONG,DOUBLE*);
WINOLEAUTAPI VarR8FromUI8(ULONG64,DOUBLE*);
WINOLEAUTAPI VarR8FromDec(DECIMAL*,DOUBLE*);

WINOLEAUTAPI VarDateFromUI1(BYTE,DATE*);
WINOLEAUTAPI VarDateFromI2(SHORT,DATE*);
WINOLEAUTAPI VarDateFromI4(LONG,DATE*);
WINOLEAUTAPI VarDateFromI8(LONG64,DATE*);
WINOLEAUTAPI VarDateFromR4(FLOAT,DATE*);
WINOLEAUTAPI VarDateFromR8(DOUBLE,DATE*);
WINOLEAUTAPI VarDateFromCy(CY,DATE*);
WINOLEAUTAPI VarDateFromStr(OLECHAR*,LCID,ULONG,DATE*);
WINOLEAUTAPI VarDateFromDisp(IDispatch*,LCID,DATE*);
WINOLEAUTAPI VarDateFromBool(VARIANT_BOOL,DATE*);
WINOLEAUTAPI VarDateFromI1(CHAR,DATE*);
WINOLEAUTAPI VarDateFromUI2(USHORT,DATE*);
WINOLEAUTAPI VarDateFromUI4(ULONG,DATE*);
WINOLEAUTAPI VarDateFromUI8(ULONG64,DATE*);
WINOLEAUTAPI VarDateFromDec(DECIMAL*,DATE*);

WINOLEAUTAPI VarCyFromUI1(BYTE,CY*);
WINOLEAUTAPI VarCyFromI2(SHORT,CY*);
WINOLEAUTAPI VarCyFromI4(LONG,CY*);
WINOLEAUTAPI VarCyFromI8(LONG64,CY*);
WINOLEAUTAPI VarCyFromR4(FLOAT,CY*);
WINOLEAUTAPI VarCyFromR8(DOUBLE,CY*);
WINOLEAUTAPI VarCyFromDate(DATE,CY*);
WINOLEAUTAPI VarCyFromStr(OLECHAR*,LCID,ULONG,CY*);
WINOLEAUTAPI VarCyFromDisp(IDispatch*,LCID,CY*);
WINOLEAUTAPI VarCyFromBool(VARIANT_BOOL,CY*);
WINOLEAUTAPI VarCyFromI1(CHAR,CY*);
WINOLEAUTAPI VarCyFromUI2(USHORT,CY*);
WINOLEAUTAPI VarCyFromUI4(ULONG,CY*);
WINOLEAUTAPI VarCyFromUI8(ULONG64,CY*);
WINOLEAUTAPI VarCyFromDec(DECIMAL*,CY*);

WINOLEAUTAPI VarBstrFromUI1(BYTE,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromI2(SHORT,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromI4(LONG,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromI8(LONG64,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromR4(FLOAT,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromR8(DOUBLE,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromCy(CY,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromDate(DATE,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromDisp(IDispatch*,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromBool(VARIANT_BOOL,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromI1(CHAR,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromUI2(USHORT,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromUI4(ULONG,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromUI8(ULONG64,LCID,ULONG,BSTR*);
WINOLEAUTAPI VarBstrFromDec(DECIMAL*,LCID,ULONG,BSTR*);

WINOLEAUTAPI VarBoolFromUI1(BYTE,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromI2(SHORT,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromI4(LONG,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromI8(LONG64,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromR4(FLOAT,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromR8(DOUBLE,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromDate(DATE,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromCy(CY,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromStr(OLECHAR*,LCID,ULONG,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromDisp(IDispatch*,LCID,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromI1(CHAR,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromUI2(USHORT,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromUI4(ULONG,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromUI8(ULONG64,VARIANT_BOOL*);
WINOLEAUTAPI VarBoolFromDec(DECIMAL*,VARIANT_BOOL*);

WINOLEAUTAPI VarI1FromUI1(BYTE,CHAR*);
WINOLEAUTAPI VarI1FromI2(SHORT,CHAR*);
WINOLEAUTAPI VarI1FromI4(LONG,CHAR*);
WINOLEAUTAPI VarI1FromI8(LONG64,CHAR*);
WINOLEAUTAPI VarI1FromR4(FLOAT,CHAR*);
WINOLEAUTAPI VarI1FromR8(DOUBLE,CHAR*);
WINOLEAUTAPI VarI1FromDate(DATE,CHAR*);
WINOLEAUTAPI VarI1FromCy(CY,CHAR*);
WINOLEAUTAPI VarI1FromStr(OLECHAR*,LCID,ULONG,CHAR*);
WINOLEAUTAPI VarI1FromDisp(IDispatch*,LCID,CHAR*);
WINOLEAUTAPI VarI1FromBool(VARIANT_BOOL,CHAR*);
WINOLEAUTAPI VarI1FromUI2(USHORT,CHAR*);
WINOLEAUTAPI VarI1FromUI4(ULONG,CHAR*);
WINOLEAUTAPI VarI1FromUI8(ULONG64,CHAR*);
WINOLEAUTAPI VarI1FromDec(DECIMAL*,CHAR*);

WINOLEAUTAPI VarUI2FromUI1(BYTE,USHORT*);
WINOLEAUTAPI VarUI2FromI2(SHORT,USHORT*);
WINOLEAUTAPI VarUI2FromI4(LONG,USHORT*);
WINOLEAUTAPI VarUI2FromI8(LONG64,USHORT*);
WINOLEAUTAPI VarUI2FromR4(FLOAT,USHORT*);
WINOLEAUTAPI VarUI2FromR8(DOUBLE,USHORT*);
WINOLEAUTAPI VarUI2FromDate(DATE,USHORT*);
WINOLEAUTAPI VarUI2FromCy(CY,USHORT*);
WINOLEAUTAPI VarUI2FromStr(OLECHAR*,LCID,ULONG,USHORT*);
WINOLEAUTAPI VarUI2FromDisp(IDispatch*,LCID,USHORT*);
WINOLEAUTAPI VarUI2FromBool(VARIANT_BOOL,USHORT*);
WINOLEAUTAPI VarUI2FromI1(CHAR,USHORT*);
WINOLEAUTAPI VarUI2FromUI4(ULONG,USHORT*);
WINOLEAUTAPI VarUI2FromUI8(ULONG64,USHORT*);
WINOLEAUTAPI VarUI2FromDec(DECIMAL*,USHORT*);

WINOLEAUTAPI VarUI4FromUI1(BYTE,ULONG*);
WINOLEAUTAPI VarUI4FromI2(SHORT,ULONG*);
WINOLEAUTAPI VarUI4FromI4(LONG,ULONG*);
WINOLEAUTAPI VarUI4FromI8(LONG64,ULONG*);
WINOLEAUTAPI VarUI4FromR4(FLOAT,ULONG*);
WINOLEAUTAPI VarUI4FromR8(DOUBLE,ULONG*);
WINOLEAUTAPI VarUI4FromDate(DATE,ULONG*);
WINOLEAUTAPI VarUI4FromCy(CY,ULONG*);
WINOLEAUTAPI VarUI4FromStr(OLECHAR*,LCID,ULONG,ULONG*);
WINOLEAUTAPI VarUI4FromDisp(IDispatch*,LCID,ULONG*);
WINOLEAUTAPI VarUI4FromBool(VARIANT_BOOL,ULONG*);
WINOLEAUTAPI VarUI4FromI1(CHAR,ULONG*);
WINOLEAUTAPI VarUI4FromUI2(USHORT,ULONG*);
WINOLEAUTAPI VarUI4FromUI8(ULONG64,ULONG*);
WINOLEAUTAPI VarUI4FromDec(DECIMAL*,ULONG*);

WINOLEAUTAPI VarUI8FromUI1(BYTE,ULONG64*);
WINOLEAUTAPI VarUI8FromI2(SHORT,ULONG64*);

WINOLEAUTAPI VarUI8FromI4(LONG,ULONG64*);

WINOLEAUTAPI VarUI8FromI8(LONG64,ULONG64*);
WINOLEAUTAPI VarUI8FromR4(FLOAT,ULONG64*);
WINOLEAUTAPI VarUI8FromR8(DOUBLE,ULONG64*);
WINOLEAUTAPI VarUI8FromCy(CY,ULONG64*);
WINOLEAUTAPI VarUI8FromDate(DATE,ULONG64*);
WINOLEAUTAPI VarUI8FromStr(LPCOLESTR,LCID,ULONG,ULONG64*);
WINOLEAUTAPI VarUI8FromDisp(IDispatch*,LCID,ULONG64*);
WINOLEAUTAPI VarUI8FromBool(VARIANT_BOOL,ULONG64*);
WINOLEAUTAPI VarUI8FromI1(CHAR,ULONG64*);
WINOLEAUTAPI VarUI8FromUI2(USHORT,ULONG64*);
WINOLEAUTAPI VarUI8FromUI4(ULONG,ULONG64*);
WINOLEAUTAPI VarUI8FromDec(const DECIMAL*,ULONG64*);

WINOLEAUTAPI VarDecFromUI1(BYTE,DECIMAL*);
WINOLEAUTAPI VarDecFromI2(SHORT,DECIMAL*);
WINOLEAUTAPI VarDecFromI4(LONG,DECIMAL*);
WINOLEAUTAPI VarDecFromI8(LONG64,DECIMAL*);
WINOLEAUTAPI VarDecFromR4(FLOAT,DECIMAL*);
WINOLEAUTAPI VarDecFromR8(DOUBLE,DECIMAL*);
WINOLEAUTAPI VarDecFromDate(DATE,DECIMAL*);
WINOLEAUTAPI VarDecFromCy(CY,DECIMAL*);
WINOLEAUTAPI VarDecFromStr(OLECHAR*,LCID,ULONG,DECIMAL*);
WINOLEAUTAPI VarDecFromDisp(IDispatch*,LCID,DECIMAL*);
WINOLEAUTAPI VarDecFromBool(VARIANT_BOOL,DECIMAL*);
WINOLEAUTAPI VarDecFromI1(CHAR,DECIMAL*);
WINOLEAUTAPI VarDecFromUI2(USHORT,DECIMAL*);
WINOLEAUTAPI VarDecFromUI4(ULONG,DECIMAL*);
WINOLEAUTAPI VarDecFromUI8(ULONG64,DECIMAL*);

WINOLEAUTAPI VarI4FromI8(LONG64,LONG*);
WINOLEAUTAPI VarI4FromUI8(ULONG64,LONG*);

WINOLEAUTAPI VarParseNumFromStr(OLECHAR*,LCID,ULONG,NUMPARSE*,BYTE*);
WINOLEAUTAPI VarNumFromParseNum(NUMPARSE*,BYTE*,ULONG,VARIANT*);

WINOLEAUTAPI VarDateFromUdate(UDATE*,ULONG,DATE*);
WINOLEAUTAPI VarDateFromUdateEx(UDATE*,LCID,ULONG,DATE*);
WINOLEAUTAPI VarUdateFromDate(DATE,ULONG,UDATE*);

WINOLEAUTAPI GetAltMonthNames(LCID,LPOLESTR**);

WINOLEAUTAPI VarFormat(LPVARIANT,LPOLESTR,int,int,ULONG,BSTR*);
WINOLEAUTAPI VarFormatDateTime(LPVARIANT,int,ULONG,BSTR*);
WINOLEAUTAPI VarFormatNumber(LPVARIANT,int,int,int,int,ULONG,BSTR*);
WINOLEAUTAPI VarFormatPercent(LPVARIANT,int,int,int,int,ULONG,BSTR*);
WINOLEAUTAPI VarFormatCurrency(LPVARIANT,int,int,int,int,ULONG,BSTR*);
WINOLEAUTAPI VarWeekdayName(int,int,int,ULONG,BSTR*);
WINOLEAUTAPI VarMonthName(int,int,ULONG,BSTR*);
WINOLEAUTAPI VarFormatFromTokens(LPVARIANT,LPOLESTR,LPBYTE,ULONG,BSTR*,LCID);
WINOLEAUTAPI VarTokenizeFormatString(LPOLESTR,LPBYTE,int,int,int,LCID,int*);

WINOLEAUTAPI_(ULONG) LHashValOfNameSysA(SYSKIND,LCID,LPCSTR);
WINOLEAUTAPI_(ULONG) LHashValOfNameSys(SYSKIND,LCID,const OLECHAR*);
WINOLEAUTAPI LoadTypeLib(const OLECHAR*,ITypeLib**);
WINOLEAUTAPI LoadTypeLibEx(LPCOLESTR,REGKIND,ITypeLib**);
WINOLEAUTAPI LoadRegTypeLib(REFGUID,WORD,WORD,LCID,ITypeLib**);
WINOLEAUTAPI QueryPathOfRegTypeLib(REFGUID,USHORT,USHORT,LCID,LPBSTR);
WINOLEAUTAPI RegisterTypeLib(ITypeLib*,OLECHAR*,OLECHAR*);
WINOLEAUTAPI UnRegisterTypeLib(REFGUID,WORD,WORD,LCID,SYSKIND);
WINOLEAUTAPI RegisterTypeLibForUser(ITypeLib*,OLECHAR*,OLECHAR*);

WINOLEAUTAPI UnRegisterTypeLibForUser(REFGUID,WORD,WORD,LCID,SYSKIND);
WINOLEAUTAPI CreateTypeLib(SYSKIND,const OLECHAR*,ICreateTypeLib**);
WINOLEAUTAPI CreateTypeLib2(SYSKIND,LPCOLESTR,ICreateTypeLib2**);

WINOLEAUTAPI DispGetParam(DISPPARAMS*,UINT,VARTYPE,VARIANT*,UINT*);
WINOLEAUTAPI DispGetIDsOfNames(ITypeInfo*,OLECHAR**,UINT,DISPID*);
WINOLEAUTAPI DispInvoke(void*,ITypeInfo*,DISPID,WORD,DISPPARAMS*,VARIANT*,EXCEPINFO*,UINT*);
WINOLEAUTAPI CreateDispTypeInfo(INTERFACEDATA*,LCID,ITypeInfo**);
WINOLEAUTAPI CreateStdDispatch(IUnknown*,void*,ITypeInfo*,IUnknown**);
WINOLEAUTAPI DispCallFunc(void*,ULONG,CALLCONV,VARTYPE,UINT,VARTYPE*,VARIANTARG**,VARIANT*);

WINOLEAUTAPI RegisterActiveObject(IUnknown*,REFCLSID,DWORD,DWORD*);
WINOLEAUTAPI RevokeActiveObject(DWORD,void*);
WINOLEAUTAPI GetActiveObject(REFCLSID,void*,IUnknown**);

WINOLEAUTAPI SetErrorInfo(ULONG,IErrorInfo*);
WINOLEAUTAPI GetErrorInfo(ULONG,IErrorInfo**);
WINOLEAUTAPI CreateErrorInfo(ICreateErrorInfo**);

WINOLEAUTAPI GetRecordInfoFromTypeInfo(ITypeInfo*,IRecordInfo**);
WINOLEAUTAPI GetRecordInfoFromGuids(REFGUID,ULONG,ULONG,LCID,REFGUID,IRecordInfo**);
WINOLEAUTAPI_(ULONG) OaBuildVersion(void);
WINOLEAUTAPI_(void) ClearCustData(LPCUSTDATA);
#if (NTDDI_VERSION >= NTDDI_VISTASP1)
WINOLEAUTAPI_(void) OaEnablePerUserTLibRegistration(void);
#endif /* NTDDI_VERSION >= NTDDI_VISTASP1 */

#include <poppack.h>

#endif /* _OLEAUTO_H */
