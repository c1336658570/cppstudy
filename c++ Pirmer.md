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

- 移位运算符优先级：比算术运算符优先级低，比关系运算符，赋值运算符和条件运算符优先级高。

```c++
cout << 42 + 12; //正确
cout << (10 < 42); //正确
cout << 10 < 42; //错误：试图比较cout和42！
```

- sizeof运算符：结果为size_t类型

对数组执行sizeof运算得到整个数组所占空间大小，等价于对数组所有元素sizeof一次，并对所得结果求和，（sizeof不会把数组转成指针来处理）。

堆string对象和vector对象执行sizeof运算只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间。

- 其他隐式类型转换

当数组被用作decltype关键字的参数，或者作为取地址（&）、sizeof及typeid等运算符的运算对象时，上述转换不会发生。同样，用一个引用来初始化数组，上述转换也不会发生。

- 命名的强制类型转换

```c++
强制类型转换形式：cast-name<type>(expression);
type时转换的目标类型而expression时要转换的值。cast-name是static_cast、dynamic_cast、const_cast和reinterpret_cast中的一种。dynamic_cast支持运行时类型识别。
```

- static_cast

​		任何具有名取定义的类型转换，只要不包含底层const，都可以使用static_cast。

​		例如，通过一个运算对象强制转换成double类型就能使表达式执行浮点数除法。

```c++
//进行强制类型转换以便执行浮点数除法
double slope = static_cast<double>(j) / i;

//使用static_cast找回存在于void *指针中的值
void *p = &d;
double *dp = static_cast<double*>(p);
```

- const_cast

​		const_cast只能改变运算对象的底层const

```c++
//将常量对象转成非常量对象
const char *pc;
char *p = const_cast<char *>(pc);

//只有const_cast能改变表达式的常量属性，使用其他形式的命名强制类型转换改变表达式的常量属性都将发生编译器错误。同样的，也不能用const_cast改变表达式的类型
const char *cp;
//错误static_cast不能转换掉const性质
char *q = static_cast<char *>(cp);
static_cast<string>(cp); //正确：字符串字面值转为string类型
const_cast<string>(cp); //错误const_cast只改变常量属性
```

- reinterpret_cast

​		reinterpret_cast通常为运算对象的位模式提供较低层次上的重新解释。例如：

```c++
int *ip;
char *pc = reinterpret_cast<char *>(ip);
//必须记住pc指向真实对象是int而非字符，如果把pc当成普通的字符指针使用就可能运行时发生错误，例如：
string str(pc);
//可能导致异常的运行时行为。
```

## chap5

- 范围for语句

```c++
for (declaration : expression)
    statement;
expression必须是一个序列，比如用花括号括起来的初始值列表、数组或者vector或string等类型的对象，这些类型的共同特点是拥有能返回迭代器begin和end成员。
declaration定义了一个变量，序列中的每个元素都能转换成该变量的类型。确保类型相容最简单的办法是使用auto类型说明符。如果需要堆序列中的元素执行写操作，循环变量必须声明为引用类型。
每次迭代都会重新定义循环控制变量，并将其初始化成序列中的下一个值，之后才会执行statement。所有元素处理万循环终止
```

```c++
vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto &r : v)
{
    r *= 2;
}

//等价的传统for语句
for (auto beg = v.begin(), end = v.end(); beg != end; ++beg)
{
    auto &r = *beg;
    r *= 2;
}

不能通过范围for语句添加vector对象（或其他容器）的元素。在范围for语句中，预存了end()的值。一旦在这个序列中添加（删除元素），end函数的值可能变的无效了。
```

- try语句块和异常处理

```c++
异常处理包括：
throw表达式，异常检测部分使用了throw表达式来表示它遇到了无法处理的问题，我们说throw引发（raise）了异常。
tyr语句块，异常处理部分使用try语句块处理异常。try语句块以关键字try开始，并以一个或多个catch子句结束。try语句块中代码抛出的异常通常会被某个catch子句处理。因为catch子句“处理”异常，所以它们也被称作异常处理代码。
一套异常类，用于在throw表达式和相关的catch子句之间传递异常的具体信息。
```

- throw表达式

```c++
程序的异常检测部分使用throw表达式引发一个异常。throw表达式包含关键字throw和紧随其后的一个表达式，其中表达式的类型就是抛出异常的类型。

例如：
Sales_item item1, item2;
cin >> item1 >> item2;
//首先检查item1和item2是否表示同一种书籍
if (item1.isbn() == item2.isbn())
{
    cout << item1 + item2 << endl;
    return 0;
}
else
{
    cerr << "Data must refer to same ISBN" << endl;
    return -1;
}

//改写程序，使检查完后不再输出一条信息，而是抛出一个异常
if (item1.isbn() != item2.isbn())
{
    throw runtime_error("Data must refer to same ISBN");
}
cout << item1 + item2 << endl;
//如果ISBN不一样就抛出一个异常，该异常类型为runtime_error的对象。抛出异常将终止当前的函数，并把控制权转移给能处理该异常的代码。
//runtime_error是标准库异常类型的一种，在头文件stdexcept中。
```

- try语句块

