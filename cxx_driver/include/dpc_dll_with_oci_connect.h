#ifndef _DPC_DLL_H
#define _DPC_DLL_H

#include "DPItypes.h"

#ifdef __cplusplus
extern "C" { 			/* Assume C declarations for C++   */
#endif  /* __cplusplus */

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifdef WIN32
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )
#else
#define DllImport
#define DllExport
#endif


struct sql_cursor
{
    unsigned int curocn;
    dhandle ptr;
    udint8 magic;
};

typedef struct sql_cursor sql_cursor;
typedef struct sql_cursor SQL_CURSOR;

#define DPC_CONNECT_CONNNAME    "DM7DBDEFAULTNAME"

#define DPC_C_CHAR          1
#define DPC_C_VARCHAR       2
#define DPC_C_TINYINT       3
#define DPC_C_SINT          4
#define DPC_C_INT           5
#define DPC_C_FLOAT         6
#define DPC_C_DOUBLE        7
#define DPC_C_BINARY        8
#define DPC_C_BIGINT        9
#define DPC_C_FILE          10
#define DPC_C_BLOB          11
#define DPC_C_CLOB          12
#define DPC_C_VARCHAR2      13
#define DPC_C_SQLCURSOR     14
#define DPC_C_CHARF         15
#define DPC_C_UINT          16      // [bug614507]无符号整数类型变量绑定
#define DPC_C_USINT         17      // 无符号short
#define DPC_C_UTINYINT      18      // 无符号byte
#define DPC_C_UBIGINT       19      // 无符号int64

/*FETCH TYPE*/
#define DPC_FETCH_NEXT      1
#define DPC_FETCH_FIRST     2
#define DPC_FETCH_LAST      3 
#define DPC_FETCH_PRIOR     4
#define DPC_FETCH_ABSOLUTE  5
#define DPC_FETCH_RELATIVE  6

#define DPC_LOB_FETCH_ONE		1
#define DPC_LOB_FETCH_FIRST		2
#define DPC_LOB_FETCH_NEXT 		3
#define DPC_LOB_FETCH_LAST  	4

//define diag attributes
#define DIAG_ATTR_NUMBER								(sdint4)0
#define DIAG_ATTR_MORE                                  (sdint4)1
#define DIAG_ATTR_COMMAND_FUNCTION                      (sdint4)2
#define DIAG_ATTR_DYNAMIC_FUNCTION                      (sdint4)3
#define DIAG_ATTR_ROW_COUNT                             (sdint4)4
#define DIAG_ATTR_CONDITION_NUMBER                      (sdint4)5
#define DIAG_ATTR_RETURNED_SQLSTATE                     (sdint4)6
#define DIAG_ATTR_CLASS_ORIGIN                          (sdint4)7
#define DIAG_ATTR_SUBCLASS_ORIGIN                       (sdint4)8
#define DIAG_ATTR_SERVER_NAME                           (sdint4)9
#define DIAG_ATTR_CONNECTION_NAME                       (sdint4)10
#define DIAG_ATTR_CONSTRAINT_CATALOG                    (sdint4)11
#define DIAG_ATTR_CONSTRAINT_SCHEMA                     (sdint4)12
#define DIAG_ATTR_CONSTRAINT_NAME                       (sdint4)13
#define DIAG_ATTR_CATALOG_NAME                          (sdint4)14
#define DIAG_ATTR_SCHEMA_NAME                           (sdint4)15
#define DIAG_ATTR_TABLE_NAME                            (sdint4)16
#define DIAG_ATTR_COLUMN_NAME                           (sdint4)17
#define DIAG_ATTR_CURSOR_NAME                           (sdint4)18
#define DIAG_ATTR_MESSAGE_TEXT                          (sdint4)19
#define DIAG_ATTR_MESSAGE_LENGTH                        (sdint4)20
#define DIAG_ATTR_MESSAGE_OCTET_LENGTH                  (sdint4)21

//define Descriptor attributes
#define DS_ATTR_COUNT					(sdint4)1

