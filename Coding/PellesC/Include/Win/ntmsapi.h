#ifndef _NTMSAPI_H
#define _NTMSAPI_H

#if __POCC__ >= 500
#pragma once
#endif

/* NTMS API definitions */

#include <pshpack8.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef GUID NTMS_GUID;
typedef GUID *LPNTMS_GUID;

#define NTMS_NULLGUID  {0,0,0,{0,0,0,0,0,0,0,0}}
#define NTMS_IS_NULLGUID(id) ((id.Data1==0)&&(id.Data2==0)&&(id.Data3==0)&&\
    (id.Data4[0]==0)&&(id.Data4[1]==0)&&(id.Data4[2]==0)&&\
    (id.Data4[3]==0)&&(id.Data4[4]==0)&&(id.Data4[5]==0)&&\
    (id.Data4[6]==0)&&(id.Data4[7]==0))

#define NTMS_OBJECTNAME_LENGTH  64
#define NTMS_DESCRIPTION_LENGTH  127
#define NTMS_DEVICENAME_LENGTH  64
#define NTMS_SERIALNUMBER_LENGTH  32
#define NTMS_REVISION_LENGTH  32
#define NTMS_BARCODE_LENGTH  64
#define NTMS_SEQUENCE_LENGTH  32
#define NTMS_VENDORNAME_LENGTH  128
#define NTMS_PRODUCTNAME_LENGTH  128
#define NTMS_USERNAME_LENGTH  64
#define NTMS_APPLICATIONNAME_LENGTH  64
#define NTMS_COMPUTERNAME_LENGTH  64
#define NTMS_I1_MESSAGE_LENGTH  127
#define NTMS_MESSAGE_LENGTH  256
#define NTMS_POOLHIERARCHY_LENGTH  512
#define NTMS_OMIDLABELID_LENGTH  255
#define NTMS_OMIDLABELTYPE_LENGTH  64
#define NTMS_OMIDLABELINFO_LENGTH  256

#define NTMS_OMID_TYPE_RAW_LABEL  0x01
#define NTMS_OMID_TYPE_FILESYSTEM_INFO  0x02

#define NTMS_GENERIC_READ  NTMS_USE_ACCESS
#define NTMS_GENERIC_WRITE  NTMS_USE_ACCESS|NTMS_MODIFY_ACCESS
#define NTMS_GENERIC_EXECUTE NTMS_USE_ACCESS|NTMS_MODIFY_ACCESS|NTMS_CONTROL_ACCESS
#define NTMS_GENERIC_ALL  NTMS_USE_ACCESS|NTMS_MODIFY_ACCESS|NTMS_CONTROL_ACCESS

#define NTMS_MAXATTR_LENGTH  0x10000
#define NTMS_MAXATTR_NAMELEN  32

#ifndef NTMS_NOREDEF
enum NtmsObjectsTypes {
    NTMS_UNKNOWN = 0,
    NTMS_OBJECT,
    NTMS_CHANGER,
    NTMS_CHANGER_TYPE,
    NTMS_COMPUTER,
    NTMS_DRIVE,
    NTMS_DRIVE_TYPE,
    NTMS_IEDOOR,
    NTMS_IEPORT,
    NTMS_LIBRARY,
    NTMS_LIBREQUEST,
    NTMS_LOGICAL_MEDIA,
    NTMS_MEDIA_POOL,
    NTMS_MEDIA_TYPE,
    NTMS_PARTITION,
    NTMS_PHYSICAL_MEDIA,
    NTMS_STORAGESLOT,
    NTMS_OPREQUEST,
    NTMS_NUMBER_OF_OBJECT_TYPES
};

typedef struct _NTMS_ASYNC_IO {
    NTMS_GUID OperationId;
    NTMS_GUID EventId;
    DWORD dwOperationType;
    DWORD dwResult;
    DWORD dwAsyncState;
    HANDLE hEvent;
    BOOL bOnStateChange;
} NTMS_ASYNC_IO, *LPNTMS_ASYNC_IO;

enum NtmsAsyncStatus {
    NTMS_ASYNCSTATE_QUEUED = 0,
    NTMS_ASYNCSTATE_WAIT_RESOURCE,
    NTMS_ASYNCSTATE_WAIT_OPERATOR,
    NTMS_ASYNCSTATE_INPROCESS,
    NTMS_ASYNCSTATE_COMPLETE
};

enum NtmsAsyncOperations {
    NTMS_ASYNCOP_MOUNT = 1
};

enum NtmsMountOptions {
    NTMS_MOUNT_READ = 0x0001,
    NTMS_MOUNT_WRITE = 0x0002,
    NTMS_MOUNT_ERROR_NOT_AVAILABLE = 0x0004,
    NTMS_MOUNT_ERROR_IF_UNAVAILABLE = 0x0004,
    NTMS_MOUNT_ERROR_OFFLINE = 0x0008,
    NTMS_MOUNT_ERROR_IF_OFFLINE = 0x0008,
    NTMS_MOUNT_SPECIFIC_DRIVE = 0x0010,
    NTMS_MOUNT_NOWAIT = 0x0020
};

enum NtmsDismountOptions {
    NTMS_DISMOUNT_DEFERRED = 0x0001
};

enum NtmsMountPriority {
    NTMS_PRIORITY_DEFAULT = 0,
    NTMS_PRIORITY_HIGHEST = 15,
    NTMS_PRIORITY_HIGH = 7,
    NTMS_PRIORITY_NORMAL = 0,
    NTMS_PRIORITY_LOW = -7,
    NTMS_PRIORITY_LOWEST = -15
};

typedef struct _NTMS_MOUNT_INFORMATION {
    DWORD dwSize;
    LPVOID lpReserved;
} NTMS_MOUNT_INFORMATION, *LPNTMS_MOUNT_INFORMATION;

enum NtmsAllocateOptions {
    NTMS_ALLOCATE_NEW = 0x0001,
    NTMS_ALLOCATE_NEXT = 0x0002,
    NTMS_ALLOCATE_ERROR_IF_UNAVAILABLE = 0x0004
};

typedef struct _NTMS_ALLOCATION_INFORMATION {
    DWORD dwSize;
    LPVOID lpReserved;
    NTMS_GUID AllocatedFrom;
} NTMS_ALLOCATION_INFORMATION, *LPNTMS_ALLOCATION_INFORMATION;

enum NtmsCreateOptions {
    NTMS_OPEN_EXISTING = 0x0001,
    NTMS_CREATE_NEW = 0x0002,
    NTMS_OPEN_ALWAYS = 0x0003
};

enum NtmsDriveState {
    NTMS_DRIVESTATE_DISMOUNTED = 0,
    NTMS_DRIVESTATE_MOUNTED = 1,
    NTMS_DRIVESTATE_LOADED = 2,
    NTMS_DRIVESTATE_UNLOADED = 5,
    NTMS_DRIVESTATE_BEING_CLEANED = 6,
    NTMS_DRIVESTATE_DISMOUNTABLE = 7
};

