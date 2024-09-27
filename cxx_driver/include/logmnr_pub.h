#ifndef LOGMNR_PUB_H
#define LOGMNR_PUB_H

#include "dm.h"
#include "dmerr.h"
#include "dmstr.h"
#include "dop.h"
#include "rt_mo.h"
#include "ndct.h"

#define  LOGMNR_NEWFILE         1
#define  LOGMNR_REMOVEFILE      2
#define  LOGMNR_ADDFILE         3

/*
* START_LSN, COMMIT_LSN, CSCN, ROLLBACK, START_TS, COMMIT_TS
* 这几列的值跟事务相关，在dtab_logmnr_contents_build_data_low填充时计算，
* 因为它需要遍历日志文件中的记录，找到记录所在事务开始和结束的点
*/
#define LOGMNR_BDTA_LSN             0
#define LOGMNR_BDTA_TIMESTAMP       1
#define LOGMNR_BDTA_START_LSN       2
#define LOGMNR_BDTA_COMMMIT_LSN     3
#define LOGMNR_BDTA_START_TS        4
#define LOGMNR_BDTA_COMMIT_TS       5
#define LOGMNR_BDTA_TRXID           6
#define LOGMNR_BDTA_OPER            7
#define LOGMNR_BDTA_OPER_CODE       8
#define LOGMNR_BDTA_SCHNAME         9
#define LOGMNR_BDTA_REC_ROWID       10
#define LOGMNR_BDTA_USERNAME        11
#define LOGMNR_BDTA_OBJID           12
#define LOGMNR_BDTA_OBJV            13
#define LOGMNR_BDTA_SQL_REDO        14
#define LOGMNR_BDTA_SQL_UNDO        15
#define LOGMNR_BDTA_RS_ID           16
#define LOGMNR_BDTA_SSN             17
#define LOGMNR_BDTA_CSF             18
#define LOGMNR_BDTA_STATUS          19
#define LOGMNR_BDTA_COL_DATAS       20
#define LOGMNR_BDTA_REDO_VALUE      21
#define LOGMNR_BDTA_UNDO_VALUE      22
#define LOGMNR_BDTA_TABLE_NAME      23
#define LOGMNR_BDTA_RBA_SEQ         24
#define LOGMNR_BDTA_RBA_BLK         25
#define LOGMNR_BDTA_RBA_OFFSET      26
#define LOGMNR_BDTA_TRXID_NUMBER    27
#define LOGMNR_BDTA_CSCN            28
#define LOGMNR_BDTA_ROLLBACK        29
#define LOGMNR_BDTA_TRX_INNER_SEQ   30
#define LOGMNR_BDTA_SESSION_INFO    31
#define LOGMNR_BDTA_SUBTAB_ID       32
#define LOGMNR_BDTA_SESSION_ID      33

//用以初始化logmnr log上的 bdta, 字段信息为v$logmnr_contents的子集 + 附加的1个字段 COL_DATAS
#define  LOGMNR_MTABLE_COLS_NUM  34

#define LOGMNR_OP_INTERNAL   0
#define LOGMNR_OP_INSERT     1
#define LOGMNR_OP_DELETE     2
#define LOGMNR_OP_UPDATE     3
#define LOGMNR_OP_BUPD       4  // dm特有的，批量更新
#define LOGMNR_OP_DDL        5 
#define LOGMNR_OP_START      6
#define LOGMNR_OP_COMMIT     7
#define LOGMNR_OP_SEL_LOB    9
#define LOGMNR_OP_LOB_WRITE  10
#define LOGMNR_OP_LOB_TRIM   11
#define LOGMNR_OP_INSERT_FAST   12  // dm特有的，批量插入
#define LOGMNR_OP_LOB_NEW    13     // dm特有的，行外大字段LOB_NEW
#define LOGMNR_OP_LOB_DATA   14     // dm特有的，行外大字段LOB_DATA
#define LOGMNR_OP_SEL_UPD    25
#define LOGMNR_OP_LOB_ERASE  28
#define LOGMNR_OP_MIS_LSN    34
#define LOGMNR_OP_ROLLBACK   36
#define LOGMNR_OP_SEQ_MODIFY 37
#define LOGMNR_OP_XA_COMMIT  38
#define LOGMNR_OP_UNSUPPORT  255

