/*
    递减运算符重载
*/

#include <iostream>
using namespace std;

class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger()
    {
        m_A = 0;
    }

    //前自减运算符重载
    MyInteger &operator--()
    {
        m_A--;

        return *this;
    }
    
    //后自减运算符重载
    MyInteger operator--(int)
    {
        MyInteger temp(*this);

        m_A--;

        return temp;
    }

private:
    int m_A;
};

ostream &operator<<(ostream &cout, MyInteger myint)
{
    cout << myint.m_A;

    return cout;
}

void test01()
{
    MyInteger myint;
    cout << "前自减运算符" << endl;
    cout << --(--myint) << endl;
    cout << myint << endl;
}

void test02()
{
    MyInteger myint;
    cout << "后自减运算符" << endl;
    cout << myint-- << endl;
    cout << myint << endl;
}

int main(void)
{
    test01();

    test02();

    return 0;
}