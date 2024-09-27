#ifndef _OOPI_H
#define _OOPI_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <exception>
#include <string.h>
#include <stdio.h>
#include "DPI.h"
#include "DPIext.h"
#include "DPItypes.h"

using std::map;
using std::exception;

#ifdef WIN32
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

#define OOPI_BLOB_WRITE_BUF_LEN  (32 * 1024)

typedef unsigned long   CONNECTIONTYPE;

enum RETURNCODE
{
    DAO_IS_OPENED = 1,				//designate object node has open
    DAO_ILLEGAL_HANDLE = 2,			//invalid handle
    DAO_ILLEGAL_CALLSEQ = 3,		//invalid call seq 
    DAO_ILLEGAL_INPUT = 4,			//invalid input
    DAO_END_OF_RECORD = 5,			//the database access has to result end
    DAO_ERROR = 6,					//the database access failed by some error
    DAO_FALSE = 7,					//bool "FALSE"
    DAO_TRUE = 8,					//bool "TRUE"
    DAO_NULL_DATA = 9,				//the database access no data use
    DAO_SUCCESS = 10,				//the database access complete suceess
    DAO_SUCCESS_WITHINFO = 11		//the database access complete suceess,append info.
};

class OOPI_Connection;
class OOPI_Recordset;
class OOPI_StoredProc;
class OOPI_TableLoader;
class OOPI_Field;
class OOPI_Parameter;
class OOPI_SqlError;
class OOPI_Utility;
class OOPI_Blob;
class OOPI_Bfile;
class OOPI_MetaData;
class OOPI_Schema;
class OOPI_UserInfo;
class OOPI_RoleInfo;
class OOPI_ObjPrivsList;
class OOPI_ObjPrivs;
class OOPI_TableInfo;
class OOPI_ViewInfo;
class OOPI_FieldInfo;
class OOPI_PrimaryKey;
class OOPI_ForeignKey;
class OOPI_CheckCondition;

enum EDAO_ConnectionType
{
    DAO_CONNECTION_SOCKET = 0		//SOCKET conn mode
};

enum EDAO_DBMSTtype
{
    DAO_CONNECTION_DM7 = 0
};

enum EDAO_RecordsetStatus
{
    DAO_RECORDSET_COMMANDSET = 0,
    DAO_RECORDSET_PARAMETERINIT = 1,
    DAO_RECORDSET_PARAMETERSET = 2,
    DAO_RECORDSET_PREPARED = 3,
    DAO_RECORDSET_EXECUTED = 4,
    DAO_RECORDSET_OPENED = 5,
    DAO_RECORDSET_END = 6,
    DAO_RECORDSET_CLOSED = 7
};

enum EDAO_FieldType
{
    DAO_UNDEFINED = 0,
    DAO_INTEGER_TYPE = 1,
    DAO_DOUBLE_TYPE = 2,
    DAO_DATE_TYPE = 3,
    DAO_STRING_TYPE	= 4,
    DAO_LONG_STRING_TYPE = 5,
    DAO_BINARY_TYPE = 6,
    DAO_LONGBINARY_TYPE	= 7,
    DAO_BLOB_TYPE = 8,
    DAO_BFILE_TYPE = 9
};

enum EDAO_IsolationLevel
{
    DAO_ISOLEVEL_READ_UNCOMMITTED = ISO_LEVEL_READ_UNCOMMITTED,
    DAO_ISOLEVEL_READ_COMMITED = ISO_LEVEL_READ_COMMITTED,
    DAO_ISOLEVEL_REPEATABLE_READ = ISO_LEVEL_REPEATABLE_READ,
    DAO_ISOLEVEL_SERIALIZABLE = ISO_LEVEL_SERIALIZABLE
};

enum EDAO_ConnectionStatus
{
    DAO_CONNECTION_CONNECTED = 0,
    DAO_CONNECTION_TRANSACTIONBEGUN = 1
};

enum EDAO_PropertyType
{
    DAO_PROPERTY_DBTYPE = 0,
    DAO_PROPERTY_LONGBINARYNAME = 1,
    DAO_PROPERTY_BLOBNAME = 2,
    DAO_PROPERTY_NULLTABNAME = 3,
    DAO_PROPERTY_PARAMARRAY = 4,
    DAO_PROPERTY_INDEXDROP = 5,
    DAO_PROPERTY_COLUMNDROP = 6
};


