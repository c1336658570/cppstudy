# c++ Pirmer

## chap2

- 常量表达式：值不会改变且在编译过程就能得到计算结果的表达式
- constexpr：将变量声明为constexpr类型以便由编译器来验证变量的值是否是一个常量表达式。声明为constexpr变量一定是一个常量，而且必须用常量表达式初始化。

```c++
constexpr int mf = 20;
constexpr int limit = mf + 1;
constexpr int sz = size(); //当size是一个sonstexpr函数时才是正确的声明语句
```

- 指针和constexpr

```c++
constexpr int *np = nullptr; //np是一个指向整数的常量指针
const int *p = nullptr; //p是一个指向常量的指针
```

- 类型别名 

1. typedef
2. using

```c++
using SI = Sales_iteml; //SI是Sales_item的同义词
```

- auto类型说明符：编译器分析表达式所属类型（一般会忽略掉顶层const）

- decltype类型指示符：选择并返回操作数的数据类型（如果decltype使用的表达式是一个变量，则decltype返回该变量的类型包括顶层const和引用在内）

```c++
decltype(f()) sum = x; //sum的类型就是函数f的返回类型

const int ci = 0, &cj = ci;
decltype(ci) x = 0; //x的类型是const int
decltype(cj) y = x; //y的类型是const int &, y 绑定到变量x
decltype(cj) z; //z是一个引用必须初始化
```

- decltype和引用：如果decltype使用的表达式不是一个变量，则decltype返回表达式结果对应的类型。

```c++
//decltype的结果可以是引用类型
int i = 42, *p = &i, &r = i;
decltype(r + 0) b; //正确：加法结果为int，b是一个未初始化int
decltype(*p) c; //错误：c是int&， 必须初始化

r是一个引用，decltype(r)结果是引用，如果让结果类型是r指向的类型，可以把r作为表达式一部分，如r+0，这个表达式的结果是一个具体值而非引用
如果表达式是解引用操作，则decltype将得到引用类型。
    
decltype和auto重要区别：decltype的结果类型与表达式形式密切相关。如果变量名加上一对括号，则得到类型与不加括号时会有不同。 如果decltype使用的是一个不加括号的变量，则得到的结果就是该变量的类型：如果给变量加上一层或多层括号，编译器就会把它当作是一个表达式。变量是一种可以作为赋值语句左值的特殊表达式，所以这样的decltype就会得到引用类型。

//decltype表达式如果是加上括号的变量，结果将是引用
decltype((i)) d; //错误：d是int&，必须初始化
decltype(i) e; //正确：e是一个（未初始化的int）

注：decltype((variable))结果永远是引用，decltype(variable)结果只有当variable本身就是引用时才是引用
```

### chap 3

- 定义和初始化string对象

```c++
string s1;
string s2(s1);
string s2 = s1;
string s3("value");
string s3 = "value";
string s4(n, 'c');
```

- string对象上的操作

```c++
os << s 将s写到输出流s中，返回os
is >> s 从is中读取字符串给s，以空白分隔，返回is
getline(is, s); 从is读取一行赋给s，返回is
s.empty() s为空返回true，否则返回false
s.size() 返回s中字符的个数
s[n] 返回s中第n个字符的引用
s1+s2 返回s1和s2连接后的结果
s1 = s2 用s2的副本代替s1原来的字符
s1 == s2 如果s1和s2中字符完全一样，则相等
s1 != s2
<, <=, > , >=字典排序

```

- string::size_tpye类型

用来存放string类的size函数返回值的变量

- 基于范围的for语句

```c++
for(declaration : expression)
    statement
expression部分是一个对象，用于表示一个序列。declaration部分是一个变量，该变量将用于访问序列中的基础元素。每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值。

例：
string str("some string");
for(auto c : str)
    cout << c << endl;

string s("Hello World!!!");
decltype(s.size()) punct_cnt = 0;
for (auto c : s)
    if (ispunct(c)) //如果该字符是标点符号
		++punct_cnt;
cout << punct_cnt << "punctuation characters in" << s << endl;
```

- 使用范围for语句改变字符串中的字符

```c++
//小转大
string s("Hello World!!!");
for (auto &c : s)
    c = toupper(c);
cout << s << endl;
```

- 使用下标执行迭代

```c++
//依次处理s中的字符，直到处理完或者遇到空白
for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    s[index] = toupper(s[index]);
```



- 定义和初始化vector对象

