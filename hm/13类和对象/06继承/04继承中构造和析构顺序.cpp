/*
    子类继承父类后，当创建子类对象，也会调用父类的构造函数
    父类和子类的构造和析构顺序谁先谁后？
*/

#include <iostream>
using namespace std;

class Base
{
    public:
    Base()
    {
        cout << "Base构造函数！" << endl;
    }
    ~Base()
    {
        cout << "Base析构函数！" << endl;
    }
};

class Son : public Base
{
    public:
    Son()
    {
        cout << "Son构造函数！" << endl;
    }
    ~Son()
    {
        cout << "Son析构函数！" << endl;
    }
};

void test01()
{
    //Base b;

    //先创建父类，在创建子类
    //先创建子类，在创建父类
    Son s;
}

int main(void)
{
    test01();

    return 0;
}