typedef struct _NTMS_DRIVEINFORMATIONA {
    DWORD Number;
    DWORD State;
    NTMS_GUID DriveType;
    CHAR szDeviceName[NTMS_DEVICENAME_LENGTH];
    CHAR szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
    CHAR szRevision[NTMS_REVISION_LENGTH];
    WORD ScsiPort;
    WORD ScsiBus;
    WORD ScsiTarget;
    WORD ScsiLun;
    DWORD dwMountCount;
    SYSTEMTIME LastCleanedTs;
    NTMS_GUID SavedPartitionId;
    NTMS_GUID Library;
    GUID Reserved;
    DWORD dwDeferDismountDelay;
} NTMS_DRIVEINFORMATIONA;

typedef struct _NTMS_DRIVEINFORMATIONW {
    DWORD Number;
    DWORD State;
    NTMS_GUID DriveType;
    WCHAR szDeviceName[NTMS_DEVICENAME_LENGTH];
    WCHAR szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
    WCHAR szRevision[NTMS_REVISION_LENGTH];
    WORD ScsiPort;
    WORD ScsiBus;
    WORD ScsiTarget;
    WORD ScsiLun;
    DWORD dwMountCount;
    SYSTEMTIME LastCleanedTs;
    NTMS_GUID SavedPartitionId;
    NTMS_GUID Library;
    GUID Reserved;
    DWORD dwDeferDismountDelay;
} NTMS_DRIVEINFORMATIONW;

enum NtmsLibraryType {
    NTMS_LIBRARYTYPE_UNKNOWN = 0,
    NTMS_LIBRARYTYPE_OFFLINE = 1,
    NTMS_LIBRARYTYPE_ONLINE = 2,
    NTMS_LIBRARYTYPE_STANDALONE = 3
};

enum NtmsLibraryFlags {
    NTMS_LIBRARYFLAG_FIXEDOFFLINE = 0x01,
    NTMS_LIBRARYFLAG_CLEANERPRESENT = 0x02,
    NTMS_LIBRARYFLAG_AUTODETECTCHANGE = 0x04
};

enum NtmsInventoryMethod {
    NTMS_INVENTORY_NONE = 0,
    NTMS_INVENTORY_FAST = 1,
    NTMS_INVENTORY_OMID = 2,
    NTMS_INVENTORY_DEFAULT = 3,
    NTMS_INVENTORY_SLOT = 4,
    NTMS_INVENTORY_STOP = 5,
    NTMS_INVENTORY_MAX
};

typedef struct _NTMS_LIBRARYINFORMATION {
    DWORD LibraryType;
    NTMS_GUID CleanerSlot;
    NTMS_GUID CleanerSlotDefault;
    BOOL LibrarySupportsDriveCleaning;
    BOOL BarCodeReaderInstalled;
    DWORD InventoryMethod;
    DWORD dwCleanerUsesRemaining;
    DWORD FirstDriveNumber;
    DWORD dwNumberOfDrives;
    DWORD FirstSlotNumber;
    DWORD dwNumberOfSlots;
    DWORD FirstDoorNumber;
    DWORD dwNumberOfDoors;
    DWORD FirstPortNumber;
    DWORD dwNumberOfPorts;
    DWORD FirstChangerNumber;
    DWORD dwNumberOfChangers;
    DWORD dwNumberOfMedia;
    DWORD dwNumberOfMediaTypes;
    DWORD dwNumberOfLibRequests;
    GUID Reserved;
    BOOL AutoRecovery;
    DWORD dwFlags;
} NTMS_LIBRARYINFORMATION;

typedef struct _NTMS_CHANGERINFORMATIONA {
    DWORD Number;
    NTMS_GUID ChangerType;
    CHAR szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
    CHAR szRevision[NTMS_REVISION_LENGTH];
    CHAR szDeviceName[NTMS_DEVICENAME_LENGTH];
    WORD ScsiPort;
    WORD ScsiBus;
    WORD ScsiTarget;
    WORD ScsiLun;
    NTMS_GUID Library;
} NTMS_CHANGERINFORMATIONA;

typedef struct _NTMS_CHANGERINFORMATIONW {
    DWORD Number;
    NTMS_GUID ChangerType;
    WCHAR szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
    WCHAR szRevision[NTMS_REVISION_LENGTH];
    WCHAR szDeviceName[NTMS_DEVICENAME_LENGTH];
    WORD ScsiPort;
    WORD ScsiBus;
    WORD ScsiTarget;
    WORD ScsiLun;
    NTMS_GUID Library;
} NTMS_CHANGERINFORMATIONW;

enum NtmsSlotState {
    NTMS_SLOTSTATE_UNKNOWN = 0,
    NTMS_SLOTSTATE_FULL = 1,
    NTMS_SLOTSTATE_EMPTY = 2,
    NTMS_SLOTSTATE_NOTPRESENT = 3,
    NTMS_SLOTSTATE_NEEDSINVENTORY = 4
};

typedef struct _NTMS_STORAGESLOTINFORMATION {
    DWORD Number;
    DWORD State;
    NTMS_GUID Library;
} NTMS_STORAGESLOTINFORMATION;

enum NtmsDoorState {
    NTMS_DOORSTATE_UNKNOWN = 0,
    NTMS_DOORSTATE_CLOSED = 1,
    NTMS_DOORSTATE_OPEN = 2
};

typedef struct _NTMS_IEDOORINFORMATION {
    DWORD Number;
    DWORD State;
    WORD MaxOpenSecs;
    NTMS_GUID Library;
} NTMS_IEDOORINFORMATION;

enum NtmsPortPosition {
    NTMS_PORTPOSITION_UNKNOWN = 0,
    NTMS_PORTPOSITION_EXTENDED = 1,
    NTMS_PORTPOSITION_RETRACTED = 2
};

enum NtmsPortContent {
    NTMS_PORTCONTENT_UNKNOWN = 0,
    NTMS_PORTCONTENT_FULL = 1,
    NTMS_PORTCONTENT_EMPTY = 2
};

typedef struct _NTMS_IEPORTINFORMATION {
    DWORD Number;
    DWORD Content;
    DWORD Position;
    WORD MaxExtendSecs;
    NTMS_GUID Library;
} NTMS_IEPORTINFORMATION;

enum NtmsBarCodeState {
    NTMS_BARCODESTATE_OK = 1,
    NTMS_BARCODESTATE_UNREADABLE = 2
};

enum NtmsMediaState {
    NTMS_MEDIASTATE_IDLE = 0,
    NTMS_MEDIASTATE_INUSE = 1,
    NTMS_MEDIASTATE_MOUNTED = 2,
    NTMS_MEDIASTATE_LOADED = 3,
    NTMS_MEDIASTATE_UNLOADED = 4,
    NTMS_MEDIASTATE_OPERROR = 5,
    NTMS_MEDIASTATE_OPREQ = 6
};

