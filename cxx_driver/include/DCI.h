#ifdef __cplusplus
extern "C" {
#endif

#ifndef _DCI_H
#define _DCI_H

#include "DCI1.h"

#ifndef DCI_EXPORT
#ifndef OCI_EXPORT
#define OCI_EXPORT
#endif
#endif

#ifdef WIN32
#define DCI_API   __declspec( dllexport )
#else
#define DCI_API
#endif

#if defined(OCI_EXPORT) || defined(OCI_DEFINE)

typedef dub1                ub1;
typedef dsb1                sb1;

typedef dub2                ub2;
typedef dsb2                sb2;

typedef dub4                ub4;
typedef dsb4                sb4;

typedef dmtext              oratext;

typedef deb1                eb1;
typedef deb2                eb2;
typedef deb4                eb4;

typedef db1                 b1;
typedef db2                 b2;
typedef db4                 b4;

#if !defined(LUSEMFC)
typedef dtext               text;
#endif

typedef dmtext              OraText;

typedef deword              eword;
typedef duword              uword;
typedef dsword              sword;

typedef dubig_ora           ubig_ora;
typedef dsbig_ora           sbig_ora;

typedef dmub8               oraub8;
typedef dmsb8               orasb8;
typedef dub8                ub8;
typedef dsb8                sb8;

typedef dlgenfp_t           lgenfp_t;

#if !defined(MOTIF) && !defined(LISPL) && !defined(__cplusplus) && !defined(LUSEMFC)
typedef dstring             string;
#endif

typedef dutext              utext;

#define OCI_TYPECODE_REF                DCI_TYPECODE_REF
#define OCI_TYPECODE_DATE               DCI_TYPECODE_DATE
#define OCI_TYPECODE_SIGNED8            DCI_TYPECODE_SIGNED8
#define OCI_TYPECODE_SIGNED16           DCI_TYPECODE_SIGNED16
#define OCI_TYPECODE_SIGNED32           DCI_TYPECODE_SIGNED32
#define OCI_TYPECODE_REAL               DCI_TYPECODE_REAL
#define OCI_TYPECODE_DOUBLE             DCI_TYPECODE_DOUBLE
#define OCI_TYPECODE_FLOAT              DCI_TYPECODE_FLOAT
#define OCI_TYPECODE_NUMBER             DCI_TYPECODE_NUMBER
#define OCI_TYPECODE_DECIMAL            DCI_TYPECODE_DECIMAL
#define OCI_TYPECODE_UNSIGNED8          DCI_TYPECODE_UNSIGNED8
#define OCI_TYPECODE_UNSIGNED16         DCI_TYPECODE_UNSIGNED16
#define OCI_TYPECODE_UNSIGNED32         DCI_TYPECODE_UNSIGNED32
#define OCI_TYPECODE_BFLOAT             DCI_TYPECODE_BFLOAT
#define OCI_TYPECODE_BDOUBLE            DCI_TYPECODE_BDOUBLE
#define OCI_TYPECODE_OCTET              DCI_TYPECODE_OCTET
#define OCI_TYPECODE_SMALLINT           DCI_TYPECODE_SMALLINT
#define OCI_TYPECODE_INTEGER            DCI_TYPECODE_INTEGER
#define OCI_TYPECODE_RAW                DCI_TYPECODE_RAW
#define OCI_TYPECODE_PTR                DCI_TYPECODE_PTR
#define OCI_TYPECODE_VARCHAR2           DCI_TYPECODE_VARCHAR2
#define OCI_TYPECODE_CHAR               DCI_TYPECODE_CHAR
#define OCI_TYPECODE_VARCHAR            DCI_TYPECODE_VARCHAR
#define OCI_TYPECODE_MLSLABEL           DCI_TYPECODE_MLSLABEL
#define OCI_TYPECODE_VARRAY             DCI_TYPECODE_VARRAY
#define OCI_TYPECODE_TABLE              DCI_TYPECODE_TABLE
#define OCI_TYPECODE_OBJECT             DCI_TYPECODE_OBJECT
#define OCI_TYPECODE_OPAQUE             DCI_TYPECODE_OPAQUE
#define OCI_TYPECODE_NAMEDCOLLECTION    DCI_TYPECODE_NAMEDCOLLECTION
#define OCI_TYPECODE_BLOB               DCI_TYPECODE_BLOB
#define OCI_TYPECODE_BFILE              DCI_TYPECODE_BFILE
#define OCI_TYPECODE_CLOB               DCI_TYPECODE_CLOB
#define OCI_TYPECODE_CFILE              DCI_TYPECODE_CFILE
#define OCI_TYPECODE_TIME               DCI_TYPECODE_TIME
#define OCI_TYPECODE_TIME_TZ            DCI_TYPECODE_TIME_TZ
#define OCI_TYPECODE_TIMESTAMP          DCI_TYPECODE_TIMESTAMP
#define OCI_TYPECODE_TIMESTAMP_TZ       DCI_TYPECODE_TIMESTAMP_TZ
#define OCI_TYPECODE_TIMESTAMP_LTZ      DCI_TYPECODE_TIMESTAMP_LTZ
#define OCI_TYPECODE_INTERVAL_YM        DCI_TYPECODE_INTERVAL_YM
#define OCI_TYPECODE_INTERVAL_DS        DCI_TYPECODE_INTERVAL_DS
#define OCI_TYPECODE_OTMFIRST           DCI_TYPECODE_OTMFIRST
#define OCI_TYPECODE_OTMLAST            DCI_TYPECODE_OTMLAST
#define OCI_TYPECODE_SYSFIRST           DCI_TYPECODE_SYSFIRST
#define OCI_TYPECODE_SYSLAST            DCI_TYPECODE_SYSLAST
#define OCI_TYPECODE_PLS_INTEGER        DCI_TYPECODE_PLS_INTEGER
#define OCI_TYPECODE_NCHAR              DCI_TYPECODE_NCHAR
#define OCI_TYPECODE_NVARCHAR2          DCI_TYPECODE_NVARCHAR2
#define OCI_TYPECODE_NCLOB              DCI_TYPECODE_NCLOB

#define OCI_NUMBER_UNSIGNED             DCI_NUMBER_UNSIGNED         /* Unsigned type -- ubX */
#define OCI_NUMBER_SIGNED               DCI_NUMBER_SIGNED           /* Signed type -- sbX */

#define OCI_HTYPE_FIRST                 DCI_HTYPE_FIRST
#define OCI_HTYPE_ENV                   DCI_HTYPE_ENV
#define OCI_HTYPE_ERROR                 DCI_HTYPE_ERROR
#define OCI_HTYPE_SVCCTX                DCI_HTYPE_SVCCTX
#define OCI_HTYPE_STMT                  DCI_HTYPE_STMT
#define OCI_HTYPE_BIND                  DCI_HTYPE_BIND
#define OCI_HTYPE_DEFINE                DCI_HTYPE_DEFINE
#define OCI_HTYPE_DESCRIBE              DCI_HTYPE_DESCRIBE
#define OCI_HTYPE_SERVER                DCI_HTYPE_SERVER
#define OCI_HTYPE_SESSION               DCI_HTYPE_SESSION
#define OCI_HTYPE_AUTHINFO              DCI_HTYPE_AUTHINFO
#define OCI_HTYPE_TRANS                 DCI_HTYPE_TRANS
#define OCI_HTYPE_COMPLEXOBJECT         DCI_HTYPE_COMPLEXOBJECT
#define OCI_HTYPE_SECURITY              DCI_HTYPE_SECURITY
#define OCI_HTYPE_SUBSCRIPTION          DCI_HTYPE_SUBSCRIPTION
#define OCI_HTYPE_DIRPATH_CTX           DCI_HTYPE_DIRPATH_CTX
#define OCI_HTYPE_DIRPATH_COLUMN_ARRAY  DCI_HTYPE_DIRPATH_COLUMN_ARRAY
#define OCI_HTYPE_DIRPATH_STREAM        DCI_HTYPE_DIRPATH_STREAM
#define OCI_HTYPE_PROC                  DCI_HTYPE_PROC
#define OCI_HTYPE_DIRPATH_FN_CTX        DCI_HTYPE_DIRPATH_FN_CTX
#define OCI_HTYPE_DIRPATH_FN_COL_ARRAY  DCI_HTYPE_DIRPATH_FN_COL_ARRAY
#define OCI_HTYPE_XADSESSION            DCI_HTYPE_XADSESSION
#define OCI_HTYPE_XADTABLE              DCI_HTYPE_XADTABLE
#define OCI_HTYPE_XADFIELD              DCI_HTYPE_XADFIELD
#define OCI_HTYPE_XADGRANULE            DCI_HTYPE_XADGRANULE
#define OCI_HTYPE_XADRECORD             DCI_HTYPE_XADRECORD
#define OCI_HTYPE_XADIO                 DCI_HTYPE_XADIO
#define OCI_HTYPE_CPOOL                 DCI_HTYPE_CPOOL
#define OCI_HTYPE_SPOOL                 DCI_HTYPE_SPOOL
#define OCI_HTYPE_ADMIN                 DCI_HTYPE_ADMIN
#define OCI_HTYPE_LAST                  DCI_HTYPE_LAST

#define OCI_DTYPE_FIRST                 DCI_DTYPE_FIRST
#define OCI_DTYPE_LOB                   DCI_DTYPE_LOB
#define OCI_DTYPE_SNAP                  DCI_DTYPE_SNAP
#define OCI_DTYPE_RSET                  DCI_DTYPE_RSET
#define OCI_DTYPE_PARAM                 DCI_DTYPE_PARAM
#define OCI_DTYPE_ROWID                 DCI_DTYPE_ROWID
#define OCI_DTYPE_COMPLEXOBJECTCOMP     DCI_DTYPE_COMPLEXOBJECTCOMP
#define OCI_DTYPE_FILE                  DCI_DTYPE_FILE
#define OCI_DTYPE_AQENQ_OPTIONS         DCI_DTYPE_AQENQ_OPTIONS
#define OCI_DTYPE_AQDEQ_OPTIONS         DCI_DTYPE_AQDEQ_OPTIONS
#define OCI_DTYPE_AQMSG_PROPERTIES      DCI_DTYPE_AQMSG_PROPERTIES
#define OCI_DTYPE_AQAGENT               DCI_DTYPE_AQAGENT
#define OCI_DTYPE_LOCATOR               DCI_DTYPE_LOCATOR
#define OCI_DTYPE_INTERVAL_YM           DCI_DTYPE_INTERVAL_YM
#define OCI_DTYPE_INTERVAL_DS           DCI_DTYPE_INTERVAL_DS
#define OCI_DTYPE_AQNFY_DESCRIPTOR      DCI_DTYPE_AQNFY_DESCRIPTOR
#define OCI_DTYPE_DATE                  DCI_DTYPE_DATE
#define OCI_DTYPE_TIME                  DCI_DTYPE_TIME
#define OCI_DTYPE_TIME_TZ               DCI_DTYPE_TIME_TZ
#define OCI_DTYPE_TIMESTAMP             DCI_DTYPE_TIMESTAMP
#define OCI_DTYPE_TIMESTAMP_TZ          DCI_DTYPE_TIMESTAMP_TZ
#define OCI_DTYPE_TIMESTAMP_LTZ         DCI_DTYPE_TIMESTAMP_LTZ
#define OCI_DTYPE_UCB                   DCI_DTYPE_UCB
#define OCI_DTYPE_SRVDN                 DCI_DTYPE_SRVDN
#define OCI_DTYPE_SIGNATURE             DCI_DTYPE_SIGNATURE
#define OCI_DTYPE_RESERVED_1            DCI_DTYPE_RESERVED_1
#define OCI_DTYPE_LAST                  DCI_DTYPE_LAST

#define OCI_TEMP_BLOB                   DCI_TEMP_BLOB
#define OCI_TEMP_CLOB                   DCI_TEMP_CLOB

#define OCI_OTYPE_NAME                  DCI_OTYPE_NAME
#define OCI_OTYPE_REF                   DCI_OTYPE_REF
#define OCI_OTYPE_PTR                   DCI_OTYPE_PTR

#define OCI_ATTR_FNCODE                         DCI_ATTR_FNCODE
#define OCI_ATTR_OBJECT                         DCI_ATTR_OBJECT
#define OCI_ATTR_NONBLOCKING_MODE               DCI_ATTR_NONBLOCKING_MODE
#define OCI_ATTR_SQLCODE                        DCI_ATTR_SQLCODE
#define OCI_ATTR_ENV                            DCI_ATTR_ENV
#define OCI_ATTR_SERVER                         DCI_ATTR_SERVER
#define OCI_ATTR_SESSION                        DCI_ATTR_SESSION
#define OCI_ATTR_TRANS                          DCI_ATTR_TRANS
#define OCI_ATTR_ROW_COUNT                      DCI_ATTR_ROW_COUNT
#define OCI_ATTR_SQLFNCODE                      DCI_ATTR_SQLFNCODE
#define OCI_ATTR_PREFETCH_ROWS                  DCI_ATTR_PREFETCH_ROWS
#define OCI_ATTR_NESTED_PREFETCH_ROWS           DCI_ATTR_NESTED_PREFETCH_ROWS
#define OCI_ATTR_PREFETCH_MEMORY                DCI_ATTR_PREFETCH_MEMORY
#define OCI_ATTR_NESTED_PREFETCH_MEMORY         DCI_ATTR_NESTED_PREFETCH_MEMORY
#define OCI_ATTR_CHAR_COUNT                     DCI_ATTR_CHAR_COUNT
#define OCI_ATTR_PDSCL                          DCI_ATTR_PDSCL
#define OCI_ATTR_FSPRECISION                    DCI_ATTR_FSPRECISION
#define OCI_ATTR_PDPRC                          DCI_ATTR_PDPRC
#define OCI_ATTR_LFPRECISION                    DCI_ATTR_LFPRECISION
#define OCI_ATTR_PARAM_COUNT                    DCI_ATTR_PARAM_COUNT
#define OCI_ATTR_ROWID                          DCI_ATTR_ROWID
#define OCI_ATTR_CHARSET                        DCI_ATTR_CHARSET
#define OCI_ATTR_NCHAR                          DCI_ATTR_NCHAR
#define OCI_ATTR_USERNAME                       DCI_ATTR_USERNAME
#define OCI_ATTR_PASSWORD                       DCI_ATTR_PASSWORD
#define OCI_ATTR_STMT_TYPE                      DCI_ATTR_STMT_TYPE
#define OCI_ATTR_INTERNAL_NAME                  DCI_ATTR_INTERNAL_NAME
#define OCI_ATTR_EXTERNAL_NAME                  DCI_ATTR_EXTERNAL_NAME
#define OCI_ATTR_XID                            DCI_ATTR_XID
#define OCI_ATTR_TRANS_LOCK                     DCI_ATTR_TRANS_LOCK
#define OCI_ATTR_TRANS_NAME                     DCI_ATTR_TRANS_NAME
#define OCI_ATTR_HEAPALLOC                      DCI_ATTR_HEAPALLOC
#define OCI_ATTR_CHARSET_ID                     DCI_ATTR_CHARSET_ID
#define OCI_ATTR_CHARSET_FORM                   DCI_ATTR_CHARSET_FORM
#define OCI_ATTR_MAXDATA_SIZE                   DCI_ATTR_MAXDATA_SIZE
#define OCI_ATTR_CACHE_OPT_SIZE                 DCI_ATTR_CACHE_OPT_SIZE
#define OCI_ATTR_CACHE_MAX_SIZE                 DCI_ATTR_CACHE_MAX_SIZE
#define OCI_ATTR_PINOPTION                      DCI_ATTR_PINOPTION
#define OCI_ATTR_ALLOC_DURATION                 DCI_ATTR_ALLOC_DURATION
#define OCI_ATTR_PIN_DURATION                   DCI_ATTR_PIN_DURATION
#define OCI_ATTR_FDO                            DCI_ATTR_FDO
#define OCI_ATTR_POSTPROCESSING_CALLBACK        DCI_ATTR_POSTPROCESSING_CALLBACK
#define OCI_ATTR_POSTPROCESSING_CONTEXT         DCI_ATTR_POSTPROCESSING_CONTEXT
#define OCI_ATTR_ROWS_RETURNED                  DCI_ATTR_ROWS_RETURNED
#define OCI_ATTR_FOCBK                          DCI_ATTR_FOCBK
#define OCI_ATTR_IN_V8_MODE                     DCI_ATTR_IN_V8_MODE
#define OCI_ATTR_LOBEMPTY                       DCI_ATTR_LOBEMPTY
#define OCI_ATTR_SESSLANG                       DCI_ATTR_SESSLANG
#define OCI_ATTR_VISIBILITY                     DCI_ATTR_VISIBILITY
#define OCI_ATTR_RELATIVE_MSGID                 DCI_ATTR_RELATIVE_MSGID
#define OCI_ATTR_SEQUENCE_DEVIATION             DCI_ATTR_SEQUENCE_DEVIATION
#define OCI_ATTR_CONSUMER_NAME                  DCI_ATTR_CONSUMER_NAME
#define OCI_ATTR_DEQ_MODE                       DCI_ATTR_DEQ_MODE
#define OCI_ATTR_NAVIGATION                     DCI_ATTR_NAVIGATION
#define OCI_ATTR_WAIT                           DCI_ATTR_WAIT
#define OCI_ATTR_DEQ_MSGID                      DCI_ATTR_DEQ_MSGID
#define OCI_ATTR_PRIORITY                       DCI_ATTR_PRIORITY
#define OCI_ATTR_DELAY                          DCI_ATTR_DELAY
#define OCI_ATTR_EXPIRATION                     DCI_ATTR_EXPIRATION
#define OCI_ATTR_CORRELATION                    DCI_ATTR_CORRELATION
#define OCI_ATTR_ATTEMPTS                       DCI_ATTR_ATTEMPTS
#define OCI_ATTR_RECIPIENT_LIST                 DCI_ATTR_RECIPIENT_LIST
#define OCI_ATTR_EXCEPTION_QUEUE                DCI_ATTR_EXCEPTION_QUEUE
#define OCI_ATTR_ENQ_TIME                       DCI_ATTR_ENQ_TIME
#define OCI_ATTR_MSG_STATE                      DCI_ATTR_MSG_STATE
#define OCI_ATTR_AGENT_NAME                     DCI_ATTR_AGENT_NAME
#define OCI_ATTR_AGENT_ADDRESS                  DCI_ATTR_AGENT_ADDRESS
#define OCI_ATTR_AGENT_PROTOCOL                 DCI_ATTR_AGENT_PROTOCOL
#define OCI_ATTR_USER_PROPERTY                  DCI_ATTR_USER_PROPERTY
#define OCI_ATTR_SENDER_ID                      DCI_ATTR_SENDER_ID
#define OCI_ATTR_ORIGINAL_MSGID                 DCI_ATTR_ORIGINAL_MSGID
#define OCI_ATTR_QUEUE_NAME                     DCI_ATTR_QUEUE_NAME
#define OCI_ATTR_NFY_MSGID                      DCI_ATTR_NFY_MSGID
#define OCI_ATTR_MSG_PROP                       DCI_ATTR_MSG_PROP
#define OCI_ATTR_NUM_DML_ERRORS                 DCI_ATTR_NUM_DML_ERRORS
#define OCI_ATTR_DML_ROW_OFFSET                 DCI_ATTR_DML_ROW_OFFSET
#define OCI_ATTR_AQ_NUM_ERRORS                  DCI_ATTR_AQ_NUM_ERRORS
#define OCI_ATTR_AQ_ERROR_INDEX                 DCI_ATTR_AQ_ERROR_INDEX
#define OCI_ATTR_DATEFORMAT                     DCI_ATTR_DATEFORMAT
#define OCI_ATTR_BUF_ADDR                       DCI_ATTR_BUF_ADDR
#define OCI_ATTR_BUF_SIZE                       DCI_ATTR_BUF_SIZE
#define OCI_ATTR_DIRPATH_MODE                   DCI_ATTR_DIRPATH_MODE
#define OCI_ATTR_DIRPATH_NOLOG                  DCI_ATTR_DIRPATH_NOLOG
#define OCI_ATTR_DIRPATH_PARALLEL               DCI_ATTR_DIRPATH_PARALLEL
#define OCI_ATTR_NUM_ROWS                       DCI_ATTR_NUM_ROWS
#define OCI_ATTR_COL_COUNT                      DCI_ATTR_COL_COUNT
#define OCI_ATTR_STREAM_OFFSET                  DCI_ATTR_STREAM_OFFSET
#define OCI_ATTR_SHARED_HEAPALLOC               DCI_ATTR_SHARED_HEAPALLOC
#define OCI_ATTR_SERVER_GROUP                   DCI_ATTR_SERVER_GROUP
#define OCI_ATTR_MIGSESSION                     DCI_ATTR_MIGSESSION
#define OCI_ATTR_NOCACHE                        DCI_ATTR_NOCACHE
#define OCI_ATTR_MEMPOOL_SIZE                   DCI_ATTR_MEMPOOL_SIZE
#define OCI_ATTR_MEMPOOL_INSTNAME               DCI_ATTR_MEMPOOL_INSTNAME
#define OCI_ATTR_MEMPOOL_APPNAME                DCI_ATTR_MEMPOOL_APPNAME
#define OCI_ATTR_MEMPOOL_HOMENAME               DCI_ATTR_MEMPOOL_HOMENAME
#define OCI_ATTR_MEMPOOL_MODEL                  DCI_ATTR_MEMPOOL_MODEL
#define OCI_ATTR_MODES                          DCI_ATTR_MODES
#define OCI_ATTR_SUBSCR_NAME                    DCI_ATTR_SUBSCR_NAME
#define OCI_ATTR_SUBSCR_CALLBACK                DCI_ATTR_SUBSCR_CALLBACK
#define OCI_ATTR_SUBSCR_CTX                     DCI_ATTR_SUBSCR_CTX
#define OCI_ATTR_SUBSCR_PAYLOAD                 DCI_ATTR_SUBSCR_PAYLOAD
#define OCI_ATTR_SUBSCR_NAMESPACE               DCI_ATTR_SUBSCR_NAMESPACE
#define OCI_ATTR_PROXY_CREDENTIALS              DCI_ATTR_PROXY_CREDENTIALS
#define OCI_ATTR_INITIAL_CLIENT_ROLES           DCI_ATTR_INITIAL_CLIENT_ROLES
#define OCI_ATTR_UNK                            DCI_ATTR_UNK
#define OCI_ATTR_NUM_COLS                       DCI_ATTR_NUM_COLS
#define OCI_ATTR_LIST_COLUMNS                   DCI_ATTR_LIST_COLUMNS
#define OCI_ATTR_RDBA                           DCI_ATTR_RDBA
#define OCI_ATTR_CLUSTERED                      DCI_ATTR_CLUSTERED
#define OCI_ATTR_PARTITIONED                    DCI_ATTR_PARTITIONED
#define OCI_ATTR_INDEX_ONLY                     DCI_ATTR_INDEX_ONLY
#define OCI_ATTR_LIST_ARGUMENTS                 DCI_ATTR_LIST_ARGUMENTS
#define OCI_ATTR_LIST_SUBPROGRAMS               DCI_ATTR_LIST_SUBPROGRAMS
#define OCI_ATTR_REF_TDO                        DCI_ATTR_REF_TDO
#define OCI_ATTR_LINK                           DCI_ATTR_LINK
#define OCI_ATTR_MIN                            DCI_ATTR_MIN
#define OCI_ATTR_MAX                            DCI_ATTR_MAX
#define OCI_ATTR_INCR                           DCI_ATTR_INCR
#define OCI_ATTR_CACHE                          DCI_ATTR_CACHE
#define OCI_ATTR_ORDER                          DCI_ATTR_ORDER
#define OCI_ATTR_HW_MARK                        DCI_ATTR_HW_MARK
#define OCI_ATTR_TYPE_SCHEMA                    DCI_ATTR_TYPE_SCHEMA
#define OCI_ATTR_TIMESTAMP                      DCI_ATTR_TIMESTAMP
#define OCI_ATTR_NUM_ATTRS                      DCI_ATTR_NUM_ATTRS
#define OCI_ATTR_NUM_PARAMS                     DCI_ATTR_NUM_PARAMS
#define OCI_ATTR_OBJID                          DCI_ATTR_OBJID
#define OCI_ATTR_PTYPE                          DCI_ATTR_PTYPE
#define OCI_ATTR_PARAM                          DCI_ATTR_PARAM
#define OCI_ATTR_OVERLOAD_ID                    DCI_ATTR_OVERLOAD_ID
#define OCI_ATTR_TABLESPACE                     DCI_ATTR_TABLESPACE
#define OCI_ATTR_TDO                            DCI_ATTR_TDO
#define OCI_ATTR_LTYPE                          DCI_ATTR_LTYPE
#define OCI_ATTR_PARSE_ERROR_OFFSET             DCI_ATTR_PARSE_ERROR_OFFSET
#define OCI_ATTR_IS_TEMPORARY                   DCI_ATTR_IS_TEMPORARY
#define OCI_ATTR_IS_TYPED                       DCI_ATTR_IS_TYPED
#define OCI_ATTR_DURATION                       DCI_ATTR_DURATION
#define OCI_ATTR_IS_INVOKER_RIGHTS              DCI_ATTR_IS_INVOKER_RIGHTS
#define OCI_ATTR_OBJ_NAME                       DCI_ATTR_OBJ_NAME
#define OCI_ATTR_OBJ_SCHEMA                     DCI_ATTR_OBJ_SCHEMA
#define OCI_ATTR_OBJ_ID                         DCI_ATTR_OBJ_ID
#define OCI_ATTR_DIRPATH_SORTED_INDEX           DCI_ATTR_DIRPATH_SORTED_INDEX
#define OCI_ATTR_DIRPATH_INDEX_MAINT_METHOD     DCI_ATTR_DIRPATH_INDEX_MAINT_METHOD
#define OCI_ATTR_DIRPATH_FILE                   DCI_ATTR_DIRPATH_FILE
#define OCI_ATTR_DIRPATH_STORAGE_INITIAL        DCI_ATTR_DIRPATH_STORAGE_INITIAL
#define OCI_ATTR_DIRPATH_STORAGE_NEXT           DCI_ATTR_DIRPATH_STORAGE_NEXT
#define OCI_ATTR_TRANS_TIMEOUT                  DCI_ATTR_TRANS_TIMEOUT
#define OCI_ATTR_SERVER_STATUS                  DCI_ATTR_SERVER_STATUS
#define OCI_ATTR_STATEMENT                      DCI_ATTR_STATEMENT
#define OCI_ATTR_DIRPATH_SKIPINDEX_METHOD       DCI_ATTR_DIRPATH_SKIPINDEX_METHOD
#define OCI_ATTR_DEQCOND                        DCI_ATTR_DEQCOND
#define OCI_ATTR_RESERVED_2                     DCI_ATTR_RESERVED_2
#define OCI_ATTR_SUBSCR_RECPT                   DCI_ATTR_SUBSCR_RECPT
#define OCI_ATTR_SUBSCR_RECPTPROTO              DCI_ATTR_SUBSCR_RECPTPROTO
#define OCI_ATTR_DIRPATH_EXPR_TYPE              DCI_ATTR_DIRPATH_EXPR_TYPE
#define OCI_ATTR_DIRPATH_INPUT                  DCI_ATTR_DIRPATH_INPUT
#define OCI_DIRPATH_INPUT_TEXT                  DCI_DIRPATH_INPUT_TEXT
#define OCI_DIRPATH_INPUT_STREAM                DCI_DIRPATH_INPUT_STREAM
#define OCI_DIRPATH_INPUT_UNKNOWN               DCI_DIRPATH_INPUT_UNKNOWN
#define OCI_ATTR_LDAP_HOST                      DCI_ATTR_LDAP_HOST
#define OCI_ATTR_LDAP_PORT                      DCI_ATTR_LDAP_PORT
#define OCI_ATTR_BIND_DN                        DCI_ATTR_BIND_DN
#define OCI_ATTR_LDAP_CRED                      DCI_ATTR_LDAP_CRED
#define OCI_ATTR_WALL_LOC                       DCI_ATTR_WALL_LOC
#define OCI_ATTR_LDAP_AUTH                      DCI_ATTR_LDAP_AUTH
#define OCI_ATTR_LDAP_CTX                       DCI_ATTR_LDAP_CTX
#define OCI_ATTR_SERVER_DNS                     DCI_ATTR_SERVER_DNS
#define OCI_ATTR_DN_COUNT                       DCI_ATTR_DN_COUNT
#define OCI_ATTR_SERVER_DN                      DCI_ATTR_SERVER_DN
#define OCI_ATTR_MAXCHAR_SIZE                   DCI_ATTR_MAXCHAR_SIZE
#define OCI_ATTR_CURRENT_POSITION               DCI_ATTR_CURRENT_POSITION
#define OCI_ATTR_RESERVED_3                     DCI_ATTR_RESERVED_3
#define OCI_ATTR_RESERVED_4                     DCI_ATTR_RESERVED_4
#define OCI_ATTR_DIRPATH_FN_CTX                 DCI_ATTR_DIRPATH_FN_CTX
#define OCI_ATTR_DIGEST_ALGO                    DCI_ATTR_DIGEST_ALGO
#define OCI_ATTR_CERTIFICATE                    DCI_ATTR_CERTIFICATE
#define OCI_ATTR_SIGNATURE_ALGO                 DCI_ATTR_SIGNATURE_ALGO
#define OCI_ATTR_CANONICAL_ALGO                 DCI_ATTR_CANONICAL_ALGO
#define OCI_ATTR_PRIVATE_KEY                    DCI_ATTR_PRIVATE_KEY
#define OCI_ATTR_DIGEST_VALUE                   DCI_ATTR_DIGEST_VALUE
#define OCI_ATTR_SIGNATURE_VAL                  DCI_ATTR_SIGNATURE_VAL
#define OCI_ATTR_SIGNATURE                      DCI_ATTR_SIGNATURE
#define OCI_ATTR_STMTCACHESIZE                  DCI_ATTR_STMTCACHESIZE
#define OCI_ATTR_CONN_NOWAIT                    DCI_ATTR_CONN_NOWAIT
#define OCI_ATTR_CONN_BUSY_COUNT                DCI_ATTR_CONN_BUSY_COUNT
#define OCI_ATTR_CONN_OPEN_COUNT                DCI_ATTR_CONN_OPEN_COUNT
#define OCI_ATTR_CONN_TIMEOUT                   DCI_ATTR_CONN_TIMEOUT
#define OCI_ATTR_STMT_STATE                     DCI_ATTR_STMT_STATE
#define OCI_ATTR_CONN_MIN                       DCI_ATTR_CONN_MIN
#define OCI_ATTR_CONN_MAX                       DCI_ATTR_CONN_MAX
#define OCI_ATTR_CONN_INCR                      DCI_ATTR_CONN_INCR
#define OCI_ATTR_DIRPATH_OID                    DCI_ATTR_DIRPATH_OID
#define OCI_ATTR_NUM_OPEN_STMTS                 DCI_ATTR_NUM_OPEN_STMTS
#define OCI_ATTR_DESCRIBE_NATIVE                DCI_ATTR_DESCRIBE_NATIVE
#define OCI_ATTR_BIND_COUNT                     DCI_ATTR_BIND_COUNT
#define OCI_ATTR_HANDLE_POSITION                DCI_ATTR_HANDLE_POSITION
#define OCI_ATTR_RESERVED_5                     DCI_ATTR_RESERVED_5
#define OCI_ATTR_SERVER_BUSY                    DCI_ATTR_SERVER_BUSY
#define OCI_ATTR_DIRPATH_SID                    DCI_ATTR_DIRPATH_SID
#define OCI_ATTR_SUBSCR_RECPTPRES               DCI_ATTR_SUBSCR_RECPTPRES
#define OCI_ATTR_TRANSFORMATION                 DCI_ATTR_TRANSFORMATION
#define OCI_ATTR_ROWS_FETCHED                   DCI_ATTR_ROWS_FETCHED
#define OCI_ATTR_SCN_BASE                       DCI_ATTR_SCN_BASE
#define OCI_ATTR_SCN_WRAP                       DCI_ATTR_SCN_WRAP
#define OCI_ATTR_RESERVED_6                     DCI_ATTR_RESERVED_6
#define OCI_ATTR_READONLY_TXN                   DCI_ATTR_READONLY_TXN
#define OCI_ATTR_RESERVED_7                     DCI_ATTR_RESERVED_7
#define OCI_ATTR_ERRONEOUS_COLUMN               DCI_ATTR_ERRONEOUS_COLUMN
#define OCI_ATTR_RESERVED_8                     DCI_ATTR_RESERVED_8
#define OCI_ATTR_DIRPATH_OBJ_CONSTR             DCI_ATTR_DIRPATH_OBJ_CONSTR
#define OCI_ATTR_INST_TYPE                      DCI_ATTR_INST_TYPE
#define OCI_ATTR_ENV_UTF16                      DCI_ATTR_ENV_UTF16
#define OCI_ATTR_RESERVED_9                     DCI_ATTR_RESERVED_9
#define OCI_ATTR_RESERVED_10                    DCI_ATTR_RESERVED_10
#define OCI_ATTR_DIRPATH_STREAM_VERSION         DCI_ATTR_DIRPATH_STREAM_VERSION
#define OCI_ATTR_DIRPATH_VARRAY_INDEX           DCI_ATTR_DIRPATH_VARRAY_INDEX
#define OCI_ATTR_RESERVED_12                    DCI_ATTR_RESERVED_12
#define OCI_ATTR_RESERVED_13                    DCI_ATTR_RESERVED_13
#define OCI_ATTR_IS_EXTERNAL                    DCI_ATTR_IS_EXTERNAL
#define OCI_ATTR_RESERVED_15                    DCI_ATTR_RESERVED_15
#define OCI_ATTR_STMT_IS_RETURNING              DCI_ATTR_STMT_IS_RETURNING
#define OCI_ATTR_RESERVED_16                    DCI_ATTR_RESERVED_16
#define OCI_ATTR_RESERVED_17                    DCI_ATTR_RESERVED_17
#define OCI_ATTR_RESERVED_18                    DCI_ATTR_RESERVED_18
#define OCI_ATTR_RESERVED_19                    DCI_ATTR_RESERVED_19
#define OCI_ATTR_LIST_TYPE                      DCI_ATTR_LIST_TYPE
#define OCI_ATTR_DRIVER_NAME                    DCI_ATTR_DRIVER_NAME
#define OCI_ATTR_ENV_CHARSET_ID                 DCI_ATTR_ENV_CHARSET_ID
#define OCI_ATTR_ENV_NCHARSET_ID                DCI_ATTR_ENV_NCHARSET_ID

/**************************EXTENDED ATTRIBUTES FOR DM****************************/
#define OCI_ATTR_SSL_PATH                       DCI_ATTR_SSL_PATH
#define OCI_ATTR_SSL_PWD                        DCI_ATTR_SSL_PWD
#define OCI_ATTR_MPP_LOGIN                      DCI_ATTR_MPP_LOGIN
#define OCI_ATTR_RW_SEPARATE                    DCI_ATTR_RW_SEPARATE
#define OCI_ATTR_RW_SEPARATE_PERCENT            DCI_ATTR_RW_SEPARATE_PERCENT
#define OCI_ATTR_LOGIN_CERTIFICATE              DCI_ATTR_LOGIN_CERTIFICATE
#define OCI_ATTR_PORT                           DCI_ATTR_PORT
#define OCI_ATTR_CONN_TYPE                      DCI_ATTR_CONN_TYPE
#define OCI_ATTR_DIRPATH_SET_IDENTITY           DCI_ATTR_DIRPATH_SET_IDENTITY

#define OCI_DIRPATH_STREAM_VERSION_1            DCI_DIRPATH_STREAM_VERSION_1
#define OCI_DIRPATH_STREAM_VERSION_2            DCI_DIRPATH_STREAM_VERSION_2
#define OCI_DIRPATH_STREAM_VERSION_3            DCI_DIRPATH_STREAM_VERSION_3

#define OCI_ATTR_BIND_ROWCBK                    DCI_ATTR_BIND_ROWCBK
#define OCI_ATTR_BIND_ROWCTX                    DCI_ATTR_BIND_ROWCTX
#define OCI_ATTR_SKIP_BUFFER                    DCI_ATTR_SKIP_BUFFER

#define OCI_SUBSCR_PROTO_OCI                    DCI_SUBSCR_PROTO_OCI
#define OCI_SUBSCR_PROTO_MAIL                   DCI_SUBSCR_PROTO_MAIL
#define OCI_SUBSCR_PROTO_SERVER                 DCI_SUBSCR_PROTO_SERVER
#define OCI_SUBSCR_PROTO_HTTP                   DCI_SUBSCR_PROTO_HTTP
#define OCI_SUBSCR_PROTO_MAX                    DCI_SUBSCR_PROTO_MAX

#define OCI_SUBSCR_PRES_DEFAULT                 DCI_SUBSCR_PRES_DEFAULT
#define OCI_SUBSCR_PRES_XML                     DCI_SUBSCR_PRES_XML
#define OCI_SUBSCR_PRES_MAX                     DCI_SUBSCR_PRES_MAX

#define OCI_UCS2ID                              DCI_UCS2ID
#define OCI_UTF16ID                             DCI_UTF16ID

#define OCI_MPP_LOGIN_GLOBAL                    DCI_MPP_LOGIN_GLOBAL
#define OCI_MPP_LOGIN_LOCAL                     DCI_MPP_LOGIN_LOCAL

#define OCI_RW_SEPARATE_OFF                     DCI_RW_SEPARATE_OFF
#define OCI_RW_SEPARATE_ON                      DCI_RW_SEPARATE_ON

#define OCI_CONN_TCP                            DCI_CONN_TCP
#define OCI_CONN_UDP                            DCI_CONN_UDP
#define OCI_CONN_IPC                            DCI_CONN_IPC
#define OCI_CONN_RDMA                           DCI_CONN_RDMA
#define OCI_CONN_UNIXSOCKET                     DCI_CONN_UNIXSOCKET //UNIXSOCKET

#define OCI_SERVER_NOT_CONNECTED                DCI_SERVER_NOT_CONNECTED
#define OCI_SERVER_NORMAL                       DCI_SERVER_NORMAL

#define OCI_SUBSCR_NAMESPACE_ANONYMOUS          DCI_SUBSCR_NAMESPACE_ANONYMOUS
#define OCI_SUBSCR_NAMESPACE_AQ                 DCI_SUBSCR_NAMESPACE_AQ
#define OCI_SUBSCR_NAMESPACE_MAX                DCI_SUBSCR_NAMESPACE_MAX

#define OCI_CRED_RDBMS                          DCI_CRED_RDBMS
#define OCI_CRED_EXT                            DCI_CRED_EXT
#define OCI_CRED_PROXY                          DCI_CRED_PROXY
#define OCI_CRED_RESERVED_1                     DCI_CRED_RESERVED_1
#define OCI_CRED_RESERVED_2                     DCI_CRED_RESERVED_2

#define OCI_SUCCESS                             DCI_SUCCESS
#define OCI_SUCCESS_WITH_INFO                   DCI_SUCCESS_WITH_INFO
#define OCI_RESERVED_FOR_INT_USE                DCI_RESERVED_FOR_INT_USE
#define OCI_NO_DATA                             DCI_NO_DATA
#define OCI_ERROR                               DCI_ERROR
#define OCI_INVALID_HANDLE                      DCI_INVALID_HANDLE
#define OCI_NEED_DATA                           DCI_NEED_DATA
#define OCI_STILL_EXECUTING                     DCI_STILL_EXECUTING

#define OCI_CONTINUE                            DCI_CONTINUE
#define OCI_ROWCBK_DONE                         DCI_ROWCBK_DONE

#define OCI_DT_INVALID_DAY                      DCI_DT_INVALID_DAY
#define OCI_DT_DAY_BELOW_VALID                  DCI_DT_DAY_BELOW_VALID
#define OCI_DT_INVALID_MONTH                    DCI_DT_INVALID_MONTH
#define OCI_DT_MONTH_BELOW_VALID                DCI_DT_MONTH_BELOW_VALID
#define OCI_DT_INVALID_YEAR                     DCI_DT_INVALID_YEAR
#define OCI_DT_YEAR_BELOW_VALID                 DCI_DT_YEAR_BELOW_VALID
#define OCI_DT_INVALID_HOUR                     DCI_DT_INVALID_HOUR
#define OCI_DT_HOUR_BELOW_VALID                 DCI_DT_HOUR_BELOW_VALID
#define OCI_DT_INVALID_MINUTE                   DCI_DT_INVALID_MINUTE
#define OCI_DT_MINUTE_BELOW_VALID               DCI_DT_MINUTE_BELOW_VALID
#define OCI_DT_INVALID_SECOND                   DCI_DT_INVALID_SECOND
#define OCI_DT_SECOND_BELOW_VALID               DCI_DT_SECOND_BELOW_VALID
#define OCI_DT_DAY_MISSING_FROM_1582            DCI_DT_DAY_MISSING_FROM_1582
#define OCI_DT_YEAR_ZERO                        DCI_DT_YEAR_ZERO
#define OCI_DT_INVALID_TIMEZONE                 DCI_DT_INVALID_TIMEZONE
#define OCI_DT_INVALID_FORMAT                   DCI_DT_INVALID_FORMAT

#define OCI_INTER_INVALID_DAY                   DCI_INTER_INVALID_DAY
#define OCI_INTER_DAY_BELOW_VALID               DCI_INTER_DAY_BELOW_VALID
#define OCI_INTER_INVALID_MONTH                 DCI_INTER_INVALID_MONTH
#define OCI_INTER_MONTH_BELOW_VALID             DCI_INTER_MONTH_BELOW_VALID
#define OCI_INTER_INVALID_YEAR                  DCI_INTER_INVALID_YEAR
#define OCI_INTER_YEAR_BELOW_VALID              DCI_INTER_YEAR_BELOW_VALID
#define OCI_INTER_INVALID_HOUR                  DCI_INTER_INVALID_HOUR
#define OCI_INTER_HOUR_BELOW_VALID              DCI_INTER_HOUR_BELOW_VALID
#define OCI_INTER_INVALID_MINUTE                DCI_INTER_INVALID_MINUTE
#define OCI_INTER_MINUTE_BELOW_VALID            DCI_INTER_MINUTE_BELOW_VALID
#define OCI_INTER_INVALID_SECOND                DCI_INTER_INVALID_SECOND
#define OCI_INTER_SECOND_BELOW_VALID            DCI_INTER_SECOND_BELOW_VALID
#define OCI_INTER_INVALID_FRACSEC               DCI_INTER_INVALID_FRACSEC
#define OCI_INTER_FRACSEC_BELOW_VALID           DCI_INTER_FRACSEC_BELOW_VALID

#define OCI_V7_SYNTAX                           DCI_V7_SYNTAX
#define OCI_V8_SYNTAX                           DCI_V8_SYNTAX
#define OCI_NTV_SYNTAX                          DCI_NTV_SYNTAX

#define OCI_FETCH_CURRENT                       DCI_FETCH_CURRENT
#define OCI_FETCH_NEXT                          DCI_FETCH_NEXT
#define OCI_FETCH_FIRST                         DCI_FETCH_FIRST
#define OCI_FETCH_LAST                          DCI_FETCH_LAST
#define OCI_FETCH_PRIOR                         DCI_FETCH_PRIOR
#define OCI_FETCH_ABSOLUTE                      DCI_FETCH_ABSOLUTE
#define OCI_FETCH_RELATIVE                      DCI_FETCH_RELATIVE
#define OCI_FETCH_RESERVED_1                    DCI_FETCH_RESERVED_1

#define OCI_SB2_IND_PTR                         DCI_SB2_IND_PTR
#define OCI_DATA_AT_EXEC                        DCI_DATA_AT_EXEC
#define OCI_DYNAMIC_FETCH                       DCI_DYNAMIC_FETCH
#define OCI_PIECEWISE                           DCI_PIECEWISE
#define OCI_DEFINE_RESERVED_1                   DCI_DEFINE_RESERVED_1
#define OCI_BIND_RESERVED_2                     DCI_BIND_RESERVED_2
#define OCI_DEFINE_RESERVED_2                   DCI_DEFINE_RESERVED_2
#define OCI_BIND_SOFT                           DCI_BIND_SOFT
#define OCI_DEFINE_SOFT                         DCI_DEFINE_SOFT

#define OCI_DEFAULT                             DCI_DEFAULT
#define OCI_IOV                                 DCI_IOV           /* For scatter gather bind/define */

#define OCI_THREADED                            DCI_THREADED
#define OCI_OBJECT                              DCI_OBJECT
#define OCI_EVENTS                              DCI_EVENTS
#define OCI_RESERVED1                           DCI_RESERVED1
#define OCI_SHARED                              DCI_SHARED
#define OCI_RESERVED2                           DCI_RESERVED2
#define OCI_NO_UCB                              DCI_NO_UCB
#define OCI_SHARED_EXT                          DCI_SHARED_EXT
#define OCI_NO_MUTEX                            DCI_NO_MUTEX
#define OCI_ALWAYS_BLOCKING                     DCI_ALWAYS_BLOCKING
#define OCI_USE_LDAP                            DCI_USE_LDAP
#define OCI_REG_LDAPONLY                        DCI_REG_LDAPONLY
#define OCI_UTF16                               DCI_UTF16
#define OCI_AFC_PAD_ON                          DCI_AFC_PAD_ON
#define OCI_ENVCR_RESERVED3                     DCI_ENVCR_RESERVED3
#define OCI_NEW_LENGTH_SEMANTICS                DCI_NEW_LENGTH_SEMANTICS
#define OCI_NO_MUTEX_STMT                       DCI_NO_MUTEX_STMT
#define OCI_MUTEX_ENV_ONLY                      DCI_MUTEX_ENV_ONLY
#define OCI_NCHAR_LITERAL_REPLACE_ON            DCI_NCHAR_LITERAL_REPLACE_ON
#define OCI_NCHAR_LITERAL_REPLACE_OFF           DCI_NCHAR_LITERAL_REPLACE_OFF
#define OCI_STM_RESERVED4                       DCI_STM_RESERVED4

#define OCI_CPOOL_REINITIALIZE                  DCI_CPOOL_REINITIALIZE

#define OCI_LOGON2_SPOOL                        DCI_LOGON2_SPOOL
#define OCI_LOGON2_CPOOL                        DCI_LOGON2_CPOOL
#define OCI_LOGON2_STMTCACHE                    DCI_LOGON2_STMTCACHE
#define OCI_LOGON2_PROXY                        DCI_LOGON2_PROXY

#define OCI_SPC_REINITIALIZE                    DCI_SPC_REINITIALIZE
#define OCI_SPC_HOMOGENEOUS                     DCI_SPC_HOMOGENEOUS
#define OCI_SPC_STMTCACHE                       DCI_SPC_STMTCACHE
#define OCI_SPC_NO_RLB                          DCI_SPC_NO_RLB

#define OCI_SESSGET_SPOOL                       DCI_SESSGET_SPOOL
#define OCI_SESSGET_CPOOL                       DCI_SESSGET_CPOOL
#define OCI_SESSGET_STMTCACHE                   DCI_SESSGET_STMTCACHE
#define OCI_SESSGET_CREDPROXY                   DCI_SESSGET_CREDPROXY
#define OCI_SESSGET_CREDEXT                     DCI_SESSGET_CREDEXT
#define OCI_SESSGET_SPOOL_MATCHANY              DCI_SESSGET_SPOOL_MATCHANY

#define OCI_SPOOL_ATTRVAL_WAIT                  DCI_SPOOL_ATTRVAL_WAIT
#define OCI_SPOOL_ATTRVAL_NOWAIT                DCI_SPOOL_ATTRVAL_NOWAIT
#define OCI_SPOOL_ATTRVAL_FORCEGET              DCI_SPOOL_ATTRVAL_FORCEGET

#define OCI_SESSRLS_DROPSESS                    DCI_SESSRLS_DROPSESS
#define OCI_SESSRLS_RETAG                       DCI_SESSRLS_RETAG

#define OCI_SPD_FORCE                           DCI_SPD_FORCE

#define OCI_STMT_STATE_INITIALIZED              DCI_STMT_STATE_INITIALIZED
#define OCI_STMT_STATE_EXECUTED                 DCI_STMT_STATE_EXECUTED
#define OCI_STMT_STATE_END_OF_FETCH             DCI_STMT_STATE_END_OF_FETCH

#define OCI_MEM_INIT                            DCI_MEM_INIT
#define OCI_MEM_CLN                             DCI_MEM_CLN
#define OCI_MEM_FLUSH                           DCI_MEM_FLUSH
#define OCI_DUMP_HEAP                           DCI_DUMP_HEAP

#define OCI_CLIENT_STATS                        DCI_CLIENT_STATS
#define OCI_SERVER_STATS                        DCI_SERVER_STATS

#define OCI_ENV_NO_UCB                          DCI_ENV_NO_UCB
#define OCI_ENV_NO_MUTEX                        DCI_ENV_NO_MUTEX

#define OCI_NO_SHARING                          DCI_NO_SHARING
#define OCI_PREP_RESERVED_1                     DCI_PREP_RESERVED_1
#define OCI_PREP_AFC_PAD_ON                     DCI_PREP_AFC_PAD_ON
#define OCI_PREP_AFC_PAD_OFF                    DCI_PREP_AFC_PAD_OFF

#define OCI_BATCH_MODE                          DCI_BATCH_MODE
#define OCI_EXACT_FETCH                         DCI_EXACT_FETCH
#define OCI_KEEP_FETCH_STATE                    DCI_KEEP_FETCH_STATE
#define OCI_STMT_SCROLLABLE_READONLY            DCI_STMT_SCROLLABLE_READONLY
#define OCI_DESCRIBE_ONLY                       DCI_DESCRIBE_ONLY
#define OCI_COMMIT_ON_SUCCESS                   DCI_COMMIT_ON_SUCCESS
#define OCI_NON_BLOCKING                        DCI_NON_BLOCKING
#define OCI_BATCH_ERRORS                        DCI_BATCH_ERRORS
#define OCI_PARSE_ONLY                          DCI_PARSE_ONLY
#define OCI_EXACT_FETCH_RESERVED_1              DCI_EXACT_FETCH_RESERVED_1
#define OCI_SHOW_DML_WARNINGS                   DCI_SHOW_DML_WARNINGS
#define OCI_EXEC_RESERVED_2                     DCI_EXEC_RESERVED_2
#define OCI_DESC_RESERVED_1                     DCI_DESC_RESERVED_1
#define OCI_EXEC_RESERVED_3                     DCI_EXEC_RESERVED_3
#define OCI_EXEC_RESERVED_4                     DCI_EXEC_RESERVED_4
#define OCI_IDU_BATCH_COMPATIBLE                DCI_IDU_BATCH_COMPATIBLE

#define OCI_MIGRATE                             DCI_MIGRATE
#define OCI_SYSDBA                              DCI_SYSDBA
#define OCI_SYSOPER                             DCI_SYSOPER
#define OCI_PRELIM_AUTH                         DCI_PRELIM_AUTH
#define OCIP_ICACHE                             DCIP_ICACHE
#define OCI_AUTH_RESERVED_1                     DCI_AUTH_RESERVED_1
#define OCI_STMT_CACHE                          DCI_STMT_CACHE

#define OCI_SESSEND_RESERVED_1                  DCI_SESSEND_RESERVED_1

#define OCI_FASTPATH                            DCI_FASTPATH
#define OCI_ATCH_RESERVED_1                     DCI_ATCH_RESERVED_1
#define OCI_ATCH_RESERVED_2                     DCI_ATCH_RESERVED_2
#define OCI_ATCH_RESERVED_3                     DCI_ATCH_RESERVED_3
#define OCI_CPOOL                               DCI_CPOOL
#define OCI_ATCH_RESERVED_4                     DCI_ATCH_RESERVED_4

#define OCI_PREP2_CACHE_SEARCHONLY              DCI_PREP2_CACHE_SEARCHONLY
#define OCI_PREP2_GET_PLSQL_WARNINGS            DCI_PREP2_GET_PLSQL_WARNINGS

#define OCI_STRLS_CACHE_DELETE                  DCI_STRLS_CACHE_DELETE

#define OCI_PARAM_IN                            DCI_PARAM_IN
#define OCI_PARAM_OUT                           DCI_PARAM_OUT

#define OCI_TRANS_NEW                           DCI_TRANS_NEW
#define OCI_TRANS_JOIN                          DCI_TRANS_JOIN
#define OCI_TRANS_RESUME                        DCI_TRANS_RESUME
#define OCI_TRANS_STARTMASK                     DCI_TRANS_STARTMASK
#define OCI_TRANS_READONLY                      DCI_TRANS_READONLY
#define OCI_TRANS_READWRITE                     DCI_TRANS_READWRITE
#define OCI_TRANS_SERIALIZABLE                  DCI_TRANS_SERIALIZABLE
#define OCI_TRANS_ISOLMASK                      DCI_TRANS_ISOLMASK
#define OCI_TRANS_LOOSE                         DCI_TRANS_LOOSE
#define OCI_TRANS_TIGHT                         DCI_TRANS_TIGHT
#define OCI_TRANS_TYPEMASK                      DCI_TRANS_TYPEMASK
#define OCI_TRANS_NOMIGRATE                     DCI_TRANS_NOMIGRATE
#define OCI_TRANS_SEPARABLE                     DCI_TRANS_SEPARABLE

#define OCI_TRANS_TWOPHASE                      DCI_TRANS_TWOPHASE

#define OCI_ENQ_IMMEDIATE                       DCI_ENQ_IMMEDIATE
#define OCI_ENQ_ON_COMMIT                       DCI_ENQ_ON_COMMIT

#define OCI_DEQ_BROWSE                          DCI_DEQ_BROWSE
#define OCI_DEQ_LOCKED                          DCI_DEQ_LOCKED
#define OCI_DEQ_REMOVE                          DCI_DEQ_REMOVE
#define OCI_DEQ_REMOVE_NODATA                   DCI_DEQ_REMOVE_NODATA
#define OCI_DEQ_GETSIG                          DCI_DEQ_GETSIG

#define OCI_DEQ_FIRST_MSG                       DCI_DEQ_FIRST_MSG
#define OCI_DEQ_NEXT_MSG                        DCI_DEQ_NEXT_MSG
#define OCI_DEQ_NEXT_TRANSACTION                DCI_DEQ_NEXT_TRANSACTION
#define OCI_DEQ_MULT_TRANSACTION                DCI_DEQ_MULT_TRANSACTION

#define OCI_DEQ_RESERVED_1                      DCI_DEQ_RESERVED_1

#define OCI_MSG_WAITING                         DCI_MSG_WAITING
#define OCI_MSG_READY                           DCI_MSG_READY
#define OCI_MSG_PROCESSED                       DCI_MSG_PROCESSED
#define OCI_MSG_EXPIRED                         DCI_MSG_EXPIRED

#define OCI_ENQ_BEFORE                          DCI_ENQ_BEFORE
#define OCI_ENQ_TOP                             DCI_ENQ_TOP

#define OCI_DEQ_IMMEDIATE                       DCI_DEQ_IMMEDIATE
#define OCI_DEQ_ON_COMMIT                       DCI_DEQ_ON_COMMIT

#define OCI_DEQ_WAIT_FOREVER                    DCI_DEQ_WAIT_FOREVER
#define OCI_DEQ_NO_WAIT                         DCI_DEQ_NO_WAIT

#define OCI_MSG_NO_DELAY                        DCI_MSG_NO_DELAY

#define OCI_MSG_NO_EXPIRATION                   DCI_MSG_NO_EXPIRATION

#define OCI_AQ_RESERVED_1                       DCI_AQ_RESERVED_1
#define OCI_AQ_RESERVED_2                       DCI_AQ_RESERVED_2
#define OCI_AQ_RESERVED_3                       DCI_AQ_RESERVED_3

#define OCI_OTYPE_UNK                           DCI_OTYPE_UNK
#define OCI_OTYPE_TABLE                         DCI_OTYPE_TABLE
#define OCI_OTYPE_VIEW                          DCI_OTYPE_VIEW
#define OCI_OTYPE_SYN                           DCI_OTYPE_SYN
#define OCI_OTYPE_PROC                          DCI_OTYPE_PROC
#define OCI_OTYPE_FUNC                          DCI_OTYPE_FUNC
#define OCI_OTYPE_PKG                           DCI_OTYPE_PKG
#define OCI_OTYPE_STMT                          DCI_OTYPE_STMT

#define OCI_ATTR_DATA_SIZE                      DCI_ATTR_DATA_SIZE
#define OCI_ATTR_DATA_TYPE                      DCI_ATTR_DATA_TYPE
#define OCI_ATTR_DISP_SIZE                      DCI_ATTR_DISP_SIZE
#define OCI_ATTR_NAME                           DCI_ATTR_NAME
#define OCI_ATTR_PRECISION                      DCI_ATTR_PRECISION
#define OCI_ATTR_SCALE                          DCI_ATTR_SCALE
#define OCI_ATTR_IS_NULL                        DCI_ATTR_IS_NULL
#define OCI_ATTR_TYPE_NAME                      DCI_ATTR_TYPE_NAME
#define OCI_ATTR_SCHEMA_NAME                    DCI_ATTR_SCHEMA_NAME
#define OCI_ATTR_SUB_NAME                       DCI_ATTR_SUB_NAME
#define OCI_ATTR_POSITION                       DCI_ATTR_POSITION

#define OCI_ATTR_COMPLEXOBJECTCOMP_TYPE         DCI_ATTR_COMPLEXOBJECTCOMP_TYPE
#define OCI_ATTR_COMPLEXOBJECTCOMP_TYPE_LEVEL   DCI_ATTR_COMPLEXOBJECTCOMP_TYPE_LEVEL
#define OCI_ATTR_COMPLEXOBJECT_LEVEL            DCI_ATTR_COMPLEXOBJECT_LEVEL
#define OCI_ATTR_COMPLEXOBJECT_COLL_OUTOFLINE   DCI_ATTR_COMPLEXOBJECT_COLL_OUTOFLINE

#define OCI_ATTR_DISP_NAME                      DCI_ATTR_DISP_NAME
#define OCI_ATTR_ENCC_SIZE                      DCI_ATTR_ENCC_SIZE
#define OCI_ATTR_COL_ENC                        DCI_ATTR_COL_ENC
#define OCI_ATTR_COL_ENC_SALT                   DCI_ATTR_COL_ENC_SALT

#define OCI_ATTR_OVERLOAD                       DCI_ATTR_OVERLOAD
#define OCI_ATTR_LEVEL                          DCI_ATTR_LEVEL
#define OCI_ATTR_HAS_DEFAULT                    DCI_ATTR_HAS_DEFAULT
#define OCI_ATTR_IOMODE                         DCI_ATTR_IOMODE
#define OCI_ATTR_RADIX                          DCI_ATTR_RADIX
#define OCI_ATTR_NUM_ARGS                       DCI_ATTR_NUM_ARGS

#define OCI_ATTR_TYPECODE                       DCI_ATTR_TYPECODE
#define OCI_ATTR_COLLECTION_TYPECODE            DCI_ATTR_COLLECTION_TYPECODE
#define OCI_ATTR_VERSION                        DCI_ATTR_VERSION
#define OCI_ATTR_IS_INCOMPLETE_TYPE             DCI_ATTR_IS_INCOMPLETE_TYPE
#define OCI_ATTR_IS_SYSTEM_TYPE                 DCI_ATTR_IS_SYSTEM_TYPE
#define OCI_ATTR_IS_PREDEFINED_TYPE             DCI_ATTR_IS_PREDEFINED_TYPE
#define OCI_ATTR_IS_TRANSIENT_TYPE              DCI_ATTR_IS_TRANSIENT_TYPE
#define OCI_ATTR_IS_SYSTEM_GENERATED_TYPE       DCI_ATTR_IS_SYSTEM_GENERATED_TYPE
#define OCI_ATTR_HAS_NESTED_TABLE               DCI_ATTR_HAS_NESTED_TABLE
#define OCI_ATTR_HAS_LOB                        DCI_ATTR_HAS_LOB
#define OCI_ATTR_HAS_FILE                       DCI_ATTR_HAS_FILE
#define OCI_ATTR_COLLECTION_ELEMENT             DCI_ATTR_COLLECTION_ELEMENT
#define OCI_ATTR_NUM_TYPE_ATTRS                 DCI_ATTR_NUM_TYPE_ATTRS
#define OCI_ATTR_LIST_TYPE_ATTRS                DCI_ATTR_LIST_TYPE_ATTRS
#define OCI_ATTR_NUM_TYPE_METHODS               DCI_ATTR_NUM_TYPE_METHODS
#define OCI_ATTR_LIST_TYPE_METHODS              DCI_ATTR_LIST_TYPE_METHODS
#define OCI_ATTR_MAP_METHOD                     DCI_ATTR_MAP_METHOD
#define OCI_ATTR_ORDER_METHOD                   DCI_ATTR_ORDER_METHOD

#define OCI_ATTR_NUM_ELEMS                      DCI_ATTR_NUM_ELEMS

#define OCI_ATTR_ENCAPSULATION                  DCI_ATTR_ENCAPSULATION
#define OCI_ATTR_IS_SELFISH                     DCI_ATTR_IS_SELFISH
#define OCI_ATTR_IS_VIRTUAL                     DCI_ATTR_IS_VIRTUAL
#define OCI_ATTR_IS_INLINE                      DCI_ATTR_IS_INLINE
#define OCI_ATTR_IS_CONSTANT                    DCI_ATTR_IS_CONSTANT
#define OCI_ATTR_HAS_RESULT                     DCI_ATTR_HAS_RESULT
#define OCI_ATTR_IS_CONSTRUCTOR                 DCI_ATTR_IS_CONSTRUCTOR
#define OCI_ATTR_IS_DESTRUCTOR                  DCI_ATTR_IS_DESTRUCTOR
#define OCI_ATTR_IS_OPERATOR                    DCI_ATTR_IS_OPERATOR
#define OCI_ATTR_IS_MAP                         DCI_ATTR_IS_MAP
#define OCI_ATTR_IS_ORDER                       DCI_ATTR_IS_ORDER
#define OCI_ATTR_IS_RNDS                        DCI_ATTR_IS_RNDS
#define OCI_ATTR_IS_RNPS                        DCI_ATTR_IS_RNPS
#define OCI_ATTR_IS_WNDS                        DCI_ATTR_IS_WNDS
#define OCI_ATTR_IS_WNPS                        DCI_ATTR_IS_WNPS
#define OCI_ATTR_DESC_PUBLIC                    DCI_ATTR_DESC_PUBLIC

#define OCI_ATTR_CACHE_CLIENT_CONTEXT           DCI_ATTR_CACHE_CLIENT_CONTEXT
#define OCI_ATTR_UCI_CONSTRUCT                  DCI_ATTR_UCI_CONSTRUCT
#define OCI_ATTR_UCI_DESTRUCT                   DCI_ATTR_UCI_DESTRUCT
#define OCI_ATTR_UCI_COPY                       DCI_ATTR_UCI_COPY
#define OCI_ATTR_UCI_PICKLE                     DCI_ATTR_UCI_PICKLE
#define OCI_ATTR_UCI_UNPICKLE                   DCI_ATTR_UCI_UNPICKLE
#define OCI_ATTR_UCI_REFRESH                    DCI_ATTR_UCI_REFRESH

#define OCI_ATTR_IS_SUBTYPE                     DCI_ATTR_IS_SUBTYPE
#define OCI_ATTR_SUPERTYPE_SCHEMA_NAME          DCI_ATTR_SUPERTYPE_SCHEMA_NAME
#define OCI_ATTR_SUPERTYPE_NAME                 DCI_ATTR_SUPERTYPE_NAME

#define OCI_ATTR_LIST_OBJECTS                   DCI_ATTR_LIST_OBJECTS

#define OCI_ATTR_NCHARSET_ID                    DCI_ATTR_NCHARSET_ID
#define OCI_ATTR_LIST_SCHEMAS                   DCI_ATTR_LIST_SCHEMAS
#define OCI_ATTR_MAX_PROC_LEN                   DCI_ATTR_MAX_PROC_LEN
#define OCI_ATTR_MAX_COLUMN_LEN                 DCI_ATTR_MAX_COLUMN_LEN
#define OCI_ATTR_CURSOR_COMMIT_BEHAVIOR         DCI_ATTR_CURSOR_COMMIT_BEHAVIOR
#define OCI_ATTR_MAX_CATALOG_NAMELEN            DCI_ATTR_MAX_CATALOG_NAMELEN
#define OCI_ATTR_CATALOG_LOCATION               DCI_ATTR_CATALOG_LOCATION
#define OCI_ATTR_SAVEPOINT_SUPPORT              DCI_ATTR_SAVEPOINT_SUPPORT
#define OCI_ATTR_NOWAIT_SUPPORT                 DCI_ATTR_NOWAIT_SUPPORT
#define OCI_ATTR_AUTOCOMMIT_DDL                 DCI_ATTR_AUTOCOMMIT_DDL
#define OCI_ATTR_LOCKING_MODE                   DCI_ATTR_LOCKING_MODE

#define OCI_ATTR_APPCTX_SIZE                    DCI_ATTR_APPCTX_SIZE
#define OCI_ATTR_APPCTX_LIST                    DCI_ATTR_APPCTX_LIST
#define OCI_ATTR_APPCTX_NAME                    DCI_ATTR_APPCTX_NAME
#define OCI_ATTR_APPCTX_ATTR                    DCI_ATTR_APPCTX_ATTR
#define OCI_ATTR_APPCTX_VALUE                   DCI_ATTR_APPCTX_VALUE

#define OCI_ATTR_CLIENT_IDENTIFIER              DCI_ATTR_CLIENT_IDENTIFIER

#define OCI_ATTR_IS_FINAL_TYPE                  DCI_ATTR_IS_FINAL_TYPE
#define OCI_ATTR_IS_INSTANTIABLE_TYPE           DCI_ATTR_IS_INSTANTIABLE_TYPE
#define OCI_ATTR_IS_FINAL_METHOD                DCI_ATTR_IS_FINAL_METHOD
#define OCI_ATTR_IS_INSTANTIABLE_METHOD         DCI_ATTR_IS_INSTANTIABLE_METHOD
#define OCI_ATTR_IS_OVERRIDING_METHOD           DCI_ATTR_IS_OVERRIDING_METHOD

#define OCI_ATTR_CHAR_USED                      DCI_ATTR_CHAR_USED
#define OCI_ATTR_CHAR_SIZE                      DCI_ATTR_CHAR_SIZE

#define OCI_ATTR_IS_JAVA_TYPE                   DCI_ATTR_IS_JAVA_TYPE

#define OCI_ATTR_DISTINGUISHED_NAME             DCI_ATTR_DISTINGUISHED_NAME
#define OCI_ATTR_KERBEROS_TICKET                DCI_ATTR_KERBEROS_TICKET

#define OCI_ATTR_ORA_DEBUG_JDWP                 DCI_ATTR_ORA_DEBUG_JDWP
#define OCI_ATTR_RESERVED_14                    DCI_ATTR_RESERVED_14

#define OCI_ATTR_TABLE_ENC                      DCI_ATTR_TABLE_ENC
#define OCI_ATTR_TABLE_ENC_ALG                  DCI_ATTR_TABLE_ENC_ALG
#define OCI_ATTR_TABLE_ENC_ALG_ID               DCI_ATTR_TABLE_ENC_ALG_ID

#define OCI_ATTR_DIRPATH_DCACHE_NUM             DCI_ATTR_DIRPATH_DCACHE_NUM
#define OCI_ATTR_DIRPATH_DCACHE_SIZE            DCI_ATTR_DIRPATH_DCACHE_SIZE
#define OCI_ATTR_DIRPATH_DCACHE_MISSES          DCI_ATTR_DIRPATH_DCACHE_MISSES
#define OCI_ATTR_DIRPATH_DCACHE_HITS            DCI_ATTR_DIRPATH_DCACHE_HITS
#define OCI_ATTR_DIRPATH_DCACHE_DISABLE         DCI_ATTR_DIRPATH_DCACHE_DISABLE

#define OCI_ATTR_SPOOL_TIMEOUT                  DCI_ATTR_SPOOL_TIMEOUT
#define OCI_ATTR_SPOOL_GETMODE                  DCI_ATTR_SPOOL_GETMODE
#define OCI_ATTR_SPOOL_BUSY_COUNT               DCI_ATTR_SPOOL_BUSY_COUNT
#define OCI_ATTR_SPOOL_OPEN_COUNT               DCI_ATTR_SPOOL_OPEN_COUNT
#define OCI_ATTR_SPOOL_MIN                      DCI_ATTR_SPOOL_MIN
#define OCI_ATTR_SPOOL_MAX                      DCI_ATTR_SPOOL_MAX
#define OCI_ATTR_SPOOL_INCR                     DCI_ATTR_SPOOL_INCR
#define OCI_ATTR_SPOOL_STMTCACHESIZE            DCI_ATTR_SPOOL_STMTCACHESIZE

#define OCI_ATTR_IS_XMLTYPE                     DCI_ATTR_IS_XMLTYPE
#define OCI_ATTR_XMLSCHEMA_NAME                 DCI_ATTR_XMLSCHEMA_NAME
#define OCI_ATTR_XMLELEMENT_NAME                DCI_ATTR_XMLELEMENT_NAME
#define OCI_ATTR_XMLSQLTYPSCH_NAME              DCI_ATTR_XMLSQLTYPSCH_NAME
#define OCI_ATTR_XMLSQLTYPE_NAME                DCI_ATTR_XMLSQLTYPE_NAME
#define OCI_ATTR_XMLTYPE_STORED_OBJ             DCI_ATTR_XMLTYPE_STORED_OBJ

#define OCI_ATTR_HAS_SUBTYPES                   DCI_ATTR_HAS_SUBTYPES
#define OCI_ATTR_NUM_SUBTYPES                   DCI_ATTR_NUM_SUBTYPES
#define OCI_ATTR_LIST_SUBTYPES                  DCI_ATTR_LIST_SUBTYPES

#define OCI_ATTR_XML_HRCHY_ENABLED              DCI_ATTR_XML_HRCHY_ENABLED

#define OCI_ATTR_IS_OVERRIDDEN_METHOD           DCI_ATTR_IS_OVERRIDDEN_METHOD

#define OCI_ATTR_DIRPATH_RESERVED_7             DCI_ATTR_DIRPATH_RESERVED_7
#define OCI_ATTR_DIRPATH_RESERVED_8             DCI_ATTR_DIRPATH_RESERVED_8
#define OCI_ATTR_DIRPATH_CONVERT                DCI_ATTR_DIRPATH_CONVERT
#define OCI_ATTR_DIRPATH_BADROW                 DCI_ATTR_DIRPATH_BADROW
#define OCI_ATTR_DIRPATH_BADROW_LENGTH          DCI_ATTR_DIRPATH_BADROW_LENGTH
#define OCI_ATTR_DIRPATH_WRITE_ORDER            DCI_ATTR_DIRPATH_WRITE_ORDER
#define OCI_ATTR_DIRPATH_GRANULE_SIZE           DCI_ATTR_DIRPATH_GRANULE_SIZE
#define OCI_ATTR_DIRPATH_GRANULE_OFFSET         DCI_ATTR_DIRPATH_GRANULE_OFFSET
#define OCI_ATTR_DIRPATH_RESERVED_1             DCI_ATTR_DIRPATH_RESERVED_1
#define OCI_ATTR_DIRPATH_RESERVED_2             DCI_ATTR_DIRPATH_RESERVED_2

#define OCI_ATTR_OBJ_SUBS                       DCI_ATTR_OBJ_SUBS

#define OCI_ATTR_DIRPATH_RESERVED_3             DCI_ATTR_DIRPATH_RESERVED_3
#define OCI_ATTR_DIRPATH_RESERVED_4             DCI_ATTR_DIRPATH_RESERVED_4

#define OCI_ATTR_XADFIELD_RESERVED_1            DCI_ATTR_XADFIELD_RESERVED_1
#define OCI_ATTR_XADFIELD_RESERVED_2            DCI_ATTR_XADFIELD_RESERVED_2

#define OCI_ATTR_KERBEROS_CID                   DCI_ATTR_KERBEROS_CID

#define OCI_ATTR_CONDITION                      DCI_ATTR_CONDITION
#define OCI_ATTR_COMMENT                        DCI_ATTR_COMMENT
#define OCI_ATTR_VALUE                          DCI_ATTR_VALUE
#define OCI_ATTR_EVAL_CONTEXT_OWNER             DCI_ATTR_EVAL_CONTEXT_OWNER
#define OCI_ATTR_EVAL_CONTEXT_NAME              DCI_ATTR_EVAL_CONTEXT_NAME
#define OCI_ATTR_EVALUATION_FUNCTION            DCI_ATTR_EVALUATION_FUNCTION
#define OCI_ATTR_VAR_TYPE                       DCI_ATTR_VAR_TYPE
#define OCI_ATTR_VAR_VALUE_FUNCTION             DCI_ATTR_VAR_VALUE_FUNCTION
#define OCI_ATTR_VAR_METHOD_FUNCTION            DCI_ATTR_VAR_METHOD_FUNCTION
#define OCI_ATTR_ACTION_CONTEXT                 DCI_ATTR_ACTION_CONTEXT
#define OCI_ATTR_LIST_TABLE_ALIASES             DCI_ATTR_LIST_TABLE_ALIASES
#define OCI_ATTR_LIST_VARIABLE_TYPES            DCI_ATTR_LIST_VARIABLE_TYPES
#define OCI_ATTR_TABLE_NAME                     DCI_ATTR_TABLE_NAME
#define OCI_ATTR_DIRPATH_RESERVED_5             DCI_ATTR_DIRPATH_RESERVED_5
#define OCI_ATTR_DIRPATH_RESERVED_6             DCI_ATTR_DIRPATH_RESERVED_6
#define OCI_ATTR_DIRPATH_LOCK_WAIT              DCI_ATTR_DIRPATH_LOCK_WAIT
#define OCI_ATTR_MESSAGE_CSCN                   DCI_ATTR_MESSAGE_CSCN
#define OCI_ATTR_MESSAGE_DSCN                   DCI_ATTR_MESSAGE_DSCN

#define OCI_ATTR_AUDIT_SESSION_ID               DCI_ATTR_AUDIT_SESSION_ID

#define OCI_ATTR_KERBEROS_KEY                   DCI_ATTR_KERBEROS_KEY
#define OCI_ATTR_KERBEROS_CID_KEY               DCI_ATTR_KERBEROS_CID_KEY
#define OCI_ATTR_TRANSACTION_NO                 DCI_ATTR_TRANSACTION_NO

#define OCI_ATTR_MODULE                         DCI_ATTR_MODULE
#define OCI_ATTR_ACTION                         DCI_ATTR_ACTION
#define OCI_ATTR_CLIENT_INFO                    DCI_ATTR_CLIENT_INFO
#define OCI_ATTR_COLLECT_CALL_TIME              DCI_ATTR_COLLECT_CALL_TIME
#define OCI_ATTR_CALL_TIME                      DCI_ATTR_CALL_TIME
#define OCI_ATTR_ECONTEXT_ID                    DCI_ATTR_ECONTEXT_ID
#define OCI_ATTR_ECONTEXT_SEQ                   DCI_ATTR_ECONTEXT_SEQ

#define OCI_CURSOR_OPEN                         DCI_CURSOR_OPEN
#define OCI_CURSOR_CLOSED                       DCI_CURSOR_CLOSED

#define OCI_CL_START                            DCI_CL_START
#define OCI_CL_END                              DCI_CL_END

#define OCI_SP_SUPPORTED                        DCI_SP_SUPPORTED
#define OCI_SP_UNSUPPORTED                      DCI_SP_UNSUPPORTED

#define OCI_NW_SUPPORTED                        DCI_NW_SUPPORTED
#define OCI_NW_UNSUPPORTED                      DCI_NW_UNSUPPORTED

#define OCI_AC_DDL                              DCI_AC_DDL
#define OCI_NO_AC_DDL                           DCI_NO_AC_DDL

#define OCI_LOCK_IMMEDIATE                      DCI_LOCK_IMMEDIATE
#define OCI_LOCK_DELAYED                        DCI_LOCK_DELAYED

#define OCI_INSTANCE_TYPE_UNKNOWN               DCI_INSTANCE_TYPE_UNKNOWN
#define OCI_INSTANCE_TYPE_RDBMS                 DCI_INSTANCE_TYPE_RDBMS
#define OCI_INSTANCE_TYPE_OSM                   DCI_INSTANCE_TYPE_OSM

#define OCI_AUTH                                DCI_AUTH

#define OCI_MAX_FNS                             DCI_MAX_FNS
#define OCI_SQLSTATE_SIZE                       DCI_SQLSTATE_SIZE
#define OCI_ERROR_MAXMSG_SIZE                   DCI_ERROR_MAXMSG_SIZE
#define OCI_LOBMAXSIZE                          DCI_LOBMAXSIZE
#define OCI_ROWID_LEN                           DCI_ROWID_LEN

#define OCI_FO_END                              DCI_FO_END
#define OCI_FO_ABORT                            DCI_FO_ABORT
#define OCI_FO_REAUTH                           DCI_FO_REAUTH
#define OCI_FO_BEGIN                            DCI_FO_BEGIN
#define OCI_FO_ERROR                            DCI_FO_ERROR

#define OCI_FO_RETRY                            DCI_FO_RETRY

#define OCI_FO_NONE                             DCI_FO_NONE
#define OCI_FO_SESSION                          DCI_FO_SESSION
#define OCI_FO_SELECT                           DCI_FO_SELECT
#define OCI_FO_TXNAL                            DCI_FO_TXNAL

#define OCI_FNCODE_INITIALIZE                   DCI_FNCODE_INITIALIZE
#define OCI_FNCODE_HANDLEALLOC                  DCI_FNCODE_HANDLEALLOC
#define OCI_FNCODE_HANDLEFREE                   DCI_FNCODE_HANDLEFREE
#define OCI_FNCODE_DESCRIPTORALLOC              DCI_FNCODE_DESCRIPTORALLOC
#define OCI_FNCODE_DESCRIPTORFREE               DCI_FNCODE_DESCRIPTORFREE
#define OCI_FNCODE_ENVINIT                      DCI_FNCODE_ENVINIT
#define OCI_FNCODE_SERVERATTACH                 DCI_FNCODE_SERVERATTACH
#define OCI_FNCODE_SERVERDETACH                 DCI_FNCODE_SERVERDETACH
#define OCI_FNCODE_SESSIONBEGIN                 DCI_FNCODE_SESSIONBEGIN
#define OCI_FNCODE_SESSIONEND                   DCI_FNCODE_SESSIONEND
#define OCI_FNCODE_PASSWORDCHANGE               DCI_FNCODE_PASSWORDCHANGE
#define OCI_FNCODE_STMTPREPARE                  DCI_FNCODE_STMTPREPARE
#define OCI_FNCODE_BINDDYNAMIC                  DCI_FNCODE_BINDDYNAMIC
#define OCI_FNCODE_BINDOBJECT                   DCI_FNCODE_BINDOBJECT
#define OCI_FNCODE_BINDARRAYOFSTRUCT            DCI_FNCODE_BINDARRAYOFSTRUCT
#define OCI_FNCODE_STMTEXECUTE                  DCI_FNCODE_STMTEXECUTE
#define OCI_FNCODE_DEFINEOBJECT                 DCI_FNCODE_DEFINEOBJECT
#define OCI_FNCODE_DEFINEDYNAMIC                DCI_FNCODE_DEFINEDYNAMIC
#define OCI_FNCODE_DEFINEARRAYOFSTRUCT          DCI_FNCODE_DEFINEARRAYOFSTRUCT
#define OCI_FNCODE_STMTFETCH                    DCI_FNCODE_STMTFETCH
#define OCI_FNCODE_STMTGETBIND                  DCI_FNCODE_STMTGETBIND
#define OCI_FNCODE_DESCRIBEANY                  DCI_FNCODE_DESCRIBEANY
#define OCI_FNCODE_TRANSSTART                   DCI_FNCODE_TRANSSTART
#define OCI_FNCODE_TRANSDETACH                  DCI_FNCODE_TRANSDETACH
#define OCI_FNCODE_TRANSCOMMIT                  DCI_FNCODE_TRANSCOMMIT
#define OCI_FNCODE_ERRORGET                     DCI_FNCODE_ERRORGET
#define OCI_FNCODE_LOBOPENFILE                  DCI_FNCODE_LOBOPENFILE
#define OCI_FNCODE_LOBCLOSEFILE                 DCI_FNCODE_LOBCLOSEFILE
#define OCI_FNCODE_LOBCOPY                      DCI_FNCODE_LOBCOPY
#define OCI_FNCODE_LOBAPPEND                    DCI_FNCODE_LOBAPPEND
#define OCI_FNCODE_LOBERASE                     DCI_FNCODE_LOBERASE
#define OCI_FNCODE_LOBLENGTH                    DCI_FNCODE_LOBLENGTH
#define OCI_FNCODE_LOBTRIM                      DCI_FNCODE_LOBTRIM
#define OCI_FNCODE_LOBREAD                      DCI_FNCODE_LOBREAD
#define OCI_FNCODE_LOBWRITE                     DCI_FNCODE_LOBWRITE
#define OCI_FNCODE_SVCCTXBREAK                  DCI_FNCODE_SVCCTXBREAK
#define OCI_FNCODE_SERVERVERSION                DCI_FNCODE_SERVERVERSION
#define OCI_FNCODE_KERBATTRSET                  DCI_FNCODE_KERBATTRSET
#define OCI_FNCODE_ATTRGET                      DCI_FNCODE_ATTRGET
#define OCI_FNCODE_ATTRSET                      DCI_FNCODE_ATTRSET
#define OCI_FNCODE_PARAMSET                     DCI_FNCODE_PARAMSET
#define OCI_FNCODE_PARAMGET                     DCI_FNCODE_PARAMGET
#define OCI_FNCODE_STMTGETPIECEINFO             DCI_FNCODE_STMTGETPIECEINFO
#define OCI_FNCODE_LDATOSVCCTX                  DCI_FNCODE_LDATOSVCCTX
#define OCI_FNCODE_STMTSETPIECEINFO             DCI_FNCODE_STMTSETPIECEINFO
#define OCI_FNCODE_TRANSFORGET                  DCI_FNCODE_TRANSFORGET
#define OCI_FNCODE_TRANSPREPARE                 DCI_FNCODE_TRANSPREPARE
#define OCI_FNCODE_TRANSROLLBACK                DCI_FNCODE_TRANSROLLBACK
#define OCI_FNCODE_DEFINEBYPOS                  DCI_FNCODE_DEFINEBYPOS
#define OCI_FNCODE_BINDBYPOS                    DCI_FNCODE_BINDBYPOS
#define OCI_FNCODE_BINDBYNAME                   DCI_FNCODE_BINDBYNAME
#define OCI_FNCODE_LOBASSIGN                    DCI_FNCODE_LOBASSIGN
#define OCI_FNCODE_LOBISEQUAL                   DCI_FNCODE_LOBISEQUAL
#define OCI_FNCODE_LOBISINIT                    DCI_FNCODE_LOBISINIT
#define OCI_FNCODE_LOBENABLEBUFFERING           DCI_FNCODE_LOBENABLEBUFFERING
#define OCI_FNCODE_LOBCHARSETID                 DCI_FNCODE_LOBCHARSETID
#define OCI_FNCODE_LOBCHARSETFORM               DCI_FNCODE_LOBCHARSETFORM
#define OCI_FNCODE_LOBFILESETNAME               DCI_FNCODE_LOBFILESETNAME
#define OCI_FNCODE_LOBFILEGETNAME               DCI_FNCODE_LOBFILEGETNAME
#define OCI_FNCODE_LOGON                        DCI_FNCODE_LOGON
#define OCI_FNCODE_LOGOFF                       DCI_FNCODE_LOGOFF
#define OCI_FNCODE_LOBDISABLEBUFFERING          DCI_FNCODE_LOBDISABLEBUFFERING
#define OCI_FNCODE_LOBFLUSHBUFFER               DCI_FNCODE_LOBFLUSHBUFFER
#define OCI_FNCODE_LOBLOADFROMFILE              DCI_FNCODE_LOBLOADFROMFILE
#define OCI_FNCODE_LOBOPEN                      DCI_FNCODE_LOBOPEN
#define OCI_FNCODE_LOBCLOSE                     DCI_FNCODE_LOBCLOSE
#define OCI_FNCODE_LOBISOPEN                    DCI_FNCODE_LOBISOPEN
#define OCI_FNCODE_LOBFILEISOPEN                DCI_FNCODE_LOBFILEISOPEN
#define OCI_FNCODE_LOBFILEEXISTS                DCI_FNCODE_LOBFILEEXISTS
#define OCI_FNCODE_LOBFILECLOSEALL              DCI_FNCODE_LOBFILECLOSEALL
#define OCI_FNCODE_LOBCREATETEMP                DCI_FNCODE_LOBCREATETEMP
#define OCI_FNCODE_LOBFREETEMP                  DCI_FNCODE_LOBFREETEMP
#define OCI_FNCODE_LOBISTEMP                    DCI_FNCODE_LOBISTEMP
#define OCI_FNCODE_AQENQ                        DCI_FNCODE_AQENQ
#define OCI_FNCODE_AQDEQ                        DCI_FNCODE_AQDEQ
#define OCI_FNCODE_RESET                        DCI_FNCODE_RESET
#define OCI_FNCODE_SVCCTXTOLDA                  DCI_FNCODE_SVCCTXTOLDA
#define OCI_FNCODE_LOBLOCATORASSIGN             DCI_FNCODE_LOBLOCATORASSIGN
#define OCI_FNCODE_UBINDBYNAME                  DCI_FNCODE_UBINDBYNAME
#define OCI_FNCODE_AQLISTEN                     DCI_FNCODE_AQLISTEN
#define OCI_FNCODE_SVC2HST                      DCI_FNCODE_SVC2HST
#define OCI_FNCODE_SVCRH                        DCI_FNCODE_SVCRH
#define OCI_FNCODE_TRANSMULTIPREPARE            DCI_FNCODE_TRANSMULTIPREPARE
#define OCI_FNCODE_CPOOLCREATE                  DCI_FNCODE_CPOOLCREATE
#define OCI_FNCODE_CPOOLDESTROY                 DCI_FNCODE_CPOOLDESTROY
#define OCI_FNCODE_LOGON2                       DCI_FNCODE_LOGON2
#define OCI_FNCODE_ROWIDTOCHAR                  DCI_FNCODE_ROWIDTOCHAR
#define OCI_FNCODE_SPOOLCREATE                  DCI_FNCODE_SPOOLCREATE
#define OCI_FNCODE_SPOOLDESTROY                 DCI_FNCODE_SPOOLDESTROY
#define OCI_FNCODE_SESSIONGET                   DCI_FNCODE_SESSIONGET
#define OCI_FNCODE_SESSIONRELEASE               DCI_FNCODE_SESSIONRELEASE
#define OCI_FNCODE_STMTPREPARE2                 DCI_FNCODE_STMTPREPARE2
#define OCI_FNCODE_STMTRELEASE                  DCI_FNCODE_STMTRELEASE
#define OCI_FNCODE_AQENQARRAY                   DCI_FNCODE_AQENQARRAY
#define OCI_FNCODE_AQDEQARRAY                   DCI_FNCODE_AQDEQARRAY
#define OCI_FNCODE_LOBCOPY2                     DCI_FNCODE_LOBCOPY2
#define OCI_FNCODE_LOBERASE2                    DCI_FNCODE_LOBERASE2
#define OCI_FNCODE_LOBLENGTH2                   DCI_FNCODE_LOBLENGTH2
#define OCI_FNCODE_LOBLOADFROMFILE2             DCI_FNCODE_LOBLOADFROMFILE2
#define OCI_FNCODE_LOBREAD2                     DCI_FNCODE_LOBREAD2
#define OCI_FNCODE_LOBTRIM2                     DCI_FNCODE_LOBTRIM2
#define OCI_FNCODE_LOBWRITE2                    DCI_FNCODE_LOBWRITE2
#define OCI_FNCODE_LOBGETSTORAGELIMIT           DCI_FNCODE_LOBGETSTORAGELIMIT
#define OCI_FNCODE_MAXFCN                       DCI_FNCODE_MAXFCN

typedef DCIEnv                  OCIEnv;            /* OCI environment handle */
typedef DCIError                OCIError;                /* OCI error handle */
typedef DCISvcCtx               OCISvcCtx;             /* OCI service handle */
typedef DCIStmt                 OCIStmt;             /* OCI statement handle */
typedef DCIBind                 OCIBind;                  /* OCI bind handle */
typedef DCIDefine               OCIDefine;              /* OCI Define handle */
typedef DCIDescribe             OCIDescribe;          /* OCI Describe handle */
typedef DCIServer               OCIServer;              /* OCI Server handle */
typedef DCISession              OCISession;     /* OCI Authentication handle */
typedef DCIComplexObject        OCIComplexObject;          /* OCI COR handle */
typedef DCITrans                OCITrans;          /* OCI Transaction handle */
typedef DCISecurity             OCISecurity;          /* OCI Security handle */
typedef DCISubscription         OCISubscription;      /* subscription handle */ 

typedef DCICPool                OCICPool;          /* connection pool handle */
typedef DCISPool                OCISPool;             /* session pool handle */
typedef DCIAuthInfo             OCIAuthInfo;                  /* auth handle */
typedef DCIThreadMutex          OCIThreadMutex;
typedef DCIAdmin                OCIAdmin;

typedef DCIThreadKey            OCIThreadKey;
typedef DCIThreadHandle         OCIThreadHandle;

typedef DCIThreadId             OCIThreadId;
typedef DCIThreadKeyDestFunc    OCIThreadKeyDestFunc;

typedef DCISnapshot                 OCISnapshot;            /* OCI snapshot descriptor */
typedef DCIResult                   OCIResult;              /* OCI Result Set Descriptor */
typedef DCILobLocator               OCILobLocator;          /* OCI Lob Locator descriptor */
typedef DCIParam                    OCIParam;               /* OCI PARameter descriptor */

typedef DCIComplexObjectComp        OCIComplexObjectComp;

typedef DCIRowid                    OCIRowid;               /* OCI ROWID descriptor */

typedef DCIDateTime                 OCIDateTime;            /* OCI DateTime descriptor */
typedef DCIInterval                 OCIInterval;            /* OCI Interval descriptor */

typedef DCIUcb                      OCIUcb;                 /* OCI User Callback descriptor */
typedef DCIServerDNs                OCIServerDNs;           /* OCI server DN descriptor */

typedef DCIRaw                      OCIRaw;
typedef DCIString                   OCIString;

typedef DCIType                     OCIType;

typedef DCIColl                     OCIColl;
typedef DCIColl                     OCITable;

typedef DCIIter                     OCIIter;

enum OCIPinOpt
{
    /* 0 = uninitialized */
    OCI_PIN_DEFAULT = 1,                    /* default pin option */
    OCI_PIN_ANY     = 3,                    /* pin any copy of the object */
    OCI_PIN_RECENT  = 4,                    /* pin recent copy of the object */
    OCI_PIN_LATEST  = 5                     /* pin latest copy of the object */
};
typedef enum OCIPinOpt  OCIPinOpt;

typedef DCITypeCode                 OCITypeCode;

enum OCITypeGetOpt
{
    OCI_TYPEGET_HEADER,
    /* load only the header portion of the TDO when getting type */
    OCI_TYPEGET_ALL       /* load all attribute and method descriptors as well */
};

typedef DCIIOV OCIIOV;

typedef enum OCITypeGetOpt          OCITypeGetOpt;

typedef DCIObjectPropId             OCIObjectPropId;

typedef DCIRef                      OCIRef;

typedef DCIAQEnqOptions             OCIAQEnqOptions; /* AQ Enqueue Options hdl */
typedef DCIAQDeqOptions             OCIAQDeqOptions; /* AQ Dequeue Options hdl */
typedef DCIAQMsgProperties          OCIAQMsgProperties;  /* AQ Mesg Properties */
typedef DCIAQAgent                  OCIAQAgent;         /* AQ Agent descriptor */
typedef DCIAQNfyDescriptor          OCIAQNfyDescriptor;   /* AQ Nfy descriptor */
typedef DCIAQSignature              OCIAQSignature;            /* AQ Siganture */

typedef DCILobLocator               OCIClobLocator;    /* OCI Character LOB Locator */
typedef DCILobLocator               OCIBlobLocator;       /* OCI Binary LOB Locator */
typedef DCILobLocator               OCIBFileLocator; /* OCI Binary LOB File Locator */

#define OCI_INTHR_UNK               DCI_INTHR_UNK

#define OCI_ADJUST_UNK              DCI_ADJUST_UNK
#define OCI_ORACLE_DATE             DCI_ORACLE_DATE
#define OCI_ANSI_DATE               DCI_ANSI_DATE

typedef DCILobOffset                OCILobOffset;
typedef DCILobLength                OCILobLength;

enum OCILobMode
{
    OCI_LOBMODE_READONLY = 1,               /* read-only */
    OCI_LOBMODE_READWRITE = 2               /* read_write for internal lobs only */
};
typedef enum OCILobMode             OCILobMode;

enum OCILockOpt
{
    /* 0 = uninitialized */
    OCI_LOCK_NONE       = 1,        /* null (same as no lock) */
    OCI_LOCK_X          = 2,        /* exclusive lock */
    OCI_LOCK_X_NOWAIT   = 3         /* exclusive lock, do not wait  */
};
typedef enum OCILockOpt             OCILockOpt;

enum OCITypeEncap
{
    /* 0 = uninitialized */
    OCI_TYPEENCAP_PRIVATE,          /* private: only internally visible */
    OCI_TYPEENCAP_PUBLIC            /* public: visible to both internally and externally */
};
typedef enum OCITypeEncap           OCITypeEncap;

enum OCITypeParamMode
{
    /* PL/SQL starts this from 0 */
    OCI_TYPEPARAM_IN = 0,                                                /* in */
    OCI_TYPEPARAM_OUT,                                                  /* out */
    OCI_TYPEPARAM_INOUT,                                             /* in-out */
    OCI_TYPEPARAM_BYREF,              /* call by reference (implicitly in-out) */
    OCI_TYPEPARAM_OUTNCPY,                         /* OUT with NOCOPY modifier */
    OCI_TYPEPARAM_INOUTNCPY                     /* IN OUT with NOCOPY modifier */
};
typedef enum OCITypeParamMode       OCITypeParamMode;

#define OCI_ATTR_PURITY_DEFAULT         DCI_ATTR_PURITY_DEFAULT
#define OCI_ATTR_PURITY_NEW             DCI_ATTR_PURITY_NEW
#define OCI_ATTR_PURITY_SELF            DCI_ATTR_PURITY_SELF

typedef DCIDuration                     OCIDuration;

#define OCI_DURATION_INVALID            DCI_DURATION_INVALID
#define OCI_DURATION_BEGIN              DCI_DURATION_BEGIN
#define OCI_DURATION_NULL               DCI_DURATION_NULL
#define OCI_DURATION_DEFAULT            DCI_DURATION_DEFAULT
#define OCI_DURATION_USER_CALLBACK      DCI_DURATION_USER_CALLBACK
#define OCI_DURATION_NEXT               DCI_DURATION_NEXT
#define OCI_DURATION_SESSION            DCI_DURATION_SESSION
#define OCI_DURATION_TRANS              DCI_DURATION_TRANS

enum OCIRefreshOpt
{
    /* 0 = uninitialized */
    OCI_REFRESH_LOADED = 1        /* refresh objects loaded in the transaction */
};
typedef enum OCIRefreshOpt              OCIRefreshOpt; 

typedef DCIXMLType                      OCIXMLType;
typedef DCIDOMDocument                  OCIDOMDocument;
typedef DCIExtProcContext               OCIExtProcContext;

#define OCI_ONE_PIECE                   DCI_ONE_PIECE
#define OCI_FIRST_PIECE                 DCI_FIRST_PIECE
#define OCI_NEXT_PIECE                  DCI_NEXT_PIECE
#define OCI_LAST_PIECE                  DCI_LAST_PIECE

typedef DCIInd                          OCIInd;

#define OCI_IND_NOTNULL                 DCI_IND_NOTNULL
#define OCI_IND_NULL                    DCI_IND_NULL
#define OCI_IND_BADNULL                 DCI_IND_BADNULL
#define OCI_IND_NOTNULLABLE             DCI_IND_NOTNULLABLE

#define OCI_FILE_READONLY               DCI_FILE_READONLY

#define OCI_LOB_READONLY                DCI_LOB_READONLY
#define OCI_LOB_READWRITE               DCI_LOB_READWRITE
#define OCI_LOB_WRITEONLY               DCI_LOB_WRITEONLY
#define OCI_LOB_APPENDONLY              DCI_LOB_APPENDONLY
#define OCI_LOB_FULLOVERWRITE           DCI_LOB_FULLOVERWRITE
#define OCI_LOB_FULLREAD                DCI_LOB_FULLREAD

#define OCI_LOB_BUFFER_FREE             DCI_LOB_BUFFER_FREE
#define OCI_LOB_BUFFER_NOFREE           DCI_LOB_BUFFER_NOFREE

#define OCI_LOB_OPT_COMPRESS            DCI_LOB_OPT_COMPRESS
#define OCI_LOB_OPT_ENCRYPT             DCI_LOB_OPT_ENCRYPT
#define OCI_LOB_OPT_DEDUPLICATE         DCI_LOB_OPT_DEDUPLICATE
#define OCI_LOB_OPT_ALLOCSIZE           DCI_LOB_OPT_ALLOCSIZE
#define OCI_LOB_OPT_CONTENTTYPE         DCI_LOB_OPT_CONTENTTYPE
#define OCI_LOB_OPT_MODTIME             DCI_LOB_OPT_MODTIME

#define OCI_LOB_COMPRESS_OFF            DCI_LOB_COMPRESS_OFF
#define OCI_LOB_COMPRESS_ON             DCI_LOB_COMPRESS_ON

#define OCI_LOB_ENCRYPT_OFF             DCI_LOB_ENCRYPT_OFF
#define OCI_LOB_ENCRYPT_ON              DCI_LOB_ENCRYPT_ON

#define OCI_LOB_DEDUPLICATE_OFF         DCI_LOB_DEDUPLICATE_OFF
#define OCI_LOB_DEDUPLICATE_ON          DCI_LOB_DEDUPLICATE_ON

#define OCI_STMT_UNKNOWN                DCI_STMT_UNKNOWN
#define OCI_STMT_SELECT                 DCI_STMT_SELECT
#define OCI_STMT_UPDATE                 DCI_STMT_UPDATE
#define OCI_STMT_DELETE                 DCI_STMT_DELETE
#define OCI_STMT_INSERT                 DCI_STMT_INSERT
#define OCI_STMT_CREATE                 DCI_STMT_CREATE
#define OCI_STMT_DROP                   DCI_STMT_DROP
#define OCI_STMT_ALTER                  DCI_STMT_ALTER
#define OCI_STMT_BEGIN                  DCI_STMT_BEGIN
#define OCI_STMT_DECLARE                DCI_STMT_DECLARE
#define OCI_STMT_CALL                   DCI_STMT_CALL
#define OCI_STMT_MERGE                  DCI_STMT_MERGE

#define OCI_PTYPE_UNK                   DCI_PTYPE_UNK
#define OCI_PTYPE_TABLE                 DCI_PTYPE_TABLE
#define OCI_PTYPE_VIEW                  DCI_PTYPE_VIEW
#define OCI_PTYPE_PROC                  DCI_PTYPE_PROC
#define OCI_PTYPE_FUNC                  DCI_PTYPE_FUNC
#define OCI_PTYPE_PKG                   DCI_PTYPE_PKG
#define OCI_PTYPE_TYPE                  DCI_PTYPE_TYPE
#define OCI_PTYPE_SYN                   DCI_PTYPE_SYN
#define OCI_PTYPE_SEQ                   DCI_PTYPE_SEQ
#define OCI_PTYPE_COL                   DCI_PTYPE_COL
#define OCI_PTYPE_ARG                   DCI_PTYPE_ARG
#define OCI_PTYPE_LIST                  DCI_PTYPE_LIST
#define OCI_PTYPE_TYPE_ATTR             DCI_PTYPE_TYPE_ATTR
#define OCI_PTYPE_TYPE_COLL             DCI_PTYPE_TYPE_COLL
#define OCI_PTYPE_TYPE_METHOD           DCI_PTYPE_TYPE_METHOD
#define OCI_PTYPE_TYPE_ARG              DCI_PTYPE_TYPE_ARG
#define OCI_PTYPE_TYPE_RESULT           DCI_PTYPE_TYPE_RESULT
#define OCI_PTYPE_SCHEMA                DCI_PTYPE_SCHEMA
#define OCI_PTYPE_DATABASE              DCI_PTYPE_DATABASE
#define OCI_PTYPE_RULE                  DCI_PTYPE_RULE
#define OCI_PTYPE_RULE_SET              DCI_PTYPE_RULE_SET
#define OCI_PTYPE_EVALUATION_CONTEXT    DCI_PTYPE_EVALUATION_CONTEXT
#define OCI_PTYPE_TABLE_ALIAS           DCI_PTYPE_TABLE_ALIAS
#define OCI_PTYPE_VARIABLE_TYPE         DCI_PTYPE_VARIABLE_TYPE
#define OCI_PTYPE_NAME_VALUE            DCI_PTYPE_NAME_VALUE

#define OCI_LTYPE_UNK                   DCI_LTYPE_UNK
#define OCI_LTYPE_COLUMN                DCI_LTYPE_COLUMN
#define OCI_LTYPE_ARG_PROC              DCI_LTYPE_ARG_PROC
#define OCI_LTYPE_ARG_FUNC              DCI_LTYPE_ARG_FUNC
#define OCI_LTYPE_SUBPRG                DCI_LTYPE_SUBPRG
#define OCI_LTYPE_TYPE_ATTR             DCI_LTYPE_TYPE_ATTR
#define OCI_LTYPE_TYPE_METHOD           DCI_LTYPE_TYPE_METHOD
#define OCI_LTYPE_TYPE_ARG_PROC         DCI_LTYPE_TYPE_ARG_PROC
#define OCI_LTYPE_TYPE_ARG_FUNC         DCI_LTYPE_TYPE_ARG_FUNC
#define OCI_LTYPE_SCH_OBJ               DCI_LTYPE_SCH_OBJ
#define OCI_LTYPE_DB_SCH                DCI_LTYPE_DB_SCH
#define OCI_LTYPE_TYPE_SUBTYPE          DCI_LTYPE_TYPE_SUBTYPE
#define OCI_LTYPE_TABLE_ALIAS           DCI_LTYPE_TABLE_ALIAS
#define OCI_LTYPE_VARIABLE_TYPE         DCI_LTYPE_VARIABLE_TYPE
#define OCI_LTYPE_NAME_VALUE            DCI_LTYPE_NAME_VALUE

#define OCI_MEMORY_CLEARED              DCI_MEMORY_CLEARED

typedef DCIPicklerTdsCtx                OCIPicklerTdsCtx;
typedef DCIPicklerTds                   OCIPicklerTds;
typedef DCIPicklerImage                 OCIPicklerImage;
typedef DCIPicklerFdo                   OCIPicklerFdo;
typedef DCIPicklerTdsElement            OCIPicklerTdsElement;

typedef DCIAnyData                      OCIAnyData;
typedef DCIAnyDataSet                   OCIAnyDataSet;
typedef DCIAnyDataCtx                   OCIAnyDataCtx;

#define OCI_UCBTYPE_ENTRY               DCI_UCBTYPE_ENTRY
#define OCI_UCBTYPE_EXIT                DCI_UCBTYPE_EXIT
#define OCI_UCBTYPE_REPLACE             DCI_UCBTYPE_REPLACE

#define OCI_NLS_DAYNAME1                DCI_NLS_DAYNAME1
#define OCI_NLS_DAYNAME2                DCI_NLS_DAYNAME2
#define OCI_NLS_DAYNAME3                DCI_NLS_DAYNAME3
#define OCI_NLS_DAYNAME4                DCI_NLS_DAYNAME4
#define OCI_NLS_DAYNAME5                DCI_NLS_DAYNAME5
#define OCI_NLS_DAYNAME6                DCI_NLS_DAYNAME6
#define OCI_NLS_DAYNAME7                DCI_NLS_DAYNAME7
#define OCI_NLS_ABDAYNAME1              DCI_NLS_ABDAYNAME1
#define OCI_NLS_ABDAYNAME2              DCI_NLS_ABDAYNAME2
#define OCI_NLS_ABDAYNAME3              DCI_NLS_ABDAYNAME3
#define OCI_NLS_ABDAYNAME4              DCI_NLS_ABDAYNAME4
#define OCI_NLS_ABDAYNAME5              DCI_NLS_ABDAYNAME5
#define OCI_NLS_ABDAYNAME6              DCI_NLS_ABDAYNAME6
#define OCI_NLS_ABDAYNAME7              DCI_NLS_ABDAYNAME7
#define OCI_NLS_MONTHNAME1              DCI_NLS_MONTHNAME1
#define OCI_NLS_MONTHNAME2              DCI_NLS_MONTHNAME2
#define OCI_NLS_MONTHNAME3              DCI_NLS_MONTHNAME3
#define OCI_NLS_MONTHNAME4              DCI_NLS_MONTHNAME4
#define OCI_NLS_MONTHNAME5              DCI_NLS_MONTHNAME5
#define OCI_NLS_MONTHNAME6              DCI_NLS_MONTHNAME6
#define OCI_NLS_MONTHNAME7              DCI_NLS_MONTHNAME7
#define OCI_NLS_MONTHNAME8              DCI_NLS_MONTHNAME8
#define OCI_NLS_MONTHNAME9              DCI_NLS_MONTHNAME9
#define OCI_NLS_MONTHNAME10             DCI_NLS_MONTHNAME10
#define OCI_NLS_MONTHNAME11             DCI_NLS_MONTHNAME11
#define OCI_NLS_MONTHNAME12             DCI_NLS_MONTHNAME12
#define OCI_NLS_ABMONTHNAME1            DCI_NLS_ABMONTHNAME1
#define OCI_NLS_ABMONTHNAME2            DCI_NLS_ABMONTHNAME2
#define OCI_NLS_ABMONTHNAME3            DCI_NLS_ABMONTHNAME3
#define OCI_NLS_ABMONTHNAME4            DCI_NLS_ABMONTHNAME4
#define OCI_NLS_ABMONTHNAME5            DCI_NLS_ABMONTHNAME5
#define OCI_NLS_ABMONTHNAME6            DCI_NLS_ABMONTHNAME6
#define OCI_NLS_ABMONTHNAME7            DCI_NLS_ABMONTHNAME7
#define OCI_NLS_ABMONTHNAME8            DCI_NLS_ABMONTHNAME8
#define OCI_NLS_ABMONTHNAME9            DCI_NLS_ABMONTHNAME9
#define OCI_NLS_ABMONTHNAME10           DCI_NLS_ABMONTHNAME10
#define OCI_NLS_ABMONTHNAME11           DCI_NLS_ABMONTHNAME11
#define OCI_NLS_ABMONTHNAME12           DCI_NLS_ABMONTHNAME12
#define OCI_NLS_YES                     DCI_NLS_YES
#define OCI_NLS_NO                      DCI_NLS_NO
#define OCI_NLS_AM                      DCI_NLS_AM
#define OCI_NLS_PM                      DCI_NLS_PM
#define OCI_NLS_AD                      DCI_NLS_AD
#define OCI_NLS_BC                      DCI_NLS_BC
#define OCI_NLS_DECIMAL                 DCI_NLS_DECIMAL
#define OCI_NLS_GROUP                   DCI_NLS_GROUP
#define OCI_NLS_DEBIT                   DCI_NLS_DEBIT
#define OCI_NLS_CREDIT                  DCI_NLS_CREDIT
#define OCI_NLS_DATEFORMAT              DCI_NLS_DATEFORMAT
#define OCI_NLS_INT_CURRENCY            DCI_NLS_INT_CURRENCY
#define OCI_NLS_LOC_CURRENCY            DCI_NLS_LOC_CURRENCY
#define OCI_NLS_LANGUAGE                DCI_NLS_LANGUAGE
#define OCI_NLS_ABLANGUAGE              DCI_NLS_ABLANGUAGE
#define OCI_NLS_TERRITORY               DCI_NLS_TERRITORY
#define OCI_NLS_CHARACTER_SET           DCI_NLS_CHARACTER_SET
#define OCI_NLS_LINGUISTIC_NAME         DCI_NLS_LINGUISTIC_NAME
#define OCI_NLS_CALENDAR                DCI_NLS_CALENDAR
#define OCI_NLS_DUAL_CURRENCY           DCI_NLS_DUAL_CURRENCY
#define OCI_NLS_WRITINGDIR              DCI_NLS_WRITINGDIR
#define OCI_NLS_ABTERRITORY             DCI_NLS_ABTERRITORY
#define OCI_NLS_DDATEFORMAT             DCI_NLS_DDATEFORMAT
#define OCI_NLS_DTIMEFORMAT             DCI_NLS_DTIMEFORMAT
#define OCI_NLS_SFDATEFORMAT            DCI_NLS_SFDATEFORMAT
#define OCI_NLS_SFTIMEFORMAT            DCI_NLS_SFTIMEFORMAT
#define OCI_NLS_NUMGROUPING             DCI_NLS_NUMGROUPING
#define OCI_NLS_LISTSEP                 DCI_NLS_LISTSEP
#define OCI_NLS_MONDECIMAL              DCI_NLS_MONDECIMAL
#define OCI_NLS_MONGROUP                DCI_NLS_MONGROUP
#define OCI_NLS_MONGROUPING             DCI_NLS_MONGROUPING
#define OCI_NLS_INT_CURRENCYSEP         DCI_NLS_INT_CURRENCYSEP
#define OCI_NLS_CHARSET_MAXBYTESZ       DCI_NLS_CHARSET_MAXBYTESZ
#define OCI_NLS_CHARSET_FIXEDWIDTH      DCI_NLS_CHARSET_FIXEDWIDTH
#define OCI_NLS_CHARSET_ID              DCI_NLS_CHARSET_ID
#define OCI_NLS_NCHARSET_ID             DCI_NLS_NCHARSET_ID
#define OCI_NLS_MAXBUFSZ                DCI_NLS_MAXBUFSZ

#define OCI_NLS_BINARY                  DCI_NLS_BINARY
#define OCI_NLS_LINGUISTIC              DCI_NLS_LINGUISTIC
#define OCI_NLS_CASE_INSENSITIVE        DCI_NLS_CASE_INSENSITIVE

#define OCI_NLS_UPPERCASE               DCI_NLS_UPPERCASE
#define OCI_NLS_LOWERCASE               DCI_NLS_LOWERCASE

#define OCI_NLS_CS_IANA_TO_ORA          DCI_NLS_CS_IANA_TO_ORA
#define OCI_NLS_CS_ORA_TO_IANA          DCI_NLS_CS_ORA_TO_IANA
#define OCI_NLS_LANG_ISO_TO_ORA         DCI_NLS_LANG_ISO_TO_ORA
#define OCI_NLS_LANG_ORA_TO_ISO         DCI_NLS_LANG_ORA_TO_ISO
#define OCI_NLS_TERR_ISO_TO_ORA         DCI_NLS_TERR_ISO_TO_ORA
#define OCI_NLS_TERR_ORA_TO_ISO         DCI_NLS_TERR_ORA_TO_ISO
#define OCI_NLS_TERR_ISO3_TO_ORA        DCI_NLS_TERR_ISO3_TO_ORA
#define OCI_NLS_TERR_ORA_TO_ISO3        DCI_NLS_TERR_ORA_TO_ISO3

typedef DCIMsg                          OCIMsg;
typedef DCIWchar                        OCIWchar;

#define OCI_XMLTYPE_CREATE_OCISTRING    DCI_XMLTYPE_CREATE_OCISTRING
#define OCI_XMLTYPE_CREATE_CLOB         DCI_XMLTYPE_CREATE_CLOB
#define OCI_XMLTYPE_CREATE_BLOB         DCI_XMLTYPE_CREATE_BLOB

#define OCI_KERBCRED_PROXY              DCI_KERBCRED_PROXY
#define OCI_KERBCRED_CLIENT_IDENTIFIER  DCI_KERBCRED_CLIENT_IDENTIFIER

typedef DCITime         OCITime;
typedef DCIDate         OCIDate;

// #define OCIDateGetTime(date, hour, min, sec) \
// { \
//     *hour = (date)->OCIDateTime.OCITimeHH; \
//     *min = (date)->OCIDateTime.OCITimeMI; \
//     *sec = (date)->OCIDateTime.OCITimeSS; \
// }
// #define DCIDateGetTime(date, hour, min, sec) \
// { \
//     *hour = (date)->OCIDateTime.OCITimeHH; \
//     *min = (date)->OCIDateTime.OCITimeMI; \
//     *sec = (date)->OCIDateTime.OCITimeSS; \
// }
/*
   NAME: OCIDateGetTime - OCIDate Get Time portion of date
   PARAMETERS:
  	date (IN) - Oracle date whose time data is retrieved
	hour (OUT) - hour value returned
	min (OUT) - minute value returned
	sec (OUT) - second value returned
   DESCRIPTION:
  	Return time inforamtion stored in the given date. The time
	information returned is: hour, minute and seconds.
   RETURNS:
        NONE
 */

/*--------------------------- OCIDateGetDate --------------------------------*/
// #define OCIDateGetDate(date, year, month, day) \
// { \
//     *year = (date)->OCIDateYYYY; \
//     *month = (date)->OCIDateMM; \
//     *day = (date)->OCIDateDD; \
// }
// #define DCIDateGetDate(date, year, month, day) \
// { \
//     *year = (date)->OCIDateYYYY; \
//     *month = (date)->OCIDateMM; \
//     *day = (date)->OCIDateDD; \
// }
/*
   NAME: OCIDateGetDate - OCIDate Get Date (year, month, day) portion of date
   PARAMETERS:
  	date (IN) - Oracle date whose year, month, day data is retrieved
	year (OUT) - year value returned
	month (OUT) - month value returned
	day (OUT) - day value returned
   DESCRIPTION:
  	Return year, month, day inforamtion stored in the given date.
   RETURNS:
        NONE
 */

/*--------------------------- OCIDateSetTime --------------------------------*/
// #define OCIDateSetTime(date, hour, min, sec) \
// { \
//     (date)->OCIDateTime.OCITimeHH = hour; \
//     (date)->OCIDateTime.OCITimeMI = min; \
//     (date)->OCIDateTime.OCITimeSS = sec; \
// }
// #define DCIDateSetTime(date, hour, min, sec) \
// { \
//     (date)->OCIDateTime.OCITimeHH = hour; \
//     (date)->OCIDateTime.OCITimeMI = min; \
//     (date)->OCIDateTime.OCITimeSS = sec; \
// }
/*
   NAME: OCIDateSetTime - OCIDate Set Time portion of date
   PARAMETERS:
  	date (OUT) - Oracle date whose time data is set
	hour (IN) - hour value to be set 
	min (IN) - minute value to be set
	sec (IN) - second value to be set
   DESCRIPTION:
  	Set the date with the given time inforamtion.
   RETURNS:
        NONE
 */

/*--------------------------- OCIDateSetDate --------------------------------*/
// #define OCIDateSetDate(date, year, month, day) \
// { \
//     (date)->OCIDateYYYY = year; \
//     (date)->OCIDateMM = month; \
//     (date)->OCIDateDD = day; \
// }
// #define DCIDateSetDate(date, year, month, day) \
// { \
//     (date)->OCIDateYYYY = year; \
//     (date)->OCIDateMM = month; \
//     (date)->OCIDateDD = day; \
// }
/* see ociap.h or ocikp.h */

typedef DCda_Def            Cda_Def;
typedef DLda_Def            Lda_Def;

#define OCI_DIRPATH_INDEX_MAINT_SKIP_UNUSABLE           DCI_DIRPATH_INDEX_MAINT_SKIP_UNUSABLE
#define OCI_DIRPATH_INDEX_MAINT_DONT_SKIP_UNUSABLE      DCI_DIRPATH_INDEX_MAINT_DONT_SKIP_UNUSABLE
#define OCI_DIRPATH_INDEX_MAINT_SKIP_ALL                DCI_DIRPATH_INDEX_MAINT_SKIP_ALL

#define OCI_DIRPATH_NORMAL                              DCI_DIRPATH_NORMAL
#define OCI_DIRPATH_PARTIAL                             DCI_DIRPATH_PARTIAL
#define OCI_DIRPATH_NOT_PREPARED                        DCI_DIRPATH_NOT_PREPARED

#define OCI_DIRPATH_COL_COMPLETE                        DCI_DIRPATH_COL_COMPLETE
#define OCI_DIRPATH_COL_NULL                            DCI_DIRPATH_COL_NULL
#define OCI_DIRPATH_COL_PARTIAL                         DCI_DIRPATH_COL_PARTIAL
#define OCI_DIRPATH_COL_ERROR                           DCI_DIRPATH_COL_ERROR

#define OCI_DIRPATH_DATASAVE_SAVEONLY                   DCI_DIRPATH_DATASAVE_SAVEONLY
#define OCI_DIRPATH_DATASAVE_FINISH                     DCI_DIRPATH_DATASAVE_FINISH
#define OCI_DIRPATH_DATASAVE_PARTIAL                    DCI_DIRPATH_DATASAVE_PARTIAL

#define OCI_DIRPATH_EXPR_OBJ_CONSTR                     DCI_DIRPATH_EXPR_OBJ_CONSTR
#define OCI_DIRPATH_EXPR_SQL                            DCI_DIRPATH_EXPR_SQL
#define OCI_DIRPATH_EXPR_REF_TBLNAME                    DCI_DIRPATH_EXPR_REF_TBLNAME

#define OCI_DATE_INVALID_DAY                            DCI_DATE_INVALID_DAY
#define OCI_DATE_DAY_BELOW_VALID                        DCI_DATE_DAY_BELOW_VALID
#define OCI_DATE_INVALID_MONTH                          DCI_DATE_INVALID_MONTH
#define OCI_DATE_MONTH_BELOW_VALID                      DCI_DATE_MONTH_BELOW_VALID
#define OCI_DATE_INVALID_YEAR                           DCI_DATE_INVALID_YEAR
#define OCI_DATE_YEAR_BELOW_VALID                       DCI_DATE_YEAR_BELOW_VALID
#define OCI_DATE_INVALID_HOUR                           DCI_DATE_INVALID_HOUR
#define OCI_DATE_HOUR_BELOW_VALID                       DCI_DATE_HOUR_BELOW_VALID
#define OCI_DATE_INVALID_MINUTE                         DCI_DATE_INVALID_MINUTE
#define OCI_DATE_MINUTE_BELOW_VALID                     DCI_DATE_MINUTE_BELOW_VALID
#define OCI_DATE_INVALID_SECOND                         DCI_DATE_INVALID_SECOND
#define OCI_DATE_SECOND_BELOW_VALID                     DCI_DATE_SECOND_BELOW_VALID
#define OCI_DATE_DAY_MISSING_FROM_1582                  DCI_DATE_DAY_MISSING_FROM_1582
#define OCI_DATE_YEAR_ZERO                              DCI_DATE_YEAR_ZERO
#define OCI_DATE_INVALID_FORMAT                         DCI_DATE_INVALID_FORMAT

typedef DCIDirPathCtx                       OCIDirPathCtx;                  /* context */
typedef DCIDirPathFuncCtx                   OCIDirPathFuncCtx;     /* function context */
typedef DCIDirPathColArray                  OCIDirPathColArray;        /* column array */
typedef DCIDirPathStream                    OCIDirPathStream;                /* stream */
typedef DCIDirPathDesc                      OCIDirPathDesc;  /* direct path descriptor */

typedef DCICallbackInBind                   OCICallbackInBind;
typedef DCICallbackOutBind                  OCICallbackOutBind;
typedef DCICallbackDefine                   OCICallbackDefine;

#define OCI_NUMBER_SIZE                     DCI_NUMBER_SIZE
typedef DCINumber                           OCINumber;
#endif      //OCI_EXPORT

DCI_API
DCIEnv*
#ifdef OCI_EXPORT
xaoEnv(
#else
DxaoEnv(
#endif  //OCI_EXPORT
    DmText*                 dbname
);

DCI_API
DCISvcCtx*
#ifdef OCI_EXPORT
xaoSvcCtx(
#else
DxaoSvcCtx(
#endif  //OCI_EXPORT
    DmText*                 dbname
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIInitialize(
#else
DCIInitialize(
#endif // OCI_EXPORT
    dub4                    mode,
    dvoid*                  ctxp,
    dvoid*                  (*malocfp)(dvoid *ctxp, size_t size),
    dvoid*                  (*ralocfp)(dvoid *ctxp, dvoid *memptr, size_t newsize),
    void                    (*mfreefp)(dvoid *ctxp, dvoid *memptr)
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIEnvInit(
#else
DCIEnvInit(
#endif // OCI_EXPORT
    DCIEnv**                envp,
    dub4                    mode,
    size_t                  xtramem_sz,
    dvoid**                 usrmempp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIEnvCreate(
#else
DCIEnvCreate(
#endif // OCI_EXPORT
    DCIEnv**                envhpp,
    dub4                    mode,
    const void*             ctxp,
    const void*             (*malocfp) (dvoid *ctxp, size_t size),
    const void*             (*ralocfp) (dvoid *ctxp, dvoid *memptr, size_t newsize),
    const void              (*mfreefp) (dvoid *ctxp, dvoid *memptr),
    size_t                  xtramemsz,
    dvoid**                 usrmempp
);

DCI_API 
dsword  
#ifdef OCI_EXPORT
OCIEnvNlsCreate(
#else
DCIEnvNlsCreate(
#endif // OCI_EXPORT
    DCIEnv**                envhpp,
    dub4                    mode,
    void*                   ctxp,
    void*                   (*malocfp)(void  *ctxp, size_t size),
    void*                   (*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
    void                    (*mfreefp)(void  *ctxp, void  *memptr),
    size_t                  xtramemsz,
    void**                  usrmempp,
    dub2                    charset,
    dub2                    ncharset
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIHandleAlloc(
#else
DCIHandleAlloc(
#endif // OCI_EXPORT
    dvoid*                  parenth,
    dvoid**                 hndlpp,
    CONST dub4              type, 
    CONST size_t            xtramem_sz,
    dvoid**                 usrmempp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIHandleFree(
#else
DCIHandleFree(
#endif // OCI_EXPORT
    dvoid*                  hndlp,
    CONST dub4              type
);

DCI_API dsword
#ifdef OCI_EXPORT
OCISessionBegin(
#else
DCISessionBegin(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCISession*             usrhp,
    dub4                    credt,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIServerAttach(
#else
DCIServerAttach(
#endif // OCI_EXPORT
    DCIServer*              srvhp,
    DCIError*               errhp,
    CONST DmText*           dblink,
    dsb4                    dblink_len,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIStmtPrepare(
#else
DCIStmtPrepare(
#endif // OCI_EXPORT
    DCIStmt*                stmtp,
    DCIError*               errhp,
    DmText*                 stmt,
    dub4                    stmt_len,
    dub4                    language,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIStmtGetPieceInfo(
#else
DCIStmtGetPieceInfo(
#endif // OCI_EXPORT
    DCIStmt*                stmtp,
    DCIError*               errhp,
    dvoid**                 hndlpp,
    dub4*                   typep,
    dub1*                   in_outp,
    dub4*                   iterp,
    dub4*                   idxp,
    dub1*                   piecep
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIStmtSetPieceInfo(
#else
DCIStmtSetPieceInfo(
#endif // OCI_EXPORT
    dvoid*                  hndlp,
    dub4                    type,
    DCIError*               errhp,
    CONST dvoid*            bufp,
    dub4*                   alenp,
    dub1                    piece,
    CONST dvoid*            indp,
    dub2*                   rcodep
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIStmtExecute(
#else
DCIStmtExecute(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIStmt*                stmtp,
    DCIError*               errhp,
    dub4                    iters,
    dub4                    rowoff,
    CONST DCISnapshot*      snap_in,
    DCISnapshot*            snap_out,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIStmtFetch(
#else
DCIStmtFetch(
#endif // OCI_EXPORT
    DCIStmt*                stmtp,
    DCIError*               errhp,
    dub4                    nrows,
    dub2                    orientation,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDefineByPos(
#else
DCIDefineByPos(
#endif // OCI_EXPORT
    DCIStmt*                stmtp,
    DCIDefine**             defnp,
    DCIError*               errhp,
    dub4                    position,
    dvoid*                  valuep,
    dsb4                    value_sz,
    dub2                    dty,
    dvoid*                  indp,
    dub2*                   rlenp,
    dub2*                   rcodep,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIErrorGet(
#else
DCIErrorGet(
#endif // OCI_EXPORT
    dvoid*                  hndlp,
    dub4                    recordno,
    DmText*                 sqlstate,
    dsb4*                   errcodep,
    DmText*                 bufp,
    dub4                    bufsiz,
    dub4                    type
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIBindByPos(
#else
DCIBindByPos(
#endif // OCI_EXPORT
    DCIStmt*                stmtp,
    DCIBind**               bindp,
    DCIError*               errhp,
    dub4                    position,
    dvoid*                  valuep,
    dsb4                    value_sz,
    dub2                    dty,
    dvoid*                  indp,
    dub2*                   alenp,
    dub2*                   rcodep,
    dub4                    maxarr_len,
    dub4*                   curelep,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIBindByName(
#else
DCIBindByName(
#endif // OCI_EXPORT
    DCIStmt*                stmtp,
    DCIBind**               bindp,
    DCIError*               errhp,
    CONST DmText*           placeholder,
    dsb4                    placeh_len,
    dvoid*                  valuep,
    dsb4                    value_sz,
    dub2                    dty,
    dvoid*                  indp,
    dub2*                   alenp,
    dub2*                   rcodep,
    dub4                    maxarr_len,
    dub4*                   curelep,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIBindDynamic(
#else
DCIBindDynamic(
#endif // OCI_EXPORT
    DCIBind*                bindp,
    DCIError*               errhp,
    void*                   ictxp,
    DCICallbackInBind       icbfp,
    dvoid*                  octxp,
    DCICallbackOutBind      ocbfp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILogon(
#else
DCILogon(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    DCISvcCtx**             svchp,
    CONST DmText*           username,
    dub4                    uname_len,
    CONST DmText*           password,
    dub4                    passwd_len,
    CONST DmText*           dbname,
    dub4                    dbname_len
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILogoff(
#else
DCILogoff(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIPasswordChange(
#else
DCIPasswordChange(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    CONST DmText*           user_name,
    dub4                    usernm_len,
    CONST DmText*           opasswd,
    dub4                    opasswd_len,
    CONST DmText*           npasswd,
    dub4                    npasswd_len,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCITransStart(
#else
DCITransStart(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    duword                  timeout,
    dub4                    flags
);

DCI_API dsword
#ifdef OCI_EXPORT
OCITransCommit(
#else
DCITransCommit(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    dub4                    flags
);

DCI_API dsword
#ifdef OCI_EXPORT
OCITransRollback(
#else
DCITransRollback(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    dub4                    flags
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIServerDetach(
#else
DCIServerDetach(
#endif // OCI_EXPORT
    DCIServer*              srvhp,
    DCIError*               errhp,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCISessionEnd(
#else
DCISessionEnd(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCISession*             usrhp,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIAttrGet(
#else
DCIAttrGet(
#endif // OCI_EXPORT
    CONST dvoid*            trgthndlp,
    dub4                    trghndltyp,
    dvoid*                  attributep,
    dub4*                   sizep,
    dub4                    attrtype,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIAttrSet(
#else
DCIAttrSet(
#endif // OCI_EXPORT
    dvoid*                  trgthndlp,
    dub4                    trghndltyp,
    dvoid*                  attributep,
    dub4                    size,
    dub4                    attrtype,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIParamGet(
#else
DCIParamGet(
#endif // OCI_EXPORT
    CONST dvoid*            hndlp,
    dub4                    htype,
    DCIError*               errhp, 
    dvoid**                 parmdpp,
    dub4                    pos
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIParamSet(
#else
DCIParamSet(
#endif // OCI_EXPORT
    dvoid*                  hdlp,
    dub4                    htyp,
    DCIError*               errhp,
    CONST dvoid*            dscp,
    dub4                    dtyp,
    dub4                    pos
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDescribeAny(
#else
DCIDescribeAny(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    dvoid*                  objptr,
    dub4                    objnm_len,
    dub1                    objptr_typ,
    dub1                    info_level,
    dub1                    objtyp,
    DCIDescribe*            dschp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIBindArrayOfStruct(
#else
DCIBindArrayOfStruct(
#endif // OCI_EXPORT
    DCIBind*                bindp,
    DCIError*               errhp,
    dub4                    pvskip,
    dub4                    indskip,
    dub4                    alskip,
    dub4                    rcskip
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDefineArrayOfStruct(
#else
DCIDefineArrayOfStruct(
#endif // OCI_EXPORT
    DCIDefine*              defnp,
    DCIError*               errhp,
    dub4                    pvskip,
    dub4                    indskip,
    dub4                    rlskip,
    dub4                    rcskip
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDescriptorAlloc(
#else
DCIDescriptorAlloc(
#endif // OCI_EXPORT
    CONST dvoid*            parenth,
    dvoid**                 descpp, 
    CONST dub4              type,
    CONST size_t            xtramem_sz, 
    dvoid**                 usrmempp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDescriptorFree(
#else
DCIDescriptorFree(
#endif // OCI_EXPORT
    dvoid*                  descp,
    CONST dub4              type
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILobWrite(
#else
DCILobWrite(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4*                   amtp,
    dub4                    offset,
    dvoid*                  bufp,
    dub4                    buflen, 
    dub1                    piece,
    dvoid*                  ctxp, 
    dsb4                    (*cbfp)(dvoid *ctxp, dvoid* bufp, dub4* len, dub1* piece),
    dub2                    csid,
    dub1                    csfrm
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIBreak(
#else
DCIBreak(
#endif // OCI_EXPORT
    dvoid*                  hndlp,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIReset(
#else
DCIReset(
#endif // OCI_EXPORT
    dvoid*                  hndlp,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILobGetLength(
#else
DCILobGetLength(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4*                   lenp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILobRead(
#else
DCILobRead(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4*                   amtp,
    dub4                    offset,
    dvoid*                  bufp,
    dub4                    bufl, 
    dvoid*                  ctxp,
    dsb4                    (*cbfp)(dvoid* ctxp, CONST dvoid* bufp, dub4 len, dub1 piece),
    dub2                    csid,
    dub1                    csfrm
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobRead2(
#else
DCILobRead2(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dmub8*                  byte_amtp,
    dmub8*                  char_amtp,
    dmub8                   offset,
    void*                   bufp,
    dmub8                   bufl,
    dub1                    piece,
    void*                   ctxp, 
    dsb4                    (*cbfp)(void* ctxp, const void* bufp, dmub8 lenp, dub1 piecep, void** changed_bufpp, dmub8* changed_lenp),
    dub2                    csid,
    dub1                    csfrm
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIStmtFetch2(
#else
DCIStmtFetch2(
#endif // OCI_EXPORT
    DCIStmt*                stmtp,
    DCIError*               errhp,
    dub4                    nrows,
    dub2                    orientation,
    dsb4                    scrollOffset,
    dub4                    mode
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathPrepare(
#else
DCIDirPathPrepare(
#endif // OCI_EXPORT
    DCIDirPathCtx*          dpctx,
    DCISvcCtx*              svchp,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathColArrayReset(
#else
DCIDirPathColArrayReset(
#endif // OCI_EXPORT
    DCIDirPathColArray*     dpca,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathStreamReset(
#else
DCIDirPathStreamReset(
#endif // OCI_EXPORT
    DCIDirPathStream*       dpstr,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathColArrayEntrySet(
#else
DCIDirPathColArrayEntrySet(
#endif // OCI_EXPORT
    DCIDirPathColArray*     dpca,
    DCIError*               errhp,
    dub4                    rownum,
    dub2                    colIdx,
    dub1*                   cvalp,
    dub4                    clen,
    dub1                    cflg
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathColArrayEntryGet(
#else
DCIDirPathColArrayEntryGet(
#endif // OCI_EXPORT
    DCIDirPathColArray*     dpca,
    DCIError*               errhp,
    dub4                    rownum,
    dub2                    colIdx,
    dub1**                  cvalpp,
    dub4*                   clenp,
    dub1*                   cflgp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathDataSave(
#else
DCIDirPathDataSave(
#endif // OCI_EXPORT 
    DCIDirPathCtx*          dpctx,
    DCIError*               errhp,
    dub4                    action
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathColArrayToStream(
#else
DCIDirPathColArrayToStream(
#endif // OCI_EXPORT
    DCIDirPathColArray*     dpca,
    DCIDirPathCtx*          dpctx,
    DCIDirPathStream*       dpstr,
    DCIError*               errhp,
    dub4                    rowcnt,
    dub4                    rowoff
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathFinish(
#else
DCIDirPathFinish(
#endif // OCI_EXPORT
    DCIDirPathCtx*          dpctx,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathLoadStream(
#else
DCIDirPathLoadStream(
#endif // OCI_EXPORT
    DCIDirPathCtx*          dpctx,
    DCIDirPathStream*       dpstr,
    DCIError*               errhp
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathFlushRow(
#else
DCIDirPathFlushRow(
#endif // OCI_EXPORT 
    DCIDirPathCtx*          dpctx,
    DCIError*               errhp 
);

DCI_API dsword
#ifdef OCI_EXPORT
OCIDirPathAbort(
#else
DCIDirPathAbort(
#endif // OCI_EXPORT
    DCIDirPathCtx*          dpctx,
    DCIError*               errhp 
);

/* interval */
/*--------------------begin--------------------*/
DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalAdd(
#else
DCIIntervalAdd(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIInterval*            addend1,
    DCIInterval*            addend2,
    DCIInterval*            result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIIntervalAssign(
#else
DCIIntervalAssign(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    CONST DCIInterval*      ininter,
    DCIInterval*            outinter
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalCheck(
#else
DCIIntervalCheck(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    CONST DCIInterval*      interval,
    dub4*                   valid
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalCompare(
#else
DCIIntervalCompare(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIInterval*            inter1,
    DCIInterval*            inter2,
    dsword*                 result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalDivide(
#else
DCIIntervalDivide(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIInterval*            dividend, 
    DCINumber*              divisor,
    DCIInterval*            result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalFromNumber(
#else
DCIIntervalFromNumber(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIInterval*            inter,
    DCINumber*              number
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalFromText(
#else
DCIIntervalFromText(
#endif // OCI_EXPORT 
    dvoid*                  hndl,
    DCIError*               err,
    CONST DmText*           inpstr,
    size_t                  str_len,
    DCIInterval*            result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIIntervalFromTZ(
#else
DCIIntervalFromTZ(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    CONST dmtext*           inpstring,
    size_t                  str_len,
    DCIInterval*            result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIIntervalGetDaySecond(
#else
DCIIntervalGetDaySecond(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    dsb4*                   dy,
    dsb4*                   hr,
    dsb4*                   mm,
    dsb4*                   ss,
    dsb4*                   fsec,
    CONST DCIInterval*      result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIIntervalGetYearMonth(
#else
DCIIntervalGetYearMonth(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    dsb4*                   yr,
    dsb4*                   mnth,
    CONST DCIInterval*      result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalMultiply(
#else
DCIIntervalMultiply(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    CONST DCIInterval*      inter,
    DCINumber*              nfactor,
    DCIInterval*            result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalSetDaySecond(
#else
DCIIntervalSetDaySecond(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    dsb4                    dy,
    dsb4                    hr,
    dsb4                    mm,
    dsb4                    ss,
    dsb4                    fsec,
    DCIInterval*            result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalSetYearMonth(
#else
DCIIntervalSetYearMonth(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    dsb4                    yr,
    dsb4                    mnth,
    DCIInterval*            result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalSubtract(
#else
DCIIntervalSubtract(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIInterval*            minuend, 
    DCIInterval*            subtrahend,
    DCIInterval*            result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalToNumber(
#else
DCIIntervalToNumber(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    CONST DCIInterval*      inter,
    DCINumber*              number
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIIntervalToText(
#else
DCIIntervalToText(
#endif // OCI_EXPORT 
    dvoid*                  hndl,
    DCIError*               err,
    CONST DCIInterval*      inter,
    dub1                    lfprec,
    dub1                    fsprec,
    DmText*                 buffer,
    size_t                  buflen,
    size_t*                 resultlen
);

DCI_API dsword   
#ifdef OCI_EXPORT
OCILobFileCloseAll(
#else
DCILobFileCloseAll(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp
);

DCI_API dsword 
#ifdef OCI_EXPORT
OCIServerVersion(
#else
DCIServerVersion(
#endif // OCI_EXPORT
    dvoid*                  hndlp,
    DCIError*               errhp,
    DmText*                 bufp,
    dub4                    bufsz,
    dub1                    hndltype
);

DCI_API dsword 
#ifdef OCI_EXPORT
OCILobLocatorIsInit(
#else
DCILobLocatorIsInit(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    CONST DCILobLocator*    locp,
    boolean*                is_initialized
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILobTrim(
#else
DCILobTrim(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4                    newlen
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILobAssign(
#else
DCILobAssign(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    CONST DCILobLocator*    src_locp,
    DCILobLocator**         dst_locpp
);

DCI_API 
dsword
#ifdef OCI_EXPORT
OCILobCharSetForm(
#else
DCILobCharSetForm(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    const DCILobLocator*    locp,
    dub1*                   csfrm
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCILobIsEqual(
#else
DCILobIsEqual(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    const DCILobLocator*    x,
    const DCILobLocator*    y,
    boolean*                is_equal
);

DCI_API dsword
#ifdef OCI_EXPORT
OCILobFileGetName(
#else
DCILobFileGetName(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    CONST DCILobLocator*    filep,
    DmText*                 dir_alias,
    dub2*                   d_length,
    DmText*                 filename,
    dub2*                   f_length
);

DCI_API dsword   
#ifdef OCI_EXPORT
OCILobFileSetName(
#else
DCILobFileSetName(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    DCILobLocator**         filepp,
    CONST DmText*           dir_alias,
    dub2                    d_length,
    CONST DmText*           filename,
    dub2                    f_length
);

DCI_API dsword  
#ifdef OCI_EXPORT
OCILobFileExists(
#else
DCILobFileExists(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          filep,
    boolean*                flag
);

DCI_API dsword 
#ifdef OCI_EXPORT
OCINumberAssign(
#else
DCINumberAssign(
#endif // OCI_EXPORT
    DCIError*               err,
    CONST DCINumber*        from,
    DCINumber*              to
);

DCI_API dsword 
#ifdef OCI_EXPORT
OCINumberFromReal( 
#else
DCINumberFromReal(
#endif // OCI_EXPORT
    DCIError*               err,
    CONST dvoid*            rnum,
    duword                  rnum_length,
    DCINumber*              number
);

DCI_API dsword
#ifdef OCI_EXPORT
OCINumberFromInt(
#else
DCINumberFromInt(
#endif // OCI_EXPORT
    DCIError*               err,
    CONST dvoid*            inum,
    duword                  inum_length,
    duword                  inum_s_flag,
    DCINumber*              number
);

DCI_API dsword
#ifdef OCI_EXPORT
OCINumberFromText( 
#else
DCINumberFromText(
#endif // OCI_EXPORT
    DCIError*               err,
    CONST dmtext*           str,
    dub4                    str_length,
    CONST dmtext*           fmt,
    dub4                    fmt_length,
    CONST dmtext*           nls_params,
    dub4                    nls_p_length,
    DCINumber*              number
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberToInt( 
#else
DCINumberToInt(
#endif // OCI_EXPORT
    DCIError*               err,
    CONST DCINumber*        number,
    duword                  rsl_length,
    duword                  rsl_flag,
    dvoid*                  rsl
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCINumberToReal(
#else
DCINumberToReal(
#endif // OCI_EXPORT
    DCIError*               err,
    CONST DCINumber*        number,
    duword                  rsl_length,
    dvoid*                  rsl
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberToText( 
#else
DCINumberToText(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number,
    const DmText*           fmt,
    dub4                    fmt_length,
    const DmText*           nls_params,
    dub4                    nls_p_length,
    dub4*                   buf_size,
    DmText*                 buf 
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberMod(
#else
DCINumberMod(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number1,
    const DCINumber*        number2,
    DCINumber*              result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberDiv( 
#else
DCINumberDiv(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number1,
    const DCINumber*        number2,
    DCINumber*              result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberMul( 
#else
DCINumberMul(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number1,
    const DCINumber*        number2,
    DCINumber*              result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberSub( 
#else
DCINumberSub(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number1,
    const DCINumber*        number2,
    DCINumber*              result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberAdd( 
#else
DCINumberAdd(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number1,
    const DCINumber*        number2,
    DCINumber*              result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberDec( 
#else
DCINumberDec(
#endif // OCI_EXPORT
    DCIError*               err,
    DCINumber*              number
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberInc( 
#else
DCINumberInc(
#endif // OCI_EXPORT
    DCIError*               err,
    DCINumber*              number
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberNeg( 
#else
DCINumberNeg(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number,
    DCINumber*              result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberAbs(
#else
DCINumberAbs(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCINumber*        number,
    DCINumber*              result
);

DCI_API 
dub1* 
#ifdef OCI_EXPORT
OCIRawPtr(
#else
DCIRawPtr(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    const DCIRaw*           raw
);

DCI_API
dub4
#ifdef OCI_EXPORT
OCIRawSize(
#else
DCIRawSize(
#endif  //OCI_EXPORT
    DCIEnv*                 envhp,
    const DCIRaw*           raw
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIRawAllocSize(
#else
DCIRawAllocSize(
#endif  //OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    const DCIRaw*           raw,
    dub4*                   allocsize
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIRawAssignBytes(
#else
DCIRawAssignBytes(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    const dub1*             source,
    dub4                    source_len,
    DCIRaw**                target
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIRawResize(
#else
DCIRawResize(
#endif
    DCIEnv*                 envhp,
    DCIError*               errhp,
    dub2                    new_size,
    DCIRaw**                raw
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIRawAssignRaw(
#else
DCIRawAssignRaw(
#endif   
    DCIEnv*                 envhp,
    DCIError*               errhp,
    const DCIRaw*           rhs,
    DCIRaw**                lhs
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCILobLoadFromFile( 
#else
DCILobLoadFromFile(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          dst_locp,
    DCILobLocator*          src_locp,
    dub4                    amount,
    dub4                    dst_offset,
    dub4                    src_offset
);

DCI_API 
dsword
#ifdef OCI_EXPORT
OCILobFileOpen( 
#else
DCILobFileOpen( 
#endif  //OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          filep,
    dub1                    mode
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCILobFileClose(
#else
DCILobFileClose(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          filep
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCILobFileIsOpen(  
#else
DCILobFileIsOpen(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          filep,
    boolean*                flag
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCILobCreateTemporary(
#else
DCILobCreateTemporary(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub2                    csid,
    dub1                    csfrm,
    dub1                    lobtype,
    boolean                 cache,
    DCIDuration             duration
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCILobFreeTemporary(
#else
DCILobFreeTemporary(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateTimeToText(
#else
DCIDateTimeToText(
#endif
    void*                   hndl,
    DCIError*               err,
    const DCIDateTime*      date,
    const DmText*           fmt,
    dub1                    fmt_length,
    dub1                    fsprec,
    const DmText*           lang_name,
    size_t                  lang_length,
    dub4*                   buf_size,
    DmText*                 buf
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateTimeFromText(
#else
DCIDateTimeFromText(
#endif
    void*                   hndl,
    DCIError*               err,
    const DmText*           date_str,
    size_t                  d_str_length,
    const DmText*           fmt,
    dub1                    fmt_length,
    const DmText*           lang_name,
    size_t                  lang_length,
    DCIDateTime*            date 
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateAddMonths(
#else
DCIDateAddMonths(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date,
    dsb4                    num_months,
    DCIDate*                result 
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateAddDays(
#else
DCIDateAddDays(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date,
    dsb4                    num_days,
    DCIDate*                result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateNextDay(
#else
DCIDateNextDay(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date,
    const DmText*           day,
    dub4                    day_length,
    DCIDate*                next_day
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateFromText(
#else
DCIDateFromText(
#endif // OCI_EXPORT
    DCIError*               err,
    const DmText*           date_str,
    dub4                    d_str_length,
    const DmText*           fmt,
    dub1                    fmt_length,
    const DmText*           lang_name,
    dub4                    lang_length,
    DCIDate*                date 
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateToText(
#else
DCIDateToText(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date,
    const DmText*           fmt,
    dub1                    fmt_length,
    const DmText*           lang_name,
    dub4                    lang_length,
    dub4*                   buf_size,
    DmText*                 buf
);
 
DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateCompare(
#else
DCIDateCompare(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date1,
    const DCIDate*          date2,
    dsword*                 result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateCheck(
#else
DCIDateCheck(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date,
    duword*                 valid
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateDaysBetween(
#else
DCIDateDaysBetween(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date1,
    const DCIDate*          date2,
    dsb4*                   num_days
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateLastDay(
#else
DCIDateLastDay(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          date,
    DCIDate*                last_day
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateSysDate(
#else
DCIDateSysDate(
#endif // OCI_EXPORT
    DCIError*               err,
    DCIDate*                sys_date
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINlsNumericInfoGet(
#else
DCINlsNumericInfoGet(
#endif // OCI_EXPORT
    void*                   hndl,
    DCIError*               errhp,
    dsb4*                   val,
    dub2                    item
);


DCI_API
dsword
#ifdef OCI_EXPORT
OCIObjectFree(
#else
DCIObjectFree(
#endif
    DCIEnv*                 env,
    DCIError*               err,
    void*                   instance,
    dub2                    flags
);


DCI_API
dsword
#ifdef OCI_EXPORT
OCICollSize(
#else
DCICollSize(
#endif
    DCIEnv*                 env,
    DCIError*               err,
    const DCIColl*          coll,
    dsb4*                   size
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCICollTrim(
#else
DCICollTrim(
#endif
    DCIEnv*                 env,
    DCIError*               err,
    dsb4                    trim_num,
    DCIColl*                coll
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCICollAppend(
#else
DCICollAppend(
#endif
    DCIEnv*                 env,
    DCIError*               err,
    const void*             elem,
    const void*             elemind,
    DCIColl*                coll
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCICollGetElem(
#else
DCICollGetElem(
#endif 
    DCIEnv*                 env,
    DCIError*               err,
    const DCIColl*          coll,
    dsb4                    index,
    boolean*                exists,
    void**                  elem,
    void**                  elemind
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIObjectPin(
#else
DCIObjectPin(
#endif
    DCIEnv*                 env,
    DCIError*               err,
    DCIRef*                 object_ref,
    DCIComplexObject*       corhdl,
    DCIPinOpt               pin_option, 
    DCIDuration             pin_duration, 
    DCILockOpt              lock_option,
    void**                  object 
);

DCI_API 
dtext*
#ifdef OCI_EXPORT
OCIStringPtr(
#else
DCIStringPtr(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    const DCIString*        vs
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIObjectNew(
#else
DCIObjectNew(
#endif
    DCIEnv*                 env,
    DCIError*               err,
    const DCISvcCtx*        svc,
    DCITypeCode             typecode,
    DCIType*                tdo,
    void*                   table,
    DCIDuration             duration,
    boolean                 value,
    void**                  instance
);

DCI_API 
dsword   
#ifdef OCI_EXPORT
OCIBindObject(
#else
DCIBindObject( 
#endif
    DCIBind*                bindp,
    DCIError*               errhp,
    const DCIType*          type,
    void**                  pgvpp,
    dub4*                   pvszsp,
    void**                  indpp,
    dub4*                   indszp
);

DCI_API 
dsword   
#ifdef OCI_EXPORT
OCIDefineObject(
#else
DCIDefineObject(
#endif
    DCIDefine*              defnp,
    DCIError*               errhp,
    const DCIType*          type,
    void**                  pgvpp,
    dub4*                   pvszsp,
    void**                  indpp,
    dub4*                   indszp
);
/*--------------------end--------------------*/

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeGetDate(
#else
DCIDateTimeGetDate(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    CONST DCIDateTime*      date,
    dsb2*                   yr,
    dub1*                   mnth,
    dub1*                   dy
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeGetTime(
#else
DCIDateTimeGetTime(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIDateTime*            datetime,
    dub1*                   hr,
    dub1*                   mm,
    dub1*                   ss,
    dub4*                   fsec
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateTimeAssign(
#else
DCIDateTimeAssign(
#endif // OCI_EXPORT
    void*                   hndl,
    DCIError*               err,
    const DCIDateTime*      from,
    DCIDateTime*            to
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeGetTimeZoneOffset(
#else
DCIDateTimeGetTimeZoneOffset(
#endif
    void*                   hndl,
    DCIError*               err,
    const DCIDateTime*      datetime,
    dsb1*                   hour,
    dsb1*                   min
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeGetTimeZoneName(
#else
DCIDateTimeGetTimeZoneName(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    CONST DCIDateTime*      date,
    dub1*                   buf,
    dub4*                   buflen
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadMutexInit(
#else
DCIThreadMutexInit(
#endif
    void*                   hndl,
    DCIError*               err,
    DCIThreadMutex**        mutex
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadMutexAcquire(
#else
DCIThreadMutexAcquire(
#endif
    void*                   hndl,
    DCIError*               err,
    DCIThreadMutex*         mutex
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadMutexRelease(
#else
DCIThreadMutexRelease(
#endif
    void*                   hndl,
    DCIError*               err,
    DCIThreadMutex*         mutex
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadMutexDestroy(
#else
DCIThreadMutexDestroy(
#endif
    void*                   hndl,
    DCIError*               err,
    DCIThreadMutex**        mutex
);

DCI_API 
dsword
#ifdef OCI_EXPORT
OCILobLocatorAssign(
#else
DCILobLocatorAssign(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    CONST DCILobLocator*    src_locp,
    DCILobLocator**         dst_locpp
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCILobIsOpen(
#else
DCILobIsOpen(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    boolean*                flag
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateTimeConstruct(
#else
DCIDateTimeConstruct(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIDateTime*            datetime,
    dsb2                    yr,
    dub1                    mnth,
    dub1                    dy,
    dub1                    hr,
    dub1                    mm,
    dub1                    ss,
    dub4                    fsec,
    DmText*                 timezone,
    size_t                  timezone_length
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIObjectCopy(
#else
DCIObjectCopy(
#endif // OCI_EXPORT
    DCIEnv*                 env,
    DCIError*               err,
    const DCISvcCtx*        svc,
    void*                   source,
    void*                   null_source,
    void*                   target,
    void*                   null_target,
    DCIType*                tdo,
    DCIDuration             duration,
    dub1                    option
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIRefAssign(
#else
DCIRefAssign(
#endif // OCI_EXPORT
    DCIEnv*                 env,
    DCIError*               err,
    const DCIRef*           source,
    DCIRef**                target
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIObjectGetObjectRef(
#else
DCIObjectGetObjectRef(
#endif // OCI_EXPORT
    DCIEnv*                 env,
    DCIError*               err,
    void*                   object,
    DCIRef*                 object_ref
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCISessionPoolDestroy(
#else
DCISessionPoolDestroy(
#endif // OCI_EXPORT
    DCISPool*               spoolhp,
    DCIError*               errhp,
    dub4                    mode
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCISessionPoolCreate(
#else
DCISessionPoolCreate(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    DCISPool*               spoolhp,
    DmText**                poolName,
    dub4*                   poolNameLen,
    const DmText*           connStr,
    dub4                    connStrLen,
    dub4                    sessMin,
    dub4                    sessMax,
    dub4                    sessIncr,
    DmText*                 userid,
    dub4                    useridLen,
    DmText*                 password,
    dub4                    passwordLen,
    dub4                    mode 
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIConnectionPoolCreate(
#else
DCIConnectionPoolCreate(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    DCICPool*               poolhp,
    DmText**                poolName,
    dsb4*                   poolNameLen,
    const DmText*           dblink,
    dsb4                    dblinkLen,
    dub4                    connMin,
    dub4                    connMax,
    dub4                    connIncr,
    const DmText*           poolUsername,
    dsb4                    poolUserLen,
    const DmText*           poolPassword,
    dsb4                    poolPassLen,
    dub4                    mode
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIConnectionPoolDestroy(
#else
DCIConnectionPoolDestroy(
#endif // OCI_EXPORT
    DCICPool*               poolhp,
    DCIError*               errhp,
    dub4                    mode
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCICollAssign(
#else
DCICollAssign(
#endif // OCI_EXPORT
    DCIEnv*                 env,
    DCIError*               err,
    const DCIColl*          rhs,
    DCIColl*                lhs
);

DCI_API
dsb4 
#ifdef OCI_EXPORT
OCICollMax(
#else
DCICollMax(
#endif // OCI_EXPORT 
    DCIEnv*                 env,
    const DCIColl*          coll
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCICollAssignElem(
#else
DCICollAssignElem( 
#endif // OCI_EXPORT 
    DCIEnv*                 env,
    DCIError*               err,
    dsb4                    index,
    const void*             elem,
    const void*             elemind,
    DCIColl*                coll
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCISessionGet(
#else
DCISessionGet(
#endif // OCI_EXPORT 
    DCIEnv*                 envhp,
    DCIError*               errhp,
    DCISvcCtx**             svchp,
    DCIAuthInfo*            authInfop,
    DmText*                 dbName,
    dub4                    dbName_len,
    const DmText*           tagInfo,
    dub4                    tagInfo_len,
    DmText**                retTagInfo,
    dub4*                   retTagInfo_len,
    boolean*                found,
    dub4                    mode
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCISessionRelease(
#else
DCISessionRelease(
#endif // OCI_EXPORT 
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DmText*                 tag,
    dub4                    tag_len,
    dub4                    mode
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIPing(
#else
DCIPing(
#endif // OCI_EXPORT 
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    dub4                    mode
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateZoneToZone(
#else
DCIDateZoneToZone(
#endif // OCI_EXPORT   
    DCIError*               err,
    const DCIDate*          date1,
    const DmText*           zon1,
    dub4                    zon1_length,
    const DmText*           zon2,
    dub4                    zon2_length,
    DCIDate*                date2 
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIAQListen(
#else
DCIAQListen(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCIAQAgent**            agent_list,
    dub4                    num_agents,
    dsb4                    wait,
    DCIAQAgent**            agent,
    dub4                    flags
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIAQDeq(
#else
DCIAQDeq(
#endif // OCI_EXPORT
    DCISvcCtx*              svch,
    DCIError*               errh,
    DmText*                 queue_name,
    DCIAQDeqOptions*        dequeue_options,
    DCIAQMsgProperties*     message_properties,
    DCIType*                payload_tdo,
    void**                  payload,
    void**                  payload_ind,
    DCIRaw**                msgid,
    dub4                    flags
);

DCI_API
dub4
#ifdef OCI_EXPORT
OCISubscriptionRegister(
#else
DCISubscriptionRegister(
#endif // OCI_EXPORT
    DCISvcCtx*              svchp,
    DCISubscription**       subscrhpp,
    dub2                    count,
    DCIError*               errhp,
    dub4                    mode
);

DCI_API 
dub4
#ifdef OCI_EXPORT
OCISubscriptionUnRegister(
#else
DCISubscriptionUnRegister(
#endif // OCI_EXPORT   
    DCISvcCtx*              svchp,
    DCISubscription*        subscrhp,
    DCIError*               errhp,
    dub4                    mode
); 

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIAQEnq(
#else
DCIAQEnq(
#endif // OCI_EXPORT  
    DCISvcCtx*              svch,
    DCIError*               errh,
    DmText*                 queue_name,
    DCIAQEnqOptions*        enqueue_options,
    DCIAQMsgProperties*     message_properties,
    DCIType*                payload_tdo,
    void**                  payload,
    void**                  payload_ind,
    DCIRaw**                msgid,
    dub4                    flags
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCILobGetLength2(
#else
DCILobGetLength2(
#endif // OCI_EXPORT   
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dmub8*                  lenp 
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIIterCreate(
#else
DCIIterCreate(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    const DCIColl*          coll,
    DCIIter**               itr 
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIIterDelete(
#else
DCIIterDelete(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    DCIIter**               itr
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIIterNext(
#else
DCIIterNext(
#endif // OCI_EXPORT 
    DCIEnv*                 env,
    DCIError*               err,
    DCIIter*                itr,
    void**                  elem,
    void**                  elemind,
    boolean*                eoc
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIIterPrev(
#else
DCIIterPrev(
#endif // OCI_EXPORT 
    DCIEnv*                 env,
    DCIError*               err,
    DCIIter*                itr,
    void**                  elem,
    void**                  elemind,
    boolean*                boc
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadInit(
#else
DCIThreadInit(
#endif  
    void*                   hndl,
    DCIError*               err
);

DCI_API
void
#ifdef OCI_EXPORT
OCIThreadProcessInit(
#else
DCIThreadProcessInit(
#endif
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadTerm(
#else
DCIThreadTerm(
#endif
    void*                   hndl,
    DCIError*               err
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDBStartup(
#else
DCIDBStartup(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCIAdmin*               admhp,
    dub4                    mode,
    dub4                    flags
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDBShutdown(
#else
DCIDBShutdown(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCIAdmin*               admhp,
    dub4                    mode
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobTrim2(
#else
DCILobTrim2(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dmub8                   newlen
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobWrite2(
#else
DCILobWrite2(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dmub8*                  byte_amtp,
    dmub8*                  char_amtp,
    dmub8                   offset,
    void*                   bufp,
    dmub8                   buflen,
    dub1                    piece,
    void*                   ctxp,
    dsb4                    (*cbfp)
    (
        void*               ctxp,
        void*               bufp,
        dmub8*              lenp,
        dub1*               piecep,
        void**              changed_bufpp,
        dmub8*              changed_lenp
    ) ,
    dub2                    csid,
    dub1                    csfrm
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobErase(
#else
DCILobErase(
#endif  
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4*                   amount,
    dub4                    offset
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobErase2(
#else
DCILobErase2(
#endif   
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dmub8*                  amount,
    dmub8                   offset
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobGetChunkSize(
#else
DCILobGetChunkSize(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4*                   chunk_size
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobCopy(
#else
DCILobCopy(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          dst_locp,
    DCILobLocator*          src_locp,
    dub4                    amount,
    dub4                    dst_offset,
    dub4                    src_offset
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobCopy2(
#else
DCILobCopy2(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          dst_locp,
    DCILobLocator*          src_locp,
    dmub8                   amount,
    dmub8                   dst_offset,
    dmub8                   src_offset
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobLoadFromFile2(
#else
DCILobLoadFromFile2(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          dst_locp,
    DCILobLocator*          src_locp,
    dmub8                   amount,
    dmub8                   dst_offset,
    dmub8                   src_offset
); 

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobWriteAppend(
#else
DCILobWriteAppend(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4*                   amtp,
    void*                   bufp,
    dub4                    buflen,
    dub1                    piece,
    void*                   ctxp,
    dsb4                    (*cbfp)
    (
        void*               ctxp,
        void*               bufp,
        dub4*               lenp,
        dub1*               piecep
    ),
    dub2                    csid,
    dub1                    csfrm 
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobWriteAppend2(
#else
DCILobWriteAppend2(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dmub8*                  byte_amtp,
    dmub8*                  char_amtp,
    void*                   bufp, 
    dmub8                   buflen, 
    dub1                    piece, 
    void*                   ctxp, 
    dsb4                    (*cbfp)
    (
        void*               ctxp,
        void*               bufp,
        dmub8*              lenp,
        dub1*               piecep,
        void**              changed_bufpp,
        dmub8*              changed_lenp
    ),
    dub2                    csid,
    dub1                    csfrm
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobIsTemporary(
#else
DCILobIsTemporary(
#endif    
    DCIEnv*                 envhp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    boolean*                is_temporary
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobOpen(
#else
DCILobOpen(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub1                    mode
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobClose(
#else
DCILobClose(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobGetStorageLimit(
#else
DCILobGetStorageLimit(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dmub8*                  limitp
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIArrayDescriptorAlloc(
#else
DCIArrayDescriptorAlloc(
#endif
    const void*             parenth,
    void**                  descpp,
    const dub4              type,
    dub4                    array_size,
    const size_t            xtramem_sz,
    void**                  usrmempp
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIArrayDescriptorFree(
#else
DCIArrayDescriptorFree(
#endif    
    void**                  descp,
    const dub4              type
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobFlushBuffer(
#else
DCILobFlushBuffer(
#endif 
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp,
    dub4                    flag 
); 

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobDisableBuffering(
#else
DCILobDisableBuffering(
#endif  
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILobEnableBuffering(
#else
DCILobEnableBuffering(
#endif
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          locp 
); 

DCI_API
dsword
#ifdef OCI_EXPORT
OCITypeByName(
#else
DCITypeByName(
#endif  
    DCIEnv*                 env,
    DCIError*               err,
    const DCISvcCtx*        svc,
    const DmText*           schema_name,
    dub4                    s_length,
    const DmText*           type_name,
    dub4                    t_length,
    const DmText*           version_name,
    dub4                    v_length,
    DCIDuration             pin_duration,
    DCITypeGetOpt           get_option,
    DCIType**               tdo 
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateTimeIntervalAdd(
#else
DCIDateTimeIntervalAdd(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIDateTime*            addend1,
    DCIInterval*            addend2,
    DCIDateTime*            result
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateTimeIntervalSub(
#else
DCIDateTimeIntervalSub(
#endif // OCI_EXPORT
    dvoid*                  hndl,
    DCIError*               err,
    DCIDateTime*            addend1,
    DCIInterval*            addend2,
    DCIDateTime*            result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIObjectGetProperty(
#else
DCIObjectGetProperty(
#endif // OCI_EXPORT 
    DCIEnv*                 envh,
    DCIError*               errh,
    const void*             obj,
    DCIObjectPropId         propertyId,
    void*                   property,
    dub4*                   size 
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIObjectGetInd(
#else
DCIObjectGetInd(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    void*                   instance,
    void**                  null_struct
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIObjectUnpin(
#else
DCIObjectUnpin(
#endif // OCI_EXPORT   
    DCIEnv*                 env,
    DCIError*               err,
    void*                   object
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCITransPrepare(
#else
DCITransPrepare(
#endif // OCI_EXPORT   
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    dub4                    flags
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCITransForget(
#else
DCITransForget(
#endif // OCI_EXPORT   
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    dub4                    flags
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeSubtract(
#else
DCIDateTimeSubtract(
#endif // OCI_EXPORT 
    void*                   hndl,
    DCIError*               err,
    DCIDateTime*            indate1,
    DCIDateTime*            indate2,
    DCIInterval*            inter
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeSysTimeStamp(
#else
DCIDateTimeSysTimeStamp(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    DCIDateTime*            sys_date
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeConvert(
#else
DCIDateTimeConvert(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    DCIDateTime*            indate,
    DCIDateTime*            outdate
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeCheck( 
#else
DCIDateTimeCheck(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    const DCIDateTime*      date,
    dub4*                   valid
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeCompare(
#else
DCIDateTimeCompare(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    const DCIDateTime*      date1,
    const DCIDateTime*      date2,
    dsword*                 result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadIdInit(
#else
DCIThreadIdInit(
#endif // OCI_EXPORT   
    void*                   hndl,
    DCIError*               err,
    DCIThreadId**           tid
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadHndInit(
#else
DCIThreadHndInit(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    DCIThreadHandle**       thnd
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadIdDestroy( 
#else
DCIThreadIdDestroy(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    DCIThreadId**           tid
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadHndDestroy(
#else
DCIThreadHndDestroy(
#endif // OCI_EXPORT   
    void*                   hndl,
    DCIError*               err,
    DCIThreadHandle**       thnd
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadClose(
#else
DCIThreadClose(
#endif // OCI_EXPORT 
    void*                   hndl,
    DCIError*               err,
    DCIThreadHandle*        tHnd
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadCreate(
#else
DCIThreadCreate(
#endif // OCI_EXPORT 
    void*                   hndl,
    DCIError*               err,
    void                    (*start)(void*),
    void*                   arg,
    DCIThreadId*            tid,
    DCIThreadHandle*        tHnd
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadJoin(
#else
DCIThreadJoin(
#endif // OCI_EXPORT 
    void*                   hndl,
    DCIError*               err,
    DCIThreadHandle*        tHnd
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadKeyInit( 
#else
DCIThreadKeyInit(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    DCIThreadKey**          key,
    DCIThreadKeyDestFunc    destFn
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadKeyDestroy( 
#else
DCIThreadKeyDestroy(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    DCIThreadKey**          key
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadKeyGet( 
#else
DCIThreadKeyGet(
#endif // OCI_EXPORT  
    void*                   hndl,
    DCIError*               err,
    DCIThreadKey*           key,
    void**                  pValue
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIThreadKeySet( 
#else
DCIThreadKeySet(
#endif // OCI_EXPORT 
    void*                   hndl,
    DCIError*               err,
    DCIThreadKey*           key,
    void*                   value
);

DCI_API
void
#ifdef OCI_EXPORT
OCIRefClear(
#else
DCIRefClear(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIRef*                 ref
);

DCI_API
boolean 
#ifdef OCI_EXPORT
OCIRefIsNull(
#else
DCIRefIsNull(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    const DCIRef*           ref
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIRefToHex(
#else
DCIRefToHex(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    const DCIRef*           ref,
    DmText*                 hex,
    dub4*                   hex_length
);

DCI_API
dub4
#ifdef OCI_EXPORT
OCIRefHexSize( 
#else
DCIRefHexSize(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    const DCIRef*           ref 
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIStmtRelease(
#else
DCIStmtRelease(
#endif // OCI_EXPORT  
    DCIStmt*                stmthp,
    DCIError*               errhp,
    const DmText*           key,
    dub4                    keylen,
    dub4                    mode
);  

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIStmtPrepare2( 
#else
DCIStmtPrepare2(
#endif // OCI_EXPORT   
    DCISvcCtx*              svchp,
    DCIStmt**               stmthp,
    DCIError*               errhp,
    const DmText*           stmttext,
    dub4                    stmt_len,
    const DmText*           key,
    dub4                    keylen,
    dub4                    language,
    dub4                    mode
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCILobAppend(
#else
DCILobAppend(
#endif // OCI_EXPORT  
    DCISvcCtx*              svchp,
    DCIError*               errhp,
    DCILobLocator*          dst_locp,
    DCILobLocator*          src_locp 
);

/*--------------------end--------------------*/

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberCmp(
#else
DCINumberCmp(
#endif // OCI_EXPORT 
    DCIError*               err,
    const DCINumber*        number1,
    const DCINumber*        number2,
    dsword*                 result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINumberIsInt( 
#else
DCINumberIsInt(
#endif // OCI_EXPORT 
    DCIError*               err,
    const DCINumber*        number,
    boolean*                result
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCILogon2(
#else
DCILogon2(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    DCISvcCtx**             svchp,
    CONST DmText*           username,
    dub4                    uname_len,
    CONST DmText*           password,
    dub4                    passwd_len,
    CONST DmText*           dbname,
    dub4                    dbname_len,
    dub4                    mode
);

DCI_API 
dsword
#ifdef OCI_EXPORT
OCILobCharSetId(
#else
DCILobCharSetId(
#endif // OCI_EXPORT
    DCIEnv*                 envhp,
    DCIError*               errhp,
    const DCILobLocator*    locp,
    dub2*                   csid
);

DCI_API 
dsword
#ifdef OCI_EXPORT
OCIDirPathColArrayRowGet(
#else
DCIDirPathColArrayRowGet(
#endif // OCI_EXPORT
    DCIDirPathColArray*     dpca,
    DCIError*               errhp,
    dub4                    rownum,
    dub1***                 cvalppp,
    dub4**                  clenpp,
    dub1**                  cflgpp
);

DCI_API 
dsword
#ifdef OCI_EXPORT
OCIDurationBegin(
#else
DCIDurationBegin(
#endif // OCI_EXPORT 
    DCIEnv*                 env,
    DCIError*               err,
    const DCISvcCtx*        svc,
    DCIDuration             parent,
    DCIDuration*            duration
); 

DCI_API 
dsword
#ifdef OCI_EXPORT
OCIDurationEnd(
#else
DCIDurationEnd(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    const DCISvcCtx*        svc,
    DCIDuration             duration
);

DCI_API
dub4
#ifdef OCI_EXPORT
OCIStringSize(
#else
DCIStringSize(
#endif  //OCI_EXPORT
    DCIEnv*                 env,
    const DCIString*        vs
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIStringAssignText( 
#else
DCIStringAssignText(
#endif // OCI_EXPORT   
    DCIEnv*                 envhp,
    DCIError*               errhp, 
    const DmText*           rhs,
    dub2                    rhs_len,
    DCIString**             lhs
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIRowidToChar(
#else
DCIRowidToChar(
#endif 
    DCIRowid*               rowidDesc,
    DmText*                 outbfp,
    dub2*                   outbflp,
    DCIError*               errhp
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINlsEnvironmentVariableGet(
#else
DCINlsEnvironmentVariableGet(
#endif 
    void*                   val,
    size_t                  size,
    dub2                    item,
    dub2                    charset,
    size_t*                 rsize
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIStringAllocSize( 
#else
DCIStringAllocSize(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    const DCIString*        vs,
    dub4*                   allocsize
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIStringAssign( 
#else
DCIStringAssign(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    const DCIString*        rhs,
    DCIString**             lhs
);

DCI_API 
dsword 
#ifdef OCI_EXPORT
OCIStringResize( 
#else
DCIStringResize(
#endif // OCI_EXPORT  
    DCIEnv*                 env,
    DCIError*               err,
    dub4                    new_size,
    DCIString**             str
);

DCI_API
dsword 
#ifdef OCI_EXPORT
OCIDateAssign(
#else
DCIDateAssign(
#endif // OCI_EXPORT
    DCIError*               err,
    const DCIDate*          from,
    DCIDate*                to 
);

DCI_API 
dsword   
#ifdef OCI_EXPORT
OCIDefineDynamic(
#else
DCIDefineDynamic(
#endif // OCI_EXPORT
    DCIDefine*              definep,
    DCIError*               errhp,
    void*                   octxp,
    DCICallbackDefine       ocbfp 
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIStmtGetBindInfo(
#else
DCIStmtGetBindInfo(
#endif // OCI_EXPORT 
    DCIStmt*                stmtp,
    DCIError*               errhp,
    dub4                    size,
    dub4                    startloc,
    dsb4*                   found,
    DmText*                 bvnp[],
    dub1                    bvnl[],
    DmText*                 invp[],
    dub1                    inpl[],
    dub1                    dupl[],
    DCIBind*                hndl[]
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeToArray(
#else
DCIDateTimeToArray(
#endif  
    void*                   hndl,
    DCIError*               err,
    const DCIDateTime*      datetime,
    const DCIInterval*      reftz,
    dub1*                   outarray,
    dub4*                   len,
    dub1                    fsprec
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCIDateTimeFromArray(
#else
DCIDateTimeFromArray(
#endif  
    void*                   hndl,
    DCIError*               err,
    const dub1*             inarray,
    dub4*                   len,
    dub1                    type,
    DCIDateTime*            datetime,
    const DCIInterval*      reftz,
    dub1                    fsprec 
);


DCI_API
dsword
#ifdef OCI_EXPORT
OCITerminate(
#else
DCITerminate(
#endif 
    dub4                    mode
);

DCI_API
size_t
#ifdef OCI_EXPORT
OCIMultiByteStrCaseConversion(
#else
DCIMultiByteStrCaseConversion(
#endif // OCI_EXPORT
    void*                   hndl,
    DmText*                 dststr,
    const DmText*           srcstr,
    dub4                    flag
);

DCI_API 
dsword
#ifdef OCI_EXPORT
OCIClientVersion(
#else
DCIClientVersion(
#endif // OCI_EXPORT
    dsword*                 major_version,
    dsword*                 minor_version,
    dsword*                 update_num,
    dsword*                 patch_num,
    dsword*                 port_update_num
);

DCI_API
dsword
#ifdef OCI_EXPORT
obndrn(
#else
dbndrn(
#endif // OCI_EXPORT
    DCda_Def*               cursor,
    dsword                  sqlvn,
    dub1*                   progv,
    dsword                  progvl,
    dsword                  ftype,
    dsword                  scale,
    dsb2*                   indp,
    dtext*                  fmt,
    dsword                  fmtl,
    dsword                  fmtt
);

DCI_API
dsword
#ifdef OCI_EXPORT
obndrv(
#else
dbndrv(
#endif // OCI_EXPORT
    DCda_Def*               cursor,
    dtext*                  sqlvar,
    dsword                  sqlvl,
    dub1*                   progv,
    dsword                  progvl,
    dsword                  ftype,
    dsword                  scale,
    dsb2*                   indp,
    dtext*                  fmt,
    dsword                  fmtl,
    dsword                  fmtt
);

DCI_API
dsword
#ifdef OCI_EXPORT
oclose(
#else
dclose(
#endif // OCI_EXPORT
    DCda_Def*               cursor
);

DCI_API
dsword
#ifdef OCI_EXPORT
ocof(
#else
dcof(
#endif // OCI_EXPORT
    DLda_Def*               lda
);

DCI_API
dsword
#ifdef OCI_EXPORT
ocon(
#else
dcon(
#endif // OCI_EXPORT
    DLda_Def*               lda
);

DCI_API
dsword
#ifdef OCI_EXPORT
odefin(
#else
ddefin(
#endif // OCI_EXPORT
    DCda_Def*                cursor,
    dsword                   pos,
    dub1*                    buf,
    dsword                   bufl,
    dsword                   ftype,
    dsword                   scale,
    dsb2*                    indp,
    dtext*                   fmt,
    dsword                   fmtl,
    dsword                   fmtt,
    dub2*                    rlen,
    dub2*                    rcode
);

DCI_API
dsword
#ifdef OCI_EXPORT
oerhms(
#else
derhms(
#endif // OCI_EXPORT
    DLda_Def*               lda,
    dsb2                    rcode,
    dtext*                  buf,
    dsword                  bufsiz
);

DCI_API
dsword
#ifdef OCI_EXPORT
oexec(
#else
dexec(
#endif // OCI_EXPORT
    DCda_Def*               cursor
);

DCI_API
dsword
#ifdef OCI_EXPORT
ofetch(
#else
dfetch(
#endif // OCI_EXPORT
    DCda_Def*               cursor
);

DCI_API
dsword
#ifdef OCI_EXPORT
olog(
#else
dlog(
#endif // OCI_EXPORT
    DLda_Def*           lda,
    dub1*               hda,
    dtext*              uid,
    dsword              uidl,
    dtext*              pswd,
    dsword              pswdl,
    dtext*              conn,
    dsword              connl,
    dub4                mode
);

DCI_API
dsword
#ifdef OCI_EXPORT
ologof(
#else
dlogof(
#endif // OCI_EXPORT
    DLda_Def*               lda
);

DCI_API
dsword
#ifdef OCI_EXPORT
oopen(
#else
dopen(
#endif // OCI_EXPORT
    DCda_Def*               cursor,
    DLda_Def*               lda,
    dtext*                  dbn,
    dsword                  dbnl,
    dsword                  arsize,
    dtext*                  uid,
    dsword                  uidl
);

DCI_API
dsword
#ifdef OCI_EXPORT
oparse(
#else
dparse(
#endif // OCI_EXPORT
    DCda_Def*               cursor,
    dtext*                  sqlstm,
    dsb4                    sqll,
    dsword                  defflg,
    dub4                    lngflg
);

DCI_API dsword 
#ifdef OCI_EXPORT
ocom(
#else
dcom(
#endif // OCI_EXPORT
    DLda_Def*               lda
);

DCI_API
dsword 
#ifdef OCI_EXPORT
orol(
#else
drol(
#endif // OCI_EXPORT
    DLda_Def*               lda
);

DCI_API
void
#ifdef OCI_EXPORT
OCIDateSetTime(
#else
DCIDateSetTime(
#endif
    DCIDate*                date,
    dub1                    hour,
    dub1                    min,
    dub1                    sec
);

DCI_API
void
#ifdef OCI_EXPORT
OCIDateGetTime(
#else
DCIDateGetTime(
#endif
    const DCIDate*          date,
    dub1*                   hour,
    dub1*                   min,
    dub1*                   sec
);

DCI_API
void
#ifdef OCI_EXPORT
OCIDateSetDate(
#else
DCIDateSetDate(
#endif
    DCIDate*                date,
    dsb2                    year,
    dub1                    month,
    dub1                    day
);

DCI_API
void
#ifdef OCI_EXPORT
OCIDateGetDate(
#else
DCIDateGetDate(
#endif
    const DCIDate*          date,
    dsb2*                   year,
    dub1*                   month,
    dub1*                   day
);

DCI_API
dub2
#ifdef OCI_EXPORT
OCINlsCharSetNameToId(
#else
DCINlsCharSetNameToId(
#endif 
    void*               hndl,
    const DmText*       name
);

DCI_API
dsword
#ifdef OCI_EXPORT
OCINlsCharSetIdToName(
#else
DCINlsCharSetIdToName(
#endif 
    void*               hndl,
    DmText*             buf,
    size_t              buflen,
    dub2                id
);

#endif      //_DCI_H

#ifdef __cplusplus
}
#endif      //__cplusplus

