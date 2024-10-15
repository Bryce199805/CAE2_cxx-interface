# C++ 数据接口用户手册

C++数据接口为用户提供直接操作达梦数据库的相关API接口，便于拥有管理员权限的用户对数据库中相关库表进行增删改查操作。

## 目录说明
- **lib**  包含数据接口所打包的库文件以及相关依赖
- **include** 数据接口作用到的相关头文件
- **config_withoutFileSystem.yaml**  数据库配置参数文件

## 环境配置
- 中文编码请设置为gb18030
- 将lib目录添加到环境变量中
- 将config_withoutFileSystem.yaml中配置信息修改为本机对应的信息
```yaml
## config_withoutFileSystem.yaml
database:
  server: "192.168.8.201:5236"  # 数据库服务地址 ip:port
  username: "SYSDBA"            # 数据库用户名
  passwd: "SYSDBA"              # 数据库密码
```
## API 用户手册
API包括`CAE`类和`DBVariant`类
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

##### `CAE(const std::string &file_path);`

创建`CAE`对象用于操作数据库，需要用户提供数据库相关配置的`yaml`文件地址

- 形参列表：
  - `file_path`: `yaml`配置文件地址

```c++
CAE obj("../config.yaml");
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