```c++
语法
try
{
    program-statements
}
catch (exception-declaration)
{
    handler-statments
}
catch (exception-declaration)
{
    handler-statments
}
//...
catch子句包括3部分：关键字catch、括号内一个（可能未命名）对象的声明（称作异常声明，exception declaration）以及一个块。当选中了某个catch子句处理异常后，执行与之对应的块。catch一旦完成，程序跳转到try语句块最后一个catch子句之后的那条语句继续执行。
try语句块中的program-statements组成程序正常逻辑，program-statements可以包括声明在内的任意C++语句。try语句内声明的变量无法在块外访问，特别是catch子句内也无法访问。

//编写处理异常代码
while (cin >> item1 >> item2)
{
    try
    {
        //执行添加两个Sales_item对象的代码
        //如果添加失败，代码抛出一个runtime_error异常
    }
    catch (runtime_error err)
    {
        //提醒用户两个ISBN必须一致，询问是否重新输入
        cout << err.what() << "\nTry Again? Enter y or n" << endl;
        char c;
        cin >> c;
        
        if (!cin || c == 'n')
        {
            break; //跳出while循环
        }
    }
}

err.what()返回C风格字符串（即const char *)。其中runtime_error的what成员返回的是初始化一个具体对象时所用的string对象的副本。

//如果编写的代码抛出异常，则catch子句输出
Data must refer to same ISBN
Try Again? Enter y or n
```

- 标准异常（定义在在4个头文件中）

1. exceptrion头文件定义了最通用的异常类exception。它只报告异常的发生，不提供任何额外信息。
2. stdexcept头文件定义了如下表几种异常类。
3. new头文件定义了bad_alloc异常类型。
4. type_info头文件定义了bad_cast异常类型。

```c++
exception 					最常见的问题
runtime_error				只有在运行时才能检测出来的问题
range_error					运行时错误：生成的结果超过了有意义的值域范围
overflow_error				运行时错误：计算上溢
underflow_error				运行时错误：计算下溢
logic_error					程序逻辑错误
domain_error				逻辑错误：参数对应的结果值不存在
invalid_argument			逻辑错误：无效参数
length_error				逻辑错误：试图创建一个超出该类型最大长度的对象
out_of_range				逻辑错误：使用一个超出有效范围的值
```

只能以默认初始化方式初始化exception、bad_alloc和bad_cast对象，不允许提供初始值。

其他异常恰好相反：应该使用string对象或C风格字符串初始化这些对象，但是不允许默认初始化的方式。

## chap 6

- 数组型参

```c++
数组的两个特殊性值对我们定义和使用作用在数组上的函数有影响，这两个性质分别是：不允许拷贝数组以及使用数组时（通常）会将其转换成指针。我们不能拷贝数组，所以我们无法以值传递方式使用数组参数。因为数组会被转成指针，当我们传递一个数组时，实际传递的是指向数组首元素的指针。
void print(const int *);
void print(const int[]);
void print(const int [10]);
//三者等价
```

- 管理指针型参的三种常用技术

1. 使用标记指定数组长度

```c++
例如c风格字符串，以空字符结尾
void print(const char *cp)
{
    if (cp)
    {
        while (*cp)
        {
            cout << *cp++;
        }
    }
}
//此方法适用于由明显结束标记且不会与普通数据混淆的情况，但是对int类型就不太有效了
```

2. 使用标准库规范

```c++
//传递指向数组首元素和尾元素的指针。
void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << endl;
    }
}
```

3. 显式传递一个表示数组大小的型参

```c++
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}

//调用
int j[] = {0, 1};
print(j, end(j) - begin(j));
```

- 数组引用型参

```c++
void pinrt(int (&arr)[10])
{
    for (auto elem : arr)
    {
        cout << elem << endl;
    }
}
//限制了print函数的可用性，只能将函数作用于大小为10的数组。
```

- 传递多维数组

```c++
void print(int (*matrix)[10], int rowSize)
{
    
}
//等价于
void print(int matrix[][10], int rowSize)
{
    
}
```

- main：处理命令行选项

```c++
向main函数传递实参，常见情况是用户通过设置一组选项来确定函数所要执行的操作。例如，加入main函数位于可执行文件prog内，可以向程序传递下面的选项：
prog -d -o ofile data0
这些命令行选项通过两个（可选的）型参传递给main函数：
int main(int argc, char *argv[])
{
}
//等价于
int main(int argc, char **argv)
{
}
```

- 含有可变型参的函数

```c++
initializer_list型参
如果函数的实参数量未知，但是全部实参类型都相同，可以使用initializer_list类型性的性参。initializer_list是一种标库类型，用于表示某种特定类型的值的数组。initializer_list定义在同名头文件中。

initializer_list<T> lst;				默认初始化；T类型元素的空列表
initializer_list<T> lst{a, b, c...};	lst的元素数量和初始值一样多；lst的元素是对应初始值的副本；列表中的元素是const
lst2(lst)								拷贝或赋值一个initializer_list对象不会拷贝列表中的元素；拷贝后，元列表和副本共享元素
lst.size()								列表中的元素数量
lst.begin()								返回指向lst中首元素的指针
lst.end()								返回指向lst中尾元素下一位置的指针
```

```c++
//和vector一样，initializer_list也是一种模板类型，定义时必须说明元素类型
initializer_list<string> ls;
initializer_list<int> li;
//和vector不一样的是，initializer_list对象中的元素永远是常量值，我们不能改变initializer_list对象中的元素值。

//使用如下形式编写输出错误信息的函数，使其可以作用域可变数量的实参：
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl;
}

//如果想像initializer_list型参中传递一个值序列，必须把序列放在一对花括号内
//expected和actual是string对象
if (expected != actual)
{
    error_msg({"functionX", expected, actual});
}
else
{
    error)msg({"functionX", "okay"});
}

//含有initializer_list型参的函数可能拥有其他型参。例如，调试系统可能有个名为ErrCode的类用来表示不同类型的错误。
void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)
    {
        cout << elem << " ";
    }
    cout << endl;
}

//上述代码调用
if (expected != actual)
{
    error_msg(ErrCode(42), {"functionX", expected, actual});
}
else
{
    error_msg(ErrCode(0), {"fuctionX", "okay"});
}
```

