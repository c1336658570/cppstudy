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

//建筑物类
class Building
{

    //GoodGay全局函数是building的好朋友，可以访问building中私有成员
    friend void GoodGay(Building *Building); 

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom; //客厅

private:
    string m_BedRoom; //卧室
};

//全局函数
void GoodGay(Building *Building)
{
    cout << "好基友全局函数正在访问：" << Building->m_SittingRoom << endl;

    cout << "好基友全局函数正在访问：" << Building->m_BedRoom << endl;
}

void test01()
{
    Building building;
    GoodGay(&building);
}

int main(void)
{
    test01();

    return 0;
}