//define Item Descriptor attributes
#define IDS_ATTR_INVALID                    (sdint4)0
#define IDS_ATTR_CARDINALITY				(sdint4)1
#define IDS_ATTR_CHARACTER_SET_CATALOG		(sdint4)2
#define IDS_ATTR_CHARACTER_SET_NAME			(sdint4)3
#define IDS_ATTR_CHARACTER_SET_SCHEMA		(sdint4)4
#define IDS_ATTR_COLLATION_CATALOG			(sdint4)5
#define IDS_ATTR_COLLATION_NAME				(sdint4)6
#define IDS_ATTR_COLLATION_SCHEMA			(sdint4)7
#define IDS_ATTR_DATA						(sdint4)8
#define IDS_ATTR_DATETIME_INTERVAL_CODE		(sdint4)9
#define IDS_ATTR_DATETIME_INTERVAL_PRECISION	(sdint4)10
#define IDS_ATTR_DEGREE						(sdint4)11
#define IDS_ATTR_INDICATOR					(sdint4)12
#define IDS_ATTR_KEY_MEMBER					(sdint4)13
#define IDS_ATTR_LENGTH						(sdint4)14
#define IDS_ATTR_LEVEL						(sdint4)15
#define IDS_ATTR_NAME						(sdint4)16
#define IDS_ATTR_NULLABLE					(sdint4)17
#define IDS_ATTR_OCTET_LENGTH				(sdint4)18
#define IDS_ATTR_PARAMETER_MODE				(sdint4)19
#define IDS_ATTR_PARAMETER_ORDINAL_POSITION	(sdint4)20
#define IDS_ATTR_PARAMETER_SPECIFIC_CATALOG	(sdint4)21
#define IDS_ATTR_PARAMETER_SPECIFIC_NAME	(sdint4)22
#define IDS_ATTR_PARAMETER_SPECIFIC_SCHEMA	(sdint4)23
#define IDS_ATTR_PRECISION					(sdint4)24
#define IDS_ATTR_RETURNED_CARDINALITY		(sdint4)25
#define IDS_ATTR_RETURNED_LENGTH			(sdint4)26
#define IDS_ATTR_RETURNED_OCTET_LENGTH		(sdint4)27
#define IDS_ATTR_SCALE						(sdint4)28
#define IDS_ATTR_SCOPE_CATALOG				(sdint4)29
#define IDS_ATTR_SCOPE_NAME					(sdint4)30
#define IDS_ATTR_SCOPE_SCHEMA				(sdint4)31
#define IDS_ATTR_TYPE						(sdint4)32
#define IDS_ATTR_UNNAMED					(sdint4)33
#define IDS_ATTR_USER_DEFINED_TYPE_CATALOG	(sdint4)34
#define IDS_ATTR_USER_DEFINED_TYPE_NAME		(sdint4)35
#define IDS_ATTR_USER_DEFINED_TYPE_SCHEMA	(sdint4)36
#define IDS_ATTR_DESCRIPTORS_COUNT          (sdint4)37
#define IDS_ATTR_DATA_REF                   (sdint4)38
#define IDS_ATTR_USER_DEFINED_TYPE_NAME_LENGTH (sdint4)39
#define IDS_ATTR_USER_DEFINED_TYPE_SCHEMA_LENGTH (sdint4)40
#define IDS_ATTR_LASE                       IDS_ATTR_USER_DEFINED_TYPE_SCHEMA_LENGTH

#define IDS_LOB_ATTR_LENGTH                   0

#define DPC_VAL_INPUT           1
#define DPC_VAL_OUTPUT          2
#define DPC_VAL_INPUT_OUTPUT    3
#define DPC_VAL_INPUT_UNKONWN   4

#define DPC_INDICATOR_1BYTES    1
#define DPC_INDICATOR_2BYTES    2
#define DPC_INDICATOR_4BYTES    4
#define DPC_INDICATOR_8BYTES    8

