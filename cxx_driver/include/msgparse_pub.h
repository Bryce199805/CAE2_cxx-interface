/****************************************************************************************************
FILE 
    MSGPARSE.H

    Copyright (c) ,2022, Dameng and/or its affiliates. All rights reserved.

DESCRIPTION
    PARSE MESSAGE

HISTORY
    2022/10/12  LJ Created
****************************************************************************************************/

#ifndef MSGPARSE_PUB_H
#define MSGPARSE_PUB_H

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++   */
#endif  /* __cplusplus */

/*---------------------MSGPARSE DECLARATION BASIC------------------*/
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

#if defined (_WINDOWS) || defined (WIN32)
#ifndef DllImport
#define DllImport   __declspec( dllimport )
#endif

#ifndef DllExport
#define DllExport   __declspec( dllexport )
#endif
#else
#define DllImport
#define DllExport
#endif

#define DM_COMM_VER 9

/*---------------------MSGPARSE DECLARATION PARAINFO-------------------*/
#define NAMELEN                 128                     /* Size in bytes */

#ifndef MAX_STR_LEN
#define MAX_STR_LEN             32767                   /* Size in bytes */
#endif

#ifndef MAX_PATH_LEN
#define MAX_PATH_LEN             256                    /* Size in bytes */
#endif

#define MAX_PARAM_LEN            512                    /* Size in bytes */

#define MAX_ROWID_LEN            18                     /* Size in bytes */

#define MAX_LOB_LEN              2048                   /* Size in bytes */

/* check struct info */
#define MAGIC_DECLARE   ulint n_magic2;

struct paraminfo_struct
{
    lint    serno;                                 /* param seqno */
    lint    type;                                  /* param type, -2 indicate out parameter */
    char    name[MAX_PATH_LEN + 1];                /* param name */ 
    union {                                        /* param data */
        char    str[MAX_STR_LEN + 1];              /* char */
        lint    int_val;                           /* bit /tinyint/ smallint/ int/ */
        lint64  int64_val;                         /* int64 */
        double  double_val;                        /* double */
        float   float_val;                         /* float */
        byte    lob_val[MAX_LOB_LEN + 1];          /* blob/text, long data not filled */
        byte    bin_val[MAX_STR_LEN * 2 + 3];       /* binary/ varbinary, include 0x prefix */
        char    intv_str[MAX_PARAM_LEN];           /* interval_ym/interval_dt */
        byte    rowidstr[MAX_ROWID_LEN + 1];       /* rowid */
        byte    xdec_str[MAX_PARAM_LEN];           /* xdec */
        char    dt_str[MAX_PARAM_LEN];             /* date/time/datetime/time_tz/datetime_tz/datetime_tz */
    }val;
    lint     vallen;                                /* param data actual len, -2 indicate data null */

    MAGIC_DECLARE
};
#define paraminfo_MAGIC    94568456321
typedef struct paraminfo_struct PARAMINFO;

#define MSG_STARTUP_INFO_LEN 257 //startup info storage len
typedef struct msg_startup_info_struct  msg_startup_info_t;  /* The statup message info. */
struct msg_startup_info_struct
{
   char         info[MSG_STARTUP_INFO_LEN]; /* The startup message info.*/
};

typedef struct msg_info_struct  msg_info_t;  /* The msg extra info. */
struct msg_info_struct
{
   char         u[NAMELEN + 1];  /* The user extra info in the login message. */
};

#define res_info_MAGIC    682451224
typedef struct res_info_struct res_info_t;  /* The response info of the response message. */
struct res_info_struct
{
    lint     type;          /* The response statement type: Insert/Delete/Update/Select/Fetch/Other. */
    ulint    handle;        /* The statement handle. */

    lint64   affect_rows;   /* The affect rows in the current response message. */
    lint64   total_rows;    /* The total rows for the request statement sql. */

    MAGIC_DECLARE
};