typedef struct _NTMS_PMIDINFORMATIONA {
    NTMS_GUID CurrentLibrary;
    NTMS_GUID MediaPool;
    NTMS_GUID Location;
    DWORD LocationType;
    NTMS_GUID MediaType;
    NTMS_GUID HomeSlot;
    CHAR szBarCode[NTMS_BARCODE_LENGTH];
    DWORD BarCodeState;
    CHAR szSequenceNumber[NTMS_SEQUENCE_LENGTH];
    DWORD MediaState;
    DWORD dwNumberOfPartitions;
    DWORD dwMediaTypeCode;
    DWORD dwDensityCode;
    NTMS_GUID MountedPartition;
} NTMS_PMIDINFORMATIONA;

typedef struct _NTMS_PMIDINFORMATIONW {
    NTMS_GUID CurrentLibrary;
    NTMS_GUID MediaPool;
    NTMS_GUID Location;
    DWORD LocationType;
    NTMS_GUID MediaType;
    NTMS_GUID HomeSlot;
    WCHAR szBarCode[NTMS_BARCODE_LENGTH];
    DWORD BarCodeState;
    WCHAR szSequenceNumber[NTMS_SEQUENCE_LENGTH];
    DWORD MediaState;
    DWORD dwNumberOfPartitions;
    DWORD dwMediaTypeCode;
    DWORD dwDensityCode;
    NTMS_GUID MountedPartition;
} NTMS_PMIDINFORMATIONW;

typedef struct _NTMS_LMIDINFORMATION {
    NTMS_GUID MediaPool;
    DWORD dwNumberOfPartitions;
} NTMS_LMIDINFORMATION;

enum NtmsPartitionState {
    NTMS_PARTSTATE_UNKNOWN = 0,
    NTMS_PARTSTATE_UNPREPARED = 1,
    NTMS_PARTSTATE_INCOMPATIBLE = 2,
    NTMS_PARTSTATE_DECOMMISSIONED = 3,
    NTMS_PARTSTATE_AVAILABLE = 4,
    NTMS_PARTSTATE_ALLOCATED = 5,
    NTMS_PARTSTATE_COMPLETE = 6,
    NTMS_PARTSTATE_FOREIGN = 7,
    NTMS_PARTSTATE_IMPORT = 8,
    NTMS_PARTSTATE_RESERVED = 9
};

typedef struct _NTMS_PARTITIONINFORMATIONA {
    NTMS_GUID PhysicalMedia;
    NTMS_GUID LogicalMedia;
    DWORD State;
    WORD Side;
    DWORD dwOmidLabelIdLength;
    BYTE OmidLabelId[NTMS_OMIDLABELID_LENGTH];
    CHAR szOmidLabelType[NTMS_OMIDLABELTYPE_LENGTH];
    CHAR szOmidLabelInfo[NTMS_OMIDLABELINFO_LENGTH];
    DWORD dwMountCount;
    DWORD dwAllocateCount;
    LARGE_INTEGER Capacity;
} NTMS_PARTITIONINFORMATIONA;

typedef struct _NTMS_PARTITIONINFORMATIONW {
    NTMS_GUID PhysicalMedia;
    NTMS_GUID LogicalMedia;
    DWORD State;
    WORD Side;
    DWORD dwOmidLabelIdLength;
    BYTE OmidLabelId[NTMS_OMIDLABELID_LENGTH];
    WCHAR szOmidLabelType[NTMS_OMIDLABELTYPE_LENGTH];
    WCHAR szOmidLabelInfo[NTMS_OMIDLABELINFO_LENGTH];
    DWORD dwMountCount;
    DWORD dwAllocateCount;
    LARGE_INTEGER Capacity;
} NTMS_PARTITIONINFORMATIONW;

enum NtmsPoolType {
    NTMS_POOLTYPE_UNKNOWN = 0,
    NTMS_POOLTYPE_SCRATCH = 1,
    NTMS_POOLTYPE_FOREIGN = 2,
    NTMS_POOLTYPE_IMPORT = 3,
    NTMS_POOLTYPE_APPLICATION = 1000
};

enum NtmsAllocationPolicy {
    NTMS_ALLOCATE_FROMSCRATCH = 1
};

enum NtmsDeallocationPolicy {
    NTMS_DEALLOCATE_TOSCRATCH = 1
};

typedef struct _NTMS_MEDIAPOOLINFORMATION {
    DWORD PoolType;
    NTMS_GUID MediaType;
    NTMS_GUID Parent;
    DWORD AllocationPolicy;
    DWORD DeallocationPolicy;
    DWORD dwMaxAllocates;
    DWORD dwNumberOfPhysicalMedia;
    DWORD dwNumberOfLogicalMedia;
    DWORD dwNumberOfMediaPools;
} NTMS_MEDIAPOOLINFORMATION;

enum NtmsReadWriteCharacteristics {
    NTMS_MEDIARW_UNKNOWN = 0,
    NTMS_MEDIARW_REWRITABLE = 1,
    NTMS_MEDIARW_WRITEONCE = 2,
    NTMS_MEDIARW_READONLY = 3
};

typedef struct _NTMS_MEDIATYPEINFORMATION {
    DWORD MediaType;
    DWORD NumberOfSides;
    DWORD ReadWriteCharacteristics;
    DWORD DeviceType;
} NTMS_MEDIATYPEINFORMATION;

typedef struct _NTMS_DRIVETYPEINFORMATIONA {
    CHAR szVendor[NTMS_VENDORNAME_LENGTH];
    CHAR szProduct[NTMS_PRODUCTNAME_LENGTH];
    DWORD NumberOfHeads;
    DWORD DeviceType;
} NTMS_DRIVETYPEINFORMATIONA;

typedef struct _NTMS_DRIVETYPEINFORMATIONW {
    WCHAR szVendor[NTMS_VENDORNAME_LENGTH];
    WCHAR szProduct[NTMS_PRODUCTNAME_LENGTH];
    DWORD NumberOfHeads;
    DWORD DeviceType;
} NTMS_DRIVETYPEINFORMATIONW;

typedef struct _NTMS_CHANGERTYPEINFORMATIONA {
    CHAR szVendor[NTMS_VENDORNAME_LENGTH];
    CHAR szProduct[NTMS_PRODUCTNAME_LENGTH];
    DWORD DeviceType;
} NTMS_CHANGERTYPEINFORMATIONA;

typedef struct _NTMS_CHANGERTYPEINFORMATIONW {
    WCHAR szVendor[NTMS_VENDORNAME_LENGTH];
    WCHAR szProduct[NTMS_PRODUCTNAME_LENGTH];
    DWORD DeviceType;
} NTMS_CHANGERTYPEINFORMATIONW;

enum NtmsLmOperation {
    NTMS_LM_REMOVE = 0,
    NTMS_LM_DISABLECHANGER = 1,
    NTMS_LM_DISABLELIBRARY = 1,
    NTMS_LM_ENABLECHANGER = 2,
    NTMS_LM_ENABLELIBRARY = 2,
    NTMS_LM_DISABLEDRIVE = 3,
    NTMS_LM_ENABLEDRIVE = 4,
    NTMS_LM_DISABLEMEDIA = 5,
    NTMS_LM_ENABLEMEDIA = 6,
    NTMS_LM_UPDATEOMID = 7,
    NTMS_LM_INVENTORY = 8,
    NTMS_LM_DOORACCESS = 9,
    NTMS_LM_EJECT = 10,
    NTMS_LM_EJECTCLEANER = 11,
    NTMS_LM_INJECT = 12,
    NTMS_LM_INJECTCLEANER = 13,
    NTMS_LM_PROCESSOMID = 14,
    NTMS_LM_CLEANDRIVE = 15,
    NTMS_LM_DISMOUNT = 16,
    NTMS_LM_MOUNT = 17,
    NTMS_LM_WRITESCRATCH = 18,
    NTMS_LM_CLASSIFY = 19,
    NTMS_LM_RESERVECLEANER = 20,
    NTMS_LM_RELEASECLEANER = 21,
    NTMS_LM_MAXWORKITEM
};

