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