- 省略符型参（只能出现在型参列表的最后一个位置）

```c++
//两种形式
void foo(parm_list, ...);
void foo(...);
```

- 列表初始化的返回值

```c++
C++11规定，函数可以返回花括号包围的值的列表。此处列表也用来对表示函数返回的临时量进行初始化。如果列表为空，临时量执行值初始化；否则，返回的值由函数的返回类型决定
    
vector<string> process()
{
    //...
    //expected和actual是string对象
    if (expected.empty())
    {
        return {}; //返回空vector对象
    }
    else if (expected == actual)
    {
        return {"functionX", "okay"}; //返回列表初始化的vector对象
    }
    else
    {
        return {"functionX", expected, actual};
    }
}
```

- main返回值

```c++
返回0表示成功，其他值表示失败，非0的含义由机器而定。为使返回值与机器无关，cstdlib头文件定义了两个预处理变量，可以用这俩变量表示成功与失败
int main()
{
    if (some_failure)
    {
        return EXIT_FAILURE; 
    }
    else
    {
        return EXIT_SUCCESS;
    }
}
```

- 返回数组指针

```c++
//数组不能拷贝，所以函数不能返回数组。不过，能返回数组的指针或引用。

typedef int arrT[10]; //arrT是一个类型别名，它表示的类型是含有10个整形的数组

using arrT = int[10]; //等价声明
arrT *func(int i); //返回一个指向含有10个整数的数组的指针
```

```c++
//返回数组指针的函数
Type (*function(parameter_list))[dimension];
//Type表示元素类型，dimension表示数组大小。
int (*func(int i))[10];
```

- 使用尾置返回类型

```c++
//尾置返回类型跟在型参列表后面并以一个->符号开头。为了表示函数真正的返回类型跟在型参列表之后，我们在本应该放置返回类型的地方方一个auto
auto func(int i) -> int(*)[10];
```

- 使用decltype

```c++
//如果我们知道函数返回的指针指向哪个数组，就可以使用decltype关键字声明返回类型。例如：
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
//返回一个指针，该指针指向含有5个整数的数组
decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even; //返回一个指向数组的指针
}
//decltype并不负责把数组类型转换成对应的指针，所以decltype的结果是个数组，要想表示arrPtr返回指针还必须在函数声明时加一个*符号。
```

- 函数重载：名字相同但型参列表不同

```c++
void print(const cahr *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);

int j[2] = {0, 1};
print("Hello World"); // 调用print(const cahr *);
print(j, end(j) - begin(j)); //调用print(const int *, size_t );
print(begin(j), end(j)); //调用print(const int *, const int *);
```

不允许两个函数除了返回类型外其他所有要素都相同。

- 重载和const型参

```c++
顶层const不影响传入函数的对象。一个拥有顶层const的型参无法和另一个没有顶层const的型参区分开来
Record lookup(Phone);
Record lookup(const Phone); //重复声明了Record lookup(Phone);

Record lookup(Phone *);
Record lookup(Phone * const); //重复声明了Record lookup(Phone *);
```

```c++
如果型参是某种类型的指针或引用，则通过区分其指向的是常量对象还是非常量对象可以实现函数重载，此时的const是底层的。
Record lookup(Account &);
Record lookup(const Account &); //新函数，作用于常量

Record lookup(Account *); //新函数，作用于指向Account的指针
Record lookup(const Account *); //新函数，作用于指向常量的指针
```

- const_cast和重载

```c++
//如果实参是常量引用，就调用这个，返回一个常量引用
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2; //返回长度短的那个，不管实参是不是常量引用，都返回常量引用
}
//重载版本，如果实参是非常量引用，就调用这个，返回一个非常量引用
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string &>(r);
}
```

- 默认实参

```c++
typedef string::size_type sz;
string screen(sz ht = 24, sz = wid = 80, char backgrnd = ' ');
//默认实参可以有多个，某个型参被赋予默认值，其后的型参都必须由默认值。

//调用
window = screen(); //等价于screen(24, 80, ' ');
window = screen(66); //等价于screen(66, 80, ' ');
window = screen(66, 256); //等价于screen(66, 256, ' ');
window = screen(66, 256, '#'); //等价于screen(66, 256, '#');

window = screen(, , '?'); //错误，只能省略尾部实参
window = screen('?'); //调用screen('?', 80, ' '); '?'被隐式转为string::size_type类型，作为heitght的值传给函数。 '?'对应0x35，也就是十进制数63，所以将63传给了height。
```

- 默认型参声明：给定作用域中一个型参只能被赋予一次默认实参。即，函数后续声明中只能为没有默认值的型参添加默认实参，而且该实参右侧必须所有型参都有默认值。

```c++
//例如，表示高度和宽度的型参没有默认值
string screen(sz, sz, char = ' ');
//错误，不能修改已经存在的默认值
string screen(sz, sz, char = '*');
//正确，添加默认实参
string screen(sz = 24, sz = 80, char);
```

- 默认实参的初始值

```c++
局部变量不能作为默认实参。除此之外，只要表达式的类型能转换成型参所需的类型，该表达式就能作为默认实参。
//wd、def和ht的声明必须出现在函数之外
sz wd = 80;
char def = ' ';
sz ht();
string screen(sz = ht(), sz = wd, char = def);
string window = screen(); //调用screen(ht(), 80, ' ');

//用作默认实参的名字在函数声明所在的作用域内解析，而这些名字的求值过程发生在函数调用时：
void f2()
{
    def = '*';
    sz wd = 100; //该局部变量wd虽然屏蔽了全局变量wd，但是该局部变量和函数调用没有任何关系
    window = screen(); //调用screen(ht(), 80, '*');
}
```