#define req_info_MAGIC    686354112
typedef struct req_info_struct req_info_t;   /* The command type of the request message. */
struct req_info_struct
{
    lint    cmd_type;        /* The command type, type from interface ReqType */

    MAGIC_DECLARE
};

/*--------------------- type for interface ReqType -------------------*/
#define DM_MSG_LOGIN                   (usint)101 /*Login */
#define DM_MSG_LOGOUT                  (usint)102 /*Logout */
#define DM_MSG_STMT_ALLOCATE           (usint)103 /*Allocate a statement handle */
#define DM_MSG_STMT_FREE               (usint)104 /*Free a statement handle */
#define DM_MSG_PREPARE                 (usint)105 /*Prepare */
#define DM_MSG_FETCH                   (usint)106 /*Fetch */
#define DM_MSG_COMMIT                  (usint)107 /*Commit */
#define DM_MSG_ROLLBACK                (usint)108 /*Rollback */
#define DM_MSG_CANCEL                  (usint)109 /*Cancel */
#define DM_MSG_EXECUTE2                (usint)110 /*Bind params */
#define DM_MSG_PUT_DATA                (usint)111 /*Write lob data */
#define DM_MSG_GET_DATA                (usint)112 /*Get data request */
#define DM_MSG_CREATE_BLOB             (usint)113 /*Create a lob  */
#define DM_MSG_CLOSE_STMT              (usint)114 /*Close stmt handle */
#define DM_MSG_TIME_OUT                (usint)115 /*Time out */
#define DM_MSG_CURSOR_PREPARE          (usint)116 /*Prepare cursor */
#define DM_MSG_CURSOR_EXECUTE          (usint)117 /*Execute cursor */
#define DM_MSG_EXPLAIN                 (usint)118 /*Query plan */
#define DM_MSG_GET_DATA_ARR            (usint)119 /*Get data arr */
#define DM_MSG_GET_ROW_NUM             (usint)120 /*Get row num */
#define DM_MSG_GET_LOB_LEN             (usint)121 /*Get lob len */
#define DM_MSG_GET_LOB_DATA            (usint)122 /*Get lob data */
#define DM_MSG_MORE_RESULT             (usint)123 /*More result */
#define DM_MSG_EXEC_RETURN_AUTO_VALUE  (usint)124 /*Return into */
#define DM_MSG_RESET_SESS              (usint)125 /*Reset sess */
#define DM_MSG_PRE_EXEC                (usint)126 /*Plan in msg_execute when put data */
#define DM_MSG_EXEC_DIRECT             (usint)127 /*Const parameterized */
#define DM_MSG_STARTUP                 (usint)128 /*Startup */

#define DM_MSG_OTHER                   (usint)999 /*Other message type */

/*--------------------- MSGPARSE ERROR CODE-------------------*/
#define DM_INVALID_LEN                          -1   /* The message length is insufficient. */
#define DM_WR_MSG                               -2   /* The data cannot be identity. */
#define DM_INVALID_MSG_TYPE                     -3   /* Invalid message type. */
#define DM_RN_NEW_SQL                           -4   /* Not new sql. */
#define DM_OUT_OF_MSG_BUFF                      -5   /* Out of message buffer. */
#define DM_NO_SQL_OR_PARAM                      -6   /* No sql or param. */
#define DM_PARA_UNSUPPORT                       -7   /* Unsupported parameter type.*/

/*--------------------- err_no for interface CrtErrResp -------------------*/
#define DM_EC_INVALID_CLIENT_VESION             -11  /* Invalid client version */
#define DM_EC_UKEY_AUTH_MISMATCH                -12  /* UKEY authentication mismatch */
#define DM_EC_CONNECT_CAN_NOT_ESTABLISHED       -13  /* Fail to establish connection */
#define DM_EC_RN_INVALID_USER_NAME              -14  /* Invalid user name */
#define DM_EC_ENC_DECRYPT_FAIL                  -15  /* Fail to decrypt */
#define DM_EC_INVALID_PASSWORD                  -16  /* Invalid username or password */
#define DM_EC_RECV_OOB                          -17  /* Connection exception */
#define DM_EC_CONNECT_LOST                      -18  /* Connection lost */
#define DM_EC_INVALID_MSG                       -19  /* Invalid message */
#define DM_EC_OUT_OF_MSG_BUFFER                 -20  /* Message size is out of buffer  */

