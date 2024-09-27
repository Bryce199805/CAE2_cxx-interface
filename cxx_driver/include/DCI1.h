/**********************************************************
file: 
    DCI1.h
Notes:
    DCI Interface public definitions
Legal Notices£º
Legal Notices:
Dameng Database
Copyright(C) 2000-2022 DM and/or its affiliates. All rights reserved.
http://www.dameng.com
*******************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _DCI1_H
#define _DCI1_H

#include <limits.h>
#include <sys/types.h>

#define SQLT_CHR                        1               /* (ORANET TYPE) character string */
#define SQLT_NUM                        2               /* (ORANET TYPE) oracle numeric */
#define SQLT_INT                        3               /* (ORANET TYPE) integer */
#define SQLT_FLT                        4               /* (ORANET TYPE) Floating point number */
#define SQLT_STR                        5               /* zero terminated string */
#define SQLT_VNU                        6               /* NUM with preceding length byte */
#define SQLT_PDN                        7               /* (ORANET TYPE) Packed Decimal Numeric */
#define SQLT_LNG                        8               /* long */
#define SQLT_VCS                        9               /* Variable character string */
#define SQLT_NON                        10              /* Null/empty PCC Descriptor entry */
#define SQLT_RID                        11              /* rowid */
#define SQLT_DAT                        12              /* date in oracle format */
#define SQLT_VBI                        15              /* binary in VCS format */
#define SQLT_BFLOAT                     21              /* Native Binary float*/
#define SQLT_BDOUBLE                    22              /* NAtive binary double */
#define SQLT_BIN                        23              /* binary data(DTYBIN) */
#define SQLT_LBI                        24              /* long binary */
#define SQLT_UIN                        68              /* unsigned integer */
#define SQLT_SLS                        91              /* Display sign leading separate */
#define SQLT_LVC                        94              /* Longer longs (char) */
#define SQLT_LVB                        95              /* Longer long binary */ 
#define SQLT_AFC                        96              /* Ansi fixed char */
#define SQLT_AVC                        97              /* Ansi Var char */
#define SQLT_IBFLOAT                    100             /* binary float canonical */
#define SQLT_IBDOUBLE                   101             /* binary double canonical */
#define SQLT_CUR                        102             /* cursor  type */
#define SQLT_RDD                        104             /* rowid descriptor */
#define SQLT_LAB                        105             /* label type */
#define SQLT_OSL                        106             /* oslabel type */
#define SQLT_NTY                        108             /* named object type */
#define SQLT_REF                        110             /* ref type */
#define SQLT_CLOB                       112             /* character lob */
#define SQLT_BLOB                       113             /* binary lob */
#define SQLT_BFILEE                     114             /* binary file lob */
#define SQLT_CFILEE                     115             /* character file lob */
#define SQLT_RSET                       116             /* result set type */
#define SQLT_NCO                        122             /* named collection type (varray or nested table) */
#define SQLT_VST                        155             /* OCIString type */
#define SQLT_ODT                        156             /* OCIDate type */
#define SQLT_DATE                       184             /* ANSI Date */
#define SQLT_TIME                       185             /* TIME */
#define SQLT_TIME_TZ                    186             /* TIME WITH TIME ZONE */
#define SQLT_TIMESTAMP                  187             /* TIMESTAMP */
#define SQLT_TIMESTAMP_TZ               188             /* TIMESTAMP WITH TIME ZONE */
#define SQLT_INTERVAL_YM                189             /* INTERVAL YEAR TO MONTH */
#define SQLT_INTERVAL_DS                190             /* INTERVAL DAY TO SECOND */
#define SQLT_TIMESTAMP_LTZ              232             /* TIMESTAMP WITH LOCAL TZ */
#define SQLT_PNTY                       241             /* pl/sql representation of named types */
#define SQLT_FILE                       SQLT_BFILEE     /* binary file lob */
#define SQLT_CFILE                      SQLT_CFILEE
#define SQLT_BFILE                      SQLT_BFILEE
#define SQLT_BOL                        252             /* pl/sql 'boolean' */


#define DCI_TYPECODE_REF                SQLT_REF            /* SQL/OTS OBJECT REFERENCE */
#define DCI_TYPECODE_DATE               SQLT_DAT            /* SQL DATE  OTS DATE */
#define DCI_TYPECODE_SIGNED8            27                  /* SQL SIGNED INTEGER(8)  OTS SINT8 */
#define DCI_TYPECODE_SIGNED16           28                  /* SQL SIGNED INTEGER(16)  OTS SINT16 */
#define DCI_TYPECODE_SIGNED32           29                  /* SQL SIGNED INTEGER(32)  OTS SINT32 */
#define DCI_TYPECODE_REAL               21                  /* SQL REAL  OTS SQL_REAL */
#define DCI_TYPECODE_DOUBLE             22                  /* SQL DOUBLE PRECISION  OTS SQL_DOUBLE */
#define DCI_TYPECODE_FLOAT              SQLT_FLT            /* SQL FLOAT(P)  OTS FLOAT(P) */
#define DCI_TYPECODE_NUMBER             SQLT_NUM            /* SQL NUMBER(P S)  OTS NUMBER(P S) */
#define DCI_TYPECODE_DECIMAL            SQLT_PDN            /* SQL DECIMAL(P S)  OTS DECIMAL(P S) */
#define DCI_TYPECODE_UNSIGNED8          SQLT_BIN            /* SQL UNSIGNED INTEGER(8)  OTS UINT8 */
#define DCI_TYPECODE_UNSIGNED16         25                  /* SQL UNSIGNED INTEGER(16)  OTS UINT16 */
#define DCI_TYPECODE_UNSIGNED32         26                  /* SQL UNSIGNED INTEGER(32)  OTS UINT32 */
#define DCI_TYPECODE_BFLOAT             SQLT_IBFLOAT        /* Binary float */
#define DCI_TYPECODE_BDOUBLE            SQLT_IBDOUBLE       /* Binary double */
#define DCI_TYPECODE_OCTET              245                 /* SQL ???  OTS OCTET */
#define DCI_TYPECODE_SMALLINT           246                 /* SQL SMALLINT  OTS SMALLINT */
#define DCI_TYPECODE_INTEGER            SQLT_INT            /* SQL INTEGER  OTS INTEGER */
#define DCI_TYPECODE_RAW                SQLT_LVB            /* SQL RAW(N)  OTS RAW(N) */
#define DCI_TYPECODE_PTR                32                  /* SQL POINTER  OTS POINTER */
#define DCI_TYPECODE_VARCHAR2           SQLT_VCS            /* SQL VARCHAR2(N)  OTS SQL_VARCHAR2(N) */
#define DCI_TYPECODE_CHAR               SQLT_AFC            /* SQL CHAR(N)  OTS SQL_CHAR(N) */
#define DCI_TYPECODE_VARCHAR            SQLT_CHR            /* SQL VARCHAR(N)  OTS SQL_VARCHAR(N) */
#define DCI_TYPECODE_MLSLABEL           SQLT_LAB            /* OTS MLSLABEL */
#define DCI_TYPECODE_VARRAY             247                 /* SQL VARRAY  OTS PAGED VARRAY */
#define DCI_TYPECODE_TABLE              248                 /* SQL TABLE  OTS MULTISET */
#define DCI_TYPECODE_OBJECT             SQLT_NTY            /* SQL/OTS NAMED OBJECT TYPE */
#define DCI_TYPECODE_OPAQUE             58                  /* SQL/OTS Opaque Types */
#define DCI_TYPECODE_NAMEDCOLLECTION    SQLT_NCO            /* SQL/OTS NAMED COLLECTION TYPE */
#define DCI_TYPECODE_BLOB               SQLT_BLOB           /* SQL/OTS BINARY LARGE OBJECT */
#define DCI_TYPECODE_BFILE              SQLT_BFILE          /* SQL/OTS BINARY FILE OBJECT */
#define DCI_TYPECODE_CLOB               SQLT_CLOB           /* SQL/OTS CHARACTER LARGE OBJECT */
#define DCI_TYPECODE_CFILE              SQLT_CFILE          /* SQL/OTS CHARACTER FILE OBJECT */
#define DCI_TYPECODE_TIME               SQLT_TIME           /* SQL/OTS TIME */
#define DCI_TYPECODE_TIME_TZ            SQLT_TIME_TZ        /* SQL/OTS TIME_TZ */
#define DCI_TYPECODE_TIMESTAMP          SQLT_TIMESTAMP      /* SQL/OTS TIMESTAMP */
#define DCI_TYPECODE_TIMESTAMP_TZ       SQLT_TIMESTAMP_TZ   /* SQL/OTS TIMESTAMP_TZ */
#define DCI_TYPECODE_TIMESTAMP_LTZ      SQLT_TIMESTAMP_LTZ  /* TIMESTAMP_LTZ */
#define DCI_TYPECODE_INTERVAL_YM        SQLT_INTERVAL_YM    /* SQL/OTS INTRVL YR-MON */
#define DCI_TYPECODE_INTERVAL_DS        SQLT_INTERVAL_DS    /* SQL/OTS INTRVL DAY-SEC */
#define DCI_TYPECODE_OTMFIRST           228                 /* first Open Type Manager typecode */
#define DCI_TYPECODE_OTMLAST            320                 /* last OTM typecode */
#define DCI_TYPECODE_SYSFIRST           228                 /* first OTM system type (internal) */
#define DCI_TYPECODE_SYSLAST            235                 /* last OTM system type (internal) */
#define DCI_TYPECODE_PLS_INTEGER        266                 /* type code for PLS_INTEGER */
/* NOTE : The following NCHAR related codes are just short forms for saying
   OCI_TYPECODE_VARCHAR2 with a charset form of SQLCS_NCHAR. These codes are
   intended for use in the OCIAnyData API only and nowhere else. */
#define DCI_TYPECODE_NCHAR              286
#define DCI_TYPECODE_NVARCHAR2          287
#define DCI_TYPECODE_NCLOB              288


#ifndef TRUE
#define TRUE        1
#define FALSE       0
#endif

#ifndef lint
typedef unsigned char   dub1;
typedef signed char     dsb1;
#else
#define dub1            unsigned char
#define dsb1            signed char
#endif

#define UB1MAXVAL       ((dub1)UCHAR_MAX)
#define UB1MINVAL       ((dub1)        0)
#define SB1MAXVAL       ((dsb1)SCHAR_MAX)
#define SB1MINVAL       ((dsb1)SCHAR_MIN)
#define MINUB1MAXVAL    ((dub1)  255)
#define MAXUB1MINVAL    ((dub1)    0)
#define MINSB1MAXVAL    ((dsb1)  127)
#define MAXSB1MINVAL    ((dsb1) -127)

#ifndef lint
typedef unsigned short  dub2;
typedef signed short    dsb2;
#else
#define dub2            unsigned short
#define dsb2            signed short
#endif

#define UB2MAXVAL       ((dub2)USHRT_MAX)
#define UB2MINVAL       ((dub2)        0)
#define SB2MAXVAL       ((dsb2) SHRT_MAX)
#define SB2MINVAL       ((dsb2) SHRT_MIN)
#define MINUB2MAXVAL    ((dub2) 65535)
#define MAXUB2MINVAL    ((dub2)     0)
#define MINSB2MAXVAL    ((dsb2) 32767)
#define MAXSB2MINVAL    ((dsb2)-32767)

#ifndef lint
typedef unsigned int    dub4;
typedef signed int      dsb4;
#else
#define dub4            unsigned int
#define dsb4            signed int
#endif 

#ifndef INT_MAX
#define INT_MIN         (-2147483647 - 1)   /* minimum (signed) int value */
#define INT_MAX         2147483647          /* maximum (signed) int value */
#endif

#define UB4MAXVAL       ((dub4)UINT_MAX)
#define UB4MINVAL       ((dub4)        0)
#define SB4MAXVAL       ((dsb4) INT_MAX)
#define SB4MINVAL       ((dsb4) INT_MIN)
#define MINUB4MAXVAL    ((dub4) 4294967295)
#define MAXUB4MINVAL    ((dub4)          0)
#define MINSB4MAXVAL    ((dsb4) 2147483647)
#define MAXSB4MINVAL    ((dsb4)-2147483647)

#define ORAUB8MINVAL    ((dmub8)0)
#define ORAUB8MAXVAL    ((dmub8)18446744073709551615)
#define ORASB8MINVAL    ((dmsb8)-9223372036854775808)
#define ORASB8MAXVAL    ((dmsb8) 9223372036854775807)

#define MAXORAUB8MINVAL ((dmub8)0)
#define MINORAUB8MAXVAL ((dmub8)18446744073709551615)
#define MAXORASB8MINVAL ((dmsb8)-9223372036854775807)
#define MINORASB8MAXVAL ((dmsb8) 9223372036854775807)

#define UB1BITS          CHAR_BIT
#define UB1MASK          ((1 << ((duword)CHAR_BIT)) - 1)

#ifndef lint
typedef unsigned char   dmtext;
#else
#define dmtext          unsigned char
#endif

#ifndef lint 
typedef char            deb1;
typedef short           deb2;
typedef int             deb4;
#else
#define deb1            char
#define deb2            short
#define deb4            int
#endif

#define EB1MAXVAL      ((deb1)SCHAR_MAX)
#define EB1MINVAL      ((deb1)        0)
#define MINEB1MAXVAL   ((deb1)  127)
#define MAXEB1MINVAL   ((deb1)    0)
#define EB2MAXVAL      ((deb2) SHRT_MAX)
#define EB2MINVAL      ((deb2)        0)
#define MINEB2MAXVAL   ((deb2) 32767)
#define MAXEB2MINVAL   ((deb2)     0)
#define EB4MAXVAL      ((deb4) INT_MAX)
#define EB4MINVAL      ((deb4)        0)
#define MINEB4MAXVAL   ((deb4) 2147483647)
#define MAXEB4MINVAL   ((deb4)          0)

#ifndef lint
typedef dsb1            db1;
#else
#define db1             dsb1
#endif
#define B1MAXVAL        SB1MAXVAL
#define B1MINVAL        SB1MINVAL

#ifndef lint
typedef dsb2            db2;
#else
#define db2             dsb2
#endif
#define B2MAXVAL        SB2MAXVAL
#define B2MINVAL        SB2MINVAL

#ifndef lint
typedef dsb4            db4;
#else 
#define db4             dsb4
#endif
#define B4MAXVAL        SB4MAXVAL
#define B4MINVAL        SB4MINVAL


#if !defined(LUSEMFC)
#ifdef lint
#define dtext           unsigned char
#else
typedef dmtext          dtext;
# endif
#endif

#ifdef lint
#define DmText          unsigned char
#else
typedef dmtext          DmText;
#endif

#ifndef lint
typedef int             deword;
typedef unsigned int    duword;
typedef signed int      dsword;
#else
#define deword          int
#define duword          unsigned int
#define dsword          signed int
#endif

#define EWORDMAXVAL     ((deword) INT_MAX)
#define EWORDMINVAL     ((deword)       0)
#define UWORDMAXVAL     ((duword)UINT_MAX)
#define UWORDMINVAL     ((duword)       0)
#define SWORDMAXVAL     ((dsword) INT_MAX)
#define SWORDMINVAL     ((dsword) INT_MIN)
#define MINEWORDMAXVAL  ((deword)  2147483647)
#define MAXEWORDMINVAL  ((deword)      0)
#define MINUWORDMAXVAL  ((duword)  4294967295)
#define MAXUWORDMINVAL  ((duword)           0)
#define MINSWORDMAXVAL  ((dsword)  2147483647)
#define MAXSWORDMINVAL  ((dsword) -2147483647)

#ifdef _WIN64

#ifndef lint
typedef unsigned _int64 dubig_ora;
typedef   signed _int64 dsbig_ora;
#else
#define dubig_ora       unsigned _int64
#define dsbig_ora       signed _int64
#endif

#define UBIG_ORAMAXVAL  ((dubig_ora)_UI64_MAX)
#define UBIG_ORAMINVAL  ((dubig_ora)        0)
#define SBIG_ORAMAXVAL  ((dsbig_ora) _I64_MAX)
#define SBIG_ORAMINVAL  ((dsbig_ora) _I64_MIN)
#define MINUBIG_ORAMAXVAL ((dubig_ora) 4294967295)
#define MAXUBIG_ORAMINVAL ((dubig_ora)          0)
#define MINSBIG_ORAMAXVAL ((dsbig_ora) 2147483647)
#define MAXSBIG_ORAMINVAL ((dsbig_ora)-2147483647)

#else

#ifndef lint
typedef unsigned long   dubig_ora;
typedef   signed long   dsbig_ora;
#else
#define dubig_ora       unsigned long
#define dsbig_ora       signed long
#endif

#define UBIG_ORAMAXVAL      ((dubig_ora)ULONG_MAX)
#define UBIG_ORAMINVAL      ((dubig_ora)        0)
#define SBIG_ORAMAXVAL      ((dsbig_ora) LONG_MAX)
#define SBIG_ORAMINVAL      ((dsbig_ora) LONG_MIN)
#define MINUBIG_ORAMAXVAL   ((dubig_ora) 4294967295)
#define MAXUBIG_ORAMINVAL   ((dubig_ora)          0)
#define MINSBIG_ORAMAXVAL   ((dsbig_ora) 2147483647)
#define MAXSBIG_ORAMINVAL   ((dsbig_ora)-2147483647)

#endif                                                             /* _WIN64 */

/* --- Signed/Unsigned eight-byte scalar (orasb8/oraub8) --- */