- 内联函数和constexpr函数

- 内联函数可避免函数调用的开销（调用前保存寄存器，并在返回时恢复；可能需要拷贝实参；程序转向一个新的位置继续执行）。

```c++
//将函数指定为内联函数，通常就是将它在每个调用点上“内联的”展开。假设我们把shorterString函数定义为内联函数，则如下调用
cout << shorterString(s1, s2) << endl;
//将在编译过程展开成类似下面的形式，从而消除了shorterString函数运行时开销
cout << (s1.size() < s2.size() ? s1 : s2) << endl;

//在shorterString函数的返回类型前面加上关键字inline，这样就可以将它声明成内联函数了：
//内联版本：寻找两个string对象中较短的哪个
inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
```

- constexpr函数

```c++
//constexpr函数是指能用于常量表达式的函数。定义该类型函数时几项约定：函数的返回类型及所有型参类型都得是字面值类型，而且函数体中必须有且只有一条return语句
constexpr int new_sz()
{
    return 42;
}
constexpr int foo = new_sz(); //正确：foo是一个常量表达式
//把new_sz定义为无参数的constexpr函数。因为编译器能在编译时验证new_sz函数返回的是常量表达式，所以可以用new_sz函数初始化constexpr类型的变量foo。
//执行初始化任务是，编译器把堆constexpr函数的调用替换成其结果值。为了能在编译过程中随时展开，constexpr函数被隐式地指定为内联函数。
//constexpr函数体也可以包含其他语句，只要这些语句在运行时不执行任何操作就行。例如，空语句、类型别名以及using声明。
//我们允许constexpr函数返回值并非一个常量
//如果arg时常量表达式，则scale(arg)也是常量表达式
constexpr size_t scale(size_t cnt)
{
    return new_sz() * cnt;
}
//当scale的实参时常量表达式时，它的返回值也是常量表达式，反之则不然
int arr[scale[2]]; //正确，scale(2)是常量表达式
int i = 2; //i不是常量表达式
int a2[scale(i)]; //错误，scale(i)不是常量表达式
```

- 把内联函数和constexpr函数放在头文件内

​		内链函数和constexpr函数和其他函数不同，它可以在程序中多次定义，但是多次定义必须完全一致。基于这个原因，内联函数和constexpr函数通常定义在头文件中。

- 调试帮助
- assert预处理宏。（定义在cassert头文件中）

​		assert宏使用一个表达式作为它的条件：

​		assert(expr);

​		首先对expr求值，如果为假，assert输出信息并终止程序，如果为真，assert什么也不做

```c++
//assert宏常用于检查“不能发生”的条件。例如，一个堆输入文本进行操作的程序可能要求所有给定单词的长度都大于某个阈值。此时，程序可以包含一条如下所示的语句
assert(word.size() > threshold);
```

- NDEBUG预处理变量

​		assert的行为依赖于NDEBUG的预处理变量的状态。如果定义了NDEBUG，则assert什么也不做。默认状态没有定义NDEBUG，此时assert将执行运行时检查。

```c++
cc -D NDEBUG main.c # use /D with the Microsoft compiler
//此命令等价于在main.c开头写#define NDEBUG
```

```c++
//除了用assert外，也可以使用NDEBUG编写自己的条件调试代码。如果NDEBUG未定义，将执行#ifndef和endif之间的代码，如果定义了NDEBUG，这些代码将被忽略掉

void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
    //__func__编译器定义的一个局部晶态变量，用于存放函数的名字
    cerr << __func__ << ": array size is" << size << endl;
    #endif
    //...
}
//__func__是const char 的一个静态数组，存放函数的名字。
//__FILE__存放文件名的字符串字面值
//__LINE__存放当前行号的整形字面值
//__TIME__存放文件编译时间的字符串字面值
//__DATE__存放文件编译日期的字符串字面值

//可以使用这些常量在错误消息中提供更多信息：
if (word.size() < threshold)
{
    cerr << "Error: " << __FILE__ 
        << " : in function " << __func__
        << " at line " << __LINE__ << endl
        << "		Compiled on " << __DATE__
        << " at " << __TIME__ << endl
        <<"		Word read was \"" <<word
        <<"\":Length too short" << endl;
}
//如果程序提供一个长度小于threshold的string对象，将得到错误信息
```

- 重载函数的指针

```c++
void ff(int *);
void ff(unsigned int);
void (*pf1)(unsigned int) = ff;/pf1指向ff(unisigned);
void (*pf2)(int) = ff; //错误，没有任何一个ff与该型参列表匹配
double (*pf3)(int *) = ff; //错误，ff和pf3的返回值类型不匹配
```

- 函数指针性参

```c++
bool lengthCompare(const string &, const string &);

void useBigger(const string &s1, const string &s2, 
               bool pf(const string &, const string &));
//等价声明：显式地将型参定义为指向函数的指针
void useBigger(consg string &s1, const string &s2,
               bool (*pf)(const string &, const string &));
//我们可以把函数直接当成实参使用，会自动转换成指针

//类型别名简化函数指针
//Func和Func2是函数类型
typedef bool Func(const string &, const string &);
typedef decltype(lengthCompare) Func2; //等价类型

//FuncP和FuncP2是指向函数的指针
typedef bool (*Funcp)(const string &, const string &);
typedef decltype(lengthCompare) *FuncP2; //等价类型

//userBigger重新声明
void userBigger(const string &, const string &, Func); //编译器自动将Func表示的函数类型转换成指针
void userBigger(const string &, const string &, FuncP2); //等价
```

