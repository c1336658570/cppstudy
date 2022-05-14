/*
    函数调用运算符重载
    函数调用运算符()也可以重载
    由于重载后使用的方式非常像函数的调用，因此称为仿函数
    仿函数没有固定写法，非常灵活
*/

#include <iostream>
#include <string>
using namespace std;

class MyPrint
{
public:

    //重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void MyPrint02(string test)
{
    cout << test << endl;
}

void test01()
{
    MyPrint myprint;

    myprint("hello world"); //由于使用起来非常类似函数调用，因此成为仿函数

    MyPrint02("hello world");
}

//仿函数非常灵活，没有固定的写法
//加法类
class MyAdd
{
    public:

    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test02()
{
    MyAdd myadd = MyAdd();
    int ret = myadd(100, 100);
    cout << "ret = " << ret << endl;

    //匿名函数对象
    cout << MyAdd()(100, 100) << endl;
}

int main(void)
{
    test01();

    test02();

    return 0;
}