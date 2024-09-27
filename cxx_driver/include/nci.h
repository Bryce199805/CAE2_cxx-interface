#ifndef _NCI_H
#define _NCI_H 

#ifdef WIN32
#ifdef  _WIN64
typedef unsigned __int64    size_t;
#else
typedef _W64 unsigned int   size_t;
#endif
#else
//#define size_t unsigned long 
#endif 


typedef unsigned short nusint;  
//typedef unsigned char nbyte; 

typedef unsigned int nulint;   
typedef nulint    ndmbool; 

#define nlint int

#ifdef WIN32
#define NCI_API   __declspec( dllexport )
#else
#define NCI_API 
#endif 

#define NCI_TYPECODE_REF         SQLT_REF        /* SQL/OTS OBJECT REFERENCE */ 
#define NCI_TYPECODE_DATE        SQLT_DAT              /* SQL DATE  OTS DATE */ 
#define NCI_TYPECODE_SIGNED8     27     /* SQL SIGNED INTEGER(8)  OTS SINT8 */ 
#define NCI_TYPECODE_SIGNED16    28    /* SQL SIGNED INTEGER(16)  OTS SINT16 */ 
#define NCI_TYPECODE_SIGNED32    29    /* SQL SIGNED INTEGER(32)  OTS SINT32 */ 
#define NCI_TYPECODE_REAL        21                /* SQL REAL  OTS SQL_REAL */ 
#define NCI_TYPECODE_DOUBLE      22  /* SQL DOUBLE PRECISION  OTS SQL_DOUBLE */ 
#define NCI_TYPECODE_FLOAT       SQLT_FLT      /* SQL FLOAT(P)  OTS FLOAT(P) */ 
#define NCI_TYPECODE_NUMBER      SQLT_NUM/* SQL NUMBER(P S)  OTS NUMBER(P S) */ 
#define NCI_TYPECODE_DECIMAL     SQLT_PDN    /* SQL DECIMAL(P S)  OTS DECIMAL(P S) */ 
#define NCI_TYPECODE_UNSIGNED8   SQLT_BIN    /* SQL UNSIGNED INTEGER(8)  OTS UINT8 */ 
#define NCI_TYPECODE_UNSIGNED16  25  /* SQL UNSIGNED INTEGER(16)  OTS UINT16 */ 
#define NCI_TYPECODE_UNSIGNED32  26  /* SQL UNSIGNED INTEGER(32)  OTS UINT32 */ 
#define NCI_TYPECODE_BFLOAT      SQLT_IBFLOAT       /* Binary float */  
#define NCI_TYPECODE_BDOUBLE     SQLT_IBDOUBLE  /* Binary double */ 
#define NCI_TYPECODE_OCTET       245                   /* SQL ???  OTS OCTET */ 
#define NCI_TYPECODE_SMALLINT    246           /* SQL SMALLINT  OTS SMALLINT */ 
#define NCI_TYPECODE_INTEGER     SQLT_INT        /* SQL INTEGER  OTS INTEGER */ 
#define NCI_TYPECODE_RAW         SQLT_LVB          /* SQL RAW(N)  OTS RAW(N) */ 
#define NCI_TYPECODE_PTR         32              /* SQL POINTER  OTS POINTER */ 
#define NCI_TYPECODE_VARCHAR2    SQLT_VCS      /* SQL VARCHAR2(N)  OTS SQL_VARCHAR2(N) */ 
#define NCI_TYPECODE_CHAR        SQLT_AFC    /* SQL CHAR(N)  OTS SQL_CHAR(N) */ 
#define NCI_TYPECODE_VARCHAR     SQLT_CHR         /* SQL VARCHAR(N)  OTS SQL_VARCHAR(N) */ 
#define NCI_TYPECODE_MLSLABEL    SQLT_LAB                    /* OTS MLSLABEL */ 
#define NCI_TYPECODE_VARRAY      247         /* SQL VARRAY  OTS PAGED VARRAY */ 
#define NCI_TYPECODE_TABLE       248              /* SQL TABLE  OTS MULTISET */ 
#define NCI_TYPECODE_OBJECT      SQLT_NTY       /* SQL/OTS NAMED OBJECT TYPE */  
#define NCI_TYPECODE_OPAQUE       58                /*  SQL/OTS Opaque Types */ 
#define NCI_TYPECODE_NAMEDCOLLECTION  SQLT_NCO /* SQL/OTS NAMED COLLECTION TYPE */ 
#define NCI_TYPECODE_BLOB        SQLT_BLOB    /* SQL/OTS BINARY LARGE OBJECT */ 
#define NCI_TYPECODE_BFILE       SQLT_BFILE    /* SQL/OTS BINARY FILE OBJECT */ 
#define NCI_TYPECODE_CLOB        SQLT_CLOB /* SQL/OTS CHARACTER LARGE OBJECT */ 
#define NCI_TYPECODE_CFILE       SQLT_CFILE /* SQL/OTS CHARACTER FILE OBJECT */ 

/* the following are ANSI datetime datatypes added in 8.1 */
#define NCI_TYPECODE_TIME        SQLT_TIME                   /* SQL/OTS TIME */
#define NCI_TYPECODE_TIME_TZ     SQLT_TIME_TZ             /* SQL/OTS TIME_TZ */ 
#define NCI_TYPECODE_TIMESTAMP   SQLT_TIMESTAMP         /* SQL/OTS TIMESTAMP */ 
#define NCI_TYPECODE_TIMESTAMP_TZ  SQLT_TIMESTAMP_TZ /* SQL/OTS TIMESTAMP_TZ */ 

#define NCI_TYPECODE_TIMESTAMP_LTZ  SQLT_TIMESTAMP_LTZ /* TIMESTAMP_LTZ */ 

#define NCI_TYPECODE_INTERVAL_YM SQLT_INTERVAL_YM   /* SQL/OTS INTRVL YR-MON */ 
#define NCI_TYPECODE_INTERVAL_DS SQLT_INTERVAL_DS  /* SQL/OTS INTRVL DAY-SEC */ 

#define NCI_TYPECODE_OTMFIRST    228     /* first Open Type Manager typecode */ 
#define NCI_TYPECODE_OTMLAST     320                    /* last OTM typecode */ 
#define NCI_TYPECODE_SYSFIRST    228     /* first OTM system type (internal) */ 
#define NCI_TYPECODE_SYSLAST     235      /* last OTM system type (internal) */ 
#define NCI_TYPECODE_PLS_INTEGER   266     /* type code for PLS_INTEGER */ 

/* the following are PL/SQL-only internal. They should not be used */
#define NCI_TYPECODE_ITABLE      SQLT_TAB             /* PLSQL indexed table */ 
#define NCI_TYPECODE_RECORD      SQLT_REC                    /* PLSQL record */ 
#define NCI_TYPECODE_BOOLEAN     SQLT_BOL                   /* PLSQL boolean */ 


/* NOTE : The following NCHAR related codes are just short forms for saying
   NCI_TYPECODE_VARCHAR2 with a charset form of SQLCS_NCHAR. These codes are
   intended for use in the OCIAnyData API only and nowhere else. */
#define NCI_TYPECODE_NCHAR       286 
#define NCI_TYPECODE_NVARCHAR2   287 
#define NCI_TYPECODE_NCLOB       288 

/*-----------------------------  Various Modes ------------------------------*/
#define NCI_DEFAULT         0x00000000  
/* the default value for parameters and attributes */
/*-------------OCIInitialize Modes / OCICreateEnvironment Modes -------------*/
#define NCI_THREADED        0x00000001      /* appl. in threaded environment */ 
#define NCI_OBJECT          0x00000002  /* application in object environment */ 
#define NCI_EVENTS          0x00000004  /* application is enabled for events */ 
#define NCI_RESERVED1       0x00000008                           /* reserved */ 
#define NCI_SHARED          0x00000010  /* the application is in shared mode */ 
#define NCI_RESERVED2       0x00000020                           /* reserved */ 
/* The following *TWO* are only valid for OCICreateEnvironment call */
#define NCI_NO_UCB          0x00000040 /* No user callback called during ini */ 
#define NCI_NO_MUTEX        0x00000080 /* the environment handle will not be */ 
/*  protected by a mutex internally */
#define NCI_SHARED_EXT      0x00000100              /* Used for shared forms */ 
/************************** 0x00000200 free **********************************/
#define NCI_ALWAYS_BLOCKING 0x00000400    /* all connections always blocking */ 
/************************** 0x00000800 free **********************************/
#define NCI_USE_LDAP        0x00001000            /* allow  LDAP connections */ 
#define NCI_REG_LDAPONLY    0x00002000              /* only register to LDAP */ 
#define NCI_UTF16           0x00004000        /* mode for all UTF16 metadata */ 
#define NCI_AFC_PAD_ON      0x00008000  
/* turn on AFC blank padding when rlenp present */
#define NCI_ENVCR_RESERVED3 0x00010000                           /* reserved */ 
#define NCI_NEW_LENGTH_SEMANTICS  0x00020000   /* adopt new length semantics */ 
/* the new length semantics, always bytes, is used by OCIEnvNlsCreate */
#define NCI_NO_MUTEX_STMT   0x00040000           /* Do not mutex stmt handle */ 
#define NCI_MUTEX_ENV_ONLY  0x00080000  /* Mutex only the environment handle */ 
#define NCI_NCHAR_LITERAL_REPLACE_ON  0x00400000 /* nchar literal replace on */ 
#define NCI_NCHAR_LITERAL_REPLACE_OFF 0x00800000 /* nchar literal replace off*/ 
#define NCI_STM_RESERVED4   0x00100000                           /* reserved */ 
 

#ifndef TRUE
# define TRUE  1
# define FALSE 0
#endif 

#ifndef nlint 
typedef unsigned char  ub1;                   
typedef   signed char  sb1;                  
#else 
#define ub1 unsigned char 
#define sb1 signed char 
#endif 

#define UB1MAXVAL ((ub1)UCHAR_MAX) 
#define UB1MINVAL ((ub1)        0) 
#define SB1MAXVAL ((sb1)SCHAR_MAX) 
#define SB1MINVAL ((sb1)SCHAR_MIN) 
#define MINUB1MAXVAL ((ub1)  255) 
#define MAXUB1MINVAL ((ub1)    0) 
#define MINSB1MAXVAL ((sb1)  127) 
#define MAXSB1MINVAL ((sb1) -127) 

#ifndef nlint 
typedef unsigned short    ub2;                
typedef   signed short    sb2;               
#else 
#define ub2  unsigned short 
#define sb2  signed short 
#endif

#define UB2MAXVAL ((ub2)USHRT_MAX) 
#define UB2MINVAL ((ub2)        0) 
#define SB2MAXVAL ((sb2) SHRT_MAX) 
#define SB2MINVAL ((sb2) SHRT_MIN) 
#define MINUB2MAXVAL ((ub2) 65535) 
#define MAXUB2MINVAL ((ub2)     0) 
#define MINSB2MAXVAL ((sb2) 32767) 
#define MAXSB2MINVAL ((sb2)-32767) 

#ifndef nlint 
typedef unsigned int  ub4;                   
typedef   signed int  sb4;                   
#else 
#define eb4 int 
#define ub4 unsigned int 
#define sb4 signed int 
#endif  

#ifndef INT_MAX
#define INT_MIN     (-2147483647 - 1) /* minimum (signed) int value */
#define INT_MAX       2147483647    /* maximum (signed) int value */
#endif

#define UB4MAXVAL ((ub4)UINT_MAX) 
#define UB4MINVAL ((ub4)        0) 
#define SB4MAXVAL ((sb4) INT_MAX) 
#define SB4MINVAL ((sb4) INT_MIN) 
#define MINUB4MAXVAL ((ub4) 4294967295) 
#define MAXUB4MINVAL ((ub4)          0) 
#define MINSB4MAXVAL ((sb4) 2147483647) 
#define MAXSB4MINVAL ((sb4)-2147483647)  

#define ORAUB8MINVAL    ((oraub8)0)
#define ORAUB8MAXVAL    ((oraub8)18446744073709551615)
#define ORASB8MINVAL    ((orasb8)-9223372036854775808)
#define ORASB8MAXVAL    ((orasb8) 9223372036854775807)

#define MAXORAUB8MINVAL ((oraub8)0)
#define MINORAUB8MAXVAL ((oraub8)18446744073709551615)
#define MAXORASB8MINVAL ((orasb8)-9223372036854775807)
#define MINORASB8MAXVAL ((orasb8) 9223372036854775807)

#define UB1BITS          CHAR_BIT
#define UB1MASK          ((1 << ((uword)CHAR_BIT)) - 1) 


#ifndef lint
# define oratext unsigned char
#else
typedef  unsigned char oratext;
#endif 

#ifndef nlint 
typedef          char     eb1;
typedef          short    eb2;               
typedef          int      eb4;               
#else
# define         eb1      char
# define         eb2      short
# define         eb4      int
#endif

#define EB1MAXVAL      ((eb1)SCHAR_MAX) 
#define EB1MINVAL      ((eb1)        0) 
#define MINEB1MAXVAL   ((eb1)  127) 
#define MAXEB1MINVAL   ((eb1)    0) 
#define EB2MAXVAL      ((eb2) SHRT_MAX) 
#define EB2MINVAL      ((eb2)        0) 
#define MINEB2MAXVAL   ((eb2) 32767) 
#define MAXEB2MINVAL   ((eb2)     0) 
#define EB4MAXVAL      ((eb4) INT_MAX) 
#define EB4MINVAL      ((eb4)        0) 
#define MINEB4MAXVAL   ((eb4) 2147483647) 
#define MAXEB4MINVAL   ((eb4)          0)  

