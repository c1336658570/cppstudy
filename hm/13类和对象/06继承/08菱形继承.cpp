/*
    菱形继承
    两个派生类继承同一个基类
    又有某个类同时继承两个派生类
    这种继承称为菱形继承，或者钻石继承
*/

#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
    int m_Age;
};

//羊类
class Sheep : virtual public Animal
{
};

//驼类
class Tuo : virtual public Animal
{
};

//利用虚继承 解决菱形继承的问题
//继承之前加上关键字virtual变为虚继承
//Animal类称为虚基类
//本质  继承了Sheep和Tuo的虚基类指针(vbptr   virtual base pointer)，
//该指针指向一个虚基类表(vbtable)，通过虚基类表和偏移量，能找到唯一的m_Age;
//羊驼类
class SheepTuo : public Sheep, public Tuo
{
};

void test01()
{
    SheepTuo st;

    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    //当菱形继承，两个父类拥有相同的数据，需要加以作用域区分
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;

    //这份数据我们知道只要有一份就可以，菱形继承导致数据有两份，资源浪费

}

int main(void)
{
    test01();

    return 0;
}