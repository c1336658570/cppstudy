#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
        cout << "Person的有参构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height; //身高
};

void test01()
{
    Person p1(18, 160);
    cout << "p1的年龄为：" << p1.m_Age << endl;

    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_Age << endl;
}

int main(void)
{
    test01();

    return 0;
}