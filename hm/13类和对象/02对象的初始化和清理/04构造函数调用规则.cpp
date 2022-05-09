#include <iostream>
using namespace std;

//构造函数调用规则
// 1.创建一个类，c++编译器会给每个类添加至少3个函数
//默认构造（空实现）
//析构函数（空实现）
//拷贝构造 （值拷贝）

// 2.如果我们写了有参构造,编译器就不会提供默认构造,依然提供拷贝构造
// 3.如果我们写了拷贝构造函数,编译器就不提供其他构造函数

class Person
{
public:
    Person()
    {
        cout << "Person默认构造函数调用" << endl;
    }

    Person(int age)
    {
        m_Age = age;

        cout << "Person有参构造函数调用" << endl;
    }

    Person(const Person &p)
    {
        m_Age = p.m_Age;

        cout << "Person拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }

    int m_Age;
};

class Person2
{
public:
    // Person2()
    // {
    //     cout << "Person默认构造函数调用" << endl;
    // }

    Person2(int age)
    {
        m_Age = age;

        cout << "Person有参构造函数调用" << endl;
    }

    Person2(const Person2 &p)
    {
        m_Age = p.m_Age;

        cout << "Person拷贝构造函数调用" << endl;
    }

    ~Person2()
    {
        cout << "Person析构函数调用" << endl;
    }

    int m_Age;
};

void test01()
{
    Person p;
    p.m_Age = 18;
    Person p2(p);

    cout << "p2的年龄为：" << p2.m_Age << endl;
}

// 2.如果我们写了有参构造,编译器就不会提供默认构造,依然提供拷贝构造
void test02()
{
    // Person2 p; //报错,没有默认构造函数
    Person2 p1(28);
    Person2 p2(p1);

    cout << "p2的年龄为:" << p2.m_Age << endl;
}

// 3.如果我们写了拷贝构造函数,编译器就不提供其他构造函数
void test03()
{
    // Person2 p;      //报错,没有默认构造函数
    // Person2 p1(28); //报错,没有有参构造函数
}

int main(void)
{
    // test01();
    // cout << endl;

    test02();
    cout << endl;

    return 0;
}