#define LOGMNR_TYPE_ARCHIVED    1
#define LOGMNR_TYPE_ONLINE      2

#define LOGMNR_MAX_CACHE_ITEM   1000

#define  LOGMNR_UNDO 1
#define  LOGMNR_REDO 0

#define  LOGMNR_OPTION_COMMIT_ONLY     2
#define  LOGMNR_OPTION_SKIP_CORRUPTION 4
#define  LOGMNR_OPTION_DDL_TRACKING    8
#define  LOGMNR_OPTION_ONLINE_DICT     16
#define  LOGMNR_OPTION_REDOLOG_DICT    32
#define  LOGMNR_OPTION_NO_DELIMITER    64
#define  LOGMNR_OPTION_PRETTY_SQL      512
#define  LOGMNR_OPTION_CONTINUOUS      1024
#define  LOGMNR_OPTION_NO_ROWID        2048
#define  LOGMNR_OPTION_STRING_LITERALS 4096

#define LOGMNR_INTERNAL   "INTERNAL"
#define LOGMNR_INSERT     "INSERT"
#define LOGMNR_DELETE     "DELETE"
#define LOGMNR_UPDATE     "UPDATE"
#define LOGMNR_BUPD       "BATCH_UPDATE"
#define LOGMNR_DDL        "DDL"
#define LOGMNR_START      "START"
#define LOGMNR_COMMIT     "COMMIT"
#define LOGMNR_SEL_LOB    "SEL_LOB_LOCATOR"
#define LOGMNR_LOB_WRITE  "LOB_WRITE"
#define LOGMNR_LOB_TRIM   "LOB_TRIM"
#define LOGMNR_INSERT_FAST "INSERT_FAST"
#define LOGMNR_SEL_UPD    "SELECT_FOR_UPDATE"
#define LOGMNR_LOB_ERASE  "LOB_ERASE"
#define LOGMNR_MIS_LSN    "MISSING_SCN"
#define LOGMNR_ROLLBACK   "ROLLBACK"
#define LOGMNR_XA_COMMIT  "XA_COMMIT"
#define LOGMNR_UNSUPPORT  "UNSUPPORTED"
#define LOGMNR_START      "START"
#define LOGMNR_SEQ_MODIFY "SEQ MODIFY"
#define LOGMNR_LOB_NEW    "LOB_NEW"
#define LOGMNR_LOB_DATA   "LOB_DATA"

typedef struct logmnr_tid_lsn_struct logmnr_tid_lsn_t;
typedef DM_LIST_BASE_NODE_T(logmnr_tid_lsn_t) logmnr_trxid_lst_t;

#define logmnr_tid_lsn_MAGIC   76876619
struct logmnr_tid_lsn_struct
{
    ulint64           trx_id; 
    ulint64           lsn;
    ulint             type;
    dmtime_t          time;
    ulint             seq; 

    hash_node_t       hash; 

    DM_LIST_NODE_T(logmnr_tid_lsn_t) 
        link;

    MAGIC_DECLARE
};

/* 不对外公开的信息
* 从logmnr_client.h中移除到logmnr_pub.h
*/
#define logmnr_col_item_MAGIC   76876640
typedef struct logmnr_col_item_struct logmnr_col_item_t;
struct logmnr_col_item_struct
{
	usint		colid; //列id号
	sysname_t	name;  //列名
	ulint		type;  //列类型

    MAGIC_DECLARE
};