#define ORAXB8_DEFINED
#ifndef lint
#ifndef __GNUC__
#ifdef __BORLANDC__
typedef unsigned __int64    dmub8;
typedef signed __int64      dmsb8;
#else
typedef unsigned _int64     dmub8;
typedef signed _int64       dmsb8;
#endif /* __BORLANDC__ */
#else
typedef unsigned long long  dmub8;
typedef signed long long    dmsb8;
#endif /*__GNUC__*/
typedef dmub8               dub8;
typedef dmsb8               dsb8;
#else
#ifndef __GNUC__
#ifdef __BORLANDC__
#define dmub8               unsigned __int64 
#define dmsb8               signed __int64 
#else
#define dmub8               unsigned _int64 
#define dmsb8               signed _int64 
#endif 
#else
#define dmub8               unsigned long long
#define dmsb8               signed long long
#endif
# define dub8               dmub8
# define dsb8               dmsb8

#endif /* !lint */

#define UBIGORABITS      (UB1BITS * sizeof(dubig_ora))

#undef CONST
#define CONST const

#define dvoid void

typedef void (*dlgenfp_t)( void );

#ifndef boolean
#define boolean         int
#endif

#ifdef sparc
#define SIZE_TMAXVAL    SB4MAXVAL
#else
#define SIZE_TMAXVAL    UB4MAXVAL
#endif

#define MINSIZE_TMAXVAL (size_t)4294967295

#if !defined(MOTIF) && !defined(LISPL) && !defined(__cplusplus) && !defined(LUSEMFC)
typedef  dtext          *dstring;
#endif

#ifndef lint
typedef unsigned short  dutext;
#else
#define dutext          unsigned short
#endif

#define DCI_NUMBER_UNSIGNED     0                           /* Unsigned type -- ubX */
#define DCI_NUMBER_SIGNED       2                           /* Signed type -- sbX */

/* CHAR/NCHAR/VARCHAR2/NVARCHAR2/CLOB/NCLOB char set "form" information */
#define SQLCS_IMPLICIT                  1               /* for CHAR, VARCHAR2, CLOB w/o a specified set */
#define SQLCS_NCHAR                     2               /* for NCHAR, NCHAR VARYING, NCLOB */
#define SQLCS_EXPLICIT                  3               /* for CHAR, etc, with "CHARACTER SET ..." syntax */
#define SQLCS_FLEXIBLE                  4               /* for PL/SQL "flexible" parameters */
#define SQLCS_LIT_NULL                  5               /* for typecheck of NULL and empty_clob() lits */

/*--------------------------------------------------------------------------- 
                     PUBLIC TYPES AND CONSTANTS 
  ---------------------------------------------------------------------------*/

/*-----------------------------Handle Types----------------------------------*/
/* handle types range from 1 - 49 */
#define DCI_HTYPE_FIRST                 1                       /* start value of handle type */
#define DCI_HTYPE_ENV                   1                       /* environment handle */
#define DCI_HTYPE_ERROR                 2                       /* error handle */
#define DCI_HTYPE_SVCCTX                3                       /* service handle */
#define DCI_HTYPE_STMT                  4                       /* statement handle */
#define DCI_HTYPE_BIND                  5                       /* bind handle */
#define DCI_HTYPE_DEFINE                6                       /* define handle */
#define DCI_HTYPE_DESCRIBE              7                       /* describe handle */
#define DCI_HTYPE_SERVER                8                       /* server handle */
#define DCI_HTYPE_SESSION               9                       /* authentication handle */
#define DCI_HTYPE_AUTHINFO              DCI_HTYPE_SESSION       /* SessionGet auth handle */
#define DCI_HTYPE_TRANS                 10                      /* transaction handle */
#define DCI_HTYPE_COMPLEXOBJECT         11                      /* complex object retrieval handle */
#define DCI_HTYPE_SECURITY              12                      /* security handle */
#define DCI_HTYPE_SUBSCRIPTION          13                      /* subscription handle */
#define DCI_HTYPE_DIRPATH_CTX           14                      /* direct path context */
#define DCI_HTYPE_DIRPATH_COLUMN_ARRAY  15                      /* direct path column array */
#define DCI_HTYPE_DIRPATH_STREAM        16                      /* direct path stream */
#define DCI_HTYPE_PROC                  17                      /* process handle */
#define DCI_HTYPE_DIRPATH_FN_CTX        18                      /* direct path function context */
#define DCI_HTYPE_DIRPATH_FN_COL_ARRAY  19                      /* dp object column array */
#define DCI_HTYPE_XADSESSION            20                      /* access driver session */
#define DCI_HTYPE_XADTABLE              21                      /* access driver table */
#define DCI_HTYPE_XADFIELD              22                      /* access driver field */
#define DCI_HTYPE_XADGRANULE            23                      /* access driver granule */
#define DCI_HTYPE_XADRECORD             24                      /* access driver record */
#define DCI_HTYPE_XADIO                 25                      /* access driver I/O */
#define DCI_HTYPE_CPOOL                 26                      /* connection pool handle */
#define DCI_HTYPE_SPOOL                 27                      /* session pool handle */
#define DCI_HTYPE_ADMIN                 28                      /*administration handle*/
#define DCI_HTYPE_LAST                  28                      /* last value of a handle type */
/*---------------------------------------------------------------------------*/


/*-------------------------Descriptor Types----------------------------------*/
/* descriptor values range from 50 - 255 */
#define DCI_DTYPE_FIRST                 50                      /* start value of descriptor type */
#define DCI_DTYPE_LOB                   50                      /* lob  locator */
#define DCI_DTYPE_SNAP                  51                      /* snapshot descriptor */
#define DCI_DTYPE_RSET                  52                      /* result set descriptor */
#define DCI_DTYPE_PARAM                 53                      /* a parameter descriptor obtained from ocigparm */
#define DCI_DTYPE_ROWID                 54                      /* rowid descriptor */
#define DCI_DTYPE_COMPLEXOBJECTCOMP     55                      /* complex object retrieval descriptor */
#define DCI_DTYPE_FILE                  56                      /* File Lob locator */
#define DCI_DTYPE_AQENQ_OPTIONS         57                      /* enqueue options */
#define DCI_DTYPE_AQDEQ_OPTIONS         58                      /* dequeue options */
#define DCI_DTYPE_AQMSG_PROPERTIES      59                      /* message properties */
#define DCI_DTYPE_AQAGENT               60                      /* aq agent */
#define DCI_DTYPE_LOCATOR               61                      /* LOB locator */
#define DCI_DTYPE_INTERVAL_YM           62                      /* Interval year month */
#define DCI_DTYPE_INTERVAL_DS           63                      /* Interval day second */
#define DCI_DTYPE_AQNFY_DESCRIPTOR      64                      /* AQ notify descriptor */
#define DCI_DTYPE_DATE                  65                      /* Date */
#define DCI_DTYPE_TIME                  66                      /* Time */
#define DCI_DTYPE_TIME_TZ               67                      /* Time with timezone */
#define DCI_DTYPE_TIMESTAMP             68                      /* Timestamp */
#define DCI_DTYPE_TIMESTAMP_TZ          69                      /* Timestamp with timezone */
#define DCI_DTYPE_TIMESTAMP_LTZ         70                      /* Timestamp with local tz */
#define DCI_DTYPE_UCB                   71                      /* user callback descriptor */
#define DCI_DTYPE_SRVDN                 72                      /* server DN list descriptor */
#define DCI_DTYPE_SIGNATURE             73                      /* signature */
#define DCI_DTYPE_RESERVED_1            74                      /* reserved for internal use */
#define DCI_DTYPE_LAST                  74                      /* last value of a descriptor type */
/*---------------------------------------------------------------------------*/

/*--------------------------------LOB types ---------------------------------*/
#define DCI_TEMP_BLOB                   1                       /* LOB type - BLOB ------------------ */
#define DCI_TEMP_CLOB                   2                       /* LOB type - CLOB ------------------ */

/*---------------------------------------------------------------------------*/

/*-------------------------Object Ptr Types----------------------------------*/
#define DCI_OTYPE_NAME                  1                       /* object name */
#define DCI_OTYPE_REF                   2                       /* REF to TDO */
#define DCI_OTYPE_PTR                   3                       /* PTR to TDO */
/*---------------------------------------------------------------------------*/

/*=============================Attribute Types===============================*/
/* 
   Note: All attributes are global.  New attibutes should be added to the end
   of the list. Before you add an attribute see if an existing one can be 
   used for your handle. 

   If you see any holes please use the holes first. 
 
*/
/*===========================================================================*/