#ifndef nlint 
typedef         sb1  b1;                   
#else 
#define         b1 sb1 
#endif  
#define  B1MAXVAL  SB1MAXVAL 
#define  B1MINVAL  SB1MINVAL 

#ifndef nlint 
typedef         sb2      b2;              
#else 
#define         b2 sb2 
#endif  
#define  B2MAXVAL  SB2MAXVAL 
#define  B2MINVAL  SB2MINVAL 

#ifndef nlint 
typedef         sb4    b4;                
#else 
#define         b4 sb4 
#endif  
# define  B4MAXVAL  SB4MAXVAL 
# define  B4MINVAL  SB4MINVAL 


#if !defined(LUSEMFC)
# ifndef lint
#  define text unsigned char
# else
typedef oratext text;
# endif
#endif

#ifndef lint
# define OraText unsigned char
#else
typedef oratext OraText;
#endif


typedef OraText NCIText  ; 

#ifndef nlint
typedef          int eword;                  
typedef unsigned int uword;                  
typedef   signed int sword;                  
#else
#define eword int
#define uword unsigned int
#define sword signed int
#endif 

#define  EWORDMAXVAL  ((eword) INT_MAX)
#define  EWORDMINVAL  ((eword)       0)
#define  UWORDMAXVAL  ((uword)UINT_MAX)
#define  UWORDMINVAL  ((uword)       0)
#define  SWORDMAXVAL  ((sword) INT_MAX)
#define  SWORDMINVAL  ((sword) INT_MIN)
#define  MINEWORDMAXVAL  ((eword)  2147483647)
#define  MAXEWORDMINVAL  ((eword)      0)
#define  MINUWORDMAXVAL  ((uword)  4294967295)
#define  MAXUWORDMINVAL  ((uword)           0)
#define  MINSWORDMAXVAL  ((sword)  2147483647)
#define  MAXSWORDMINVAL  ((sword) -2147483647) 

#ifdef _WIN64

#ifndef nlint
typedef unsigned _int64 ubig_ora;     
typedef   signed _int64 sbig_ora;     
#else
#define ubig_ora unsigned _int64
#define sbig_ora signed _int64
#endif 

#define UBIG_ORAMAXVAL ((ubig_ora)_UI64_MAX)
#define UBIG_ORAMINVAL ((ubig_ora)        0)
#define SBIG_ORAMAXVAL ((sbig_ora) _I64_MAX)
#define SBIG_ORAMINVAL ((sbig_ora) _I64_MIN)
#define MINUBIG_ORAMAXVAL ((ubig_ora) 4294967295)
#define MAXUBIG_ORAMINVAL ((ubig_ora)          0)
#define MINSBIG_ORAMAXVAL ((sbig_ora) 2147483647)
#define MAXSBIG_ORAMINVAL ((sbig_ora)-2147483647)

#else

#ifndef nlint
typedef unsigned long  ubig_ora;             
typedef   signed long  sbig_ora;             
#else
#define ubig_ora unsigned long
#define sbig_ora signed long
#endif 

#define UBIG_ORAMAXVAL ((ubig_ora)ULONG_MAX)
#define UBIG_ORAMINVAL ((ubig_ora)        0)
#define SBIG_ORAMAXVAL ((sbig_ora) LONG_MAX)
#define SBIG_ORAMINVAL ((sbig_ora) LONG_MIN)
#define MINUBIG_ORAMAXVAL ((ubig_ora) 4294967295)
#define MAXUBIG_ORAMINVAL ((ubig_ora)          0)
#define MINSBIG_ORAMAXVAL ((sbig_ora) 2147483647)
#define MAXSBIG_ORAMINVAL ((sbig_ora)-2147483647)

#endif                                                             /* _WIN64 */

/* --- Signed/Unsigned eight-byte scalar (orasb8/oraub8) --- */

#define ORAXB8_DEFINED
#ifndef nlint
#ifndef __GNUC__
#ifdef __BORLANDC__
typedef unsigned __int64 oraub8;
typedef signed __int64 orasb8;
#else
typedef unsigned _int64 oraub8;
typedef signed _int64 orasb8;
#endif /* __BORLANDC__ */
#else
typedef unsigned long long oraub8;
typedef signed long long orasb8;
#endif /*__GNUC__*/
typedef oraub8 ub8;
typedef orasb8 sb8;
#else
#ifndef __GNUC__
#ifdef __BORLANDC__
#define oraub8 unsigned __int64
#define orasb8 signed __int64
#else
#define oraub8 unsigned _int64
#define orasb8 signed _int64
#endif /* __BORLANDC__ */
#else
#define oraub8 unsigned long long
#define orasb8 signed long long
#endif /*__GNUC__*/
# define ub8 oraub8
# define sb8 orasb8
#endif /*lint*/

#define UBIGORABITS      (UB1BITS * sizeof(ubig_ora)) 

#undef CONST
#define CONST const 

#define dvoid void 

//typedef void (*lgenfp_t)( void ); 

#ifndef ORASYS_TYPES
# include <sys/types.h>
# define ORASYS_TYPES
#endif  

//#ifndef boolean
//# define boolean int
//#endif  

#ifdef sparc
# define SIZE_TMAXVAL SB4MAXVAL               
#else
# define SIZE_TMAXVAL UB4MAXVAL              
#endif 

#define MINSIZE_TMAXVAL (size_t)4294967295   
#define cbool ndmbool


/*-------------------------Credential Types----------------------------------*/
#define NCI_CRED_RDBMS      1                  /* database username/password */ 
/*-----------------------------Handle Types----------------------------------*/
/* handle types range from 1 - 49 */
#define NCI_HTYPE_FIRST          1             /* start value of handle type */ 
#define NCI_HTYPE_ENV            1                     /* environment handle */ 
#define NCI_HTYPE_ERROR          2                           /* error handle */ 
#define NCI_HTYPE_SVCCTX         3                         /* service handle */ 
#define NCI_HTYPE_STMT           4                       /* statement handle */ 
#define NCI_HTYPE_BIND           5                            /* bind handle */ 
#define NCI_HTYPE_DEFINE         6                          /* define handle */ 
#define NCI_HTYPE_DESCRIBE       7                        /* describe handle */ 
#define NCI_HTYPE_SERVER         8                          /* server handle */ 
#define NCI_HTYPE_SESSION        9                  /* authentication handle */  
#define NCI_HTYPE_AUTHINFO      NCI_HTYPE_SESSION  /* SessionGet auth handle */  
#define NCI_HTYPE_TRANS         10                     /* transaction handle */ 
#define NCI_HTYPE_COMPLEXOBJECT 11        /* complex object retrieval handle */ 
#define NCI_HTYPE_SECURITY      12                        /* security handle */ 
#define NCI_HTYPE_SUBSCRIPTION  13                    /* subscription handle */ 
#define NCI_HTYPE_DIRPATH_CTX   14                    /* direct path context */ 
#define NCI_HTYPE_DIRPATH_COLUMN_ARRAY 15        /* direct path column array */ 
#define NCI_HTYPE_DIRPATH_STREAM       16              /* direct path stream */ 
#define NCI_HTYPE_PROC                 17                  /* process handle */ 
#define NCI_HTYPE_DIRPATH_FN_CTX       18    /* direct path function context */ 
#define NCI_HTYPE_DIRPATH_FN_COL_ARRAY 19          /* dp object column array */ 
#define NCI_HTYPE_XADSESSION    20                  /* access driver session */ 
#define NCI_HTYPE_XADTABLE      21                    /* access driver table */ 
#define NCI_HTYPE_XADFIELD      22                    /* access driver field */ 
#define NCI_HTYPE_XADGRANULE    23                  /* access driver granule */ 
#define NCI_HTYPE_XADRECORD     24                   /* access driver record */ 
#define NCI_HTYPE_XADIO         25                      /* access driver I/O */ 
#define NCI_HTYPE_CPOOL         26                 /* connection pool handle */ 
#define NCI_HTYPE_SPOOL         27                    /* session pool handle */ 
#define NCI_HTYPE_ADMIN         28                 /*administration handle*/  
#define NCI_HTYPE_LAST          28            /* last value of a handle type */  
/*===========================================================================*/  
#define NCI_ATTR_FNCODE  1                          /* the OCI function code */ 
#define NCI_ATTR_OBJECT   2 /* is the environment initialized in object mode */ 
#define NCI_ATTR_NONBLOCKING_MODE  3                    /* non blocking mode */ 
#define NCI_ATTR_SQLCODE  4                                  /* the SQL verb */ 
#define NCI_ATTR_ENV  5                            /* the environment handle */ 
#define NCI_ATTR_SERVER 6                               /* the server handle */ 
#define NCI_ATTR_SESSION 7                        /* the user session handle */ 
#define NCI_ATTR_TRANS   8                         /* the transaction handle */ 
#define NCI_ATTR_ROW_COUNT   9                  /* the rows processed so far */ 
#define NCI_ATTR_SQLFNCODE 10               /* the SQL verb of the statement */ 
#define NCI_ATTR_PREFETCH_ROWS  11    /* sets the number of rows to prefetch */ 
#define NCI_ATTR_NESTED_PREFETCH_ROWS 12 /* the prefetch rows of nested table*/ 
#define NCI_ATTR_PREFETCH_MEMORY 13         /* memory limit for rows fetched */ 
#define NCI_ATTR_NESTED_PREFETCH_MEMORY 14   /* memory limit for nested rows */ 
#define NCI_ATTR_CHAR_COUNT  15 
#define NCI_ATTR_PDSCL   16                          /* packed decimal scale */
#define NCI_ATTR_FSPRECISION NCI_ATTR_PDSCL    
#define NCI_ATTR_PDPRC   17                         /* packed decimal format */ 
#define NCI_ATTR_LFPRECISION NCI_ATTR_PDPRC  
#define NCI_ATTR_PARAM_COUNT 18       /* number of column in the select list */ 
#define NCI_ATTR_ROWID   19                                     /* the rowid */ 
#define NCI_ATTR_CHARSET  20                      /* the character set value */ 
#define NCI_ATTR_NCHAR   21                                    /* NCHAR type */ 
#define NCI_ATTR_USERNAME 22                           /* username attribute */ 
#define NCI_ATTR_PASSWORD 23                           /* password attribute */ 
#define NCI_ATTR_STMT_TYPE   24                            /* statement type */ 
#define NCI_ATTR_INTERNAL_NAME   25             /* user friendly global name */ 
#define NCI_ATTR_EXTERNAL_NAME   26      /* the internal name for global txn */ 
#define NCI_ATTR_XID     27           /* XOPEN defined global transaction id */ 
#define NCI_ATTR_TRANS_LOCK 28                                            /* */ 
#define NCI_ATTR_TRANS_NAME 29    /* string to identify a global transaction */ 
#define NCI_ATTR_HEAPALLOC 30                /* memory allocated on the heap */ 
#define NCI_ATTR_CHARSET_ID 31                           /* Character Set ID */ 
#define NCI_ATTR_CHARSET_FORM 32                       /* Character Set Form */ 
#define NCI_ATTR_MAXDATA_SIZE 33       /* Maximumsize of data on the server  */ 
#define NCI_ATTR_CACHE_OPT_SIZE 34              /* object cache optimal size */ 
#define NCI_ATTR_CACHE_MAX_SIZE 35   /* object cache maximum size percentage */ 
#define NCI_ATTR_PINOPTION 36             /* object cache default pin option */ 
#define NCI_ATTR_ALLOC_DURATION 37 
#define NCI_ATTR_PIN_DURATION 38        /* object cache default pin duration */ 
#define NCI_ATTR_FDO          39       /* Format Descriptor object attribute */ 
#define NCI_ATTR_POSTPROCESSING_CALLBACK 40
                                         /* Callback to process outbind data */ 
#define NCI_ATTR_POSTPROCESSING_CONTEXT 41
                                 /* Callback context to process outbind data */ 
#define NCI_ATTR_ROWS_RETURNED 42 
               /* Number of rows returned in current iter - for Bind handles */
#define NCI_ATTR_FOCBK        43              /* Failover Callback attribute */ 
#define NCI_ATTR_IN_V8_MODE   44 /* is the server/service context in V8 mode */ 
#define NCI_ATTR_LOBEMPTY     45                              /* empty lob ? */  
#define NCI_ATTR_SESSLANG     46                  /* session language handle */ 

#define NCI_ATTR_VISIBILITY             47                     /* visibility */ 
#define NCI_ATTR_RELATIVE_MSGID         48            /* relative message id */ 
#define NCI_ATTR_SEQUENCE_DEVIATION     49             /* sequence deviation */  

#define NCI_ATTR_CONSUMER_NAME          50                  /* consumer name */ 
#define NCI_ATTR_DEQ_MODE               51                   /* dequeue mode */ 
#define NCI_ATTR_NAVIGATION             52                     /* navigation */ 
#define NCI_ATTR_WAIT                   53                           /* wait */ 
#define NCI_ATTR_DEQ_MSGID              54             /* dequeue message id */ 

#define NCI_ATTR_PRIORITY               55                       /* priority */ 
#define NCI_ATTR_DELAY                  56                          /* delay */  
#define NCI_ATTR_EXPIRATION             57                     /* expiration */  
#define NCI_ATTR_CORRELATION            58                 /* correlation id */ 
#define NCI_ATTR_ATTEMPTS               59                  /* # of attempts */ 
#define NCI_ATTR_RECIPIENT_LIST         60                 /* recipient list */ 
#define NCI_ATTR_EXCEPTION_QUEUE        61           /* exception queue name */ 
#define NCI_ATTR_ENQ_TIME               62 /* enqueue time (only NCIAttrGet) */ 
#define NCI_ATTR_MSG_STATE              63/* message state (only NCIAttrGet) */ 
                                                   /* NOTE: 64-66 used below */
