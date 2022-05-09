#include <iostream>
using namespace std;
#include "circle.h"
#include "point.h"

void isInCircle(Circle &c, Point &p)
{
    //计算两点之间距离的平方
    int distance =
        (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

    //计算半径的平方
    int rDistance = c.getR() * c.getR();

    //判断关系
    if (distance == rDistance)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance > rDistance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}

int main(void)
{
    //创建圆
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);

    //创建点
    Point p;
    p.setX(10);
    p.setY(11);

    //判断点到圆的关系
    isInCircle(c, p);

    return 0;
}