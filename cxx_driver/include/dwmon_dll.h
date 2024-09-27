
#ifndef _DWMON_DLL_H_
#define _DWMON_DLL_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )
#else
#define DllImport
#define DllExport
#endif

/* data type */
typedef int                         DWMON_RETURN;

#ifndef _MON_COMM_DTYPE_
#define _MON_COMM_DTYPE_

typedef void*                       mhandle;
typedef signed char                 mschar;
typedef int                         mint4;
typedef unsigned int                muint4;
typedef unsigned short              msint2;
typedef unsigned int                mbool;
typedef unsigned char               mbyte;

#if defined(WIN32) || defined(WINDOWS)
typedef __int64                     mint8;
typedef unsigned __int64            muint8;
#else
typedef long long int               mint8;
typedef unsigned long long int      muint8;
#endif

#endif

//返回码
#define DWMON_SUCCESS               0
#define DWMON_ERROR                 (-1)
#define DWMON_INVALID_HANDLE        (-2)
#define DWMON_LOG_INIT_FAILED       (-3)
#define DWMON_SYS_INIT_FAILED       (-4)
#define DWMON_NOT_LOGIN             (-5)
#define DWMON_READ_INI_FAILED       (-6)
#define DWMON_INVALID_LOG_PATH      (-7)
#define DWMON_SET_EXECING_FAILED    (-8)
#define DWMON_RESET_EXECING_FAILED  (-9)
#define DWMON_INST_ERROR            (-10)
#define DWMON_SYS_NOT_OK            (-11)       /* tip命令检查返回值，系统不是正常状态 */
#define DWMON_MPPCTL_DIFF           (-12)       /* mpp控制文件不一致 */
#define DWMON_DWCTL_NO_ITEM         (-13)       /* dwctl没有接管项记录 */
#define DWMON_MULTI_CONFIRM_MON     (-14)       /* 存在多个确认监视器 */
#define DWMON_WATCH_CONN_FAIL       (-15)       /* 建立到所有守护进程的连接失败 */
#define DWMON_INVALID_ARGVAL        (-16)       /* 参数非法 */
#define DWMON_CODE_MSG_NOT_FOUND    (-17)       /* 没有找到code对应的错误信息 */
#define DWMON_OUT_OF_MEMORY         (-18)       /* 内存不足 */
#define DWMON_REACH_TO_MAX_CONN     (-19)       /* 监视器已达到最大连接数(10个) */
#define DWMON_CHECK_RECOV_LATER     (-20)       /* 当前无法判断备库是否可以RECOVER，需要稍后重试(比如有监视器命令正在执行、指定实例还未达到恢复间隔或者指定实例上的RLOG_BUF还未全部重演完成等情况)*/
#define DWMON_STDBY_CANNOT_RECOVER  (-21)       /* 备库不满足recover条件 */
#define DWMON_CHECK_OPEN_LATER      (-22)       /* 当前无法判断实例是否可自动OPEN，需要稍后重试（比如有监视器命令正在执行，或者实例还未启动到MOUNT状态等情况）*/
#define DWMON_INST_CANNOT_OPEN      (-23)       /* 实例无法自动OPEN */
#define DWMON_DW_CANNOT_OPEN        (-24)       /* 实例已经处于OPEN状态，但watch无法切换OPEN */
#define DWMON_PRIM_IS_OK            (-25)       /* 主库实例OPEN且主库watch OPEN，但存在其他异常实例 */
#define DWMON_NEED_WAIT_DW          (-26)       /* 没有正常主库（实例和watch都是OPEN状态） 或者 组中全部是local实例，但存在有实例没有OPEN，需要等待守护进程处理完成 */
#define DWMON_NEED_USER             (-27)       /* 没有正常主库（实例和watch都是OPEN状态） 或者 组中全部是local实例，但存在有实例没有OPEN，需要用户确认是否手动干预 */
#define DWMON_NEED_DEINIT           (-28)       /* 没有deinit，直接free handle报错 */
#define DWMON_INVALID_WALLET_PATH   (-29)       /* MON_WALLET_PATH为空，或该路径下没有合法的wallet文件 */
#define DWMON_THRD_PTY_LIB_LOAD_FAILED  (-30)   /* 第三方加密库加载失败，或者监视器生成密钥对失败，需要检查第三方加密库文件是否存在 */
#define DWMON_MLOG_SIZE_TOO_SMALL   (-31)       /* 联机日志空间太小 */
#define DWMON_INVALID_MON_NAME_LEN  (-32)       /* 监视器名长度非法 */
#define DWMON_NOT_MRAFT             (-33)       /* 当前不是多实例监视器 */

#define DWMON_STR_LEN                   64      /* 不包括结尾的'\0' */
#define DWMON_MAX_GROUP                 128     /* 监视器最多允许配置的组个数，mpp最多1024组，local单独成组? */
#define DWMON_MAX_GROUP_NON_LOCAL_INST  9       /* 每组最多的非本地实例个数(1主8备)*/
#define DWMON_MAX_GROUP_LOCAL_INST      24      /* 每组最多的本地实例个数(8异备+8同备+8个普通local实例)*/
#define DWMON_MAX_GROUP_IP              33      /* 每组最多允许配置的IP个数，local和non local总数 */

#define DWMON_MAX_TCP_CONN              10      /* 每个守护进程最多允许同时连接的监视器个数(DW2_MAX_M_TCP_CONN) */

//监视器协同退出类型
/* 说明:mraft没有raft的RRAFT_EXIT_ALL_PRE状态,这是因为监视器leader协同退出时不需要执行完全检查点也不需要等待多数follower落盘,
        mraft协同退出只需要一次通信,说明如下:
        若leader收到协同退出指令,直接通知follower退出,follower收到后直接退出,无需等待后续消息
        若follower收到协同退出指令,直接通知leader广播其他follower,然后自己直接退出,无需等待leader广播消息 */
#define MRAFT_EXIT_ALL_NONE                 0   //未配置
#define MRAFT_EXIT_ALL_LEADER               1   //leader协同退出的第1个状态，在leader上执行exit all或者收到follower转发的exit all命令时设置，leader先设置此状态，再启动协同推出，然后再启动正式退出，这两个动作共用这1个状态
#define MRAFT_EXIT_ALL_NOTIFY_LEADER        2   //follower协同退出的第1个状态(在follower上执行exit all的场景下才会有)，follower先设置此状态，再将exit all转发至leader --跟随者已通知领导者
#define MRAFT_EXIT_ALL_FOLLOWER_SHUTDOWN    3   //follower协同退出的第3个状态，follower收到leader的正式退出指令，并且开始真正退出
#define MRAFT_EXIT_ALL_NORMAL               4   //普通退出，仅退出自己

#define MRAFT_STAT_CANDIDATE    0           //候选者
#define MRAFT_STAT_LEADER       1           //领导者
#define MRAFT_STAT_FOLLOWER     2           //跟随者
#define MRAFT_STAT_NOT_LEADER   3           //非LEADER
#define MRAFT_STAT_UNKNOW       4           //未知

/********************************************************************************************/
/* 分配句柄 */
DllExport
DWMON_RETURN
dwmon_alloc_handle(
    mhandle*        mhdle
);