#define NCI_ATTR_AGENT_NAME             64                     /* agent name */ 
#define NCI_ATTR_AGENT_ADDRESS          65                  /* agent address */ 
#define NCI_ATTR_AGENT_PROTOCOL         66                 /* agent protocol */ 
#define NCI_ATTR_USER_PROPERTY          67                  /* user property */ 
#define NCI_ATTR_SENDER_ID              68                      /* sender id */ 
#define NCI_ATTR_ORIGINAL_MSGID         69            /* original message id */ 

#define NCI_ATTR_QUEUE_NAME             70                     /* queue name */ 
#define NCI_ATTR_NFY_MSGID              71                     /* message id */ 
#define NCI_ATTR_MSG_PROP               72             /* message properties */ 

#define NCI_ATTR_NUM_DML_ERRORS         73       /* num of errs in array DML */ 
#define NCI_ATTR_DML_ROW_OFFSET         74        /* row offset in the array */ 

              /* AQ array error handling uses DML method of accessing errors */
#define NCI_ATTR_AQ_NUM_ERRORS          NCI_ATTR_NUM_DML_ERRORS 
#define NCI_ATTR_AQ_ERROR_INDEX         NCI_ATTR_DML_ROW_OFFSET 

#define NCI_ATTR_DATEFORMAT             75     /* default date format string */ 
#define NCI_ATTR_BUF_ADDR               76                 /* buffer address */ 
#define NCI_ATTR_BUF_SIZE               77                    /* buffer size */  
#define NCI_ATTR_DIRPATH_MODE           78  /* mode of direct path operation */ 
#define NCI_ATTR_DIRPATH_NOLOG          79               /* nologging option */ 
#define NCI_ATTR_DIRPATH_PARALLEL       80     /* parallel (temp seg) option */ 
#define NCI_ATTR_NUM_ROWS               81 /* number of rows in column array */ 
                                  /* NOTE that NCI_ATTR_NUM_COLS is a column
                                   * array attribute too.
                                   */
#define NCI_ATTR_COL_COUNT              82        /* columns of column array
                                                     processed so far.       */ 
#define NCI_ATTR_STREAM_OFFSET          83  /* str off of last row processed */ 
#define NCI_ATTR_SHARED_HEAPALLOC       84    /* Shared Heap Allocation Size */ 

#define NCI_ATTR_SERVER_GROUP           85              /* server group name */ 

#define NCI_ATTR_MIGSESSION             86   /* migratable session attribute */ 

#define NCI_ATTR_NOCACHE                87                 /* Temporary LOBs */ 

#define NCI_ATTR_MEMPOOL_SIZE           88                      /* Pool Size */ 
#define NCI_ATTR_MEMPOOL_INSTNAME       89                  /* Instance name */ 
#define NCI_ATTR_MEMPOOL_APPNAME        90               /* Application name */ 
#define NCI_ATTR_MEMPOOL_HOMENAME       91            /* Home Directory name */ 
#define NCI_ATTR_MEMPOOL_MODEL          92     /* Pool Model (proc,thrd,both)*/ 
#define NCI_ATTR_MODES                  93                          /* Modes */ 

#define NCI_ATTR_SUBSCR_NAME            94           /* name of subscription */ 
#define NCI_ATTR_SUBSCR_CALLBACK        95            /* associated callback */ 
#define NCI_ATTR_SUBSCR_CTX             96    /* associated callback context */ 
#define NCI_ATTR_SUBSCR_PAYLOAD         97             /* associated payload */ 
#define NCI_ATTR_SUBSCR_NAMESPACE       98           /* associated namespace */ 

#define NCI_ATTR_PROXY_CREDENTIALS      99         /* Proxy user credentials */ 
#define NCI_ATTR_INITIAL_CLIENT_ROLES  100       /* Initial client role list */ 

#define NCI_ATTR_UNK              101                   /* unknown attribute */  
#define NCI_ATTR_NUM_COLS         102                   /* number of columns */ 
#define NCI_ATTR_LIST_COLUMNS     103        /* parameter of the column list */ 
#define NCI_ATTR_RDBA             104           /* DBA of the segment header */ 
#define NCI_ATTR_CLUSTERED        105      /* whether the table is clustered */ 
#define NCI_ATTR_PARTITIONED      106    /* whether the table is partitioned */ 
#define NCI_ATTR_INDEX_ONLY       107     /* whether the table is index only */ 
#define NCI_ATTR_LIST_ARGUMENTS   108      /* parameter of the argument list */ 
#define NCI_ATTR_LIST_SUBPROGRAMS 109    /* parameter of the subprogram list */ 
#define NCI_ATTR_REF_TDO          110          /* REF to the type descriptor */ 
#define NCI_ATTR_LINK             111              /* the database link name */ 
#define NCI_ATTR_MIN              112                       /* minimum value */ 
#define NCI_ATTR_MAX              113                       /* maximum value */ 
#define NCI_ATTR_INCR             114                     /* increment value */ 
#define NCI_ATTR_CACHE            115   /* number of sequence numbers cached */ 
#define NCI_ATTR_ORDER            116     /* whether the sequence is ordered */ 
#define NCI_ATTR_HW_MARK          117                     /* high-water mark */ 
#define NCI_ATTR_TYPE_SCHEMA      118                  /* type's schema name */ 
#define NCI_ATTR_TIMESTAMP        119             /* timestamp of the object */ 
#define NCI_ATTR_NUM_ATTRS        120                /* number of sttributes */ 
#define NCI_ATTR_NUM_PARAMS       121                /* number of parameters */ 
#define NCI_ATTR_OBJID            122       /* object id for a table or view */ 
#define NCI_ATTR_PTYPE            123           /* type of info described by */ 
#define NCI_ATTR_PARAM            124                /* parameter descriptor */ 
#define NCI_ATTR_OVERLOAD_ID      125     /* overload ID for funcs and procs */ 
#define NCI_ATTR_TABLESPACE       126                    /* table name space */ 
#define NCI_ATTR_TDO              127                       /* TDO of a type */ 
#define NCI_ATTR_LTYPE            128                           /* list type */ 
#define NCI_ATTR_PARSE_ERROR_OFFSET 129                /* Parse Error offset */ 
#define NCI_ATTR_IS_TEMPORARY     130          /* whether table is temporary */ 
#define NCI_ATTR_IS_TYPED         131              /* whether table is typed */ 
#define NCI_ATTR_DURATION         132         /* duration of temporary table */ 
#define NCI_ATTR_IS_INVOKER_RIGHTS 133                  /* is invoker rights */ 
#define NCI_ATTR_OBJ_NAME         134           /* top level schema obj name */ 
#define NCI_ATTR_OBJ_SCHEMA       135                         /* schema name */ 
#define NCI_ATTR_OBJ_ID           136          /* top level schema object id */ 

#define NCI_ATTR_DIRPATH_SORTED_INDEX    137 /* index that data is sorted on */ 

            /* direct path index maint method (see oci8dp.h) */
#define NCI_ATTR_DIRPATH_INDEX_MAINT_METHOD 138 

    /* parallel load: db file, initial and next extent sizes */

#define NCI_ATTR_DIRPATH_FILE               139      /* DB file to load into */ 
#define NCI_ATTR_DIRPATH_STORAGE_INITIAL    140       /* initial extent size */ 
#define NCI_ATTR_DIRPATH_STORAGE_NEXT       141          /* next extent size */  

#define NCI_ATTR_TRANS_TIMEOUT              142       /* transaction timeout */ 
#define NCI_ATTR_SERVER_STATUS              143/* state of the server handle */ 
#define NCI_ATTR_STATEMENT                  144 /* statement txt in stmt hdl */ 

            /* direct path index maint method (see oci8dp.h) */
#define NCI_ATTR_DIRPATH_SKIPINDEX_METHOD   145 

#define NCI_ATTR_DEQCOND                    146         /* dequeue condition */ 
#define NCI_ATTR_RESERVED_2                 147                  /* reserved */  
  
#define NCI_ATTR_SUBSCR_RECPT               148 /* recepient of subscription */ 
#define NCI_ATTR_SUBSCR_RECPTPROTO          149    /* protocol for recepient */ 

    /* 8.2 dpapi support of ADTs */
#define NCI_ATTR_DIRPATH_EXPR_TYPE  150        /* expr type of NCI_ATTR_NAME */  

#define NCI_ATTR_DIRPATH_INPUT      151    /* input in text or stream format */ 
#define NCI_DIRPATH_INPUT_TEXT     0x01 
#define NCI_DIRPATH_INPUT_STREAM   0x02 
#define NCI_DIRPATH_INPUT_UNKNOWN  0x04 

#define NCI_DIRPATH_DATASAVE_SAVEONLY 0              
#define NCI_DIRPATH_DATASAVE_FINISH   1           /* execute finishing logic */ 
/* save portion of input data (before space error occurred) and finish */
#define NCI_DIRPATH_DATASAVE_PARTIAL  2     

#define NCI_ATTR_LDAP_HOST       153              /* LDAP host to connect to */ 
#define NCI_ATTR_LDAP_PORT       154              /* LDAP port to connect to */ 
#define NCI_ATTR_BIND_DN         155                              /* bind DN */ 
#define NCI_ATTR_LDAP_CRED       156       /* credentials to connect to LDAP */ 
#define NCI_ATTR_WALL_LOC        157               /* client wallet location */ 
#define NCI_ATTR_LDAP_AUTH       158           /* LDAP authentication method */ 
#define NCI_ATTR_LDAP_CTX        159        /* LDAP adminstration context DN */ 
#define NCI_ATTR_SERVER_DNS      160      /* list of registration server DNs */ 

#define NCI_ATTR_DN_COUNT        161             /* the number of server DNs */ 
#define NCI_ATTR_SERVER_DN       162                  /* server DN attribute */ 

#define NCI_ATTR_MAXCHAR_SIZE               163     /* max char size of data */ 

#define NCI_ATTR_CURRENT_POSITION           164 /* for scrollable result sets*/ 

/* Added to get attributes for ref cursor to statement handle */
#define NCI_ATTR_RESERVED_3                 165                  /* reserved */ 
#define NCI_ATTR_RESERVED_4                 166                  /* reserved */ 
#define NCI_ATTR_DIRPATH_FN_CTX             167  /* fn ctx ADT attrs or args */ 
#define NCI_ATTR_DIGEST_ALGO                168          /* digest algorithm */ 
#define NCI_ATTR_CERTIFICATE                169               /* certificate */ 
#define NCI_ATTR_SIGNATURE_ALGO             170       /* signature algorithm */ 
#define NCI_ATTR_CANONICAL_ALGO             171    /* canonicalization algo. */ 
#define NCI_ATTR_PRIVATE_KEY                172               /* private key */ 
#define NCI_ATTR_DIGEST_VALUE               173              /* digest value */ 
#define NCI_ATTR_SIGNATURE_VAL              174           /* signature value */ 
#define NCI_ATTR_SIGNATURE                  175                 /* signature */ 

/* attributes for setting OCI stmt caching specifics in svchp */
#define NCI_ATTR_STMTCACHESIZE              176     /* size of the stm cache */ 

/* --------------------------- Connection Pool Attributes ------------------ */
#define NCI_ATTR_CONN_NOWAIT               178 
#define NCI_ATTR_CONN_BUSY_COUNT            179 
#define NCI_ATTR_CONN_OPEN_COUNT            180 
#define NCI_ATTR_CONN_TIMEOUT               181 
#define NCI_ATTR_STMT_STATE                 182 
#define NCI_ATTR_CONN_MIN                   183 
#define NCI_ATTR_CONN_MAX                   184 
#define NCI_ATTR_CONN_INCR                  185 

#define NCI_ATTR_DIRPATH_OID                187   /* loading into an OID col */ 

#define NCI_ATTR_NUM_OPEN_STMTS             188     /* open stmts in session */ 
#define NCI_ATTR_DESCRIBE_NATIVE            189  /* get native info via desc */ 

#define NCI_ATTR_BIND_COUNT                 190   /* number of bind postions */ 
#define NCI_ATTR_HANDLE_POSITION            191 /* pos of bind/define handle */ 
#define NCI_ATTR_RESERVED_5                 192                 /* reserverd */ 
#define NCI_ATTR_SERVER_BUSY                193 /* call in progress on server*/ 

#define NCI_ATTR_DIRPATH_SID                194   /* loading into an SID col */ 
/* notification presentation for recipient */
#define NCI_ATTR_SUBSCR_RECPTPRES           195 
#define NCI_ATTR_TRANSFORMATION             196 /* AQ message transformation */ 

#define NCI_ATTR_ROWS_FETCHED               197 /* rows fetched in last call */ 

/* --------------------------- Snapshot attributes ------------------------- */
#define NCI_ATTR_SCN_BASE                   198             /* snapshot base */ 
#define NCI_ATTR_SCN_WRAP                   199             /* snapshot wrap */ 

/* --------------------------- Miscellanous attributes --------------------- */
#define NCI_ATTR_RESERVED_6                 200                  /* reserved */ 
#define NCI_ATTR_READONLY_TXN               201           /* txn is readonly */ 
#define NCI_ATTR_RESERVED_7                 202                  /* reserved */ 
#define NCI_ATTR_ERRONEOUS_COLUMN           203 /* position of erroneous col */ 
#define NCI_ATTR_RESERVED_8                 204                  /* reserved */ 

