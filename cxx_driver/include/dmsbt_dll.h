/********************************************************************
file: 
    dmsbt_dll.h
Notes:
    sbt interface 
History:
    Date         Who         RefDoc         Memo
    2016-09-05   shenning                   create
********************************************************************/
#ifndef DMSBT_DLL_H
#define DMSBT_DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" { 			/* Assume C declarations for C++   */
#endif  /* __cplusplus */

typedef int                     sbtcode_t;
typedef int                     sbtbool;
typedef unsigned char           sbtbyte;
typedef signed char             sbtchar;
typedef signed short            sbtint2;
typedef unsigned short          sbtuint2;
typedef int                     sbtint4;
typedef unsigned int            sbtuint4;

#if defined(WIN32) || defined(WINDOWS)
typedef __int64                 sbtint8;
typedef unsigned __int64        sbtuint8;
#else
typedef long long int           sbtint8;
typedef unsigned long long int  sbtuint8;
#endif

#ifdef DM64
typedef sbtuint8        sbtuint3264;
typedef sbtint8         sbtint3264;
#else
typedef sbtuint4        sbtuint3264;
typedef sbtint4         sbtint3264;
#endif

#define SBT_SUCCESS(code)   ((sbtint4)code >= 0)

#define SBT_RET_IF_ERR(c) \
    { if (!SBT_SUCCESS(c)) return (c);}

#ifdef WIN32
#define SBT_DIR_CHAR        '\\'
#define SBT_DIR_STR         "\\"
#define SBT_DIR_STR_LEN     1
#else
#define SBT_DIR_CHAR        '/'
#define SBT_DIR_STR         "/"
#define SBT_DIR_STR_LEN     1
#endif

/************************************************************************ 
 DMSBT接口版本号，赋值SBTINIT_MMS_VSN时，以16进制数字返回，主版本号和小版本号，各占两位，如1.0，则为0x0100
 0x0201 增加全局变量gvar,
        增加sbtversion接口；
        不兼容之前版本。
 0x0202 增加extern "C"，兼容C++编译的第三方库；
        兼容前面版本。
************************************************************************/
#define DMSBT_DLL_VERSION       0x0202          //"2.2"

/************************************************************************
 * SBT_CODE = 0: 表示执行成功；
 * SBT_CODE > 0: 表示警告信息；
 * SBT_CODE < 0: 表示错误信息；
************************************************************************/
#define SBT_WARN                (sbtint4)1
#define SBT_EC_SUCCESS          (sbtint4)0
#define SBT_EC_FAIL             (sbtint4)-1

/************************************************************************ 
 * SBT_EC_DM_RESERVED: 之前为达梦预留错误码，第三方扩展需从此值之后开始，如-10001
************************************************************************/
#define SBT_EC_DM_RESERVED      (sbtint4)-10000

/***********************************************************************/
/* SBT size limits.  When the object is a  */
/* character string, the maximum length does not include the terminating null. */
/***********************************************************************/

#define SBT_ERROR_MAX       512      /* error string returned by sbterror */
#define SBT_FILE_MAX        256                        /* backup file name */
#define SBT_MMSDESC_MAX     64         /* SBT_MMS_DESC returned by sbtinit */
#define SBT_DBNAME_MAX      128                        /* SBTINIT2_DBNAME */
#define SBT_COMMENT_MAX     80                        /* SBTBFINFO_COMMENT */
#define SBT_LABEL_MAX       64                          /* SBTBFINFO_LABEL */
#define SBT_COMMAND_MAX     1024            /* command passed to sbtcommand

/************************************************************************
/* SBTINIT接口输入数据结构及常量定义
/************************************************************************/
typedef struct  sbtinit_input_struct    sbtinit_input_t;
struct sbtinit_input_struct
{
    sbtuint4        i_type;         /* Type of the object */
#define SBTINIT_TRACE_NAME          1       /* Trace File Name */
#define SBTINIT_LANGUAGE_TYPE       2       /* Language type used by API client */
#define SBTINIT_CODE_IS_UNICODE     3       /* Whether the CODE used by API client is UTF-8,FALSE by default. */
#define SBTINIT_ENV_HANDLE          4       /* Environment handle, only used by DM. */
#define SBTINIT_INEND               9999    /* end of the array */

    void*           i_obj;          /* Initialization Object */

// values for SBTINIT_LANGUAGE_TYPE
#define SBTINIT_LANGUAGE_CN         1       /* Chinese */
#define SBTINIT_LANGUAGE_EN         2       /* English */
#define SBTINIT_LANGUAGE_CNT_HK     3       /* HK Traditional Chinese */
};

/************************************************************************
/* SBTINIT接口输出数据结构及常量定义
/************************************************************************/
typedef struct  sbtinit_output_struct   sbtinit_output_t;
struct sbtinit_output_struct
{
    sbtuint4        o_type;         /* Type of the object */
#define SBTINIT_MAXSIZE             1       /* maximum backup piece size */
#define SBTINIT_MMS_APIVSN          2       /* Version Number of Tape API */
#define SBTINIT_MMS_DESC            3       /* vendor description */
#define SBTINIT_MMS_VSN             4       /* Version Number of MM Software */
#define SBTINIT_OUTEND              9999    /* end of the array*/