/* 销毁句柄 */
DllExport
DWMON_RETURN
dwmon_free_handle(
    mhandle         mhdle   //bug599409 接口以指针方式传入确保handle置空，防止重复free引发故障
);

/*********************************************************************
Purpose :
    销毁句柄
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_free_handle_low(
    mhandle*        mhdle    /*IN: 句柄信息 */
);

/* 初始化环境 */
DllExport
DWMON_RETURN
dwmon_init(
    mhandle         mhdle,      //输入句柄
    mschar*	        ini_path,   //ini文件路径
    mschar*         log_path    //log文件路径
);

/* 销毁环境 */
DllExport
DWMON_RETURN
dwmon_deinit(
    mhandle         mhdle
);

/* 设置命令执行标记以及正要执行的命令串名称 */
DllExport
DWMON_RETURN
dwmon_set_cmd_execing_with_command(
    mhandle         mhdle,      /* 监视器句柄 */
    mschar*         command     /* 上层控制台执行的命令串 */
);

/* 重置命令执行标记 */
DllExport
DWMON_RETURN
dwmon_reset_cmd_execing(
    mhandle         mhdle
);

/* 等待消息事件 */
DllExport
void
dwmon_msg_event_wait(
    mhandle         mhdle
);

/* 获取输出消息 */
DllExport
DWMON_RETURN
dwmon_get_exec_msg(
    mhandle         mhdle,          //监视器句柄
    mschar*         buf_msg,        //输出参数，消息缓冲区地址
    muint4          buf_len,        //输入参数，in:可填入消息buf的最大长度    
    muint4*         msg_len_out,    //输出参数，消息实际写入长度
    muint4*         get_flag        //输出参数，是否还有未读消息
);

/* 获取上层消息线程退出标记 */
DllExport
mbool
dwmon_get_msg_exit_flag(
    mhandle         mhdle
);

/* 设置上层消息线程退出事件 */
DllExport
void
dwmon_set_msg_exit_event(
    mhandle         mhdle
);

/* 通知并等待上层消息线程退出 */
DllExport
void
dwmon_msg_event_deinit(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_get_dw_confirm(
    mhandle         mhdle,
    mbool*          dw_confirm
);

DllExport
DWMON_RETURN
dwmon_get_mpp_flag(
    mhandle         mhdle,
    mbool*          mpp_flag
);

DllExport
DWMON_RETURN
dwmon_get_version(
    mhandle         mhdle,
    mschar*         version
);

/* 设置定时显示系统状态间隔 */
DllExport
DWMON_RETURN
dwmon_set_show_interval(
    mhandle         mhdle,
    muint4          show_interval
);

/* 获取定时显示系统状态间隔 */
DllExport
DWMON_RETURN
dwmon_get_show_interval(
    mhandle         mhdle,
    muint4*         show_interval
);

/* 设置日志自动记录间隔 */
DllExport
DWMON_RETURN
dwmon_set_log_interval(
    mhandle         mhdle,
    muint4          log_interval
);

/* 获取日志自动记录间隔 */
DllExport
DWMON_RETURN
dwmon_get_log_interval(
    mhandle         mhdle,
    muint4*         log_interval
);

/* 设置单个日志文件大小 */
DllExport
DWMON_RETURN
dwmon_set_log_file_size(
    mhandle         mhdle,
    muint4          log_file_size
);

/* 获取单个日志文件大小 */
DllExport
DWMON_RETURN
dwmon_get_log_file_size(
    mhandle         mhdle,
    muint4*         log_file_size
);

/* 获取日志路径 */
DllExport
DWMON_RETURN
dwmon_get_log_path(
    mhandle         mhdle,
    mschar*         log_path    /* 至少257长度*/
);

/* 设置日志总空间大小 */
DllExport
DWMON_RETURN
dwmon_set_log_space_limit(
    mhandle         mhdle,
    muint4          log_space_limit
);

/* 获取日志总空间大小 */
DllExport
DWMON_RETURN
dwmon_get_log_space_limit(
    mhandle         mhdle,
    muint4*         log_space_limit
);

/* 登录监视器 */
DllExport
DWMON_RETURN
dwmon_login(
    mhandle         mhdle,
    mschar*         username,
    mschar*         password
);

/*********************************************************************
Purpose :
    使用wallet登录监视器（从wallet钱包中读取用户名、密码登录）
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_login_wallet(
    mhandle         mhdle,          /* IN：监视器句柄 */
    mschar*         service_name    /* IN：服务名 */
);

