#ifndef MSG_PARSE_H
#define MSG_PARSE_H

#ifdef __cplusplus
extern "C" { 			/* Assume C declarations for C++   */
#endif  /* __cplusplus */

#ifdef WIN32
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )
#else
#define DllImport
#define DllExport
#endif

#ifdef dm_usint
#undef dm_usint
#endif
typedef unsigned short      dm_usint;

#ifdef dm_sint
#undef dm_sint
#endif
typedef short               dm_sint;

#ifdef dm_schar
#undef dm_schar
#endif
typedef signed char         dm_schar;

#ifdef dm_byte
#undef dm_byte
#endif
typedef unsigned char       dm_byte;

#ifdef dm_ulint
#undef dm_ulint
#endif
typedef unsigned int        dm_ulint; 

#ifdef dm_lint
#undef dm_lint
#endif
typedef int                 dm_lint;

#ifdef dm_lint64
#undef dm_lint64
#endif
#ifdef WIN32
typedef __int64             dm_lint64;
#else
typedef long long int       dm_lint64;
#endif

// input or output flag
#define MSG_PARA_IO_IN			0x00
#define MSG_PARA_IO_OUT			0x01
#define MSG_PARA_IO_INOUT       0x02

// message type
#define MSG_REQUEST     0
#define MSG_RESPONSE    1

// data type
#define DM_DATA_CHAR		    0           /* CHAR     */
#define DM_DATA_VARCHAR2	    1			/* VARCHAR2  */
#define DM_DATA_VARCHAR	        2           /* VARCHAR  */
#define DM_DATA_BIT		        3           /* BIT STRING */
#define DM_DATA_TINYINT    	    5           /* TINY INTEGER, 1 bytes */
#define DM_DATA_SMALLINT   	    6           /* SMALL INTEGER, 2 bytes */
#define DM_DATA_INT	    	    7           /* INTEGER 4 bytes */
#define DM_DATA_INT64	    	8			/* INTEGER 8 bytes */
#define DM_DATA_XDEC            9
#define DM_DATA_FLOAT	    	10          /* FLOAT, SINGLE */
#define DM_DATA_DOUBLE	    	11          /* DOUBLE */
#define DM_DATA_BLOB	    	12          /* BINARY LARGE OBJECT */
#define DM_DATA_DATE	    	14          /* DATE*/
#define DM_DATA_TIME            15          /* TIME*/
#define DM_DATA_DATETIME        16          /* DATE TIME */
#define DM_DATA_BINARY	    	17          /* BINARY */
#define DM_DATA_VARBINARY  	    18          /* VAR BINARY */
#define DM_DATA_TEXT		    19			/* TEXT */
#define DM_DATA_INTERVAL_YM     20          /* INTERVAL YEAR MONTH */
#define DM_DATA_INTERVAL_DT     21          /* INTERVAL DAY TIME */
#define DM_DATA_TIME_TZ		    22			/* TIME WITH ZONE */
#define DM_DATA_DATETIME_TZ	    23			/* DATE TIME WITH ZONE */
#define DM_DATA_TYPE_REF        42          /* REF TYPE */