    void*           o_obj;          /* Initialization Object */
};

/************************************************************************
/* SBTINIT2接口输入数据结构及常量定义
/************************************************************************/
typedef struct sbtinit2_input_struct    sbtinit2_input_t;
struct sbtinit2_input_struct
{
    sbtuint4        i_type;         /* Type of the object */
#define SBTINIT2_TRACE_LEVEL        1       /* Trace level */
#define SBTINIT2_MAXSIZE            2       /* maximum size of backup file API client specified, less than output by sbtinit */
#define SBTINIT2_DBNAME             3       /* Database Name */
#define SBTINIT2_DBMAGIC            4       /* Database DB MAGIC NUMBER */
#define SBTINIT2_BACKUPSET          5       /* Directory for which backupset to backup or restore,specified by BACKUPSET */
#define SBTINIT2_BACKUPDIRS         6       /* Directories for backupset searched if the member in array is null or empty string,then end.*/
#define SBTINIT2_BASEON_BACKUPSET   7       /* Base backupset directory specified by BASE ON */
#define SBTINIT2_BACKUPSETS_INFO    8       /* Need backupsets information, and need all if SBTINIT2_BACKUPDIRS not set */
#define SBTINIT2_IS_BACKUP          9       /* Tell current operation is backup */
#define SBTINIT2_IS_INCREMENT       10      /* Tell current backup is incremental,only valid when SBTINIT2_IS_BACKUP is set */
#define SBTINIT2_BACKUPNAME         11      /* Name of backupset, valid only when backup */
#define SBTINIT2_DEF_BAKDIR         12      /* The default directory where backupset be located */
#define SBTINIT2_DIRECT_IO          13      /* Whether to enable direct io during backup */
#define SBTINIT2_PARMS              14      /* The information needed to connect to OSS server */
#define SBTINIT2_INEND              9999    /* null entry - end of list */

    /* values for SBTINIT2_TRACE_LEVEL */
#define SBTINIT2_TRACE_LEVEL_NONE   1  /* nothing wrote to trace file */
#define SBTINIT2_TRACE_LEVEL_LOG    2  /* wrote log info to trace file */

    void*           i_obj;          /* Initialization Object */
};

/************************************************************************
/* SBTINIT2接口输出数据结构及常量定义
/************************************************************************/
typedef struct sbtinit2_output_struct   sbtinit2_output_t;
struct sbtinit2_output_struct
{
    sbtuint4    o_type;             /* Type of the object */
#define SBTINIT2_BACKUPSET          5       /* Directory for which backupset to backup or restore,specified by BACKUPSET */
#define SBTINIT2_BASEON_BACKUPSET   7       /* Base backupset directory specified by BASE ON */
#define SBTINIT2_BACKUPDIRS         6       /* backupsets searched to return */

#define SBTINIT2_OUTEND             9999    /* null entry - end of list */

    void*       o_obj;              /* Initialization Object */
};

/************************************************************************
/*  sbtinit2_output_struct中输出备份集信息结构
/***********************************************************************/
typedef struct sbtbackupset_obj_struct      sbtbakset_obj_t;
struct sbtbackupset_obj_struct
{    
    sbtchar             meta_file_name[SBT_FILE_MAX + 1];     /* absolute path name for meta file */
    sbtuint4            bakset_type;       /* This backupset is increment/full */    

    sbtbool             is_invalid;           /* is_invalid = TRUE，end of the baksets array */

    sbtbakset_obj_t*    p_next;             /* pointer to next valid backupset obj */
    sbtbakset_obj_t*    p_prev;             /* pointer to prev valid backupset obj */

// values for bakset_type
#define SBTBAKSET_TYPE_UNKNOWN      0       /* unknown,used for disk backup */
#define SBTBAKSET_TYPE_FULL         1       /* full */
#define SBTBAKSET_TYPE_INCRMENT     2       /* increment */
};

/************************************************************************
/* SBTBACKUP接口备份文件类型常量定义
/************************************************************************/
#define SBTBFILE_DATAFILE           1       /* datafile */
#define SBTBFILE_ARCHLOG            2       /* archived redo log */
#define SBTBFILE_METAFILE           3       /* meta file */
#define SBTBFILE_OTHER              4       /* neither datafile nor archived log */

/************************************************************************
/* SBTINFO接口数据结构及常量定义
/************************************************************************/
typedef struct sbtbfinfo_struct     sbtbfinfo_t;
struct sbtbfinfo_struct
{
    sbtuint4    sbtbfinfo_type;             /* Type of the object */
#define SBTBFINFO_NAME              1       /* name of backup file */
#define SBTBFINFO_CRETIME           2       /* file creation date/time */
#define SBTBFINFO_EXPTIME           3       /* file expiration date/time */
#define SBTBFINFO_LABLE             4       /* Volume label */
#define SBTBFINFO_COMMENT           5       /* vendor-defined comment string */
#define SBTBFINFO_END               9999    /* null entry - end of list */

