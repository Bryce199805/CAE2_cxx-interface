/**********************************************************
file:
    logmnr_client.h
Notes:
    LOMMNR FOR C interface
Legal Notices:
Dameng Database
Copyright(C) 2000-2020 DM and/or its affiliates. All rights reserved.
http://www.dameng.com
*******************************************************/

#ifndef _LOGMNR_CLIENT_H
#define _LOGMNR_CLIENT_H

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++   */
#endif  /* __cplusplus */

/* LOGMNR declaration data types */
#ifndef _DMTYPE_H
typedef int                     lint;
typedef unsigned int            ulint;
typedef unsigned short          usint;
typedef signed char             schar;
typedef unsigned char           byte;

#ifdef WIN32
typedef __int64                 lint64;
typedef unsigned __int64        ulint64;
#else
typedef long long int           lint64;
typedef unsigned long long int  ulint64;
#endif

typedef ulint                   dmbool;
typedef lint                    dmcode_t;
#endif

#ifndef NAMELEN
#define NAMELEN             128                         /* Size in bytes */
typedef schar               sysname_t[NAMELEN + 1];
#endif

#ifndef MAGIC_DECLARE
#ifdef _MAGIC
#define MAGIC_DECLARE   ulint n_magic2;
#else
#define MAGIC_DECLARE
#endif
#endif

#ifndef DllImport
#ifdef WIN32
#define DllImport   __declspec( dllimport )
#else
#define DllImport
#endif
#endif

#ifndef DllExport
#ifdef WIN32
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif
#endif

/* Implicitly ends the current LogMiner.
 * Starts a new list of redo log files to be analyzed, beginning with the redo log file you specify.
 */
#ifndef LOGMNR_NEWFILE
#define LOGMNR_NEWFILE         1
#endif

/* Removes a redo log file from an existing list of redo log files for LogMiner to process.
 * If LogMiner has called logmnr_client_start, then raises an exception.
 */
#ifndef LOGMNR_REMOVEFILE
#define LOGMNR_REMOVEFILE      2
#endif

/* Adds the specified redo log file to the list of redo log files to be analyzed.
 * Any attempt to add a duplicate file raises an exception.
 */
#ifndef LOGMNR_ADDFILE
#define LOGMNR_ADDFILE         3
#endif

/*---------------------Define attribute--------------------*/
#define LOGMNR_ATTR_PARALLEL_NUM        10001       /* Thread number for log record format, default 2, range [2, 16] */
#define LOGMNR_ATTR_BUFFER_NUM          10002       /* Buffer number for log record read, default 8, range [8, 1024] */
#define LOGMNR_ATTR_CONTENT_NUM         10003       /* Row set cache number, default 256, range [256, 2048] */
#define LOGMNR_ATTR_CHAR_CODE           10004       /* Local charset code, can only get but not set */
#define LOGMNR_ATTR_TRX_END             10005       /* Whether to find a transaction end record, default 1, value 0 or 1 */
#define LOGMNR_ATTR_TRX_WAIT_TIME       10006       /* Wait time in seconds for a transaction end record, default 60, range [0, 600] */

typedef struct logmnr_content_struct logmnr_content_t;

/* Get one row data structure by logmnr_client_get_data */
#define logmnr_content_MAGIC        66981236
struct logmnr_content_struct{
    ulint64         scn;                    /* LSN when the current log record generated*/
    ulint64         start_scn;              /* LSN when the transaction started */
    ulint64         commit_scn;             /* LSN when the transaction ended */

    schar           timestamp[30];          /* Timestamp when the current log record generated */
    schar           start_timestamp[30];    /* Timestamp when the transaction started  */
    schar           commit_timestamp[30];   /* Timestamp when the transaction ended */

    ulint64         xidusn;                 /* Not supported */
    ulint64         xidslt;                 /* Not supported */
    ulint64         xidsqn;                 /* Not supported */

    schar           xid[19];                /* The transaction identifier */

    ulint64         pxidusn;                /* Not supported */
    ulint64         pxidslt;                /* Not supported */
    ulint64         pxidsqn;                /* Not supported */
    schar*          pxid;                   /* Not supported */
    schar*          tx_name;                /* Not supported */

