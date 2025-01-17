#ifndef _EVNTCONS_H
#define _EVNTCONS_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows event consumer API definitions */

#include <wmistr.h>
#include <evntrace.h>
#include <evntprov.h>

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2197)  /* 'type' is not a standard bit-field type */
#pragma warn(disable:2198)  /* Nameless field is not standard */
#endif

#define EVENT_HEADER_EXT_TYPE_RELATED_ACTIVITYID  0x0001
#define EVENT_HEADER_EXT_TYPE_SID  0x0002
#define EVENT_HEADER_EXT_TYPE_TS_ID  0x0003
#define EVENT_HEADER_EXT_TYPE_INSTANCE_INFO  0x0004
#define EVENT_HEADER_EXT_TYPE_STACK_TRACE32  0x0005
#define EVENT_HEADER_EXT_TYPE_STACK_TRACE64  0x0006
#define EVENT_HEADER_EXT_TYPE_PEBS_INDEX  0x0007
#define EVENT_HEADER_EXT_TYPE_PMC_COUNTERS  0x0008
#define EVENT_HEADER_EXT_TYPE_PSM_KEY  0x0009
#define EVENT_HEADER_EXT_TYPE_EVENT_KEY  0x000A
#define EVENT_HEADER_EXT_TYPE_EVENT_SCHEMA_TL  0x000B
#define EVENT_HEADER_EXT_TYPE_PROV_TRAITS  0x000C
#define EVENT_HEADER_EXT_TYPE_PROCESS_START_KEY  0x000D
#define EVENT_HEADER_EXT_TYPE_MAX  0x000E

#ifndef EVENT_HEADER_EXTENDED_DATA_ITEM_DEF
#define EVENT_HEADER_EXTENDED_DATA_ITEM_DEF
typedef struct _EVENT_HEADER_EXTENDED_DATA_ITEM {
    USHORT Reserved1;
    USHORT ExtType;
    struct {
        USHORT Linkage:1;
        USHORT Reserved2:15;
    };
    USHORT DataSize;
    ULONGLONG DataPtr;
} EVENT_HEADER_EXTENDED_DATA_ITEM, *PEVENT_HEADER_EXTENDED_DATA_ITEM;
#endif /* EVENT_HEADER_EXTENDED_DATA_ITEM_DEF */

typedef struct _EVENT_EXTENDED_ITEM_INSTANCE {
    ULONG InstanceId;
    ULONG ParentInstanceId;
    GUID ParentGuid;
} EVENT_EXTENDED_ITEM_INSTANCE, *PEVENT_EXTENDED_ITEM_INSTANCE;

typedef struct _EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID {
    GUID RelatedActivityId;
} EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID, *PEVENT_EXTENDED_ITEM_RELATED_ACTIVITYID;

typedef struct _EVENT_EXTENDED_ITEM_TS_ID {
    ULONG SessionId;
} EVENT_EXTENDED_ITEM_TS_ID, *PEVENT_EXTENDED_ITEM_TS_ID;

typedef struct _EVENT_EXTENDED_ITEM_STACK_TRACE32 {
    ULONG64 MatchId;
    ULONG Address[ANYSIZE_ARRAY];
} EVENT_EXTENDED_ITEM_STACK_TRACE32, *PEVENT_EXTENDED_ITEM_STACK_TRACE32;

typedef struct _EVENT_EXTENDED_ITEM_STACK_TRACE64 {
    ULONG64 MatchId;
    ULONG64 Address[ANYSIZE_ARRAY];
} EVENT_EXTENDED_ITEM_STACK_TRACE64, *PEVENT_EXTENDED_ITEM_STACK_TRACE64;

typedef struct _EVENT_EXTENDED_ITEM_PEBS_INDEX {
    ULONG64 PebsIndex;
} EVENT_EXTENDED_ITEM_PEBS_INDEX, *PEVENT_EXTENDED_ITEM_PEBS_INDEX;

typedef struct _EVENT_EXTENDED_ITEM_PMC_COUNTERS {
    ULONG64 Counter[ANYSIZE_ARRAY];
} EVENT_EXTENDED_ITEM_PMC_COUNTERS, *PEVENT_EXTENDED_ITEM_PMC_COUNTERS;

typedef struct _EVENT_EXTENDED_ITEM_PROCESS_START_KEY {
    ULONG64 ProcessStartKey;
} EVENT_EXTENDED_ITEM_PROCESS_START_KEY, *PEVENT_EXTENDED_ITEM_PROCESS_START_KEY;

typedef struct _EVENT_EXTENDED_ITEM_EVENT_KEY {
    ULONG64 Key;
} EVENT_EXTENDED_ITEM_EVENT_KEY, *PEVENT_EXTENDED_ITEM_EVENT_KEY;

#define EVENT_HEADER_PROPERTY_XML  0x0001
#define EVENT_HEADER_PROPERTY_FORWARDED_XML  0x0002
#define EVENT_HEADER_PROPERTY_LEGACY_EVENTLOG  0x0004
#define EVENT_HEADER_PROPERTY_RELOGGABLE  0x0008

