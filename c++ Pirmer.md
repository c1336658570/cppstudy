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