#define DCI_ATTR_FNCODE                     1                           /* the OCI function code */
#define DCI_ATTR_OBJECT                     2                           /* is the environment initialized in object mode */
#define DCI_ATTR_NONBLOCKING_MODE           3                           /* non blocking mode */
#define DCI_ATTR_SQLCODE                    4                           /* the SQL verb */
#define DCI_ATTR_ENV                        5                           /* the environment handle */
#define DCI_ATTR_SERVER                     6                           /* the server handle */
#define DCI_ATTR_SESSION                    7                           /* the user session handle */
#define DCI_ATTR_TRANS                      8                           /* the transaction handle */
#define DCI_ATTR_ROW_COUNT                  9                           /* the rows processed so far */
#define DCI_ATTR_SQLFNCODE                  10                          /* the SQL verb of the statement */
#define DCI_ATTR_PREFETCH_ROWS              11                          /* sets the number of rows to prefetch */
#define DCI_ATTR_NESTED_PREFETCH_ROWS       12                          /* the prefetch rows of nested table*/
#define DCI_ATTR_PREFETCH_MEMORY            13                          /* memory limit for rows fetched */
#define DCI_ATTR_NESTED_PREFETCH_MEMORY     14                          /* memory limit for nested rows */
#define DCI_ATTR_CHAR_COUNT                 15                          /* this specifies the bind and define size in characters */
#define DCI_ATTR_PDSCL                      16                          /* packed decimal scale */
#define DCI_ATTR_FSPRECISION                DCI_ATTR_PDSCL              /* fs prec for datetime data types */
#define DCI_ATTR_PDPRC                      17                          /* packed decimal format */
#define DCI_ATTR_LFPRECISION                DCI_ATTR_PDPRC              /* fs prec for datetime data types */
#define DCI_ATTR_PARAM_COUNT                18                          /* number of column in the select list */
#define DCI_ATTR_ROWID                      19                          /* the rowid */
#define DCI_ATTR_CHARSET                    20                          /* the character set value */
#define DCI_ATTR_NCHAR                      21                          /* NCHAR type */
#define DCI_ATTR_USERNAME                   22                          /* username attribute */
#define DCI_ATTR_PASSWORD                   23                          /* password attribute */
#define DCI_ATTR_STMT_TYPE                  24                          /* statement type */
#define DCI_ATTR_INTERNAL_NAME              25                          /* user friendly global name */
#define DCI_ATTR_EXTERNAL_NAME              26                          /* the internal name for global txn */
#define DCI_ATTR_XID                        27                          /* XOPEN defined global transaction id */
#define DCI_ATTR_TRANS_LOCK                 28                          /* */
#define DCI_ATTR_TRANS_NAME                 29                          /* string to identify a global transaction */
#define DCI_ATTR_HEAPALLOC                  30                          /* memory allocated on the heap */
#define DCI_ATTR_CHARSET_ID                 31                          /* Character Set ID */
#define DCI_ATTR_CHARSET_FORM               32                          /* Character Set Form */
#define DCI_ATTR_MAXDATA_SIZE               33                          /* Maximumsize of data on the server  */
#define DCI_ATTR_CACHE_OPT_SIZE             34                          /* object cache optimal size */
#define DCI_ATTR_CACHE_MAX_SIZE             35                          /* object cache maximum size percentage */
#define DCI_ATTR_PINOPTION                  36                          /* object cache default pin option */
#define DCI_ATTR_ALLOC_DURATION             37                          /* object cache default allocation duration */
#define DCI_ATTR_PIN_DURATION               38                          /* object cache default pin duration */
#define DCI_ATTR_FDO                        39                          /* Format Descriptor object attribute */
#define DCI_ATTR_POSTPROCESSING_CALLBACK    40                          /* Callback to process outbind data */
#define DCI_ATTR_POSTPROCESSING_CONTEXT     41                          /* Callback context to process outbind data */
#define DCI_ATTR_ROWS_RETURNED              42                          /* Number of rows returned in current iter - for Bind handles */
#define DCI_ATTR_FOCBK                      43                          /* Failover Callback attribute */
#define DCI_ATTR_IN_V8_MODE                 44                          /* is the server/service context in V8 mode */
#define DCI_ATTR_LOBEMPTY                   45                          /* empty lob ? */
#define DCI_ATTR_SESSLANG                   46                          /* session language handle */
#define DCI_ATTR_VISIBILITY                 47                          /* visibility */
#define DCI_ATTR_RELATIVE_MSGID             48                          /* relative message id */
#define DCI_ATTR_SEQUENCE_DEVIATION         49                          /* sequence deviation */
#define DCI_ATTR_CONSUMER_NAME              50                          /* consumer name */
#define DCI_ATTR_DEQ_MODE                   51                          /* dequeue mode */
#define DCI_ATTR_NAVIGATION                 52                          /* navigation */
#define DCI_ATTR_WAIT                       53                          /* wait */
#define DCI_ATTR_DEQ_MSGID                  54                          /* dequeue message id */
#define DCI_ATTR_PRIORITY                   55                          /* priority */
#define DCI_ATTR_DELAY                      56                          /* delay */
#define DCI_ATTR_EXPIRATION                 57                          /* expiration */
#define DCI_ATTR_CORRELATION                58                          /* correlation id */
#define DCI_ATTR_ATTEMPTS                   59                          /* # of attempts */
#define DCI_ATTR_RECIPIENT_LIST             60                          /* recipient list */
#define DCI_ATTR_EXCEPTION_QUEUE            61                          /* exception queue name */
#define DCI_ATTR_ENQ_TIME                   62                          /* enqueue time (only OCIAttrGet) */
#define DCI_ATTR_MSG_STATE                  63                          /* message state (only OCIAttrGet) */
#define DCI_ATTR_AGENT_NAME                 64                          /* agent name */
#define DCI_ATTR_AGENT_ADDRESS              65                          /* agent address */
#define DCI_ATTR_AGENT_PROTOCOL             66                          /* agent protocol */
#define DCI_ATTR_USER_PROPERTY              67                          /* user property */
#define DCI_ATTR_SENDER_ID                  68                          /* sender id */
#define DCI_ATTR_ORIGINAL_MSGID             69                          /* original message id */
#define DCI_ATTR_QUEUE_NAME                 70                          /* queue name */
#define DCI_ATTR_NFY_MSGID                  71                          /* message id */
#define DCI_ATTR_MSG_PROP                   72                          /* message properties */
#define DCI_ATTR_NUM_DML_ERRORS             73                          /* num of errs in array DML */
#define DCI_ATTR_DML_ROW_OFFSET             74                          /* row offset in the array */
#define DCI_ATTR_AQ_NUM_ERRORS              DCI_ATTR_NUM_DML_ERRORS
#define DCI_ATTR_AQ_ERROR_INDEX             DCI_ATTR_DML_ROW_OFFSET
#define DCI_ATTR_DATEFORMAT                 75                          /* default date format string */
#define DCI_ATTR_BUF_ADDR                   76                          /* buffer address */
#define DCI_ATTR_BUF_SIZE                   77                          /* buffer size */
#define DCI_ATTR_DIRPATH_MODE               78                          /* mode of direct path operation */
#define DCI_ATTR_DIRPATH_NOLOG              79                          /* nologging option */
#define DCI_ATTR_DIRPATH_PARALLEL           80                          /* parallel (temp seg) option */
#define DCI_ATTR_NUM_ROWS                   81                          /* number of rows in column array NOTE that OCI_ATTR_NUM_COLS is a column array attribute too*/
#define DCI_ATTR_COL_COUNT                  82                          /* columns of column array processed so far.       */
#define DCI_ATTR_STREAM_OFFSET              83                          /* str off of last row processed */
#define DCI_ATTR_SHARED_HEAPALLOC           84                          /* Shared Heap Allocation Size */
#define DCI_ATTR_SERVER_GROUP               85                          /* server group name */
#define DCI_ATTR_MIGSESSION                 86                          /* migratable session attribute */
#define DCI_ATTR_NOCACHE                    87                          /* Temporary LOBs */
#define DCI_ATTR_MEMPOOL_SIZE               88                          /* Pool Size */
#define DCI_ATTR_MEMPOOL_INSTNAME           89                          /* Instance name */
#define DCI_ATTR_MEMPOOL_APPNAME            90                          /* Application name */
#define DCI_ATTR_MEMPOOL_HOMENAME           91                          /* Home Directory name */
#define DCI_ATTR_MEMPOOL_MODEL              92                          /* Pool Model (proc,thrd,both)*/
#define DCI_ATTR_MODES                      93                          /* Modes */
#define DCI_ATTR_SUBSCR_NAME                94                          /* name of subscription */
#define DCI_ATTR_SUBSCR_CALLBACK            95                          /* associated callback */
#define DCI_ATTR_SUBSCR_CTX                 96                          /* associated callback context */
#define DCI_ATTR_SUBSCR_PAYLOAD             97                          /* associated payload */
#define DCI_ATTR_SUBSCR_NAMESPACE           98                          /* associated namespace */
#define DCI_ATTR_PROXY_CREDENTIALS          99                          /* Proxy user credentials */
#define DCI_ATTR_INITIAL_CLIENT_ROLES       100                         /* Initial client role list */
#define DCI_ATTR_UNK                        101                         /* unknown attribute */
#define DCI_ATTR_NUM_COLS                   102                         /* number of columns */
#define DCI_ATTR_LIST_COLUMNS               103                         /* parameter of the column list */
#define DCI_ATTR_RDBA                       104                         /* DBA of the segment header */
#define DCI_ATTR_CLUSTERED                  105                         /* whether the table is clustered */
#define DCI_ATTR_PARTITIONED                106                         /* whether the table is partitioned */
#define DCI_ATTR_INDEX_ONLY                 107                         /* whether the table is index only */
#define DCI_ATTR_LIST_ARGUMENTS             108                         /* parameter of the argument list */
#define DCI_ATTR_LIST_SUBPROGRAMS           109                         /* parameter of the subprogram list */
#define DCI_ATTR_REF_TDO                    110                         /* REF to the type descriptor */
#define DCI_ATTR_LINK                       111                         /* the database link name */
#define DCI_ATTR_MIN                        112                         /* minimum value */
#define DCI_ATTR_MAX                        113                         /* maximum value */
#define DCI_ATTR_INCR                       114                         /* increment value */
#define DCI_ATTR_CACHE                      115                         /* number of sequence numbers cached */
#define DCI_ATTR_ORDER                      116                         /* whether the sequence is ordered */
#define DCI_ATTR_HW_MARK                    117                         /* high-water mark */
#define DCI_ATTR_TYPE_SCHEMA                118                         /* type's schema name */
#define DCI_ATTR_TIMESTAMP                  119                         /* timestamp of the object */
#define DCI_ATTR_NUM_ATTRS                  120                         /* number of sttributes */
#define DCI_ATTR_NUM_PARAMS                 121                         /* number of parameters */
#define DCI_ATTR_OBJID                      122                         /* object id for a table or view */
#define DCI_ATTR_PTYPE                      123                         /* type of info described by */
#define DCI_ATTR_PARAM                      124                         /* parameter descriptor */
#define DCI_ATTR_OVERLOAD_ID                125                         /* overload ID for funcs and procs */
#define DCI_ATTR_TABLESPACE                 126                         /* table name space */
#define DCI_ATTR_TDO                        127                         /* TDO of a type */
#define DCI_ATTR_LTYPE                      128                         /* list type */
#define DCI_ATTR_PARSE_ERROR_OFFSET         129                         /* Parse Error offset */
#define DCI_ATTR_IS_TEMPORARY               130                         /* whether table is temporary */
#define DCI_ATTR_IS_TYPED                   131                         /* whether table is typed */
#define DCI_ATTR_DURATION                   132                         /* duration of temporary table */
#define DCI_ATTR_IS_INVOKER_RIGHTS          133                         /* is invoker rights */
#define DCI_ATTR_OBJ_NAME                   134                         /* top level schema obj name */
#define DCI_ATTR_OBJ_SCHEMA                 135                         /* schema name */
#define DCI_ATTR_OBJ_ID                     136                         /* top level schema object id */
#define DCI_ATTR_DIRPATH_SORTED_INDEX       137                         /* index that data is sorted on */
#define DCI_ATTR_DIRPATH_INDEX_MAINT_METHOD 138
#define DCI_ATTR_DIRPATH_FILE               139                         /* DB file to load into */
#define DCI_ATTR_DIRPATH_STORAGE_INITIAL    140                         /* initial extent size */
#define DCI_ATTR_DIRPATH_STORAGE_NEXT       141                         /* next extent size */
#define DCI_ATTR_TRANS_TIMEOUT              142                         /* transaction timeout */
#define DCI_ATTR_SERVER_STATUS              143                         /* state of the server handle */
#define DCI_ATTR_STATEMENT                  144                         /* statement txt in stmt hdl */
#define DCI_ATTR_DIRPATH_SKIPINDEX_METHOD   145
#define DCI_ATTR_DEQCOND                    146                         /* dequeue condition */
#define DCI_ATTR_RESERVED_2                 147                         /* reserved */
#define DCI_ATTR_SUBSCR_RECPT               148                         /* recepient of subscription */
#define DCI_ATTR_SUBSCR_RECPTPROTO          149                         /* protocol for recepient */
#define DCI_ATTR_DIRPATH_EXPR_TYPE          150                         /* expr type of OCI_ATTR_NAME */
#define DCI_ATTR_DIRPATH_INPUT              151                         /* input in text or stream format */
#define DCI_DIRPATH_INPUT_TEXT              0x01
#define DCI_DIRPATH_INPUT_STREAM            0x02
#define DCI_DIRPATH_INPUT_UNKNOWN           0x04
#define DCI_ATTR_LDAP_HOST                  153                         /* LDAP host to connect to */
#define DCI_ATTR_LDAP_PORT                  154                         /* LDAP port to connect to */
#define DCI_ATTR_BIND_DN                    155                         /* bind DN */
#define DCI_ATTR_LDAP_CRED                  156                         /* credentials to connect to LDAP */
#define DCI_ATTR_WALL_LOC                   157                         /* client wallet location */
#define DCI_ATTR_LDAP_AUTH                  158                         /* LDAP authentication method */
#define DCI_ATTR_LDAP_CTX                   159                         /* LDAP adminstration context DN */
#define DCI_ATTR_SERVER_DNS                 160                         /* list of registration server DNs */
#define DCI_ATTR_DN_COUNT                   161                         /* the number of server DNs */
#define DCI_ATTR_SERVER_DN                  162                         /* server DN attribute */
#define DCI_ATTR_MAXCHAR_SIZE               163                         /* max char size of data */
#define DCI_ATTR_CURRENT_POSITION           164                         /* for scrollable result sets*/
#define DCI_ATTR_RESERVED_3                 165                         /* reserved */
#define DCI_ATTR_RESERVED_4                 166                         /* reserved */
#define DCI_ATTR_DIRPATH_FN_CTX             167                         /* fn ctx ADT attrs or args */
#define DCI_ATTR_DIGEST_ALGO                168                         /* digest algorithm */
#define DCI_ATTR_CERTIFICATE                169                         /* certificate */
#define DCI_ATTR_SIGNATURE_ALGO             170                         /* signature algorithm */
#define DCI_ATTR_CANONICAL_ALGO             171                         /* canonicalization algo. */
#define DCI_ATTR_PRIVATE_KEY                172                         /* private key */
#define DCI_ATTR_DIGEST_VALUE               173                         /* digest value */
#define DCI_ATTR_SIGNATURE_VAL              174                         /* signature value */
#define DCI_ATTR_SIGNATURE                  175                         /* signature */
#define DCI_ATTR_STMTCACHESIZE              176                         /* size of the stm cache */
#define DCI_ATTR_CONN_NOWAIT                178
#define DCI_ATTR_CONN_BUSY_COUNT            179
#define DCI_ATTR_CONN_OPEN_COUNT            180
#define DCI_ATTR_CONN_TIMEOUT               181
#define DCI_ATTR_STMT_STATE                 182
#define DCI_ATTR_CONN_MIN                   183
#define DCI_ATTR_CONN_MAX                   184
#define DCI_ATTR_CONN_INCR                  185
#define DCI_ATTR_DIRPATH_OID                187                         /* loading into an OID col */
#define DCI_ATTR_NUM_OPEN_STMTS             188                         /* open stmts in session */
#define DCI_ATTR_DESCRIBE_NATIVE            189                         /* get native info via desc */
#define DCI_ATTR_BIND_COUNT                 190                         /* number of bind postions */
#define DCI_ATTR_HANDLE_POSITION            191                         /* pos of bind/define handle */
#define DCI_ATTR_RESERVED_5                 192                         /* reserverd */
#define DCI_ATTR_SERVER_BUSY                193                         /* call in progress on server*/
#define DCI_ATTR_DIRPATH_SID                194                         /* loading into an SID col */
#define DCI_ATTR_SUBSCR_RECPTPRES           195
#define DCI_ATTR_TRANSFORMATION             196                         /* AQ message transformation */
#define DCI_ATTR_ROWS_FETCHED               197                         /* rows fetched in last call */
#define DCI_ATTR_SCN_BASE                   198                         /* snapshot base */
#define DCI_ATTR_SCN_WRAP                   199                         /* snapshot wrap */
#define DCI_ATTR_RESERVED_6                 200                         /* reserved */
#define DCI_ATTR_READONLY_TXN               201                         /* txn is readonly */
#define DCI_ATTR_RESERVED_7                 202                         /* reserved */
#define DCI_ATTR_ERRONEOUS_COLUMN           203                         /* position of erroneous col */
#define DCI_ATTR_RESERVED_8                 204                         /* reserved */
#define DCI_ATTR_DIRPATH_OBJ_CONSTR         206                         /* obj type of subst obj tbl */
#define DCI_ATTR_INST_TYPE                  207                         /* oracle instance type */
/******USED attribute 208 for  OCI_ATTR_SPOOL_STMTCACHESIZE*******************/
#define DCI_ATTR_ENV_UTF16                  209                         /* is env in utf16 mode? */
#define DCI_ATTR_RESERVED_9                 210                         /* reserved for TMZ */
#define DCI_ATTR_RESERVED_10                211                         /* reserved */
#define DCI_ATTR_DIRPATH_STREAM_VERSION     212                         /* version of the stream*/
#define DCI_ATTR_DIRPATH_VARRAY_INDEX       213                         /* varray index column */
#define DCI_ATTR_RESERVED_12                214                         /* reserved */
#define DCI_ATTR_RESERVED_13                215                         /* reserved */
#define DCI_ATTR_IS_EXTERNAL                216                         /* whether table is external */
#define DCI_ATTR_RESERVED_15                217                         /* reserved */
#define DCI_ATTR_STMT_IS_RETURNING          218                         /* stmt has returning clause */
#define DCI_ATTR_RESERVED_16                219                         /* reserved */
#define DCI_ATTR_RESERVED_17                220                         /* reserved */
#define DCI_ATTR_RESERVED_18                221                         /* reserved */
#define DCI_ATTR_RESERVED_19                222                         /* reserved */
#define DCI_ATTR_LIST_TYPE                  223                         /*attributes of list,designates list type*/
#define DCI_ATTR_DRIVER_NAME                424                         /* Specifies the name of the driver layer using OCI. (Such as JDBC, ODBC, PHP, SQL*Plus, and so on. */
#define DCI_ATTR_ENV_CHARSET_ID             DCI_ATTR_CHARSET_ID         /* charset id in env */
#define DCI_ATTR_ENV_NCHARSET_ID            DCI_ATTR_NCHARSET_ID        /* ncharset id in env */

/**************************EXTENDED ATTRIBUTES FOR DM****************************/
#define DCI_ATTR_PORT                       1000                    /* DM login port	 */
#define DCI_ATTR_DIRPATH_SET_IDENTITY       2000                    /* DRIPATH INPUT ENABLE SET IDENTITY COLUMN*/
#define DCI_ATTR_SSL_PATH                   10000                   /*attributes of SSL_PATH*/
#define DCI_ATTR_SSL_PWD                    10001
#define DCI_ATTR_MPP_LOGIN                  10002
#define DCI_ATTR_RW_SEPARATE                10003
#define DCI_ATTR_RW_SEPARATE_PERCENT        10004
#define DCI_ATTR_CONN_TYPE                  10005
#define DCI_ATTR_LOGIN_CERTIFICATE          10006

/*------------- Supported Values for Direct Path Stream Version -------------*/
#define DCI_DIRPATH_STREAM_VERSION_1            100
#define DCI_DIRPATH_STREAM_VERSION_2            200
#define DCI_DIRPATH_STREAM_VERSION_3            300                 /* default */

/* ----------------------- row callback attributes ------------------------- */
#define DCI_ATTR_BIND_ROWCBK                    301                 /* bind row callback */
#define DCI_ATTR_BIND_ROWCTX                    302                 /* ctx for bind row callback */
#define DCI_ATTR_SKIP_BUFFER                    303                 /* skip buffer in array ops */

/*------------- Supported Values for protocol for recepient -----------------*/
#define DCI_SUBSCR_PROTO_OCI                    0                   /* oci */
#define DCI_SUBSCR_PROTO_MAIL                   1                   /* mail */
#define DCI_SUBSCR_PROTO_SERVER                 2                   /* server */
#define DCI_SUBSCR_PROTO_HTTP                   3                   /* http */
#define DCI_SUBSCR_PROTO_MAX                    4                   /* max current protocols */

/*------------- Supported Values for presentation for recepient -------------*/
#define DCI_SUBSCR_PRES_DEFAULT                 0                   /* default */
#define DCI_SUBSCR_PRES_XML                     1                   /* xml */
#define DCI_SUBSCR_PRES_MAX                     2                   /* max current presentations */

/* ----- Temporary attribute value for UCS2/UTF16 character set ID -------- */ 
#define DCI_UCS2ID                              1000                /* UCS2 charset ID */
#define DCI_UTF16ID                             1000                /* UTF16 charset ID */

/*============================== End OCI Attribute Types ====================*/

/*---------------- Session Handle Attribute Values for DM only---------------------------*/
/* OCI_ATTR_MPP_LOGIN*/
#define DCI_MPP_LOGIN_GLOBAL                    0
#define DCI_MPP_LOGIN_LOCAL                     1

/* OCI_ATTR_RW_SEPARATE*/
#define DCI_RW_SEPARATE_OFF                     0
#define DCI_RW_SEPARATE_ON                      1

/* OCI_ATTR_CONN_TYPE*/
#define DCI_CONN_TCP                            0
#define DCI_CONN_UDP                            1
#define DCI_CONN_IPC                            2
#define DCI_CONN_RDMA                           3
#define DCI_CONN_UNIXSOCKET                     4

/*---------------- Server Handle Attribute Values ---------------------------*/
/* OCI_ATTR_SERVER_STATUS */
#define DCI_SERVER_NOT_CONNECTED                0x0
#define DCI_SERVER_NORMAL                       0x1

/*---------------------------------------------------------------------------*/

/*------------------------- Supported Namespaces  ---------------------------*/
#define DCI_SUBSCR_NAMESPACE_ANONYMOUS          0                   /* Anonymous Namespace */
#define DCI_SUBSCR_NAMESPACE_AQ                 1                   /* Advanced Queues */
#define DCI_SUBSCR_NAMESPACE_MAX                2                   /* Max Name Space Number */

/*-------------------------Credential Types----------------------------------*/
#define DCI_CRED_RDBMS                          1                   /* database username/password */
#define DCI_CRED_EXT                            2                   /* externally provided credentials */
#define DCI_CRED_PROXY                          3                   /* proxy authentication */
#define DCI_CRED_RESERVED_1                     4                   /* reserved */
#define DCI_CRED_RESERVED_2                     5                   /* reserved */
/*---------------------------------------------------------------------------*/

/*------------------------Error Return Values--------------------------------*/
#define DCI_SUCCESS                             0                   /* maps to SQL_SUCCESS of SAG CLI */
#define DCI_SUCCESS_WITH_INFO                   1                   /* maps to SQL_SUCCESS_WITH_INFO */
#define DCI_RESERVED_FOR_INT_USE                200                 /* reserved */ 
#define DCI_NO_DATA                             100                 /* maps to SQL_NO_DATA */
#define DCI_ERROR                               -1                  /* maps to SQL_ERROR */
#define DCI_INVALID_HANDLE                      -2                  /* maps to SQL_INVALID_HANDLE */
#define DCI_NEED_DATA                           99                  /* maps to SQL_NEED_DATA */
#define DCI_STILL_EXECUTING                     -3123               /* OCI would block error */
/*---------------------------------------------------------------------------*/

/*--------------------- User Callback Return Values -------------------------*/
#define DCI_CONTINUE                            -24200                  /* Continue with the body of the OCI function */
#define DCI_ROWCBK_DONE                         -24201                  /* done with user row callback */
/*---------------------------------------------------------------------------*/

/*------------------DateTime and Interval check Error codes------------------*/

/* DateTime Error Codes used by OCIDateTimeCheck() */
#define DCI_DT_INVALID_DAY                      0x1                     /* Bad day */
#define DCI_DT_DAY_BELOW_VALID                  0x2                     /* Bad DAy Low/high bit (1=low)*/
#define DCI_DT_INVALID_MONTH                    0x4                     /*  Bad MOnth */
#define DCI_DT_MONTH_BELOW_VALID                0x8                     /* Bad MOnth Low/high bit (1=low) */
#define DCI_DT_INVALID_YEAR                     0x10                    /* Bad YeaR */
#define DCI_DT_YEAR_BELOW_VALID                 0x20                    /*  Bad YeaR Low/high bit (1=low) */
#define DCI_DT_INVALID_HOUR                     0x40                    /*  Bad HouR */
#define DCI_DT_HOUR_BELOW_VALID                 0x80                    /* Bad HouR Low/high bit (1=low) */
#define DCI_DT_INVALID_MINUTE                   0x100                   /* Bad MiNute */
#define DCI_DT_MINUTE_BELOW_VALID               0x200                   /*Bad MiNute Low/high bit (1=low) */
#define DCI_DT_INVALID_SECOND                   0x400                   /*  Bad SeCond */
#define DCI_DT_SECOND_BELOW_VALID               0x800                   /*bad second Low/high bit (1=low)*/
#define DCI_DT_DAY_MISSING_FROM_1582            0x1000                  /*  Day is one of those "missing" from 1582 */
#define DCI_DT_YEAR_ZERO                        0x2000                  /* Year may not equal zero */
#define DCI_DT_INVALID_TIMEZONE                 0x4000                  /*  Bad Timezone */
#define DCI_DT_INVALID_FORMAT                   0x8000                  /* Bad date format input */

