/*
    友元就是让一个函数或者类访问另一个类中私有成员
    友元的关键字为 friend

    有元的三种实现
        全局函数做友元
        类做友元
        成员函数做友元
*/

#include <iostream>
#include <string>
using namespace std;

class Building;

class GoodGay
{
public:
    GoodGay();

    void visit(); //让visit函数可以访问Building中私有成员
    void visit2(); //让visit2函数不可以访问Building中私有成员

    Building *building;
};

class Building
{
    //告诉编译器 GoodGay类下的visit成员函数作为本类的好朋友，可以访问私有成员
    friend void GoodGay::visit();

public:
    Building();

public:
    string m_SittingRoom; //客厅

private:
    string m_BedRoom; //卧室
};

//在类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "visit正在访问：" << building->m_SittingRoom << endl;

    cout << "visit正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
    cout << "visit2正在访问：" << building->m_SittingRoom << endl;
    
    //cout << "visit2正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay gg;

    gg.visit();
    gg.visit2();
}

int main(void)
{
    test01();

    return 0;
}