/********************************************************************
file:
	crypto_engine.h
purpose:
    provide all the function entries that a crypto engine should provide

interface:

History
    Date        Who         RefDoc     Memo
	2007-12-27  NL                     CREATE
*******************************************************/

#ifndef CRYPTO_ENGINE_H
#define CRYPTO_ENGINE_H

#ifndef dm_h

typedef int   lint;

typedef short sint;

typedef signed char tint;

typedef unsigned int ulint;   

typedef unsigned short usint;

typedef unsigned char byte;

#ifdef _WIN64
#define dm_int3264 __int64
#define dm_uint3264 unsigned __int64
#else
#define dm_int3264 long
#define dm_uint3264 unsigned long
#endif

#endif //#ifndef dm_h

#ifdef WIN32
#define DllImport __declspec( dllimport )
#define DllExport __declspec( dllexport )
#else
#define DllImport 
#define DllExport 
#endif

#define  MIN_EXTERNAL_CIPHER_ID         5000
#define  CYT_TYPE_UNKNOWN               0           //类型, 未知算法
#define	 CYT_TYPE_SYM_BLOCK_ENCRYPT     1           //类型, 分组对称加密算法
#define  CYT_TYPE_SYM_STREAM_ENCRYPT    2           //类型, 流式对称加密算法
#define  CYT_TYPE_ASYM_ENCRYPT          3           //类型, 非对称加密算法, 保留
#define  CYT_TYPE_HASH                  4           //类型, 散列算法

#define DM_UKEY_FLAG_NONE                 0      // 不使用UKEY认证
#define DM_UKEY_FLAG_CERT                 1      // UKEY证书认证
#define DM_UKEY_FLAG_ZB                   2      // UKEY口令认证

// 第三方加密引擎类型。0：第三方软加密；1：第三方硬件加密；2：ukey。
#define CRYPTO_TYPE_SOFT    0
#define CRYPTO_TYPE_HARD    1
#define CRYPTO_TYPE_UKEY    2

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define dm_bool long
#else
#define dm_bool unsigned int
#endif

#define DM_FALSE    0
#define DM_TRUE     1

#define CYT_PARA_WORKMODE    0
#define CYT_PARA_EXTENDSIZE  1

#define WORK_MODE_ECB           (ulint)0x1
#define WORK_MODE_CBC           (ulint)0x2
#define WORK_MODE_CFB           (ulint)0x4
#define WORK_MODE_OFB           (ulint)0x8
#define WORK_MODE_CBC_NOPAD     (ulint)0x10
#define WORK_MODE_ECB_NOPAD     (ulint)0x20
#define WORK_MODE_EXTKEY        (ulint)0x40
#define WORK_MODE_STORE         (ulint)0x41     //zb适配存储加密模式, 对原文长度有限制
#define WORK_MODE_TRANS         (ulint)0x42     //zb适配传输加密模式
#define WORK_MODE_KID           (ulint)0x43
#define WORK_MODE_AUTH          (ulint)0x44
#define WORK_MODE_LOG           (ulint)0x45     //zb适配日志加密模式, 对原文长度没有限制

DllExport	
ulint
cipher_get_count(
);

DllExport
dm_bool
cipher_get_info(
    ulint       seqno,
    ulint*      cipher_id,
    byte**      cipher_name,
    byte*       type,
    ulint*      blk_size,
    ulint*      kh_size 
);

DllExport
dm_bool
cipher_get_info_ex(
    ulint       seqno,
    ulint*      cipher_id,
    byte**      cipher_name,
    byte*       type,
    ulint*      blk_size,
    ulint*      kh_size,
    byte*       work_mode 
);

DllExport
dm_bool
cipher_get_para(
    ulint       cipher_id,
    ulint       para_id,
    void*       value
);

DllExport
dm_bool
cipher_get_key_id(
    ulint   cipher_id,
    byte*   key_id,
    ulint   key_id_size,
    ulint*  key_size
);

DllExport
dm_bool
cipher_free_key_id(
    ulint   cipher_id,
    byte*   key_id,
    ulint   key_id_size
);

DllExport
dm_bool
cipher_encrypt_init(
    ulint       inner_id,
    byte*       key,
    ulint       key_size,
    void**      encrypt_para
);

DllExport
lint
cipher_get_cipher_text_size(
    ulint       inner_id,
    void*       cipher_para,
    lint        plain_text_size
);

DllExport
lint
cipher_encrypt(
    ulint       inner_id,
    void*       encrypt_para,
    byte*       plain_text,
    ulint       plain_text_size,
    byte*       cipher_text,
    ulint       cipher_text_buf_size
);

DllExport
dm_bool
cipher_decrypt_init(
    ulint       inner_id,
    byte*       key,
    ulint       key_size,
    void**      decrypt_para
);

DllExport
lint
cipher_decrypt(
   ulint        inner_id,
   void*        decrypt_para,
   byte*        cipher_text,
   ulint        cipher_text_size,
   byte*        plain_text,
   ulint        plain_text_buf_size
);