enum NtmsLmState {
    NTMS_LM_QUEUED = 0,
    NTMS_LM_INPROCESS = 1,
    NTMS_LM_PASSED = 2,
    NTMS_LM_FAILED = 3,
    NTMS_LM_INVALID = 4,
    NTMS_LM_WAITING = 5,
    NTMS_LM_DEFERRED = 6,
    NTMS_LM_CANCELLED = 7,
    NTMS_LM_STOPPED = 8
};

typedef struct _NTMS_LIBREQUESTINFORMATIONA {
    DWORD OperationCode;
    DWORD OperationOption;
    DWORD State;
    NTMS_GUID PartitionId;
    NTMS_GUID DriveId;
    NTMS_GUID PhysMediaId;
    NTMS_GUID Library;
    NTMS_GUID SlotId;
    SYSTEMTIME TimeQueued;
    SYSTEMTIME TimeCompleted;
    CHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    CHAR szUser[NTMS_USERNAME_LENGTH];
    CHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
    DWORD dwErrorCode;
    NTMS_GUID WorkItemId;
    DWORD dwPriority;
} NTMS_LIBREQUESTINFORMATIONA;

typedef struct _NTMS_LIBREQUESTINFORMATIONW {
    DWORD OperationCode;
    DWORD OperationOption;
    DWORD State;
    NTMS_GUID PartitionId;
    NTMS_GUID DriveId;
    NTMS_GUID PhysMediaId;
    NTMS_GUID Library;
    NTMS_GUID SlotId;
    SYSTEMTIME TimeQueued;
    SYSTEMTIME TimeCompleted;
    WCHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    WCHAR szUser[NTMS_USERNAME_LENGTH];
    WCHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
    DWORD dwErrorCode;
    NTMS_GUID WorkItemId;
    DWORD dwPriority;
} NTMS_LIBREQUESTINFORMATIONW;

enum NtmsOpreqCommand {
    NTMS_OPREQ_UNKNOWN = 0,
    NTMS_OPREQ_NEWMEDIA = 1,
    NTMS_OPREQ_CLEANER = 2,
    NTMS_OPREQ_DEVICESERVICE = 3,
    NTMS_OPREQ_MOVEMEDIA = 4,
    NTMS_OPREQ_MESSAGE = 5
};

enum NtmsOpreqState {
    NTMS_OPSTATE_UNKNOWN = 0,
    NTMS_OPSTATE_SUBMITTED = 1,
    NTMS_OPSTATE_ACTIVE = 2,
    NTMS_OPSTATE_INPROGRESS = 3,
    NTMS_OPSTATE_REFUSED = 4,
    NTMS_OPSTATE_COMPLETE = 5
};

typedef struct _NTMS_OPREQUESTINFORMATIONA {
    DWORD Request;
    SYSTEMTIME Submitted;
    DWORD State;
    CHAR szMessage[NTMS_MESSAGE_LENGTH];
    DWORD Arg1Type;
    NTMS_GUID Arg1;
    DWORD Arg2Type;
    NTMS_GUID Arg2;
    CHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    CHAR szUser[NTMS_USERNAME_LENGTH];
    CHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
} NTMS_OPREQUESTINFORMATIONA;

typedef struct _NTMS_OPREQUESTINFORMATIONW {
    DWORD Request;
    SYSTEMTIME Submitted;
    DWORD State;
    WCHAR szMessage[NTMS_MESSAGE_LENGTH];
    DWORD Arg1Type;
    NTMS_GUID Arg1;
    DWORD Arg2Type;
    NTMS_GUID Arg2;
    WCHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    WCHAR szUser[NTMS_USERNAME_LENGTH];
    WCHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
} NTMS_OPREQUESTINFORMATIONW;

typedef struct _NTMS_COMPUTERINFORMATION {
    DWORD dwLibRequestPurgeTime;
    DWORD dwOpRequestPurgeTime;
    DWORD dwLibRequestFlags;
    DWORD dwOpRequestFlags;
    DWORD dwMediaPoolPolicy;
} NTMS_COMPUTERINFORMATION;

enum NtmsLibRequestFlags {
    NTMS_LIBREQFLAGS_NOAUTOPURGE = 0x01,
    NTMS_LIBREQFLAGS_NOFAILEDPURGE = 0x02
};

enum NtmsOpRequestFlags {
    NTMS_OPREQFLAGS_NOAUTOPURGE = 0x01,
    NTMS_OPREQFLAGS_NOFAILEDPURGE = 0x02,
    NTMS_OPREQFLAGS_NOALERTS = 0x10,
    NTMS_OPREQFLAGS_NOTRAYICON = 0x20
};

enum NtmsMediaPoolPolicy {
    NTMS_POOLPOLICY_PURGEOFFLINESCRATCH = 0x01,
    NTMS_POOLPOLICY_KEEPOFFLINEIMPORT = 0x02
};

enum NtmsOperationalState {
    NTMS_READY = 0,
    NTMS_INITIALIZING = 10,
    NTMS_NEEDS_SERVICE = 20,
    NTMS_NOT_PRESENT = 21
};

typedef struct _NTMS_OBJECTINFORMATIONA {
    DWORD dwSize;
    DWORD dwType;
    SYSTEMTIME Created;
    SYSTEMTIME Modified;
    NTMS_GUID ObjectGuid;
    BOOL Enabled;
    DWORD dwOperationalState;
    CHAR szName[NTMS_OBJECTNAME_LENGTH];
    CHAR szDescription[NTMS_DESCRIPTION_LENGTH];
    union {
        NTMS_DRIVEINFORMATIONA Drive;
        NTMS_DRIVETYPEINFORMATIONA DriveType;
        NTMS_LIBRARYINFORMATION Library;
        NTMS_CHANGERINFORMATIONA Changer;
        NTMS_CHANGERTYPEINFORMATIONA ChangerType;
        NTMS_STORAGESLOTINFORMATION StorageSlot;
        NTMS_IEDOORINFORMATION IEDoor;
        NTMS_IEPORTINFORMATION IEPort;
        NTMS_PMIDINFORMATIONA PhysicalMedia;
        NTMS_LMIDINFORMATION LogicalMedia;
        NTMS_PARTITIONINFORMATIONA Partition;
        NTMS_MEDIAPOOLINFORMATION MediaPool;
        NTMS_MEDIATYPEINFORMATION MediaType;
        NTMS_LIBREQUESTINFORMATIONA LibRequest;
        NTMS_OPREQUESTINFORMATIONA OpRequest;
        NTMS_COMPUTERINFORMATION Computer;
    } Info;
} NTMS_OBJECTINFORMATIONA, *LPNTMS_OBJECTINFORMATIONA;