/* 不对外公开的信息
* 从logmnr_client.h中移除到logmnr_pub.h
*/
#define logmnr_client_dict_item_MAGIC   76876641
typedef struct logmnr_client_dict_item_struct logmnr_client_dict_item_t;
struct logmnr_client_dict_item_struct
{
    ulint				obj_id;	            //对象id号
    sysname_t			obj_name;           //对象名
	ulint				obj_type;			//对象类型：表、模式或用户

	//只有表的时候会用到下面几个属性
	usint               n_col_space;
	usint               cols_num;       //列数
	logmnr_col_item_t** cols_arr;       //列信息
    dmtime_t            create_time;    //表对象的创建时间

	ulint				n_fixed;		//当前连接有多少个线程占有该对象
	byte				valid_flag;		//表示对象是否有效

    hash_node_t     hash;

    DM_LIST_NODE_T(logmnr_client_dict_item_t) 
                    link;

    MAGIC_DECLARE
};

// 用于logmnr_extra_info_t中存储行信息
#define logmnr_row_info_MAGIC   76876643
typedef struct logmnr_row_info_struct logmnr_row_info_t;
struct logmnr_row_info_struct
{
    sdint8                  sess_id;                // 存储session_id
    dmrd_t                  dmrd;                   // 存储rowid

    MAGIC_DECLARE
};

// logmnr拼写sql时，解析逻辑日志中的数据，需要的额外信息
#define logmnr_extra_info_MAGIC   76876642
typedef struct logmnr_extra_info_struct logmnr_extra_info_t;
struct logmnr_extra_info_struct
{
    dmbool                  no_delimiter;           // 是否带结尾分隔符
    lint                    cvt_mode;               // 是否需要编码转换

    //以下2项是在消息版本号小于dm_comm_ver_9时有效,兼容老版本的rowid计算
    udint4                  rowid_max_hpno;         //最大的水平分区号
    udint2                  rowid_max_epno;         //最大站点号
    udint2                  rowid_n_bits_epno;      //站点号占用的数据位数
    udint2                  rowid_n_bits_real;      //给真实rowid值使用的位数。常规48，DPC为44

    MAGIC_DECLARE
};


enum
{
   logmnr_dml = 0, /*insert, delete, update*/
   logmnr_ddl,
   logmnr_trx,     /*commit和rollback*/
   logmnr_start,   
   logmnr_seq,     /*seq*/   

   logmnr_max
};

// logmnr_client.h是对外提供头文件，不能放内部信息，移动到logmnr_pub.h
/*---------------------Charset code convert--------------------*/
#define LOGMNR_CVT_NONE                 0           /* Client is the same charset code as server */
#define LOGMNR_CVT_L2U                  1           /* Client(utf) is not the same charset code as server(gbk)  */
#define LOGMNR_CVT_U2L                  2           /* Client(gbk) is not the same charset code as server(utf) */

DllExport
//设置操作类型的字符串
dmcode_t
logmnr_set_op(
    usint           llog_type,
    ulint*	        op_code,
    schar*          op_str
);

DllExport
void
logmnr_add_trx_info(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*    memobj,
	hash_table_t*   hash_tab,
	logmnr_trxid_lst_t* trxid_lst,
    os_mutex_t*     mutex,  /*IN:链表访问的互斥量*/
    ulint64         trx_id, 
    ulint           trx_seq,
    ulint           type,
    dmtime_t        time,
    ulint64         lsn
);

DllExport
void
logmnr_get_obj_sql(
    dmenv_t         env,    /*IN:环境句柄*/	
    rt_memobj_t*    memobj,
    dmstr_t*        dmstr,
    schar*			sch_name,
    ulint           schid,
    schar*			table_name,
    ulint           tabid
);

DllExport
void
logmnr_get_col_sql(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*    memobj,
    dmstr_t*        dmstr,
    schar*          col_name
);

DllExport
void
logmnr_data_calc_offset(
    byte*           data_p, 
    ulint*          offset_out
);