DllExport
dm_bool
cipher_hash_init(
    ulint       inner_id,
    void**      hash_para
);

DllExport
void
cipher_hash_update(
    ulint       inner_id,
    void*       hash_para,
    byte*       msg,
    ulint       msg_size
);

DllExport
lint
cipher_hash_final(
    ulint       inner_id,
    void*       hash_para,
    byte*       digest,
    ulint       digest_buf_size
);

DllExport
void
cipher_cleanup(
    ulint       inner_id,
    void*       hash_para
);

DllExport
dm_bool
cipher_asym_sign(
    ulint       inner_id,
    byte*       prikey,     //私钥签名
    ulint       prikey_size,
    byte*       data,
    ulint       data_size,
    byte*       signdata,
    ulint*      signdata_buf_size
);

DllExport
dm_bool
cipher_asym_verify(
    ulint       inner_id,
    byte*       pubkey,     //公钥验签
    ulint       pubkey_size,
    byte*       data,
    ulint       data_size,
    byte*       signdata,
    ulint       signdata_size
);

DllExport
dm_bool
crypto_login(
    void**      cipher_para,
    byte*       pin,
    ulint       pin_len
);

DllExport
dm_bool
crypto_logout(
    void*       cipher_para
);

DllExport
dm_bool
crypto_read_cert(
    void*       cipher_para,
    byte*       cert,
    ulint *     cert_len
);

DllExport
dm_bool
cipher_gen_random(
    byte*       random,
    ulint       random_length
);

DllExport
dm_bool
crypto_get_name(
    byte**      crypto_name,
    ulint*      len
);

DllExport
dm_bool
crypto_get_type(
    ulint*      crypto_type
);

DllExport
lint
crypto_encrypt(
    byte*       plain_text,
    ulint       plain_text_size,
    byte*       cipher_text,
    ulint       cipher_text_buf_size
);

DllExport
lint
crypto_decrypt(
    byte*       cipher_text,
    ulint       cipher_text_size,
    byte*       plain_text,
    ulint       plain_text_buf_size
);

/************************************************************************
Purpose:
传输加密, 生成公私密钥对
/************************************************************************/
DllExport
dm_bool
cipher_gen_respective_key(
    void**       pSession,      /* OUT: 会话参数 */
    byte*        pubkey,        /* OUT: 公钥, 上层预分配空间 */
    ulint*       pubkeyLen,     /* OUT: 公钥的字节长度，最大128字节 */
    byte*        prikey,        /* OUT: 私钥, 上层预分配空间 */
    ulint*       prikeyLen      /* OUT: 私钥的字节长度，最大128字节 */
);

/************************************************************************
Purpose:
传输加密, 生成传输加密密钥
/************************************************************************/
DllExport
dm_bool
cipher_gen_common_key(
    void*        pSession,      /* IN: 本次会话参数 */
    byte*        pubkey,        /* IN: 对方公钥 */
    ulint        pubkeyLen,     /* IN: 对方公钥的字节长度，最大128字节 */
    byte*        prikey,        /* IN: 自己私钥 */
    ulint        prikeyLen,     /* IN: 自己私钥的字节长度，最大128字节 */
    byte*        commkey,       /* OUT: 传输密钥, 上层预分配空间 */
    ulint*       commkeyLen     /* OUT: 传输密钥的长度长度，最大128字节 */
);

/************************************************************************
Purpose:
传输加密, 销毁psess(zb适配)
/************************************************************************/
DllExport
dm_bool
cipher_trans_destroy_key(
    void*        pSession   /* IN: 本次会话参数 */
);

/*******************************************
Purpose:
更新数据块加密密钥
Notes:
ZB适配[ZB-des-8]-[ZB-des-12]
/*******************************************/
DllExport
lint
cipher_encrypt_update_init(
    ulint       inner_id,       /* IN: 算法id */
    void**      encrypt_para,   /* OUT: para */
    byte*       key_old,        /* IN: 老key */
    ulint       key_old_size,   /* IN: 老key长度 */
    byte*       key_new,        /* IN: 新key */
    ulint       key_new_size    /* IN: 新key长度 */
);

/****************************************
Purpose:
更新数据块加密密钥
Notes:
ZB适配[ZB-des-8]-[ZB-des-12]
/****************************************/
DllExport
lint
cipher_encrypt_update(
    ulint       inner_id,       /* IN: 算法id */
    void*       encrypt_para,   /* IN: para */
    byte*       orl_data,       /* IN: 原始数据 */
    ulint       orl_data_len,   /* IN: 原始数据长度 */
    byte*       updated_data    /* OUT: 更新后数据(长度不变) */
);

/*****************************************
Purpose:
生成L1
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_gen_key(
    ulint       inner_id,       /* IN: 算法id */
    void**      pSession,       /* IN: 本次会话参数 */
    byte*       pUserL1,        /* OUT: L1, 上层预分配空间 */
    ulint*      pUserL1Len      /* OUT: L1的字节长度，最大128字节 */
);