    schar           operation[20];          /* SQL operation for log record:
                                             * INSERT - for insert statement 
                                             * DELETE - for delete statement
                                             * UPDATE - for update statement
                                             * BATCH_UPDATE - for batch update statement
                                             * DDL - for ddl statement
                                             * START - for transaction start
                                             * COMMIT - for transaction commit statement
                                             * ROLLBACK - for transaction rollback statement
                                             * SEQ MODIFY - for sequence modify
                                             * UNSUPPORTED - SQL operations is not currently supported */

    ulint           operation_code;         /* SQL operation code for log record:
                                             * 1 - INSERT
                                             * 2 - DELETE
                                             * 3 - UPDATE
                                             * 4 - BATCH_UPDATE
                                             * 5 - DDL
                                             * 6 - START
                                             * 7 - COMMIT
                                             * 36 - ROLLBACK
                                             * 37 - SEQ MODIFY
                                             * 255 - UNSUPPORTED */

    ulint           roll_back;              /* 1 = If the redo record was generated because of 
                                             *     a partial or a full rollback of the associated transaction
                                             * 0 = Otherwise */

    sysname_t       seg_owner;              /* Name of the modified schema (in case the log pertains to a schema object modification) */

    schar*          seg_name;               /* Not supported */

    sysname_t       table_name;             /* Name of the modified table (in case the log pertains to a table modification) */

    ulint           seg_type;               /* Not supported */
    schar*          seg_type_name;          /* Not supported */
    schar*          table_space;            /* Not supported */

    schar           row_id[21];             /* Row ID of the row modified (only meaningful if the change pertains to a DML).
                                             * This will be NULL if the redo record is not associated with a DML. */

    sysname_t       username;               /* Name of the user who executed the transaction */

    schar*          os_username;            /* Not supported */
    schar*          machine_name;           /* Not supported */
    ulint64         audit_sessionid;        /* Not supported */
    ulint64         session;                /* session_id */
    ulint64         serial;                 /* Not supported */
    schar*          session_info;           /* The IP address of the machine source */
    ulint64         thread;                 /* Not supported */
    ulint           sequence;               /* Not supported */

    ulint           rbasqn;                 /* Log unique serial number, start with 0 and global increment */
    ulint           rbablk;                 /* Page serial number within the log file */
    ulint           rbabyte;                /* Byte offset within the page */

    ulint64         ubafil;                 /* Not supported */
    ulint64         ubablk;                 /* Not supported */
    ulint64         ubarec;                 /* Not supported */
    ulint64         ubasqn;                 /* Not supported */
    ulint           abs_file;               /* Not supported */
    ulint           rel_file;               /* Not supported */
    ulint           data_blk;               /* Not supported */

    ulint           data_obj;               /* ID of the modified table (in case the log pertains to a table modification) */
    ulint           data_objv;              /* Version of the modified table (in case the log pertains to a table modification) */

    ulint           data_objd;              /* Not supported */

    schar*          sql_redo;               /* That reconstructed SQL statement is equivalent to the original SQL statement. */

    schar*          sql_undo;               /* Not supported */

    schar           rs_id[33];              /* Serial number within the transaction */

    ulint           ssn;                    /* For interface - Not supported
                                             * For V$LOGMNR_CONTENTS - SQL sequence number
                                             * If the SQL statement exceeds the length(4000 bytes) of the column can be stored,
                                             * it will be truncated into multiple continuous SQL fragment. */

    ulint           csf;                    /* For interface - Not supported
                                             * For V$LOGMNR_CONTENTS - Continuation SQL flag. Possible values are:
                                             * 0 - Indicates SQL is contained within the same row
                                             * 1 - Indicates SQL length is greater than 4000 bytes
                                             *     and is continued in the next row returned by the view */

    schar*          info;                   /* Not supported */
    ulint           status;                 /* Not supported */

    ulint64         redo_value;             /* Operation unique serial number, start with 0 and global increment.
                                             * For interface - Not supported
                                             * For V$LOGMNR_CONTENTS - Used as input to the DBMS_LOGMNR.MINE_VALUE() and DBMS_LOGMNR.COLUMN_PRESENT() functions */

    ulint64         undo_value;             /* Operation unique serial number, undo_value is one more than redo_value.
                                             * For interface - Not supported
                                             * For V$LOGMNR_CONTENTS - Used as input to the DBMS_LOGMNR.MINE_VALUE() and DBMS_LOGMNR.COLUMN_PRESENT() functions */

    ulint64         safe_resume_scn;        /* Not supported */