#define DM_EC_SUCCESS                           0    /* Execute success */

/*--------------------- MSGPARSE PARAM DATATYPES-------------------*/
#define DM_DATATYPE_CHAR         1   /*String */
#define DM_DATATYPE_BIT          2   /*Bit */
#define DM_DATATYPE_SMALLINT     3   /*Small int  */
#define DM_DATATYPE_INT          4   /*Int  */
#define DM_DATATYPE_INT64        5   /*Int64 */
#define DM_DATATYPE_FLOAT        6   /*Float */
#define DM_DATATYPE_DOUBLE       7   /*Double */
#define DM_DATATYPE_BINARY       8   /*Binary */
#define DM_DATATYPE_LOB          9   /*Lob */
#define DM_DATATYPE_IVYM         10  /*Interval year to month */
#define DM_DATATYPE_IVDT         11  /*Interval day to second */
#define DM_DATATYPE_ROWID        12  /*Rowid */
#define DM_DATATYPE_DEC          13  /*Decimal */
#define DM_DATATYPE_DATE         14  /*Date */
#define DM_DATATYPE_TIME         15  /*Time */
#define DM_DATATYPE_DATETIME     16  /*Datetime */
#define DM_DATATYPE_TIMETZ       17  /*Time with time zone */
#define DM_DATATYPE_DATETIME_TZ  18  /*Datetime with time zone */
#define DM_DATATYPE_COMP         19  /*Sarray array class record */
#define DM_DATATYPE_CURSOR       20  /*Cursor */
#define DM_DATATYPE_OTHER        21  /*Pltype_void pltype_object data_record */
#define DM_DATATYPE_DATETIME2     22  /* Datetime2 */
#define DM_DATATYPE_DATETIME2_TZ  23  /* Datetime2_tz */

/*--------------------- type for interface ResType -------------------*/
#define DM_RES_MSG_INSERT                  (usint)1001 /*Insert */
#define DM_RES_MSG_DELETE                  (usint)1002 /*Delete */
#define DM_RES_MSG_UPDATE                  (usint)1003 /*Update */
#define DM_RES_MSG_SELECT                  (usint)1004 /*Select */
#define DM_RES_MSG_FETCH                   (usint)1005 /*Fetch */
#define DM_RES_MSG_OTHER                   (usint)1006 /* Other */

/*-----------------------------------------------------------------------------
MSGPARSE CALL INTERFACE
------------------------------------------------------------------------------*/

/**************************************************************
Purpose:
Get request message packet type
***************************************************************/
DllExport
lint                         /* On success, 0 is returned. On error, < 0 is returned */
ReqType(
    byte*           buf,      /* IN£ºThe address of the message packet header. */
    lint            buflen,   /* IN£ºThe length of the message packet.*/
    lint*           type      /* OUT£ºReturn the packet type*/
);

/**********************************************************
Purpose:
Test whether the response data is logined  successful
**********************************************************/
DllExport
lint                          /* Yes, 1 is returned. On error,  0 is returned */
IsLogined(
    byte*               buf,        /* IN£ºThe address of the message packet header. */
    lint                buflen      /* IN£ºThe length of the message packet. */
);

/********************************************
Purpose:
Get info from the startup message
********************************************/
DllExport
lint                                /* On success, 0 is returned. On error, < 0 is returned */
StartupInfo(
    byte*                   buf,          /* IN£ºThe address of the message packet header. */
    lint                    buflen,       /* IN£ºThe length of the message packet. */
    msg_startup_info_t*     startup_info  /* OUT: The startup message info. */
);