/*****************************************
Purpose:
销毁pSession
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_destroy_key(
    ulint       inner_id,       /* IN: 算法id */
    void*       pSession        /* IN: 本次会话参数 */
);

/*****************************************
Purpose:
生成L3
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_sign(
    ulint       inner_id,       /* IN: 算法id */
    void*       pSession,       /* IN: 本次会话参数 */
    byte*       UserName,       /* IN: 用户名, 数据库编码后 */
    ulint       UserNameLen,    /* IN: 用户名的字节长度，最大128字节 */
    byte*       pUserPwd,       /* IN: 用户口令*/
    ulint       UserPwdLen,     /* IN: 用户口令的字节长度，最大512字节 */
    byte*       pUserL2,        /* IN: L2 */
    ulint       UserL2Len,      /* IN: L2的字节长度，最大128字节 */
    byte*       pUserL3,        /* OUT: L3, 上层预分配空间 */
    ulint*      pUserL3Len      /* OUT: L3的字节长度，最大4096字节 */
);

/*****************************************
Purpose:
校验L3与U1是否匹配
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_verify(
    ulint       inner_id,       /* IN: 算法id */
    void*       pSession,       /* IN: 本次会话参数 */
    byte*       UserName,       /* IN: 用户名, 数据库编码后*/
    ulint       UserNameLen,    /* IN: 用户名的字节长度，最大128字节 */
    byte*       pUserU1,        /* IN: 用户口令 */
    ulint       UserU1Len,      /* IN: 用户口令的字节长度，最大512字节 */
    byte*       pUserL1,        /* IN: L1 */
    ulint       UserL1Len,      /* IN: L1的字节长度，最大128字节 */
    byte*       pUserL3,        /* IN: L3 */
    ulint       UserL3Len       /* IN: L3的字节长度，最大4096字节 */
);

/*****************************************
Purpose:
生成msg的校验信息L4
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_gen_digest(
    ulint       inner_id,       /* IN: 算法id */
    void*       pSession,       /* IN: 本次会话参数 */
    byte*       msg,            /* IN: 消息 */
    ulint       msgLen,         /* IN: 消息的字节长度*/
    byte*       pUserL4,        /* OUT: L4, 上层预分配空间*/
    ulint*      pUserL4Len      /* OUT: L4的字节长度，最大256字节 */
);

/*****************************************
Purpose:
校验msg和L4是否匹配
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_check_digest(
    ulint       inner_id,       /* IN: 算法id */
    void*       pSession,       /* IN: 本次会话参数 */
    byte*       pUserL4,        /* IN: L4 */
    ulint       UserL4Len,      /* IN: L4的字节长度，最大256字节 */
    byte*       msg,            /* IN: 消息 */
    ulint       msgLen          /* IN: 消息的字节长度*/
);

/*****************************************
Purpose:
客户端修改用户口令，生成L5
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_update(
    ulint       inner_id,       /* IN: 算法id */
    void*       pSession,       /* IN: 本次会话参数 */
    byte*       pUserPwd,       /* IN: 用户老口令 */
    ulint       UserPwdLen,     /* IN: 老口令的字节长度，最大512字节 */
    byte*       pUserPwdNew,    /* IN: 用户新口令*/
    ulint       UserPwdNewLen,  /* IN: 新口令的字节长度，最大512字节 */
    byte*       pUserL5,        /* OUT: L5, 上层预分配空间*/
    ulint*      pUserL5Len      /* OUT: L5的字节长度，最大256字节 */
);

/*****************************************
Purpose:
服务端修改用户口令，使用L5生成新U1
Notes:
ZB适配[ZB-des-4]登录认证
/*****************************************/
DllExport
dm_bool
cipher_user_auth_final(
    ulint       inner_id,       /* IN: 算法id */
    void*       pSession,       /* IN: 本次会话参数 */
    byte*       UserName,       /* IN: 用户名, 数据库编码后*/
    ulint       UserNameLen,    /* IN: 用户名的字节长度，最大128字节*/
    byte*       pUserL5,        /* IN: L5 */
    ulint       UserL5Len,      /* IN: L5的字节长度，最大256字节 */
    byte*       pUserU1,        /* OUT: U1, 上层预分配空间 */
    ulint*      pUserU1Len      /* OUT: U1的字节长度，最大256字节 */
);

/************************************************************************
Purpose:
获取引擎用户认证类型
Notes:
(1)ZB适配[ZB-des-4]登录认证
(2)
DM_UKEY_FLAG_NONE                 0      // 不使用UKEY认证
DM_UKEY_FLAG_CERT                 1      // UKEY证书认证
DM_UKEY_FLAG_ZB                   2      // UKEY口令认证
/************************************************************************/
DllExport
lint
cipher_get_auth_type(
);

#ifdef __cplusplus
}
#endif

#endif