    void*       sbtbinfo_value;             /* value of the object */
};

/************************************************************************/
/* 功能：  取动态库版本
/* 参数：  version，输出参数，动态库的版本
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t 
sbtversion(
    sbtuint2*       version
);

/************************************************************************/
/* 功能：  初始化系统
/* 参数：  gvar_out,输出参数，由第三方自己申请，记录全局信息并供其他接口使用，实现文件（.c）中不能再出现全局变量
           initin，输入参数，由客户端向第三方介质输入
           initout，输出参数，由第三方介质向客户端输出           
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t 
sbtinit(
    void**              gvar_out,
    sbtinit_input_t*    in,
    sbtinit_output_t**  out
);

/************************************************************************/
/* 功能：  参数配置
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
           in，输入参数，由客户端向第三方介质输入配置参数
           out，输出参数，由第三方介质向客户端输出参数配置           
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtinit2(
    void*               gvar_in,
    sbtinit2_input_t*   in,
    sbtinit2_output_t** out
);

/************************************************************************/
/* 功能：  准备指定备份文件，开始备份
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
           bfile_type，输入参数，指定备份文件类型
           bfile_name，输入参数，指定备份文件名字，不要求第三方实现通过SBTINFO(SBTBFINFO_NAME)返回一样的文件名
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtbackup(
    void*           gvar_in,
    sbtint4         bfile_type,
    sbtchar*        bfile_name
);

/************************************************************************/
/* 功能：  写入备份数据到当前备份文件中
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
           buf：输入参数，待写入数据缓存；
           buf_len：输入参数，待写入数据长度，一定要全部写入，否则还原时失败
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtwrite(
    void*           gvar_in,
    sbtbyte*        buf,
    sbtuint4        buf_len
);

/************************************************************************/
/* 功能：  关闭当前备份文件读写
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
/* 返回值：无
/************************************************************************/
sbtcode_t
sbtclose(
    void*           gvar_in
);

/************************************************************************/
/* 功能：  返回最后一个结束备份的备份文件信息
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
           bak_file_info，输出参数，以数组的形式返回备份文件信息
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtinfo(
    void*           gvar_in,
    sbtbfinfo_t**   bak_file_info
);

/************************************************************************/
/* 功能：  一个备份集备份或还原过程结束，第三方实现释放资源
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量，并在使用结束后释放，与sbtinit申请对应    
           del_flag,输入参数，表示当前备份或还原过程结束。是否清除过程中介质上生成的文件；
           备份过程中del_flag=TRUE，说明备份过程失败；还原过程，def_flag全部为FALSE。
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtend(
    void*          gvar_in,
    sbtbool        del_flag
);

/************************************************************************/
/* 功能：  准备指定名称的备份文件，开始还原
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
           filename，输入参数，通过调用SBTINFO获取的备份文件名称(SBTBFINFO_NAME)
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtrestore(
    void*           gvar_in,
    sbtchar*        filename
);

/************************************************************************/
/* 功能： 从备份文件中读取备份数据
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
           buf：输入参数，读取数据缓存；
           buf_len：输入参数，读取数据长度，一定要读这么多，否则还原会出错
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtread(
    void*           gvar_in,
    sbtbyte*        buf,
    sbtuint4        buf_len
);

/************************************************************************/
/* 功能： 获取上次执行过程中，执行失败的描述信息
/* 参数：  gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量                           
           errdesc_utf8，输出参数，与API接口要求语言和编码方式对应的第三方实现中错误描述信息.
           描述信息长度均不能超过SBT_ERROR_MAX，否则，自动截断。
/* 返回值：返回执行失败的错误码
/************************************************************************/
sbtcode_t
sbterror(
    void*           gvar,
    sbtchar*        err_desc,
    sbtuint4        err_buf_len,
    sbtuint4*       err_len
);

/************************************************************************/
/* 功能： 向第三方传入命令字符串
/* 参数： gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量     
          cmdstr，输入参数，代表用户通过备份还原语句指定的第三方配置字符串，上层调用接口，不做任何处理
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtcommand(
    void*           gvar_in,
    sbtchar*        cmdstr
);

/************************************************************************/
/* 功能： 删除当前备份集，对应SBTINIT2_BACKUPSET指定备份集
/* 参数： gvar_in,输入参数，由第三方通过sbtinit申请的记录全局信息的变量    
          filename，输入参数，通过调用SBTINFO获取的备份文件名称(SBTBFINFO_NAME)
/* 返回值：返回该接口执行是否成功，成功返回SBT_EC_SUCCESS；否则，返回具体错误码
/************************************************************************/
sbtcode_t
sbtdelete(
    void*           gvar_in,
    sbtchar*        filename
);

#ifdef __cplusplus
}                                    /* End of extern "C" { */
#endif  /* __cplusplus */
#endif