enum NODESTATUS
{
    DAO_NSTATUS_LIST = 0,
    DAO_NSTATUS_NODE = 1,
    DAO_NSTATUS_TREE = 2
};

enum EDAO_InoutType
{
    DAO_INOUTTYPE_IN = DSQL_PARAM_INPUT,
    DAO_INOUTTYPE_OUT = DSQL_PARAM_OUTPUT,
    DAO_INOUTTYPE_INOUT = DSQL_PARAM_INPUT_OUTPUT
};

class DllExport OOPI_Connection
{
public:
    static OOPI_Connection* Global_GetConnection(CONNECTIONTYPE ct = 0);

    static CONNECTIONTYPE* Global_GetAllConnectionType(int* pn);

    virtual ~OOPI_Connection() {}

    virtual const char* GetServerName() = 0;
    virtual const char* GetDBName() = 0;
    virtual const char* GetUserName() = 0;
    virtual const char* GetPassword() = 0;
    virtual RETURNCODE Connect(const char* username, const char* password, const char* ServerName, const char* DBName = "") = 0;
    virtual RETURNCODE DisConnect() = 0;
    virtual RETURNCODE SetIsolationLevel(EDAO_IsolationLevel level) = 0;
    virtual EDAO_IsolationLevel GetIsolationLevel() = 0;
    virtual RETURNCODE TransactionBegin() = 0;
    virtual RETURNCODE TransactionEnd() = 0;
    virtual RETURNCODE Commit() = 0;
    virtual RETURNCODE Rollback() = 0;
    virtual RETURNCODE Release() = 0;
    virtual bool Status(EDAO_ConnectionStatus status) = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual OOPI_Utility* Utility() = 0;
    virtual void SetProperty(EDAO_PropertyType name, const void* value) = 0;
    virtual void GetProperty(EDAO_PropertyType name, void* value) = 0;
    virtual OOPI_Recordset* CreateRecordset() = 0;
    virtual void DeleteRecordset(OOPI_Recordset* pRecordset) = 0;
    virtual OOPI_TableLoader* CreateTableLoader() = 0;
    virtual void DeleteTableLoader(OOPI_TableLoader* pTableLoader) = 0;
    virtual OOPI_StoredProc* CreateStoredPro() = 0;
    virtual void DeleteStoredProc(OOPI_StoredProc* pStoredProc) = 0;
    virtual OOPI_MetaData* GetMetaData() = 0;
    virtual const char* GetDBMSType() = 0;
    virtual const char* GetDBMSVersion() = 0;

private:
};

class DllExport OOPI_Recordset
{
public:
    virtual ~OOPI_Recordset() {}

    virtual OOPI_Connection* OwnerConnection() = 0;
    virtual RETURNCODE SetCommand(const char* CommandText) = 0;
    virtual RETURNCODE GetCommand(char* CommandText) = 0;
    virtual RETURNCODE SetParamBufferSize(int BufferSize) = 0;
    virtual RETURNCODE SetRecordBufferSize(int BufferSize) = 0;
    virtual int GetRecordBufferSize() = 0;
    virtual RETURNCODE SetMaxLBinaryLength(int length) = 0;
    virtual RETURNCODE Execute(int mode = 0) = 0;
    virtual RETURNCODE Open(int mode = 0) = 0;
    virtual RETURNCODE OpenEx(int irows, int mode = 0) = 0;
    virtual RETURNCODE MoveNext() = 0;
    virtual bool EOR() = 0;
    virtual RETURNCODE Close() = 0;
    virtual OOPI_Field* Field(int index) = 0;
    virtual OOPI_Field* Field(const char* FieldName) = 0;
    virtual OOPI_Parameter* Parameter(int index) = 0;
    virtual OOPI_Parameter* Parameter(const char* ParameterName) = 0;
    virtual int GetNumberOfFields() = 0;
    virtual int GetNumberOfParameters() = 0;
    virtual int GetNumberOfRecords() = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual bool Status(EDAO_RecordsetStatus status) = 0;
    virtual RETURNCODE AddParamRecord() = 0;
    virtual RETURNCODE VerifyCommand() = 0;
    virtual RETURNCODE SetBLOBAccessMode(int mode) = 0;
    virtual RETURNCODE MovePrevious() = 0;
    virtual RETURNCODE MoveFirst() = 0;
    virtual RETURNCODE MoveLast() = 0;
    virtual RETURNCODE MoveTo(long rownum, bool gopast) = 0;
    virtual bool SaveRecordset(char* strFileName) = 0;

private:
};

