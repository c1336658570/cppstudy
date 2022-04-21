# include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a : b);

    cout << "c = " << c << endl;

    //在c++中三目运算符结果返回的是变量，可以继续赋值
    (a > b ? a : b) = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}