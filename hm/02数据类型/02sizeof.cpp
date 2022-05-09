# include <iostream>
using namespace std;

int main(void)
{
    //利用sizeof求数据类型所占字节

    short num1 = 10;
    cout << "short占用内存空间为：" << sizeof(short) << endl;
    cout << "short占用内存空间为：" << sizeof(num1) << endl;

    int num2 = 10;
    cout << "int占用内存空间为：" << sizeof(int) << endl;
    cout << "int占用内存空间为：" << sizeof(num2) << endl;

    long num3 = 10;
    cout << "long占用内存空间为：" << sizeof(long) << endl;
    cout << "long占用内存空间为：" << sizeof(num3) << endl;

    long num4 = 10;
    cout << "long long占用内存空间为：" << sizeof(long long) << endl;
    cout << "long long占用内存空间为：" << sizeof(num4) << endl;

    return 0;
}