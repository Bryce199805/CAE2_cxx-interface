/********************************************************************
file: 
    cpt.c
Notes:
    capture interface
History:
    Date         Who         RefDoc			Memo
    2012-11-06	 xh.wng    					moved	
********************************************************************/
#ifndef _DMCPT_DLL_H
#define _DMCPT_DLL_H

#include "DPI.h"

#define CPT_LANGUAGE_CN			    0	 
#define CPT_LANGUAGE_EN				1	 

#define DM_MAX_CPT_ERROR_INFO_LEN	512
typedef struct cpt_error_info_struct cpt_error_info_t;
struct cpt_error_info_struct
{
	sdint4		error_no;
	sdbyte		error_info[DM_MAX_CPT_ERROR_INFO_LEN];
};

typedef struct cpt_col_def_struct cpt_col_def_t;
struct cpt_col_def_struct 
{
    sdbyte			name[129];		//--field name,consistent with cpt object field 
	sdbyte			col_define[129];		//--field type,valid only when the expr is not null,must complete define, as int,varchar(200),numeric(10,2)
	sdbyte			expr[1024];		//--field expression,if not empty string  
};

#define CPT_WITH_API	1

/**
* <p>Function: cpt entry</p>
* <p>Arithmetic: none</p>
* <p>arg list: <br><ul>
* <li>con_hdbc, --in,the database connection handle</li>
* <li>schname,  --in,the schema name of the cpt object</li>
* <li>tvname,  --in,the cpt table/view</li>
* <li>wheres,  --in,the cpt condition,need to designate the new or old val condition,as'OLD:ID < 10 AND NEW:ID > 10', otherwise set "";</li>
* <li>col_defs, --in,field description</li>
* <li>n_cols,  --in,cpt field num</li>
* <li>cdc_id,  --out,cpt request identification,correspondence with changed table name</li>
* <li>cdc_id_len, --in,the buffer length identification,>=129 </li>
* <li>cdc_blob_id, --out,the cpt request identification,correspondence with blob table name</li>
* <li>cdc_blob_id_len,--in,the blob identification buffer len,>=129   </li>
* <li>error_info, --out,the error occured reason</li>
* </ul></p>
* <p>ret: udint4,whether or not success: {TRUE, FALSE}</p>
*/
DllExport
udint4
dm_create_change_data_capture(
#if CPT_WITH_API
	dhcon con_hdbc,
#else
	void *pidao_connection,               
#endif   
   sdbyte*		schname,			
   sdbyte*		tvname,				
   sdbyte*		wheres,				
   cpt_col_def_t*	col_defs,	        
   udint2		n_cols,				
   sdbyte*		cdc_id,				
   udint4		cdc_id_len,		    
   sdbyte*		cdc_blob_id,		
   udint4		cdc_blob_id_len,	    
   cpt_error_info_t* error_info			
);

/**
* <p>function: the cpt delete interface</p>
* <p>arithmetic: none</p>
* <p>arg list: <br><ul>
* <li>con_hdbc, --in,the database connection handle</li>
* <li>cdc_id,  --in,cpt request identification,correspondence with changed table name</li>
* <li>error_info, --out,the error occured reason</li>
* </ul></p>
* <p>ret: udint4, whether or not success, {TRUE, FALSE}</p>
*/
DllExport
udint4
dm_drop_change_data_capture(
#if CPT_WITH_API
	dhcon con_hdbc,
#else
	void *pidao_connection,               
#endif
   sdbyte*		cdc_id,
   cpt_error_info_t* error_info
);

/**
* <p>function: the cpt language interface</p>
* <p>arithmetic: none</p>
* <p>arg list: <br><ul>
* <li>code_id, --in,cpt code type(reserved)</li>
* <li>lang_id, --in,cpt lang type</li>
* </ul></p>
* <p>ret: dmbool, whether or not success, {TRUE, FALSE}</p>
*/
DllExport
void
dm_cpt_set_local_code(
    sdint4      code_id, /* invalid */
    sdint4      lang_id  
);

#endif
