/*
    常函数：
        成员函数后加const后我们称这个函数为常函数
        常函数内不可修改成员属性
        成员属性声明时加关键字mutable后，在常函数中依然可以修改

    常对象：
        声明对象前加const称该对象为常函数
        常对象只能调用常函数
*/

#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
    }
    // this指针的本质 是指针常量 指针的指向是不可以修改的
    // Person *const this;
    //在成员函数后面加const,修饰的是this指针，让指针指向的值也不能修改 const Person *const this
    void showPerson() const
    {
        this->m_B = 100;
        // this->m_A = 100;
        // this = NULL; //this指针不可以修改，指针的指向不能变
    }

    void func()
    {
        m_A = 100;
    }

    int m_A;
    mutable int m_B; //特殊变量，即使在常函数中，也可以修改这个值,加关键字mutable
};

void test01()
{
    Person p;
    p.showPerson();
}

void test02()
{
    const Person p; //在对象前加const，变为常对象
    // p.m_A = 100;
    p.m_B = 100; // m_B是特殊值，在常对象下也可以修改

    //常对象只能调用常函数
    p.showPerson();
    // p.func(); //常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main(void)
{
    return 0;
}