/* -------------------- 8.2 dpapi support of ADTs continued ---------------- */
#define NCI_ATTR_DIRPATH_OBJ_CONSTR         206 /* obj type of subst obj tbl */ 
#define NCI_ATTR_INST_TYPE                  207      /* oracle instance type */ 
/******USED attribute 208 for  NCI_ATTR_SPOOL_STMTCACHESIZE*******************/

#define NCI_ATTR_ENV_UTF16                  209     /* is env in utf16 mode? */ 
#define NCI_ATTR_RESERVED_9                 210          /* reserved for TMZ */ 
#define NCI_ATTR_RESERVED_10                211                  /* reserved */ 

/* Attr to allow setting of the stream version PRIOR to calling Prepare */
#define NCI_ATTR_DIRPATH_STREAM_VERSION     212      /* version of the stream*/ 
#define NCI_ATTR_DIRPATH_VARRAY_INDEX      213       /* varray index column */  
#define NCI_ATTR_RESERVED_12                214                  /* reserved */ 
#define NCI_ATTR_RESERVED_13                215                  /* reserved */ 
#define NCI_ATTR_IS_EXTERNAL                216 /* whether table is external */ 


/* -------------------------- Statement Handle Attributes ------------------ */

#define NCI_ATTR_RESERVED_15                217                  /* reserved */ 
#define NCI_ATTR_STMT_IS_RETURNING          218 /* stmt has returning clause */ 
#define NCI_ATTR_RESERVED_16                219                  /* reserved */ 
#define NCI_ATTR_RESERVED_17                220                  /* reserved */ 
#define NCI_ATTR_RESERVED_18                221                  /* reserved */ 
/* --------------------------- session attributes ---------------------------*/
#define NCI_ATTR_RESERVED_19                222                  /* reserved */  
#define NCI_ATTR_LIST_TYPE                  223                  /*attributes of list,designates list type*/  
#define NCI_ATTR_SSL_PATH                   10000                  /*attributes of SSL_PATH*/ 
#define NCI_ATTR_SSL_PWD                    10001  
#define NCI_ATTR_MPP_LOGIN                  10002 

/*------------- Supported Values for Direct Path Stream Version -------------*/
#define NCI_DIRPATH_STREAM_VERSION_1        100 
#define NCI_DIRPATH_STREAM_VERSION_2        200 
#define NCI_DIRPATH_STREAM_VERSION_3        300                   /* default */ 

/* ----------------------- row callback attributes ------------------------- */
#define NCI_ATTR_BIND_ROWCBK                301         /* bind row callback */ 
#define NCI_ATTR_BIND_ROWCTX                302 /* ctx for bind row callback */  
#define NCI_ATTR_SKIP_BUFFER                303  /* skip buffer in array ops */ 
/* ----------------------- DM attributes ----------------------------------- */
#define NCI_ATTR_PORT						1000		/* DM login port	 */ 

/* -------- client side character and national character set ids ----------- */
#define NCI_ATTR_ENV_CHARSET_ID   NCI_ATTR_CHARSET_ID   /* charset id in env */  

/*------------------------Error Return Values--------------------------------*/
#define NCI_SUCCESS 0                      /* maps to SQL_SUCCESS of SAG CLI */ 
#define NCI_SUCCESS_WITH_INFO 1             /* maps to SQL_SUCCESS_WITH_INFO */ 
#define NCI_RESERVED_FOR_INT_USE 200                            /* reserved */  
#define NCI_NO_DATA 100                               /* maps to SQL_NO_DATA */ 
#define NCI_ERROR -1                                    /* maps to SQL_ERROR */ 
#define NCI_INVALID_HANDLE -2                  /* maps to SQL_INVALID_HANDLE */  
#define NCI_NEED_DATA 99                            /* maps to SQL_NEED_DATA */ 
#define NCI_STILL_EXECUTING -3123                   /* OCI would block error */ 
/*---------------------------------------------------------------------------*/
/*----------------------- Execution Modes -----------------------------------*/
#define NCI_BATCH_MODE        0x01  /* batch the NCI statement for execution */ 
#define NCI_EXACT_FETCH       0x02         /* fetch the exact rows specified */ 
#define NCI_KEEP_FETCH_STATE  0x04                                 /* unused */ 
#define NCI_STMT_SCROLLABLE_READONLY 0x08     /* if result set is scrollable */ 
#define NCI_DESCRIBE_ONLY     0x10            /* only describe the statement */ 
#define NCI_COMMIT_ON_SUCCESS 0x20        /* commit, if successful execution */ 
#define NCI_NON_BLOCKING      0x40                           /* non-blocking */  
#define NCI_BATCH_ERRORS      0x80             /* batch errors in array dmls */ 
#define NCI_PARSE_ONLY        0x100              /* only parse the statement */ 
#define NCI_EXACT_FETCH_RESERVED_1 0x200                         /* reserved */ 
#define NCI_SHOW_DML_WARNINGS 0x400    
/* return NCI_SUCCESS_WITH_INFO for delete/update w/no where clause */
#define NCI_EXEC_RESERVED_2   0x800                              /* reserved */ 
#define NCI_DESC_RESERVED_1   0x1000                             /* reserved */ 
#define NCI_EXEC_RESERVED_3   0x2000                             /* reserved */ 
#define NCI_EXEC_RESERVED_4   0x4000                             /* reserved */  


#define NCI_LOGON2_SPOOL       0x0001     /* Use session pool */ 
#define NCI_LOGON2_CPOOL       NCI_CPOOL  /* Use connection pool */ 
#define NCI_LOGON2_STMTCACHE   0x0004     /* Use Stmt Caching */
#define NCI_LOGON2_PROXY       0x0008     /* Proxy authentiaction */ 
/*------------------------Parsing Syntax Types-------------------------------*/
#define NCI_V7_SYNTAX 2       /* V815 language - for backwards compatibility */ 
#define NCI_V8_SYNTAX 3       /* V815 language - for backwards compatibility */ 
#define NCI_NTV_SYNTAX 1    /* Use what so ever is the native lang of server */ 
                     /* these values must match the values defined in kpul.h */
/*---------------------------------------------------------------------------*/

/*------------------------Piece Information----------------------------------*/
#define NCI_PARAM_IN 0x01                                    /* in parameter */ 
#define NCI_PARAM_OUT 0x02                                  /* out parameter */ 

/*--------------------------- OCI Statement Types ---------------------------*/
#define  NCI_STMT_UNKNOWN 0                             /* Unknown statement */ 
#define  NCI_STMT_SELECT  1                             /* select statement */  
#define  NCI_STMT_UPDATE  2                             /* update statement */ 
#define  NCI_STMT_DELETE  3                             /* delete statement */ 
#define  NCI_STMT_INSERT  4                             /* Insert Statement */ 
#define  NCI_STMT_CREATE  5                             /* create statement */ 
#define  NCI_STMT_DROP    6                             /* drop statement */ 
#define  NCI_STMT_ALTER   7                             /* alter statement */ 
#define  NCI_STMT_BEGIN   8                             /* begin ... (pl/sql statement)*/ 
#define  NCI_STMT_DECLARE 9                             /* declare .. (pl/sql statement ) */ 
#define  NCI_STMT_CALL    10                            /* corresponds to kpu call */ 

/*------------------------Attach Modes---------------------------------------*/

/* The following attach modes are the same as the UPI modes defined in 
* UPIDEF.H.  Do not use these values externally.
*/ 
#define NCI_FASTPATH         0x0010              /* Attach in fast path mode */ 
#define NCI_ATCH_RESERVED_1  0x0020                              /* reserved */ 
#define NCI_ATCH_RESERVED_2  0x0080                              /* reserved */ 
#define NCI_ATCH_RESERVED_3  0x0100                              /* reserved */ 
#define NCI_CPOOL            0x0200  /* Attach using server handle from pool */ 
#define NCI_ATCH_RESERVED_4  0x0400                              /* reserved */ 

/*---------------------OCIStmtPrepare2 Modes---------------------------------*/
#define NCI_PREP2_CACHE_SEARCHONLY    0x0010                  /* ONly Search */ 
#define NCI_PREP2_GET_PLSQL_WARNINGS  0x0020         /* Get PL/SQL warnings  */ 

#define NCI_SESSGET_SPOOL      0x0001     /* SessionGet called in SPOOL mode */ 
#define NCI_SESSGET_CPOOL      NCI_CPOOL  /* SessionGet called in CPOOL mode */ 
#define NCI_SESSGET_STMTCACHE  0x0004                 /* Use statement cache */ 
#define NCI_SESSGET_CREDPROXY  0x0008     /* SessionGet called in proxy mode */ 
#define NCI_SESSGET_CREDEXT    0x0010      
#define NCI_SESSGET_SPOOL_MATCHANY 0x0020 

/*--------------------------------LOB types ---------------------------------*/
#define NCI_TEMP_BLOB 1                /* LOB type - BLOB ------------------ */ 
#define NCI_TEMP_CLOB 2                /* LOB type - CLOB ------------------ */ 

/*--------------------------- LOB open modes --------------------------------*/
#define NCI_LOB_READONLY 1              /* readonly mode open for ILOB types */ 
#define NCI_LOB_READWRITE 2                /* read write mode open for ILOBs */ 
#define NCI_LOB_WRITEONLY     3         /* Writeonly mode open for ILOB types*/ 
#define NCI_LOB_APPENDONLY    4       /* Appendonly mode open for ILOB types */  
#define NCI_LOB_FULLOVERWRITE 5                 /* Completely overwrite ILOB */ 
#define NCI_LOB_FULLREAD      6                 /* Doing a Full Read of ILOB */ 

/*----- values for cflg argument to OCIDirpathColArrayEntrySet -----*/
#define NCI_DIRPATH_COL_COMPLETE 0                /* column data is complete */ 
#define NCI_DIRPATH_COL_NULL     1                         /* column is null */ 
#define NCI_DIRPATH_COL_PARTIAL  2                 /* column data is partial */ 
#define NCI_DIRPATH_COL_ERROR    3               /* column error, ignore row */ 
/*-------------------------Descriptor Types----------------------------------*/
/* descriptor values range from 50 - 255 */
#define NCI_DTYPE_FIRST 50                 /* start value of descriptor type */ 
#define NCI_DTYPE_LOB 50                                     /* lob  locator */ 
#define NCI_DTYPE_SNAP 51                             /* snapshot descriptor */ 
#define NCI_DTYPE_RSET 52                           /* result set descriptor */ 
#define NCI_DTYPE_PARAM 53  /* a parameter descriptor obtained from NCIgparm */ 
#define NCI_DTYPE_ROWID  54                              /* rowid descriptor */ 
#define NCI_DTYPE_COMPLEXOBJECTCOMP  55 
/* complex object retrieval descriptor */
#define NCI_DTYPE_FILE 56                                /* File Lob locator */ 
#define NCI_DTYPE_AQENQ_OPTIONS 57                        /* enqueue options */ 
#define NCI_DTYPE_AQDEQ_OPTIONS 58                        /* dequeue options */ 
#define NCI_DTYPE_AQMSG_PROPERTIES 59                  /* message properties */ 
#define NCI_DTYPE_AQAGENT 60                                     /* aq agent */ 
#define NCI_DTYPE_LOCATOR 61                                  /* LOB locator */ 
#define NCI_DTYPE_INTERVAL_YM 62                      /* Interval year month */ 
#define NCI_DTYPE_INTERVAL_DS 63                      /* Interval day second */ 
#define NCI_DTYPE_AQNFY_DESCRIPTOR  64               /* AQ notify descriptor */ 
#define NCI_DTYPE_DATE 65                            /* Date */ 
#define NCI_DTYPE_TIME 66                            /* Time */ 
#define NCI_DTYPE_TIME_TZ 67                         /* Time with timezone */ 
#define NCI_DTYPE_TIMESTAMP 68                       /* Timestamp */ 
#define NCI_DTYPE_TIMESTAMP_TZ 69                /* Timestamp with timezone */ 
#define NCI_DTYPE_TIMESTAMP_LTZ 70             /* Timestamp with local tz */ 
#define NCI_DTYPE_UCB           71               /* user callback descriptor */ 
#define NCI_DTYPE_SRVDN         72              /* server DN list descriptor */  
#define NCI_DTYPE_SIGNATURE     73                              /* signature */ 
#define NCI_DTYPE_RESERVED_1    74              /* reserved for internal use */ 
#define NCI_DTYPE_LAST          74        /* last value of a descriptor type */ 

/* Attributes common to Columns and Stored Procs */
#define NCI_ATTR_DATA_SIZE      1                /* maximum size of the data */ 
#define NCI_ATTR_DATA_TYPE      2     /* the SQL type of the column/argument */ 
#define NCI_ATTR_DISP_SIZE      3                        /* the display size */ 
#define NCI_ATTR_NAME           4         /* the name of the column/argument */ 
#define NCI_ATTR_PRECISION      5                /* precision if number type */  
#define NCI_ATTR_SCALE          6                    /* scale if number type */ 
#define NCI_ATTR_IS_NULL        7                            /* is it null ? */ 
#define NCI_ATTR_TYPE_NAME      8 
/* name of the named data type or a package name for package private types */
#define NCI_ATTR_SCHEMA_NAME    9             /* the schema name */ 
#define NCI_ATTR_SUB_NAME       10      /* type name if package private type */ 
#define NCI_ATTR_POSITION       11 
 
