# include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int *p;

    p = &a;
    cout << "a的地址为：" << &a << endl;
    cout << "a的地址为：" << p << endl;

    *p = 1000;
    cout << "*p = " << *p << endl;
    cout << "a = " << a << endl;

    return 0;
}