/* Interval Error Codes used by OCIInterCheck() */
#define DCI_INTER_INVALID_DAY                   0x1                     /* Bad day */
#define DCI_INTER_DAY_BELOW_VALID               0x2                     /* Bad DAy Low/high bit (1=low) */
#define DCI_INTER_INVALID_MONTH                 0x4                     /* Bad MOnth */
#define DCI_INTER_MONTH_BELOW_VALID             0x8                     /*Bad MOnth Low/high bit (1=low) */
#define DCI_INTER_INVALID_YEAR                  0x10                    /* Bad YeaR */
#define DCI_INTER_YEAR_BELOW_VALID              0x20                    /*Bad YeaR Low/high bit (1=low) */
#define DCI_INTER_INVALID_HOUR                  0x40                    /* Bad HouR */
#define DCI_INTER_HOUR_BELOW_VALID              0x80                    /*Bad HouR Low/high bit (1=low) */
#define DCI_INTER_INVALID_MINUTE                0x100                   /* Bad MiNute */
#define DCI_INTER_MINUTE_BELOW_VALID            0x200                   /*Bad MiNute Low/high bit(1=low) */
#define DCI_INTER_INVALID_SECOND                0x400                   /* Bad SeCond */
#define DCI_INTER_SECOND_BELOW_VALID            0x800                   /*bad second Low/high bit(1=low) */
#define DCI_INTER_INVALID_FRACSEC               0x1000                  /* Bad Fractional second */
#define DCI_INTER_FRACSEC_BELOW_VALID           0x2000                  /* Bad fractional second Low/High */

/* --------------------END DateTime and Interval Constants ------------------*/

/*------------------------Parsing Syntax Types-------------------------------*/
#define DCI_V7_SYNTAX                           2                       /* V815 language - for backwards compatibility */
#define DCI_V8_SYNTAX                           3                       /* V815 language - for backwards compatibility */
#define DCI_NTV_SYNTAX                          1                       /* Use what so ever is the native lang of server */
/*---------------------------------------------------------------------------*/

/*------------------------Scrollable Cursor Fetch Options------------------- 
 * For non-scrollable cursor, the only valid (and default) orientation is 
 * OCI_FETCH_NEXT
 */
#define DCI_FETCH_CURRENT                       0x01                    /* refetching current position  */
#define DCI_FETCH_NEXT                          0x02                    /* next row */
#define DCI_FETCH_FIRST                         0x04                    /* first row of the result set */
#define DCI_FETCH_LAST                          0x08                    /* the last row of the result set */
#define DCI_FETCH_PRIOR                         0x10                    /* the previous row relative to current */
#define DCI_FETCH_ABSOLUTE                      0x20                    /* absolute offset from first */
#define DCI_FETCH_RELATIVE                      0x40                    /* offset relative to current */
#define DCI_FETCH_RESERVED_1                    0x80                    /* reserved */

/*---------------------------------------------------------------------------*/

/*------------------------Bind and Define Options----------------------------*/
#define DCI_SB2_IND_PTR                         0x00000001              /* unused */
#define DCI_DATA_AT_EXEC                        0x00000002              /* data at execute time */
#define DCI_DYNAMIC_FETCH                       0x00000002              /* fetch dynamically */
#define DCI_PIECEWISE                           0x00000004              /* piecewise DMLs or fetch */
#define DCI_DEFINE_RESERVED_1                   0x00000008              /* reserved */
#define DCI_BIND_RESERVED_2                     0x00000010              /* reserved */
#define DCI_DEFINE_RESERVED_2                   0x00000020              /* reserved */
#define DCI_BIND_SOFT                           0x00000040              /* soft bind or define */
#define DCI_DEFINE_SOFT                         0x00000080              /* soft bind or define */
#define DCI_IOV                                 0x00000200           /* For scatter gather bind/define */
/*---------------------------------------------------------------------------*/

/*-----------------------------  Various Modes ------------------------------*/
#define DCI_DEFAULT                             0x00000000              /* the default value for parameters and attributes */

/*-------------OCIInitialize Modes / OCICreateEnvironment Modes -------------*/
#define DCI_THREADED                            0x00000001              /* appl. in threaded environment */
#define DCI_OBJECT                              0x00000002              /* application in object environment */
#define DCI_EVENTS                              0x00000004              /* application is enabled for events */
#define DCI_RESERVED1                           0x00000008              /* reserved */
#define DCI_SHARED                              0x00000010              /* the application is in shared mode */
#define DCI_RESERVED2                           0x00000020              /* reserved */
/* The following *TWO* are only valid for OCICreateEnvironment call */
#define DCI_NO_UCB                              0x00000040              /* No user callback called during ini */
#define DCI_NO_MUTEX                            0x00000080              /* the environment handle will not be 
                                                                           protected by a mutex internally*/
#define DCI_SHARED_EXT                          0x00000100              /* Used for shared forms */
/************************** 0x00000200 free **********************************/
#define DCI_ALWAYS_BLOCKING                     0x00000400              /* all connections always blocking */
/************************** 0x00000800 free **********************************/
#define DCI_USE_LDAP                            0x00001000              /* allow  LDAP connections */
#define DCI_REG_LDAPONLY                        0x00002000              /* only register to LDAP */
#define DCI_UTF16                               0x00004000              /* mode for all UTF16 metadata */
#define DCI_AFC_PAD_ON                          0x00008000              /* turn on AFC blank padding when rlenp present */
#define DCI_ENVCR_RESERVED3                     0x00010000              /* reserved */
#define DCI_NEW_LENGTH_SEMANTICS                0x00020000              /* adopt new length semantics 
                                                                           the new length semantics, always bytes, is used by OCIEnvNlsCreate */
#define DCI_NO_MUTEX_STMT                       0x00040000              /* Do not mutex stmt handle */
#define DCI_MUTEX_ENV_ONLY                      0x00080000              /* Mutex only the environment handle */
#define DCI_NCHAR_LITERAL_REPLACE_ON            0x00400000              /* nchar literal replace on */
#define DCI_NCHAR_LITERAL_REPLACE_OFF           0x00800000              /* nchar literal replace off*/
#define DCI_STM_RESERVED4                       0x00100000              /* reserved */

/*---------------------------------------------------------------------------*/
/*------------------------OCIConnectionpoolCreate Modes----------------------*/

#define DCI_CPOOL_REINITIALIZE                  0x111

/*---------------------------------------------------------------------------*/
/*--------------------------------- OCILogon2 Modes -------------------------*/

#define DCI_LOGON2_SPOOL                        0x0001                  /* Use session pool */
#define DCI_LOGON2_CPOOL                        DCI_CPOOL               /* Use connection pool */
#define DCI_LOGON2_STMTCACHE                    0x0004                  /* Use Stmt Caching */
#define DCI_LOGON2_PROXY                        0x0008                  /* Proxy authentiaction */

/*---------------------------------------------------------------------------*/
/*------------------------- OCISessionPoolCreate Modes ----------------------*/

#define DCI_SPC_REINITIALIZE                    0x0001                  /* Reinitialize the session pool */
#define DCI_SPC_HOMOGENEOUS                     0x0002                  /* Session pool is homogeneneous */
#define DCI_SPC_STMTCACHE                       0x0004                  /* Session pool has stmt cache */
#define DCI_SPC_NO_RLB                          0x0008                  /* Do not enable Runtime load balancing. */ 

/*---------------------------------------------------------------------------*/
/*--------------------------- OCISessionGet Modes ---------------------------*/

#define DCI_SESSGET_SPOOL                       0x0001                  /* SessionGet called in SPOOL mode */
#define DCI_SESSGET_CPOOL                       DCI_CPOOL               /* SessionGet called in CPOOL mode */
#define DCI_SESSGET_STMTCACHE                   0x0004                  /* Use statement cache */
#define DCI_SESSGET_CREDPROXY                   0x0008                  /* SessionGet called in proxy mode */
#define DCI_SESSGET_CREDEXT                     0x0010
#define DCI_SESSGET_SPOOL_MATCHANY              0x0020
/*---------------------------------------------------------------------------*/
/*------------------------ATTR Values for Session Pool-----------------------*/
/* Attribute values for OCI_ATTR_SPOOL_GETMODE */
#define DCI_SPOOL_ATTRVAL_WAIT                  0                       /* block till you get a session */
#define DCI_SPOOL_ATTRVAL_NOWAIT                1                       /* error out if no session avaliable */
#define DCI_SPOOL_ATTRVAL_FORCEGET              2                       /* get session even if max is exceeded */

/*---------------------------------------------------------------------------*/
/*--------------------------- OCISessionRelease Modes -----------------------*/

#define DCI_SESSRLS_DROPSESS                    0x0001                  /* Drop the Session */
#define DCI_SESSRLS_RETAG                       0x0002                  /* Retag the session */

/*---------------------------------------------------------------------------*/
/*----------------------- OCISessionPoolDestroy Modes -----------------------*/

#define DCI_SPD_FORCE                           0x0001                  /* Force the sessions to terminate. 
                                                                           Even if there are some busy sessions close them */

/*---------------------------------------------------------------------------*/
/*----------------------------- Statement States ----------------------------*/

#define DCI_STMT_STATE_INITIALIZED              0x0001
#define DCI_STMT_STATE_EXECUTED                 0x0002
#define DCI_STMT_STATE_END_OF_FETCH             0x0003

/*---------------------------------------------------------------------------*/

/*----------------------------- OCIMemStats Modes ---------------------------*/
#define DCI_MEM_INIT                            0x01
#define DCI_MEM_CLN                             0x02
#define DCI_MEM_FLUSH                           0x04
#define DCI_DUMP_HEAP                           0x80

#define DCI_CLIENT_STATS                        0x10
#define DCI_SERVER_STATS                        0x20

/*----------------------------- OCIEnvInit Modes ----------------------------*/
/* NOTE: NO NEW MODES SHOULD BE ADDED HERE BECAUSE THE RECOMMENDED METHOD 
 * IS TO USE THE NEW OCICreateEnvironment MODES.
 */
#define DCI_ENV_NO_UCB                          0x01                    /* A user callback will not be called in OCIEnvInit() */
#define DCI_ENV_NO_MUTEX                        0x08                    /* the environment handle will not be protected by a mutex internally */

/*---------------------------------------------------------------------------*/

/*------------------------ Prepare Modes ------------------------------------*/
#define DCI_NO_SHARING                          0x01                    /* turn off statement handle sharing */
#define DCI_PREP_RESERVED_1                     0x02                    /* reserved */
#define DCI_PREP_AFC_PAD_ON                     0x04                    /* turn on blank padding for AFC */
#define DCI_PREP_AFC_PAD_OFF                    0x08                    /* turn off blank padding for AFC */
/*---------------------------------------------------------------------------*/

/*----------------------- Execution Modes -----------------------------------*/
#define DCI_BATCH_MODE                          0x01                    /* batch the oci statement for execution */
#define DCI_EXACT_FETCH                         0x02                    /* fetch the exact rows specified */
#define DCI_KEEP_FETCH_STATE                    0x04                    /* unused */
#define DCI_STMT_SCROLLABLE_READONLY            0x08                    /* if result set is scrollable */
#define DCI_DESCRIBE_ONLY                       0x10                    /* only describe the statement */
#define DCI_COMMIT_ON_SUCCESS                   0x20                    /* commit, if successful execution */
#define DCI_NON_BLOCKING                        0x40                    /* non-blocking */
#define DCI_BATCH_ERRORS                        0x80                    /* batch errors in array dmls */
#define DCI_PARSE_ONLY                          0x100                   /* only parse the statement */
#define DCI_EXACT_FETCH_RESERVED_1              0x200                   /* reserved */
#define DCI_SHOW_DML_WARNINGS                   0x400                   /* return OCI_SUCCESS_WITH_INFO for delete/update w/no where clause */
#define DCI_EXEC_RESERVED_2                     0x800                   /* reserved */
#define DCI_DESC_RESERVED_1                     0x1000                  /* reserved */
#define DCI_EXEC_RESERVED_3                     0x2000                  /* reserved */
#define DCI_EXEC_RESERVED_4                     0x4000                  /* reserved */
#define DCI_IDU_BATCH_COMPATIBLE                0x80000000              /*DM extend mode, to compatible with oracle idu execute mode*/

/*---------------------------------------------------------------------------*/

/*------------------------Authentication Modes-------------------------------*/
#define DCI_MIGRATE                             0x0001                  /* migratable auth context */
#define DCI_SYSDBA                              0x0002                  /* for SYSDBA authorization */
#define DCI_SYSOPER                             0x0004                  /* for SYSOPER authorization */
#define DCI_PRELIM_AUTH                         0x0008                  /* for preliminary authorization */
#define DCIP_ICACHE                             0x0010                  /* Private OCI cache mode to notify cache */
#define DCI_AUTH_RESERVED_1                     0x0020                  /* reserved */
#define DCI_STMT_CACHE                          0x0040                  /* enable OCI Stmt Caching */

/*---------------------------------------------------------------------------*/

/*------------------------Session End Modes----------------------------------*/
#define DCI_SESSEND_RESERVED_1                  0x0001                  /* reserved */
/*---------------------------------------------------------------------------*/

/*------------------------Attach Modes---------------------------------------*/
#define DCI_FASTPATH                            0x0010                  /* Attach in fast path mode */
#define DCI_ATCH_RESERVED_1                     0x0020                  /* reserved */
#define DCI_ATCH_RESERVED_2                     0x0080                  /* reserved */
#define DCI_ATCH_RESERVED_3                     0x0100                  /* reserved */
#define DCI_CPOOL                               0x0200                  /* Attach using server handle from pool */
#define DCI_ATCH_RESERVED_4                     0x0400                  /* reserved */

/*---------------------OCIStmtPrepare2 Modes---------------------------------*/
#define DCI_PREP2_CACHE_SEARCHONLY              0x0010                  /* ONly Search */
#define DCI_PREP2_GET_PLSQL_WARNINGS            0x0020                  /* Get PL/SQL warnings  */

/*---------------------OCIStmtRelease Modes----------------------------------*/
#define DCI_STRLS_CACHE_DELETE                  0x0010                  /* Delete from Cache */

/*-----------------------------End Various Modes ----------------------------*/

/*------------------------Piece Information----------------------------------*/
#define DCI_PARAM_IN                            0x01                    /* in parameter */
#define DCI_PARAM_OUT                           0x02                    /* out parameter */
/*---------------------------------------------------------------------------*/

/*------------------------ Transaction Start Flags --------------------------*/
/* NOTE: OCI_TRANS_JOIN and OCI_TRANS_NOMIGRATE not supported in 8.0.X       */
#define DCI_TRANS_NEW                           0x00000001              /* starts a new transaction branch */
#define DCI_TRANS_JOIN                          0x00000002              /* join an existing transaction */
#define DCI_TRANS_RESUME                        0x00000004              /* resume this transaction */
#define DCI_TRANS_STARTMASK                     0x000000ff
#define DCI_TRANS_READONLY                      0x00000100              /* starts a readonly transaction */
#define DCI_TRANS_READWRITE                     0x00000200              /* starts a read-write transaction */
#define DCI_TRANS_SERIALIZABLE                  0x00000400              /* starts a serializable transaction */
#define DCI_TRANS_ISOLMASK                      0x0000ff00
#define DCI_TRANS_LOOSE                         0x00010000              /* a loosely coupled branch */
#define DCI_TRANS_TIGHT                         0x00020000              /* a tightly coupled branch */
#define DCI_TRANS_TYPEMASK                      0x000f0000
#define DCI_TRANS_NOMIGRATE                     0x00100000              /* non migratable transaction */
#define DCI_TRANS_SEPARABLE                     0x00200000              /* separable transaction (8.1.6+) */

/*---------------------------------------------------------------------------*/

/*------------------------ Transaction End Flags ----------------------------*/
#define DCI_TRANS_TWOPHASE                      0x01000000              /* use two phase commit */
/*---------------------------------------------------------------------------*/

/*------------------------- AQ Constants ------------------------------------
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
 * The following constants must match the PL/SQL dbms_aq constants
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
 */
/* ------------------------- Visibility flags -------------------------------*/
#define DCI_ENQ_IMMEDIATE                       1                       /* enqueue is an independent transaction */
#define DCI_ENQ_ON_COMMIT                       2                       /* enqueue is part of current transaction */

/* ----------------------- Dequeue mode flags -------------------------------*/
#define DCI_DEQ_BROWSE                          1                       /* read message without acquiring a lock */
#define DCI_DEQ_LOCKED                          2                       /* read and obtain write lock on message */
#define DCI_DEQ_REMOVE                          3                       /* read the message and delete it */
#define DCI_DEQ_REMOVE_NODATA                   4                       /* delete message w'o returning payload */
#define DCI_DEQ_GETSIG                          5                       /* get signature only */

/* ----------------- Dequeue navigation flags -------------------------------*/
#define DCI_DEQ_FIRST_MSG                       1                       /* get first message at head of queue */
#define DCI_DEQ_NEXT_MSG                        3                       /* next message that is available */
#define DCI_DEQ_NEXT_TRANSACTION                2                       /* get first message of next txn group */
#define DCI_DEQ_MULT_TRANSACTION                5                       /* array dequeue across txn groups */

/* ----------------- Dequeue Option Reserved flags ------------------------- */
#define DCI_DEQ_RESERVED_1                      0x000001

/* --------------------- Message states -------------------------------------*/
#define DCI_MSG_WAITING                         1                       /* the message delay has not yet completed */
#define DCI_MSG_READY                           0                       /* the message is ready to be processed */
#define DCI_MSG_PROCESSED                       2                       /* the message has been processed */
#define DCI_MSG_EXPIRED                         3                       /* message has moved to exception queue */

/* --------------------- Sequence deviation ---------------------------------*/
#define DCI_ENQ_BEFORE                          2                       /* enqueue message before another message */
#define DCI_ENQ_TOP                             3                       /* enqueue message before all messages */

