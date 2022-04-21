#include <iostream>

using namespace std;

class C1
{
    int m_A; //默认权限私有
};

struct C2
{
    int m_A; //默认权限公共
};

int main(void)
{
    // struct和class区别
    // struct 默认权限是公共 public
    // class 默认权限是私有 private

    C1 c1;
    // c1.m_A;错误，c1.m.A权限默认为私有

    C2 c2;
    c2.m_A;

    return 0;
}