typedef struct _NTMS_OBJECTINFORMATIONW {
    DWORD dwSize;
    DWORD dwType;
    SYSTEMTIME Created;
    SYSTEMTIME Modified;
    NTMS_GUID ObjectGuid;
    BOOL Enabled;
    DWORD dwOperationalState;
    WCHAR szName[NTMS_OBJECTNAME_LENGTH];
    WCHAR szDescription[NTMS_DESCRIPTION_LENGTH];
    union {
        NTMS_DRIVEINFORMATIONW Drive;
        NTMS_DRIVETYPEINFORMATIONW DriveType;
        NTMS_LIBRARYINFORMATION Library;
        NTMS_CHANGERINFORMATIONW Changer;
        NTMS_CHANGERTYPEINFORMATIONW ChangerType;
        NTMS_STORAGESLOTINFORMATION StorageSlot;
        NTMS_IEDOORINFORMATION IEDoor;
        NTMS_IEPORTINFORMATION IEPort;
        NTMS_PMIDINFORMATIONW PhysicalMedia;
        NTMS_LMIDINFORMATION LogicalMedia;
        NTMS_PARTITIONINFORMATIONW Partition;
        NTMS_MEDIAPOOLINFORMATION MediaPool;
        NTMS_MEDIATYPEINFORMATION MediaType;
        NTMS_LIBREQUESTINFORMATIONW LibRequest;
        NTMS_OPREQUESTINFORMATIONW OpRequest;
        NTMS_COMPUTERINFORMATION Computer;
    } Info;
} NTMS_OBJECTINFORMATIONW, *LPNTMS_OBJECTINFORMATIONW;

typedef struct _NTMS_I1_LIBRARYINFORMATION {
    DWORD LibraryType;
    NTMS_GUID CleanerSlot;
    NTMS_GUID CleanerSlotDefault;
    BOOL LibrarySupportsDriveCleaning;
    BOOL BarCodeReaderInstalled;
    DWORD InventoryMethod;
    DWORD dwCleanerUsesRemaining;
    DWORD FirstDriveNumber;
    DWORD dwNumberOfDrives;
    DWORD FirstSlotNumber;
    DWORD dwNumberOfSlots;
    DWORD FirstDoorNumber;
    DWORD dwNumberOfDoors;
    DWORD FirstPortNumber;
    DWORD dwNumberOfPorts;
    DWORD FirstChangerNumber;
    DWORD dwNumberOfChangers;
    DWORD dwNumberOfMedia;
    DWORD dwNumberOfMediaTypes;
    DWORD dwNumberOfLibRequests;
    GUID Reserved;
} NTMS_I1_LIBRARYINFORMATION;

typedef struct _NTMS_I1_LIBREQUESTINFORMATIONA {
    DWORD OperationCode;
    DWORD OperationOption;
    DWORD State;
    NTMS_GUID PartitionId;
    NTMS_GUID DriveId;
    NTMS_GUID PhysMediaId;
    NTMS_GUID Library;
    NTMS_GUID SlotId;
    SYSTEMTIME TimeQueued;
    SYSTEMTIME TimeCompleted;
    CHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    CHAR szUser[NTMS_USERNAME_LENGTH];
    CHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
} NTMS_I1_LIBREQUESTINFORMATIONA;

typedef struct _NTMS_I1_LIBREQUESTINFORMATIONW {
    DWORD OperationCode;
    DWORD OperationOption;
    DWORD State;
    NTMS_GUID PartitionId;
    NTMS_GUID DriveId;
    NTMS_GUID PhysMediaId;
    NTMS_GUID Library;
    NTMS_GUID SlotId;
    SYSTEMTIME TimeQueued;
    SYSTEMTIME TimeCompleted;
    WCHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    WCHAR szUser[NTMS_USERNAME_LENGTH];
    WCHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
} NTMS_I1_LIBREQUESTINFORMATIONW;

typedef struct _NTMS_I1_PMIDINFORMATIONA {
    NTMS_GUID CurrentLibrary;
    NTMS_GUID MediaPool;
    NTMS_GUID Location;
    DWORD LocationType;
    NTMS_GUID MediaType;
    NTMS_GUID HomeSlot;
    CHAR szBarCode[NTMS_BARCODE_LENGTH];
    DWORD BarCodeState;
    CHAR szSequenceNumber[NTMS_SEQUENCE_LENGTH];
    DWORD MediaState;
    DWORD dwNumberOfPartitions;
} NTMS_I1_PMIDINFORMATIONA;

typedef struct _NTMS_I1_PMIDINFORMATIONW {
    NTMS_GUID CurrentLibrary;
    NTMS_GUID MediaPool;
    NTMS_GUID Location;
    DWORD LocationType;
    NTMS_GUID MediaType;
    NTMS_GUID HomeSlot;
    WCHAR szBarCode[NTMS_BARCODE_LENGTH];
    DWORD BarCodeState;
    WCHAR szSequenceNumber[NTMS_SEQUENCE_LENGTH];
    DWORD MediaState;
    DWORD dwNumberOfPartitions;
} NTMS_I1_PMIDINFORMATIONW;

typedef struct _NTMS_I1_PARTITIONINFORMATIONA {
    NTMS_GUID PhysicalMedia;
    NTMS_GUID LogicalMedia;
    DWORD State;
    WORD Side;
    DWORD dwOmidLabelIdLength;
    BYTE OmidLabelId[255];
    CHAR szOmidLabelType[64];
    CHAR szOmidLabelInfo[256];
    DWORD dwMountCount;
    DWORD dwAllocateCount;
} NTMS_I1_PARTITIONINFORMATIONA;

typedef struct _NTMS_I1_PARTITIONINFORMATIONW {
    NTMS_GUID PhysicalMedia;
    NTMS_GUID LogicalMedia;
    DWORD State;
    WORD Side;
    DWORD dwOmidLabelIdLength;
    BYTE OmidLabelId[255];
    WCHAR szOmidLabelType[64];
    WCHAR szOmidLabelInfo[256];
    DWORD dwMountCount;
    DWORD dwAllocateCount;
} NTMS_I1_PARTITIONINFORMATIONW;

typedef struct _NTMS_I1_OPREQUESTINFORMATIONA {
    DWORD Request;
    SYSTEMTIME Submitted;
    DWORD State;
    CHAR szMessage[NTMS_I1_MESSAGE_LENGTH];
    DWORD Arg1Type;
    NTMS_GUID Arg1;
    DWORD Arg2Type;
    NTMS_GUID Arg2;
    CHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    CHAR szUser[NTMS_USERNAME_LENGTH];
    CHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
} NTMS_I1_OPREQUESTINFORMATIONA;