/* ------------------------- Visibility flags -------------------------------*/
#define DCI_DEQ_IMMEDIATE                       1                       /* dequeue is an independent transaction */
#define DCI_DEQ_ON_COMMIT                       2                       /* dequeue is part of current transaction */

/* ------------------------ Wait --------------------------------------------*/
#define DCI_DEQ_WAIT_FOREVER                    -1                      /* wait forever if no message available */
#define DCI_DEQ_NO_WAIT                         0                       /* do not wait if no message is available */

/* ------------------------ Delay -------------------------------------------*/
#define DCI_MSG_NO_DELAY                        0                       /* message is available immediately */

/* ------------------------- Expiration -------------------------------------*/
#define DCI_MSG_NO_EXPIRATION                   -1                      /* message will never expire */

/* ------------------------- Reserved ---------------------------------------*/
#define DCI_AQ_RESERVED_1                       0x0002
#define DCI_AQ_RESERVED_2                       0x0004
#define DCI_AQ_RESERVED_3                       0x0008

/* -------------------------- END AQ Constants ----------------------------- */

/*-----------------------Object Types----------------------------------------*/
/*-----------Object Types **** Not to be Used **** --------------------------*/
/* Deprecated */
#define DCI_OTYPE_UNK                           0
#define DCI_OTYPE_TABLE                         1
#define DCI_OTYPE_VIEW                          2
#define DCI_OTYPE_SYN                           3
#define DCI_OTYPE_PROC                          4
#define DCI_OTYPE_FUNC                          5
#define DCI_OTYPE_PKG                           6
#define DCI_OTYPE_STMT                          7
/*---------------------------------------------------------------------------*/

/*=======================Describe Handle Parameter Attributes ===============*/
/* 
   These attributes are orthogonal to the other set of attributes defined 
   above.  These attrubutes are tobe used only for the desscribe handle 
*/
/*===========================================================================*/
/* Attributes common to Columns and Stored Procs */
#define DCI_ATTR_DATA_SIZE                      1                       /* maximum size of the data */
#define DCI_ATTR_DATA_TYPE                      2                       /* the SQL type of the column/argument */
#define DCI_ATTR_DISP_SIZE                      3                       /* the display size */
#define DCI_ATTR_NAME                           4                       /* the name of the column/argument */
#define DCI_ATTR_PRECISION                      5                       /* precision if number type */
#define DCI_ATTR_SCALE                          6                       /* scale if number type */
#define DCI_ATTR_IS_NULL                        7                       /* is it null ? */
#define DCI_ATTR_TYPE_NAME                      8                       /* name of the named data type or a package name for package private types */
#define DCI_ATTR_SCHEMA_NAME                    9                       /* the schema name */
#define DCI_ATTR_SUB_NAME                       10                      /* type name if package private type */
#define DCI_ATTR_POSITION                       11                      /* relative position of col/arg in the list of cols/args */

/* complex object retrieval parameter attributes */
#define DCI_ATTR_COMPLEXOBJECTCOMP_TYPE         50
#define DCI_ATTR_COMPLEXOBJECTCOMP_TYPE_LEVEL   51
#define DCI_ATTR_COMPLEXOBJECT_LEVEL            52
#define DCI_ATTR_COMPLEXOBJECT_COLL_OUTOFLINE   53

/* Only Columns */
#define DCI_ATTR_DISP_NAME                      100                     /* the display name */
#define DCI_ATTR_ENCC_SIZE                      101                     /* encrypted data size */
#define DCI_ATTR_COL_ENC                        102                     /* column is encrypted ? */
#define DCI_ATTR_COL_ENC_SALT                   103                     /* is encrypted column salted ? */

/*Only Stored Procs */
#define DCI_ATTR_OVERLOAD                       210                     /* is this position overloaded */
#define DCI_ATTR_LEVEL                          211                     /* level for structured types */
#define DCI_ATTR_HAS_DEFAULT                    212                     /* has a default value */
#define DCI_ATTR_IOMODE                         213                     /* in, out inout */
#define DCI_ATTR_RADIX                          214                     /* returns a radix */
#define DCI_ATTR_NUM_ARGS                       215                     /* total number of arguments */

/* only named type attributes */
#define DCI_ATTR_TYPECODE                       216                     /* object or collection */
#define DCI_ATTR_COLLECTION_TYPECODE            217                     /* varray or nested table */
#define DCI_ATTR_VERSION                        218                     /* user assigned version */
#define DCI_ATTR_IS_INCOMPLETE_TYPE             219                     /* is this an incomplete type */
#define DCI_ATTR_IS_SYSTEM_TYPE                 220                     /* a system type */
#define DCI_ATTR_IS_PREDEFINED_TYPE             221                     /* a predefined type */
#define DCI_ATTR_IS_TRANSIENT_TYPE              222                     /* a transient type */
#define DCI_ATTR_IS_SYSTEM_GENERATED_TYPE       223                     /* system generated type */
#define DCI_ATTR_HAS_NESTED_TABLE               224                     /* contains nested table attr */
#define DCI_ATTR_HAS_LOB                        225                     /* has a lob attribute */
#define DCI_ATTR_HAS_FILE                       226                     /* has a file attribute */
#define DCI_ATTR_COLLECTION_ELEMENT             227                     /* has a collection attribute */
#define DCI_ATTR_NUM_TYPE_ATTRS                 228                     /* number of attribute types */
#define DCI_ATTR_LIST_TYPE_ATTRS                229                     /* list of type attributes */
#define DCI_ATTR_NUM_TYPE_METHODS               230                     /* number of type methods */
#define DCI_ATTR_LIST_TYPE_METHODS              231                     /* list of type methods */
#define DCI_ATTR_MAP_METHOD                     232                     /* map method of type */
#define DCI_ATTR_ORDER_METHOD                   233                     /* order method of type */

/* only collection element */
#define DCI_ATTR_NUM_ELEMS                      234                     /* number of elements */

/* only type methods */
#define DCI_ATTR_ENCAPSULATION                  235                     /* encapsulation level */
#define DCI_ATTR_IS_SELFISH                     236                     /* method selfish */
#define DCI_ATTR_IS_VIRTUAL                     237                     /* virtual */
#define DCI_ATTR_IS_INLINE                      238                     /* inline */
#define DCI_ATTR_IS_CONSTANT                    239                     /* constant */
#define DCI_ATTR_HAS_RESULT                     240                     /* has result */
#define DCI_ATTR_IS_CONSTRUCTOR                 241                     /* constructor */
#define DCI_ATTR_IS_DESTRUCTOR                  242                     /* destructor */
#define DCI_ATTR_IS_OPERATOR                    243                     /* operator */
#define DCI_ATTR_IS_MAP                         244                     /* a map method */
#define DCI_ATTR_IS_ORDER                       245                     /* order method */
#define DCI_ATTR_IS_RNDS                        246                     /* read no data state method */
#define DCI_ATTR_IS_RNPS                        247                     /* read no process state */
#define DCI_ATTR_IS_WNDS                        248                     /* write no data state method */
#define DCI_ATTR_IS_WNPS                        249                     /* write no process state */
#define DCI_ATTR_DESC_PUBLIC                    250                     /* public object */

/* Object Cache Enhancements : attributes for User Constructed Instances     */
#define DCI_ATTR_CACHE_CLIENT_CONTEXT           251
#define DCI_ATTR_UCI_CONSTRUCT                  252
#define DCI_ATTR_UCI_DESTRUCT                   253
#define DCI_ATTR_UCI_COPY                       254
#define DCI_ATTR_UCI_PICKLE                     255
#define DCI_ATTR_UCI_UNPICKLE                   256
#define DCI_ATTR_UCI_REFRESH                    257

/* for type inheritance */
#define DCI_ATTR_IS_SUBTYPE                     258
#define DCI_ATTR_SUPERTYPE_SCHEMA_NAME          259
#define DCI_ATTR_SUPERTYPE_NAME                 260

/* for schemas */
#define DCI_ATTR_LIST_OBJECTS                   261                     /* list of objects in schema */

/* for database */
#define DCI_ATTR_NCHARSET_ID                    262                     /* char set id */
#define DCI_ATTR_LIST_SCHEMAS                   263                     /* list of schemas */
#define DCI_ATTR_MAX_PROC_LEN                   264                     /* max procedure length */
#define DCI_ATTR_MAX_COLUMN_LEN                 265                     /* max column name length */
#define DCI_ATTR_CURSOR_COMMIT_BEHAVIOR         266                     /* cursor commit behavior */
#define DCI_ATTR_MAX_CATALOG_NAMELEN            267                     /* catalog namelength */
#define DCI_ATTR_CATALOG_LOCATION               268                     /* catalog location */
#define DCI_ATTR_SAVEPOINT_SUPPORT              269                     /* savepoint support */
#define DCI_ATTR_NOWAIT_SUPPORT                 270                     /* nowait support */
#define DCI_ATTR_AUTOCOMMIT_DDL                 271                     /* autocommit DDL */
#define DCI_ATTR_LOCKING_MODE                   272                     /* locking mode */

/* for externally initialized context */
#define DCI_ATTR_APPCTX_SIZE                    273                     /* count of context to be init*/
#define DCI_ATTR_APPCTX_LIST                    274                     /* count of context to be init*/
#define DCI_ATTR_APPCTX_NAME                    275                     /* name  of context to be init*/
#define DCI_ATTR_APPCTX_ATTR                    276                     /* attr  of context to be init*/
#define DCI_ATTR_APPCTX_VALUE                   277                     /* value of context to be init*/

/* for client id propagation */
#define DCI_ATTR_CLIENT_IDENTIFIER              278                     /* value of client id to set*/

/* for inheritance - part 2 */
#define DCI_ATTR_IS_FINAL_TYPE                  279                     /* is final type ? */
#define DCI_ATTR_IS_INSTANTIABLE_TYPE           280                     /* is instantiable type ? */
#define DCI_ATTR_IS_FINAL_METHOD                281                     /* is final method ? */
#define DCI_ATTR_IS_INSTANTIABLE_METHOD         282                     /* is instantiable method ? */
#define DCI_ATTR_IS_OVERRIDING_METHOD           283                     /* is overriding method ? */

/* slot 284 available */

#define DCI_ATTR_CHAR_USED                      285                     /* char length semantics */
#define DCI_ATTR_CHAR_SIZE                      286                     /* char length */

/* SQLJ support */
#define DCI_ATTR_IS_JAVA_TYPE                   287                     /* is java implemented type ? */

/* N-Tier support */
#define DCI_ATTR_DISTINGUISHED_NAME             300                     /* use DN as user name */
#define DCI_ATTR_KERBEROS_TICKET                301                     /* Kerberos ticket as cred. */

/* for multilanguage debugging */
#define DCI_ATTR_ORA_DEBUG_JDWP                 302                     /* ORA_DEBUG_JDWP attribute */
#define DCI_ATTR_RESERVED_14                    303                     /* reserved */

/* TDE attributes on the Table */
#define DCI_ATTR_TABLE_ENC                      417                     /* does table have any encrypt columns */
#define DCI_ATTR_TABLE_ENC_ALG                  418                     /* Table encryption Algorithm */
#define DCI_ATTR_TABLE_ENC_ALG_ID               419                     /* Internal Id of encryption Algorithm*/

/*---------------------------End Describe Handle Attributes -----------------*/

/*------------- Supported Values for Direct Path Date cache -----------------*/
#define DCI_ATTR_DIRPATH_DCACHE_NUM             303                     /* date cache entries */
#define DCI_ATTR_DIRPATH_DCACHE_SIZE            304                     /* date cache limit */
#define DCI_ATTR_DIRPATH_DCACHE_MISSES          305                     /* date cache misses */
#define DCI_ATTR_DIRPATH_DCACHE_HITS            306                     /* date cache hits */
#define DCI_ATTR_DIRPATH_DCACHE_DISABLE         307                     /* on set: disable datecache 
                                                                         * on overflow.
                                                                         * on get: datecache disabled? 
                                                                         * could be due to overflow
                                                                         * or others                  */

/* ----------------------- Session Pool Attributes ------------------------- */
#define DCI_ATTR_SPOOL_TIMEOUT                  308                     /* session timeout */
#define DCI_ATTR_SPOOL_GETMODE                  309                     /* session get mode */
#define DCI_ATTR_SPOOL_BUSY_COUNT               310                     /* busy session count */
#define DCI_ATTR_SPOOL_OPEN_COUNT               311                     /* open session count */
#define DCI_ATTR_SPOOL_MIN                      312                     /* min session count */
#define DCI_ATTR_SPOOL_MAX                      313                     /* max session count */
#define DCI_ATTR_SPOOL_INCR                     314                     /* session increment count */
#define DCI_ATTR_SPOOL_STMTCACHESIZE            208                     /*Stmt cache size of pool  */
/*------------------------------End Session Pool Attributes -----------------*/
/*---------------------------- For XML Types ------------------------------- */
/* For table, view and column */
#define DCI_ATTR_IS_XMLTYPE                     315                     /* Is the type an XML type? */
#define DCI_ATTR_XMLSCHEMA_NAME                 316                     /* Name of XML Schema */
#define DCI_ATTR_XMLELEMENT_NAME                317                     /* Name of XML Element */
#define DCI_ATTR_XMLSQLTYPSCH_NAME              318                     /* SQL type's schema for XML Ele */
#define DCI_ATTR_XMLSQLTYPE_NAME                319                     /* Name of SQL type for XML Ele */
#define DCI_ATTR_XMLTYPE_STORED_OBJ             320                     /* XML type stored as object? */

/*---------------------------- For Subtypes ------------------------------- */
/* For type */
#define DCI_ATTR_HAS_SUBTYPES                   321                     /* Has subtypes? */
#define DCI_ATTR_NUM_SUBTYPES                   322                     /* Number of subtypes */
#define DCI_ATTR_LIST_SUBTYPES                  323                     /* List of subtypes */

/* XML flag */
#define DCI_ATTR_XML_HRCHY_ENABLED              324                     /* hierarchy enabled? */

/* Method flag */
#define DCI_ATTR_IS_OVERRIDDEN_METHOD           325                     /* Method is overridden? */

/*------------- Attributes for 10i Updates to the DirPath API ---------------*/
#define DCI_ATTR_DIRPATH_RESERVED_7             326                     /* reserved */
#define DCI_ATTR_DIRPATH_RESERVED_8             327                     /* reserved */
#define DCI_ATTR_DIRPATH_CONVERT                328                     /* stream conversion needed? */
#define DCI_ATTR_DIRPATH_BADROW                 329                     /* info about bad row */
#define DCI_ATTR_DIRPATH_BADROW_LENGTH          330                     /* length of bad row info */
#define DCI_ATTR_DIRPATH_WRITE_ORDER            331                     /* column fill order */
#define DCI_ATTR_DIRPATH_GRANULE_SIZE           332                     /* granule size for unload */
#define DCI_ATTR_DIRPATH_GRANULE_OFFSET         333                     /* offset to last granule */
#define DCI_ATTR_DIRPATH_RESERVED_1             334                     /* reserved */
#define DCI_ATTR_DIRPATH_RESERVED_2             335                     /* reserved */

/*------------- Attributes for 10i Distributed Objects ----------------------*/
#define DCI_ATTR_OBJ_SUBS                       336                     /* obj col/tab substitutable */

/*------ Attributes for 10i DirPathAPI conversion (NLS lang, terr, cs) ------*/
#define DCI_ATTR_DIRPATH_RESERVED_3             337                     /* reserved */
#define DCI_ATTR_DIRPATH_RESERVED_4             338                     /* reserved */

/*---------- Attributes for 10i XADFIELD (NLS language, territory -----------*/
#define DCI_ATTR_XADFIELD_RESERVED_1            339                     /* reserved */
#define DCI_ATTR_XADFIELD_RESERVED_2            340                     /* reserved */

/*------------- Kerberos Secure Client Identifier ---------------------------*/
#define DCI_ATTR_KERBEROS_CID                   341                     /* Kerberos db service ticket*/

/*------------------------ Attributes for Rules objects ---------------------*/
#define DCI_ATTR_CONDITION                      342                     /* rule condition */
#define DCI_ATTR_COMMENT                        343                     /* comment */
#define DCI_ATTR_VALUE                          344                     /* Anydata value */
#define DCI_ATTR_EVAL_CONTEXT_OWNER             345                     /* eval context owner */
#define DCI_ATTR_EVAL_CONTEXT_NAME              346                     /* eval context name */
#define DCI_ATTR_EVALUATION_FUNCTION            347                     /* eval function name */
#define DCI_ATTR_VAR_TYPE                       348                     /* variable type */
#define DCI_ATTR_VAR_VALUE_FUNCTION             349                     /* variable value function */
#define DCI_ATTR_VAR_METHOD_FUNCTION            350                     /* variable method function */
#define DCI_ATTR_ACTION_CONTEXT                 351                     /* action context */
#define DCI_ATTR_LIST_TABLE_ALIASES             352                     /* list of table aliases */
#define DCI_ATTR_LIST_VARIABLE_TYPES            353                     /* list of variable types */
#define DCI_ATTR_TABLE_NAME                     356                     /* table name */
#define DCI_ATTR_DIRPATH_RESERVED_5             357                     /* reserved */
#define DCI_ATTR_DIRPATH_RESERVED_6             358                     /* reserved */
#define DCI_ATTR_DIRPATH_LOCK_WAIT              359                     /* wait for lock in dpapi */
#define DCI_ATTR_MESSAGE_CSCN                   360                     /* message cscn */
#define DCI_ATTR_MESSAGE_DSCN                   361                     /* message dscn */

