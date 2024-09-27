/********************************************************************
file:
	sqlca.h
purpose:
    define datatype for SQLCA

interface:

History
    Date        Who         RefDoc     Memo
*******************************************************/

#ifndef SQLCA_DB2_H
#define SQLCA_DB2_H

#include "DPI.h"

#define DB2_SQLERRMC_LEN    70
/* define sqlca struct */
typedef struct sqlca_db2_struct		sqlca_db2_t;
struct  sqlca_db2_struct
{
   udbyte			sqlcaid[8];           /* Eyecatcher = 'SQLCA   '        */
   sdint4			sqlcabc;              /* SQLCA size in bytes = 136      */
   sdint4			sqlcode;              /* SQL return code                */

   sdint2           sqlerrml;             /* Length for SQLERRMC            */
   udbyte			sqlerrmc[DB2_SQLERRMC_LEN];         /* Error message tokens           */

   udbyte			sqlerrp[8];           /* Diagnostic information         */
   sdint4			sqlerrd[6];           /* Diagnostic information         */
   udbyte			sqlwarn[11];          /* Warning flags                  */

   udbyte			sqlstate[6];          /* State corresponding to SQLCODE */
};

#ifdef __cplusplus
extern "C" {
#endif

DllExport
void
sqlca_db2_load(
    DPIRETURN	    rt,
    sqlca_db2_t*	ca
);

#ifdef __cplusplus
}
#endif

#endif