/*
typedef unsigned char   udbyte;

typedef signed short    sdint2;
typedef unsigned short  udint2;

typedef   signed int    sdint4;                   
typedef unsigned int    udint4;                   

#ifdef WIN32
typedef __int64             sdint8;
typedef unsigned __int64    udint8;
#else
typedef long long int           sdint8;
typedef unsigned long long int  udint8;
#endif //DWINDOWS

typedef void *      dpointer;
*/

typedef int		dpc_bool_t;

typedef struct sql_indicator_struct sql_indicator_t; 

typedef struct sql_val_struct  sql_val_t;

/* define mode */
#define DPC_MODE_STD			1
#define DPC_MODE_DM			    2
#define DPC_MODE_ORACLE		    3
#define DPC_MODE_DB2			4

#define DPC_MAX_SSL_CONFIG      64


DllExport
void
dpc_set_mode(
    sdint4      mode
);

DllExport
void
dpc_set_type_mode(
    sdint4      mode
);

DllExport
void
dpc_set_unsafe_null(
    sdint4      unsafe_null
);

/*******************************************
perpose: 设置dyn_stmt_without_into标记
******************************************/
DllExport
void
dpc_set_dyn_stmt_without_into(
    sdint4          dyn_stmt_without_into  /* IN 查询动态SQL是否去掉INTO */
);

//connection
//DllExport
//void
//dpc_connect(
//    char*       server,
//    char*       user,
//    char*       pwd
//);

////////////////////////////// execute sql //////////////////////////////
//exec sql descriptor functions
DllExport
void
dpc_alloc_desc(
    char*      name,
    sdint2      max
);

DllExport
void
dpc_free_desc(
    char*      name
);

DllExport
void
dpc_alloc_desc_arr(
    char*      name,
    sdint2      max,
    sdint4      arr_size
);

DllExport
int
dpc_get_desc_field(
    char*      name,
    udint2      item_no,
    udint2      fld_id,
    sql_val_t*  val
);

DllExport
int
dpc_set_desc_field(
    char*      name,
    udint2      item_no,
    udint2      fld_id,
    sql_val_t*  val
);

DllExport
int
dpc_desc_input(
    char*      desc_name,
    char*      pre_name
);

DllExport
void
dpc_desc_output(
    char*      desc_name,
    char*      pre_name
);

DllExport
void
dpc_open_cursor_desc(
    char*      desc_name,
    char*      cur_name
);
//?PROC_INPUT_DESC_DESCRIBE
//?PROC_OUTPUT_DESC_DESCRIBE
//?PROC_EXEC_WITH_DESC
//?PROC_CUR_OPEN_WITH_DESC
//?PROC_CUR_FETCH_WITH_DESC
//?PROC_GET_DIAG_STMT
//?PROC_GET_DIAG
//?PROC_SET_DIAG_SIZE
//?PROC_SQLDA_DESCRIBE
//?PROC_SQLDA_FETCH
//?PROC_SQLDA_EXEC

//PROC_CONNECT
//PROC_DISCONNECT

//PROC_NORMAL
//PROC_CALL
DllExport
void
dpc_exec_normal(
    char*      cmd,
    char*      sql,
    udint2      arg_num,
    sql_val_t*  vals,
    udint2      for_size
);

// DllExport
// void
// dpc_exec_cursor_stmt(
//     char*      cmd,
// 	char*      name,
//     char*      sql,
//     udint2      arg_num,
//     sql_val_t*  vals,
//     udint2      for_size
// );

//PROC_COMMIT
DllExport
void
dpc_commit(int  release);

//PROC_ROLLBACK
DllExport
void
dpc_rollback(int  release);

//PROC_CUR_DECLARE
DllExport
void
dpc_declare_cursor(
    char*      name,
    char*      sql,
    udint2       arg_num,
    sql_val_t*   vals
);

DllExport
void
dpc_declare_cursor_dyn(
    char*      name,
    char*      dyn_name
);

DllExport
void
dpc_set_with_hold(
	char*      name,
	sdint4     with_hold
);


DllExport
void
dpc_close_cursor_by_name(
    char*      name
);