// request commond type
#define	DM_CMD_LOGIN				    (dm_usint)1
#define DM_CMD_STMT_ALLOCATE		    (dm_usint)3
#define DM_CMD_STMT_FREE			    (dm_usint)4
#define	DM_CMD_PREPARE				    (dm_usint)5
#define	DM_CMD_EXECUTE				    (dm_usint)6
#define	DM_CMD_FETCH				    (dm_usint)7
#define	DM_CMD_COMMIT				    (dm_usint)8
#define	DM_CMD_ROLLBACK			        (dm_usint)9
#define DM_CMD_EXECUTE2                 (dm_usint)13
#define DM_CMD_PUT_DATA			        (dm_usint)14
#define DM_CMD_GET_DATA			        (dm_usint)15
#define DM_CMD_CLOSE_STMT			    (dm_usint)17
#define DM_CMD_CHECK_TAB_FAST_INS       (dm_usint)23
#define DM_CMD_CURSOR_SET_NAME		    (dm_usint)27
#define DM_CMD_GET_LOB_LEN              (dm_usint)29
#define DM_CMD_SET_LOB_DATA             (dm_usint)30
#define DM_CMD_LOB_TRUNCATE             (dm_usint)31
#define DM_CMD_GET_LOB_DATA             (dm_usint)32
#define DM_CMD_MORE_RESULT              (dm_usint)44
#define DM_CMD_EXEC_RETURN_AUTO_VALUE   (dm_usint)45
#define DM_CMD_BCP_SET				    (dm_usint)47
#define DM_CMD_BCP_INSERT			    (dm_usint)48
#define DM_CMD_BCP_CLR				    (dm_usint)49
#define DM_CMD_SESS_ISO                 (dm_usint)52
#define DM_CMD_FLDR_GET_TABLE_INFO      (dm_usint)53
#define DM_CMD_FLDR_SET                 (dm_usint)54
#define DM_CMD_FLDR_INSERT              (dm_usint)55
#define DM_CMD_FLDR_CLR                 (dm_usint)56
#define DM_CMD_CLR_RT_ENV               (dm_usint)57
#define DM_CMD_FLDR_CLR_INDEX           (dm_usint)58
#define DM_CMD_FLDR_DESTROY             (dm_usint)59
#define DM_CMD_FLDR_BLOB                (dm_usint)61
#define DM_CMD_FLDR_LOB_PUT             (dm_usint)62
#define DM_CMD_TABLE_TS                 (dm_usint)71
#define DM_CMD_PRE_EXEC                 (dm_usint)90
#define DM_CMD_EXEC_DIRECT              (dm_usint)91
#define	DM_CMD_PRE_COMMIT               (dm_usint)92
#define	DM_CMD_SYNC_LOGIN			    (dm_usint)107
#define DM_CMD_FLDR_SET2                (dm_usint)111
#define DM_CMD_FLDR_GET_TABLE_MPP_INFO  (dm_usint)112
#define DM_CMD_FLDR_FRESH_IDENTITY      (dm_usint)113
#define DM_CMD_STARTUP				    (dm_usint)200

// sql type                      
#define DM_BASE				            (dm_usint)127                                           
#define DM_COMMIT                       (dm_usint)(DM_BASE + 20)        
#define DM_ROLLBACK                     (dm_usint)(DM_BASE + 21)         
#define DM_EXPLAIN                      (dm_usint)(DM_BASE + 22)           
#define DM_SET_TRAN                     (dm_usint)(DM_BASE + 23)         
#define DM_SET_CURSCH                   (dm_usint)(DM_BASE + 26)        
#define DM_DML_INSERT                   (dm_usint)(DM_BASE + 30)        
#define DM_DML_DELETE                   (dm_usint)(DM_BASE + 31)    
#define DM_DML_UPDATE                   (dm_usint)(DM_BASE + 32)        
#define DM_DML_SELECT                   (dm_usint)(DM_BASE + 33)        
#define DM_DML_SELECT_INTO              (dm_usint)(DM_BASE + 34)     
#define DM_DML_CALL                     (dm_usint)(DM_BASE + 35)          
#define DM_DML_MERGE                    (dm_usint)(DM_BASE + 37)          
#define DM_SET_TIME_ZONE                (dm_usint)(DM_BASE + 38)       
#define DM_SET_SESS_TRAN                (dm_usint)(DM_BASE + 39)       
#define DM_DML_CURSOR_UPDATE            (dm_usint)(DM_BASE + 73)    
#define DM_DML_CURSOR_DELETE            (dm_usint)(DM_BASE + 74)      

typedef void*       pdhndl;     // parameter description handle
typedef void*       cdhndl;     // column description handle

typedef struct  dm_lob_struct dm_lob_t;
struct  dm_lob_struct 
{
    dm_schar*       v_str;          // blob or text

    dm_byte         outrow_flag;    // 1:out row lob£¬0:in row lob
};

typedef struct msg_data_struct msg_data_t;
struct msg_data_struct
{
    dm_ulint   null_flag;           // 0:NULL,1:NOT NULL
    
    union
    {
        dm_schar*       v_str;      // DATA_CHAR,DATA_VARCHAR2,DATA_VARCHAR
                                    // DATA_XDEC,DATA_BINARY,DATA_VARBINARY,DATA_TYPE_REF
                                    // DATA_TIME,DATA_DATETIME,DATE_TIME_TZ,DATA_DATETIME_TZ
                                    // DM_DATA_INTERVAL_YM,DM_DATA_INTERVAL_DT

        dm_lint         v_int;      // DATA_INT,DATA_TINYINT,DATA_SMALLINT,DATA_BIT
        dm_lint64       v_int64;    // DATA_INT64
        float           v_float;    // DATA_FLOAT
        double          v_double;   // DATA_DOUBLE
        dm_lob_t        v_lob;      // DATA_TEXT,DATA_BLOB
    }data;
};

