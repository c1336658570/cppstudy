#  include <iostream>
using namespace std;

int main(void)
{
    //默认情况下输出小时只显示6位有效数字
    float f1 = 3.1415926f;
    cout << "f1 = " << f1 << endl;

    double d1 = 3.1415926;

    cout << "d1 = " << d1 << endl;

    cout << "float占用的内存空间为：" << sizeof(float) << endl;
    cout << "double占用的内存空间为：" << sizeof(double) << endl;

    //科学计数法
    float f2 = 3e2;
    cout << "f2 = " << f2 << endl;

    float f3 = 3e-2;
    cout << "f3 = " << f3 << endl;

    return 0;
}