/*--------------------- Audit Session ID ------------------------------------*/
#define DCI_ATTR_AUDIT_SESSION_ID               362                     /* Audit session ID */

/*--------------------- Kerberos TGT Keys -----------------------------------*/
#define DCI_ATTR_KERBEROS_KEY                   363                     /* n-tier Kerberos cred key */
#define DCI_ATTR_KERBEROS_CID_KEY               364                     /* SCID Kerberos cred key */
#define DCI_ATTR_TRANSACTION_NO                 365                     /* AQ enq txn number */

/*----------------------- Attributes for End To End Tracing -----------------*/
#define DCI_ATTR_MODULE                         366                     /* module for tracing */
#define DCI_ATTR_ACTION                         367                     /* action for tracing */
#define DCI_ATTR_CLIENT_INFO                    368                     /* client info */
#define DCI_ATTR_COLLECT_CALL_TIME              369                     /* collect call time */
#define DCI_ATTR_CALL_TIME                      370                     /* extract call time */
#define DCI_ATTR_ECONTEXT_ID                    371                     /* execution-id context */
#define DCI_ATTR_ECONTEXT_SEQ                   372                     /*execution-id sequence num */

/*---------------- Describe Handle Parameter Attribute Values ---------------*/

/* OCI_ATTR_CURSOR_COMMIT_BEHAVIOR */
#define DCI_CURSOR_OPEN                         0
#define DCI_CURSOR_CLOSED                       1

/* OCI_ATTR_CATALOG_LOCATION */
#define DCI_CL_START                            0
#define DCI_CL_END                              1

/* OCI_ATTR_SAVEPOINT_SUPPORT */
#define DCI_SP_SUPPORTED                        0
#define DCI_SP_UNSUPPORTED                      1

/* OCI_ATTR_NOWAIT_SUPPORT */
#define DCI_NW_SUPPORTED                        0
#define DCI_NW_UNSUPPORTED                      1

/* OCI_ATTR_AUTOCOMMIT_DDL */
#define DCI_AC_DDL                              0
#define DCI_NO_AC_DDL                           1

/* OCI_ATTR_LOCKING_MODE */
#define DCI_LOCK_IMMEDIATE                      0
#define DCI_LOCK_DELAYED                        1

/* ------------------- Instance type attribute values -----------------------*/
#define DCI_INSTANCE_TYPE_UNKNOWN               0
#define DCI_INSTANCE_TYPE_RDBMS                 1
#define DCI_INSTANCE_TYPE_OSM                   2

/*---------------------------------------------------------------------------*/

/*---------------------------OCIPasswordChange-------------------------------*/
#define DCI_AUTH                                0x08                    /* Change the password but do not login */

/*------------------------Other Constants------------------------------------*/
#define DCI_MAX_FNS                             100                     /* max number of OCI Functions */
#define DCI_SQLSTATE_SIZE                       5
#define DCI_ERROR_MAXMSG_SIZE                   1024                    /* max size of an error message */
#define DCI_LOBMAXSIZE                          MINUB4MAXVAL            /* maximum lob data size */
#define DCI_ROWID_LEN                           23
/*---------------------------------------------------------------------------*/

/*------------------------ Fail Over Events ---------------------------------*/
#define DCI_FO_END                              0x00000001
#define DCI_FO_ABORT                            0x00000002
#define DCI_FO_REAUTH                           0x00000004
#define DCI_FO_BEGIN                            0x00000008
#define DCI_FO_ERROR                            0x00000010
/*---------------------------------------------------------------------------*/

/*------------------------ Fail Over Callback Return Codes ------------------*/
#define DCI_FO_RETRY                            25410
/*---------------------------------------------------------------------------*/

/*------------------------- Fail Over Types ---------------------------------*/
#define DCI_FO_NONE                             0x00000001
#define DCI_FO_SESSION                          0x00000002
#define DCI_FO_SELECT                           0x00000004
#define DCI_FO_TXNAL                            0x00000008
/*---------------------------------------------------------------------------*/

/*-----------------------Function Codes--------------------------------------*/
#define DCI_FNCODE_INITIALIZE                   1                       /* OCIInitialize */
#define DCI_FNCODE_HANDLEALLOC                  2                       /* OCIHandleAlloc */
#define DCI_FNCODE_HANDLEFREE                   3                       /* OCIHandleFree */
#define DCI_FNCODE_DESCRIPTORALLOC              4                       /* OCIDescriptorAlloc */
#define DCI_FNCODE_DESCRIPTORFREE               5                       /* OCIDescriptorFree */
#define DCI_FNCODE_ENVINIT                      6                       /* OCIEnvInit */
#define DCI_FNCODE_SERVERATTACH                 7                       /* OCIServerAttach */
#define DCI_FNCODE_SERVERDETACH                 8                       /* OCIServerDetach */
/* unused         9 */ 
#define DCI_FNCODE_SESSIONBEGIN                 10                      /* OCISessionBegin */
#define DCI_FNCODE_SESSIONEND                   11                      /* OCISessionEnd */
#define DCI_FNCODE_PASSWORDCHANGE               12                      /* OCIPasswordChange */
#define DCI_FNCODE_STMTPREPARE                  13                      /* OCIStmtPrepare */
/* unused       14- 16 */
#define DCI_FNCODE_BINDDYNAMIC                  17                      /* OCIBindDynamic */
#define DCI_FNCODE_BINDOBJECT                   18                      /* OCIBindObject */
/* 19 unused */
#define DCI_FNCODE_BINDARRAYOFSTRUCT            20                      /* OCIBindArrayOfStruct */
#define DCI_FNCODE_STMTEXECUTE                  21                      /* OCIStmtExecute */
/* unused 22-24 */
#define DCI_FNCODE_DEFINEOBJECT                 25                      /* OCIDefineObject */
#define DCI_FNCODE_DEFINEDYNAMIC                26                      /* OCIDefineDynamic */
#define DCI_FNCODE_DEFINEARRAYOFSTRUCT          27                      /* OCIDefineArrayOfStruct */
#define DCI_FNCODE_STMTFETCH                    28                      /* OCIStmtFetch */
#define DCI_FNCODE_STMTGETBIND                  29                      /* OCIStmtGetBindInfo */
/* 30, 31 unused */
#define DCI_FNCODE_DESCRIBEANY                  32                      /* OCIDescribeAny */
#define DCI_FNCODE_TRANSSTART                   33                      /* OCITransStart */
#define DCI_FNCODE_TRANSDETACH                  34                      /* OCITransDetach */
#define DCI_FNCODE_TRANSCOMMIT                  35                      /* OCITransCommit */
/* 36 unused */
#define DCI_FNCODE_ERRORGET                     37                      /* OCIErrorGet */
#define DCI_FNCODE_LOBOPENFILE                  38                      /* OCILobFileOpen */
#define DCI_FNCODE_LOBCLOSEFILE                 39                      /* OCILobFileClose */
/* 40 was LOBCREATEFILE, unused */
/* 41 was OCILobFileDelete, unused  */
#define DCI_FNCODE_LOBCOPY                      42                      /* OCILobCopy */
#define DCI_FNCODE_LOBAPPEND                    43                      /* OCILobAppend */
#define DCI_FNCODE_LOBERASE                     44                      /* OCILobErase */
#define DCI_FNCODE_LOBLENGTH                    45                      /* OCILobGetLength */
#define DCI_FNCODE_LOBTRIM                      46                      /* OCILobTrim */
#define DCI_FNCODE_LOBREAD                      47                      /* OCILobRead */
#define DCI_FNCODE_LOBWRITE                     48                      /* OCILobWrite */
/* 49 unused */
#define DCI_FNCODE_SVCCTXBREAK                  50                      /* OCIBreak */
#define DCI_FNCODE_SERVERVERSION                51                      /* OCIServerVersion */
#define DCI_FNCODE_KERBATTRSET                  52                      /* OCIKerbAttrSet */
/* unused 53 */
#define DCI_FNCODE_ATTRGET                      54                      /* OCIAttrGet */
#define DCI_FNCODE_ATTRSET                      55                      /* OCIAttrSet */
#define DCI_FNCODE_PARAMSET                     56                      /* OCIParamSet */
#define DCI_FNCODE_PARAMGET                     57                      /* OCIParamGet */
#define DCI_FNCODE_STMTGETPIECEINFO             58                      /* OCIStmtGetPieceInfo */
#define DCI_FNCODE_LDATOSVCCTX                  59                      /* OCILdaToSvcCtx */
/* 60 unused */
#define DCI_FNCODE_STMTSETPIECEINFO             61                      /* OCIStmtSetPieceInfo */
#define DCI_FNCODE_TRANSFORGET                  62                      /* OCITransForget */
#define DCI_FNCODE_TRANSPREPARE                 63                      /* OCITransPrepare */
#define DCI_FNCODE_TRANSROLLBACK                64                      /* OCITransRollback */
#define DCI_FNCODE_DEFINEBYPOS                  65                      /* OCIDefineByPos */
#define DCI_FNCODE_BINDBYPOS                    66                      /* OCIBindByPos */
#define DCI_FNCODE_BINDBYNAME                   67                      /* OCIBindByName */
#define DCI_FNCODE_LOBASSIGN                    68                      /* OCILobAssign */
#define DCI_FNCODE_LOBISEQUAL                   69                      /* OCILobIsEqual */
#define DCI_FNCODE_LOBISINIT                    70                      /* OCILobLocatorIsInit */
#define DCI_FNCODE_LOBENABLEBUFFERING           71                      /* OCILobEnableBuffering */
#define DCI_FNCODE_LOBCHARSETID                 72                      /* OCILobCharSetID */
#define DCI_FNCODE_LOBCHARSETFORM               73                      /* OCILobCharSetForm */
#define DCI_FNCODE_LOBFILESETNAME               74                      /* OCILobFileSetName */
#define DCI_FNCODE_LOBFILEGETNAME               75                      /* OCILobFileGetName */
#define DCI_FNCODE_LOGON                        76                      /* OCILogon */
#define DCI_FNCODE_LOGOFF                       77                      /* OCILogoff */
#define DCI_FNCODE_LOBDISABLEBUFFERING          78                      /* OCILobDisableBuffering */
#define DCI_FNCODE_LOBFLUSHBUFFER               79                      /* OCILobFlushBuffer */
#define DCI_FNCODE_LOBLOADFROMFILE              80                      /* OCILobLoadFromFile */
#define DCI_FNCODE_LOBOPEN                      81                      /* OCILobOpen */
#define DCI_FNCODE_LOBCLOSE                     82                      /* OCILobClose */
#define DCI_FNCODE_LOBISOPEN                    83                      /* OCILobIsOpen */
#define DCI_FNCODE_LOBFILEISOPEN                84                      /* OCILobFileIsOpen */
#define DCI_FNCODE_LOBFILEEXISTS                85                      /* OCILobFileExists */
#define DCI_FNCODE_LOBFILECLOSEALL              86                      /* OCILobFileCloseAll */
#define DCI_FNCODE_LOBCREATETEMP                87                      /* OCILobCreateTemporary */
#define DCI_FNCODE_LOBFREETEMP                  88                      /* OCILobFreeTemporary */
#define DCI_FNCODE_LOBISTEMP                    89                      /* OCILobIsTemporary */
#define DCI_FNCODE_AQENQ                        90                      /* OCIAQEnq */
#define DCI_FNCODE_AQDEQ                        91                      /* OCIAQDeq */
#define DCI_FNCODE_RESET                        92                      /* OCIReset */
#define DCI_FNCODE_SVCCTXTOLDA                  93                      /* OCISvcCtxToLda */
#define DCI_FNCODE_LOBLOCATORASSIGN             94                      /* OCILobLocatorAssign */
#define DCI_FNCODE_UBINDBYNAME                  95
#define DCI_FNCODE_AQLISTEN                     96                      /* OCIAQListen */
#define DCI_FNCODE_SVC2HST                      97                      /* reserved */
#define DCI_FNCODE_SVCRH                        98                      /* reserved */
/* 97 and 98 are reserved for Oracle internal use */
#define DCI_FNCODE_TRANSMULTIPREPARE            99                      /* OCITransMultiPrepare */
#define DCI_FNCODE_CPOOLCREATE                  100                     /* OCIConnectionPoolCreate */
#define DCI_FNCODE_CPOOLDESTROY                 101                     /* OCIConnectionPoolDestroy */
#define DCI_FNCODE_LOGON2                       102                     /* OCILogon2 */
#define DCI_FNCODE_ROWIDTOCHAR                  103                     /* OCIRowidToChar */
#define DCI_FNCODE_SPOOLCREATE                  104                     /* OCISessionPoolCreate */
#define DCI_FNCODE_SPOOLDESTROY                 105                     /* OCISessionPoolDestroy */
#define DCI_FNCODE_SESSIONGET                   106                     /* OCISessionGet */
#define DCI_FNCODE_SESSIONRELEASE               107                     /* OCISessionRelease */
#define DCI_FNCODE_STMTPREPARE2                 108                     /* OCIStmtPrepare2 */
#define DCI_FNCODE_STMTRELEASE                  109                     /* OCIStmtRelease */
#define DCI_FNCODE_AQENQARRAY                   110                     /* OCIAQEnqArray */
#define DCI_FNCODE_AQDEQARRAY                   111                     /* OCIAQDeqArray */
#define DCI_FNCODE_LOBCOPY2                     112                     /* OCILobCopy2 */
#define DCI_FNCODE_LOBERASE2                    113                     /* OCILobErase2 */
#define DCI_FNCODE_LOBLENGTH2                   114                     /* OCILobGetLength2 */
#define DCI_FNCODE_LOBLOADFROMFILE2             115                     /* OCILobLoadFromFile2 */
#define DCI_FNCODE_LOBREAD2                     116                     /* OCILobRead2 */
#define DCI_FNCODE_LOBTRIM2                     117                     /* OCILobTrim2 */
#define DCI_FNCODE_LOBWRITE2                    118                     /* OCILobWrite2 */
#define DCI_FNCODE_LOBGETSTORAGELIMIT           119                     /* OCILobGetStorageLimit */
#define DCI_FNCODE_MAXFCN                       119                     /* maximum OCI function code */
/*---------------------------------------------------------------------------*/

/*-----------------------Handle Definitions----------------------------------*/
typedef struct DCIEnv           DCIEnv;            /* OCI environment handle */
typedef struct DCIError         DCIError;                /* OCI error handle */
typedef struct DCISvcCtx        DCISvcCtx;             /* OCI service handle */
typedef struct DCIStmt          DCIStmt;             /* OCI statement handle */
typedef struct DCIBind          DCIBind;                  /* OCI bind handle */
typedef struct DCIDefine        DCIDefine;              /* OCI Define handle */
typedef struct DCIDescribe      DCIDescribe;          /* OCI Describe handle */
typedef struct DCIServer        DCIServer;              /* OCI Server handle */
typedef struct DCISession       DCISession;     /* OCI Authentication handle */
typedef struct DCIComplexObject DCIComplexObject;          /* OCI COR handle */
typedef struct DCITrans         DCITrans;          /* OCI Transaction handle */
typedef struct DCISecurity      DCISecurity;          /* OCI Security handle */
typedef struct DCISubscription  DCISubscription;      /* subscription handle */

typedef struct DCICPool         DCICPool;          /* connection pool handle */
typedef struct DCISPool         DCISPool;             /* session pool handle */
typedef struct DCIAuthInfo      DCIAuthInfo;                  /* auth handle */
typedef struct DCIThreadMutex   DCIThreadMutex;
typedef struct DCIAdmin         DCIAdmin;

/* OCIThread Key for Thread-Specific Data */
typedef struct DCIThreadKey     DCIThreadKey;
typedef struct DCIThreadHandle  DCIThreadHandle;

/* OCIThread Thread ID */
typedef struct DCIThreadId      DCIThreadId;

typedef void (*DCIThreadKeyDestFunc)(void*);

/*-----------------------Descriptor Definitions------------------------------*/
typedef struct DCISnapshot          DCISnapshot;            /* OCI snapshot descriptor */
typedef struct DCIResult            DCIResult;              /* OCI Result Set Descriptor */
typedef struct DCILobLocator        DCILobLocator;          /* OCI Lob Locator descriptor */
typedef struct DCIParam             DCIParam;               /* OCI PARameter descriptor */

/* OCI COR descriptor */
typedef struct DCIComplexObjectComp DCIComplexObjectComp;   /* OCI COR descriptor */

typedef struct DCIRowid             DCIRowid;               /* OCI ROWID descriptor */

typedef struct DCIDateTime          DCIDateTime;            /* OCI DateTime descriptor */
typedef struct DCIInterval          DCIInterval;            /* OCI Interval descriptor */

typedef struct DCIUcb               DCIUcb;                 /* OCI User Callback descriptor */
typedef struct DCIServerDNs         DCIServerDNs;           /* OCI server DN descriptor */

typedef struct DCIRaw               DCIRaw;
typedef struct DCIString            DCIString; 

/*
 * OCIType - OCI Type Description Object 
 *
 * The contents of an 'OCIType' is private/opaque to clients.  Clients just 
 * need to declare and pass 'OCIType' pointers in to the type manage
 * functions.
 * The pointer points to the type in the object cache.  Thus, clients don't
 * need to allocate space for this type and must NEVER free the pointer to the
 * 'OCIType'.
 */

typedef struct DCIType              DCIType;

/* OCIColl - generic collection type */
typedef struct DCIColl              DCIColl;
typedef DCIColl                     DCITable;

/* OCIIter - collection iterator */
typedef struct DCIIter              DCIIter;

struct DCIIOV
{
    void     *bfp;                            /* The Pointer to the data buffer */
    dub4       bfl;                                 /* Length of the Data Buffer */
};
typedef struct DCIIOV DCIIOV;

