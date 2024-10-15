# C++ ���ݽӿ��û��ֲ�

C++���ݽӿ�Ϊ�û��ṩֱ�Ӳ����������ݿ�����API�ӿڣ�����ӵ�й���ԱȨ�޵��û������ݿ�����ؿ�������ɾ�Ĳ������

## Ŀ¼˵��
- **lib**  �������ݽӿ�������Ŀ��ļ��Լ��������
- **include** ���ݽӿ����õ������ͷ�ļ�
- **config_withoutFileSystem.yaml**  ���ݿ����ò����ļ�

## ��������
- ���ı���������Ϊgb18030
- ��libĿ¼��ӵ�����������
- ��config_withoutFileSystem.yaml��������Ϣ�޸�Ϊ������Ӧ����Ϣ
```yaml
## config_withoutFileSystem.yaml
database:
  server: "192.168.8.201:5236"  # ���ݿ�����ַ ip:port
  username: "SYSDBA"            # ���ݿ��û���
  passwd: "SYSDBA"              # ���ݿ�����
```
## API �û��ֲ�
API����`CAE`���`DBVariant`��
### Class DBVariant
`DBVariant`�ṩ��һ��ͨ�������������ڴ����ѯ��������ڴ���нӴ����ݿ��в�ѯ�����������͵�ֵ��֧��`std::string`,`int`,`float`,`double`���͡�

#### ���캯��

##### `DBVariant() = default;`

Ĭ�Ϲ��캯��

```c++
DBVariant obj;
```

##### `DBVariant(const std::string& val);`

���ַ�����ʼ������

```c++
DBVariant obj("test string");
```

##### ` DBVariant(int val)`

��`int`���ͳ�ʼ������

```c++
DBVariant obj(10);
```

##### ` DBVariant(float val)`

��`float`���ͳ�ʼ������

```c++
DBVariant obj(12.3);
```

##### ` DBVariant(double val)`

��`double`���ͳ�ʼ������

```c++
DBVariant obj(12.3);
```

#### setValue����
##### `void setValue(const std::string &val);`
���ڽ�ֵ����Ϊ`std::string`���͵���ֵ
- �β��б�
  - val: ��Ҫ�޸ĳ�Ϊ���ַ���
- ����ֵ���ͣ�`void`

```c++
DBVariant obj;
obj.setValue("this is a test string.");
std::cout << obj.asTypeString() << std::endl;  
// �����
// this is a test string.
```

##### `void setValue(int val);`
���ڽ�ֵ����Ϊ`int`���͵���ֵ
- �β��б�
    - val: ��Ҫ�޸ĳ�Ϊ��������ֵ
- ����ֵ���ͣ�`void`

```c++
DBVariant obj;
int a = 10;
obj.setValue(a);
std::cout << obj.asTypeInteger() << std::endl;  
// �����
// 10
```

##### `void setValue(float val);`
���ڽ�ֵ����Ϊ`float`���͵���ֵ
- �β��б�
    - val: ��Ҫ�޸ĳ�Ϊ�ĵ����ȸ�����
- ����ֵ���ͣ�`void`

```C++
DBVariant obj;
float a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeFloat() << std::endl;  
// �����
// 12.3
```

##### `void setValue(double val);`
���ڽ�ֵ����Ϊ`double`���͵���ֵ
- �β��б�
    - val: ��Ҫ�޸ĳ�Ϊ��˫���ȸ�����
- ����ֵ���ͣ�`void`

```c++
DBVariant obj;
double a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeDouble() << std::endl;  
// �����
// 12.3
```



#### asType����
ָ��`DBVariant`����ľ�������ֵ���Ա����������������

##### `std::string asTypeString();`
���ڽ�`DBVariant`������Ϊ`std::string`���͵��ַ���
- ����ֵ��`std::string`�����ַ���

```c++
DBVariant obj;
obj.setValue("this is a test string.");
std::cout << obj.asTypeString() << std::endl;  
// �����
// this is a test string.
```

##### `int asTypeInteger();`
���ڽ�`DBVariant`������Ϊ`int`���͵�������ֵ
- ����ֵ��`int`������ֵ

```
DBVariant obj;
int a = 10;
obj.setValue(a);
std::cout << obj.asTypeInteger() << std::endl;  
// �����
// 10
```

##### `float asTypeFloat();`
���ڽ�`DBVariant`������Ϊ`float`���͵ĵ����ȸ�����
- ����ֵ��`float`���͵ĵ����ȸ�����

```c++
DBVariant obj;
float a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeFloat() << std::endl;  
// �����
// 12.3
```

##### `double asTypeDouble();`
���ڽ�`DBVariant`������Ϊ`double`���͵�˫���ȸ�����
- ����ֵ��`double`���͵�˫���ȸ�����

```c++
DBVariant obj;
double a = 12.3;
obj.setValue(a);
std::cout << obj.asTypeDouble() << std::endl;  
// �����
// 12.3
```



### Class CAE

`CAE`���װ�˶����ݿ�����Ļ�����ɾ�Ĳ鷽�������ṩ�Բ�ѯ����Ĵ�ӡ����������֤

#### ���캯��

##### `CAE(const std::string &file_path);`

����`CAE`�������ڲ������ݿ⣬��Ҫ�û��ṩ���ݿ�������õ�`yaml`�ļ���ַ

- �β��б�
  - `file_path`: `yaml`�����ļ���ַ

```c++
CAE obj("../config.yaml");
```



#### Query����

