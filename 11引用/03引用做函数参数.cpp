#include <iostream>
using namespace std;

//交换两个数

// 1.值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    /*
    cout << "swap01a = " << a << endl;
    cout << "swap01b = " << b << endl;
    */
}

// 2.地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3.引用传递
void mySWap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;

    /*
    mySwap01(a, b);
    cout << "swap01a = " << a << endl;
    cout << "swap01b = " << b << endl;
    */

    /*
    mySwap02(&a, &b);
    cout << "swap02a = " << a << endl;
    cout << "swapo2b = " << b << endl;
    */

    mySWap03(a, b); // 引用传递，形参会修饰实参
    cout << "swap03a = " << a << endl;
    cout << "swapo3b = " << b << endl;

    return 0;
}