/* 退出登录 */
DllExport
DWMON_RETURN
dwmon_logout(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_startup_database_watch(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_startup_watch(
    mhandle         mhdle,
    mschar*         group_name
);

DllExport
DWMON_RETURN
dwmon_startup_watch_all(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_stop_database_watch(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_stop_watch(
    mhandle         mhdle,
    mschar*         group_name
);

DllExport
DWMON_RETURN
dwmon_stop_watch_all(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_startup_group(
    mhandle         mhdle,
    mschar*         group_name
);

DllExport
DWMON_RETURN
dwmon_startup_group_all(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_stop_group(
    mhandle         mhdle,
    mschar*         group_name
);

/* 多组情况下，限定只能MPP */
DllExport
DWMON_RETURN
dwmon_stop_group_all(
    mhandle         mhdle
);

/* 强制open指定组的指定实例，只有一组时，允许不指定group_name，inst_name不允许为NULL */
DllExport
DWMON_RETURN
dwmon_open_database(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

/* 获取可切换主机的备机个数和实例名数组，只有一组时，允许不指定group_name */
DllExport
DWMON_RETURN
dwmon_get_switchover_standby(
    mhandle         mhdle,
    mschar*         group_name,
    muint4*         n_db,           /* 输入输出参数，输入：可获取的最大实例个数，输出：实际获取的实例个数 */
    mschar**        db_name_arr     /* 输出参数，实例名数组，和n_inst个数对应 */
);

/* 切换主备机实例，只有一组时，允许不指定group_name，只有一个备机时，允许不指定inst_name */
DllExport
DWMON_RETURN
dwmon_switchover(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

/* 获取可接管故障主机的备机个数和实例名数组，只有一组时，允许不指定group_name */
DllExport
DWMON_RETURN
dwmon_get_takeover_standby(
    mhandle         mhdle,
    mschar*         group_name,
    mbool           force_flag,
    muint4*         n_db,           /* 输入输出参数，输入：可获取的最大实例个数，输出：实际获取的实例个数 */
    mschar**        db_name_arr     /* 输出参数，实例名数组，和n_inst个数对应 */
);

DllExport
DWMON_RETURN
dwmon_takeover(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_takeover_force(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

/* 获取监控组个数，及名字 */
DllExport
DWMON_RETURN
dwmon_get_n_group(
    mhandle         mhdle,
    muint4*         n_group,        /* 输入输出参数，输入：可获取的最大组个数，输出：实际获取的组个数 */
    mschar**        group_name_arr  /* 输出参数，守护组名数组，和n_group个数对应 */
);

/* 获取指定组名的相关配置信息以及故障切换模式，只有一组时，允许不指定group_name */
DllExport
DWMON_RETURN
dwmon_get_group_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，组名 */
    muint4*         oguid,          /* oguid值 */
    muint4*         n_dw,           /* 输入输出参数，输入：可获取的最大守护进程个数，输出：实际获取的守护进程个数 */
    mschar**        dw_ip_arr,      /* 输出参数，watch ip数组，和n_dw个数对应 */
    msint2*         port_arr,       /* watch port */
    mschar*         dw_type,        /* watch配置的类型rt/timely/mpp */
    mschar*         dw_mode,        /* watch配置的故障切换模式auto/manual */
    mschar*         primary_name,   /* PRIMARY实例名 */
    muint4*         n_split,        /* 输入输出参数，输入：可获取的最大分裂组个数，输出：实际获取的分裂组个数 */
    mschar**        split_iname_arr,/* 输出参数，分裂组ctl文件最新的实例名数组，和n_split对应 */
    muint4*         n_db,           /* 非本地库个数 */
    mschar**        db_name_arr,    /* 非本地库名数组 */
    muint4*         n_local,        /* 输入输出参数，输入：可获取的最大本地实例个数，输出：实际获取的实例个数 */
    mschar**        local_name_arr  /* 输出参数，本地实例名数组, 和n_local对应 */
);

/* 获取指定组中分裂主机实例信息，只有一组时，允许不指定group_name */
DllExport
DWMON_RETURN
dwmon_get_split_sub_group_database(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，指定组名 */
    mschar*         db_name,        /* 输入参数，分裂组ctl文件最新的库名 */
    muint4*         n_db,           /* 输入输出参数，从属于db_name的库个数，不一定是备机，也可能是其他从属的主机，输入：可获取的最大库个数，输出：实际获取的库个数 */
    mschar**        db_name_arr     /* 输出参数，从属于db_name的库名数组，和n_db对应 */
);

DllExport
DWMON_RETURN
dwmon_get_database_arch_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，库所属组名 */
    mschar*		    db_name,        /* 输入参数，库名 */
    mschar*         arch_type,      /* 配置的归档类型rt/timely/mpp */
    muint4*         n_arch,         /* 输入输出参数，配置rt/timely/mpp归档数，输入：可获取的最大归档个数，输出：实际获取的归档个数 */
    mschar**        arch_dest,      /* 输出参数，归档目标实例名数组，和n_arch对应 */
    mschar**        mal_sta,        /* 输出参数，mal链路状态数组，和n_arch对应 */
    mschar**        arch_sta,       /* 输出参数，归档状态数组，和n_arch对应 */
    muint4*         n_async,        /* 输入输出参数，配置的异步归档数，输入：可获取的最大异步归档个数，输出：实际获取的异步归档个数 */
    mschar**        async_dest,     /* 输出参数，异步归档目标实例名数组，和n_async对应 */
    mschar**        async_mal_sta   /* 输出参数，到异备的归档状态数组，和n_async对应 */
);

/* 检查mppctl是否处于一致状态 */
DllExport
DWMON_RETURN
dwmon_check_mppctl(
    mhandle         mhdle
);

/* 恢复mppctl到一致状态 */
DllExport
DWMON_RETURN
dwmon_recover_mppctl(
    mhandle         mhdle
);

/* 获取mpp节点信息 */
DllExport
DWMON_RETURN
dwmon_get_mpp_site_info(
    mhandle         mhdle,      /* 输入参数，监视器句柄 */
    muint4*         n_site,     /* 输入输出参数，mpp站点数，输入：可获取的站点个数，输出：实际获取的站点个数 */
    muint4*         ep_seqno,   /* 输出参数，mpp站点号数组，和n_site对应 */
    mschar**        db_name,    /* 输出参数，mpp站点实例名数组，和n_site对应 */
    mschar**        db_ip,      /* 输出参数，mpp站点ip数组，和n_site对应 */
    muint4*         db_port     /* 输出参数，mpp站点port数组，和n_site对应 */
);

/* 检查当前系统运行状况 */
DllExport
DWMON_RETURN
dwmon_tip(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_get_watch_ctl_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名 */
    mschar*         db_name,        /* 输入参数，实例名 */
    mschar*         ctl_status,     /* 输出参数，dwctl文件状态 */
    mschar*         desc            /* 输出参数，dwctl分裂描述信息，缓存长度不能小于513 */ 
);

DllExport
DWMON_RETURN
dwmon_get_database_open_history(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名 */
    mschar*         db_name,        /* 输入参数，实例名 */
    muint4*         n_item          /* 输入输出参数，实例open记录个数 */
);

DllExport
DWMON_RETURN
dwmon_get_nth_open_history(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，库所属组名 */
    mschar*         db_name,        /* 输入参数，库名 */
    muint4          nth,            /* 输入参数，指定获取第nth个dwctl记录项 */
    mschar*         tguid,          /* 输出参数，tguid */
    muint8*         rowid,          /* 输出参数，系统表所在行的rowid */
    mschar*         time,           /* 输出参数，执行时间 */
    mschar*         sys_mode,       /* 输出参数，OPEN时所处的系统模式（PRIMARY/NORMAL） */
    mschar*         p_db_name,      /* 输出参数，对应主库的实例名 */
    mschar*         c_db_name,      /* 输出参数，当前库的实例名 */
    muint4*         p_db_magic,     /* 输入参数，对应主库的db_magic */
    muint4*         c_db_magic,     /* 输入参数，当前库的db_magic */
    msint2*         n_ep,           /* 输入输出参数，实例节点个数 */
    muint8*         aseq_arr,       /* 输出参数，aseq数组 */
    muint8*         alsn_arr        /* 输出参数，alsn数组 */
);

DllExport
DWMON_RETURN
dwmon_get_monitor_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名，只有一组允许不指定 */
    mschar*         db_name,        /* 输入输出参数(缓存长度不能小于17)，库名，允许是local守护类型的库，如果没有指定则返回dmmonitor.ini中第一个活动watch信息，并输出对应的库名 */
    muint4*         n_mon,          /* 输入输出参数，连接到inst_name的monitor个数，输入：可获取的最大monitor个数，输出：实际获取的monitor个数 */
    mschar**        conn_time_arr,  /* 输出参数，monitor创建连接时间数组，和n_mon对应 */
    muint4*         confirm_arr,    /* 输出参数，monitor的确认监视器标记数组，和n_mon对应 */
    muint8*         mid_arr,        /* 输出参数，monitor唯一ID数组，和n_mon对应 */
    mschar**        mon_ip_arr,     /* 输出参数，monitor的IP地址数组，和n_mon对应*/
    mschar**        mon_version_arr /* 输出参数，monitor的版本信息，和n_mon对应 */
);

DllExport
DWMON_RETURN
dwmon_get_error_msg_by_code(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mint4           code,           /* 输入参数，错误code */
    mschar*         buf_msg,        /* 输出参数，code对应的错误描述信息 */
    muint4          buf_len,        /* 输入参数，可填入buf缓存的最大长度，建议不小于4096 */
    muint4*         msg_len_out     /* 输出参数，buf缓存的实际写入长度 */
);

/*********************************************************************
Purpose :
    批量设置自动接管组
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_group_auto_takeover_list(
    mhandle         mhdle,              /* IN：监视器句柄 */
    mschar*         group_name,         /* IN：组名 */
    mschar*         list_str            /* IN：自动接管组配置串 */
);

/*********************************************************************
Purpose :
    批量取消自动接管组
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_cancel_group_auto_takeover_list(
    mhandle         mhdle,              /* IN：监视器句柄 */
    mschar*         group_name,         /* IN：组名 */
    mschar*         list_str            /* IN：自动接管组配置串 */
);

/*********************************************************************
Purpose :
    获取指定组的指定库的自动接管备选库列表，及其对应的自动接管优先级
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_auto_takeover_list(
    mhandle         mhdle,          /* IN：监视器句柄 */
    mschar*         group_name,     /* IN：组名 */
    mschar*         db_name,        /* IN：数据库名 */
    mschar**        takeover_list,  /* OUT：自动接管备选库名列表 */
    muint4*         priority_list,  /* OUT：自动接管备选库的优先级列表，与takeover_list一一对应 */
    muint4*         n_inst          /* IN/OUT：输入takeover_list数组长度吗，输出实际获取到的inst个数 */
);

/*********************************************************************
Purpose :
    设置备库的自动接管优先级（此接口需要在确认监视器上执行）
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_database_auto_takeover_priority(
    mhandle         mhdle,          /* IN：监视器句柄 */
    mschar*         group_name,     /* IN：组名 */
    mschar*         db_name,        /* IN：需要设置自动接管优先级的数据库名 */
    muint4          priority_level  /* IN：自动接管优先级 */
);

/* 设置备库的恢复间隔时间 */
DllExport
DWMON_RETURN
dwmon_set_database_recover_time(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,        /* 输入参数，需要设置恢复时间间隔的备库名 */
    muint4          recover_time    /* 输入参数，需要设置的恢复时间间隔 */
);

DllExport
DWMON_RETURN
dwmon_get_n_apply(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,            /* 输入参数，需要获取日志同步信息的备库名 */
    mschar*         ep_name,            /* 输出参数，获取apply的备库主ep名称 */
    msint2*         n_apply,            /* 输出，apply个数 */
    mschar*         prim_name           /* 备库当前对应的主库实例名 */
);

/* 获取备库inst实例上主ep记录的第nth个apply_info上的lsn等信息，供show命令打印显示，这里不输出详细统计信息 */
DllExport
DWMON_RETURN
dwmon_get_ep_nth_apply_info(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,            /* 输入参数，需要获取apply信息的备库名 */
    muint4          nth,                /* 输入参数，获取inst_name库上第nth个apply_info上的lsn等相关信息 */
    mschar*         prim_name,          /* 输出参数，第nth个apply_info上记录的pname信息，可能为空 */
    msint2*         dsc_seqno,          /* 输出参数，主库节点seqno */
    muint8*         sseq,               /* 输出参数，备库可重演到的最大日志包序号 */
    muint8*         slsn,               /* 输出参数，备库可重演到的最大LSN，对应日志包序号为sseq（和dsc_seqno对应）*/
    muint8*         kseq,               /* 输出参数，非自动切换模式下，备库保持不重演的日志包序号 */
    muint8*         klsn,               /* 输出参数，非自动切换模式下，备库保持不重演的最大LSN，对应的日志包序号为kseq（和dsc_seqno对应）*/
    muint8*         aseq,               /* 输出参数，备库已经重演到的日志包序号（和dsc_seqno对应）*/
    muint8*         alsn,               /* 输出参数，备库已经重演到的lsn值，对应的日志包序号为aseq（和dsc_seqno对应）*/
    muint4*         n_task,             /* 输出参数，当前还剩余的重演任务数，在watch/monitor中使用 */
    muint8*         tsk_mem_used        /* 输出参数，当前任务队列占用的总内存大小（字节）*/
);

/* 修改备库的归档状态无效 */
DllExport
DWMON_RETURN
dwmon_set_database_arch_invalid(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name         /* 输入参数，需要设置恢复时间间隔的备库名 */
);

/*********************************************************************
Purpose :
	获取指定实例的守护进程配置信息
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_watch_config_info(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入输出参数，守护组名，只有一组时可以不指定，如果没有指定，则输入组名，不允许为NULL */
    mschar*         inst_name,          /* 输入参数，指定实例名 */
    mschar*         dw_type,            /* dmwatcher.ini的dw_type配置值 */
    mschar*         dw_mode,            /* dmwatcher.ini的dw_mode配置值 */
    muint4*         dw_error_time,      /* dmwatcher.ini的dw_error_time配置值 */
    muint4*         inst_oguid,         /* dmwatcher.ini的inst_oguid配置值 */
    muint4*         inst_error_time,    /* dmwatcher.ini的inst_error_time配置值 */
    muint4*         inst_recover_time,  /* dmwatcher.ini的inst_recover_time配置值 */
    mschar*         inst_ini,               /* dmwatcher.ini的inst_ini配置值 */
    mschar*         dcr_ini,                /* dmwatcher.ini的dcr_ini配置值 */
    muint4*         inst_auto_restart,      /* dmwatcher.ini的inst_auto_restart配置值 */
    mschar*         inst_startup_cmd,       /* dmwatcher.ini的inst_startup_cmd配置值 */
    muint4*         inst_host_check,        /* dmwatcher.ini的inst_host_check配置值 */
    muint4*         rlog_send_threshold,    /* dmwatcher.ini的rlog_send_threshold配置值 */
    muint4*         rlog_apply_threshold,   /* dmwatcher.ini的rlog_apply_threshold配置值 */
    mschar*         dcs_startup_cmd,        /* dmwatcher.ini的DCS_STARTUP_CMD配置值 */
    mschar*         dcs_ini,                /* dmwatcher.ini的dcs_ini配置值 */
    muint4*         dcs_port                /* dmwatcher.ini的dcs_port配置值 */
);

/* 设置指定组中所有备库归档无效，如果没有指定group_name，则对所有组执行 */
DllExport
DWMON_RETURN
dwmon_set_group_arch_invalid(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name          /* 输入参数，守护组名，不指定则对所有组执行 */
);

/* 设置指定组中所有备库的恢复间隔，如果没有指定group_name，则对所有组执行 */
DllExport
DWMON_RETURN
dwmon_set_group_recover_time(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入参数，守护组名，不指定则对所有组执行 */
    muint4          recover_time        /* 输入参数，恢复间隔，只修改主库watch的内存值 */
);

/*********************************************************************
Purpose :
    从备库守护进程上获取主库的历史信息
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_primary_info(
    mhandle         mhdle,      /* IN：监视器句柄 */
    mschar*         group_name  /* IN：组名 */
);

/* 设置指定组中所有守护进程参数值，如果没有指定group_name，则对所有组执行 */
DllExport
DWMON_RETURN
dwmon_set_group_para_value(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入参数，守护组名，不指定则对所有组执行 */
    mschar*         para_name,          /* 输入参数，待修改的参数名称 */
    mschar*         para_value          /* 输入参数，待修改的参数值，修改所有watch的内存值和dmwatcher.ini文件值 */
);

/* 将备库分离出守护系统 */
DllExport
DWMON_RETURN
dwmon_detach_database(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name             /* 输入参数，指定备库名 */
);

/* 备库维护完成后，重新将备库加回 */
DllExport
DWMON_RETURN
dwmon_attach_database(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name             /* 输入参数，指定备库名 */
);

/* 强杀指定组的所有server */
DllExport
DWMON_RETURN
dwmon_kill_group(
    mhandle         mhdle,
    mschar*         group_name
);

/* 强杀所有组的所有server */
DllExport
DWMON_RETURN
dwmon_kill_group_all(
    mhandle         mhdle
);

/* 检查指定实例是否满足自动recover条件 */
DllExport
DWMON_RETURN
dwmon_check_recover(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，组名 */
    mschar*         db_name         /* 输入参数，实例名 */
);

/* 获取组中第nth个库的全局信息 */
DllExport
DWMON_RETURN
dwmon_get_nth_database_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名 */
    muint4          nth,            /* 输入参数，取第nth个实例信息 */
    mschar*         dw_time,        /* 守护进程当前时间 */
    mschar*         dw_ip,          /* 守护进程IP地址 */
    msint2*         dw_port,        /* 守护进程TCP端口 */
    mschar*         dw_type,        /* 守护类型 */
    mschar*         dw_mode,        /* 故障切换模式 */
    muint4*         dw_err_time,    /* 远程守护进程故障认定时间间隔 */
    mschar*         dw_sta,         /* 守护进程状态 */
    mschar*         dw_sub_sta,     /* 守护进程子状态 */
    mschar*         dw_ctl_sta,     /* 守护进程控制文件状态 */
    mschar*         db_name,        /* 实例名 */
    mschar*         db_ok_str,      /* 实例是否正常 */
    mschar*         svr_mode,       /* 实例模式 */
    mschar*         svr_status,     /* 实例状态 */
    mschar*         arch_type,      /* 库上主ep配置的归档类型 */
    mschar*         arch_status,    /* 当前库为rt/timely备库时，主库到当前备库的归档状态 */
    muint4*         pmnt_magic,     /* 数据库永久魔数 */
    muint4*         db_magic,       /* 数据库魔数 */
    msint2*         n_ep,           /* 输入输出参数，库中的ep个数 */
    msint2*         ep_seqno_arr,   /* 库中的ep seqno数组 */
    mschar**        ep_name_arr,    /* 库中的ep实例名数组 */
    msint2*         dsc_ctl_node,   /* 库中控制ep的seqno */
    mschar*         dsc_status,     /* 库的hpc状态 */
    msint2*         n_ok_ep,        /* 输入输出参数，库中的ok ep个数 */
    msint2*         ok_ep_arr,      /* 库中的ok ep的seqno数组 */
    msint2*         n_break_ep,     /* 输入输出参数，当前正在故障处理的节点数*/
    msint2*         break_ep_arr    /* 输出参数，当前正在故障处理的ep seqno数组 */
);

