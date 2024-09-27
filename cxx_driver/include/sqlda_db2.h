
#ifndef SQLDA_DB2_H             /* Permit duplicate Includes                 */
#define SQLDA_DB2_H

//#include "sqlsystm.h"          /* System-Specific Include                   */
/* _SQLOLDCHAR defaults to 'char'.  See sqlsystm.h for details. */

#ifdef WIN32
#include <stddef.h>
#endif

#include "DPI.h"
/*
#if (defined(DB2OS2) || defined(DB2NT))
#if defined _WIN64
#pragma pack(8)
#else
#pragma pack(4)
#endif
#elif (defined(DB2WIN))
#pragma pack(2)
#elif (defined(DB2MAC))
#if (defined(DB2PPC))
#pragma align 4
#elif (defined(DB268K))
#pragma align 2
#endif
#elif (defined(DB2HP) || defined(DB2SNI))

#elif (defined(DB2SUN) && defined(__xlC__))
#pragma options align=natural
#elif (defined(DB2AIX) && defined(__64BIT__))
#pragma options align=natural
#elif (defined(DB2AIX))
#pragma options align=power
#endif*/

/* define identifier */
#define NAMELEN			    128
#define PATHLEN             256
//typedef char               sysname_t[NAMELEN + 1];

//typedef unsigned int     dmbool;

/* SQLDA: SQL Descriptor Area - Variable descriptor                             */
typedef struct sqlname  sqlname_t;
struct  sqlname                             /* Variable Name                    */
{
    sdint2          length;                 /* Name length [1..128]             */
    sysname_t       data;                   /* Variable or Column name          */
};

/* Structure for any user-defined types:                                        */
/*   Distinct types, structured types, and reference types                      */
typedef struct sqldistinct_type sqluser_def_type;
struct  sqldistinct_type                    /* Name of user-defined type        */
{
    sdint2          length;                 /* Name length [1..128]             */
    sysname_t       data;                   /* Name of user-defined type        */
    sdbyte          reserved1[3];           /* reserved                         */
};

typedef struct sqlvar   sqlvar_t;
struct  sqlvar                              /* Variable Description             */
{
    sdint2              sqltype;                /* Variable data type               */
    sdint2              sqllen;                 /* Variable data length             */
    sdbyte*             sqldata;                /* Pointer to variable data value   */
    sdint2*             sqlind;                 /* Pointer to Null indicator        */
    sqlname_t           sqlname;                /* Variable name                    */
};

// typedef struct sqlda    sqlda_t;
struct  sqlda
{
    sdbyte           sqldaid[8];             /* Eye catcher = 'SQLDA   '         */
    /************************************************************************/
    /* The 7th byte has special meaning.  If it is a '2', this means there  */
    /* are twice as many sqlvars as there are host variables or columns.    */
    /* This is typically used when Large Objects (LOBs) or User Defined     */
    /* Types (UDFs) are present in the SQLDA.  The first N entries use the  */
    /* sqlvar structure and the second N entries use the sqlvar2 structure. */
    /************************************************************************/
    sdint4          sqldabc;                /* SQLDA size in bytes=16+143*SQLN   */
    sdint2            sqln;                   /* Number of SQLVAR elements        */
    sdint2            sqld;                   /* # of columns or host vars.       */
    sqlvar_t*       sqlvar;                 /* first SQLVAR element             */
};

typedef struct sqlda sqlda;

/* macro for allocating SQLDA */
#define SQLDASIZE(n) (offsetof(sqlda, sqlvar) + \
                     (n) * sizeof(sqlvar_t))

/****************************************************************************/
/* Because we may need to support 8 byte lengths in the future,             */
/* sql8bytelen is defined using 8 bytes.  Currently, however, we have only  */
/* four byte integers.                                                      */
/****************************************************************************/
union sql8bytelen
{
    sdint4            reserve1[2];                /* reserved for future 8 byte lengths.      */
    sdint4            sqllonglen;                 /* this is what is currently used           */
};

union sql4bytelen
{
    udbyte            reserve1[4];                /* reserved                               */
    sdint4            sqllonglen;                 /* this is what is currently used         */
};

/****************************************************************************/
/* The sqlvar2 structure maps the second "N" sqlvar entries.  The           */
/* second "N" entries are used to hold the length of LOB columns            */
/* and host variables.  The second "N" entries may also be used to          */
/* hold the SQLDATALEN field for LOB columns on a FETCH USING               */
/* DESCRIPTOR request.                                                      */
/*                                                                          */
/* To set or retrieve these fields, use the macros provided below.          */
/****************************************************************************/