class DllExport OOPI_StoredProc
{
public:
    virtual ~OOPI_StoredProc() {}

    virtual OOPI_Connection* OwnerConnection() = 0;
    virtual RETURNCODE SetProcName(const char* procedurestatement) = 0;
    virtual RETURNCODE GetProcName(char* procName) = 0;
    virtual RETURNCODE Call() = 0;
    virtual RETURNCODE Close() = 0;
    virtual RETURNCODE AddParamRecord() = 0;
    virtual OOPI_Parameter* Parameter(int index) = 0;
    virtual OOPI_Parameter* Parameter(const char* ParameterName) = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual bool Status(EDAO_RecordsetStatus status) = 0;
    virtual int GetNumberOfParameters() = 0;

private:
};

class DllExport OOPI_TableLoader
{
public:
    virtual ~OOPI_TableLoader() {}

    virtual OOPI_Connection* OwnerConnection() = 0;
    virtual RETURNCODE SetTableName(const char* tableName) = 0;
    virtual RETURNCODE GetTableName(char* tableName) = 0;
    virtual RETURNCODE SetParamBufferSize(int BufferSize) = 0;
    virtual int GetParamBufferSize() = 0;
    virtual RETURNCODE SetMaxLBinaryLength(int length) = 0;
    virtual RETURNCODE Execute() = 0;
    virtual RETURNCODE Close() = 0;
    virtual int GetNumberOfParameters() = 0;
    virtual OOPI_Parameter* Parameter(int index) = 0;
    virtual OOPI_Parameter* Parameter(const char* ParameterName) = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual bool Status(EDAO_RecordsetStatus status) = 0;
    virtual RETURNCODE AddParamRecord() = 0;
    virtual RETURNCODE SetBLOBAccessMode(int mode) = 0;

private:
};

class DllExport OOPI_Field
{
public:
    virtual ~OOPI_Field() {}

    virtual const char* GetName() = 0;
    virtual EDAO_FieldType GetType() = 0;
    virtual int GetPrecision() = 0;
    virtual int GetScale() = 0;
    virtual int GetMaxSize() = 0;
    virtual int GetSize() = 0;
    virtual int GetDefinitionSize() = 0;
    virtual bool IsNull() = 0;
    virtual RETURNCODE GetInt(int* pValue) = 0;
    virtual RETURNCODE GetDouble(double* pValue) = 0;
    virtual RETURNCODE GetDate(char* pDate) = 0;
    virtual RETURNCODE GetString(char* pString) = 0;
    virtual RETURNCODE GetString(char* pString, int* size, int length) = 0;
    virtual RETURNCODE GetLString(char* pString) = 0;
    virtual RETURNCODE GetLString(char* pString, int* size, int length) = 0;
    virtual RETURNCODE GetBinary(char* pBinary) = 0;
    virtual RETURNCODE GetBinary(char* pBinary, int* size, int length) = 0;
    virtual RETURNCODE GetLongBinary(char* pLongBinary) = 0;
    virtual RETURNCODE GetLongBinary(char* pLongBinary, int* size, int length) = 0;
    virtual RETURNCODE GetBlob(OOPI_Blob** pValue) = 0;
    virtual RETURNCODE GetBFile(OOPI_Bfile** ppBFile) = 0;
    virtual RETURNCODE GetBFileBuffer(char* pValue, int length, int offset) = 0;
    virtual RETURNCODE GetBLobBuffer(char* pValue, int length, int offset) = 0;

private:
};

class DllExport OOPI_Parameter
{
public:
    virtual ~OOPI_Parameter() {}