/*********************************************************************
Purpose :
    获取指定实例名所在库的全局信息
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_info_by_name(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名 */
    mschar*         db_name,        /* 输入参数，实例名 */
    mschar*         dw_time,        /* 主守护进程当前时间 */
    mschar*         dw_ip,          /* 主守护进程IP地址 */
    msint2*         dw_port,        /* 主守护进程TCP端口 */
    mschar*         dw_type,        /* 主守护类型 */
    mschar*         dw_mode,        /* 主守护进程配置的故障切换模式 */
    muint4*         dw_err_time,    /* 远程主守护进程故障认定时间间隔 */
    mschar*         dw_sta,         /* 主守护进程状态 */
    mschar*         dw_sub_sta,     /* 主守护进程子状态 */
    mschar*         dw_ctl_sta,     /* 守护进程控制文件状态 */
    mschar*         dbt_ok_str,     /* 库是否正常 */
    mschar*         svr_mode,       /* 库模式 */
    mschar*         svr_status,     /* 库状态 */
    mschar*         arch_type,      /* 库上主ep配置的归档类型 */
    mschar*         arch_status,    /* 当前库为rt/timely备库时，主库到当前备库的归档状态 */
    muint4*         pmnt_magic,     /* 数据库永久魔数 */
    muint4*         db_magic,       /* 数据库魔数 */
    msint2*         n_ep,           /* 库中的ep个数 */
    msint2*         ep_seqno_arr,   /* 库中的ep seqno数组 */
    mschar**        ep_name_arr,    /* 库中的ep实例名数组 */
    msint2*         dsc_ctl_node,   /* 库中控制ep的seqno */
    mschar*         dsc_status,     /* 库的hpc状态 */
    msint2*         n_ok_ep,        /* 库中的ok ep个数，取自master ep，在hpc_master != 0xFF时有效 */
    msint2*         ok_ep_arr,      /* 库中的ok ep的seqno数组，取自master ep，在hpc_master != 0xFF时有效 */
    msint2*         n_break_ep,     /* 输入输出参数，当前正在故障处理的节点数*/
    msint2*         break_ep_arr    /* 输出参数，当前正在故障处理的ep seqno数组 */
);