enum DCIPinOpt
{
    /* 0 = uninitialized */
    DCI_PIN_DEFAULT = 1,                    /* default pin option */
    DCI_PIN_ANY     = 3,                    /* pin any copy of the object */
    DCI_PIN_RECENT  = 4,                    /* pin recent copy of the object */
    DCI_PIN_LATEST  = 5                     /* pin latest copy of the object */
};
typedef enum DCIPinOpt  DCIPinOpt;

/* The OCITypeCode type is interchangeable with the existing SQLT type
   which is a ub2 */
typedef dub2            DCITypeCode;

/*----------------------- GET OPTIONS FOR TDO  ------------------------------*/
enum DCITypeGetOpt
{
    DCI_TYPEGET_HEADER,
    /* load only the header portion of the TDO when getting type */
    DCI_TYPEGET_ALL       /* load all attribute and method descriptors as well */
};
typedef enum DCITypeGetOpt  DCITypeGetOpt;

typedef dub1                DCIObjectPropId;

/*------------------------- OBJECT REFERENCE (REF) --------------------------*/
typedef struct DCIRef       DCIRef;

/*-------------------------- AQ Descriptors ---------------------------------*/
typedef struct DCIAQEnqOptions      DCIAQEnqOptions; /* AQ Enqueue Options hdl */
typedef struct DCIAQDeqOptions      DCIAQDeqOptions; /* AQ Dequeue Options hdl */
typedef struct DCIAQMsgProperties   DCIAQMsgProperties;  /* AQ Mesg Properties */
typedef struct DCIAQAgent           DCIAQAgent;         /* AQ Agent descriptor */
typedef struct DCIAQNfyDescriptor   DCIAQNfyDescriptor;   /* AQ Nfy descriptor */
typedef struct DCIAQSignature       DCIAQSignature;            /* AQ Siganture */
/*---------------------------------------------------------------------------*/

/* Lob typedefs for Pro*C */
typedef struct DCILobLocator        DCIClobLocator;    /* OCI Character LOB Locator */
typedef struct DCILobLocator        DCIBlobLocator;       /* OCI Binary LOB Locator */
typedef struct DCILobLocator        DCIBFileLocator; /* OCI Binary LOB File Locator */
/*---------------------------------------------------------------------------*/

/* Undefined value for tz in interval types*/
#define DCI_INTHR_UNK               24

/* These defined adjustment values */
#define DCI_ADJUST_UNK              10
#define DCI_ORACLE_DATE             0
#define DCI_ANSI_DATE               1

/*------------------------ Lob-specific Definitions -------------------------*/

/*
 * ociloff - OCI Lob OFFset
 *
 * The offset in the lob data.  The offset is specified in terms of bytes for
 * BLOBs and BFILes.  Character offsets are used for CLOBs, NCLOBs.
 * The maximum size of internal lob data is 4 gigabytes.  FILE LOB 
 * size is limited by the operating system.
 */
typedef dub4                        DCILobOffset;

/*
 * ocillen - OCI Lob LENgth (of lob data)
 *
 * Specifies the length of lob data in bytes for BLOBs and BFILes and in 
 * characters for CLOBs, NCLOBs.  The maximum length of internal lob
 * data is 4 gigabytes.  The length of FILE LOBs is limited only by the
 * operating system.
 */
typedef dub4                        DCILobLength;

/*
 * ocilmo - OCI Lob open MOdes
 *
 * The mode specifies the planned operations that will be performed on the
 * FILE lob data.  The FILE lob can be opened in read-only mode only.
 * 
 * In the future, we may include read/write, append and truncate modes.  Append
 * is equivalent to read/write mode except that the FILE is positioned for
 * writing to the end.  Truncate is equivalent to read/write mode except that
 * the FILE LOB data is first truncated to a length of 0 before use.
 */
enum DCILobMode
{
    DCI_LOBMODE_READONLY = 1,           /* read-only */
    DCI_LOBMODE_READWRITE = 2           /* read_write for internal lobs only */
};
typedef enum DCILobMode DCILobMode;

/*--------------------------- OBJECT LOCK OPTION ----------------------------*/
enum DCILockOpt
{
    /* 0 = uninitialized */
    DCI_LOCK_NONE       = 1,        /* null (same as no lock) */
    DCI_LOCK_X          = 2,        /* exclusive lock */
    DCI_LOCK_X_NOWAIT   = 3         /* exclusive lock, do not wait  */
};
typedef enum DCILockOpt DCILockOpt;

/*------------------------ TYPE ENCAPSULTATION LEVEL ------------------------*/
enum DCITypeEncap
{
    /* 0 = uninitialized */
    DCI_TYPEENCAP_PRIVATE,          /* private: only internally visible */
    DCI_TYPEENCAP_PUBLIC            /* public: visible to both internally and externally */
};
typedef enum DCITypeEncap DCITypeEncap;

/*--------------------------- TYPE PARAMETER MODE ---------------------------*/
enum DCITypeParamMode
{
    /* PL/SQL starts this from 0 */
    DCI_TYPEPARAM_IN = 0,                                                /* in */
    DCI_TYPEPARAM_OUT,                                                  /* out */
    DCI_TYPEPARAM_INOUT,                                             /* in-out */
    DCI_TYPEPARAM_BYREF,              /* call by reference (implicitly in-out) */
    DCI_TYPEPARAM_OUTNCPY,                         /* OUT with NOCOPY modifier */
    DCI_TYPEPARAM_INOUTNCPY                     /* IN OUT with NOCOPY modifier */
};
typedef enum DCITypeParamMode DCITypeParamMode;

#define DCI_ATTR_PURITY_DEFAULT         0x00
#define DCI_ATTR_PURITY_NEW             0x01
#define DCI_ATTR_PURITY_SELF            0x02
/*-------------------------- OBJECT Duration --------------------------------*/

typedef dub2                            DCIDuration;

#define DCI_DURATION_INVALID            0xFFFF                                  /* Invalid duration */
#define DCI_DURATION_BEGIN              (DCIDuration)10
/* beginning sequence of duration */
#define DCI_DURATION_NULL               (DCIDuration)(DCI_DURATION_BEGIN-1)
/* null duration */
#define DCI_DURATION_DEFAULT            (DCIDuration)(DCI_DURATION_BEGIN-2)     /* default */
#define DCI_DURATION_USER_CALLBACK      (DCIDuration)(DCI_DURATION_BEGIN-3)
#define DCI_DURATION_NEXT               (DCIDuration)(DCI_DURATION_BEGIN-4)
/* next special duration */
#define DCI_DURATION_SESSION            (DCIDuration)(DCI_DURATION_BEGIN)
/* the end of user session */
#define DCI_DURATION_TRANS              (DCIDuration)(DCI_DURATION_BEGIN+1)
/* the end of user transaction */
/*---------------------------------------------------------------------------*/
enum DCIRefreshOpt
{
    /* 0 = uninitialized */
    DCI_REFRESH_LOADED = 1        /* refresh objects loaded in the transaction */
};
typedef enum DCIRefreshOpt          DCIRefreshOpt; 

/* OCI representation of XMLType */
typedef struct DCIXMLType           DCIXMLType;

/* OCI representation of OCIDomDocument */
typedef struct DCIDOMDocument       DCIDOMDocument;

/* OCI representation of OCIExtProcContext */
typedef struct DCIExtProcContext    DCIExtProcContext;
/*----------------------------Piece Definitions------------------------------*/

/* if ocidef.h is being included in the app, ocidef.h should precede oci.h */

/* 
 * since clients may  use oci.h, ocidef.h and ocidfn.h the following defines
 * need to be guarded, usually internal clients
 */
#ifndef DCI_FLAGS
#define DCI_FLAGS
#define DCI_ONE_PIECE                   0                   /* one piece */
#define DCI_FIRST_PIECE                 1                   /* the first piece */
#define DCI_NEXT_PIECE                  2                   /* the next of many pieces */
#define DCI_LAST_PIECE                  3                   /* the last piece */
#endif

/*---------------------------------------------------------------------------*/

/*--------------------------- OBJECT INDICATOR ------------------------------*/

typedef dsb2        DCIInd;
/*
 * OCIInd -- a variable of this type contains (null) indicator information
 */

#define DCI_IND_NOTNULL                 (DCIInd)0                       /* not NULL */
#define DCI_IND_NULL                    (DCIInd)(-1)                    /* NULL */
#define DCI_IND_BADNULL                 (DCIInd)(-2)                    /* BAD NULL */
#define DCI_IND_NOTNULLABLE             (DCIInd)(-3)                    /* not NULLable */

/*--------------------------- FILE open modes -------------------------------*/
#define DCI_FILE_READONLY               1                               /* readonly mode open for FILE types */
/*---------------------------------------------------------------------------*/
/*--------------------------- LOB open modes --------------------------------*/
#define DCI_LOB_READONLY                1                               /* readonly mode open for ILOB types */
#define DCI_LOB_READWRITE               2                               /* read write mode open for ILOBs */
#define DCI_LOB_WRITEONLY               3                               /* Writeonly mode open for ILOB types*/
#define DCI_LOB_APPENDONLY              4                               /* Appendonly mode open for ILOB types */
#define DCI_LOB_FULLOVERWRITE           5                               /* Completely overwrite ILOB */
#define DCI_LOB_FULLREAD                6                               /* Doing a Full Read of ILOB */

/*----------------------- LOB Buffering Flush Flags -------------------------*/
#define DCI_LOB_BUFFER_FREE             1
#define DCI_LOB_BUFFER_NOFREE           2
/*---------------------------------------------------------------------------*/

/*---------------------------LOB Option Types -------------------------------*/
#define DCI_LOB_OPT_COMPRESS            1                               /* SECUREFILE Compress */
#define DCI_LOB_OPT_ENCRYPT             2                               /* SECUREFILE Encrypt */
#define DCI_LOB_OPT_DEDUPLICATE         4                               /* SECUREFILE Deduplicate */
#define DCI_LOB_OPT_ALLOCSIZE           8                               /* SECUREFILE Allocation Size */
#define DCI_LOB_OPT_CONTENTTYPE         16                              /* SECUREFILE Content Type */
#define DCI_LOB_OPT_MODTIME             32                              /* SECUREFILE Modification Time */

/*------------------------   LOB Option Values ------------------------------*/
/* Compression */
#define DCI_LOB_COMPRESS_OFF            0                               /* Compression off */
#define DCI_LOB_COMPRESS_ON             1                               /* Compression on */

/* Encryption */
#define DCI_LOB_ENCRYPT_OFF             0                               /* Encryption Off */
#define DCI_LOB_ENCRYPT_ON              2                               /* Encryption On */

/* Deduplciate */
#define DCI_LOB_DEDUPLICATE_OFF         0                               /* Deduplicate Off */
#define DCI_LOB_DEDUPLICATE_ON          4                               /* Deduplicate Lobs */

/*--------------------------- OCI Statement Types ---------------------------*/
#define DCI_STMT_UNKNOWN                0                               /* Unknown statement */
#define DCI_STMT_SELECT                 1                               /* select statement */
#define DCI_STMT_UPDATE                 2                               /* update statement */
#define DCI_STMT_DELETE                 3                               /* delete statement */
#define DCI_STMT_INSERT                 4                               /* Insert Statement */
#define DCI_STMT_CREATE                 5                               /* create statement */
#define DCI_STMT_DROP                   6                               /* drop statement */
#define DCI_STMT_ALTER                  7                               /* alter statement */
#define DCI_STMT_BEGIN                  8                               /* begin ... (pl/sql statement)*/
#define DCI_STMT_DECLARE                9                               /* declare .. (pl/sql statement ) */
#define DCI_STMT_CALL                   10                              /* corresponds to kpu call */
#define DCI_STMT_MERGE                  16                              /* merge statement */
/*---------------------------------------------------------------------------*/

/*--------------------------- OCI Parameter Types ---------------------------*/
#define DCI_PTYPE_UNK                   0                               /* unknown   */
#define DCI_PTYPE_TABLE                 1                               /* table     */
#define DCI_PTYPE_VIEW                  2                               /* view      */
#define DCI_PTYPE_PROC                  3                               /* procedure */
#define DCI_PTYPE_FUNC                  4                               /* function  */
#define DCI_PTYPE_PKG                   5                               /* package   */
#define DCI_PTYPE_TYPE                  6                               /* user-defined type */
#define DCI_PTYPE_SYN                   7                               /* synonym   */
#define DCI_PTYPE_SEQ                   8                               /* sequence  */
#define DCI_PTYPE_COL                   9                               /* column    */
#define DCI_PTYPE_ARG                   10                              /* argument  */
#define DCI_PTYPE_LIST                  11                              /* list      */
#define DCI_PTYPE_TYPE_ATTR             12                              /* user-defined type's attribute */
#define DCI_PTYPE_TYPE_COLL             13                              /* collection type's element */
#define DCI_PTYPE_TYPE_METHOD           14                              /* user-defined type's method */
#define DCI_PTYPE_TYPE_ARG              15                              /* user-defined type method's arg */
#define DCI_PTYPE_TYPE_RESULT           16                              /* user-defined type method's result */
#define DCI_PTYPE_SCHEMA                17                              /* schema */
#define DCI_PTYPE_DATABASE              18                              /* database */
#define DCI_PTYPE_RULE                  19                              /* rule */
#define DCI_PTYPE_RULE_SET              20                              /* rule set */
#define DCI_PTYPE_EVALUATION_CONTEXT    21                              /* evaluation context */
#define DCI_PTYPE_TABLE_ALIAS           22                              /* table alias */
#define DCI_PTYPE_VARIABLE_TYPE         23                              /* variable type */
#define DCI_PTYPE_NAME_VALUE            24                              /* name value pair */

/*---------------------------------------------------------------------------*/

/*----------------------------- OCI List Types ------------------------------*/
#define DCI_LTYPE_UNK                   0                               /* unknown   */
#define DCI_LTYPE_COLUMN                1                               /* column list */
#define DCI_LTYPE_ARG_PROC              2                               /* procedure argument list */
#define DCI_LTYPE_ARG_FUNC              3                               /* function argument list */
#define DCI_LTYPE_SUBPRG                4                               /* subprogram list */
#define DCI_LTYPE_TYPE_ATTR             5                               /* type attribute */
#define DCI_LTYPE_TYPE_METHOD           6                               /* type method */
#define DCI_LTYPE_TYPE_ARG_PROC         7                               /* type method w/o result argument list */
#define DCI_LTYPE_TYPE_ARG_FUNC         8                               /* type method w/result argument list */
#define DCI_LTYPE_SCH_OBJ               9                               /* schema object list */
#define DCI_LTYPE_DB_SCH                10                              /* database schema list */
#define DCI_LTYPE_TYPE_SUBTYPE          11                              /* subtype list */
#define DCI_LTYPE_TABLE_ALIAS           12                              /* table alias list */
#define DCI_LTYPE_VARIABLE_TYPE         13                              /* variable type list */
#define DCI_LTYPE_NAME_VALUE            14                              /* name value list */

/*---------------------------------------------------------------------------*/

/*-------------------------- Memory Cartridge Services ---------------------*/
#define DCI_MEMORY_CLEARED              1
/*-------------------------- Pickler Cartridge Services ---------------------*/
typedef struct DCIPicklerTdsCtx         DCIPicklerTdsCtx;
typedef struct DCIPicklerTds            DCIPicklerTds;
typedef struct DCIPicklerImage          DCIPicklerImage;
typedef struct DCIPicklerFdo            DCIPicklerFdo;
typedef dub4                            DCIPicklerTdsElement;

typedef struct DCIAnyData               DCIAnyData;
typedef struct DCIAnyDataSet            DCIAnyDataSet;
typedef struct DCIAnyDataCtx            DCIAnyDataCtx;

/*---------------------------------------------------------------------------*/

/*--------------------------- User Callback Constants -----------------------*/
#define DCI_UCBTYPE_ENTRY               1                          /* entry callback */
#define DCI_UCBTYPE_EXIT                2                           /* exit callback */
#define DCI_UCBTYPE_REPLACE             3                    /* replacement callback */
/*---------------------------------------------------------------------------*/

