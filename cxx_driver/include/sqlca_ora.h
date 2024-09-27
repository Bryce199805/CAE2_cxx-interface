/********************************************************************
file:
	sqlca.h
purpose:
    define datatype for SQLCA

interface:

History
    Date        Who         RefDoc     Memo
*******************************************************/

#ifndef SQLCA_ORA_H
#define SQLCA_ORA_H

#include "DPI.h"

/* define sqlca struct */
typedef struct sqlca_ora_struct		sqlca_ora_t;
struct sqlca_ora_struct {
    udbyte sqlcaid[8];
    sdint4 sqlcabc;
    sdint4 sqlcode;
    struct {
        sdint2 sqlerrml;
        udbyte sqlerrmc[70];
    } sqlerrm;
    udbyte sqlerrp[8];
    sdint4 sqlerrd[6];
    udbyte sqlwarn[11];
    udbyte sqlstate[6];
};

#define SQLCA_HAS_WARN		(sqlca.sqlcode > 0)
#define SQLCA_NOT_FOUND		(sqlca.sqlcode == 100)
#define SQLCA_HAS_ERROR		(sqlca.sqlcode < 0)

#endif
