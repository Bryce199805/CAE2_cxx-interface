# C++ 数据接口用户手册

C++数据接口为用户提供直接操作达梦数据库的相关API接口，便于拥有管理员权限的用户对数据库中相关库表进行增删改查操作。

## 目录说明
- **lib**  包含数据接口所打包的库文件以及相关依赖
- **include** 数据接口作用到的相关头文件
- **interface-config.yaml**  数据库配置参数文件

## 环境配置
- 中文编码请设置为UTF-8
- 将lib目录添加到环境变量中
- interface-config.yaml中配置信息修改为本机对应的信息
- 若文件操作出现乱码，则Windows中文编码需要设置为UTF-8
```yaml
## interface-config.yaml
server:
  username: "708_USER"
  password: "708_user"
  database-server: "192.168.8.201:5236"
  file-system-server: "192.168.8.201:9000"

log:
  username: "Admin_LOG"
  password: "logmanager"
  cidr: "192.168.8.0/24"
  enable: true
```
## API 用户手册

API包括`CAE`类、`DBVariant`类和`CAEwithFileSystem`类
### Class DBVariant
`DBVariant`提供了一种通用数据类型用于处理查询结果，用于处理承接从数据库中查询到的任意类型的值，支持`std::string`,`int`,`float`,`double`类型。

#### 构造函数

##### `DBVariant() = default;`

默认构造函数

```c++
DBVariant obj;
```

##### `DBVariant(const std::string& val);`

以字符串初始化对象

```c++
DBVariant obj("test string");
```

##### ` DBVariant(int val)`

以`int`类型初始化对象

```c++
DBVariant obj(10);
```

##### ` DBVariant(float val)`

以`float`类型初始化对象

```c++
DBVariant obj(12.3);
```

##### ` DBVariant(double val)`

以`double`类型初始化对象

```c++
DBVariant obj(12.3);
```

#### setValue方法
##### `void setValue(const std::string &val);`
用于将值设置为`std::string`类型的新值
- 形参列表：
  - val: 需要修改成为的字符串
- 返回值类型：`void`

```c++
DBVariant obj;
obj.setValue("this is a test string.");
std::cout << obj.asTypeString() << std::endl;  
// 输出：
// this is a test string.
```

##### `void setValue(int val);`
用于将值设置为`int`类型的新值
- 形参列表：
    - val: 需要修改成为的整型数值
- 返回值类型：`void`

```c++
DBVariant obj;
int a = 10;
obj.setValue(a);
std::cout << obj.asTypeInteger() << std::endl;  
// 输出：
// 10
```

##### `void setValue(float val);`
用于将值设置为`float`类型的新值
- 形参列表：
    - val: 需要修改成为的单精度浮点数
- 返回值类型：`void`

```C++
DBVariant obj;
float a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeFloat() << std::endl;  
// 输出：
// 12.3
```

##### `void setValue(double val);`
用于将值设置为`double`类型的新值
- 形参列表：
    - val: 需要修改成为的双精度浮点数
- 返回值类型：`void`

```c++
DBVariant obj;
double a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeDouble() << std::endl;  
// 输出：
// 12.3
```



#### asType方法
指定`DBVariant`对象的具体类型值，以便进行输出或后续处理

##### `std::string asTypeString();`
用于将`DBVariant`对象标记为`std::string`类型的字符串
- 返回值：`std::string`类型字符串

```c++
DBVariant obj;
obj.setValue("this is a test string.");
std::cout << obj.asTypeString() << std::endl;  
// 输出：
// this is a test string.
```

##### `int asTypeInteger();`
用于将`DBVariant`对象标记为`int`类型的整型数值
- 返回值：`int`类型数值

```
DBVariant obj;
int a = 10;
obj.setValue(a);
std::cout << obj.asTypeInteger() << std::endl;  
// 输出：
// 10
```

##### `float asTypeFloat();`
用于将`DBVariant`对象标记为`float`类型的单精度浮点数
- 返回值：`float`类型的单精度浮点数