DllExport
DWMON_RETURN
dwmon_get_database_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名 */
    mschar*         db_name,        /* 输入参数，实例所属库的名称 */
    msint2*         n_ep,           /* 输入输出参数，输出ep个数 */
    msint2*         ep_seqno_arr,   /* 输出参数，输出所有ep的seqno数组 */
    mschar**        ep_name_arr,    /* 输出参数，输出所有ep实例名数组 */
    msint2*         dsc_ctl_node,   /* 输出参数，输出库中控制ep的seqno */
    mschar*         dsc_status,     /* 库的hpc状态 */
    msint2*         n_ok_ep,        /* 输入输出参数，输出库中ok ep个数 */
    msint2*         ok_ep_arr,      /* 输出参数，输出库中ok ep的seqno数组 */
    msint2*         n_break_ep,     /* 输入输出参数，当前正在故障处理的节点数 */
    msint2*         break_ep_arr    /* 输出参数，当前正在故障处理的ep seqno数组 */
);

DllExport
DWMON_RETURN
dwmon_get_ep_info_by_name(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名 */
    mschar*         ep_name,        /* 输入参数，ep实例名 */
    muint4*         ep_port,        /* 实例端口号 */
    mschar*         ep_ok_str,      /* 实例是否正常 */
    mschar*         svr_mode,       /* 实例模式 */
    mschar*         svr_status,     /* 实例状态 */
    mschar*         prim_inst,      /* 对应PRIMARY实例名 */
    mschar*         prim_mal_sta,   /* 对应PRIMARY实例到本实例的MAL链路状态  只对备库有效，输出主库主ep到ep_name所在的备库主ep的mal链路状态 */
    mschar*         prim_arch_type, /* 对应PRIMARY实例到本实例的归档类型 */
    mschar*         prim_arch_sta,  /* 对应PRIMARY实例到本实例的归档状态，只对备库有效，输出主库主ep到ep_name所在的备库主ep的归档状态 */
    muint8*         fseq,           /* 已写入联机日志的rlog_pkg包序号 */
    muint8*         flsn,           /* 已写入联机日志的flsn值，对应的包序号为fseq */
    muint8*         cseq,           /* 系统当前已经分配的最大RLOG_PKG包序号 */
    muint8*         clsn,           /* 系统当前已经分配的最大LSN值，对应的包序号为cseq */
    mschar*         arch_type,      /* 实例自身配置的归档类型rt/timely */
    muint4*         n_arch,         /* 实例自身配置的rt/timely归档数 */
    muint4*         n_async,        /* 实例自身配置的异步归档数 */
    muint4*         n_subscb,       /* 实例自身配置的订阅归档数 0 or 1*/
    msint2*         dsc_seqno,      /* 实例的seqno */
    mschar*         g_dw_status,    /* ep上设置的全局状态标记 */
    mbyte*          mpp_flag_mem,   /* 内存中的mpp_ini*/
    mbyte*          mpp_flag_file   /* ini文件中的mpp_ini*/
);