    ulint64         cscn;                   /* This column is deprecated in favor of the COMMIT_SCN column */

    schar*          object_id;              /* Not supported */
    schar*          edition_name;           /* Not supported */
    schar*          client_id;              /* Not supported */

    ulint           seq;                    /* Serial number within the transaction, digit number for the RS_ID column */
    ulint64         trxid;                  /* The transaction identifier, digit number for the XID column */

    MAGIC_DECLARE
};

/***********************************************
Purpose:
Initialize the LogMiner environment
Notes:
Such as: mutex, etc
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_init();

/***********************************************
Purpose:
Create a connection to the DM database
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_create_connect( 
    schar*          ip,             /* IN: DM server ip */
    usint           port,           /* IN: DM server listen port */
    schar*          uname,          /* IN: Login user name */
    schar*          pwd,            /* IN: Login user password */
    void**          conn            /* OUT: Connection handle for LogMiner */
);

/***********************************************
Purpose:
Set LogMiner attribute
Notes:
Attribute possible values are:
LOGMNR_ATTR_PARALLEL_NUM
LOGMNR_ATTR_BUFFER_NUM
LOGMNR_ATTR_CONTENT_NUM
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_set_attr( 
    void*           conn,       /* IN: Connection handle */
    ulint           attr,       /* IN: Attribute identifier */
    void*           val,        /* IN: Attribute new value */
    ulint           val_len     /* IN: Attribute value size in bytes */
);

/***********************************************
Purpose:
Get LogMiner attribute
Notes:
Attribute possible values are:
LOGMNR_ATTR_PARALLEL_NUM
LOGMNR_ATTR_BUFFER_NUM
LOGMNR_ATTR_CONTENT_NUM
LOGMNR_ATTR_CHAR_CODE
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_get_attr( 
    void*           conn,               /* IN: Connection handle */
    ulint           attr,               /* IN: Attribute identifier */
    void*           buf,                /* IN/OUT: Attribute value */
    ulint           buf_len,            /* IN: Attribute value buffer size in bytes */
    ulint*          val_len             /* OUT: Attribute value real size in bytes */
);

/***********************************************
Purpose:
Adds the specified redo log file to the list of redo log files to be analyzed.
Notes:
Any attempt to add a duplicate file raises an exception.
Options possible values are:
LOGMNR_NEWFILE
LOGMNR_REMOVEFILE
LOGMNR_ADDFILE
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_add_logfile( 
    void*           conn,               /* IN: Connection handle */
    schar*          logfilename,        /* IN: Redo log file path */
    ulint           options             /* IN: Options of the redo log file */
);

/***********************************************
Purpose:
Removes a redo log file from an existing list of redo log files for LogMiner to process.
Notes:
If LogMiner has called logmnr_client_start, then raises an exception.
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_remove_logfile( 
    void*           conn,               /* IN: Connection handle */
    schar*          logfilename         /* IN: Redo log file path */
);

/***********************************************
Purpose:
Start to analyze the added redo log files.
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_start( 
    void*           conn,           /* IN: Connection handle */
    lint64          trxid,          /* IN: Transaction identifier */
    schar*          starttime,      /* IN: Transaction start timestamp */
    schar*          endtime         /* IN: Transaction end timestamp */
);

/***********************************************
Purpose:
Get the LogMiner content of the added redo log file
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_get_data(
    void*                   conn,               /* IN: Connection handle */
    lint                    row_num,            /* IN: The row number of content you want to get */
    logmnr_content_t***     data,               /* OUT: LogMiner content array */
    lint*                   real_num            /* OUT: The real row number of content you got */
);

/***********************************************
Purpose:
End analysis of the added redo log files.
Options possible values are:
0 - Remove the added redo log files
1 - Reserve the added redo log files
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_end(
    void*        conn,                  /* IN: Connection handle */
    ulint        options                /* IN: Options of the connection handle */
);

/***********************************************
Purpose:
Close the connection to the DM database
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_close_connect(
    void*        conn                   /* IN: Connection handle */
);

/***********************************************
Purpose:
Destroy the LogMiner environment
***********************************************/
DllExport
dmcode_t        /* On success, 0 is returned. On error, < 0 is reuturned */
logmnr_client_deinit();

#ifdef __cplusplus
}                                    /* End of extern "C" { */
#endif  /* __cplusplus */

#endif