```c++
DBVariant obj;
float a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeFloat() << std::endl;  
// 输出：
// 12.3
```

##### `double asTypeDouble();`
用于将`DBVariant`对象标记为`double`类型的双精度浮点数
- 返回值：`double`类型的双精度浮点数

```c++
DBVariant obj;
double a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeDouble() << std::endl;  
// 输出：
// 12.3
```



### Class CAE

`CAE`类封装了对数据库操作的基本增删改查方法，并提供对查询结果的打印方法用于验证

#### 构造函数

##### `CAE(const std::string &file_path, bool withFile);`

创建`CAE`对象用于操作数据库和文件系统，需要用户提供数据库和文件系统相关配置的`yaml`文件地址，并将文件系统开关设置为`true`

- 形参列表：
  - `file_path`: `yaml`配置文件地址
  - `withFile`: 文件系统开关

```c++
CAE obj("../config.yaml", true);
```



#### Query方法

##### `bool Query(std::string &sql_str, std::vector<std::vector<std::string>>& res);`

执行用户提供的`select`类型`sql`语句，将查询结果以`std::string`类型返回到用户预声明的二维`vector`容器中.

- 形参列表：
  - `sql_str`: 需要执行的`select`类型的`sql`语句，`std::string`类型引用传递
  - `res`: 用户声明的二维`vector`容器，内层类型应为`std::string`，用于存放查询结果，引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
// 进行查询并打印结果
if(obj.Query(sql_str, res)){
    obj.printResult(res);
}
```

##### `bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>>& res);`

执行用户提供的`select`类型`sql`语句，将查询结果以`DBVariant`类型返回到用户预声明的二维`vector`容器中，调用结果需使用`DBVariant`类方法指定为具体的类型。

- 形参列表：
  - `sql_str`: 需要执行的`select`类型的`sql`语句，`std::string`类型引用传递
  - `res`: 用户声明的二维`vector`容器，内层类型应为`DBVariant`，用于存放查询结果，引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<DBVariant>> res;
// 进行查询
if(obj.Query(sql_str, res)){
	std::cout << "query success." << std::endl;
}
```

##### `bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>>& res, std::vector<int>& col_types);`

执行用户提供的`select`类型`sql`语句，将查询结果以`DBVariant`类型返回到用户预声明的二维`vector`容器中，并将查询到每一列的类型以数值的形式返回到`int`类型的`vector`容器中，调用查询结果时需使用`DBVariant`类方法指定为具体的类型。

- 形参列表：
  - `sql_str`: 需要执行的`select`类型的`sql`语句，`std::string`类型引用传递
  - `res`: 用户声明的二维`vector`容器，内层类型应为`DBVariant`，用于存放查询结果，引用传递
  - `col_types`：用户声明的`int`类型`vector`容器，用于存放查询结果每一列的类型，引用传递
    - 0: `std::string`
    - 1: `int`
    - 2: ` float`
    - 3: `double`
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
std::vector<int> types;
// 进行查询并打印结果
if(obj.Query(sql_str, res)){
    obj.printResult(res, types);
}
```


#### Delete方法
##### `bool Delete(std::string &sql_str);`

执行用户提供的`delete`类型`sql`语句，对相关记录进行删除操作。

- 形参列表：
  - `sql_str`: 需要执行的`delete`类型的`sql`语句，`std::string`类型引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "delete from TestDB.TestTable where id > 10";

// 执行删除
if(obj.Delete(sql_str)){
	std::cout << "delete success." << std::endl;
}
```

#### Update方法
##### `bool Update(std::string &sql_str);`

执行用户提供的`update`类型`sql`语句，对相关记录进行更新操作。

- 形参列表：
  - `sql_str`: 需要执行的`update`类型的`sql`语句，`std::string`类型引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "update TestDB.TestTable set col1 = val1 where id > 10";