typedef struct _NTMS_I1_OPREQUESTINFORMATIONW {
    DWORD Request;
    SYSTEMTIME Submitted;
    DWORD State;
    WCHAR szMessage[NTMS_I1_MESSAGE_LENGTH];
    DWORD Arg1Type;
    NTMS_GUID Arg1;
    DWORD Arg2Type;
    NTMS_GUID Arg2;
    WCHAR szApplication[NTMS_APPLICATIONNAME_LENGTH];
    WCHAR szUser[NTMS_USERNAME_LENGTH];
    WCHAR szComputer[NTMS_COMPUTERNAME_LENGTH];
} NTMS_I1_OPREQUESTINFORMATIONW;

typedef struct _NTMS_I1_OBJECTINFORMATIONA {
    DWORD dwSize;
    DWORD dwType;
    SYSTEMTIME Created;
    SYSTEMTIME Modified;
    NTMS_GUID ObjectGuid;
    BOOL Enabled;
    DWORD dwOperationalState;
    CHAR szName[NTMS_OBJECTNAME_LENGTH];
    CHAR szDescription[NTMS_DESCRIPTION_LENGTH];
    union {
        NTMS_DRIVEINFORMATIONA Drive;
        NTMS_DRIVETYPEINFORMATIONA DriveType;
        NTMS_I1_LIBRARYINFORMATION Library;
        NTMS_CHANGERINFORMATIONA Changer;
        NTMS_CHANGERTYPEINFORMATIONA ChangerType;
        NTMS_STORAGESLOTINFORMATION StorageSlot;
        NTMS_IEDOORINFORMATION IEDoor;
        NTMS_IEPORTINFORMATION IEPort;
        NTMS_I1_PMIDINFORMATIONA PhysicalMedia;
        NTMS_LMIDINFORMATION LogicalMedia;
        NTMS_I1_PARTITIONINFORMATIONA Partition;
        NTMS_MEDIAPOOLINFORMATION MediaPool;
        NTMS_MEDIATYPEINFORMATION MediaType;
        NTMS_I1_LIBREQUESTINFORMATIONA LibRequest;
        NTMS_I1_OPREQUESTINFORMATIONA OpRequest;
    } Info;
} NTMS_I1_OBJECTINFORMATIONA, *LPNTMS_I1_OBJECTINFORMATIONA;

typedef struct _NTMS_I1_OBJECTINFORMATIONW {
    DWORD dwSize;
    DWORD dwType;
    SYSTEMTIME Created;
    SYSTEMTIME Modified;
    NTMS_GUID ObjectGuid;
    BOOL Enabled;
    DWORD dwOperationalState;
    WCHAR szName[NTMS_OBJECTNAME_LENGTH];
    WCHAR szDescription[NTMS_DESCRIPTION_LENGTH];
    union {
        NTMS_DRIVEINFORMATIONW Drive;
        NTMS_DRIVETYPEINFORMATIONW DriveType;
        NTMS_I1_LIBRARYINFORMATION Library;
        NTMS_CHANGERINFORMATIONW Changer;
        NTMS_CHANGERTYPEINFORMATIONW ChangerType;
        NTMS_STORAGESLOTINFORMATION StorageSlot;
        NTMS_IEDOORINFORMATION IEDoor;
        NTMS_IEPORTINFORMATION IEPort;
        NTMS_I1_PMIDINFORMATIONW PhysicalMedia;
        NTMS_LMIDINFORMATION LogicalMedia;
        NTMS_I1_PARTITIONINFORMATIONW Partition;
        NTMS_MEDIAPOOLINFORMATION MediaPool;
        NTMS_MEDIATYPEINFORMATION MediaType;
        NTMS_I1_LIBREQUESTINFORMATIONW LibRequest;
        NTMS_I1_OPREQUESTINFORMATIONW OpRequest;
    } Info;
} NTMS_I1_OBJECTINFORMATIONW, *LPNTMS_I1_OBJECTINFORMATIONW;

enum NtmsCreateNtmsMediaOptions {
    NTMS_ERROR_ON_DUPLICATE = 0x0001
};

enum NtmsDriveType {
    NTMS_UNKNOWN_DRIVE = 0
};

enum NtmsNotificationOperations {
    NTMS_OBJ_UPDATE = 1,
    NTMS_OBJ_INSERT = 2,
    NTMS_OBJ_DELETE = 3,
    NTMS_EVENT_SIGNAL = 4,
    NTMS_EVENT_COMPLETE = 5
};

typedef struct _NTMS_NOTIFICATIONINFORMATION {
    DWORD dwOperation;
    NTMS_GUID ObjectId;
} NTMS_NOTIFICATIONINFORMATION, *LPNTMS_NOTIFICATIONINFORMATION;