/*--------------------- NLS service type and constance ----------------------*/
#define DCI_NLS_DAYNAME1                1                       /* Native name for Monday */
#define DCI_NLS_DAYNAME2                2                       /* Native name for Tuesday */
#define DCI_NLS_DAYNAME3                3                       /* Native name for Wednesday */
#define DCI_NLS_DAYNAME4                4                       /* Native name for Thursday */
#define DCI_NLS_DAYNAME5                5                       /* Native name for Friday */
#define DCI_NLS_DAYNAME6                6                       /* Native name for for Saturday */
#define DCI_NLS_DAYNAME7                7                       /* Native name for for Sunday */
#define DCI_NLS_ABDAYNAME1              8                       /* Native abbreviated name for Monday */
#define DCI_NLS_ABDAYNAME2              9                       /* Native abbreviated name for Tuesday */
#define DCI_NLS_ABDAYNAME3              10                      /* Native abbreviated name for Wednesday */
#define DCI_NLS_ABDAYNAME4              11                      /* Native abbreviated name for Thursday */
#define DCI_NLS_ABDAYNAME5              12                      /* Native abbreviated name for Friday */
#define DCI_NLS_ABDAYNAME6              13                      /* Native abbreviated name for for Saturday */
#define DCI_NLS_ABDAYNAME7              14                      /* Native abbreviated name for for Sunday */
#define DCI_NLS_MONTHNAME1              15                      /* Native name for January */
#define DCI_NLS_MONTHNAME2              16                      /* Native name for February */
#define DCI_NLS_MONTHNAME3              17                      /* Native name for March */
#define DCI_NLS_MONTHNAME4              18                      /* Native name for April */
#define DCI_NLS_MONTHNAME5              19                      /* Native name for May */
#define DCI_NLS_MONTHNAME6              20                      /* Native name for June */
#define DCI_NLS_MONTHNAME7              21                      /* Native name for July */
#define DCI_NLS_MONTHNAME8              22                      /* Native name for August */
#define DCI_NLS_MONTHNAME9              23                      /* Native name for September */
#define DCI_NLS_MONTHNAME10             24                      /* Native name for October */
#define DCI_NLS_MONTHNAME11             25                      /* Native name for November */
#define DCI_NLS_MONTHNAME12             26                      /* Native name for December */
#define DCI_NLS_ABMONTHNAME1            27                      /* Native abbreviated name for January */
#define DCI_NLS_ABMONTHNAME2            28                      /* Native abbreviated name for February */
#define DCI_NLS_ABMONTHNAME3            29                      /* Native abbreviated name for March */
#define DCI_NLS_ABMONTHNAME4            30                      /* Native abbreviated name for April */
#define DCI_NLS_ABMONTHNAME5            31                      /* Native abbreviated name for May */
#define DCI_NLS_ABMONTHNAME6            32                      /* Native abbreviated name for June */
#define DCI_NLS_ABMONTHNAME7            33                      /* Native abbreviated name for July */
#define DCI_NLS_ABMONTHNAME8            34                      /* Native abbreviated name for August */
#define DCI_NLS_ABMONTHNAME9            35                      /* Native abbreviated name for September */
#define DCI_NLS_ABMONTHNAME10           36                      /* Native abbreviated name for October */
#define DCI_NLS_ABMONTHNAME11           37                      /* Native abbreviated name for November */
#define DCI_NLS_ABMONTHNAME12           38                      /* Native abbreviated name for December */
#define DCI_NLS_YES                     39                      /* Native string for affirmative response */
#define DCI_NLS_NO                      40                      /* Native negative response */
#define DCI_NLS_AM                      41                      /* Native equivalent string of AM */
#define DCI_NLS_PM                      42                      /* Native equivalent string of PM */
#define DCI_NLS_AD                      43                      /* Native equivalent string of AD */
#define DCI_NLS_BC                      44                      /* Native equivalent string of BC */
#define DCI_NLS_DECIMAL                 45                      /* decimal character */
#define DCI_NLS_GROUP                   46                      /* group separator */
#define DCI_NLS_DEBIT                   47                      /* Native symbol of debit */
#define DCI_NLS_CREDIT                  48                      /* Native sumbol of credit */
#define DCI_NLS_DATEFORMAT              49                      /* Oracle date format */
#define DCI_NLS_INT_CURRENCY            50                      /* International currency symbol */
#define DCI_NLS_LOC_CURRENCY            51                      /* Locale currency symbol */
#define DCI_NLS_LANGUAGE                52                      /* Language name */
#define DCI_NLS_ABLANGUAGE              53                      /* Abbreviation for language name */
#define DCI_NLS_TERRITORY               54                      /* Territory name */
#define DCI_NLS_CHARACTER_SET           55                      /* Character set name */
#define DCI_NLS_LINGUISTIC_NAME         56                      /* Linguistic name */
#define DCI_NLS_CALENDAR                57                      /* Calendar name */
#define DCI_NLS_DUAL_CURRENCY           78                      /* Dual currency symbol */
#define DCI_NLS_WRITINGDIR              79                      /* Language writing direction */
#define DCI_NLS_ABTERRITORY             80                      /* Territory Abbreviation */
#define DCI_NLS_DDATEFORMAT             81                      /* Oracle default date format */
#define DCI_NLS_DTIMEFORMAT             82                      /* Oracle default time format */
#define DCI_NLS_SFDATEFORMAT            83                      /* Local string formatted date format */
#define DCI_NLS_SFTIMEFORMAT            84                      /* Local string formatted time format */
#define DCI_NLS_NUMGROUPING             85                      /* Number grouping fields */
#define DCI_NLS_LISTSEP                 86                      /* List separator */
#define DCI_NLS_MONDECIMAL              87                      /* Monetary decimal character */
#define DCI_NLS_MONGROUP                88                      /* Monetary group separator */
#define DCI_NLS_MONGROUPING             89                      /* Monetary grouping fields */
#define DCI_NLS_INT_CURRENCYSEP         90                      /* International currency separator */
#define DCI_NLS_CHARSET_MAXBYTESZ       91                      /* Maximum character byte size      */
#define DCI_NLS_CHARSET_FIXEDWIDTH      92                      /* Fixed-width charset byte size    */
#define DCI_NLS_CHARSET_ID              93                      /* Character set id */
#define DCI_NLS_NCHARSET_ID             94                      /* NCharacter set id */
#define DCI_NLS_MAXBUFSZ                100                     /* Max buffer size may need for OCINlsGetInfo */

#define DCI_NLS_BINARY                  0x1             /* for the binary comparison */
#define DCI_NLS_LINGUISTIC              0x2             /* for linguistic comparison */
#define DCI_NLS_CASE_INSENSITIVE        0x10            /* for case-insensitive comparison */

#define DCI_NLS_UPPERCASE               0x20               /* convert to uppercase */
#define DCI_NLS_LOWERCASE               0x40               /* convert to lowercase */

#define DCI_NLS_CS_IANA_TO_ORA          0   /* Map charset name from IANA to Oracle */
#define DCI_NLS_CS_ORA_TO_IANA          1   /* Map charset name from Oracle to IANA */
#define DCI_NLS_LANG_ISO_TO_ORA         2   /* Map language name from ISO to Oracle */
#define DCI_NLS_LANG_ORA_TO_ISO         3   /* Map language name from Oracle to ISO */
#define DCI_NLS_TERR_ISO_TO_ORA         4   /* Map territory name from ISO to Oracle*/
#define DCI_NLS_TERR_ORA_TO_ISO         5   /* Map territory name from Oracle to ISO*/
#define DCI_NLS_TERR_ISO3_TO_ORA        6   /* Map territory name from 3-letter ISO */
/* abbreviation to Oracle               */
#define DCI_NLS_TERR_ORA_TO_ISO3        7   /* Map territory name from Oracle to    */
/* 3-letter ISO abbreviation            */

typedef struct DCIMsg                   DCIMsg;
typedef dub4                            DCIWchar;

#define DCI_XMLTYPE_CREATE_OCISTRING    1
#define DCI_XMLTYPE_CREATE_CLOB         2
#define DCI_XMLTYPE_CREATE_BLOB         3

/*------------------------- Kerber Authentication Modes ---------------------*/
#define DCI_KERBCRED_PROXY              1       /* Apply Kerberos Creds for Proxy */
#define DCI_KERBCRED_CLIENT_IDENTIFIER  2       /*Apply Creds for Secure Client ID */
/*--------------------------------------------------------------------------- 
                     PRIVATE TYPES AND CONSTANTS 
  ---------------------------------------------------------------------------*/
struct DCITime
{
    dub1 OCITimeHH;              /* hours; range is 0 <= hours <=23 */
    dub1 OCITimeMI;              /* minutes; range is 0 <= minutes <= 59 */
    dub1 OCITimeSS;              /* seconds; range is 0 <= seconds <= 59 */
};
typedef struct DCITime  DCITime;
/* 
 * OCITime - OCI TiMe portion of date
 *
 * This structure should be treated as an opaque structure as the format
 * of this structure may change. Use OCIDateGetTime/OCIDateSetTime 
 * to manipulate time portion of OCIDate.
 */

struct DCIDate
{
    dsb2       OCIDateYYYY;         /* gregorian year; range is -4712 <= year <= 9999 */
    dub1       OCIDateMM;           /* month; range is 1 <= month < 12 */
    dub1       OCIDateDD;           /* day; range is 1 <= day <= 31 */
    DCITime   OCIDateTime;          /* time */
};
typedef struct DCIDate  DCIDate;
 
/*--------------------------------------------------------------------------- 
                          PRIVATE FUNCTIONS 
  ---------------------------------------------------------------------------*/
struct Dcda_head {
    dsb2            v2_rc;
    dub2            ft;
    dub4            rpc;
    dub2            peo;
    dub1            fc;
    dub1            rcs1;
    dub2            rc;
    dub1            wrn;
    dub1            rcs2;
    dsword          rcs3;
    struct {
        struct {
           dub4     rcs4;
           dub2     rcs5;
           dub1     rcs6;
        } rd;
        dub4        rcs7;
        dub2        rcs8;
    } rid;
    dsword          ose;
    dub1            chk;
    dvoid*          rcsp;
};

/*
** Size of HDA area:
** 512 for 64 bit arquitectures
** 256 for 32 bit arquitectures
*/

#if defined(SS_64BIT_SERVER) || defined(__64BIT__)
#define HDA_SIZE 512
#else
#define HDA_SIZE 256
#endif

#if defined(SS_64BIT_SERVER) || defined(__64BIT__)
#define CDA_SIZE 88
#else
#define CDA_SIZE 64
#endif

/* the real CDA, padded to CDA_SIZE bytes in size */
struct Dcda_def {
    dsb2            v2_rc;                                  /* V2 return code */
    dub2            ft;                                     /* SQL function type */
    dub4            rpc;                                    /* rows processed count */
    dub2            peo;                                    /* parse error offset */
    dub1            fc;                                     /* OCI function code */
    dub1            rcs1;                                   /* filler area */
    dub2            rc;                                     /* V7 return code */
    dub1            wrn;                                    /* warning flags */
    dub1            rcs2;                                   /* reserved */
    dsword          rcs3;                                   /* reserved */
    struct {                                                /* rowid structure */
        struct {
           dub4     rcs4;
           dub2     rcs5;
           dub1     rcs6;
        } rd;
        dub4        rcs7;
        dub2        rcs8;
    } rid;
    dsword          ose;                                                /* OSD dependent error */
    dub1            chk;
    dvoid*          rcsp;                                               /* pointer to reserved area */
    dub1            rcs9[CDA_SIZE - sizeof (struct Dcda_head)];          /* filler */
};

typedef struct Dcda_def DCda_Def;

/* the logon data area (LDA)
   is the same shape as the CDA */
typedef struct Dcda_def DLda_Def;

/* OCI Environment Modes for opinit call */
#define OCI_EV_DEF 0                  /* default single-threaded environment */
#define OCI_EV_TSF 1                              /* thread-safe environment */

/* OCI Logon Modes for olog call */
#define OCI_LM_DEF 0                                        /* default login */
#define OCI_LM_NBL 1                                   /* non-blocking logon */

/* valuses for crsfc */
#define csrfpa                      2               /* ...OSQL */
#define csrfex                      4               /* ...OEXEC */
#define csrfbi                      6               /* ...OBIND */
#define csrfdb                      8               /* ...ODFINN */
#define csrfdi                      10              /* ...ODSRBN */
#define csrffe                      12              /* ...OFETCH */
#define csrfop                      14              /* ...OOPEN */
#define csrfcl                      16              /* ...OCLOSE */
#define csrfds                      22              /* ...ODSC */
#define csrfnm                      24              /* ...ONAME */
#define csrfp3                      26              /* ...OSQL3 */
#define csrfbr                      28              /* ...OBNDRV */
#define csrfbx                      30              /* ...OBNDRN */
#define csrfso                      34              /* ...OOPT */
#define csrfre                      36              /* ...ORESUM */
#define csrfbn                      50              /* ...OBINDN */
#define csrfca                      52              /* ..OCANCEL */
#define csrfsd                      54              /* ..OSQLD */
#define csrfef                      56              /* ..OEXFEN */
#define csrfln                      58              /* ..OFLNG */
#define csrfdp                      60              /* ..ODSCSP */
#define csrfba                      62              /* ..OBNDRA */
#define csrfbps                     63              /*..OBINDPS */
#define csrfdps                     64              /*..ODEFINPS */
#define csrfgpi                     65              /* ...OGETPI */
#define csrfspi                     66              /* ...OSETPI */

/* values for csrwrn */
#define CSRWANY  0x01                         /* there is a warning flag set */
#define CSRWTRUN 0x02                           /* a data item was truncated */
#define CSRWNVIC 0x04      /* NULL values were used in an aggregate function */
#define CSRWITCE 0x08           /* column count not equal to into list count */
#define CSRWUDNW 0x10               /* update or delete without where clause */
#define CSRWRSV0 0x20
#define CSRWROLL 0x40                                   /* rollback required */
#define CSRWRCHG 0x80       /* change after query start on select for update */

/*----- values for OCI_ATTR_DIRPATH_SKIPINDEX_METHOD attribute -----*/
#define DCI_DIRPATH_INDEX_MAINT_SKIP_UNUSABLE           2
#define DCI_DIRPATH_INDEX_MAINT_DONT_SKIP_UNUSABLE      3
#define DCI_DIRPATH_INDEX_MAINT_SKIP_ALL                4

/* values for OCI_ATTR_STATE attribute of OCIDirPathCtx */
#define DCI_DIRPATH_NORMAL                              1               /* can accept rows, last row complete */
#define DCI_DIRPATH_PARTIAL                             2               /* last row was partial */
#define DCI_DIRPATH_NOT_PREPARED                        3               /* direct path context is not prepared */

/*----- values for cflg argument to OCIDirpathColArrayEntrySet -----*/
#define DCI_DIRPATH_COL_COMPLETE                        0               /* column data is complete */
#define DCI_DIRPATH_COL_NULL                            1               /* column is null */
#define DCI_DIRPATH_COL_PARTIAL                         2               /* column data is partial */
#define DCI_DIRPATH_COL_ERROR                           3               /* column error, ignore row */

/*----- values for action parameter to OCIDirPathDataSave -----*/
#define DCI_DIRPATH_DATASAVE_SAVEONLY                   0               /* data save point only */
#define DCI_DIRPATH_DATASAVE_FINISH                     1               /* execute finishing logic */
/* save portion of input data (before space error occurred) and finish */
#define DCI_DIRPATH_DATASAVE_PARTIAL                    2

/*- OCI_ATTR_DIRPATH_EXPR_TYPE values (describes OCI_ATTR_NAME expr type) -*/
#define DCI_DIRPATH_EXPR_OBJ_CONSTR                     1               /* NAME is an object constructor */
#define DCI_DIRPATH_EXPR_SQL                            2               /* NAME is an opaque or sql function */
#define DCI_DIRPATH_EXPR_REF_TBLNAME                    3               /* NAME is table name if ref is scoped*/

/* Listing of error bits used by OCIDateCheck() */
#define DCI_DATE_INVALID_DAY                            0x1             /* Bad DAy */
#define DCI_DATE_DAY_BELOW_VALID                        0x2             /* Bad DAy Low/high bit (1=low)*/
#define DCI_DATE_INVALID_MONTH                          0x4             /* Bad MOnth */
#define DCI_DATE_MONTH_BELOW_VALID                      0x8             /* Bad MOnth Low/high bit (1=low)*/
#define DCI_DATE_INVALID_YEAR                           0x10            /* Bad YeaR */
#define DCI_DATE_YEAR_BELOW_VALID                       0x20            /* Bad YeaR Low/high bit (1=low)*/
#define DCI_DATE_INVALID_HOUR                           0x40            /* Bad HouR */
#define DCI_DATE_HOUR_BELOW_VALID                       0x80            /* Bad HouR Low/high bit (1=low)*/
#define DCI_DATE_INVALID_MINUTE                         0x100           /* Bad MiNute */
#define DCI_DATE_MINUTE_BELOW_VALID                     0x200           /* Bad MiNute Low/high bit (1=low)*/
#define DCI_DATE_INVALID_SECOND                         0x400           /* Bad SeCond */
#define DCI_DATE_SECOND_BELOW_VALID                     0x800           /* bad second Low/high bit (1=low)*/
#define DCI_DATE_DAY_MISSING_FROM_1582                  0x1000          /* Day is one of those "missing" from 1582 */
#define DCI_DATE_YEAR_ZERO                              0x2000          /* Year may not equal zero */
#define DCI_DATE_INVALID_FORMAT                         0x8000          /* Bad date format input */

typedef struct DCIDirPathCtx                DCIDirPathCtx;                  /* context */
typedef struct DCIDirPathFuncCtx            DCIDirPathFuncCtx;     /* function context */
typedef struct DCIDirPathColArray           DCIDirPathColArray;        /* column array */
typedef struct DCIDirPathStream             DCIDirPathStream;                /* stream */
typedef struct DCIDirPathDesc               DCIDirPathDesc;  /* direct path descriptor */

typedef dsb4 (*DCICallbackInBind)(dvoid *ictxp, DCIBind *bindp, dub4 iter,
                                dub4 index, dvoid **bufpp, dub4 *alenp,
                                dub1 *piecep, dvoid **indp);

typedef dsb4 (*DCICallbackOutBind)(dvoid *octxp, DCIBind *bindp, dub4 iter,
                                dub4 index, dvoid **bufpp, dub4 **alenp,
                                dub1 *piecep, dvoid **indp,
                                dub2 **rcodep);

typedef dsb4 (*DCICallbackDefine)(dvoid *octxp, DCIDefine *defnp, dub4 iter,
                                dvoid **bufpp, dub4 **alenp, dub1 *piecep,
                                dvoid **indp, dub2 **rcodep);


/*number*/
#define DCI_NUMBER_SIZE     22
struct DCINumber
{
    dub1 OCINumberPart[DCI_NUMBER_SIZE];
};
typedef struct DCINumber    DCINumber;

#endif      //_DCI1_H

#ifdef __cplusplus
}
#endif      //__cplusplus