DllExport
void
dpc_close_cursor_by_handle(
    dhandle      cur
);

//diagnose information handle
DllExport
void
dpc_diag_get_attr(
    udint2          item_id,
    udint2          attr_id,
    sql_val_t*      val
);

DllExport
void
dpc_set_sqlca(
    void*        sqlca
);

//exec prepare
DllExport
void
dpc_prepare(
    char*      name,
    char*      sql
);

DllExport
void
dpc_dealloc_prepare(
	char*      name
);

DllExport
void
dpc_exec_immediate(
    char*      sql
);


//////////////////////////////////////////////////////////////////////////new bigen
DllExport
void
dpc_alloc_bind_items(
    sdint4  col_nums,
    void**  handle
);

DllExport
void
dpc_alloc_bind_items_for_rowbinding(
    sdint4  col_nums,
	sdint4	size_of_row,
    sdint4	size_of_row_ind,
    void**  ptr
);

/***************************************
purpose:
    申请游标绑定句柄
[NOTE]:
    use_cursor_bind设为y才使用
****************************************/
DllExport
void
dpc_alloc_cursor_bind_items_for_rowbinding(
    char*       name,               /* IN: 游标名 */
    void*       cur_var,            /* IN: 游标变量 */
    sdint2      io_type,            /* IN: 绑定参数类型 */
    sdint4      col_nums,           /* IN: 参数个数 */
    sdint4      size_of_row,        /* IN: 数据绑定行长 */
    sdint4      size_of_row_ind,    /* IN: 指示符行长 */
    void**      ptr                 /* OUT: 返回绑定句柄 */
);

DllExport
void
dpc_set_item_prop(
    void*   handle,
    udint2  nth,
    sdint2  propid,
    void*   prop
);

DllExport
void
dpc_bind_item(
    void*       handle,
    udint2      nth,
    char*     name,
    void*       val_ptr,
    udint2      val_type,
    slength      precison,
    slength      scale,
    slength      size,
    void*       indtr,
    udint2      ind_sz,
    sdint4      need_keep_ind
);

/************************************************
purpose:
    设置绑定参数和指示符的步长
************************************************/
DllExport
void
dpc_bind_array_of_struct(
    void*       handle,     /* IN: 绑定句柄 */
    udint2      nth,        /* IN: 绑定参数序号 */
    slength     pvskip,     /* IN: 绑定参数步长 */
    slength     indskip     /* IN: 绑定指示符步长 */
);

DllExport
void
dpc_free_bind_items(
    void*   handle    
);

DllExport
void
dpc_fetch(
    char*     name,
    void*       into_hndl,
    void*       using_hndl,
    char*     into_desc_name,
    char*     using_desc_name,
	udint2      for_size,
    sdint4      orient,
    sdint2      c_type,
    void*       data_ptr,
    sdint4      data_sz,
    sdint4      is_const
);

DllExport
void
dpc_exec_normal_ex(
    char*     sql,
    void*       bind_hndl,
    udint2      for_size
);

DllExport
void
dpc_declare_cursor_ex(
    char*     name,
    char*     sql,
    void*       bind_hndl
);

DllExport
void
dpc_open_cursor_ex(
    char*             name,
    void*               bind_hndl,
	udint2				for_size
);

DllExport
sdint4
dpc_get_data_not_found();

DllExport
sdint4
dpc_get_rt_info(
    sdint4*     code,
    char*     state
);

DllExport
sdint4
dpc_get_rt_info_ex(
    long*     code,
    char*     state
);

DllExport
void
dpc_connect_ex(
    char*         conn_name,
    unsigned short* conn_ind,
    char*         server,
    unsigned short* svr_ind,
    char*         user,
    unsigned short* user_ind,
    char*         pwd,
    unsigned short* pwd_ind
);

DllExport
void
dpc_disconnect_ex(
    char*         conn_name,
    unsigned short* conn_name_ind,
    sdint4          type
);

DllExport
void
dpc_set_connection_ex(
    char*         conn_name,
    unsigned short* conn_name_ind
);

