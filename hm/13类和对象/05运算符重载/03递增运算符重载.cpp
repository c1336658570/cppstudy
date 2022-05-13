/*
    递增运算符重载
*/

#include <iostream>
using namespace std;

//自定义类型
class MyInteger
{
    friend ostream &operator <<(ostream &cout, MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }

    //重载前置++运算符 返回引用，为了一直对一个数据进行操作
    MyInteger &operator++ ()
    {
        //先进行++
        m_Num++;

        //再把自身返回
        return *this;
    }

    //重载后置++运算符
    //void operator++ (int) int代表占位参数，可以用于区分前置和后置递增
    MyInteger operator++ (int)
    {
        //先记录当时结果结果
        MyInteger temp = *this;

        //后递增
        m_Num++;
        
        //最后将我们记录的结果再返回
        return temp;
    }

private:
    int m_Num;
};

//重载<<运算符
ostream &operator <<(ostream &cout, MyInteger myint)
{
    cout << myint.m_Num;

    return cout;
}

void test01()
{
    MyInteger myint;

    cout << "前置递增：" << endl;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

void test02()
{
    MyInteger myint;
    cout << "后置递增：" << endl;
    cout << myint++ << endl;
    cout << myint << endl;
}

int main(void)
{
    test01();
    
    test02();

    return 0;
}