DllExport
DWMON_RETURN
dwmon_get_nth_ep_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，实例所属组名 */
    mschar*         db_name,        /* 输入参数，实例所属的库名 */
    muint4          nth,            /* 输入参数，取inst_name库上的第nth个实例信息 */
    mschar*         ep_name,        /* 输出参数，ep实例名 */
    muint4*         ep_port,        /* 实例端口号 */
    mschar*         ep_ok_str,      /* 实例是否正常 */
    mschar*         svr_mode,       /* 实例模式 */
    mschar*         svr_status,     /* 实例状态 */
    mschar*         prim_inst,      /* 对应PRIMARY实例名 */
    mschar*         prim_mal_sta,   /* 对应PRIMARY实例到本实例的MAL链路状态  只对备库有效，输出主库主ep到ep_name所在的备库主ep的mal链路状态 */
    mschar*         prim_arch_type, /* 对应PRIMARY实例到本实例的归档类型 */
    mschar*         prim_arch_sta,  /* 对应PRIMARY实例到本实例的归档状态，只对备库有效，输出主库主ep到ep_name所在的备库主ep的归档状态 */
    muint8*         fseq,           /* 已写入联机日志的rlog_pkg包序号 */
    muint8*         flsn,           /* 已写入联机日志的flsn值，对应的包序号为fseq */
    muint8*         cseq,           /* 系统当前已经分配的最大RLOG_PKG包序号 */
    muint8*         clsn,           /* 系统当前已经分配的最大LSN值，对应的包序号为cseq */
    mschar*         arch_type,      /* 实例自身配置的归档类型rt/timely */
    muint4*         n_arch,         /* 实例自身配置的rt/timely归档数 */
    muint4*         n_async,        /* 实例自身配置的异步归档数 */
    muint4*         n_subscb,       /* 实例自身配置的订阅归档数 0 or 1*/
    msint2*         dsc_seqno,      /* 实例的seqno */
    mschar*         g_dw_status,    /* ep上设置的全局状态标记 */
    mbyte*          mpp_flag_mem,   /* 内存中的mpp_ini*/
    mbyte*          mpp_flag_file   /* ini文件中的mpp_ini*/
);

/* 检查指定实例是否满足自动OPEN条件 */
DllExport
DWMON_RETURN
dwmon_check_open(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，组名 */
    mschar*         db_name         /* 输入参数，实例名 */
);