#if defined (_WIN64) || defined (DM64)
#define SQLVAR2_PAD 8
#else
#define SQLVAR2_PAD 0
#endif

typedef struct sqlvar2  sqlvar2_t;
struct sqlvar2                                      /* Variable Description                     */
{
   union sql4bytelen    len;                        /* Four byte length.                        */
   udbyte                 reserve2[3+SQLVAR2_PAD];    /* Reserved                                 */
   udbyte                 sqlflag4;                   /* Indicates type of Var (see flag values below)    */
   sdbyte*               sqldatalen;                 /* Pointer to four (4) byte                 */
                                                    /* length buffer. This may be               */
                                                    /* used to hold the length for              */
                                                    /* lob data types.                          */
   sqluser_def_type     sqldatatype_name;           /* User-defined type name             */
};

/* 
 * Use of reinterpret_cast<> here is so C++ compilers won't object to the 
 * conversion of struct sqlvar * to struct sqlvar2 *.
 */
#if defined __cplusplus && __cplusplus >= 199707L
#define db2Sqlvar2Convert(e) (reinterpret_cast<struct sqlvar2 *>((e)))
#else
#define db2Sqlvar2Convert(e) ((struct sqlvar2 *)(e))
#endif

/****************************************************************************/
/* Flag values for sqlflag4 field of sqlvar2.                               */
/****************************************************************************/

#define SQLFLAG4_BASE    0x00  /* Type is base type or distinct type        */
#define SQLFLAG4_REF     0x01  /* Reference type                            */
#define SQLFLAG4_STRUCT  0x12  /* Structured type                           */

/****************************************************************************/
/* Macros for using the sqlvar2 fields.                                     */
/****************************************************************************/

/****************************************************************************/
/* A '2' in the 7th byte of sqldaid indicates a doubled amount of sqlvars.  */
/****************************************************************************/
#define   SQLDOUBLED  '2'
#define   SQLSINGLED  ' '

/****************************************************************************/
/* GETSQLDOUBLED(daptr) will return 1 if the SQLDA pointed to by daptr      */
/* has been doubled, or 0 if it has not been doubled.                       */
/****************************************************************************/
#define GETSQLDOUBLED(daptr) (((daptr)->sqldaid[6] == ( char) SQLDOUBLED) ? \
    (1)         : \
    (0)           )

/****************************************************************************/
/* SETSQLDOUBLED(daptr, SQLDOUBLED) will make the 7th byte of sqldaid to    */
/* be a '2'.                                                                */
/* SETSQLDOUBLED(daptr, SQLSINGLED) will make the 7th byte of sqldaid to    */
/* be a ' '.                                                                */
/****************************************************************************/
#define SETSQLDOUBLED(daptr, newvalue) (((daptr)->sqldaid[6] = (newvalue)))

/****************************************************************************/
/* GETSQLDALONGLEN(daptr,n) will return the data length of the nth entry    */
/* in the sqlda pointed to by daptr. Use this only if the sqlda was         */
/* doubled and the nth SQLVAR entry has a LOB datatype.                     */
/****************************************************************************/
#define GETSQLDALONGLEN(daptr,n) \
   ((db2Sqlvar2Convert(&((daptr)->sqlvar[(n) + ((daptr)->sqld)])))->len.sqllonglen)

/****************************************************************************/
/* SETSQLDALONGLEN(daptr,n,len) will set the sqllonglen field of the        */
/* sqlda pointed to by daptr to len for the nth entry. Use this only if     */
/* the sqlda was doubled and the nth SQLVAR entry has a LOB datatype.       */
/****************************************************************************/
#define SETSQLDALONGLEN(daptr,n,length)  { \
   struct sqlvar2     *var2ptr; \
   var2ptr = db2Sqlvar2Convert(&((daptr)->sqlvar[(n) + ((daptr)->sqld)])); \
   var2ptr->len.sqllonglen  =  (sqlint32) (length); \
   }