```c++
vector<T> v1; //默认初始化
vector<T> v2(v1); //v2包含了v1的元素的副本
vector<T> v2 = v1;
vector<T> v3(n, val); //v3包含了n个重复元素，每个元素的值都是val
vector<T> v4(n); //v4包含了n个重复执行了值初始化的对象
vector<T> v5{a, b, c,...}; //v5包含了初始值个数的元素，每个元素被赋予相应的初始值
vector<T> v5 = {a, b, c};
```

```c++
vector<int> ivec(10); //10个元素，每个都初始化为0
vector<string> svec(10); //10个元素，每个都是空string对象

注：某些类必须明确提供初始值，如果vector不支持默认初始化，我们就必须提供初始的元素值。对这种类型来说，只提供元素数量而不设定初始值无法完成初始化工作。
如果只提供了元素数量而没有设定初始值，只能使用直接初始化。
```

```c++
vector<int> v1(10); //v1由10个元素，都是0
vector<int> v2{10}; //v2由1个元素，值是10

vector<int> v3(10, 1); //v3由10个元素，值都是1
vector<int> v4{10, 1}; //v4由两个元素，值分别是10和1

{}花括号中的值与vector的元素类型相匹配，为列表初始化，不匹配时需考虑其他情况。

vector<string> v5{"hi"}; //列表初始化
vector<string> v6("hi"); //错误，不能使用字符串字面常量构造vector对象
vector<string> v7{10}; //v7有10个默认初始化的元素
vector<string> v8{10, "hi"}; //v8有10个值为"hi"的元素
注：只有v5是列表初始化
```

- 向vector对象中添加元素

```c++
vector<T> v2;
v2.push_back(T);
```

- 其他vector操作

```c++
v.empty() 如果v不含任何元素，返回真，否则返回假
v.size() 返回v中元素个数
v.push_back(t) 向v尾端添加一个值为t的元素
v[n] 返回v中第n个位置上元素的引用
v1 = v2 用v2中元素的拷贝替换v1中的元素
v1 = {a, b, c} 用列表中元素拷贝替换v1中的元素
v1 == v2 v1和v2相等当且仅当它们的元素数量相同且对应位置元素值都相同
v1 != v2    
<, <=, >, >= 顾名思义，以字典顺序进行比较   
    
vector<int>::size_type //正确
string::size_type //正确
vecotr::size_type //错误
```

- 迭代器运算符

```c++
*iter 返回迭代器iter所指元素的引用
iter->mem 解引用iter并获取该元素的名为mem的成员，等价于（*iter）.mem
++iter 令iter指示容器中的下一个元素
--iter 令iter指示容器中的上一个元素
iter1 == iter2 判断两个迭代器是否相等
iter1 != iter2
```

- 迭代器类型

```c++
vector<int>::iterator it; //it能读写vector<int>的元素
string::iterator it2; //it2能读写string对象中的字符

vector<int>::const_iterator it3; //it3只能读元素，不能写元素
string::const_iterator it4; //it4只能读字符，不能写字符

cbegin和cend 返回常量迭代器（返回值为const_iterator）
```

- 迭代器运算

```c++
//vector和string迭代器支持的运算
iter + n  迭代器加上一个整数值仍得到一个迭代器，迭代器指示的新位置与原来相比向前移动了若干个元素。结果迭代器或者指示容器内的一个元素，或者指示容器尾元素的下一位置  
iter - n 迭代器减去一个整数值仍得一个迭代器，迭代器指示的新位置与原来相比向后移动了若干元素。结果迭代器或者指示容器内的一个元素，或者指示容器尾元素的下一位置  
iter1 += n 迭代器加法的复合赋值语句，将iter1加n的结果赋给iter1
iter1 -= n 迭代器减法的复合赋值语句，将iter1减n的结果赋给iter1
iter1 - iter2 两个迭代器相减的结果是它们之间的距离，也就是说，将运算符右侧的迭代器向前移动差值个元素后将得到左侧的迭代器，参与运算的两个迭代器必须指向同一容器中的元素或者尾元素的下一位置
>、>=、<、<= 迭代器的关系运算符，如果某迭代器指向容器位置在另一个迭代器所指位置之前，则说前者小于后者。参与运算的两个迭代器必须指向同一容器中的元素或者尾元素的下一位置
```

- 迭代器相减后的类型：类型为difference_type的带符号整形数

- 数组下标的类型：通常为size_t（无符号整形）

```c++
int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto ia2(ia); //ia2是一个整形指针，指向ia的第一个元素（编译器会默认把数组名转为指向数组首元素的指针）
decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //ia3是一个含有10个整数的数组（编译器不会转换）
ia3[4] = 5; //正确
```

- 指针也是迭代器

