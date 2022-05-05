/*
    引用：给变量起别名
    语法：数据类型 &别名 = 原名
    int &b = a;
*/

#include <iostream>
using namespace std;

int main(void)
{
    //引用基本用法
    //数据类型 &别名 = 原名

    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}