##### `bool Query(std::string &sql_str, std::vector<std::vector<std::string>>& res);`

ִ���û��ṩ��`select`����`sql`��䣬����ѯ�����`std::string`���ͷ��ص��û�Ԥ�����Ķ�ά`vector`������.

- �β��б�
  - `sql_str`: ��Ҫִ�е�`select`���͵�`sql`��䣬`std::string`�������ô���
  - `res`: �û������Ķ�ά`vector`�������ڲ�����ӦΪ`std::string`�����ڴ�Ų�ѯ��������ô���
- ����ֵ���ͣ�`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
// ���в�ѯ����ӡ���
if(obj.Query(sql_str, res)){
    obj.printResult(res);
}
```

##### `bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>>& res);`

ִ���û��ṩ��`select`����`sql`��䣬����ѯ�����`DBVariant`���ͷ��ص��û�Ԥ�����Ķ�ά`vector`�����У����ý����ʹ��`DBVariant`�෽��ָ��Ϊ��������͡�

- �β��б�
  - `sql_str`: ��Ҫִ�е�`select`���͵�`sql`��䣬`std::string`�������ô���
  - `res`: �û������Ķ�ά`vector`�������ڲ�����ӦΪ`DBVariant`�����ڴ�Ų�ѯ��������ô���
- ����ֵ���ͣ�`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<DBVariant>> res;
// ���в�ѯ
if(obj.Query(sql_str, res)){
	std::cout << "query success." << std::endl;
}
```

##### `bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>>& res, std::vector<int>& col_types);`

ִ���û��ṩ��`select`����`sql`��䣬����ѯ�����`DBVariant`���ͷ��ص��û�Ԥ�����Ķ�ά`vector`�����У�������ѯ��ÿһ�е���������ֵ����ʽ���ص�`int`���͵�`vector`�����У����ò�ѯ���ʱ��ʹ��`DBVariant`�෽��ָ��Ϊ��������͡�

- �β��б�
  - `sql_str`: ��Ҫִ�е�`select`���͵�`sql`��䣬`std::string`�������ô���
  - `res`: �û������Ķ�ά`vector`�������ڲ�����ӦΪ`DBVariant`�����ڴ�Ų�ѯ��������ô���
  - `col_types`���û�������`int`����`vector`���������ڴ�Ų�ѯ���ÿһ�е����ͣ����ô���
    - 0: `std::string`
    - 1: `int`
    - 2: ` float`
    - 3: `double`
- ����ֵ���ͣ�`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
std::vector<int> types;
// ���в�ѯ����ӡ���
if(obj.Query(sql_str, res)){
    obj.printResult(res, types);
}
```


#### Delete����
##### `bool Delete(std::string &sql_str);`

ִ���û��ṩ��`delete`����`sql`��䣬����ؼ�¼����ɾ��������

- �β��б�
  - `sql_str`: ��Ҫִ�е�`delete`���͵�`sql`��䣬`std::string`�������ô���
- ����ֵ���ͣ�`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "delete from TestDB.TestTable where id > 10";

// ִ��ɾ��
if(obj.Delete(sql_str)){
	std::cout << "delete success." << std::endl;
}
```

#### Update����
##### `bool Update(std::string &sql_str);`

ִ���û��ṩ��`update`����`sql`��䣬����ؼ�¼���и��²�����

- �β��б�
  - `sql_str`: ��Ҫִ�е�`update`���͵�`sql`��䣬`std::string`�������ô���
- ����ֵ���ͣ�`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "update TestDB.TestTable set col1 = val1 where id > 10";

// ִ�и���
if(obj.Update(sql_str)){
	std::cout << "update success." << std::endl;
}
```



#### Insert����
##### `bool Insert(std::string &sql_str);`

ִ���û��ṩ��`insert`����`sql`��䣬�����н��м򵥵Ĳ��빦�ܡ�

- �β��б�
  - `sql_str`: ��Ҫִ�е�`insert`���͵�`sql`��䣬`std::string`�������ô���
- ����ֵ���ͣ�`bool`

```c++
CAE obj("../config.yaml");
std::string sql_str = "insert into TestDB.TestTable values (val1, val2, val3);

// ִ��ɾ��
if(obj.Insert(sql_str)){
	std::cout << "insert success." << std::endl;
}
```


#### printResult����
##### `void printResult(std::vector<std::vector<std::string>>& res);`

����`std::string`�����������صĲ�ѯ������д�ӡ

- �β��б�
  - `res`: �û������Ķ�ά`vector`�������ڲ�����ӦΪ`std::string`��`Query`�����õ��Ĳ�ѯ��������ô���
- ����ֵ���ͣ�`void`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
// ���в�ѯ����ӡ���
if(obj.Query(sql_str, res)){
    obj.printResult(res);
}
```

##### `void printResult(std::vector<std::vector<DBVariant>>& res, std::vector<int>& col_types);`

����`DBVariant`�����������صĲ�ѯ������д�ӡ

- �β��б�
  - `res`: �û������Ķ�ά`vector`�������ڲ�����ӦΪ`DBVariant`��`Query`�����õ��Ĳ�ѯ��������ô���
- ����ֵ���ͣ�`void`

```c++
CAE obj("../config.yaml");
std::string sql_str = "select * from TestDB.TestTable where id > 10";
std::vector<std::vector<std::string>> res;
std::vector<int> types;
// ���в�ѯ����ӡ���
if(obj.Query(sql_str, res)){
    obj.printResult(res, types);
}
```