typedef struct msg_param_desc_struct msg_param_desc_t;
struct msg_param_desc_struct
{
    dm_usint				    seqno;       // parameter bind sequence
    dm_byte                     io_flag;     // input or output
	dm_usint                    sql_pl_type; // simple data type, not support cursor or complex type
};

// request: login
typedef struct msg_login_struct msg_login_t;
struct msg_login_struct
{
    // message don't include ip,mac address,os user
	dm_schar		    host_name[129]; /** max length 128 */
    dm_schar            appname[129];   /** max length 128 */
    dm_schar            username[256];  /** plain or cipher */

};

// request: prepare
typedef struct msg_prepare_struct msg_prepare_t;
struct msg_prepare_struct
{
    dm_ulint       sql_len;   /** sql length */
    dm_schar*      sql_text;  /** prepare sql */

};

// request: execute
typedef struct msg_execute_struct msg_execute_t;
struct msg_execute_struct
{

    dm_ulint	            n_para_rows;	/** parameter row number */
    dm_ulint                param_num;      /** parameter number */
    msg_param_desc_t*       params_desc;    /** parameter description */
    msg_data_t* 		    params_data;    /** parameter data */

};

// request: execute directly
typedef struct msg_exec_direct_struct msg_exec_direct_t;
struct msg_exec_direct_struct
{
    msg_prepare_t   prepare;        // sql text
    msg_execute_t   execute;        // parameter information
};

// request: put lob data
typedef struct msg_put_data_struct msg_put_data_t;
struct msg_put_data_struct
{
    dm_ulint               bytes_to_write; // byte number
    dm_schar*              lob_data;       // hexadecimal lob data
};

// request: set lob data
typedef struct msg_set_lob_data_struct msg_set_lob_data_t;
struct msg_set_lob_data_struct
{
    dm_ulint               bytes_to_write;    // byte number
    dm_byte                byte_flag;         // 0: BLOB,1:TEXT
    dm_schar*              lob_data;          // blob or text data
};

// request information
typedef struct msg_req_info_struct  msg_req_info_t;
struct msg_req_info_struct 
{
    dm_usint        req_cmd_type;       // request command type
    dm_usint        resp_cmd_type;      // response command type  

    union
    {
        msg_login_t             msg_login;          // login information
        msg_prepare_t           msg_prepare;        // sql text
        msg_execute_t           msg_execute;        // parameter information
        msg_exec_direct_t       msg_exec_direct;    // sql text and parameter information
        msg_put_data_t          msg_put_data;       // put lob data
        msg_set_lob_data_t      msg_set_lob_data;   // set lob data

    }info;
};

/** result set's column data*/
typedef struct msg_rs_col_struct msg_rs_col_t;
struct msg_rs_col_struct
{
    dm_usint                    sql_pl_type;    // simple column type, not support cursor or complex type

    msg_data_t*                 data_arr;       // column data array
};

typedef struct msg_res_exec_call_struct msg_res_exec_call_t;
struct msg_res_exec_call_struct
{
    dm_lint64               affect_rows;        /** affect row number */

    dm_usint                n_out_params;       /** output parameter number */
    msg_param_desc_t*       params_desc;        /** output parameter description */
    msg_data_t* 		    params_data;        /** output parameter data */

    dm_ulint                cur_rs_rows;        /** result set's row number */
    dm_usint                n_cols;             /** result set's column number */
    cdhndl                  cdesc;              /** result set's description handle */
    msg_rs_col_t*           cols_data;          /** result set's data */
};

typedef struct msg_res_exec_cursor_ud_struct msg_res_exec_cursor_ud_t;
struct msg_res_exec_cursor_ud_struct
{
    dm_lint64               affect_rows;        /** affect row number */

    dm_usint                n_out_params;       /** output parameter number */
    msg_param_desc_t*       params_desc;        /** output parameter description */
    msg_data_t*             params_data;        /** output parameter data */
};

typedef struct msg_res_exec_sel_struct msg_res_exec_sel_t;
struct msg_res_exec_sel_struct
{
    dm_lint64               affect_rows;        /** affect row number */

    dm_ulint                cur_rs_rows;        /** result set's row number */
    dm_usint                n_cols;             /** result set's column number */
    cdhndl                  cdesc;              /** result set's description handle */
    msg_rs_col_t*           cols_data;          /** result set's data */
};