    virtual RETURNCODE SetName(const char* Name) = 0;
    virtual RETURNCODE SetType(EDAO_FieldType type) = 0;
    virtual RETURNCODE SetInOutType(EDAO_InoutType type) = 0;
    virtual RETURNCODE SetMaxSize(int MaxSize) = 0;
    virtual RETURNCODE SetNull() = 0;
    virtual RETURNCODE SetInt(int iVal) = 0;
    virtual RETURNCODE SetDouble(double dVal) = 0;
    virtual RETURNCODE SetDate(const char* pDate) = 0;
    virtual RETURNCODE SetString(const char* pString) = 0;
    virtual RETURNCODE SetLString(const char* pString) = 0;
    virtual RETURNCODE SetBinary(const char* pBinary, int length) = 0;
    virtual RETURNCODE SetLongBinary(const char* pBinary, int length) = 0;
    virtual RETURNCODE SetBlob(char* pValue, int length) = 0;
    virtual RETURNCODE SetBfile(char* dirname, char* filename) = 0;
    virtual RETURNCODE GetInt(int* pValue) = 0;
    virtual RETURNCODE GetDouble(double* pValue) = 0;
    virtual RETURNCODE GetDate(char* pDate) = 0;
    virtual RETURNCODE GetString(char* pString) = 0;
    virtual RETURNCODE GetString(char* pString, int* size, int length) = 0;
    virtual RETURNCODE GetLString(char* pString) = 0;
    virtual RETURNCODE GetLString(char* pString, int* size, int length) = 0;
    virtual RETURNCODE GetBinary(char* pBinary, short* length) = 0;
    virtual RETURNCODE GetBinary(char* pBinary, int* size, int length) = 0;
    virtual RETURNCODE GetLongBinary(char* pValue, int* length) = 0;
    virtual RETURNCODE GetLongBinary(char* pValue, int* size, int length) = 0;
    virtual RETURNCODE GetBlob(OOPI_Blob** pValue) = 0;
    virtual RETURNCODE GetBFile(OOPI_Bfile** ppBFile) = 0;
    virtual RETURNCODE GetBFileBuffer(char* pValue, int length, int offset) = 0;
    virtual RETURNCODE GetBLobBuffer(char* pValue, int length, int offset) = 0;
    virtual const char* GetName() = 0;
    virtual EDAO_FieldType GetType() = 0;
    virtual EDAO_InoutType GetInOutType() = 0;
    virtual int GetMaxSize() = 0;

private:
};

class DllExport OOPI_SqlError
{
public:
    virtual ~OOPI_SqlError() {}

    virtual bool HasError() = 0;
    virtual int GetSqlErrorCode() = 0;
    virtual const char* GetSqlMsg() = 0;
    virtual const char* GetSqlStatement() = 0;
    virtual const char* GetEntireMessage() = 0;

private:
};

class DllExport OOPI_Utility
{
public:
    virtual ~OOPI_Utility() {}

    virtual RETURNCODE GetServerTime(char* time) = 0;
    virtual RETURNCODE LockTable(const char* tablename) = 0;
    virtual RETURNCODE UnLockTables() = 0;
    virtual RETURNCODE IsTableLocked(const char* tablename) = 0;
    virtual RETURNCODE ChangePassword(const char* username, const char* newpass, const char* oldpass) = 0;
    virtual RETURNCODE DropIndex(const char* indexname, const char* tablename) = 0;
    virtual RETURNCODE DropColumn(const char* tablename, const char* columnname) = 0;
    virtual RETURNCODE GetDBMSVersion(char* version) = 0;
    virtual RETURNCODE GetInterDataType(int	outerdt, char* interdt, int precision, bool	isVar, int Scale) = 0;

private:
};

class DllExport OOPI_Blob
{
public:
    virtual ~OOPI_Blob() {}

    virtual int GetLength() = 0;
    virtual void Close() = 0;
    virtual int ReadBytes(void*	buffer, int length, int offset) = 0;
    virtual int SaveAsFile(const char* fullPathName) = 0;

private:
};

class DllExport OOPI_Bfile
{
public:
    virtual ~OOPI_Bfile() {}