- 返回指向函数的指针

```c++
//使用类型别名
using F = int(int *, int); //F是函数类型，不是指针
Using PF = int(*)(int *, int); //PF是指针类型
//和函数型参不一样，返回值类型不会自动地转换成指针
PF f1(int); //正确，PF是指向函数的指针，f1返回指向函数的指针
F f1(int); //错误，F是函数类型，f1不能返回一个函数
F *f1(int); //正确，显式地指定返回类型是指向函数的指针

//直接声明
int (*f1(int))(int *, int);
```

- 使用auto和decltype用于函数指针类型

```c++
string::size_type sumLength(consg string &, const string &);
string::size_type largeLength(consg string &, const string &);

//getFcn函数返回指向sumLength或者largerLength的指针
decltype(sumLength) *getFcn(const string &); //需要老及decltype作用于某个函数时，它返回函数类型而非指针类型，需要显式的加上*表明我们需要返回指针，而非函数本身。
```

## chap 7

```c++
class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

```



- 引入this

```c++
this指针是隐式定义的，this是一个常量指针(T *const this)，不能改变this保存的地址，this永远指向对象本身
```

- 引入const成员函数

```c++
在成员函数参数列表之后，紧跟在参数列表后的const表示this是一个指向常量的指针。这样使用const的成员函数被称作常量成员函数。
const T *const this;
```

- 在类外定义成员函数

```c++
类外定义成员函数，必须与它的声明匹配（返回类型、参数列表、函数名、const属性）。例如：
double Sales_data::avg_price() const
{
    if (uhnits_sokd)
    {
        return revenue/units_sold;
    }
    else
    {
        return 0;
    }
}

//Sales_data::avg_price使用作用域运算符，说明我们定义了一个名为avg_pricec的函数，并且该类被声明在类Sales_data的作用域内。
```

- 定义一个返回this对象的函数

```c++
函数combine的设计初中类似于复合运算符+=，调用该函数的对象代表的是赋值运算符左侧的运算对象，右侧运算对象通过显式的实参被传入函数：
Sales_data & Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; //把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this; //返回调用该函数的对象
}

//调用
total.combine(trans);
```

- 定义类相关的非成员函数

```c++
//定义read和print

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}
//IO类不能被拷贝，只能通过引用来传递它们
```

- 定义add函数

```c++
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; //拷贝构造
    sum.combine(rhs);
    return sum;
}
```

- 构造函数：构造函数不能被声明为const的，当我们创建类的一个const对象时，直到构造函数完成初始化过程，对象才能真正取得其“常量”属性。因此构造函数在const对象的构造过程中可以向其写值。

- 合成的默认构造函数

```c++
我们的类没有显式的定义构造函数，那么编译器就会为我们隐式地定义一个默认构造函数。
编译器创建的构造函数又被称为合成默认构造函数。
合成默认构造按照如下规则初始化类内成员：
如果存在类内的初始值，用它来初始化成员
否则，默认初始化该成员
```

- 某些类不能依赖于合成的默认构造函数

```c++
合成默认构造函数只适合非常间的的类。
三种必须定义自己默认构造函数的原因：
编译器只有在发现类不包含任何构造函数的情况下才会替我们生成一个默认构造函数。一旦定义了一些其他的构造函数，除非我们再定义一个默认的构造函数，否则此类没有默认构造函数。
对某些类来说，合成默认构造函数可能执行错误的操作。如果定义在块中的内置数据类型或复合类型（数组或指针）的对象被默认初始化，则它们的值是为定义的。
有时候编译器不能为某些类合成默认构造函数。例如，如果类中包含一个其他类类型的成员且这个类型成员没有默认构造函数，那么编译器将无法初始化该成员。
```

- 定义Sales_data的构造函数

```c++
一个istream&，从中读取一条交易信息。
一个const string &，表示ISBN编号；一个unsigned，表示售出的图书数量；以及一个double，表示图书的售出价格。
一个const string &，表示ISBN编号；编译器将赋予其它成员默认值。
一个空参数列表（即默认构造函数）。
struct Sales_data 
{
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
```

```c++
=defalut的含义
Sales_data() = default;
我们需要编译器生成一个默认构造函数，可以通过在参数列表后面写上=default来要求编译器生成默认构造函数。
=defalut既可以和声明一起出现在类的内部，也可以作为出现在类的外部。和其他函数一样，如果=defalut在类的内部，则默认是内联的；如果出现在类的外部，则默认是不内联的。
```

- 构造函数初始值列表

```c++
Sales_data(const std::string &s) : bookNo(s){ }
Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p *n){ }

//只有1个string类型参数的构造函数使用string对象初始化bookNo，对于units_sold和revenue则没有显式初始化，它将以合成默认构造函数相同的方式隐式初始化。
Sales_data(const std::string &s) : bookNo(s), units_sold(s), revenue(0){ }
```

- 在类的外部定义构造函数

```c++
Sales_data::Sales_dat(std::istream &is)
{
    read(is, *this); //read作用是从is读取一条交易信息后，存入this对象中
}
```

- Screen类的成员函数（在类内编写的成员函数默认是内联的，在类外默认不是）

```c++
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default; // needed because Screen has another constructor
                        // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c) {}
    friend class Window_mgr;
    Screen(pos ht = 0, pos wd = 0) : cursor(0), height(ht), width(wd), contents(ht * wd, ' ') {}
    char get() const // get the character at the cursor
    {
        return contents[cursor];
    }                                      // 隐式内联
    inline char get(pos ht, pos wd) const; // 显式内联
    Screen &clear(char = bkground);

private:
    static const char bkground = ' ';

public:
    Screen &move(pos r, pos c); // can be made inline later
    Screen &set(char);
    Screen &set(pos, pos, char);
    // display overloaded on whether the object is const or not
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const { os << contents; }
    pos cursor = 0;            //光标位置
    pos height = 0, width = 0; //屏幕的宽和高
    std::string contents;
};
```

