/*
    重载关系运算符，可以让两个自定义类型进行比较
*/

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    bool operator==(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
            return true;
        else
            return false;
    }

    bool operator!=(Person &p)
    {
        if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
            return true;
        else
            return false;
    }
    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("Tom", 18);

    Person p2("Tom", 18);

    if (p1 == p2)
    {
        cout << "p1 和 p2 是相等的！" << endl;
    }
    else
    {
        cout << "p1 和 p2 是不相等的！" << endl;
    }

    if (p1 != p2)
    {
        cout << "p1 和 p2 是不相等的！" << endl;
    }
    else
    {
        cout << "p1 和 p2 是相等的！" << endl;
    }
}

int main(void)
{
    test01();

    return 0;
}