typedef struct msg_res_exec_sel_into_struct msg_res_exec_sel_into_t;
struct msg_res_exec_sel_into_struct
{
    dm_lint64               affect_rows;        /** affect row number */

    dm_usint                n_out_params;       /** output parameter number */
    msg_param_desc_t*       params_desc;        /** output parameter description */
    msg_data_t* 		    params_data;        /** output parameter data */
};

typedef struct msg_res_exec_idu_struct msg_res_exec_idu_t;
struct msg_res_exec_idu_struct
{
    dm_lint64               affect_rows;        /** affect row number */

    dm_usint                n_out_params;       /** output parameter number */
    msg_param_desc_t*       params_desc;        /** output parameter description */
    msg_data_t* 		    params_data;        /** output parameter data */
};

// execute
typedef struct msg_res_execute_struct msg_res_execute_t;
struct msg_res_execute_struct
{
    dm_usint        sql_type;       /** sql type */

    dm_byte*        prt_msg;        /** print information */

    union
    {
        msg_res_exec_call_t         msg_call;           /** call */
        msg_res_exec_cursor_ud_t    msg_cursor_ud;      /** cursor update or cursor delete */
        msg_res_exec_sel_t          msg_sel;            /** select */
        msg_res_exec_sel_into_t     msg_sel_into;       /** select into */
        msg_res_exec_idu_t          msg_idu;            /** update,insert,delete */
    }info;
};

// prepare
typedef struct msg_res_prepare_struct msg_res_prepare_t;
struct msg_res_prepare_struct
{
    pdhndl          pdesc;      // parameter description handle
    cdhndl          cdesc;      // column description handle
};

// fetch data
typedef struct msg_res_fetch_struct msg_res_fetch_t;
struct msg_res_fetch_struct
{
    dm_ulint        n_rows;         /** result set's row number*/

    dm_usint        n_cols;         /** result set's column number */
    msg_rs_col_t*   cols_data;      /** result set's data */
};

// get data
typedef struct msg_res_get_data_struct msg_res_get_data_t;
struct msg_res_get_data_struct
{
    dm_ulint        n_bytes;        /** byte number */

    dm_byte*        data;           /** hexadecimal lob data */
};

// get lob data
typedef struct msg_res_get_lob_data_struct msg_res_get_lob_data_t;
struct msg_res_get_lob_data_struct
{
    dm_ulint        n_bytes;        /** byte number */

    dm_byte*        data;           /** hexadecimal lob data */
};

// more result
typedef struct msg_res_more_result_struct msg_res_more_result_t;
struct msg_res_more_result_struct
{
    dm_byte                 has_rs;     /** whether has got data, 0:NO,1:YES */
    msg_res_exec_sel_t      msg_sel;    /** result set */
};

// response information
typedef struct msg_res_info_struct  msg_res_info_t;
struct msg_res_info_struct
{
    dm_usint        cmd_type;           /** command type */

    dm_lint         code;               /** error code */

    union
    {
        msg_res_prepare_t       msg_prepare;        /** prepare */
        msg_res_execute_t       msg_execute;        /** execute */
        msg_res_fetch_t         msg_fetch;          /** fetch */
        msg_res_get_data_t      msg_get_data;       /** get data */
        msg_res_more_result_t   msg_more_rs;        /** more result */
        msg_res_get_lob_data_t  msg_get_lob_data;   /** get lob data */
    }info;
};

typedef struct msg_info_struct msg_info_t;
struct msg_info_struct
{
    dm_byte                 msg_type;

    union
    {
        msg_req_info_t      info_req;       // request information
        msg_res_info_t      info_res;       // response information
    }msg;
};

DllExport
dm_lint
msg_parse_req(
    dm_byte*            msg_in,     /** request message */
    msg_info_t**        info_out    /** out information */
);

DllExport
dm_lint
msg_parse_resp(
    dm_byte*            msg_in,         /** response message */
    dm_ulint            msg_len,        /** message length */
    dm_usint            cmd_type,       /** request command type*/
    pdhndl              pdesc,          /** prepare parameter description information */
    cdhndl              cdesc,          /** prepare column description information */
    msg_info_t**        info_out        /** out information*/
);

DllExport
void
msg_info_free(
    msg_info_t*     msg_info
);

/*show msg*/
DllExport
void
msg_show(
    msg_info_t*     msg_info
);

#ifdef __cplusplus
}                                    /* End of extern "C" { */
#endif  /* __cplusplus */

#endif