- 令成员函数作内联函数：在类内声明时可以写上Inline关键字，声明成员内联函数，也可以在类外实现时加上关键字inline，使其成为内联函数，二者只有一个也是正确的

```c++
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c;    // move cursor to the column within that row
    return *this;        // return this object as an lvalue
}
char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width;      // compute row location
    return contents[row + c]; // return character at the given column
}
```

- 可变数据成员：希望在成员函数内修改类的某个数据成员，即使时一个const成员函数内。可以通过在变量声明时加入mutable关键字做到这一点

​		一个可变数据成员永远不是const，即使它是const对象的成员。

- 基于const指针的重载

```c++
class Screen
{
public:
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const 
    {
        do_display(os);
        return *this;
    }
private:
   
    void do_display(std::ostream &os) const 
    {
        os << contents; 
    }
}

//当调用do_display时，它的this指针将隐式的传递给do_display。当display的非常量版本调用do_display时，它的this指针将隐式的从指向非常量的指针，转为指向常量的指针。
```

- 友元再探：普通函数、其他类和其他类内的成员函数都可以定义成友元。友元关系不存在传递性（一个类有自己的友元，但是该类又是另一个类的友元，该类中的友元不能访问另一个类）。

- 成员函数做友元

1. 首先定义A类，其中声明函数1，但是不能定义它。在函数1中使用B类的成员之前必须先声明B类。
2. 接下来定义B类，包括对于函数1的友元声明。
3. 最后定义函数1，此时它才可以使用B类中的成员

- 友元声明和作用域

​		类和非成员函数的声明不是必须在它们的友元之前。

```c++
struct X{
    friend void f() {/*友元函数可以定义在类的内部*/}
    X(){f();} //错误，f还没有被声明
    void g();
    void h();
}
void X::g() { return f(); } //错误，f还没有被声明
void f(); //声明定义在X中的函数
void X::h() { return f(); } //正确
```

- 构造函数初始值有时必不可少

```c++
class ConstRef{
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};

ConstRef::ConstRef(int il)
{
    i = ii; //正确
    ci = ii; //错误
    ri = i; //错误
}
//构造函数开始执行，初始化已经完毕

//正确
ConstRef::ConstRef(int il) : i(ii), ci(ii), ri(i)
{}
```

- 成员初始化的顺序：构造函数初始值列表值说明用于初始化成员的值，而不限定初始化成员的具体执行顺序。初始化顺序与它们在类中定义出现的顺序一致。

- 委托构造函数，使用它所属类的其他构造函数执行它自己的初始化过程

```c++
class Sales_data{
public:
    //非委托构造函数使用对应的实参初始化成员
    Sales_data(std::string s, unsigned cnt, double price) : 
    		bookNo(s), units_sold(cnt), revenue(cnt *price){}
    //其余构造函数全部委托给另一个构造函数
    Sales_data() : Sales_dat("", 0, 0){}
    Sales_data(std::string s) : Sales_data(s, 0, 0){}
    Sales_data(std::istream &is) : Sales_dat()
    {
        read(is, *this);
    }
}

//先执行受委托的构造函数的初始值列表和函数体，再执行委托者的函数体。
```

- 隐式的类类型转换

1. 只允许一步类类型转换

```c++
class Sales_data {
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(std::istream &);
};
string null_book = "9-999-99999-9";
//构造一个临时的Sales_data对象
//该对象的units_sold和revenue等于0，bookNo等于null_book
item.combin(null_book);
item.combin("9-999-99999-9"); //错误，需要两部转换，char *->string->Sales_sold
item.combin(string("9-999-99999-9")); //正确
item.combin(Sales_data("9-999-99999-9")); //正确

item.combin(cin); //正确
隐式的将cin转换成了Sales_data类型，这个转换接受一个istream的Sales_data构造函数。通过读标准输入创建了一个临时的Sales_data对象，并将得到的对象传递给combine。
```



2. 类类型转换不是总有效

- 抑制构造函数定义的隐式类型转换

​		在要求隐式转换的程序上下文中，我们可以通过将构造函数声明为explicit加以阻止：

```c++
class Sales_data {
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
    explicit Sales_data(const std::string &s): bookNo(s) { }
	explicit Sales_data(std::istream &);
};
item.combin(null_book);// 错误，string构造函数是explicit的
item.combin(cin); //错误，istream构造函数是explicit的
//关键字explicit只对一个实参的构造函数有效。
//只能在类内声明构造函数时使用explicit关键字，类外定义不应该重复声明
explicit Sales_data(std::istream &) //错误，explicit只能出现在类内声明处
{
    read(is, *this);
}
```

- explicit构造函数只能用于直接初始化

```c++
Sales_data item1(null_book); //正确，直接初始化
Sales_data item2 = null_book; //错误，不能拷贝初始化
```

- 为转换显式的使用构造函数

```c++
item.combine(Sales_dat(null_book)); //正确
item.combine(static_cast<Sales_data>(cin));z //正确
```

- 聚合类使得用户可以直接访问其成员，条件如下：

1. 所有成员都是public的
2. 没有定义任何构造函数
3. 没有类内初始值
4. 没有基类，也没有virtual函数