DllExport
int
dpc_get_desc_field_ex(
    char*     desc_name,
    udint2      item_no,
    udint2      fld_id,   
    sdint2      pc_ctype,
    void*       data_ptr,       //数据地址
    sdint4      data_sz
);

DllExport
int
dpc_get_desc_field_ex_arr(
    char*     desc_name,
    udint2      item_no,
    udint2      fld_id, 
    sdint4      arr_size,
    sdint2      pc_ctype,
    void*       data_ptr,       //数据地址
    sdint4      data_sz
);

DllExport
int
dpc_get_desc_field_param_ex(
    char*     desc_name,
    sdint2      field_pc_ctype,
    void*       field_data_ptr,  //数据地址//0表示获取descriptor信息
    sdint4      field_data_sz,
    udint2      fld_id,   
    sdint2      pc_ctype,
    void*       data_ptr,       //数据地址
    sdint4      data_sz        //数据缓冲区长度。可能存在如下情况，调用者指定int,short等等不同长度的整数，可通过该长度的指示符获得整数的具体长度
);

DllExport
int
dpc_set_desc_field_ex(
    char*     desc_name,
    udint2      item_no,
    udint2      fld_id,
    sdint2      c_type,
    void*       data_ptr,
    sdint4      data_sz,
    udint2      is_const
);

DllExport
int
dpc_set_desc_field_ref_ex(
    char*     desc_name,
    udint2      item_no,
    udint2      fld_id,
    sdint2      c_type,
    void*       data_ptr,
    sdint4      data_sz,
    udint2      is_const
);

DllExport
int
dpc_set_desc_field_ex_arr(
    char*     desc_name,
    udint2      item_no,
    udint2      fld_id,
    sdint4      arr_size,
    sdint2      pc_ctype,    
    void*       data_ptr,
    sdint4      data_sz,
    udint2      is_const
);

DllExport
void 
dpc_load_sqlca_ex(
    void*		sqlca,
	sdint4		mode
);

DllExport
void
dpc_set_trans_ex(
    char*     iso_lvl,
    char*     access_mode,
    sdint2      c_type,
    void*       data_ptr,
    sdint4      data_sz,
    udint2      is_const
);

DllExport
void
dpc_set_session_ex(
	char*  auth_id
);

DllExport
void
dpc_set_timezone_ex(
	char*  timezone_value
);

DllExport
void
dpc_exec_prepare_ex(
    char*             pre_name,
    void*               into_hndl,
    void*               using_hndl,
    char*             into_desc_name,
    char*             using_desc_name,
	udint2				for_size
);

DllExport
void
dpc_diag_get_attr_ex(
    sdint2          item_id,
    udint2          attr_id,
    void*           diag_buf,
    udint4          buf_sz
);

DllExport
void
dpc_alloc_diag_diag();

DllExport
sdint4
dpc_get_diag_rt_info(
    sdint4*     code,
    char*     state
);

DllExport
sdint4
dpc_get_diag_rt_info_ex(
    long*     code,
    char*     state
);

DllExport
void
dpc_alloc_lob(
	void**		lobaddr
);

/*********************************************************
purpose:
    分配对象
*********************************************************/
DllExport
void
dpc_alloc_obj(
    void**      objaddr,        /* 对象地址 */
    udint2      obj_type,       /* 对象类型 */
    void**      objind,         /* 对象指示符地址 */
    udint2      for_size        /* 批量分配对象个数 */
);

/*********************************************************
purpose:
    获取对象成员值
*********************************************************/
DllExport
void
dpc_get_obj_val(
    void*       objaddr,        /* IN: 对象地址 */
    void*       obj_ind,        /* IN: 对象指示符 */
    udint2      obj_ind_sz,     /* IN: 对象指示符变量大小 */
    char*       name,           /* IN: 对象成员名 */
    udint2      val_type,       /* IN: 绑定变量类型 */
    void*       val_ptr,        /* OUT: 输出成员值变量地址 */
    slength     val_len,        /* IN: val大小 */
    void*       ind_ptr,        /* OUT: 指示符变量 */
    udint2      ind_sz,         /* IN:  指示符变量大小 */
    udint2      nth             /* IN: 保留参数，成员序号 */
);