#ifdef UNICODE
#define _NTMS_DRIVEINFORMATION _NTMS_DRIVEINFORMATIONW
#define NTMS_DRIVEINFORMATION NTMS_DRIVEINFORMATIONW
#define _NTMS_CHANGERINFORMATION _NTMS_CHANGERINFORMATIONW
#define NTMS_CHANGERINFORMATION NTMS_CHANGERINFORMATIONW
#define _NTMS_PMIDINFORMATION _NTMS_PMIDINFORMATIONW
#define NTMS_PMIDINFORMATION NTMS_PMIDINFORMATIONW
#define _NTMS_PARTITIONINFORMATION _NTMS_PARTITIONINFORMATIONW
#define NTMS_PARTITIONINFORMATION NTMS_PARTITIONINFORMATIONW
#define _NTMS_DRIVETYPEINFORMATION _NTMS_DRIVETYPEINFORMATIONW
#define NTMS_DRIVETYPEINFORMATION NTMS_DRIVETYPEINFORMATIONW
#define _NTMS_CHANGERTYPEINFORMATION _NTMS_CHANGERTYPEINFORMATIONW
#define NTMS_CHANGERTYPEINFORMATION NTMS_CHANGERTYPEINFORMATIONW
#define _NTMS_LIBREQUESTINFORMATION _NTMS_LIBREQUESTINFORMATIONW
#define NTMS_LIBREQUESTINFORMATION NTMS_LIBREQUESTINFORMATIONW
#define _NTMS_OPREQUESTINFORMATION _NTMS_OPREQUESTINFORMATIONW
#define NTMS_OPREQUESTINFORMATION NTMS_OPREQUESTINFORMATIONW
#define _NTMS_OBJECTINFORMATION _NTMS_OBJECTINFORMATIONW
#define NTMS_OBJECTINFORMATION NTMS_OBJECTINFORMATIONW
#define LPNTMS_OBJECTINFORMATION LPNTMS_OBJECTINFORMATIONW
#define NTMS_I1_LIBREQUESTINFORMATION  NTMS_I1_LIBREQUESTINFORMATIONW
#define NTMS_I1_PARTITIONINFORMATION  NTMS_I1_PARTITIONINFORMATIONW
#define NTMS_I1_PMIDINFORMATION  NTMS_I1_PMIDINFORMATIONW
#define NTMS_I1_OPREQUESTINFORMATION  NTMS_I1_OPREQUESTINFORMATIONW
#define NTMS_I1_OBJECTINFORMATION  NTMS_I1_OBJECTINFORMATIONW
#define OpenNtmsSession OpenNtmsSessionW
#define GetNtmsDeviceName GetNtmsDeviceNameW
#define GetNtmsObjectInformation GetNtmsObjectInformationW
#define SetNtmsObjectInformation SetNtmsObjectInformationW
#define CreateNtmsMediaPool CreateNtmsMediaPoolW
#define GetNtmsMediaPoolName GetNtmsMediaPoolNameW
#define GetNtmsObjectAttribute GetNtmsObjectAttributeW
#define SetNtmsObjectAttribute SetNtmsObjectAttributeW
#define SubmitNtmsOperatorRequest SubmitNtmsOperatorRequestW
#define CreateNtmsMedia CreateNtmsMediaW
#define EjectDiskFromSADrive EjectDiskFromSADriveW
#else
#define _NTMS_DRIVEINFORMATION _NTMS_DRIVEINFORMATIONA
#define NTMS_DRIVEINFORMATION NTMS_DRIVEINFORMATIONA
#define _NTMS_CHANGERINFORMATION _NTMS_CHANGERINFORMATIONA
#define NTMS_CHANGERINFORMATION NTMS_CHANGERINFORMATIONA
#define _NTMS_PMIDINFORMATION _NTMS_PMIDINFORMATIONA
#define NTMS_PMIDINFORMATION NTMS_PMIDINFORMATIONA
#define _NTMS_PARTITIONINFORMATION _NTMS_PARTITIONINFORMATIONA
#define NTMS_PARTITIONINFORMATION NTMS_PARTITIONINFORMATIONA
#define _NTMS_DRIVETYPEINFORMATION _NTMS_DRIVETYPEINFORMATIONA
#define NTMS_DRIVETYPEINFORMATION NTMS_DRIVETYPEINFORMATIONA
#define _NTMS_CHANGERTYPEINFORMATION _NTMS_CHANGERTYPEINFORMATIONA
#define NTMS_CHANGERTYPEINFORMATION NTMS_CHANGERTYPEINFORMATIONA
#define _NTMS_LIBREQUESTINFORMATION _NTMS_LIBREQUESTINFORMATIONA
#define NTMS_LIBREQUESTINFORMATION NTMS_LIBREQUESTINFORMATIONA
#define _NTMS_OPREQUESTINFORMATION _NTMS_OPREQUESTINFORMATIONA
#define NTMS_OPREQUESTINFORMATION NTMS_OPREQUESTINFORMATIONA
#define _NTMS_OBJECTINFORMATION _NTMS_OBJECTINFORMATIONA
#define NTMS_OBJECTINFORMATION NTMS_OBJECTINFORMATIONA
#define LPNTMS_OBJECTINFORMATION LPNTMS_OBJECTINFORMATIONA
#define NTMS_I1_LIBREQUESTINFORMATION  NTMS_I1_LIBREQUESTINFORMATIONA
#define NTMS_I1_PARTITIONINFORMATION  NTMS_I1_PARTITIONINFORMATIONA
#define NTMS_I1_PMIDINFORMATION  NTMS_I1_PMIDINFORMATIONA
#define NTMS_I1_OPREQUESTINFORMATION  NTMS_I1_OPREQUESTINFORMATIONA
#define NTMS_I1_OBJECTINFORMATION  NTMS_I1_OBJECTINFORMATIONA
#define OpenNtmsSession OpenNtmsSessionA
#define GetNtmsDeviceName GetNtmsDeviceNameA
#define GetNtmsObjectInformation GetNtmsObjectInformationA
#define SetNtmsObjectInformation SetNtmsObjectInformationA
#define CreateNtmsMediaPool CreateNtmsMediaPoolA
#define GetNtmsMediaPoolName GetNtmsMediaPoolNameA
#define GetNtmsObjectAttribute GetNtmsObjectAttributeA
#define SetNtmsObjectAttribute SetNtmsObjectAttributeA
#define SubmitNtmsOperatorRequest SubmitNtmsOperatorRequestA
#define CreateNtmsMedia CreateNtmsMediaA
#define EjectDiskFromSADrive EjectDiskFromSADriveA
#endif /* UNICODE */

#define NTMS_PARTSTATE_NEW NTMS_PARTSTATE_UNKNOWN
#endif /* NTMS_NOREDEF */

enum NtmsSessionOptions {
    NTMS_SESSION_QUERYEXPEDITE = 0x1
};

enum NtmsEjectOperation {
    NTMS_EJECT_START = 0,
    NTMS_EJECT_STOP = 1,
    NTMS_EJECT_QUEUE = 2,
    NTMS_EJECT_FORCE = 3,
    NTMS_EJECT_IMMEDIATE = 4,
    NTMS_EJECT_ASK_USER = 5
};

enum NtmsInjectOperation {
    NTMS_INJECT_START = 0,
    NTMS_INJECT_STOP = 1,
    NTMS_INJECT_RETRACT = 2,
    NTMS_INJECT_STARTMANY = 3
};

typedef struct {
    WCHAR FileSystemType[64];
    WCHAR VolumeName[256];
    DWORD SerialNumber;
} NTMS_FILESYSTEM_INFO;

enum NtmsAccessMask {
    NTMS_USE_ACCESS = 0x1,
    NTMS_MODIFY_ACCESS = 0x2,
    NTMS_CONTROL_ACCESS = 0x4
};

