/*
    静态成员就是在成员变量或成员函数前加static关键字
    静态成员变量
        所有对象共享同一份数据
        在编译阶段分配内存
        类内声明，类外初始化
    静态成员函数
        所有对象共享同一个函数
        静态成员函数只能访问静态成员变量
*/

#include <iostream>
using namespace std;

class Person
{
public:
    static void func()
    {
        m_A = 100; //静态成员函数可以访问 静态成员变量
        // m_B = 200; //静态成员函数不可以访问 非静态成员变量，所有对象共享func，func无法区分修改是哪个对象的m_B
        cout << "static void func调用" << endl;
    }

    static int m_A; //静态成员变量
    int m_B;

    //静态成员函数也是有访问权限的
private:
    static void func2()
    {
        cout << "static void func2调用" << endl;
    }
};

int Person::m_A = 0;

void test01()
{
    // 1、通过对象访问
    Person p;
    p.func();

    // 2、通过类名访问
    Person::func();

    //Person::func2(); // 类外不能访问
}

int main(void)
{
    test01();

    return 0;
}