/* 清理指定实例的归档发送统计信息 */
DllExport
DWMON_RETURN
dwmon_clear_database_arch_send_info(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_clear_group_arch_send_info(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name          /* 输入参数，守护组名，不指定则对所有组执行 */
);

/* 清理指定实例的RAPPLY_INFO */
DllExport
DWMON_RETURN
dwmon_clear_database_rapply_stat(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_clear_group_rapply_stat(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name          /* 输入参数，守护组名，不指定则对所有组执行 */
);

/* 找出指定备库的源库名称 */
DllExport
DWMON_RETURN
dwmon_get_source_database_name(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,        /* 输入参数，待查找源库的备库实例名 */
    mschar*         source_name     /* 输出参数，输出源库实例名（如果inst_name是异步备库，源库可能也是STANDBY模式）*/
);

/* 获取源ep到目标实例inst_name的归档发送信息 */
DllExport
DWMON_RETURN
dwmon_get_ep_arch_send_info(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         source_name,    /* 输入参数，源库的某个ep实例名（如果是异步备库，源库可能也是STANDBY模式） */
    mschar*         db_name,        /* 输入参数，需要获取日志同步信息的备库名 */
    muint4*         time_in_ini,        /* 输出参数，主dmwatcher.ini中配置的恢复时间间隔(inst_recover_time)，对local守护类型无效 */
    muint4*         time_in_mem,        /* 输出参数，主dmwatcher内存中当前设置的恢复时间间隔，对local守护类型无效 */
    mschar*         last_recover_time,  /* 输出参数，主dmwatcher上次恢复时间，对local守护类型无效 */
    mint4*          last_recover_code,  /* 输出参数，主dmwatcher上次恢复code，对local守护类型无效 */
    mschar*         arch_type,          /* 输出参数，source_name到inst_name的归档类型rt/timely/async */
    mschar*         mal_sta,            /* 输出参数，source_name到inst_name备库主ep的mal链路状态 */
    mschar*         arch_sta,           /* 输出参数，source_name到inst_name备库主ep的归档状态 */
    mschar*         send_type,          /* 输出参数，source_name到inst_name的最近一次arch发送类型（实时同步或watch发起的recovery同步） */
    mschar*         last_start_time,    /* 输出参数，source_name到inst_name的最近一次arch发送起始时间 */
    mschar*         last_end_time,      /* 输出参数，source_name到inst_name的最近一次arch发送结束时间 */
    mint8*          last_send_time,     /* 输出参数，source_name到inst_name的最近一次arch发送耗时（微秒） */
    muint8*         last_start_lsn,     /* 输出参数，source_name到inst_name的最近一次arch发送起始lsn */
    muint8*         last_end_lsn,       /* 输出参数，source_name到inst_name的最近一次arch发送结束lsn */
    muint4*         last_send_len,      /* 输出参数，source_name到inst_name的最近一次arch发送长度（字节） */
    muint4*         last_send_ptx,      /* 输出参数，source_name到inst_name的最近一次arch发送的ptx个数 */
    mint4*          code,               /* 输出参数，source_name到inst_name的最近一次arch发送code */
    mschar*         desc_info,          /* 输出参数，source_name到inst_name的最近一次arch发送描述信息 */
    mint4*          recnt_cnt,          /* 输出参数，source_name到inst_name最近发送次数的N值 */
    mint8*          recnt_send_len,     /* 输出参数，source_name到inst_name最近N次累计日志发送长度（字节）（N值取自recnt_cnt） */
    mint8*          recnt_ptx_cnt,      /* 输出参数，source_name到inst_name最近N次累计日志发送ptx个数 */
    mint8*          recnt_send_time,    /* 输出参数，source_name到inst_name最近N次累计日志发送耗时（微秒）  */
    mint8*          max_send_time,      /* 输出参数，source_name到inst_name最大发送耗时（微秒）*/
    mschar*         max_end_time,       /* 输出参数，source_name到inst_name最大发送耗时的结束时间 */
    muint4*         max_ptx_cnt,        /* 输出参数，source_name到inst_name最大发送的ptx个数*/
    muint4*         max_send_len,       /* 输出参数，source_name到inst_name最大发送的日志长度（字节）*/
    mint8*          max_send_lsn,       /* 输出参数，source_name到inst_name最大发送的日志lsn值 */
    mint8*          total_send_cnt,     /* 输出参数，source_name到inst_name累计发送次数*/
    mint8*          total_send_len,     /* 输出参数，source_name到inst_name累计发送日志长度（字节）*/
    mint8*          total_ptx_cnt,      /* 输出参数，source_name到inst_name累计发送ptx个数*/
    mint8*          total_send_time     /* 输出参数，source_name到inst_name累计发送耗时（微秒）*/
);

DllExport
DWMON_RETURN
dwmon_get_ep_nth_apply_stat(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,            /* 输入参数，需要获取日志同步信息的备库名 */
    muint4          nth,                /* 输入参数，获取inst_name的第nth个apply_info信息 */
    mschar*         prim_name,          /* 输出参数，第nth个apply_info上记录的主库节点名称 */
    msint2*         dsc_seqno,          /* 输出参数，主库节点seqno */
    muint8*         sseq,               /* 输出参数，备库可重演到的最大日志包序号  */
    muint8*         slsn,               /* 输出参数，备库可重演到的最大LSN，对应的日志包序号为sseq（和dsc_seqno对应）*/
    muint8*         kseq,               /* 输出参数，非自动切换模式下，备库保持不重演的日志包序号 */
    muint8*         klsn,               /* 输出参数，非自动切换模式下，备库保持不重演的最大LSN，对应日志包序号为kseq（和dsc_seqno对应）*/
    muint8*         aseq,               /* 输出参数，备库已经重演到的日志包序号 */
    muint8*         alsn,               /* 输出参数，备库已经重演到的lsn值，对应日志包序号为aseq（和dsc_seqno对应）*/
    muint4*         n_task,             /* 输出参数，当前还剩余的重演任务数，在watch/monitor中使用 */
    muint8*         tsk_mem_used,       /* 输出参数，当前任务队列占用的总内存大小（字节）*/    
    mint4*          recnt_apply_num,    /* 输出参数，最近累计重演的次数N */
    muint4*         last_recved_len,    /* 输出参数，最近一次收到的日志长度（字节）*/
    mint8*          last_res_time,      /* 输出参数，最近一次消息响应时间（微秒）*/
    mint8*          last_wait_time,     /* 输出参数，最近一次任务等待时间（微秒）*/
    muint4*         last_apply_len,     /* 输出参数，最近一次重演的日志长度（字节）*/
    mint8*          last_apply_time,    /* 输出参数，最近一次重演耗时（微秒）*/
    mint8*          recnt_recved_len,   /* 输出参数，最近N次累计接收长度（N值取自recnt_apply_num） */
    mint8*          recnt_res_time,     /* 输出参数，最近N次累计响应时间（微秒） */
    mint8*          recnt_wait_time,    /* 输出参数，最近N次累计等待时间（微秒） */
    mint8*          recnt_apply_len,    /* 输出参数，最近N次累计重演长度（字节） */
    mint8*          recnt_apply_time,   /* 输出参数，最近N次累计重演时间（微秒） */
    mint8*          max_res_time,       /* 输出参数，最大消息响应时间（微秒） */
    mint8*          max_wait_time,      /* 输出参数，最大任务等待时间（微秒） */
    mint8*          max_apply_time,     /* 输出参数，最大任务重演时间（微秒） */
    muint4*         max_apply_len,      /* 输出参数，和max_apply_time对应的日志长度（字节） */
    mint8*          total_recved_num,   /* 输出参数，累计收到日志缓冲区个数 */
    mint8*          total_recved_len,   /* 输出参数，累计收到日志量（字节）*/
    mint8*          total_apply_num,    /* 输出参数，累计重演日志个数 */
    mint8*          total_apply_len,    /* 输出参数，累计重演日志量（字节）*/
    mint8*          total_res_time,     /* 输出参数，累计消息响应时间，收到消息到响应消息（微秒） */
    mint8*          total_wait_time,    /* 输出参数，累计任务等待时间（微秒） */
    mint8*          total_apply_time    /* 输出参数，累计日志重演时间（微秒）*/
);

/*********************************************************************
Purpose :
    获取apply info并行重演信息  
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_ep_nth_apply_with_parallel_info(
    mhandle         mhdle,              /* IN: 监视器句柄 */
    mschar*         group_name,         /* IN: 守护组名，只有一组时可以不指定 */
    mschar*         db_name,            /* IN: 需要获取日志同步信息的备库名 */
    muint4          nth,                /* IN: 获取inst_name的第nth个apply_stat统计信息 */
    mschar*         prim_name,          /* OUT:第nth个apply_info上记录的pname信息，可能为空 */
    msint2*         dsc_seqno,          /* OUT:主库节点seqno */
    muint8*         sseq,               /* OUT:备库可重演到的最大日志包序号 */
    muint8*         slsn,               /* OUT:备库可重演到的最大LSN，对应日志包序号为sseq（和dsc_seqno对应）*/
    muint8*         kseq,               /* OUT:非自动切换模式下，备库保持不重演的日志包序号 */
    muint8*         klsn,               /* OUT:非自动切换模式下，备库保持不重演的最大LSN，对应的日志包序号为kseq（和dsc_seqno对应）*/
    muint8*         rseq,               /* OUT:备库已经重演到的日志包序号（和dsc_seqno对应）*/
    muint8*         rlsn,               /* OUT:备库已经重演到的lsn值，对应的日志包序号为aseq（和dsc_seqno对应）*/
    msint2*         n_pll,              /* OUT:并行度信息 */
    muint8*         redo_lsn_arr,       /* OUT:redo lsn信息，从plog redo struct上获取 */
    muint4*         n_task,             /* OUT:当前还剩余的重演任务数，在watch/monitor中使用 */
    muint8*         tsk_mem_used        /* OUT:Z当前任务队列占用的总内存大小（字节）*/    
);

DllExport
DWMON_RETURN
dwmon_stop_database(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name         /* 输入参数，库名 */
);

DllExport
DWMON_RETURN
dwmon_startup_database(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name         /* 输入参数，库名 */
);

DllExport
DWMON_RETURN
dwmon_kill_database(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name         /* 输入参数，库名 */
);

/* 获取指定实例的DMCSS配置信息 */
DllExport
DWMON_RETURN
dwmon_get_css_config_info(
    mhandle         mhdle,              /* 输入参数，监视器句柄 */
    mschar*         group_name,         /* 输入输出参数，守护组名，只有一组时可以不指定，如果没有指定，则输入组名，不允许为NULL */
    mschar*         inst_name,          /* 输入参数，指定实例名 */
    muint4*         asm_restart_itvl,   /* 输出参数，dmdcr.ini的asm_restart_itvl配置值 */
    muint4*         db_restart_itvl     /* 输出参数，dmdcr.ini的db_restart_itvl配置值 */
);

/* 打开指定组中所有RAC节点的自动拉起功能 */
DllExport
DWMON_RETURN
dwmon_set_group_auto_restart_on(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name      /* 输入参数，守护组名，不指定则对所有组执行 */
);

/* 关闭指定组中所有RAC节点的自动拉起功能 */
DllExport
DWMON_RETURN
dwmon_set_group_auto_restart_off(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name      /* 输入参数，守护组名，不指定则对所有组执行 */
);

DllExport
DWMON_RETURN
dwmon_get_takeover_time(
    mhandle         mhdle
);

/*********************************************************************
Purpose :
    获取指定守护组自动接管时间
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_takeover_time_by_group_name(
    mhandle         mhdle,          /* IN:  监视器句柄*/
    mschar*         group_name,     /* IN:  守护组名，只有一组时可以不指定 */
    muint4*         remain_time,    /* OUT: 自动接管时间 */
    mschar*         inst_name       /* OUT: 接管实例名   */
);

