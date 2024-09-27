/******************************************************
file:
    asmapi.h
Notes:
    to define struct and interface for ASM DLL
history:
    Date        Who         RefDoc    Memo
    2015-07-20  ww/sn                      Created
*******************************************************/
#ifndef DMASM2_H
#define DMASM2_H

/* environment specific definitions */
#ifndef EXPORT
#define EXPORT   
#endif

#ifndef DllImport
#if defined (_WINDOWS) || defined (WIN32)
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )
#else
#define DllImport 
#define DllExport 
#endif //DWINDOWS
#endif

#include "apitype.h"

#ifndef ASMAPI_PUB
#define ASMAPI_PUB

typedef udint4              asmbool;

/* function return type */
typedef sdint4              ASMRETURN;

#ifdef WIN32
typedef void*               asm_fhandle_t;
#else
typedef udint4              asm_fhandle_t;
#endif /* WIN32 */

typedef void*               asm_dhandle_t;

typedef void*               asmcon_handle;

#define INVALID_ASM_FILE_HANDLE 0xFFFFFFFFFFFFFFFF

/* define identifier */
#define ASM_NAMELEN             32
typedef sdbyte                  asm_name_t[ASM_NAMELEN + 1];

/* define file path */
#define ASM_MAX_PATH_LEN        256
typedef sdbyte                  asm_pathname_t[ASM_MAX_PATH_LEN + 1];

/* define time identifier */
#define ASM_TIMELEN             29
typedef sdbyte                  asm_time_t[ASM_TIMELEN + 1];

#define ASMAPI_ERR_MAX_LEN      512
typedef sdbyte                  asm_error_t[ASMAPI_ERR_MAX_LEN + 1];

#endif

/* dmasm_dir_get_first使用，用于指定目标获取对象类型 */
#define ASM_FILE_TYPE_UNDEFIND  0
#define ASM_FILE_TYPE_FILE      1
#define ASM_FILE_TYPE_DIR       2

typedef struct asm_file_attr_struct ASM_FILE_ATTR;
struct asm_file_attr_struct
{
    asm_fhandle_t   fil_id;
    sdbyte          type;       /* 文件类型：file/dir */
    asm_pathname_t  name;       /* 文件名称 */
    asm_pathname_t  full_path;  /* 完整路径 */  
    udint8          size;       /* 文件大小（byte），对于目录，忽略此字段 */
    udint8          c_time;     /* 创建时间 */
    udint8          m_time;     /* 修改时间 */

    udint2          group_id;   /* 所在磁盘组编号 */
    udint2          disk_id;    /* 所在磁盘ID */
    udint4          disk_auno;  /* 所在磁盘AU编号 */
    udint4          offset;     /* AU偏移 */
};


/*
功能：ASM接口模块初始化
参数：无
返回：成功，返回0；否则，错误码
*/
DllExport
ASMRETURN
dmasm_sys_init(
    sdbyte*         err_desc,
    udint4*         err_len,
    udint4          char_code,
    udint4          lang_id             /* 使用指定的lang_id, == ULINT_UNDEFINED才从系统去读 */
);

/*
功能：ASM接口模块释放
参数：无
返回：无
*/
DllExport
void
dmasm_sys_deinit();

/*
功能：申请并初始化连接对象
参数：con 输出参数，记录申请的连接对象
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_alloc_con(
    asmcon_handle*      con,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
功能：释放连接对象
参数：con 输入，待释放连接对象
返回：无
*/
DllExport
void
dmasm_free_con(
    asmcon_handle  con
);

/*
功能：建立连接
参数：con 输入参数，使用建立连接的对象
      username 输入，用户名
      password 输入，密码
      hostname 输入，主机名
      portnum  输入，端口号
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_connect(
    asmcon_handle   con,
    sdbyte*         username,
    sdbyte*         password,
    sdbyte*         hostname,
    udint2          portnum,
    asmbool*        con_is_local,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_change_pwd(
    asmcon_handle   con,
    sdbyte*         username,
    sdbyte*         password,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：关闭连接
参数：con 输入参数，待关闭的连接对象
返回：无
*/
DllExport
void
dmasm_close_con(
    asmcon_handle  con
);

