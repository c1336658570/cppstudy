#include <iostream>
using namespace std;

//函数重载的注意事项
// 1.引用作为重载的条件

//变量调用这个
void func(int &a) // int &a = 10; 不合法（不加const引用必须指向一段合法的内存空间）
{
    cout << "func(int &a) 调用" << endl;
}

//常量调用这个
void func(const int &a) // const int &a = 10; 合法等价于int temp = 10; const int &a = temp;
{
    cout << "func(const int &a) 调用" << endl;
}

// 2.函数重载碰到默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a, int b = 10) 的调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a) 的调用" << endl;
}

int main(void)
{
    int a = 10;
    func(a);

    func(10);

    // func2(10); //当函数重载出现默认参数，出现二义性，报错，尽量避免这种情况
    func2(10, 20); //传两个参数可以，传一个参数不行

    return 0;
}