/*********************************************************
purpose:
    分配对象
*********************************************************/
DllExport
void
dpc_collection_get(
    void*       objaddr,        /* IN: 对象地址 */
    void*       obj_ind,        /* IN: 对象指示符 */
    udint2      obj_ind_sz,     /* IN: 对象指示符变量大小 */
    udint2      val_type,       /* IN: 绑定变量类型 */
    void*       val_ptr,        /* OUT: 输出值变量地址 */
    slength     val_len,        /* IN: val大小 */
    void*       ind_ptr,        /* OUT: 指示符变量 */
    udint2      ind_sz,         /* IN:  指示符变量大小 */
    udint2      for_size        /* IN: 获取值个数 */
);

/*********************************************************
purpose:
    分配对象
*********************************************************/
DllExport
void
dpc_collection_append(
    void*       objaddr,        /* IN: 对象地址 */
    void*       obj_ind,        /* IN: 对象指示符 */
    udint2      obj_ind_sz,     /* IN: 对象指示符变量大小 */
    udint2      val_type,       /* IN: 绑定变量类型 */
    void*       val_ptr,        /* IN: 输出值变量地址 */
    slength     val_len,        /* IN: val大小 */
    void*       ind_ptr,        /* IN: 指示符变量 */
    udint2      ind_sz,         /* IN: 指示符变量大小 */
    udint2      for_size        /* IN: 插入值个数 */
);

/*************************************
purpose:
    释放object对象
****************************************/
DllExport
void
dpc_free_obj(
    void**      objaddr,        /* 对象地址 */
    udint2      obj_type,       /* 对象类型 */
    void**      objind,         /* 对象指示符地址 */
    udint2      for_size        /* 批量分配对象个数 */
);

/*************************************
purpose:
    重置array对象值offset偏移
****************************************/
DllExport
void
dpc_collection_reset(
    void*       objaddr,        /* 对象地址 */
    void*       objind,         /* 对象指示符地址 */
    udint2      ind_size        /* 对象指示符大小 */
);

/*************************************
purpose:
    获取array对象描述信息
****************************************/
DllExport
void
dpc_get_coll_attr(
    void*       objaddr,        /* 对象 */
    void*       objind,         /* 对象指示符地址 */
    udint2      ind_size,       /* 对象指示符大小 */
    sdint4      attr_id,        /* 属性id */
    udint2      val_type,       /* 绑定buf类型 */
    void*       val_ptr,        /* 绑定buf地址 */
    sdint2      size,           /* 绑定buf大小 */
    void*       ind_ptr,        /* 绑定buf指示符 */
    udint2      ind_sz          /* 绑定buf指示符大小 */
);

DllExport
void
dpc_free_lob(
	void*  lob
);

DllExport
void
dpc_read_lob(
	void*    lob,
	udint4	 offset,
	sdint4	 pctype,
	dpointer data_to_read,
	sdint4	 data_to_read_size,
	dpointer val_buf, 
	sdint4   buf_len
);

DllExport
void
dpc_write_lob(
	void*    lob,	
	udint4	 offset,
	sdint4	 pctype,
	dpointer data_to_write,
	sdint4	 data_to_write_size,
	dpointer val_buf,
	sdint4   buf_len,
	udint4	 app_flag,
	udint4	 chosen
);

DllExport
void
dpc_get_lob_attr(
	void*		lob,
	sdint4		attr_id,
	udint2      val_type,
	void*       val_ptr,
    sdint2      size,
    void*       ind_ptr,
    udint2      ind_sz
);

DllExport
void
dpc_alloc_cursor(
    sql_cursor*  cur,
	char*		lob_name
);

DllExport
void
dpc_free_cursor(
    dhandle      cur
);