/* complex object retrieval parameter attributes */
#define NCI_ATTR_COMPLEXOBJECTCOMP_TYPE         50  
#define NCI_ATTR_COMPLEXOBJECTCOMP_TYPE_LEVEL   51 
#define NCI_ATTR_COMPLEXOBJECT_LEVEL            52 
#define NCI_ATTR_COMPLEXOBJECT_COLL_OUTOFLINE   53 

/*------------------------Scrollable Cursor Fetch Options------------------- 
 * For non-scrollable cursor, the only valid (and default) orientation is 
 * NCI_FETCH_NEXT
 */
#define NCI_FETCH_CURRENT 0x01               /* refetching current position  */ 
#define NCI_FETCH_NEXT 0x02                                      /* next row */ 
#define NCI_FETCH_FIRST 0x04                  /* first row of the result set */  
#define NCI_FETCH_LAST 0x08                /* the last row of the result set */ 
#define NCI_FETCH_PRIOR 0x10         /* the previous row relative to current */ 
#define NCI_FETCH_ABSOLUTE 0x20                /* absolute offset from first */ 
#define NCI_FETCH_RELATIVE 0x40                /* offset relative to current */ 
#define NCI_FETCH_RESERVED_1 0x80                                /* reserved */ 

/*---------------------------------------------------------------------------*/

/*------------------------Bind and Define Options----------------------------*/
#define NCI_SB2_IND_PTR       0x00000001                           /* unused */ 
#define NCI_DATA_AT_EXEC      0x00000002             /* data at execute time */ 
#define NCI_DYNAMIC_FETCH     0x00000002                /* fetch dynamically */ 
#define NCI_PIECEWISE         0x00000004          /* piecewise DMLs or fetch */ 
#define NCI_DEFINE_RESERVED_1 0x00000008                         /* reserved */ 
#define NCI_BIND_RESERVED_2   0x00000010                         /* reserved */ 
#define NCI_DEFINE_RESERVED_2 0x00000020                         /* reserved */ 
#define NCI_BIND_SOFT         0x00000040              /* soft bind or define */ 
#define NCI_DEFINE_SOFT       0x00000080              /* soft bind or define */ 

#define NCI_ONE_PIECE 0                                         /* one piece */
#define NCI_FIRST_PIECE 1                                 /* the first piece */
#define NCI_NEXT_PIECE 2                          /* the next of many pieces */
#define NCI_LAST_PIECE 3                                   /* the last piece */

#define  NCI_DURATION_INVALID 0xFFFF                     /* Invalid duration */  
#define  NCI_DURATION_BEGIN (NCIDuration)10  
/* beginning sequence of duration */
#define  NCI_DURATION_NULL (NCIDuration)(NCI_DURATION_BEGIN-1)  
/* null duration */
#define  NCI_DURATION_DEFAULT (NCIDuration)(NCI_DURATION_BEGIN-2) /* default */  
#define  NCI_DURATION_USER_CALLBACK (NCIDuration)(NCI_DURATION_BEGIN-3)  
#define  NCI_DURATION_NEXT (NCIDuration)(NCI_DURATION_BEGIN-4)  
/* next special duration */
#define  NCI_DURATION_SESSION (NCIDuration)(NCI_DURATION_BEGIN)  
/* the end of user session */
#define  NCI_DURATION_TRANS (NCIDuration)(NCI_DURATION_BEGIN+1) 

/*-------------------------Object Ptr Types----------------------------------*/
#define NCI_OTYPE_NAME 1                                      /* object name */ 
#define NCI_OTYPE_REF  2                                       /* REF to TDO */ 
#define NCI_OTYPE_PTR  3                                       /* PTR to TDO */ 

/*--------------------------- OCI Parameter Types ---------------------------*/
#define NCI_PTYPE_UNK                 0                         /* unknown   */ 
#define NCI_PTYPE_TABLE               1                         /* table     */ 
#define NCI_PTYPE_VIEW                2                         /* view      */ 
#define NCI_PTYPE_PROC                3                         /* procedure */ 
#define NCI_PTYPE_FUNC                4                         /* function  */ 
#define NCI_PTYPE_PKG                 5                         /* package   */ 
#define NCI_PTYPE_TYPE                6                 /* user-defined type */ 
#define NCI_PTYPE_SYN                 7                         /* synonym   */ 
#define NCI_PTYPE_SEQ                 8                         /* sequence  */ 
#define NCI_PTYPE_COL                 9                         /* column    */ 
#define NCI_PTYPE_ARG                 10                        /* argument  */ 
#define NCI_PTYPE_LIST                11                        /* list      */ 
#define NCI_PTYPE_TYPE_ATTR           12    /* user-defined type's attribute */ 
#define NCI_PTYPE_TYPE_COLL           13        /* collection type's element */ 
#define NCI_PTYPE_TYPE_METHOD         14       /* user-defined type's method */ 
#define NCI_PTYPE_TYPE_ARG            15   /* user-defined type method's arg */ 
#define NCI_PTYPE_TYPE_RESULT         16/* user-defined type method's result */ 
#define NCI_PTYPE_SCHEMA              17                           /* schema */ 
#define NCI_PTYPE_DATABASE            18                         /* database */ 
#define NCI_PTYPE_RULE                19                             /* rule */ 
#define NCI_PTYPE_RULE_SET            20                         /* rule set */ 
#define NCI_PTYPE_EVALUATION_CONTEXT  21               /* evaluation context */ 
#define NCI_PTYPE_TABLE_ALIAS         22                      /* table alias */ 
#define NCI_PTYPE_VARIABLE_TYPE       23                    /* variable type */ 
#define NCI_PTYPE_NAME_VALUE          24                  /* name value pair */ 

/*---------------------------------------------------------------------------*/
/*--------------------- User Callback Return Values -------------------------*/
#define NCI_CONTINUE -24200    /* Continue with the body of the OCI function */ 

enum NCITypeGetOpt
{
    NCI_TYPEGET_HEADER,
    /* load only the header portion of the TDO when getting type */
    NCI_TYPEGET_ALL       /* load all attribute and method descriptors as well */
};
typedef enum NCITypeGetOpt NCITypeGetOpt;
 

/*-----------------------Handle Definitions----------------------------------*/
//typedef struct NCIEnv           NCIEnv;            /* NCI environment handle */
typedef struct NCIEnv           NCIEnv;            /* OCI environment handle */
typedef struct NCIError         NCIError;                /* OCI error handle */
typedef struct NCISvcCtx        NCISvcCtx;             /* OCI service handle */
typedef struct NCIStmt          NCIStmt;             /* OCI statement handle */
typedef struct NCIBind          NCIBind;                  /* OCI bind handle */
typedef struct NCIDefine        NCIDefine;              /* OCI Define handle */
typedef struct NCIDescribe      NCIDescribe;          /* OCI Describe handle */
typedef struct NCIServer        NCIServer;              /* OCI Server handle */
typedef struct NCISession       NCISession;     /* OCI Authentication handle */
typedef struct NCIComplexObject NCIComplexObject;          /* OCI COR handle */
typedef struct NCITrans         NCITrans;          /* OCI Transaction handle */
typedef struct NCISecurity      NCISecurity;          /* OCI Security handle */
typedef struct NCISubscription  NCISubscription;      /* subscription handle */  

typedef struct NCICPool         NCICPool;          /* connection pool handle */
typedef struct NCISPool         NCISPool;             /* session pool handle */
typedef struct NCIAuthInfo      NCIAuthInfo;                  /* auth handle */
typedef struct NCIThreadMutex   NCIThreadMutex;
typedef struct NCIAdmin         NCIAdmin;
typedef struct NCIThreadKey     NCIThreadKey;
typedef struct NCIThreadHandle  NCIThreadHandle;
typedef struct NCIThreadId      NCIThreadId; 

typedef struct NCIResult        NCIResult;      /* OCI Result Set Descriptor */
typedef struct NCILobLocator    NCILobLocator; /* OCI Lob Locator descriptor */
typedef struct NCIParam         NCIParam;        /* OCI PARameter descriptor */ 
typedef struct NCIComplexObjectComp NCIComplexObjectComp;

typedef struct NCIRowid NCIRowid;                    /* OCI ROWID descriptor */

typedef struct NCIDateTime NCIDateTime;           /* OCI DateTime descriptor */
typedef struct NCIInterval NCIInterval;           /* OCI Interval descriptor */

typedef struct NCIString            NCIString; 
typedef struct NCIType        NCIType;

struct NCITime
{
    ub1 NCITimeHH;                          /* hours; range is 0 <= hours <=23 */
    ub1 NCITimeMI;                     /* minutes; range is 0 <= minutes <= 59 */
    ub1 NCITimeSS;                     /* seconds; range is 0 <= seconds <= 59 */
};
typedef struct NCITime NCITime;

struct NCIDate
{
    sb2 NCIDateYYYY;         /* gregorian year; range is -4712 <= year <= 9999 */
    ub1 NCIDateMM;                          /* month; range is 1 <= month < 12 */
    ub1 NCIDateDD;                             /* day; range is 1 <= day <= 31 */
    NCITime NCIDateTime;                                               /* time */
};
typedef struct NCIDate  NCIDate;

typedef struct NCISnapshot      NCISnapshot;   
typedef struct NCIRef           NCIRef;

typedef ub2 NCIDuration; 

typedef struct NCIDirPathCtx      NCIDirPathCtx;                  /* context */
typedef struct NCIDirPathFuncCtx  NCIDirPathFuncCtx;     /* function context */
typedef struct NCIDirPathColArray NCIDirPathColArray;        /* column array */
typedef struct NCIDirPathStream   NCIDirPathStream;                /* stream */
typedef struct NCIDirPathDesc     NCIDirPathDesc;  /* direct path descriptor */

#define NCI_NUMBER_SIZE 22
struct NCINumber
{
    ub1 NINumberPart[NCI_NUMBER_SIZE];
};
typedef struct NCINumber NCINumber;

typedef sb4 (*NCICallbackInBind)(dvoid *ictxp, NCIBind *bindp, ub4 iter, 
                                ub4 index, dvoid **bufpp, ub4 *alenp,
                                ub1 *piecep, dvoid **indp);
typedef sb4 (*NCICallbackOutBind)(dvoid *octxp, NCIBind *bindp, ub4 iter,
                                ub4 index, dvoid **bufpp, ub4 **alenp,
                                ub1 *piecep, dvoid **indp,
                                ub2 **rcodep);
typedef sb4 (*NCICallbackDefine)(dvoid *octxp, NCIDefine *defnp, ub4 iter,
                                dvoid **bufpp, ub4 **alenp, ub1 *piecep,
                                dvoid **indp, ub2 **rcodep);

#define NCIDateGetDate(date, year, month, day) \
{ \
    *year = (date)->NCIDateYYYY; \
    *month = (date)->NCIDateMM; \
    *day = (date)->NCIDateDD; \
}
#define NCIDateSetTime(date, hour, min, sec) \
{ \
    (date)->NCIDateTime.NCITimeHH = hour; \
    (date)->NCIDateTime.NCITimeMI = min; \
    (date)->NCIDateTime.NCITimeSS = sec; \
}
#define NCIDateSetDate(date, year, month, day) \
{ \
    (date)->NCIDateYYYY = year; \
    (date)->NCIDateMM = month; \
    (date)->NCIDateDD = day; \
}
#define NCIDateGetTime(date, hour, min, sec) \
{ \
    *hour = (date)->NCIDateTime.NCITimeHH; \
    *min = (date)->NCIDateTime.NCITimeMI; \
    *sec = (date)->NCIDateTime.NCITimeSS; \
}


#ifndef SQLDEF 
#define SQLT_CHR  1                        /* (ORANET TYPE) character string */
#define SQLT_NUM  2                          /* (ORANET TYPE) oracle numeric */
#define SQLT_INT  3                                 /* (ORANET TYPE) integer */
#define SQLT_FLT  4                   /* (ORANET TYPE) Floating point number */
#define SQLT_STR  5                                /* zero terminated string */
#define SQLT_VNU  6                        /* NUM with preceding length byte */
#define SQLT_PDN  7                  /* (ORANET TYPE) Packed Decimal Numeric */
#define SQLT_LNG  8                                                  /* long */
#define SQLT_VCS  9                             /* Variable character string */
#define SQLT_NON  10                      /* Null/empty PCC Descriptor entry */
#define SQLT_RID  11                                                /* rowid */
#define SQLT_DAT  12                                /* date in oracle format */
#define SQLT_VBI  15                                 /* binary in VCS format */
#define SQLT_BFLOAT 21                                /* Native Binary float*/
#define SQLT_BDOUBLE 22                             /* NAtive binary double */
#define SQLT_BIN  23                                  /* binary data(DTYBIN) */
#define SQLT_LBI  24                                          /* long binary */
#define SQLT_UIN  68                                     /* unsigned integer */
#define SQLT_SLS  91                        /* Display sign leading separate */
#define SQLT_LVC  94                                  /* Longer longs (char) */
#define SQLT_LVB  95                                  /* Longer long binary */ 
#define SQLT_AFC  96                                      /* Ansi fixed char */
#define SQLT_AVC  97                                        /* Ansi Var char */
#define SQLT_IBFLOAT  100                          /* binary float canonical */
#define SQLT_IBDOUBLE 101                         /* binary double canonical */
#define SQLT_CUR  102                                        /* cursor  type */
#define SQLT_RDD  104                                    /* rowid descriptor */
#define SQLT_LAB  105                                          /* label type */
#define SQLT_OSL  106                                        /* oslabel type */