// 执行更新
if(obj.Update(sql_str)){
	std::cout << "update success." << std::endl;
}
```



#### Insert方法
##### `bool Insert(std::string &sql_str);`

执行用户提供的`insert`类型`sql`语句，向库表中进行简单的插入功能。

- 形参列表：
  - `sql_str`: 需要执行的`insert`类型的`sql`语句，`std::string`类型引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "insert into TestDB.TestTable values (val1, val2, val3);

// 执行删除
if(obj.Insert(sql_str)){
	std::cout << "insert success." << std::endl;
}
```


#### printResult方法
##### `void printResult(std::vector<std::vector<std::string>>& res);`

对以`std::string`类型容器返回的查询结果进行打印

- 形参列表：
  - `res`: 用户声明的二维`vector`容器，内层类型应为`std::string`，`Query`方法得到的查询结果，引用传递
- 返回值类型：`void`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
// 进行查询并打印结果
if(obj.Query(sql_str, res)){
    obj.printResult(res);
}
```

##### `void printResult(std::vector<std::vector<DBVariant>>& res, std::vector<int>& col_types);`

对以`DBVariant`类型容器返回的查询结果进行打印

- 形参列表：
  - `res`: 用户声明的二维`vector`容器，内层类型应为`DBVariant`，`Query`方法得到的查询结果，引用传递
- 返回值类型：`void`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
std::vector<int> types;
// 进行查询并打印结果
if(obj.Query(sql_str, res)){
    obj.printResult(res, types);
}
```



#### UploadFile

##### `bool UploadFile(std::string dbName, std::string tableName, const std::string &id, std::string col, std::string local_path);`

从本地上传用户指定的文件到文件系统中

- 形参列表：
  - `dbName`: 存储文件的数据库名，`std::string`类型值传递
  - `tableName`: 存储文件的表名，`std::string`类型值传递
  - `id`: 存储文件的表的ID，`const std::string`类型引用传递
  - `col`: 存储文件的表的字段，`std::string`类型值传递
  - `local_path`: 需要上传的本地文件路径，`std::string`类型值传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml", true);
//上传文件
if (obj.UploadFile("hull_model_and_information_db", "hull_parameter_info", "SampleShip_KCS0001", "TRANSVERSE_AREA_CURVE", "E:/CAE/upfile/SampleShip_KCS0000.png")) {
  std::cout << "Upload file done." << std::endl;
}
```

#### GetFile

##### `bool GetFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col,std::string local_path);`

从文件系统中下载文件到用户指定的本地路径

- 形参列表：
  - `dbName`: 存储文件的数据库名，`std::string`类型值传递
  - `tableName`: 存储文件的表名，`std::string`类型值传递
  - `id`: 存储文件的表的ID，`const std::string`类型引用传递
  - `col`: 存储文件的表的字段，`const std::string`类型引用传递
  - `local_path`: 下载文件的本地路径，`std::string`类型值传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml", true);
//下载文件
if (obj.GetFile("hull_model_and_information_db", "HULL_PARAMETER_INFO", "SampleShip_KCS0000",
                "HULL_3D_MODEL", "E:/CAE/downfile/")) {
  std::cout << "Download file done." << std::endl;
}
```

##### `bool GetFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col, std::vector<unsigned char> &object_data);`

从文件系统中以字符流形式下载文件，并存储到一个`vector`容器

- 形参列表：
  - `dbName`: 存储文件的数据库名，`std::string`类型值传递
  - `tableName`: 存储文件的表名，`std::string`类型值传递
  - `id`: 存储文件的表的ID，`const std::string`类型引用传递
  - `col`: 存储文件的表的字段，`const std::string`类型引用传递
  - `object_data`: 用户声明的`vector`容器，类型为`unsigned char`，用于存放下载的文件字符流，引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml", true);
