#include <iostream>
using namespace std;

class Person1
{
public:
    //传统初始化操作
    Person1(int a, int b, int c)
    {
        m_A = a;
        m_B = b;
        m_C = c;
    }

    int m_A;
    int m_B;
    int m_C;
};

class Person2
{
public:
    //传统初始化操作
    /*Person(int a, int b, int c)
    {
        m_A = a;
        m_B = b;
        m_C = c;
    }*/

    //初始化列表初始化属性
    Person2(int a, int b, int c) : m_A(a), m_B(b), m_C(c)
    {
    }
    // Person2() : m_A(10), m_B(20), m_C(30)
    // {
    // }

    int m_A;
    int m_B;
    int m_C;
};

void test01()
{
    Person1 p(10, 20, 30);
    cout << "m_A = " << p.m_A << endl;
    cout << "m_B = " << p.m_B << endl;
    cout << "m_C = " << p.m_C << endl;

    // person2 p2;
    Person2 p2(30, 20, 10);
    cout << "m_A = " << p2.m_A << endl;
    cout << "m_B = " << p2.m_B << endl;
    cout << "m_C = " << p2.m_C << endl;
}

int main(void)
{
    test01();

    return 0;
}