DllExport
byte
logmnr_op_type(
    ulint           op_code
);

//根据llog里面字段的信息,还原成对应格式的字符串并附加到dmstr中
DllExport
dmcode_t
logmnr_get_data_from_llog(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*	memobj,
    dmstr_t*		dmstr,
    byte*           data_p, 
    ulint*          offset_out,
    dmbool          mine_flag /*挖掘时以字符串形式返回结果，但是不用加引号*/
);

/*根据当前的sql语句类型，或取对应的undo类型*/
DllExport
usint
logmnr_get_undo_op(
    usint           oracle_op_code
);

DllExport
dmcode_t
logmnr_pub_build_ddl_sql(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf, 
    logmnr_extra_info_t* extra_info      /* IN: 额外信息 */
);

DllExport
dmcode_t
logmnr_pub_build_seq_sql(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf
);

/***********************************************
Purpose:
    logmnr解析LOB_DATA日志
***********************************************/
DllExport
dmcode_t        // 返回码
logmnr_pub_build_lob_data(
    dmenv_t                 env,            /* IN: 环境句柄 */
    rt_memobj_t*            memobj,         /* IN: 内存空间 */
    byte*                   llog,           /* IN: 逻辑日志 */
    dmstr_t*                dmstr           /* OUT: dmstr */
);

DllExport
dmcode_t
logmnr_pub_build_seq_sql_for_rlog2(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf,
    logmnr_row_info_t*   row_info       /* OUT: 行信息*/
);

/***********************************************
Purpose:
根据逻辑日志llog构造sql语句填充到dmstr中
***********************************************/
DllExport
dmcode_t // 执行错误码
logmnr_pub_build_sql(
    dmenv_t                     env,            /* IN: 环境句柄 */
    rt_memobj_t*                memobj,         /* IN: 内存空间 */
    byte*                       llog,           /* IN: 逻辑日志 */
    dmstr_t*                    buf,            /* OUT: dmstr */
    schar*                      sch_name,       /* IN: 模式名 */
    ulint                       schema_id,      /* IN: 模式id */
    ndct_table_t*               table,          /* IN: 表对象 */
    ulint                       table_id,       /* IN: 表id */
    usint                       op_code,        /* IN: 操作类型 */
    dmbool                      is_undo,        /* IN: 是否拼写undo语句 */
    logmnr_row_info_t*          row_info,       /* OUT: 行信息*/
    logmnr_extra_info_t*        extra_info      /* IN: 额外信息 */
);

/************************************************************************
purpose:
    生成xid的信息
************************************************************************/
DllExport
dmcode_t    /*返回code*/
logmnr_pub_build_xid_for_rlog2(
    dmenv_t             env,        /*IN:环境句柄*/
    rt_memobj_t*        memobj,     /*IN:内存*/
    byte*               llog,       /*IN:逻辑日志*/
    dmstr_t*            sql_redo,   /*OUT:sql缓存*/
    logmnr_row_info_t*  row_info    /*OUT:row_info */
);

/***********************************************
Purpose:
根据逻辑日志llog构造sql语句填充到dmstr中
***********************************************/
DllExport
dmcode_t // 执行错误码
logmnr_pub_build_sql_for_rlog2(
    dmenv_t                     env,            /* IN: 环境句柄 */
    rt_memobj_t*                memobj,         /* IN: 内存空间 */
    byte*                       llog,           /* IN: 逻辑日志 */
    dmstr_t*                    buf,            /* OUT: dmstr */
    dmstr_t**                   bufs,           /* OUT: 如果fast insert，需要拼成多条逻辑日志 */
    schar*                      sch_name,       /* IN: 模式名 */
    ulint                       schema_id,      /* IN: 模式id */
    ndct_table_t*               table,          /* IN: 表对象 */
    ulint                       table_id,       /* IN: 表id */
    usint                       op_code,        /* IN: 操作类型 */
    dmbool                      is_undo,        /* IN: 是否拼写undo语句 */
    logmnr_row_info_t*          row_info,       /* OUT: 行信息*/
    logmnr_extra_info_t*        extra_info,     /* IN: 额外信息 */
    dmbool                      parse_lob,      /* IN: 是否解析大字段 */
    ulint*                      subtab_id       /* OUT: 子表id*/
);