#define SQLT_NTY  108                                   /* named object type */
#define SQLT_REF  110                                            /* ref type */
#define SQLT_CLOB 112                                       /* character lob */
#define SQLT_BLOB 113                                          /* binary lob */
#define SQLT_BFILEE 114                                    /* binary file lob */
#define SQLT_CFILEE 115                                 /* character file lob */
#define SQLT_RSET 116                                     /* result set type */
#define SQLT_NCO  122      /* named collection type (varray or nested table) */
#define SQLT_VST  155                                      /* OCIString type */
#define SQLT_ODT  156                                        /* OCIDate type */

/* datetimes and intervals */
#define SQLT_DATE                      184                      /* ANSI Date */
#define SQLT_TIME                      185                           /* TIME */
#define SQLT_TIME_TZ                   186            /* TIME WITH TIME ZONE */
#define SQLT_TIMESTAMP                 187                      /* TIMESTAMP */
#define SQLT_TIMESTAMP_TZ              188       /* TIMESTAMP WITH TIME ZONE */
#define SQLT_INTERVAL_YM               189         /* INTERVAL YEAR TO MONTH */
#define SQLT_INTERVAL_DS               190         /* INTERVAL DAY TO SECOND */
#define SQLT_TIMESTAMP_LTZ             232        /* TIMESTAMP WITH LOCAL TZ */

#define SQLT_PNTY   241              /* pl/sql representation of named types */

/* CHAR/NCHAR/VARCHAR2/NVARCHAR2/CLOB/NCLOB char set "form" information */
#define SQLCS_IMPLICIT 1     /* for CHAR, VARCHAR2, CLOB w/o a specified set */
#define SQLCS_NCHAR    2                  /* for NCHAR, NCHAR VARYING, NCLOB */
#define SQLCS_EXPLICIT 3   /* for CHAR, etc, with "CHARACTER SET ..." syntax */
#define SQLCS_FLEXIBLE 4                 /* for PL/SQL "flexible" parameters */
#define SQLCS_LIT_NULL 5      /* for typecheck of NULL and empty_clob() lits */
#endif

NCI_API
sword 
NCIConnectionPoolCreate(
    NCIEnv         *envhp,
    NCIError       *errhp, 
    NCICPool       *poolhp,
    OraText        **poolName,
    sb4            *poolNameLen,
    const OraText  *dblink, 
    sb4            dblinkLen,
    ub4            connMin,
    ub4            connMax,
    ub4            connIncr,
    const OraText  *poolUsername,
    sb4            poolUserLen,
    const OraText  *poolPassword,
    sb4            poolPassLen,
    ub4            mode 
);

NCI_API
sword 
NCIEnvCreate(
    NCIEnv       **envhpp,  
    ub4           mode,    
    CONST dvoid   *ctxp,
    CONST dvoid   *(*malocfp) (dvoid    *ctxp,  size_t    size),
    CONST dvoid   *(*ralocfp) (dvoid     *ctxp, dvoid     *memptr,   size_t    newsize),
    CONST void    (*mfreefp)  (dvoid     *ctxp, dvoid      *memptr),
    size_t         xtramemsz,
    dvoid          **usrmempp 
);

NCI_API
sword 
NCIEnvNlsCreate(
    NCIEnv      **envhpp,
    ub4          mode,
    dvoid       *ctxp,
    dvoid       *(*malocfp)
    (dvoid   *ctxp,
    size_t    size),
    dvoid       *(*ralocfp)
    (dvoid    *ctxp,
    dvoid   *memptr,
    size_t   newsize),
    void         (*mfreefp)
    (dvoid   *ctxp,
    dvoid   *memptr),
    size_t        xtramemsz,
    dvoid        **usrmempp,
    ub2          charset,
    ub2          ncharset 
);

NCI_API
sword 
NCITerminate(
    ub4    mode
);

NCI_API
sword 
NCIConnectionPoolDestroy(
    NCICPool     *poolhp,
    NCIError     *errhp, 
    ub4          mode 
);

NCI_API
sword   
NCIEnvInit(
    NCIEnv    **envp, 
    ub4        mode, 
    size_t     xtramem_sz, 
    dvoid      **usrmempp
);

NCI_API
sword   
NCIInitialize (
    ub4      mode, 
	dvoid    *ctxp, 
    dvoid    *(*malocfp)
	(dvoid   *ctxp, 
	size_t   size),
    dvoid    *(*ralocfp)
	(dvoid   *ctxp, 
	dvoid   *memptr, 
	size_t   newsize),
    void   (*mfreefp)
	(dvoid   *ctxp, 
	dvoid    *memptr)
);

NCI_API
sword   
NCILogoff (
    NCISvcCtx   *svchp, 
    NCIError     *errhp
);

NCI_API
sword   
NCILogon (
    NCIEnv     *envhp, 
    NCIError   *errhp, 
    NCISvcCtx  **svchp, 
    CONST NCIText    *username,
    ub4               uname_len, 
    CONST NCIText    *password, 
    ub4               passwd_len, 
    CONST NCIText    *dbname, 
    ub4               dbname_len
);


NCI_API
sword   
NCIServerAttach (
    NCIServer       *srvhp, 
    NCIError        *errhp,
    CONST NCIText *dblink, 
    sb4             dblink_len, 
    ub4             mode
);

NCI_API
sword   
NCIServerDetach (
    NCIServer      *srvhp, 
    NCIError      *errhp, 
    ub4          mode
);

NCI_API
sword   
NCISessionBegin(
    NCISvcCtx    *svchp, 
    NCIError      *errhp, 
    NCISession    *usrhp,
    ub4           credt, 
    ub4           mode
);

NCI_API
sword   
NCISessionEnd (
    NCISvcCtx    *svchp, 
    NCIError      *errhp, 
    NCISession    *usrhp, 
    ub4           mode
);

NCI_API
sword   
NCIAttrGet(
    CONST dvoid   *trgthndlp, 
    ub4           trghndltyp, 
    dvoid         *attributep, 
    ub4           *sizep, 
    ub4           attrtype, 
    NCIError      *errhp
);

NCI_API
sword   
NCIAttrSet(
    dvoid       *trgthndlp, 
    ub4         trghndltyp, 
    dvoid       *attributep,
    ub4         size, 
    ub4         attrtype, 
    NCIError    *errhp
);

NCI_API
sword   
NCIDescriptorAlloc(
    CONST dvoid   *parenth, 
    dvoid          **descpp, 
    CONST ub4     type, 
    CONST size_t   xtramem_sz, 
    dvoid          **usrmempp
);

NCI_API
sword   
NCIDescriptorFree(
    dvoid        *descp, 
    CONST ub4   type
);

NCI_API
sword   
NCIHandleAlloc(
    dvoid        *parenth, 
    dvoid        **hndlpp, 
    CONST ub4   type, 
    CONST size_t   xtramem_sz, 
    dvoid          **usrmempp
);

NCI_API
sword 
NCIHandleFree ( 
    void      *hndlp,
    ub4       type 
);

NCI_API
sword   
NCIParamGet(
    CONST dvoid     *hndlp, 
    ub4              htype, 
    NCIError         *errhp, 
    dvoid            **parmdpp, 
    ub4              pos
);

NCI_API
sword 
NCIParamSet ( 
    dvoid           *hndlp,
    ub4            htype,
    NCIError        *errhp,
    CONST dvoid    *dscp,
    ub4            dtyp,
    ub4            pos 
);

NCI_API
sword   
NCIBindArrayOfStruct(
    NCIBind    *bindp, 
    NCIError   *errhp, 
    ub4        pvskip, 
    ub4        indskip,
    ub4        alskip, 
    ub4        rcskip
);

NCI_API
sword       
NCIBindByName (
    NCIStmt       *stmtp, 
    NCIBind       **bindp, 
    NCIError       *errhp,
    CONST NCIText *placeholder, 
    sb4            placeh_len, 
    dvoid          *valuep, 
    sb4            value_sz, 
    ub2            dty, 
    dvoid          *indp, 
    ub2            *alenp, 
    ub2            *rcodep, 
    ub4            maxarr_len, 
    ub4            *curelep, 
    ub4            mode
);

NCI_API
sword   
NCIBindByPos (
    NCIStmt         *stmtp, 
    NCIBind        **bindp, 
    NCIError        *errhp,
    ub4             position, 
    dvoid           *valuep, 
    sb4             value_sz,
    ub2            dty, 
    dvoid          *indp, 
    ub2            *alenp, 
    ub2            *rcodep,
    ub4            maxarr_len, 
    ub4            *curelep, 
    ub4            mode
);

NCI_API
sword     
NCIBindDynamic ( 
    NCIBind     *bindp,
    NCIError    *errhp,
    dvoid       *ictxp, 
    NCICallbackInBind   icbfp,
    dvoid*          octxp,
    NCICallbackOutBind  ocbfp
);

NCI_API
sword      
NCIBindObject ( 
    NCIBind          *bindp,
    NCIError         *errhp, 
    CONST NCIType    *type,
    dvoid            **pgvpp, 
    ub4              *pvszsp, 
    dvoid            **indpp, 
    ub4              *indszp  
);

NCI_API
sword    
NCIDefineArrayOfStruct (
    NCIDefine     *defnp, 
    NCIError      *errhp, 
    ub4           pvskip,
    ub4           indskip, 
    ub4           rlskip, 
    ub4           rcskip
);

NCI_API
sword   
NCIDefineByPos(
    NCIStmt     *stmtp, 
    NCIDefine   **defnp, 
    NCIError     *errhp,
    ub4          position, 
    dvoid        *valuep, 
    sb4          value_sz, 
    ub2          dty,
    dvoid        *indp, 
    ub2          *rlenp, 
    ub2          *rcodep, 
    ub4          mode
);

NCI_API
sword      
NCIDefineDynamic ( 
    NCIDefine   *defnp,
    NCIError    *errhp,
    dvoid       *octxp, 
    NCICallbackDefine       ocbfp  
);

NCI_API
sword 
NCIDefineObject ( 
    NCIDefine       *defnp,
    NCIError        *errhp,
    CONST NCIType   *type,
    dvoid           **pgvpp, 
    ub4             *pvszsp, 
    dvoid           **indpp, 
    ub4             *indszp 
);

NCI_API
sword   
NCIDescribeAny (
    NCISvcCtx *svchp, 
    NCIError *errhp, 
    dvoid *objptr, 
    ub4 objnm_len, 
    ub1 objptr_typ, 
    ub1 info_level,
    ub1 objtyp, 
    NCIDescribe *dschp
);

NCI_API
sword 
NCIStmtGetBindInfo (
    NCIStmt      *stmtp,
    NCIError     *errhp,
    ub4          size,
    ub4          startloc,
    sb4          *found,
    text         *bvnp[],
    ub1          bvnl[],
    text         *invp[],
    ub1          inpl[],
    ub1          dupl[],
    NCIBind      *hndl[]
);

NCI_API
sword   
NCIStmtExecute (
    NCISvcCtx       *svchp, 
    NCIStmt         *stmtp, 
    NCIError        *errhp, 
    ub4             iters, 
    ub4             rowoff, 
    CONST NCISnapshot *snap_in, 
    NCISnapshot *snap_out, 
    ub4 mode
);

NCI_API
sword   
NCIStmtFetch (
    NCIStmt        *stmtp, 
    NCIError       *errhp, 
    ub4            nrows, 
    ub2            orientation, 
    ub4            mode
);

NCI_API
sword  
NCIStmtFetchRow ( 
    NCIStmt     *stmthp,
    NCIError     *errhp, 
    ub4          nrows,
    ub2          orientation,
    sb4          fetchOffset,
    ub4          mode 
);

NCI_API
sword 
NCIStmtGetPieceInfo ( 
    CONST NCIStmt  *stmtp,
    NCIError        *errhp,
    dvoid           **hndlpp,
    ub4             *typep,
    ub1             *in_outp,
    ub4             *iterp, 
    ub4             *idxp,
    ub1             *piecep 
);

NCI_API
sword   
NCIStmtPrepare (
    NCIStmt       *stmtp, 
    NCIError      *errhp, 
    NCIText       *stmt,
    ub4           stmt_len, 
    ub4           language, 
    ub4           mode
);

NCI_API
sword 
NCIStmtPrepareWithCache (
    NCISvcCtx       *svchp,
    NCIStmt         **stmthp,
    NCIError        *errhp,
    CONST OraText  *stmttext,
    ub4             stmt_len,
    CONST OraText  *key,
    ub4             keylen,
    ub4             language,
    ub4             mode 
);

NCI_API
sword 
NCIStmtRelease (  
    NCIStmt         *stmthp,  
    NCIError        *errhp,
    CONST OraText  *key,
    ub4             keylen,
    ub4             mode 
);  

NCI_API
sword 
NCIStmtSetPieceInfo ( 
    dvoid             *hndlp,
    ub4               type,
    NCIError          *errhp,
    CONST dvoid      *bufp,
    ub4               *alenp, 
    ub1               piece,
    CONST dvoid      *indp, 
    ub2               *rcodep 
); 

NCI_API
sword 
NCILobDurationBegin ( 
    NCIEnv            *env,
    NCIError           *err,
    CONST NCISvcCtx  *svc, 
    NCIDuration        parent,
    NCIDuration        *duration 
);

NCI_API
sword 
NCILobDurationEnd(
    NCIEnv              *env,
    NCIError            *err,
    CONST NCISvcCtx     *svc, 
    NCIDuration         duration  
);

NCI_API
sword 
    NCILobAppend ( 
    NCISvcCtx        *svchp,
    NCIError          *errhp,
    NCILobLocator     *dst_locp,
    NCILobLocator     *src_locp 
);