//以字符流形式下载文件
std::vector<unsigned char> object_data;
if (obj.GetFile("HuLL_MODEL_AND_INFORMATION_Db", "hull_parameter_info", "SampleShip_KCS0000", "HULL_3D_MODEL", object_data)) {
  std::cout << "Download data stream done." << std::endl;
  std::cout << "object_data size: " << object_data.size() << std::endl;
}
```

#### DeleteFile

##### `bool DeleteFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col);`

从文件系统中删除文件

- 形参列表：
  - `dbName`: 存储文件的数据库名，`std::string`类型值传递
  - `tableName`: 存储文件的表名，`std::string`类型值传递
  - `id`: 存储文件的表的ID，`const std::string`类型引用传递
  - `col`: 存储文件的表的字段，`const std::string`类型引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml", true);
//删除文件
if (obj.DeleteFile("HULL_MODEL_AND_INFORMATION_DB", "hull_parameter_info", "SampleShip_KCS0000",
                   "HULL_3D_MODEL")) {
  std::cout << "Delete file done." << std::endl;
}
```

#### DeleteRecord

从数据库中删除一条带有文件存储的记录

##### `bool DeleteRecord(std::string dbName, std::string tableName, const std::string &id);`

- 形参列表：
  - `dbName`: 存储文件的数据库名，`std::string`类型值传递
  - `tableName`: 存储文件的表名，`std::string`类型值传递
  - `id`: 存储文件的表的ID，`const std::string`类型引用传递
- 返回值类型：`bool`

```c++
CAE obj("../config.yaml", true);
//删除记录
if (obj.DeleteRecord("hull_model_and_information_db", "hull_parameter_info", "SampleShip_KCS0000")) {
  std::cout << "Delete record done." << std::endl;
}
```

## CMAKE构建指南与程序样例

### CMAKE参数

- 需要导入 `/path_to_libcae/include` 和 `/path_to_libcae/include`
- 可执行程序需要链接 `dmdpi`,`yaml-cpp`和`libCAE2.a`

```cmake
# CmakeList.txt Sample
cmake_minimum_required(VERSION 3.28)
project(test)

set(CMAKE_CXX_STANDARD 17)
# CAE setting import 

include_directories(D:/libCAEFILE/include)
link_directories(D:/libCAEFILE/lib)

add_executable(test main.cpp)

target_compile_definitions(test PRIVATE USE_FILESYSTEM)

target_link_libraries(test
        dmdpi yaml-cpp  # 动态库
        libCAE2ALL.a  # 主静态库
        bcrypt # 系统库 文件系统
        ws2_32 crypt32 # 系统库
        wpcap Packet IPHlpApi # ws2_32
        sqltoast.a
)
```

### 程序样例