#define EVENT_HEADER_FLAG_EXTENDED_INFO  0x0001
#define EVENT_HEADER_FLAG_PRIVATE_SESSION  0x0002
#define EVENT_HEADER_FLAG_STRING_ONLY  0x0004
#define EVENT_HEADER_FLAG_TRACE_MESSAGE  0x0008
#define EVENT_HEADER_FLAG_NO_CPUTIME  0x0010
#define EVENT_HEADER_FLAG_32_BIT_HEADER  0x0020
#define EVENT_HEADER_FLAG_64_BIT_HEADER  0x0040
#define EVENT_HEADER_FLAG_CLASSIC_HEADER  0x0100
#define EVENT_HEADER_FLAG_PROCESSOR_INDEX  0x0200

#ifndef EVENT_HEADER_DEF
#define EVENT_HEADER_DEF
typedef struct _EVENT_HEADER {
    USHORT Size;
    USHORT HeaderType;
    USHORT Flags;
    USHORT EventProperty;
    ULONG ThreadId;
    ULONG ProcessId;
    LARGE_INTEGER TimeStamp;
    GUID ProviderId;
    EVENT_DESCRIPTOR EventDescriptor;
    union {
        struct {
            ULONG KernelTime;
            ULONG UserTime;
        } DUMMYSTRUCTNAME;
        ULONG64 ProcessorTime;
    } DUMMYUNIONNAME;
    GUID ActivityId;
} EVENT_HEADER, *PEVENT_HEADER;
#endif /* EVENT_HEADER_DEF */

#ifndef EVENT_RECORD_DEF
#define EVENT_RECORD_DEF
typedef struct _EVENT_RECORD {
    EVENT_HEADER EventHeader;
    ETW_BUFFER_CONTEXT BufferContext;
    USHORT ExtendedDataCount;
    USHORT UserDataLength;
    PEVENT_HEADER_EXTENDED_DATA_ITEM ExtendedData;
    PVOID UserData;
    PVOID UserContext;
} EVENT_RECORD, *PEVENT_RECORD;

typedef const EVENT_RECORD *PCEVENT_RECORD;
#endif /* EVENT_RECORD_DEF */

#define EVENT_ENABLE_PROPERTY_SID  0x00000001
#define EVENT_ENABLE_PROPERTY_TS_ID  0x00000002
#define EVENT_ENABLE_PROPERTY_STACK_TRACE  0x00000004
#define EVENT_ENABLE_PROPERTY_PSM_KEY  0x00000008
#define EVENT_ENABLE_PROPERTY_IGNORE_KEYWORD_0  0x00000010
#define EVENT_ENABLE_PROPERTY_PROVIDER_GROUP  0x00000020
#define EVENT_ENABLE_PROPERTY_ENABLE_KEYWORD_0  0x00000040
#define EVENT_ENABLE_PROPERTY_PROCESS_START_KEY  0x00000080
#define EVENT_ENABLE_PROPERTY_EVENT_KEY  0x00000100
#define EVENT_ENABLE_PROPERTY_EXCLUDE_INPRIVATE  0x00000200

#define PROCESS_TRACE_MODE_REAL_TIME  0x00000100
#define PROCESS_TRACE_MODE_RAW_TIMESTAMP  0x00001000
#define PROCESS_TRACE_MODE_EVENT_RECORD  0x10000000

FORCEINLINE ULONG GetEventProcessorIndex(PCEVENT_RECORD EventRecord) {
    if ((EventRecord->EventHeader.Flags & EVENT_HEADER_FLAG_PROCESSOR_INDEX) != 0) {
        return EventRecord->BufferContext.ProcessorIndex;
    } else {
        return EventRecord->BufferContext.ProcessorNumber;
    }
}

typedef enum {
    EtwProviderTraitTypeGroup = 1,
    EtwProviderTraitTypeMax
} ETW_PROVIDER_TRAIT_TYPE;

/*
inline void EtwGetTraitFromProviderTraits(PVOID ProviderTraits, UCHAR TraitType, PVOID *Trait, PUSHORT Size) {
    const USHORT ByteCount = *(USHORT UNALIGNED *)ProviderTraits;
    PUCHAR Ptr = (PUCHAR)ProviderTraits;
    const UCHAR *PtrEnd = Ptr + ByteCount;

    *Trait = NULL;
    *Size = 0;

    if (ByteCount < 3) {
        return;
    }

    Ptr += 2;

    Ptr += strnlen((PCSTR)Ptr, ByteCount - 3u);
    Ptr += 1;

    while (Ptr < PtrEnd) {
        const USHORT TraitByteCount = *(const USHORT UNALIGNED *)Ptr;
        if (TraitByteCount < 3) {
            return;
        }
        if ((Ptr[2] == TraitType) && 
            (Ptr + TraitByteCount <= PtrEnd)) {

            *Trait = (PVOID)(Ptr + 3);
            *Size = TraitByteCount - 3u;
            return;
        }
        Ptr += TraitByteCount;
    }
}
*/

typedef enum {
    EventSecuritySetDACL,
    EventSecuritySetSACL,
    EventSecurityAddDACL,
    EventSecurityAddSACL,
    EventSecurityMax
} EVENTSECURITYOPERATION;

#if (WINVER >= _WIN32_WINNT_LONGHORN)
ULONG EVNTAPI EventAccessControl(LPGUID,ULONG,PSID,ULONG,BOOLEAN);
ULONG EVNTAPI EventAccessQuery(LPGUID,PSECURITY_DESCRIPTOR,PULONG);
ULONG EVNTAPI EventAccessRemove(LPGUID);
#endif /* WINVER >= _WIN32_WINNT_LONGHORN */

#if __POCC__ >= 290
#pragma warn(pop)
#endif

#endif /* _EVNTCONS_H */
