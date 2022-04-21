#include <iostream>
using namespace std;

const double PI = 3.14;
//设计一个圆类，求圆的周长

// class 代表设计一个类，类后面紧跟着的就是类的名称
class Circle
{
    //访问权限
    //公共权限
public:
    //属性
    //半径
    int m_r;

    //行为
    double calculateZC()
    {
        return 2 * PI * m_r;
    }
};

int main(void)
{
    //类的实例化
    Circle c1;
    c1.m_r = 10;

    cout << "圆的周长为：" << c1.calculateZC() << endl;

    return 0;
}