/************************************************************************
purpose:
获取监视器状态
/************************************************************************/
DllExport
DWMON_RETURN
dwmon_get_monitor_state(
    mhandle             mhdle,          /* 输入参数，监视器句柄 */
    muint4*             n_mon,          /* 输出参数, 监视器个数 */
    mschar**            mon_name_arr,   /* 输出参数，monitor名字数组, 和n_mon对应 */
    muint4*             mon_state_arr,  /* 输出参数，monitor的监视器状态数组, 和n_mon对应 */
    muint4*             mon_id_arr,     /* 输出参数，monitorID数组, 和n_mon对应 */
    muint4*             mon_role_arr,   /* 输出参数, monitor角色数组, 和n_mon对应 */
    mschar**            mon_ip_arr,     /* 输出参数，monitor的IP地址数组，和n_mon对应*/
    muint4*             mon_port_arr,   /* 输出参数，monitor的端口号信息，和n_mon对应 */
    muint4*             mon_bro,        /* 输出参数, monitor的广播延时 */
    muint4*             mon_vote        /* 输出参数, monitor的投票延时 */
);

/***********************************************************************
Purpose:
    monitor层设置异步备库重演时间点接口
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_database_until_time(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,        /* 输入参数，需要设置重演时间点的备库名 */
    mschar*         until_time      /* 输入参数，需要设置的异步备库重演时间点 */
);

/***********************************************************************
Purpose:
    monitor层获取异步备库重演时间点接口
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_until_time(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,        /* 输入参数，需要获取重演时间点的备库名 */
    mschar*         until_time,     /* 输出参数，异步备库的重演时间点 */
    mbool*          apply_over      /* 输出参数，TRUE/FALSE，备库是否已重演到指定的until_time时间点 */
);

/***********************************************************************
Purpose:
monitor层获取rfile的n_max_ep seq lsn
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_rfil_lsn(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,        /* 输入参数，需要获取重演时间点的备库名 */
    muint4*         n_max_ep,        /* 输入参数，需要获取重演时间点的备库名 */
    muint8*         keep_seq,       /* 输出参数，monitor的监视器状态数组, 和n_mon对应 */
    muint8*         keep_lsn        /* 输出参数，monitor的监视器状态数组, 和n_mon对应 */
);

/***********************************************************************
Purpose:
monitor层获取ep subscb_mode
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_subscb_mode(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,        /* 输入参数，需要获取重演时间点的备库名 */
    muint4*         subscb_mode        /* 输出参数，monitor的监视器状态数组, 和n_mon对应 */
);

/***********************************************************************
Purpose:
    获取指定ep的IP地址
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_ep_host(
    mhandle         mhdle,          /* IN: 监视器句柄 */
    mschar*         group_name,     /* IN: 实例所属组名 */
    mschar*         ep_name,        /* IN: ep实例名 */
    mschar*         ep_host         /* OUT: 输出ep的IP地址，如果配置有外网IP，则输出外网IP，否则输出内网IP */
);

/***********************************************************************
Purpose:
    监视器获取指定备库的APPLY_WAIT标记，标记用于表示备库是否是事务一致的
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_apply_wait(
    mhandle         mhdle,          /* 输入参数，监视器句柄 */
    mschar*         group_name,     /* 输入参数，守护组名，只有一组时可以不指定 */
    mschar*         db_name,        /* 输入参数，备库名 */
    mbool*          apply_wait      /* 输出参数，TRUE/FALSE，事务一致标志 */
);

/*********************************************************************
Purpose :
    获取指定库上配置的同步归档信息
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_sync_arch_info(
    mhandle         mhdle,          /* IN: 输入参数，监视器句柄 */
    mschar*         group_name,     /* IN: 输入参数，库所属组名 */
    mschar*         db_name,        /* IN: 输入参数，库名 */
    muint4*         n_sync,         /* IN/OUT: 输入要获取的sync归档个数，输出实际填充的sync归档数 */
    mschar**        sync_dest,      /* OUT: 同步归档目标实例名数组 */
    mschar**        sync_mal_sta,   /* OUT: 到同步备库的mal链路状态数组 */
    mschar**        sync_arch_sta   /* OUT: 到同步备库的归档状态数组 */
);

/*********************************************************************
Purpose :
    多实例监视器创建联机日志文件
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_create_mlog(
    mhandle         mhdle,      /* IN: 监视器句柄 */
    mschar*         file_path,  /* IN: 文件路径   */
    muint8          file_size,  /* IN: 文件大小   */
    mschar*         mon_name,   /* IN: 监视器名   */
    muint4          mon_magic   /* IN: 监视器魔数 */
);

/*********************************************************************
Purpose :
    读取协同退出标记
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_exit_all(
    mhandle         mhdle,    /* IN: 监视器句柄 */
    muint4*         exit_all    /* OUT: 协同退出标记 */
);

/*********************************************************************
Purpose :
    读取多实例监视器相关信息
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_mraft_info(
    mhandle         mhdle,    /* IN: 监视器句柄 */
    muint4*         n_dest,   /* OUT:监视器数目 */
    mbyte*          vote_stat,/* OUT:选举角色   */
    muint4*         leader_id, /* OUT: leader_id */
    mbool*          hp_flag,  /* OUT:堆积标记   */
    muint4*         l_term_id, /* OUT: 当前任期号 */
    muint8*         c_seqno,  /* OUT:c_seqno    */
    muint8*         f_seq_arr, /* OUT: f_seqno_arr */
    muint4*         term_id_arr /* OUT: term_id_arr */
);

/*********************************************************************
Purpose :
    根据角色设置协同退出标记
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_exit_all();

/*********************************************************************
Purpose :
    读取监视器堆积标记
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_hp_flag(
    mhandle         mhdle,     /* IN:  监视器句柄    */
    mbool*          hp_flag    /* OUT: 监视器日志堆积标记 */
);

/*********************************************************************
Purpose:
    根据用户输入的组名和库名，查找真实的组名和库名
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_real_group_db_name(
    mhandle         mhdle,          /* IN：监视器句柄 */
    mschar*         group_name,     /* IN：用户输入的组名，可能为空 */
    mschar*         db_name,        /* IN：用户输入的实例名，可能为空 */
    mschar*         real_grpname,   /* OUT：真实组名 */
    mschar*         real_dbname     /* OUT：真实组名 */
);

#ifdef __cplusplus
}
#endif

#endif