/********************************************
Purpose:
Get the user extra info from the login request message
********************************************/
DllExport
lint                                /* On success, 0 is returned. On error, < 0 is returned */
LoginUser(
    byte*               buf,                    /* IN£ºThe address of the message packet header. */
    lint                buflen,                 /* IN£ºThe length of the message packet. */
    msg_startup_info_t* startup_info,           /* IN: The startup message info*/
    msg_info_t*         msg_info                /* OUT: The user extra info */
);

/***********************************************************
Purpose:
Test whether the request data contains the complete package.
************************************************************/
DllExport
lint                          /* Yes, 0 is returned. No, < 0£º error code is returned */
HaveAFullReqPack(
    byte*           buf,       /* IN£ºThe address of the message packet header. */
    lint            buflen,    /* IN£ºThe length of the message packet. */
    lint*           pPackLen   /* OUT£ºThe complete message packet total length */
);

/**************************************************
Purpose:
Check whether the request data is for the new SQL 
**************************************************/
DllExport
lint                        /* Yes, 0 is returned. No, < 0£ºerror code is returned */
IsNewSQL(
    byte*                   buf,    /* IN£ºThe address of the message packet header. */
    lint                    buflen  /* IN£ºThe length of the message packet. */
);

/****************************************************************************************************
Purpose:
Intercepts abnormal connections, to build response message packet that meet DAMENG standards, 
and notifies clients of abnormal connections in the form of error message.
****************************************************************************************************/
DllExport
lint                               /* On success, 0 is returned. On error, < 0 is returned */
CrtErrResp(
    lint            err_no,           /* IN: Error code. */
    char*           errmsg,           /* IN: Error txt. */
    byte*           respbuf,          /* OUT: the buf is used to build the response message.*/
    lint*           respbuflen        /* INOUT: The valid length of the respbuf when input, the actual length of the build response message when output. */
);

/****************************************************************
Purpose:
Extract the SQL and the parameters from the request message.
****************************************************************/
DllExport
lint                            /* On success, 0 is returned. On error, < 0 is returned */
ParseReq(
    unsigned char*      buf,       /* IN£ºThe address of the message packet header. */
    lint                buflen,    /* IN£ºThe length of the message packet. */
    char*               sql,       /* OUT£ºReturn the parsed SQL statement. */
    lint*               sqllen,    /* INOUT£ºThe valid length of the sql when input, the actual length of the sql when output. */
    PARAMINFO*          pParams,   /* OUT£ºThe param information storage struct.*/ 
    lint*               iParam     /* INOUT£ºThe valid number of the pParams when input, the actual number of the pParams when output. */
);

/****************************************************************
Purpose:
Extract the stmt info from the request message.
****************************************************************/
DllExport
lint                              /* On success, 0 is returned. On error, < 0 is returned */ 
ParseReqInfo(
    unsigned char*      buf,             /* IN£ºThe address of the message packet header. */
    lint                buflen,          /* IN£ºThe length of the message packet. */
    req_info_t*         req_info         /* OUT: The command type of the request message packet. */
);

/****************************************************************
Purpose:
Extract the stmt info from the response message.
****************************************************************/
DllExport
lint                              /* On success, 0 is returned. On error, < 0 is returned */
ParseRes(
    unsigned char*      buf,             /* IN£ºThe address of the message packet header. */
    lint                buflen,          /* IN£ºThe length of the message packet. */
    req_info_t*         req_info,        /* IN: The request message info*/
    res_info_t*         res_info         /* OUT: The response message info*/
);

/***********************************************************************
Purpose:
Obtain the communication version of the current message version
***********************************************************************/
DllExport
lint /* Return the current message version */
GetMsgVer(
);

#ifdef __cplusplus
}                                    /* End of extern "C" { */
#endif  /* __cplusplus */

#endif  /* #ifndef _MSGPARSE_PUB_H */