NCI_API
sword 
NCILobAssign ( 
    NCIEnv                *envhp, 
    NCIError               *errhp, 
    CONST NCILobLocator   *src_locp, 
    NCILobLocator          **dst_locpp 
);

NCI_API
sword 
NCILobCharSetForm ( 
    NCIEnv                *envhp, 
    NCIError              *errhp, 
    CONST NCILobLocator   *locp, 
    ub1                   *csfrm 
);

NCI_API
sword 
NCILobCharSetId ( 
    NCIEnv                  *envhp, 
    NCIError                 *errhp, 
    CONST NCILobLocator     *locp, 
    ub2                      *csid 
);

NCI_API
sword 
NCILobClose ( 
    NCISvcCtx      *svchp,
    NCIError       *errhp, 
    NCILobLocator  *locp 
);

NCI_API
sword 
NCILobCopy ( 
    NCISvcCtx        *svchp,
    NCIError          *errhp,
    NCILobLocator     *dst_locp,
    NCILobLocator     *src_locp,
    ub4               amount,
    ub4               dst_offset,
    ub4               src_offset 
);

NCI_API
sword 
NCILobCreateTemporary (
    NCISvcCtx          *svchp,
    NCIError           *errhp,
    NCILobLocator      *locp,
    ub2                 csid,
    ub1                 csfrm,
    ub1                 lobtype,
    int                 cache,
    NCIDuration         duration
);

NCI_API
sword 
NCILobDisableBuffering ( 
    NCISvcCtx      *svchp, 
    NCIError       *errhp, 
    NCILobLocator  *locp 
); 

NCI_API
sword 
NCILobEnableBuffering ( 
    NCISvcCtx     *svchp,
    NCIError       *errhp, 
    NCILobLocator  *locp
);

NCI_API
sword 
NCILobErase (
    NCISvcCtx     *svchp,
    NCIError       *errhp, 
    NCILobLocator  *locp,
    ub4           *amount,
    ub4            offset
);

NCI_API
sword 
NCILobFileClose (
    NCISvcCtx     *svchp,
    NCIError        *errhp, 
    NCILobLocator   *filep
);

NCI_API
sword 
NCILobFileCloseAll(
    NCISvcCtx     *svchp,
    NCIError        *errhp
);

NCI_API
sword 
NCILobFileExists(
    NCISvcCtx     *svchp,
    NCIError       *errhp,
    NCILobLocator  *filep,
    int             *flag
);

NCI_API
sword 
NCILobFileGetName(
    NCIEnv  	         *envhp,
    NCIError	    	     *errhp,
    CONST NCILobLocator  *filep,
    text	         		 *dir_alias,
    ub2					 *d_length,
    text					 *filename,
    ub2					 *f_length
);

NCI_API
sword 
NCILobFileIsOpen(
    NCISvcCtx  	         *svchp,
    NCIError	    	 *errhp,
    NCILobLocator  	     *filep,
    int	                 *flag
);

NCI_API
sword 
NCILobFileOpen(
    NCISvcCtx  	         *svchp,
    NCIError	    	     *errhp,
    NCILobLocator  	     *filep,
    ub1	                 mode
);

NCI_API
sword 
NCILobFileSetName(
    NCIEnv  	         *envhp,
    NCIError	    	 *errhp,
    NCILobLocator  	 **filepp,
    CONST text       *dir_alias,
    ub2	             d_length,
    CONST text       *filename,
    ub2              f_length
);

NCI_API 
sword 
NCILobFlushBuffer(
    NCISvcCtx  	     *svchp,
    NCIError	    	 *errhp,
    NCILobLocator  	 *locp,
    ub4              flag
);

NCI_API
sword 
    NCILobFreeTemporary(
    NCISvcCtx 	     *svchp,
    NCIError	     *errhp,
    NCILobLocator  	 *locp
);

NCI_API
sword 
    NCILobGetChunkSize(
    NCISvcCtx 	     *svchp,
    NCIError	     *errhp,
    NCILobLocator  	 *locp,
    ub4              *chunk_size 
);

NCI_API
sword 
NCILobGetLength(
    NCISvcCtx 	     *svchp,
    NCIError	     *errhp,
    NCILobLocator  	 *locp,
    ub4              *lenp 
);

NCI_API
sword 
NCILobIsEqual(
    NCIEnv 	     			     *envhp,
    CONST NCILobLocator    	     *x,
    CONST NCILobLocator  	     *y,
    int             		     *is_equal
);

NCI_API
sword 
NCILobIsOpen(
    NCISvcCtx	     			 *svchp,
    NCIError			    	 *errhp,
    NCILobLocator		  	 *locp,
    int             		 *flag
);

NCI_API
sword 
NCILobIsTemporary(
    NCIEnv     			 *envhp,
    NCIError			    	 *errhp,
    NCILobLocator		  	 *locp,
    int             		 *is_temporary
);

NCI_API
sword 
NCILobLoadFromFile(
    NCISvcCtx   		 *svchp,
    NCIError			    	 *errhp,
    NCILobLocator		  	 *dst_locp,
    NCILobLocator		  	 *src_locp,
    ub4						 amount,
    ub4						 dst_offset,
    ub4						 src_offset
);

NCI_API
sword 
NCILobLocatorAssign(
    NCISvcCtx   		 *svchp,
    NCIError			    	 *errhp,
    CONST NCILobLocator	  	 *src_locp,
    NCILobLocator		  	 **dst_locpp
);

NCI_API
sword 
NCILobLocatorIsInit(
    NCIEnv     			 *envhp,
    NCIError			    	 *errhp,
    CONST NCILobLocator	  	 *locp,
    int             		 *is_initialized
);

NCI_API
sword 
NCILobOpen(
    NCISvcCtx     			 *svchp,
    NCIError			     *errhp,
    NCILobLocator	  	 *locp,
    ub1             	 mode
);

NCI_API
sword
NCILobRead(
    NCISvcCtx     			 *svchp,
    NCIError		    	 *errhp,
    NCILobLocator	  	 *locp,
    ub4        		     *amtp,
    ub4                  offset,
    dvoid                *bufp,
    ub4                  bufl,
    dvoid                *ctxp,
    sb4                 (*cbfp)    
    (dvoid         *ctxp, 
    CONST dvoid   *bufp, 
    ub4            len,
    ub1            piece) ,
    ub2                  csid,
    ub1                  csfrm
);

NCI_API
sword 
NCILobTrim(
    NCISvcCtx     			 *svchp,
    NCIError			     *errhp,
    NCILobLocator	  	 *locp,
    ub4             	 newlen
);

NCI_API
sword 
NCILobWrite(
    NCISvcCtx     			 *svchp,
    NCIError			     *errhp,
    NCILobLocator	  	 *locp,
    ub4             	 *amtp,
    ub4					 *offset,
    dvoid				 *bufp,
    ub4					 buflen,
    ub1					 piece,
    dvoid				 *ctxp,
    sb4                 (*cbfp)
    ( 
    dvoid  *ctxp,
    dvoid  *bufp,
    ub4    *lenp,
    ub1	   *piecep  ),
    ub2				  csid,
    ub1				  csfrm
);

NCI_API
sword 
NCILobWriteAppend(
    NCISvcCtx     	 *svchp,
    NCIError			     *errhp,
    NCILobLocator	  	 *locp,
    ub4             	 *amtp,
    dvoid				 *bufp,
    ub4					 buflen,
    ub1					 piece,
    dvoid				 *ctxp,
    sb4                 (*cbfp)
    ( 
    dvoid  *ctxp,
    dvoid  *bufp,
    ub4    *lenp,
    ub1	   *piecep  ),
    ub2				  csid,
    ub1				  csfrm
);

NCI_API
sword	
NCIDirPathAbort(
    NCIDirPathCtx      *dpctx,
    NCIError           *errhp
);

NCI_API
sword 
NCIDirPathColArrayEntryGet ( 
    NCIDirPathColArray   *dpca,
    NCIError             *errhp,
    ub4                  rownum,
    ub2                  colIdx,
    ub1                  **cvalpp,
    ub4                  *clenp,
    ub1                  *cflgp
);

NCI_API
sword	
NCIDirPathColArrayEntrySet(
    NCIDirPathColArray *dpca, 
	NCIError *errhp,
    ub4 rownum, 
	ub2 colIdx, 
	ub1 *cvalp, 
	ub4 clen,
    ub1 cflg
);  

NCI_API
sword 
NCIDirPathColArrayRowGet( 
    NCIDirPathColArray   *dpca,
    NCIError             *errhp,
    ub4                  rownum,
    ub1                  ***cvalppp,
    ub4                  **clenpp,
    ub1                  **cflgpp 
);

NCI_API
sword	
NCIDirPathColArrayReset(
    NCIDirPathColArray *dpca, 
    NCIError *errhp
);

NCI_API
sword	
NCIDirPathColArrayToStream(
    NCIDirPathColArray   *dpca,
    NCIDirPathCtx       *dpctx,
    NCIDirPathStream    *dpstr, 
    NCIError           *errhp,
    ub4                rowcnt, 
    ub4                rowoff
);

NCI_API
sword	
NCIDirPathDataSave(
    NCIDirPathCtx   *dpctx, 
    NCIError       *errhp, 
    ub4            action
);

NCI_API
sword	
NCIDirPathFinish(
    NCIDirPathCtx   *dpctx,
 	NCIError       *errhp
);

NCI_API
sword 
NCIDirPathFlushRow (
    NCIDirPathCtx          *dpctx,
    NCIError               *errhp 
);

NCI_API
sword	
NCIDirPathLoadStream(
    NCIDirPathCtx       *dpctx,
    NCIDirPathStream   *dpstr,
    NCIError           *errhp
);

NCI_API
sword	
NCIDirPathPrepare(
    NCIDirPathCtx    *dpctx, 
    NCISvcCtx       *svchp,
    NCIError        *errhp
);

NCI_API
sword	
NCIDirPathStreamReset(
    NCIDirPathStream   *dpstr, 
    NCIError          *errhp
);

NCI_API
sword   
NCITransCommit(
    NCISvcCtx    *svchp, 
    NCIError     *errhp, 
    ub4          flags
);

NCI_API
sword   
NCITransRollback(
    NCISvcCtx     *svchp, 
    NCIError      *errhp, 
    ub4           flags
);

NCI_API
sword 
NCITransStart ( 
    NCISvcCtx    *svchp, 
    NCIError     *errhp, 
    uword        timeout,
    ub4          flags 
);

NCI_API
sword 
NCIDateAddDays ( 
    NCIError          *err,
    CONST NCIDate     *date, 
    sb4               num_days,
    NCIDate           *result 
);

NCI_API
sword 
NCIDateAddMonths ( 
    NCIError            *err,
    CONST NCIDate       *date,
    sb4                 num_months,
    NCIDate             *result 
);

NCI_API
sword 
NCIDateAssign ( 
    NCIError         *err,
    CONST NCIDate    *from, 
    NCIDate          *to 
);

NCI_API
sword 
NCIDateCheck ( 
    NCIError          *err,
    CONST NCIDate     *date, 
    uword             *valid 
);

NCI_API
sword 
NCIDateCompare ( 
    NCIError           *err, 
    CONST NCIDate      *date1, 
    CONST NCIDate      *date2,
    sword              *result 
);

NCI_API
sword 
NCIDateDaysBetween ( 
    NCIError            *err, 
    CONST NCIDate       *date1, 
    CONST NCIDate       *date2, 
    sb4                 *num_days 
);

NCI_API
sword 
NCIDateFromText ( 
    NCIError           *err,
    CONST text         *date_str, 
    ub4                d_str_length, 
    CONST text         *fmt,
    ub1                fmt_length, 
    CONST text         *lang_name,
    ub4                lang_length, 
    NCIDate            *date 
);

NCI_API
sword 
NCIDateLastDay ( 
    NCIError            *err,
    CONST NCIDate       *date, 
    NCIDate             *next_day
);

NCI_API
sword 
NCIDateNextDay ( 
    NCIError            *err,
    CONST NCIDate       *date,
    CONST OraText       *day, 
    ub4                 day_length,
    NCIDate             *next_day 
);

NCI_API
sword 
NCIDateSysDate ( 
    NCIError       *err,
    NCIDate        *sys_date 
);

NCI_API
sword 
NCIDateToText ( 
    NCIError                  *err, 
    CONST NCIDate             *date, 
    CONST OraText             *fmt, 
    ub1                       fmt_length, 
    CONST OraText             *lang_name,
    ub4                       lang_length, 
    ub4                       *buf_size, 
    OraText                   *buf 
);

NCI_API  
sword 
NCIDateTimeAssign ( 
    dvoid               *hndl, 
    NCIError            *err,
    CONST NCIDateTime   *from,
    NCIDateTime         *to 
);

NCI_API
sword 
NCIDateTimeCheck ( 
    dvoid               *hndl,
    NCIError            *err, 
    CONST NCIDateTime   *date, 
    ub4                 *valid 
);

NCI_API
sword 
NCIDateTimeCompare ( 
    dvoid              *hndl,
    NCIError           *err,
    CONST NCIDateTime  *date1, 
    CONST NCIDateTime  *date2,
    sword              *result 
);

NCI_API
sword 
NCIDateTimeConstruct ( 
    dvoid         *hndl,
    NCIError      *err,
    NCIDateTime   *datetime,
    sb2           year,
    ub1           month,
    ub1           day,
    ub1           hour,
    ub1           min,
    ub1           sec,
    ub4           fsec,
    OraText       *timezone,
    size_t        timezone_length 
);