/*
功能：获取磁盘组的个数
参数：conn 输入，目标连接
      num 输出，磁盘组个数，未指定(null)，直接返回      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_n_group(
    asmcon_handle   con,
    udint2*         num,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：获取磁盘组ID数组
参数：conn 输入，目标连接
      num 输出，实际磁盘组个数
      id_arr 输出，磁盘组ID数组，有效值个数取num的输出和id_arr的较小者      
      arr_size 输入，id_arr的大小
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_group_id_arr(
    asmcon_handle   con_in,    
    udint2*         id_arr,
    udint4*         au_size_arr,
    udint4*         ex_size_arr,
    udint2          arr_size,
    udint2*         num,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：获取一个磁盘组的信息
参数：conn 输入，目标连接
      group_id 输入，目标磁盘组ID
      group_name 输出，磁盘组名称，最大128字节，不包括字符串结尾符
      status 输出，磁盘组中裸设备块的状态,如ASM_GROUP_STA_NORMAL      
      n_disk 输出，磁盘组中包含磁盘的个数
      *：若某个输出为NULL，则相应字段不取
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_group_info_by_id(
    asmcon_handle   con,
    udint2          group_id,
    sdbyte*         group_name,
    udint2          name_buflen,
    udint2*         status,
    udint2*         n_disk,
    udint4*         total_size,
    udint4*         free_size,
    udint4*         au_size,
    sdbyte*         n_copy,
    udint4*         redo_size,
    udint2*         rbl_stat,
    udint2*         rbl_pwr,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：获取一个磁盘组的信息
参数：conn 输入，目标连接
      group_id 输出，目标磁盘组ID
      group_name 输入，磁盘组名称，最大128字节，不包括字符串结尾符
      status 输出，磁盘组中裸设备块的状态,如ASM_GROUP_STA_NORMAL      
      n_disk 输出，磁盘组中包含磁盘的个数
      *：若某个输出为NULL，则相应字段不取
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_group_info_by_name(
    asmcon_handle   con_in,
    sdbyte*         group_name,
    udint2*         group_id,
    udint2*         status,    
    udint2*         n_disk,
    udint4*         total_size,
    udint4*         free_size,
    sdbyte*         err_desc,
    udint4*         err_len        
);

/*
功能：获取一个磁盘组中磁盘ID数组
参数：conn 输入，目标连接
      group_id 输入，指定磁盘组的ID
      n_disk 输出，实际存在的磁盘的个数
      id_arr 输出，输出磁盘ID的数组，有效值个数取n_disk输出值和arr_size中较小者
      arr_size 输入，id_arr的大小
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_disk_id_arr_by_group(
    asmcon_handle   con_in,
    udint2          group_id,    
    udint2*         id_arr,
    udint2          arr_size,
    udint2*         n_disk,
    sdbyte*         err_desc,
    udint4*         err_len
);

/***********************************************************************************
purpose:
    新增low接口获取一个磁盘的信息
NOTES:
    v$asmdisk获取磁盘信息使用该接口，防止外部直接调用dmasm_get_disk_info造成错误
***********************************************************************************/
DllExport
ASMRETURN
dmasm_get_disk_info_low(
    asmcon_handle       conn_in,
    udint2              group_id,
    udint4              disk_id,
    sdbyte*             path,
    udint2              path_buflen,
    sdbyte*             name,
    udint2              name_buflen,
    sdbyte*             frp_name,       /*OUT:磁盘所属故障组名（兼容新版用）*/
    udint2              frp_buflen,     /*IN:存放磁盘所属故障组名buf长度（兼容新版用）*/
    sdbyte*             status_name,    /*OUT:磁盘状态（兼容新版用）*/
    udint2              status_buflen,  /*IN:存放磁盘状态buf长度（兼容新版用）*/
    udint4*             size,
    udint4*             free_auno,
    sdbyte*             create_time,
    sdbyte*             modify_time,
    udint4*             version,            /* OUT: 磁盘版本号 */
    asmbool*            destroyed,          /* OUT: 物理磁盘是否损坏 */
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
功能：获取一个磁盘的信息
参数：conn 输入，目标连接
      group_id 输入，指定磁盘组的ID
      disk_id 输入，指定磁盘的ID
      path 输出，磁盘路径，最长256个字节，不包括字符串结尾符
      name 输出，磁盘名字，最长128个字节，不包括字符串结尾符
      size 输出，磁盘大小，以M为单位
      free_auno 输出，磁盘空闲AU的偏移
      create_time 输出，磁盘创建时间
      modity_time 输出，磁盘修改时间
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_disk_info(
    asmcon_handle   con,
    udint2          group_id,
    udint4          disk_id,
    sdbyte*         path,
    udint2          path_buflen,
    sdbyte*         name,
    udint2          name_buflen,
    sdbyte*         frp_name,       /*OUT:磁盘所属故障组名（兼容新版用）*/
    udint2          frp_buflen,     /*IN:存放磁盘所属故障组名buf长度（兼容新版用）*/
    sdbyte*         status_name,    /*OUT:磁盘状态（兼容新版用）*/
    udint2          status_buflen,  /*IN:存放磁盘状态buf长度（兼容新版用）*/
    udint4*         size,
    udint4*         free_auno,
    sdbyte*         create_time,
    sdbyte*         modify_time,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：获取磁盘组中文件个数
参数：conn 输入，目标连接
      group_id 输入，指定磁盘组ID
      num 输出，磁盘组中文件个数      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_file_num_by_group(
    asmcon_handle   con,
    udint2          group_id,
    udint4*         num,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：获取磁盘组中文件ID数组
参数：conn 输入，目标连接
      group_id 输入，指定磁盘组ID
      real_num 输出，实际存在的磁盘组ID个数
      id_arr 输出，文件ID数组，有效值个数最大与arr_size一致，若real_num小于arr_size，则为real_num
      arr_size 输入，指定id_arr的大小
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_get_file_id_arr_by_group(
    asmcon_handle       conn_in,
    udint2              group_id,    
    asm_fhandle_t*      id_arr,
    udint4              arr_size,
    udint4*             real_num,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
功能：获取一个文件信息
参数：conn 输入，目标连接
      file_id 输入，目标文件ID
      filepath 输出，目标检查文件，最大256个字节，不包括字符串结尾符
      filesize 输出，目标文件大小，单位BYTE，实际大小
      createtime 输出，目标文件创建时间
      modifytime 输出，目标文件最后修改时间
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_attributes_get_by_handle(
    asmcon_handle   conn,
    asm_fhandle_t   file_id,
    void*           fattr_out,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：检查磁盘是否溢出
参数：conn 输入，目标连接
      filepath 输入，目标检查文件，最大256个字节，不包括字符串结尾符
      filesize 输入，目标检查大小，单位BYTE，实际大小
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_check_disk_space(
    asmcon_handle   conn,
    sdbyte*         filepath,
    udbyte          n_copy,
    udint8          filesize,
    asmbool*        overflow,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：创建asm文件
参数：conn 输入，目标连接
      filepath 输入，目标检查文件，最大256个字节，不包括字符串结尾符      
      filesize 输入，创建文件大小，实际大小，单位BYTE     
      fhandle 文件创建成功后，输出句柄
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_create(
    asmcon_handle   conn,    
    asmbool         p_flag,
    sdbyte*         filepath,    
    udint8          filesize,
    asm_fhandle_t*  fil_handle,
    asmbool         init_flag,
    udint2          striping_size,      /* IN：条带化类型，新代码兼容参数 */
    udbyte          redundancy_type,    /* IN：镜像类型，新代码兼容参数 */
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：根据路径，删除asm文件
参数：conn 输入，目标连接
      filepath 输入，目标检查文件，最大256个字节，不包括字符串结尾符
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_delete(
    asmcon_handle   conn,    
    sdbyte*         filepath,    
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：打开asm文件
参数：conn 输入，目标连接
      filepath 输入，目标检查文件，最大256个字节，不包括字符串结尾符 
      fhandle 输出，打开的文件句柄
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_open(
    asmcon_handle   conn,    
    sdbyte*         filepath,
    asm_fhandle_t*  fhandle,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：关闭asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待关闭的文件句柄
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_close(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle
);


/*
功能：扩展asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待扩展的文件句柄
      offset 输入，文件偏移
      extend_size 输入，偏移之后再扩展的大小，单位B，实际大小
返回：true 成功；false 失败
*/
DllExport
ASMRETURN
dmasm_file_extend(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle,
    udint8          offset,
    udint8          extend_size,
    udint4          need_init,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：截断asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待截断的文件句柄      
      truncate_size 输入，截断后的长度，单位BYTE
      real_size 输出，截断后的实际长度，若truncate_size大于实际长度，则不截断，输出实际长度，否则与truncate_size相等
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_trunc(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle,    
    udint8          truncate_size,
    udint8*         real_size,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：读asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待读文件句柄
      offset 输入，读文件的起始偏移
      buffer 输入输出，读取文件内容的存放缓存
      bytes_to_read 输入，要求读取字节个数      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_read_by_offset(
    asmcon_handle       conn,
    asm_fhandle_t       fhandle,
    udint8              offset,
    sdbyte*             buffer,
    udint4              bytes_to_read,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
功能：读asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待读文件句柄
      offset 输入，读文件的起始偏移
      buffer 输入输出，读取文件内容的存放缓存
      bytes_to_read 输入，要求读取字节个数      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_read_by_offset_inner(
    void*               env,
    asmcon_handle       conn,
    asm_fhandle_t       fhandle,
    udint8              offset,
    sdbyte*             buffer,
    udint4              bytes_to_read,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
功能：读asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待读文件句柄
      offset 输入，读文件的起始偏移
      buffer 输入输出，读取文件内容的存放缓存
      bytes_to_read 输入，要求读取字节个数      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_read_by_offset_normal(
    asmcon_handle   conn,     
    asm_fhandle_t   fhandle,
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_read,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：异步读asm文件，内部不循环，不允许跨簇操作，调用处确保一次调用的读取的长度；若超长，则报错，且由输出参数bytes_read返回能够读取的长度
参数：conn 输入，目标连接      
      fhandle 输入，待读文件句柄
      asmdisk 输出，文件读关联的asmdisk句柄
      offset 输入，读文件的起始偏移
      buffer 输入输出，读取文件内容的存放缓存
      bytes_to_read 输入，要求读取字节个数
      bytes_read 输出，实际读出的数据
      ctl，输入，windows平台传入overlapped，非wins平台，直接传入NULL
      os_err，输出，os层操作出现的错误码
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_async_read_by_offset(
    void*                   env,
    asmcon_handle           conn_in,
    asm_fhandle_t           fhandle,
    asm_fhandle_t*          asmdisk,
    udint8                  offset,
    sdbyte*                 buffer,
    udint4                  bytes_to_read,
    udint4*                 bytes_read,
    void*                   ctl,
    ASMRETURN*              os_err,
    sdbyte*                 err_desc,
    udint4*                 err_len
);

/*
功能：写asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待写文件句柄
      offset 输入，写文件的起始偏移
      buffer 输入，写入文件内容的存放缓存
      bytes_to_write 输入，待写入字节个数      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_write_by_offset(
    asmcon_handle   conn,
    asm_fhandle_t   fhandle,
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_write,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：写asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待写文件句柄
      offset 输入，写文件的起始偏移
      buffer 输入，写入文件内容的存放缓存
      bytes_to_write 输入，待写入字节个数      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_write_by_offset_inner(
    void*           env,
    asmcon_handle   conn,
    asm_fhandle_t   fhandle,
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_write,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：写asm文件
参数：conn 输入，目标连接      
      fhandle 输入，待写文件句柄
      offset 输入，写文件的起始偏移
      buffer 输入，写入文件内容的存放缓存
      bytes_to_write 输入，待写入字节个数      
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_write_by_offset_normal(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle,    
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_write,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：异步写asm文件，内部不循环，不允许跨簇操作，调用处确保一次调用的写入的长度；若超长，则报错，且由输出参数bytes_written返回能够写入的长度
参数：conn 输入，目标连接      
      fhandle 输入，待写文件句柄
      asmdisk 输出，fhandle读写关联的asmdisk句柄
      offset 输入，写文件的起始偏移
      buffer 输入，写入文件内容的存放缓存
      bytes_to_write 输入，待写入字节个数
      bytes_written输出，实际写入的个数
      ctl    输入，windows平台overlapped参数，非wins直接传入NULL
      os_err，输出，os层操作出现的错误码
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_async_write_by_offset(
    void*                   env,
    asmcon_handle           conn_in,
    asm_fhandle_t           fhandle,
    asm_fhandle_t*          asmdisk,
    udint8                  offset,
    sdbyte*                 buffer,
    udint4                  bytes_to_write,
    udint4*                 bytes_written,
    void*                   ctl,
    ASMRETURN*              os_err,
    sdbyte*                 err_desc,
    udint4*                 err_len
);

/*
功能：创建ASM文件目录
参数：conn 输入，目标连接      
      source 输入，源文件，仅支持本地文件或者ASM文件
      dest 输入，目标文件，仅支持本地文件或者ASM文件
      bFailIfExists 输入，如果存在，是否覆盖
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_copy(
    asmcon_handle   conn,
    sdbyte*         source,
    sdbyte*         dest,
    asmbool         bOverwriteIfExists,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_file_copy_low(
    asmcon_handle   conn,
    sdbyte*         source,
    sdbyte*         dest,
    asmbool         bOverwriteIfExists,             //文件存在，是否覆盖
    asmbool         recursion_flag,                 //目录，是否递归拷贝
    asmbool         fast_flag,                      //是否优化
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：重命名ASM文件或者目录
参数：conn 输入，目标连接
      source 输入，源文件，仅支持ASM文件
      dest 输入，目标文件，仅支持ASM文件
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_file_rename(
    asmcon_handle   conn_in,
    sdbyte*         source,
    sdbyte*         dest,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_file_compare(
    asmcon_handle   conn,
    sdbyte*         source,
    sdbyte*         dest,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：创建ASM文件目录
参数：conn 输入，目标连接      
      fdir 输入，待创建的文件目录路径
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_dir_create(
    asmcon_handle   conn,        
    asmbool         p_flag,
    sdbyte*         fdirectory,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：删除ASM文件目录
参数：conn 输入，目标连接      
      fdir 输入，待删除的文件目录路径
返回：成功，返回0；失败，错误码
*/
DllExport
ASMRETURN
dmasm_dir_delete(
    asmcon_handle   conn,        
    sdbyte*         fdirectory,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：创建磁盘组
参数：conn 输入，目标连接      
      group_name 输入，磁盘组名字，最大128字节，不包括字符串结尾符
      disk_path 输入，磁盘组所在初始磁盘的路径
返回：成功 0，失败，错误码
*/
DllExport 
ASMRETURN
dmasm_create_diskgroup(
    asmcon_handle   conn,        
    sdbyte*         group_name,
    sdbyte*         disk_path,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：根据名称，删除磁盘组
参数：conn 输入，目标连接      
      group_name 输入，磁盘组名字      
返回：成功 0，失败，错误码
*/
DllExport 
ASMRETURN
dmasm_drop_diskgroup_by_name(
    asmcon_handle   conn,        
    sdbyte*         group_name,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
功能：磁盘组中添加磁盘
参数：conn 输入，目标连接      
      group_name 输入，磁盘组名字
      disk_path 输入，添加磁盘的路径
返回：成功，返回0；失败，错误码
*/
DllExport 
ASMRETURN
dmasm_add_disk_to_diskgroup(
    asmcon_handle   conn,        
    sdbyte*         group_name,
    sdbyte*         disk_path,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_get_asmapi_sys_info(
    udint4*             au_size,
    udint4*             extent_size,
    udint4*             extent_arr_size,
    sdint4*             local_coding,
    sdint4*             local_langid,
    asmbool*            shm_inited,
    sdbyte*             err_desc,
    udint4*             err_len
);

/***********************************************************************************
purpose:
    新增low接口获取一个未使用磁盘的信息
NOTES:
    v$asmdisk获取磁盘信息使用该接口，防止外部直接调用dmasm_get_unused_disk_info造成错误
***********************************************************************************/
DllExport
ASMRETURN
dmasm_get_unused_disk_info_low(
    asmcon_handle       conn_in,
    asm_pathname_t*     disk_path,      /* 磁盘路径 */
    asm_name_t*         disk_name,      /* 磁盘名称 */
    udint4*             disk_size,      /* 磁盘大小 */
    udint2*             disk_au_size,   /* 磁盘au大小 */
    udint4              max_n_disk,     /* 收集磁盘的个数上限 */
    udint4*             real_n_disk,    /* 实际收集的磁盘个数  */
    udint4*             version,        /*OUT:磁盘版本  */
    asmbool*            is_ok,          /*OUT:物理磁盘是否损坏*/
    sdbyte*             err_desc,
    udint4*             err_len
);

DllExport
ASMRETURN
dmasm_get_unused_disk_info(
    asmcon_handle       conn_in, 
    asm_pathname_t*     disk_path,      /* 磁盘路径 */
    asm_name_t*         disk_name,      /* 磁盘名称 */
    udint4*             disk_size,      /* 磁盘大小 */
    udint2*             disk_au_size,   /* 磁盘au大小 */
    udint4              max_n_disk,     /* 收集磁盘的个数上限 */
    udint4*             real_n_disk,    /* 实际收集的磁盘个数  */
    sdbyte*             err_desc, 
    udint4*             err_len    
);

DllExport
ASMRETURN
dmasm_get_unused_disk_cnt(
    asmcon_handle       conn_in,     
    udint4*             cnt,    /* 磁盘个数 */
    sdbyte*             err_desc, 
    udint4*             err_len    
);

DllExport
ASMRETURN
dmasm_dir_get_first(
    asmcon_handle       conn_in,
    sdbyte*             path,           /* dir name */
    sdbyte*             suffix,         /* file suffix used as the filter, such as ".log" */    
    asm_dhandle_t*      dir_handle_out,
    ASM_FILE_ATTR*      fattr_out,
    asmbool*            exist_flag,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
ASMRETURN
dmasm_dir_get_next(
    asmcon_handle       conn_in,
    asm_dhandle_t       dir_handle,
    sdbyte*             path,           /* dir name */
    sdbyte*             suffix,         /* file suffix used as the filter, such as ".log" */    
    ASM_FILE_ATTR*      fattr_out,
    asmbool*            exist_flag,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
ASMRETURN
dmasm_dir_close(
    asmcon_handle       conn_in,
    asm_dhandle_t       dir_handle,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
ASMRETURN
dmasm_pwd(
    asmcon_handle       conn_in,
    sdbyte*             cur_path,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
asmbool
dmasm_dhandle_check(
    asm_dhandle_t       dhandle
);

DllExport
ASMRETURN
dmasm_file_attributes_get(
    asmcon_handle       conn_in,
    sdbyte*             path,
    ASM_FILE_ATTR*      fattr_out,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
ASMRETURN
dmasm_get_file_info(
    asmcon_handle   conn,
    asm_fhandle_t   file_id,
    ASM_FILE_ATTR*  fattr_out,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_path_is_asmdisk(
    asmcon_handle   conn,
    sdbyte*         path,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_file_is_exist(
    asmcon_handle   conn_in,
    sdbyte*         path,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_file_flush(
    asmcon_handle   conn_in,
    asm_fhandle_t   fhandle,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_conn_check(
    asmcon_handle   conn_in,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_path_is_valid(
    sdbyte*         path
);

DllExport
asmbool
dmasm_disk_info(
    asmcon_handle*  con,
    sdbyte*         path,
    udint8*         totalsize,
    udint8*         freesize
);

#endif