    virtual const char* GetDirAlias() = 0;
    virtual const char* GetFileName() = 0;
    virtual int GetLength() = 0;
    virtual void Close() = 0;
    virtual int ReadBytes(void*	buffer, int length, int offset) = 0;
    virtual int SaveAsFile(const char* fullPathName) = 0;

private:
};

class DllExport OOPI_MetaData
{
public:
    virtual ~OOPI_MetaData() {}

    virtual OOPI_Connection* OwnerConnection() = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual int GetSchemaCount() = 0;
    virtual OOPI_Schema* GetSchema(int index) = 0;
    virtual OOPI_Schema* GetSchema(const char* sname) = 0;
    virtual const char* GetSchemaName(int index) = 0;
    virtual OOPI_Schema* GetCurrentSchema() = 0;
    virtual int GetUserCount() = 0;
    virtual OOPI_UserInfo* GetUserInfo(int index) = 0;
    virtual OOPI_UserInfo* GetUserInfo(const char* uname) = 0;
    virtual const char* GetUserName(int index) = 0;
    virtual int GetRoleCount() = 0;
    virtual OOPI_RoleInfo* GetRoleInfo(int index) = 0;
    virtual OOPI_RoleInfo* GetRoleInfo(const char* uname) = 0;
    virtual const char* GetRoleName(int index) = 0;
    virtual void Clear() = 0;

private:
};

class DllExport OOPI_Schema
{
public:
    

    enum SEARCHMODE
    {
        DAO_SMODE_CURRENT_NODE = 0,
        DAO_SMODE_INCLUDE_CHILD = 1
    };

    virtual ~OOPI_Schema() {}

    virtual OOPI_MetaData* OwnerMetaData() = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual const char* GetSchemaName() = 0;
    virtual const char* GetLogicalSpace() = 0;
    virtual const char* GetCreateTime() = 0;
    virtual NODESTATUS GetStatus() = 0;
    virtual RETURNCODE Open(SEARCHMODE mode, unsigned long objtype) = 0;
    virtual bool IsOpen() = 0;
    virtual int GetTableCount() = 0;
    virtual OOPI_TableInfo* GetTableInfo(int index) = 0;
    virtual OOPI_TableInfo* GetTableInfo(const char* tname) = 0;
    virtual const char* GetTableName(int index) = 0;
    virtual int GetViewCount() = 0;
    virtual OOPI_ViewInfo* GetViewInfo(int index) = 0;
    virtual OOPI_ViewInfo* GetViewInfo(const char* vname) = 0;
    virtual const char* GetViewName(int index) = 0;
    virtual void Close() = 0;

private:
};

class DllExport OOPI_UserInfo
{
public:
    virtual ~OOPI_UserInfo() {}

    virtual OOPI_MetaData* OwnerMetaData() = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual const char* GetUserName() = 0;
    virtual RETURNCODE Open() = 0;
    virtual bool IsOpen() = 0;
    virtual int GetRoleCount() = 0;
    virtual const char* GetRoleName(int index) = 0;
    virtual int GetSysPrivsCount() = 0;
    virtual const char* GetSysPrivs(int index) = 0;
    virtual RETURNCODE QueryObjPrivs(const char* sname, const char* oname, const char* pname) = 0;
    virtual OOPI_ObjPrivsList* QueryObjPrivs(const char* sname, const char* oname) = 0;
    virtual void Close() = 0;

private:
};

class DllExport OOPI_RoleInfo
{
public:
    virtual ~OOPI_RoleInfo() {}

    virtual OOPI_MetaData* OwnerMetaData() = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual const char* GetCurrentRoleName() = 0;
    virtual RETURNCODE Open() = 0;
    virtual bool IsOpen() = 0;
    virtual int GetRoleCount() = 0;
    virtual const char* GetRoleName(int index) = 0;
    virtual int GetSysPrivsCount() = 0;
    virtual const char* GetSysPrivs(int index) = 0;
    virtual RETURNCODE QueryObjPrivs(const char* sname, const char* oname, const char* pname) = 0;
    virtual OOPI_ObjPrivsList* QueryObjPrivs(const char* sname, const char* oname) = 0;
    virtual void Close() = 0;

private:
};