/****************************************************************************/
/* GETSQLDALENPTR(daptr,n) will return a pointer to the data length for     */
/* the nth entry in the sqlda pointed to by daptr.  Unlike the inline       */
/* value (union sql8bytelen len), which is 8 bytes, the sqldatalen pointer  */
/* field returns a pointer to a sqlint32 (4 byte) integer.                      */
/* If the SQLDATALEN pointer is zero, a NULL pointer will be returned.      */
/*                                                                          */
/* NOTE: Use this only if the sqlda has been doubled.                       */
/****************************************************************************/
#define GETSQLDALENPTR(daptr,n) \
   ((sqlint32 *) (db2Sqlvar2Convert(&(daptr)->sqlvar[(n) + (daptr)->sqld]))->sqldatalen)

/****************************************************************************/
/* SETSQLDALENPTR(daptr,n,ptr) will set a pointer to the data length for    */
/* the nth entry in the sqlda pointed to by daptr.                          */
/* Use this only if the sqlda has been doubled.                             */
/****************************************************************************/
#define SETSQLDALENPTR(daptr,n,ptr)  {  \
   struct sqlvar2 *var2ptr;    \
   var2ptr = db2Sqlvar2Convert(&((daptr)->sqlvar[(n) + ((daptr)->sqld)])); \
   var2ptr->sqldatalen  = (schar *) ptr; \
   }

/****************************************************************************/
/* GETSQLDAFLAG4(daptr,n) will return the type character flag (sqlflag4)    */
/* from the nth entry in the sqlda pointed to by daptr.                     */
/* Use this only if the sqlda was doubled.                                  */
/****************************************************************************/

#define GETSQLDAFLAG4(daptr,n) ( \
    (schar) ((db2Sqlvar2Convert( &((daptr)->sqlvar[(n) + \
                               ((daptr)->sqld)])))->sqlflag4) )

/****************************************************************************/
/* SETSQLDAFLAG4(daptr,n,flag) will set the type character flag (sqlflag4)  */
/* from the nth entry in the sqlda pointed to by daptr.                     */
/* Use this only if the sqlda was doubled.                                  */
/****************************************************************************/

#define SETSQLDAFLAG4(daptr,n,flag) { \
   struct sqlvar2 *var2ptr; \
   var2ptr = db2Sqlvar2Convert(&((daptr)->sqlvar[(n) + ((daptr)->sqld)])); \
   var2ptr->sqlflag4 = (schar) (flag); \
   }

/*
#if (defined(DB2OS2) || defined(DB2NT) || defined(DB2WIN))
#pragma pack()
#elif (defined(DB2MAC))
#pragma align
#elif (defined(DB2HP) || defined(DB2SNI))

#elif (defined(DB2AIX) || (defined(DB2SUN) && defined(__xlC__)))
#pragma options align=reset
#endif*/

#define     SQL_RC_W236     236
#define     SQL_RC_W237     237
#define     SQL_RC_W238     238
#define     SQL_RC_W239     239

/* Variable Types                                                             */
#define SQL_TYP_NULINC          1

#define SQL_TYP_DATE           384     /* DATE                                */
//#define SQL_TYP_NDATE          (SQL_TYP_DATE+SQL_TYP_NULINC)

#define SQL_TYP_TIME           388     /* TIME                                */
//#define SQL_TYP_NTIME          (SQL_TYP_TIME+SQL_TYP_NULINC)

#define SQL_TYP_STAMP          392     /* TIMESTAMP                           */
//#define SQL_TYP_NSTAMP         (SQL_TYP_STAMP+SQL_TYP_NULINC)

//#define SQL_TYP_DATALINK       396     /* DATALINK                            */
//#define SQL_TYP_NDATALINK      (SQL_TYP_DATALINK+SQL_TYP_NULINC)

// #define SQL_TYP_CGSTR          400     /* C NUL-terminated graphic str        */
//#define SQL_TYP_NCGSTR         (SQL_TYP_CGSTR+SQL_TYP_NULINC)

#define SQL_TYP_BLOB           404     /* BLOB - varying length string        */
// #define SQL_TYP_NBLOB          (SQL_TYP_BLOB+SQL_TYP_NULINC)

#define SQL_TYP_CLOB           408     /* CLOB - varying length string        */
// #define SQL_TYP_NCLOB          (SQL_TYP_CLOB+SQL_TYP_NULINC)

//#define SQL_TYP_DBCLOB         412     /* DBCLOB - varying length string      */
//#define SQL_TYP_NDBCLOB        (SQL_TYP_DBCLOB+SQL_TYP_NULINC)

#define SQL_TYP_VARCHAR        448     /* VARCHAR(i) - varying length string  */
/* (2 byte length)                     */
// #define SQL_TYP_NVARCHAR       (SQL_TYP_VARCHAR+SQL_TYP_NULINC) 

