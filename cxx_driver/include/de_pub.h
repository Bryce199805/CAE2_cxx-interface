#ifndef DE_PUB_H
#define DE_PUB_H

#ifdef __cplusplus
extern "C" {
#endif 

#ifndef DMASM2_H
typedef   signed short     sdint2;
typedef unsigned short     udint2;

typedef   signed int       sdint4;                   
typedef unsigned int       udint4; 

#ifdef WIN32
typedef __int64            sdint8;
typedef unsigned __int64   udint8;
#else
typedef long long int          sdint8;
typedef unsigned long long int udint8;
#endif

typedef signed char         sdbyte;
typedef unsigned char       udbyte;

#endif

#ifndef __DDB__
#define __DDB__

typedef double      ddouble;

#endif

#define NSTR_LOCAL_LEN  48

typedef struct de_str_struct de_str;
struct de_str_struct
{
    udint4            len;     
    udbyte*           data;    
    udbyte            local_space[NSTR_LOCAL_LEN];  /*end with '\0', only storage 47 bytes*/
};


typedef struct de_data_struct de_data;
struct de_data_struct
{
	udint4 null_flag; /*whether is null, 1:not null 0: null*/
	union	
    {
		sdint4   v_int;
		ddouble  v_double;
		de_str   v_str;
	}data;
};


typedef struct de_args_struct de_args;
struct de_args_struct
{
	udint4        n_args;       
    de_data*      args;         
};

/**
 * <p>Function: return the arg_id para as int</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
	<li> args: not null</li>
	<li> arg_id: get the id para value, start with 0, not null</li>
* </ul></p>
 * <p>return val : the arg_id para as int</p>
 */
sdint4 
de_get_int(
    de_args* args, 
    udint4   arg_id
);

/**
 * <p>Function: return the arg_id para as double</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
	<li> args: not null</li>
	<li> arg_id: get the id para value,start with 0,not null</li>
* </ul></p>
 * <p>return val : the arg_id para as double</p>
 */
ddouble 
de_get_double(
    de_args*  args, 
    udint4    arg_id
);

/**
 * <p>Function: return the arg_id para as string</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> args: not null</li>
   <li> arg_id: get the id para value,start with 0,not null</li>
* </ul></p>
 * <p>return val : the arg_id para as string</p>
 */
udbyte* 
de_get_str(
    de_args* args, 
    udint4   arg_id
);

/**
 * <p>Function: return the arg_id para as string</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
	<li> args: not null</li>
	<li> arg_id: get the id para value,start with 0,not null</li>
	<li> alen: return the length of string</li>
* </ul></p>
 * <p>return val : the arg_id para as string</p>
 */
udbyte* 
de_get_str_with_len(
    de_args*    args, 
    udint4      arg_id, 
    udint4*     alen
);

/**
 * <p>Function: set the arg_id para as int</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> args: not null</li>
   <li> arg_id: set the id para value,start with 0,not null</li> 
* </ul></p>
 * <p>return val: the arg_id para as int</p>
 */
void 
de_set_int(
    de_args*    args, 
    udint4      arg_id, 
    sdint4      ret
);

/**
 * <p>Function: set the arg_id para as double</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> args: not null</li>
   <li> arg_id: set the id para value,start with 0,not null</li> 
* </ul></p>
 * <p>return val: the arg_id para as double</p>
 */
void 
de_set_double(
    de_args* args, 
    udint4   arg_id, 
    ddouble  ret
);

/**
 * <p>Function: set the arg_id para as string</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> args: not null</li>
   <li> arg_id: set the id para value,start with 0,not null</li> 
   <li> ret: the new arg_id para as string,end with '\0'</li>
* </ul></p>
 * <p>return val: nothing</p>
 */
void de_set_str(
    de_args*    args, 
    udint4      arg_id, 
    udbyte*     ret
);

/**
 * <p>Function: set the arg_id para as string</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   	<li> args: not null</li>
   	<li> arg_id: set the id para value,start with 0,not null</li> 
    <li> alen: length of the new string</li>
   <li> ret: the new arg_id para as string,not end with '\0'</li>
* </ul></p>
 * <p>return val: nothing</p>
 */
void 
de_set_str_with_len(
    de_args*    args, 
    udint4      arg_id, 
    udbyte*     ret, 
    udint4      alen
);

/**
 * <p>Function: return the arg_id para as int</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> ret: return the int value</li>
* </ul></p>
 * <p>return val: int</p>
 */
de_data 
de_return_int(
    sdint4 ret
);

/**
 * <p>Function: return the arg_id para as double</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> ret: return the double value</li>
* </ul></p>
 * <p>return val: double</p>
 */
de_data 
de_return_double(
    ddouble ret
);

/**
 * <p>Function: return the arg_id para as string</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> ret: return the string value, end with '\0'</li>
* </ul></p>
 * <p>return val: string</p>
 */
de_data
de_return_str(
    udbyte* ret
);

/**
 * <p>Function: return the arg_id para as string</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li> ret: return the string value, not end with '\0'</li>
   <li> alen: the length of string</li>
* </ul></p>
 * <p>return val: string</p>
 */
de_data 
de_return_str_with_len(
    udbyte*    ret, 
    udint4     alen
);

/**
 * <p>Function: free space</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
   <li>str: return the point to the space of the string need free</li> 
* </ul></p>
 * <p>return val: nothing</p>
 */
void 
de_str_free(
    sdbyte* str
);

/**
 * <p>Function: whether the args are null</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
	 <li> args: not null</li>
	 <li> arg_id: set the id para value,start with 0,not null</li>
* </ul></p>
 * <p>return val: bool</p>
 */
udint4 
de_is_null(
    de_args*  args, 
    udint4    arg_id
);

/**
 * <p>Function: set the args null</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: <br><ul>
	 <li> args: not null</li>
	 <li> arg_id: set the id para value,start with 0,not null</li>
* </ul></p>
 * <p>return val: nothing</p>
 */
void  
de_set_null(
    de_args*    args, 
    udint4      arg_id
);

/**
 * <p>Function: return null</p>
 * <p>Arthimetic: none</p>
 * <p>arg list: none<br><ul>
* </ul></p>
 * <p>return val: none</p>
 */
de_data 
de_return_null(); 

typedef 
de_data
(*de_exec_fun_t)(
de_args*    args
);

#ifdef __cplusplus
}
#endif

#endif