class DllExport OOPI_ObjPrivsList
{
public:
    virtual ~OOPI_ObjPrivsList() {}

    virtual int GetObjPrivsCount() = 0;
    virtual OOPI_ObjPrivs* GetObjPrivs(int index) = 0;
    virtual void Release() = 0;
};

class DllExport OOPI_ObjPrivs
{
public:
    virtual ~OOPI_ObjPrivs() {}

    virtual const char* GetSysPrivs() = 0;
    virtual const char* GetObjSchema() = 0;
    virtual const char* GetObjName() = 0;

private:
};

class DllExport OOPI_TableInfo
{
public:
    virtual ~OOPI_TableInfo() {}

    virtual OOPI_Schema* OwnerSchema() = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual const char* GetOwner() = 0;
    virtual const char* GetTableName() = 0;
    virtual const char* GetTableType() = 0;
    virtual const char* GetLogicalSpace() = 0;
    virtual int GetRecordCount() = 0;
    virtual const char* GetComments() = 0;
    virtual RETURNCODE Open() = 0;
    virtual bool IsOpen() = 0;
    virtual int GetForeignKeyCount() = 0;
    virtual OOPI_ForeignKey* GetForeignKey(int index) = 0;
    virtual int GetPrimaryKeyCount() = 0;
    virtual OOPI_PrimaryKey* GetPrimaryKey(int index) = 0;
    virtual int GetCheckCount() = 0;
    virtual OOPI_CheckCondition* GetCheck(int index) = 0;
    virtual int GetFieldCount() = 0;
    virtual OOPI_FieldInfo* GetFieldInfo(int index) = 0;
    virtual OOPI_FieldInfo* GetFieldInfo(const char* fname) = 0;
    virtual const char* GetFieldName(int index) = 0;
    virtual void Close() = 0;

private:
};

class DllExport OOPI_ViewInfo
{
public:
    virtual ~OOPI_ViewInfo() {}

    virtual OOPI_Schema* OwnerSchema() = 0;
    virtual OOPI_SqlError* Error() = 0;
    virtual const char* GetOwner() = 0;
    virtual const char* GetViewName() = 0;
    virtual const char* GetDefineText() = 0;
    virtual const char* GetComments() = 0;
    virtual RETURNCODE Open() = 0;
    virtual int GetFieldCount() = 0;
    virtual OOPI_FieldInfo* GetFieldInfo(int index) = 0;
    virtual OOPI_FieldInfo* GetFieldInfo(const char* fname) = 0;
    virtual const char* GetFieldName(int index) = 0;
    virtual void Close() = 0;

private:
};

class DllExport OOPI_FieldInfo
{
public:
    virtual ~OOPI_FieldInfo() {}

    virtual int GetID() = 0;
    virtual const char* GetName() = 0;
    virtual const char* GetType() = 0;
    virtual int GetDefineSize() = 0;
    virtual int GetPrecision() = 0;
    virtual int GetScale() = 0;
    virtual bool IsNullable() = 0;
    virtual const char* GetDefaultValue() = 0;
    virtual const char* GetComments() = 0;

private:
};

class DllExport OOPI_PrimaryKey
{
public:
    virtual ~OOPI_PrimaryKey() {}

    virtual const char* GetConstraintName() = 0;
    virtual const char* GetFieldName() = 0;

private:
};

class DllExport OOPI_ForeignKey
{
public:
    virtual ~OOPI_ForeignKey() {}

    virtual const char* GetConstraintName() = 0;
    virtual const char* GetFieldName() = 0;
    virtual const char* GetRefConstraintName() = 0;
    virtual const char* GetRefTableOwner() = 0;
    virtual const char* GetRefTableName() = 0;
    virtual const char* GetRefFieldName() = 0;

private:
};

class DllExport OOPI_CheckCondition
{
public:
    virtual ~OOPI_CheckCondition() {}

    virtual const char* GetConstraintName() = 0;
    virtual const char* GetFieldName() = 0;
    virtual const char* GetCheckCondition() = 0;

private:
};

#endif      //_OOPI_H