DllExport
void
dpc_fetch_var(
    dhandle     var,
    void*       into_hndl,
    void*       using_hndl,
    char*     into_desc_name,
    char*     using_desc_name,
	udint2      for_size,
    sdint4      orient,
    sdint2      c_type,
    void*       data_ptr,
    sdint4      data_sz,
    sdint4      is_const
);

DllExport
void*
dpc_get_cur_context(
);


DllExport
void
dpc_context_alloc(
    void**       context
);

DllExport
void*
dpc_context_use(
    void*       context,
    sdint2      mode
);


DllExport
void
dpc_context_free(
    void**       context
);

DllExport
void
dpc_switch_conn(
    char*       conn_name
);

DllExport
void
dpc_enable_threads();

/****************************************
perpose :多进程调试时打印信息
*************************************** */
DllExport
void
dpc_show();

DllExport
void
dpc_exec_select_into(
    char*     sql,
    void*       into_hndl,
    void*       bind_hndl,
    udint2      for_size
);


DllExport
void
dpc_prepare_ex(
    char*           name,
    char*           sql,
    unsigned short* sql_ind
);

DllExport
void
dpc_autocommit();

DllExport
void
dpc_autocommit_off();

DllExport
void
dpc_exec_immediate_ex(
    char*          sql,
    unsigned short* sql_ind
);

DllExport
void
dpc_get_xa_conn();

DllExport
void
dpc_read_lob_for_varchar(
    void*               lob_name,
    udint4              offset,
    sdint4              pctype,
    dpointer            data_to_read,
    sdint4              data_to_read_size,
    dpointer            val_buf,
    sdint4              buf_len     /* IN:缓冲区空间大小(0:varchar指针; 非0:varchar数组) */
);

DllExport
void
dpc_write_lob_for_varchar(
    void*               lob_name,           /* IN:大字段对象 */
    udint4              offset,             /* IN:大字段偏移 */
    sdint4              pctype,             /* IN:大字段类型 */
    dpointer            data_to_write,      /* IN:写入长度指示符 */
    sdint4              data_to_write_size, /* IN:指示符大小 */
    dpointer            val_buf,            /* IN:数据缓冲区 */
    sdint4              buf_len,            /* IN:缓冲区空间大小(0:varchar指针; 非0:varchar数组) */
    udint4              app_flag,           /* IN:是否为追加方式写入 */
    udint4              chosen              /* IN:大字段分片写入方式 */
);

#ifdef _OciConnect

DllExport
void
dpc_connect_ex_with_oci(
    char*         conn_name,
    unsigned short* conn_ind,
    char*         server,
    unsigned short* svr_ind,
    char*         user,
    unsigned short* user_ind,
    char*         pwd,
    unsigned short* pwd_ind
);

DllExport
sdint4
SQLEnvGet(
    void*   context,
    void**  oeh
);

DllExport
sdint4
SQLSvcCtxGet(
    void           *context,
    char           *dbname,
    int             dbnamelen,
    void            **svc
);

#endif//_DciConnect


/**********************************************
purpose:
    从游标上申请绑定句柄空间
**********************************************/
DllExport
void
dpc_alloc_cursor_bind_items(
    char*       cur_name,       /* IN: 游标名 */
    void*       cur_var,        /* IN: 游标变量 */
    sdint2      io_type,        /* IN: 绑定句柄类型 */
    sdint4      col_nums,       /* IN: 参数个数 */
    void**      ptr             /* OUT: 返回绑定句柄 */
);

/***********************************************
Purpose:
    设置成员详细信息,REF data
Note:
    封装inner接口，生成dpc_trace
***********************************************/
DllExport
int
dpc_set_desc_field_ref_ex_arr(
    char*       desc_name,
    udint2      item_no,
    udint2      fld_id,
    sdint4      arr_size,
    sdint2      pc_ctype,
    void*       data_ptr,
    sdint4      data_sz,
    udint2      is_const
);

//////////////////////////////////////////////////////////////////////////new end
#ifdef __cplusplus
}                                    /* End of extern "C" { */
#endif  /* __cplusplus */
#endif//_DPC_DLL_H

