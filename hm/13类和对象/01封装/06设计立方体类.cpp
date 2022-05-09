#include <iostream>
using namespace std;

/*
设计立方体类
    求面积体积
    判断俩立方体面积和体积是否相等
*/

class Cube
{
private:
    int m_L; //长
    int m_W; //宽
    int m_H; //高

public:
    //设置长
    void setL(int length)
    {
        m_L = length;
    }

    //获取长
    int getL()
    {
        return m_L;
    }

    //设置宽
    void setW(int width)
    {
        m_W = width;
    }

    //获取宽
    int getW()
    {
        return m_W;
    }
    //设置高
    void setH(int high)
    {
        m_H = high;
    }
    //获取高
    int getH()
    {
        return m_H;
    }
    //获取立方体面积
    int calculateS()
    {
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
    }
    //获取立方体体积
    int calculateV()
    {
        return m_H * m_L * m_W;
    }

    //利用成员函数判断两个立方体是否相等
    bool isSame(Cube &c)
    {
        if (m_L == c.getL() && getW() == c.getW() && m_H == c.getH())
            return true;
        else
            return false;
    }
};

//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
        return true;
    else
        return false;
}

int main(void)
{
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);

    cout << "c1的面积为" << c1.calculateS() << endl;
    cout << "c1的体积为" << c1.calculateV() << endl;

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);

    //利用全局函数
    bool ret = isSame(c1, c2);
    if (ret)
    {
        cout << "全局函数判断结果：c1和c2是相等的" << endl;
    }
    else
    {
        cout << "全局函数判断结果：c1和c2是不相等的" << endl;
    }
    //利用成员函数
    ret = c1.isSame(c2);
    if (ret)
    {
        cout << "成员函数判断结果：c1和c2是相等的" << endl;
    }
    else
    {
        cout << "成员函数判断结果：c1和c2是不相等的" << endl;
    }

    return 0;
}