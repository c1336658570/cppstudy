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

    void visit(); //参观函数 访问Building中的属性

    Building *building;
};

class Building
{
    //GoodGay是本类的好朋友可以访问本类私有的成员
    friend class GoodGay;

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
    cout << "好基友类正在访问：" << building->m_SittingRoom << endl;

    cout << "好基友类正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
}

int main(void)
{
    test01();

    return 0;
}