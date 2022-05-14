/*
    赋值运算符重载
    创建一个类，c++编译器会给每个类添加至少4个函数
        默认构造（空实现）
        析构函数（空实现）
        拷贝构造 （值拷贝）
        赋值运算符operator=，对属性进行值拷贝
*/

#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    //重载 赋值运算符
    Person &operator=(Person &p)
    {
        //编译器提供的是浅拷贝
        // m_Age = p.m_Age;

        //先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        //深拷贝操作
        m_Age = new int(*p.m_Age);

        return *this;
    }

    int *m_Age = NULL;
};

void test01()
{
    Person p1(18);

    Person p2(20);

    Person p3(30);

    p3 = p2 = p1; //赋值操作

    cout << "p1的年龄为:" << *p1.m_Age << endl;
    cout << "p2的年龄为:" << *p2.m_Age << endl;
    cout << "p3的年龄为:" << *p3.m_Age << endl;
}

int main(void)
{
    test01();

    int a = 10;
    int b = 20;
    int c = 30;

    a = b = c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}