NCI_API
sword 
NCIDateTimeConvert ( 
    dvoid        *hndl,
    NCIError     *err, 
    NCIDateTime  *indate, 
    NCIDateTime  *outdate 
);

NCI_API
sword 
NCIDateTimeFromArray ( 
    dvoid              *hndl,
    NCIError           *err, 
    CONST ub1          *inarray,
    ub4                *len, 
    ub1                type,
    NCIDateTime        *datetime,
    CONST NCIInterval  *reftz,
    ub1                fsprec 
);

NCI_API
sword 
NCIDateTimeFromText ( 
    dvoid              *hndl,
    NCIError           *err, 
    CONST OraText      *date_str,
    size_t             dstr_length,
    CONST OraText      *fmt,
    ub1                fmt_length, 
    CONST OraText      *lang_name,
    size_t             lang_length, 
    NCIDateTime        *datetime 
);

NCI_API
sword
NCIDateTimeGetDate ( 
    dvoid              *hndl,
    NCIError           *err, 
    CONST NCIDateTime  *datetime,
    sb2                *year, 
    ub1                *month, 
    ub1                *day 
);

NCI_API
sword 
NCIDateTimeGetTime ( 
    dvoid         *hndl, 
    NCIError      *err, 
    NCIDateTime   *datetime, 
    ub1           *hour,
    ub1           *min, 
    ub1           *sec, 
    ub4           *fsec 
);

NCI_API
sword 
NCIDateTimeGetTimeZoneName ( 
    dvoid              *hndl, 
    NCIError           *err, 
    CONST NCIDateTime  *datetime, 
    ub1                *buf,
    ub4                *buflen 
);

NCI_API
sword
NCIDateTimeGetTimeZoneOffset ( 
    dvoid              *hndl, 
    NCIError           *err, 
    CONST NCIDateTime  *datetime, 
    sb1                *hour,
    sb1                *min  
);

NCI_API
sword 
NCIDateTimeIntervalAdd ( 
    dvoid        *hndl, 
    NCIError     *err, 
    NCIDateTime  *datetime, 
    NCIInterval  *inter, 
    NCIDateTime  *outdatetime 
);


NCI_API
sword 
NCIDateTimeIntervalSub ( 
    dvoid        *hndl,
    NCIError     *err, 
    NCIDateTime  *datetime, 
    NCIInterval  *inter,
    NCIDateTime  *outdatetime
);

NCI_API
sword 
NCIDateTimeSubtract ( 
    dvoid        *hndl, 
    NCIError     *err,
    NCIDateTime  *indate1,
    NCIDateTime  *indate2, 
    NCIInterval  *inter 
);

NCI_API
sword 
NCIDateTimeSysTimeStamp ( 
    dvoid          *hndl,
    NCIError       *err, 
    NCIDateTime    *sys_date 
);

NCI_API
sword 
NCIDateTimeToArray ( 
    dvoid              *hndl,
    NCIError           *err, 
    CONST NCIDateTime  *datetime, 
    CONST NCIInterval  *reftz,
    ub1                *outarray, 
    ub4                *len, 
    ub1                fsprec 
);

NCI_API
sword 
NCIDateTimeToText ( 
    dvoid               *hndl, 
    NCIError            *err, 
    CONST NCIDateTime   *date, 
    CONST OraText       *fmt,
    ub1                 fmt_length, 
    ub1                 fsprec,
    CONST OraText       *lang_name, 
    size_t              lang_length, 
    ub4                 *buf_size, 
    OraText             *buf 
);

NCI_API
sword 
NCIDateZoneToZone ( 
    NCIError           *err, 
    CONST NCIDate      *date1, 
    CONST OraText      *zon1,
    ub4                zon1_length, 
    CONST OraText      *zon2, 
    ub4                zon2_length, 
    NCIDate            *date2 
);

NCI_API
sword
NCIIntervalAdd ( 
    dvoid        *hndl, 
    NCIError     *err, 
    NCIInterval  *addend1, 
    NCIInterval  *addend2, 
    NCIInterval  *result 
);

NCI_API
void 
NCIIntervalAssign ( 
    dvoid             *hndl, 
    NCIError          *err, 
    CONST NCIInterval *inpinter, 
    NCIInterval       *outinter 
);

NCI_API
sword 
NCIIntervalCheck ( 
    dvoid              *hndl,
    NCIError            *err,
    CONST NCIInterval   *interval,
    ub4                 *valid 
);

NCI_API
sword 
NCIIntervalCompare( 
    dvoid         *hndl, 
    NCIError      *err,
    NCIInterval   *inter1, 
    NCIInterval   *inter2, 
    sword         *result 
);

NCI_API
sword 
NCIIntervalDivide ( 
    dvoid        *hndl, 
    NCIError     *err, 
    NCIInterval  *dividend, 
    NCINumber    *divisor, 
    NCIInterval  *result 
);

NCI_API
sword
NCIIntervalFromNumber ( 
    dvoid            *hndl, 
    NCIError           *err,
    NCIInterval        *interval,
    NCINumber          *number 
);

NCI_API
sword 
NCIIntervalFromText ( 
    dvoid          *hndl, 
    NCIError       *err, 
    CONST OraText  *inpstring,
    size_t         str_len,
    NCIInterval    *result 
);

NCI_API
sword 
NCIIntervalFromTZ ( 
    dvoid          *hndl, 
    NCIError       *err, 
    CONST oratext  *inpstring,
    size_t         str_len, 
    NCIInterval    *result 
) ;

NCI_API
sword 
NCIIntervalGetDaySecond (
    dvoid              *hndl, 
    NCIError           *err, 
    sb4                *dy, 
    sb4                *hr,
    sb4                *mm, 
    sb4                *ss, 
    sb4                *fsec, 
    CONST NCIInterval  *interval 
);

NCI_API
sword 
NCIIntervalGetYearMonth ( 
    dvoid              *hndl, 
    NCIError           *err, 
    sb4                *yr,
    sb4                *mnth,
    CONST NCIInterval  *interval 
);

NCI_API
sword 
NCIIntervalMultiply ( 
    dvoid              *hndl, 
    NCIError           *err, 
    CONST NCIInterval  *inter,
    NCINumber          *nfactor,
    NCIInterval        *result 
);

NCI_API
sword
NCIIntervalSetDaySecond ( 
    dvoid              *hndl, 
    NCIError           *err, 
    sb4                dy,
    sb4                hr,
    sb4                mm, 
    sb4                ss, 
    sb4                fsec, 
    NCIInterval        *result 
);

NCI_API
sword 
NCIIntervalSetYearMonth ( 
    dvoid              *hndl, 
    NCIError           *err, 
    sb4                yr,
    sb4                mnth,
    NCIInterval        *result 
);

NCI_API
sword 
NCIIntervalSubtract (
    dvoid        *hndl,
    NCIError     *err, 
    NCIInterval  *minuend, 
    NCIInterval  *subtrahend,
    NCIInterval  *result 
);

NCI_API
sword 
NCIIntervalToNumber ( 
    dvoid              *hndl, 
    NCIError           *err,
    NCIInterval        *interval,
    NCINumber          *number 
);

NCI_API
sword 
NCIIntervalToText (
    dvoid              *hndl,
    NCIError           *err,
    CONST NCIInterval  *interval,
    ub1                lfprec,
    ub1                fsprec,
    OraText            *buffer, 
    size_t             buflen,
    size_t             *resultlen 
);

NCI_API
sword 
NCIStringAllocSize ( 
    NCIEnv              *env,
    NCIError            *err, 
    CONST NCIString     *vs,
    ub4                 *allocsize 
); 

NCI_API
sword 
NCIStringAssign ( 
    NCIEnv               *env, 
    NCIError             *err, 
    CONST NCIString      *rhs, 
    NCIString            **lhs 
);

NCI_API
sword 
NCIStringAssignText ( 
    NCIEnv           *env,
    NCIError         *err, 
    CONST OraText    *rhs, 
    ub2              rhs_len,
    NCIString         **lhs 
);

NCI_API
text *
NCIStringPtr ( 
    NCIEnv               *env,
    CONST NCIString      *vs 
);

NCI_API
sword 
NCIStringResize ( 
    NCIEnv          *env,
    NCIError        *err,
    ub4             new_size,
    NCIString        **str 
);

NCI_API
ub4 
NCIStringSize ( 
    NCIEnv              *env,
    CONST NCIString     *vs 
);

NCI_API
sword   
NCIErrorGet (
    dvoid     *hndlp, 
    ub4       recordno, 
    NCIText    *sqlstate,
    sb4       *errcodep, 
    NCIText   *bufp, 
    ub4        bufsiz, 
    ub4        type
);

NCI_API
sword 
NCINlsEnvironmentVariableGet( 
    dvoid     *val,
    size_t    size,
    ub2       item,
    ub2       *charset, 
    size_t    *rsize 
);

NCI_API
sword 
NCIPasswordChange ( 
    NCISvcCtx     *svchp,
    NCIError      *errhp,
    CONST text    *user_name,
    ub4           usernm_len,
    CONST text    *opasswd,
    ub4           opasswd_len,
    CONST text    *npasswd,
    sb4           npasswd_len,
    ub4           mode 
);

NCI_API
sword 
NCIRowidToChar ( 
    NCIRowid      *rowidDesc,
    OraText       *outbfp,
    ub2           *outbflp,
    NCIError      *errhp 
);

NCI_API
sword     
NCIServerVersion ( 
    dvoid        *hndlp, 
    NCIError     *errhp, 
    text         *bufp,
    ub4          bufsz,
    ub1          hndltype 
); 

NCI_API
sword 
NCITypeArrayByName(
    NCIEnv*             envhp,
    NCIError*           errhp,
    const NCISvcCtx*    svc,
    ub4                 array_len,
    const OraText*      schema_name[],
    ub4                 s_length[],
    const OraText*      type_name[],
    ub4                 t_length[],
    const OraText*      version_name[],
    ub4                 v_length[],
    NCIDuration         pin_duration,
    NCITypeGetOpt       get_option,
    NCIType*            tdo[]
);

NCI_API
sword 
NCITypeArrayByRef (
    NCIEnv*         envhp,
    NCIError*       errhp,
    ub4             array_len,
    const NCIRef*   type_ref[],
    NCIDuration     pin_duration,
    NCITypeGetOpt   get_option,
    NCIType*        tdo[]
);

NCI_API
sword 
NCITypeByName (
    NCIEnv*             env,
    NCIError*           err, 
    const NCISvcCtx*    svc, 
    const OraText*      schema_name,
    ub4                 s_length, 
    const OraText*      type_name, 
    ub4                 t_length, 
    const OraText*      version_name,
    ub4                 v_length,
    NCIDuration         pin_duration,
    NCITypeGetOpt       get_option,
    NCIType**           tdo 
);

NCI_API
sword 
NCITypeByRef (
    NCIEnv*         env,
    NCIError*       err,
    const NCIRef*   type_ref,
    NCIDuration     pin_duration,
    NCITypeGetOpt   get_option,
    NCIType**       tdo 
);

NCI_API
cbool  
CryptoInit(
    void**   crypto_para
); 

NCI_API
void   
CryptoDestroy(
    void*	crypto_para
); 

NCI_API
cbool  
CryptoCipherEncryptInit(
    nusint 	inner_id,
    void*	crypto_para,
    unsigned char*	key,
    nusint 	key_size,
    void**	encrypt_para
);

NCI_API
nlint  
CryptoCipherGetCipherextSize(
    nusint 	inner_id,
    void*	crypto_para,
    void*	encrypt_para,
    nlint	plain_text_size
); 

NCI_API
nlint 
CryptoCipherEncrypt(
    nusint	inner_id,
    void*	crypto_para,
    void*	encrypt_para,
    unsigned char*	plain_text,
    nusint  	plain_text_size,
    unsigned char*	cipher_text,
    nusint 	cipher_text_buf_size
); 

NCI_API
void 
CryptoCipherCleanup(
    nusint 	inner_id,
    void*	crypto_para,
    void*	cipher_para
); 

NCI_API
cbool 
CryptoCipherDecryptInit(
    nusint	inner_id,
    void*	crypto_para,
    unsigned char*	key,
    nusint	key_size,
    void**	decrypt_para
);

NCI_API
nlint  
CryptoCipherGetPlainTextSize(
    nusint 	inner_id,
    void*	crypto_para,
    void*	decrypt_para,
    nlint	cipher_text_size
);

NCI_API
nlint 
CryptoCipherEncrypt(
    nusint	inner_id,
    void*	crypto_para,
    void*	encrypt_para,
    unsigned char*	plain_text,
    nusint  	plain_text_size,
    unsigned char*	cipher_text,
    nusint 	cipher_text_buf_size
);

NCI_API
nlint  
CryptoCipherDecrypt(
    nusint	inner_id,
    void*	crypto_para,
    void*	decrypt_para,
    unsigned char*	cipher_text,
    nusint	cipher_text_size,
    unsigned char*	plain_text,
    nusint	plain_text_buf_size
);  

NCI_API
cbool  
CryptoCipherHashInit(
    nusint 	inner_id,
    void*	crypto_para,
    void**	hash_para
);

NCI_API
void  
CryptoCipherHashUpdate(
    nusint	inner_id,
    void*	crypto_para,
    void*	hash_para,
    unsigned char*	msg,
    nusint	msg_size
);

NCI_API
nlint   
CryptoCipherHashFinal(
    nusint 	inner_id,
    void*	crypto_para,
    void*	hash_para,
    unsigned char*	digest,
    nusint	digest_buf_size
);

#endif