DllExport
void
logmnr_binary_assign_from_lint64(
    nstr_t*         dst,
	lint64          v
);

DllExport
dmcode_t
logmnr_get_data_from_llog_for_rlog2(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*    memobj,
    dmstr_t*        dmstr,
    byte*           data_p, 
    ulint*          offset_out,
    dmbool          mine_flag, /*挖掘时以字符串形式返回结果，但是不用加引号*/
    dmbool          parse_lob       /* IN: 是否解析大字段 */
);

/***********************************************
Purpose:
从nrec获取数据，用于精简逻辑日志
***********************************************/
DllExport
dmcode_t
logmnr_get_data_from_compressed_llog_for_rlog2(
    dmenv_t         env,            /*IN:环境句柄*/
    rt_memobj_t*    memobj,
    dmstr_t*        dmstr,          /*IN:输出字符串*/
    nrec_t*         nrec,           /*IN:记录*/
    usint           nrec_tail_len,  /*IN:记录尾部字段的长度，只有V4才有，V3是USINT_UNDEFINED*/
    usint           col_num,        /*IN:列数，不包括rowid列*/
    byte*           types,          /*IN:列描述*/
    usint*          type_len,       /*IN:列的长度，因为nrec里没有定长列的长度头，目前只有char和binary会用到*/
    dmbool          mine_flag,      /*挖掘时以字符串形式返回结果，但是不用加引号*/
    dmbool          parse_lob       /* IN: 是否解析大字段 */
);

DllExport
void
logmnr_data_calc_offset_for_rlog2(
    byte*           data_p, 
    ulint*          offset_out
);

DllExport
dmcode_t
logmnr_pub_build_trunc_tab_sql_for_rlog2(
    dmenv_t             env,    /*IN:环境句柄*/
    rt_memobj_t*        memobj,
    byte*               llog, 
    dmstr_t*            buf, 
    logmnr_row_info_t*   row_info,       /* OUT: 行信息*/
    logmnr_extra_info_t* extra_info      /* IN: 额外信息 */
);

DllExport
dmcode_t
logmnr_pub_build_ddl_sql_for_rlog2(
    dmenv_t         env,    /*IN:环境句柄*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf, 
    logmnr_row_info_t*   row_info,       /* OUT: 行信息*/
    logmnr_extra_info_t* extra_info      /* IN: 额外信息 */
);

/********************************************
Purpose:
    移除掉DDL语句最后的分隔符
********************************************/
DllExport
dmcode_t      /* 执行错误码 */
logmnr_pub_build_ddl_remove_delimiter(
    byte*           sql,            /* IN: 日志中记录的ddl语句 */
    ulint*          sql_len_io      /* IN/OUT: dll语句的长度 */
);

/***********************************************
Purpose:
获取逻辑日志中记录的rowid
***********************************************/
DllExport
dmcode_t
logmnr_pub_build_sql_get_rowid(
    byte*                       llog,               /*IN:逻辑日志记录*/
    ulint*                      offset_inout,       /*INOUT:日志偏移*/
    logmnr_row_info_t*          row_info,           /* OUT: 行信息*/
    logmnr_extra_info_t*        extra_info          /*IN:额外信息 */
);

/*********************************************************************
Purpose :
    初始化row_info
*********************************************************************/
DllExport
dmcode_t                            //返回code
logmnr_pub_extra_row_info_init(
    logmnr_row_info_t* row_info     /*IN:row_info句柄*/
);

#endif