```c++
//例如
struct Data{
    int ival;
    string s;
}
//可以提供一个花括号括起来的成员初始值列表，初始化聚合类的数据成员
//val1.ival = 0; val1.s = string("Anna");
Data val1 = {0, "Anna"};
//初始值顺序必须与声明一致。
//初始值列表中的元素少于类成员数量，则靠后成员被值初始化。初始列表中的元素个数决不能超过类的成员数量。
```

- 字面值常量类，和普通类不同，字面值类型的类可能含有constexpr函数成员。这样的成员必须符合constexpr函数的所有要求，它们是隐式const的。

​		数据成员都是字面值类型的聚合类是字面值常量类。如果不是聚合类符合如下要求，则它也是字面值常量类：

1. 数据成员都必须是字面值类型
2. 类必须至少包含一个constexpr构造函数
3. 如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式；或者如果成员属于某种类类型，则初始值必须使用成员自己的constexpr构造函数。
4. 类必须使用析构函数的默认定义，该成员负责销毁类的对象。

- constexpr构造函数

```c++
//构造函数不能是const的，但字面值常量类的构造函数可以是constexpr函数。
//constexpr构造函数可以声明成=default的形式。否则，constexpr构造函数就必须即符合构造函数要求(不能包含返回语句)，又符合constexpr函数的要求（拥有唯一可执行语句就是返回语句）。综合者两点可知，constexpr构造函数体一般是空的。通过前置关键字constexpr就可以声明一个constexpr构造函数了
class Debug
{
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }

private:
	bool hw;	// hardware errors other than IO errors
	bool io;	// IO errors
	bool other; // other errors
};
//constexpr构造函数必须初始化所有数据成员，初始值或者使用constexpr构造函数，或是一条常量表达式。
//constexpr构造函数用于生成constexpr对象以及constexpr函数的参数或返回类型：
constexpr Debug io_sub(false, true, ture); //调试IO
if (io_sub.any()) //等价于if(true)
    cerr << "print appropriate error messages" << endl;
constexpr Debug prod(false); //无调试
if (prod.any()) //等价于if(false)
    cerr << "print an error messages" << endl;
```

- 类的静态成员

​		类的静态成员存在于任何对象之外，对象中不包含任何与静态成员有关的数据。

```c++
class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);   
private:
    std::string owner; 
    double amount;
    static double interestRate; 
    static double initRate() { }
};
```



​		静态成员函数也不与任何对象绑定在一起，它们不包含this指针。作为结果，静态成员函数不能声明成const的，而且我们也不能再static函数体内使用this指针。这一限制既适用于this的显示调用，也对调用非静态成员的隐式调用有效。

- 使用类的静态成员

```c++
//使用作用域运算符访问静态成员
double r;
r = Account::rate(); 
//使用类的对象、引用或指针访问
Account ac1;
Account *ac2 = &ac1;
r = ac1.rate();
r = ac2->rate();

//成员函数不用通过作用域运算符就能直接使用静态成员
class Account {
public:
    void calculate() { amount += amount * interestRate; } 
private:
    static double interestRate; 
};
```

- 定义静态成员（静态成员函数可以在类内定义，也可以在类外定义，类外定义时，不能重复static关键字，类内声明出现一次就可以）

​		静态数据成员不属于任何一个对象，所以它们并不是创建类对象时被定义的。意味着它们不是由类的构造函数初始化的。一般来说，我们不能在类的内部初始化静态成员。相反的，必须在类的外部定义和初始化静态成员。

​		类似全局变量，静态数据成员定义在任何函数之外。一旦定义，存在于程序整个声明周期。

```c++
//定义和初始化一个静态成员
double Account::interestRate = initRate();
//从类名开始，这条语句剩余部分就位于类的作用域之内了。因此可以直接使用initRate()函数。
```

- 静态成员的类内初始化，可以为静态成员提供const整数类型的类内初始值，要求静态成员必须是字面值常量类型的constexpr。初始值必须是常量表达式。

```c++
class Account {
public:
    static double rate() { return interestRate; }
    static void rate(double);   
private:
    static constexpr int period = 30; 
    double daily_tbl[period];
};
```

- 静态成员能用于某些场景，而普通成员不能

```c++
//静态成员可以是不完全类型，特别的，静态数据乘员类型可以就是它所属的类型。而非静态数据成员则受到限制，只能声明引用或指针
class Bar{
public:
    //...
private:
    static Bar mem1; //正确
    Bar *mem2; //正确
    Bar mem3; //错误
}
//我们可以使用静态成员作为默认实参，而非静态成员不行，因为他的值本身属于对象的一部分，这么做会导致无法真正提供一个对象以便从中获取成员的值，最重将导致错误。
class Screen{
public:
    //bkground表示一个在类中稍后定义的静态成员
    screen& clear(char = bkground);
private:
    static const char bkground;
}
```

# chap 8

- IO类

```c++
iostream 		istream，wistream
    			ostream，wostream
    			iostream，wiostream
fstream			ifstream，wifstream
    			ofstream，wofstream
    			fstream，wfstream
sstream 		istringstream，wistringstream
    			ostringstream，wostringstream
    			stringstream，wstringstream
//wcin、wcout和wcerr对应cin、cout和cerr的宽字符版本。
```

- IO对象无拷贝或赋值

```c++
ofstream out1, out2;
out1 = out2; //错误
ofstream print(ofstream); //错误
out2 = print(out2); //错误
```

- 条件状态

![2022-07-13 14-50-22 的屏幕截图](/home/cccmmf/cppstudy/C++primer/2022-07-13 14-50-22 的屏幕截图.png)

- 管理条件状态

