#include <iostream>
using namespace std;
/*
函数重载
    函数名可以相同，提高复用性
条件
    同一个作用于
    函数名相同
    函数参数类型或者个数不同或者顺序不同
函数的返回值不能做为函数重载的条件（函数的返回值可以是int或者void，我们不接收返回值，int和void作用相同）
*/

//全局作用域
void func()
{
    cout << "func 的调用" << endl;
}

void func(int a)
{
    cout << "func(int a) 的调用" << endl;
}

void func(double a)
{
    cout << "func(double a) 的调用" << endl;
}

void func(int a, double b)
{
    cout << "func(int a, double b) 的调用" << endl;
}

void func(double a, int b)
{
    cout << "func(double a, int b) 的调用" << endl;
}

int main(void)
{
    func();
    func(10);
    func(3.14);
    func(3, 3.14);
    func(3.14, 3);

    return 0;
}