#define SQL_TYP_CHAR           452     /* CHAR(i) - fixed length string       */
//#define SQL_TYP_NCHAR          (SQL_TYP_CHAR+SQL_TYP_NULINC)

#define SQL_TYP_LONG           456     /* LONG VARCHAR - varying length       */
/* string                              */
// #define SQL_TYP_NLONG          (SQL_TYP_LONG+SQL_TYP_NULINC)

#define SQL_TYP_CSTR           460     /* varying length string for C (null   */
/* terminated)                         */
#define SQL_TYP_NCSTR          (SQL_TYP_CSTR+SQL_TYP_NULINC)

//#define SQL_TYP_VARGRAPH       464     /* VARGRAPHIC(i) - varying length      */
/* graphic string (2 byte length)      */
//#define SQL_TYP_NVARGRAPH      (SQL_TYP_VARGRAPH+SQL_TYP_NULINC)

//#define SQL_TYP_GRAPHIC        468     /* GRAPHIC(i) - fixed length graphic   */
/* string                              */
//#define SQL_TYP_NGRAPHIC       (SQL_TYP_GRAPHIC+SQL_TYP_NULINC)

//#define SQL_TYP_LONGRAPH       472     /* LONG VARGRAPHIC(i) - varying        */
/* length graphic string               */
//#define SQL_TYP_NLONGRAPH      (SQL_TYP_LONGRAPH+SQL_TYP_NULINC)

#define SQL_TYP_LSTR           476     /* varying length string for Pascal    */
/* (1-byte length)                     */
#define SQL_TYP_NLSTR          (SQL_TYP_LSTR+SQL_TYP_NULINC)

#define SQL_TYP_FLOAT          480     /* FLOAT - 4 or 8 byte floating point  */
//#define SQL_TYP_NFLOAT         (SQL_TYP_FLOAT+SQL_TYP_NULINC)

#define SQL_TYP_DECIMAL        484     /* DECIMAL (m,n)                       */
//#define SQL_TYP_NDECIMAL       (SQL_TYP_DECIMAL+SQL_TYP_NULINC)

//#define SQL_TYP_ZONED          488     /* Zoned Decimal -> DECIMAL (m,n)      */
//#define SQL_TYP_NZONED         (SQL_TYP_ZONED+SQL_TYP_NULINC)

#define SQL_TYP_BIGINT         492     /* BIGINT - 8-byte signed integer      */
//#define SQL_TYP_NBIGINT        (SQL_TYP_BIGINT+SQL_TYP_NULINC)

#define SQL_TYP_INTEGER        496     /* INTEGER - 4-byte signed integer     */
//#define SQL_TYP_NINTEGER       (SQL_TYP_INTEGER+SQL_TYP_NULINC)

#define SQL_TYP_SMALL          500     /* SMALLINT - 2-byte signed integer    */
//#define SQL_TYP_NSMALL         (SQL_TYP_SMALL+SQL_TYP_NULINC)

#define SQL_TYP_NUMERIC        504     /* NUMERIC -> DECIMAL (m,n)            */
//#define SQL_TYP_NNUMERIC       (SQL_TYP_NUMERIC+SQL_TYP_NULINC)

#define SQL_TYP_NDATE			-100
#define SQL_TYP_NTIME			-101
#define SQL_TYP_NSTAMP			-103
#define SQL_TYP_NBLOB			-106
#define SQL_TYP_NCLOB			-107
#define SQL_TYP_NVARCHAR		-108
#define SQL_TYP_NCHAR			-109
#define SQL_TYP_NLONG			-110
#define SQL_TYP_NFLOAT			-116
#define SQL_TYP_NDECIMAL		-117
#define SQL_TYP_NBIGINT			-119
#define SQL_TYP_NINTEGER		-120
#define SQL_TYP_NSMALL			-121
#define SQL_TYP_NNUMERIC		-122


#ifdef __cplusplus
extern "C" {
#endif

DllExport
dmbool
sqlda_db2_describe(
    char*		    stmt,
    sqlda*		da,
    dmbool          is_param
);

DllExport
dmbool
sqlda_db2_fetch(
    char*	        cur_name,
    sqlda*		da,
	sdint4			rows
);

DllExport
int
sqlda_db2_exec(
    char*	    	        stmt,
    sqlda*			    da,
	udint4			        rows
);

#ifdef __cplusplus
}
#endif


#endif /* SQLDASIZE */