```c++
//迭代器支持的运算指针都支持
//利用指针遍历元素
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *e = &arr[10]; //指向尾元素下一个元素
for (int *b = arr; b != e; ++b)
    cout << *b << endl; //输出arr的元素
```

- 标准库函数begin和end

```c++
int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *beg = begin(ia); //指向ia首元素的指针
int *last = end(ia); //指向arr尾元素的下一位置的指针
```

- 指针的运算

```c++
//迭代器支持的运算指针都支持
constexpr size_t sz = 5;
int arr[sz] = {1, 2, 3, 4, 5};
int *ip = arr; //ip指向arr[0]
int *ip2 = ip + 4; //ip2指向arr[4]

//两个指针相减的类型为ptrdiff_t类型（指针相减可能为负，所以带符号类型）
//两个指针相减的结果为它们之间的距离
```

- 数组下标和指针

```c++
int ia[] = {0, 2, 4, 6, 8};
int i = ia[2];
int *p = &ia[2];
int j = p[1];
int k = p[-2]; //等价于ia[0]
//数组下标可以为负，string和vector下标为无符号整形，必须为正（标准库下标必须为正，内置数据类型无要求）
```

- 混用string对象和C风格字符串

```c++
//string转c风格字符串
string s("Hello World");
char *str = s;//错误，不能用string对象初始化char *
const char *str = s.c_str(); //正确
```

- 使用数组初始化vector对象

```c++
//不允许使用一个数组为另一个内置类型的数组赋初值，也不允许使用vector对象初始化数组。相反的，允许使用数组来初始化vector对象。

//利用整个数组初始化vector容器
int int_arr[] = {0, 1, 2, 3, 4, 5};
vector<int> ivec(begin(int_arr), end(int_arr));

//利用数组部分元素初始化vector对象，拷贝三个元素：int_arr[1], int_arr[2], int_arr[3]
vector<int> subVec(int_arr+1, int_arr+4);
```

- 使用范围的for语句处理多维数组

```c++
int ia[3][4];
size_t cnt = 0;
for (auto &row : ia) //对于外层数组的每一个元素
    for(auto &col : row) //对于内层数组的每一个元素
    {
        col = cnt; //将下一个值赋给该元素
        ++cnt; //将cnt加1
    }
//row（含有4个整数的数组的引用），col（整数的引用）
```

```c++
int ia[3][4];
for(const auto &row : ia) //对于外层数组的每一个元素
    for (auto col : row) //对于内层数组的每一个元素
        cout << col << endl;
//该程序没有任何读写操作，外层循环设置为引用类型，为了避免数组被自动转换成指针。

for(auto row : ia) //对于外层数组的每一个元素
    for (auto col : row) //对于内层数组的每一个元素
//上述程序将无法通过编译，因为第一个循环便利ia的所有元素，ia的元素实际上是大小为4的数组。因为row不是引用类型，编译器会初始化row时自动将这些数组形式的元素转换成指向数组内首元素的指针。这样row的类型就是int *，内层循环就是不合法的
```

- 指针和多维数组

```c++
int ia[3][4]; //大小为3的数组，每个元素是含有4个整数的数组
int (*p)[4] = ia; //p指向含有4个整数的数组
p = &ia[2]; //p指向ia的尾元素

//使用auto或者decltype就能尽可能避免数组前面加上一个指针类型
//输出ia中每个元素的值
//p指向含有4个整数的数组
for (auto p = ia; p != ia + 3; ++p)
{
    //q指向4个整数数组的首元素
    for (auto q = *p; q != *p + 4; ++q)
    {
        cout << *q << ' ';
    }
    cout << endl;
}

//使用标准库函数begin和end实现上述功能
//p指向ia的第一个数组
for (auto p = begin(ia); p != end(ia); ++p)
{
    //q指向内层数组的首元素
    for (auto q = begin(*p); q != end(*p); ++q)
    {
        cout << *q << ' ';
    }
    cout << endl;
}
```

- 类型别名简化多维数组指针

```c++
int ia[3][4];
usingg int_array = int[4];
typedef int int_array[4]; //等价

for (int_array *p = ia; p != ia + 3; ++p)
{
    for (int *q = *p; q != *p + 4; ++q)
    {
        cout << *q << ' ';
    }
    cout << endl;
}
```

## chap 4

- 赋值运算符

```c++
//C++11标准允许使用花括号括起来的初始值列表作为赋值语句的右侧运算对象
int k = {3.14}; //错误：窄化转换
vector<int> vi; //初始为空
vi = {0, 1, 2, 3, 4, 5 , 6, 7, 8, 9}; //vi含有10个元素，从0-9
```

