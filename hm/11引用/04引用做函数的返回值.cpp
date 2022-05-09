#include <iostream>
using namespace std;

// 1.不要返回局部变量的引用
int &test01()
{

    int a = 10;
    return a; //错误
}

int &test02()
{

    static int a = 10;
    return a;
}

int main(void)
{

    // int &ref = test01();

    // cout << 'ref = ' << ref << endl;

    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    // 2.函数的调用可以做左值
    test02() = 1000; //如果函数的返回值是一个引用，那么这个函数调用可以作为左值

    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    ref2 = 50;

    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    return 0;
}