```c++
//main.cpp Sample

#include "CAE.h"

int main() {
  CAE obj("../config.yaml", true);
  // 查询测试
  std::string query_sql = "select * from BASIC_SHIP_INFORMATION_DB.SHIP_DATA_INFO where ship_type = '油船'";
  std::vector<std::vector<DBVariant> > result2;
  std::vector<int> col_types;

  if (obj.Query(query_sql, result2, col_types)) {
    // 输出打印测试
    obj.printResult(result2, col_types);
  }

  // 插入测试
  std::string insert_sql ="insert into BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO (SHIP_DATA_ID, SISTER_DATA_ID, SHIP_NAME) values (7082006, 7082007, 'test No1')";
  if (obj.Insert(insert_sql)) {
    std::cout << "insert done." << std::endl;
  }

  // 更新测试
  std::string update_sql = "update BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO set SHIP_NAME = 'test No1' where SHIP_NAME = 'test No3'";
  if (obj.Update(update_sql)) {
    std::cout << "update done." << std::endl;
  }

  //删除测试
  std::string delete_sql = "delete from BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO where SHIP_NAME = 'test No1'";
  if (obj.Delete(delete_sql)) {
    std::cout << "delete done." << std::endl;
  }

  // 上传文件 指定路径，带文件名 hull_parameter_info
  if (obj.UploadFile("hull_model_and_information_db", "hull_parameter_info", "SampleShip_KCS0000", "HULL_3D_MODEL", "../doc/SampleShip_KCS0000.igs")) {
    std::cout << "Upload file done." << std::endl;
  }
  // 下载文件 指定路径，不带文件名
  if (obj.GetFile("hull_model_and_information_db", "HULL_PARAMETER_INFO", "SampleShip_KCS0000",
                  "HULL_3D_MODEL", "E:/CAE/downfile/")) {
    std::cout << "Download file done." << std::endl;
  }
  //下载字符流
  std::vector<unsigned char> object_data;
  if (obj.GetFile("HuLL_MODEL_AND_INFORMATION_Db", "hull_parameter_info", "SampleShip_KCS0000", "HULL_3D_MODEL", object_data)) {
    std::cout << "Download data stream done." << std::endl;
    std::cout << "object_data size: " << object_data.size() << std::endl;
  }

  // 删除文件
  if (obj.DeleteFile("HULL_MODEL_AND_INFORMATION_DB", "hull_parameter_info", "SampleShip_KCS0000",
                     "HULL_3D_MODEL")) {
    std::cout << "Delete file done." << std::endl;
  }

  //删除记录
  if (obj.DeleteRecord("hull_model_and_information_db", "hull_parameter_info", "SampleShip_KCS0000"))   {
    std::cout << "Delete record done." << std::endl;
  }

  return 0;
}

/* 输出结果

[DB Message]: Connect to server success!
[Logger Message]: Connect to server success!
----------------------------------------------------------------------
[DB Message]: Query Success!
7082006 Al Adailiah 油船 2020-02-28 15 Kuwait Oil Tanker 2025-01-01 LR 
7082009 Bow Explorer 油船 2020-08-01 14 Odfjell 2025-01-01 DNV 
7082014 Eagle Blane 油船 2020-02-01 14.5 AET lnc.Ltd. 2025-01-01 DNV 
7082015 Eagle petrolina 油船 2020-05-01 14.5 AET lnc.Ltd. 2025-01-01 DNV 
7082016 FueLNG Bellina 油船 2020-01-01 11 FueLNG Pte Ltd 2025-01-01 ABS 
7082017 Fujisan Maru 油船 2020-03-23 0 lino Kaiun Kaisha, Ltd. 2025-01-01 NK 
7082018 Future Diamond 油船 2020-01-31 16.5 JX Ocean 2025-01-01 DNV 
7082026 Solar Sharna 油船 2020-06-15 14.5 Tristar Transport LLC 2025-01-01 LR 
7082027 Tove Knutsen 油船 2020-09-28 14.5 Knutsen NYk Offshore Tankers AS 2025-01-01 DNV 
7082030 BW Lotus 油船 2011-01-05 16.1 BW Fleet Management 2025-01-01  
7082031 Marine Vicky 油船 2020-01-13 11.5 V-Bunkers Tankers Pte. Ltd. 2025-01-01 BV 
7082033 Fure Vinga 油船 1905-07-10 13 Furetank Rederi AB 2025-01-01 BV 
7082034 Sea Turtle 油船 1905-07-13 14.2 PTM 2025-01-01 LR 
7082035 114000DWT成品油原油船 油船 2019-01-01 14.1 希腊/马绍尔群岛/巴拿马 2025-01-01 ABS&DNV&BV 
[DB Message]: Insert success!
insert done.
[DB Message]: Update success!
update done.
[DB Message]: Delete success!
delete done.
[DB Message]: File is successfully uploaded.
Upload file done.
Total number of loaded entities 267.
iges转换stl完成
[DB Message]: File successfully downloaded to E:/CAE/downfile//SampleShip_KCS0000.igs
Download file done.
[DB Message]: Get file success.
Download data stream done.
object_data size: 1498632
[DB Message]: File is successfully deleted.
Delete file done.
[DB Message]: Record is successfully deleted.
Delete record done.
----------------------------------------------------------------------
[Logger Message]: Disconnect from server success!
[DB Message]: Disconnect from server success!

*/
```

