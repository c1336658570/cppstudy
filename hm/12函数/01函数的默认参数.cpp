#include <iostream>
using namespace std;

//函数的默认参数
//如果自己传入数据，使用传入数据，如果没有，就使用默认值
int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

// 1.注意事项
// 1.如果某个位置已经有了默认参数，那么从这个位置开始往后，都必须有默认参数

/*
int func2(int a = 20, int b, int c)
{
    return a + b + c;
}
*/

// 2.如果函数声明有默认参数，函数实现就不能有默认参数（声明和实现只能有一个有默认参数）
int func2(int a = 10, int b = 10);

// int func2(int a = 10, int b = 10)  错误
int func2(int a, int b)
{
    return a + b;
}

int main(void)
{
    cout << func(10, 20, 30) << endl;

    cout << func(10) << endl;
    cout << func(10, 30) << endl;

    return 0;
}