```c++
//记住cin的当前状态
auto old_state = cin.rdstate(); //记住cin的当强状态
cin.clear(); //使cin有效
process_input(cin); //使用cin
cin.setstate(old_state); //将cin置为原有状态

//下面代码将failbit和badbit复位，但保持eofbit不便
cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit)
```

- 管理输出缓冲

```c++
在每个输出操作后，可以用操纵父unibuf设置流的内部状态，来清空缓冲区。默认情况下，cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新。
一个输出流可能被关联到另一个流。当读写都被关联的流时，关联到的流缓冲区会被刷新。默认情况，cin和cerr都关联到cout。因此，读cin或写cerr都会导致cout的缓冲区刷新
```

- 刷新输出缓冲区：flush、ends和endl

```c++
cout << "hi!" << endl; //输出hi！和换行，然后刷新缓冲区
cout << "hi!" << flush; //输出hi!，然后刷新缓冲区
cout << "hi!" << ends; //输出hi和一个空字符，然后刷新缓冲区
```

- unibuf操纵符：使用unibuf操纵符，告诉流每次写操作后都进行一次flush操作。nounitbuf操作符则重置流，使其恢复使用正常的系统管理的缓冲区刷新机制

```c++
cout << unitbuf; //所有输出操作都会立即刷新缓冲区
cout << nounitbuf; //回到正常的缓冲方式
//注：如果程序崩溃，输出缓冲区不会被刷新。
```

- 关联输入和输出流：当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新关联的输出流。标准库将cout和cin关联在一起。

```c++
cin >> ival; //导致cout的缓冲区被刷新
```

```c++
//tie有两个版本。一个不带参数，返回指向输出流的指针。如果本对象关联到一个输出流，则返回的就是指向这个流的指针，如果对象未关联到流，则返回空指针。tie第二个版本接收一个ostream的指针，将自己关联到此ostream。即x.tie(&o)将流x关联到输出流G

cin.tie(&cout); //仅仅用来展示：标库将cin和cout关联在一起
//old_tie指向当前关联到cin的流（如果有的话）
ostream *old_tie = cin.tie(nullptr); //cin不再于其他流关联
cin.tie(&cerr); //将cin与cerr关联，读取cin会刷新cerr
cin.tie(&old_tie); //重建cin与cout间的正常关联
```

- 文件输入输出：ifstream从一个给定文件读取数据，ofstream向一个给定文件写入数据，fstream可以读写给定文件。

![2022-07-13 15-18-23 的屏幕截图](/home/cccmmf/cppstudy/C++primer/2022-07-13 15-18-23 的屏幕截图.png)

- 使用文件流对象

```c++
ifstream in(ifile); //构造一个ifstream并打开给定文件
ofstream out; //输出文件流并未关联到任何文件
```

- 用fstream代替iostream&：fstream是从iostream继承过来的，接收iostream类型的引用（或指针）参数的函数可以用对应的fstream（或sstream）类型调用。

```c++
ifstream input(argv[1]); //打开销售记录文件
ofstream output(argv[2]); //打开输出文件
Sales_data total; //保存销售总额的变量
if (read（input, total)) //读取第一条销售记录
{
    Sales_data trans; //保存下一条销售记录的变量
    while (read(input, trans)) //读取剩余记录
    {
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans); //更新销售总额
        }
        else
        {
            print(output, total) << endl; //打印结果
            total = trans; //处理下一本书
        }
    }
    print(output, total) << endl; //打印最后一本书的销售额
}
else //文件中无输入数据
{
    cerr << "No data?!" << endl;
}
//read和print型参虽然是istream&和ostream&，但我们可以传递fstream对象
```

- 成员函数open和close

```c++
ifstream in(ifile); //构筑一个ifstream并打开给定文件
ofstream out; //输出文件流未与任何文件相关联
out.open(iflie + ".copy"); //打开指定文件
//如果open失败，failbit会被置位。
if (out); //检查open是否成功。open成功，可以使用文件了。
//对一个已打开的文件调用oepn会失败，并会导致failbit被置位。随后试图使用文件流的操作都会失败。为了将文件流关联另一文件，需要先关闭已关联的文件
in.close(); //关闭文件
in.open(ifile + "2"); //打开另一个文件。
//open成功，会使good()为true
```

- 文件模式

![2022-07-13 15-35-59 的屏幕截图](/home/cccmmf/cppstudy/C++primer/2022-07-13 15-35-59 的屏幕截图.png)

1. ifstream或fstream只能in
2. ofstream或fstream只能out
3. 只有当out被设定时才可以设定trunc
4. 只要trunc没被设定，就可以设定app模式。app模式下，没有显式指定out，文件也总以输出方式打开
5. 默认情况下，即使没设定trunc，以out打开也会截断文件。若要保留out模式打开文件的内容，必须同时指定app，只能在文件尾部添加内容；或者同时指定in模式，即打开文件同时进行读写操作。
6. ate和binary模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用

​		每个文件流都有默认模式，ifstream默认in，ofstream默认out，fstream默认in和out

- 以out模式打开文件会丢弃已有数据

```c++
//file1被截断
ofstream out("file1"); //隐含输出加截断
ofstream out2("file1", ofstream::out); //隐含的截断文件
ofstream out3("file1", ofstream::out | ofstream::trunc);
//保留文件内容，显式指定app模式
ofstream app("file2", ofstream::app); //隐含为输出模式
ofstream app2("file2", ofstream::out | ofstream::app);
```

- 每次调用open时都会确定文件模式

```c++
ofstream out;
out.open("scratchpad"); //隐含输出和截断
out.close(); //关闭
out.open("precious", ofstream::app); //输出和追加
out.close();
```

