/*
    成员函数如何区分是哪个对象调用自己呢？
    通过this指针，this指针指向被调用的成员函数所属的对象

    this指针是隐含每一个非静态成员函数内的一种指针
    this指针不需要定义，直接使用即可

    this指针的用途：
        当形参和成员变量同名时，可用this指针来区分
        在类的非静态成员函数中返回对象本身，可使用return *this
*/

#include <iostream>
using namespace std;

class Person
{
    public:
    Person(int age)
    {
        //this指针指向被调用的成员函数所属的对象
        this->age = age;
    }

    void PersonAddAge(Person &p)
    {
        this->age += p.age;
    }

    //返回对象本身用*this
    Person &PersonAddAge2(Person &p)
    {
        this->age += p.age;
        return *this;
    }

    int age;
};
//1、解决名称冲突
void test01()
{
    Person p1(18);
    cout << "p1的年龄为：" << p1.age << endl;
}

//2、返回对象本身用*this
void test02()
{
    Person p1(10);

    Person p2(10);
    
    p2.PersonAddAge(p1);

    cout << "p2的年龄为：" << p2.age << endl;
    
    //链式编程思想
    p2.PersonAddAge2(p1).PersonAddAge2(p1).PersonAddAge2(p1).PersonAddAge2(p1);

    cout << "p2的年龄为：" << p2.age << endl;
}

int main(void)
{
    test01();

    test02();

    return 0;
}