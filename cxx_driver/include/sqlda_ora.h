

/* NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************
*/

/*  MODIFIED
    apopat     05/08/02  - [2362423] MVS PE to make lines shorter than 79
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for sqlda
    lvbcheng   08/15/97 -  Move sqlda protos to sqlcpr.h
    lvbcheng   06/25/97 -  Move sqlda protos to this file
    jbasu      01/29/95 -  correct typo
    jbasu      01/27/95 -  correct comment - ub2->sb2
    jbasu      12/12/94 - Bug 217878: note this is an SOSD file
    Morse      12/01/87 - undef L and S for v6 include files
    Richey     07/13/87 - change int defs to long 
    Clare      09/13/84 - Port: Ch types to match SQLLIB structs
    Clare      10/02/86 - Add ifndef SQLDA
*/

#ifndef SQLDA_ORA_H
#define SQLDA_ORA_H

#ifdef T
# undef T
#endif
#ifdef F
# undef F
#endif

#ifdef S
# undef S
#endif
#ifdef L
# undef L
#endif

 
struct SQLDA {
  /* ub4    */ udint4        N; /* Descriptor size in number of entries        */
  /* text** */ char        **V; /* Ptr to Arr of addresses of main variables   */
  /* ub4*   */ udint4       *L; /* Ptr to Arr of lengths of buffers            */
  /* sb2*   */ sdint2		*T; /* Ptr to Arr of types of buffers              */
  /* sb2**  */ sdint2	   **I; /* Ptr to Arr of addresses of indicator vars   */
  /* sb4    */ sdint4        F; /* Number of variables found by DESCRIBE       */
  /* text** */ char        **S; /* Ptr to Arr of variable name pointers        */
  /* ub2*   */ udint2     *M; /* Ptr to Arr of max lengths of var. names     */
  /* ub2*   */ udint2     *C; /* Ptr to Arr of current lengths of var. names */
  /* text** */ char      **X; /* Ptr to Arr of ind. var. name pointers       */
  /* ub2*   */ udint2     *Y; /* Ptr to Arr of max lengths of ind. var. names*/
  /* ub2*   */ udint2     *Z; /* Ptr to Arr of cur lengths of ind. var. names*/
  };
 
typedef struct SQLDA SQLDA;
 
#endif