HANDLE WINAPI OpenNtmsSessionW(LPCWSTR,LPCWSTR,DWORD);
HANDLE WINAPI OpenNtmsSessionA(LPCSTR,LPCSTR,DWORD);
DWORD WINAPI CloseNtmsSession(HANDLE);
DWORD WINAPI MountNtmsMedia(HANDLE,LPNTMS_GUID,LPNTMS_GUID,DWORD,DWORD,int,DWORD,LPNTMS_MOUNT_INFORMATION);
DWORD WINAPI DismountNtmsMedia(HANDLE,LPNTMS_GUID,DWORD,DWORD);
DWORD WINAPI AllocateNtmsMedia(HANDLE,LPNTMS_GUID,LPNTMS_GUID,LPNTMS_GUID,DWORD,DWORD,LPNTMS_ALLOCATION_INFORMATION);
DWORD WINAPI DeallocateNtmsMedia(HANDLE,LPNTMS_GUID,DWORD);
DWORD WINAPI SwapNtmsMedia(HANDLE,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI AddNtmsMediaType(HANDLE,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI DeleteNtmsMediaType(HANDLE,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI ChangeNtmsMediaType(HANDLE,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI DecommissionNtmsMedia(HANDLE,LPNTMS_GUID);
DWORD WINAPI SetNtmsMediaComplete(HANDLE,LPNTMS_GUID);
DWORD WINAPI DeleteNtmsMedia(HANDLE,LPNTMS_GUID);
DWORD WINAPI CreateNtmsMediaPoolA(HANDLE,LPCSTR,LPNTMS_GUID,DWORD,LPSECURITY_ATTRIBUTES,LPNTMS_GUID);
DWORD WINAPI CreateNtmsMediaPoolW(HANDLE,LPCWSTR,LPNTMS_GUID,DWORD,LPSECURITY_ATTRIBUTES,LPNTMS_GUID);
DWORD WINAPI GetNtmsMediaPoolNameA(HANDLE,LPNTMS_GUID,LPSTR,LPDWORD);
DWORD WINAPI GetNtmsMediaPoolNameW(HANDLE,LPNTMS_GUID,LPWSTR,LPDWORD);
DWORD WINAPI MoveToNtmsMediaPool(HANDLE,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI DeleteNtmsMediaPool(HANDLE,LPNTMS_GUID);
DWORD WINAPI DeleteNtmsLibrary(HANDLE,LPNTMS_GUID);
DWORD WINAPI DeleteNtmsDrive(HANDLE,LPNTMS_GUID);
DWORD WINAPI GetNtmsObjectInformationA(HANDLE,LPNTMS_GUID,LPNTMS_OBJECTINFORMATIONA);
DWORD WINAPI GetNtmsObjectInformationW(HANDLE,LPNTMS_GUID,LPNTMS_OBJECTINFORMATIONW);
DWORD WINAPI SetNtmsObjectInformationA(HANDLE,LPNTMS_GUID,LPNTMS_OBJECTINFORMATIONA);
DWORD WINAPI SetNtmsObjectInformationW(HANDLE,LPNTMS_GUID,LPNTMS_OBJECTINFORMATIONW);
DWORD WINAPI CreateNtmsMediaA(HANDLE,LPNTMS_OBJECTINFORMATIONA,LPNTMS_OBJECTINFORMATIONA,DWORD);
DWORD WINAPI CreateNtmsMediaW(HANDLE,LPNTMS_OBJECTINFORMATIONW,LPNTMS_OBJECTINFORMATIONW,DWORD);
DWORD WINAPI EnumerateNtmsObject(HANDLE,const LPNTMS_GUID,LPNTMS_GUID,LPDWORD,DWORD,DWORD);
DWORD WINAPI DisableNtmsObject(HANDLE,DWORD,LPNTMS_GUID);
DWORD WINAPI EnableNtmsObject(HANDLE,DWORD,LPNTMS_GUID);
DWORD WINAPI EjectNtmsMedia(HANDLE,LPNTMS_GUID,LPNTMS_GUID,DWORD);
DWORD WINAPI InjectNtmsMedia(HANDLE,LPNTMS_GUID,LPNTMS_GUID,DWORD);
DWORD WINAPI AccessNtmsLibraryDoor(HANDLE,LPNTMS_GUID,DWORD);
DWORD WINAPI CleanNtmsDrive(HANDLE,LPNTMS_GUID);
DWORD WINAPI DismountNtmsDrive(HANDLE,LPNTMS_GUID);
DWORD WINAPI InventoryNtmsLibrary(HANDLE,LPNTMS_GUID,DWORD);
DWORD WINAPI UpdateNtmsOmidInfo(HANDLE,LPNTMS_GUID,DWORD,DWORD,LPVOID);
DWORD WINAPI CancelNtmsLibraryRequest(HANDLE,LPNTMS_GUID);
DWORD WINAPI GetNtmsRequestOrder(HANDLE,LPNTMS_GUID,LPDWORD);
DWORD WINAPI SetNtmsRequestOrder(HANDLE,LPNTMS_GUID,DWORD);
DWORD WINAPI DeleteNtmsRequests(HANDLE,LPNTMS_GUID,DWORD,DWORD);
DWORD WINAPI ReserveNtmsCleanerSlot(HANDLE,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI ReleaseNtmsCleanerSlot(HANDLE,LPNTMS_GUID);
DWORD WINAPI InjectNtmsCleaner(HANDLE,LPNTMS_GUID,LPNTMS_GUID,DWORD,DWORD);
DWORD WINAPI EjectNtmsCleaner(HANDLE,LPNTMS_GUID,LPNTMS_GUID,DWORD);
DWORD WINAPI BeginNtmsDeviceChangeDetection(HANDLE,LPHANDLE);
DWORD WINAPI SetNtmsDeviceChangeDetection(HANDLE,HANDLE,LPNTMS_GUID,DWORD,DWORD);
DWORD WINAPI EndNtmsDeviceChangeDetection(HANDLE,HANDLE);
DWORD WINAPI GetNtmsObjectSecurity(HANDLE,LPNTMS_GUID,DWORD,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,LPDWORD);
DWORD WINAPI SetNtmsObjectSecurity(HANDLE,LPNTMS_GUID,DWORD,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
DWORD WINAPI GetNtmsObjectAttributeA(HANDLE,LPNTMS_GUID,DWORD,LPCSTR,LPVOID,LPDWORD);
DWORD WINAPI GetNtmsObjectAttributeW(HANDLE,LPNTMS_GUID,DWORD,LPCWSTR,LPVOID,LPDWORD);
DWORD WINAPI SetNtmsObjectAttributeA(HANDLE,LPNTMS_GUID,DWORD,LPCSTR,LPVOID,DWORD);
DWORD WINAPI SetNtmsObjectAttributeW(HANDLE,LPNTMS_GUID,DWORD,LPCWSTR,LPVOID,DWORD);
DWORD WINAPI SubmitNtmsOperatorRequestW(HANDLE,DWORD,LPCWSTR,LPNTMS_GUID,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI SubmitNtmsOperatorRequestA(HANDLE,DWORD,LPCSTR,LPNTMS_GUID,LPNTMS_GUID,LPNTMS_GUID);
DWORD WINAPI WaitForNtmsOperatorRequest(HANDLE,LPNTMS_GUID,DWORD);
DWORD WINAPI CancelNtmsOperatorRequest(HANDLE,LPNTMS_GUID);
DWORD WINAPI SatisfyNtmsOperatorRequest(HANDLE,LPNTMS_GUID);
DWORD WINAPI ImportNtmsDatabase(HANDLE);
DWORD WINAPI ExportNtmsDatabase(HANDLE);
DWORD WINAPI ImportNtmsDatabase(HANDLE);
DWORD WINAPI ExportNtmsDatabase(HANDLE);
HANDLE WINAPI OpenNtmsNotification(HANDLE,DWORD);
DWORD WINAPI WaitForNtmsNotification(HANDLE,LPNTMS_NOTIFICATIONINFORMATION,DWORD);
DWORD WINAPI CloseNtmsNotification(HANDLE);
DWORD WINAPI EjectDiskFromSADriveW(LPCWSTR,LPCWSTR,LPCWSTR,HWND,LPCWSTR,LPCWSTR,DWORD);
DWORD WINAPI EjectDiskFromSADriveA(LPCSTR,LPCSTR,LPCSTR,HWND,LPCSTR,LPCSTR,DWORD);
#ifdef PRE_SEVIL
DWORD WINAPI CreateNtmsMediaPool(HANDLE,LPCTSTR,LPNTMS_GUID,DWORD,LPSECURITY_ATTRIBUTES,LPNTMS_GUID);
DWORD WINAPI GetNtmsObjectInformation(HANDLE,LPNTMS_GUID,LPNTMS_OBJECTINFORMATION);
DWORD WINAPI SetNtmsObjectInformation(HANDLE,LPNTMS_GUID,LPNTMS_OBJECTINFORMATION);
#endif

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif /* _NTMSAPI_H */
