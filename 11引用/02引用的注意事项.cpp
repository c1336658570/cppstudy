/*
    引用必须初始化
    int &b; 错误用法

    引用初始化后就不能改变了
    
*/

# include <iostream>
using namespace std;

int main(void)
{
    //1.引用必须初始化
    int a = 10;
    //int &b;  必须初始化
    int &b = a;

    //2.引用初始化后就不能改变了
    int c = 20;

    b = c; //赋值操作，而不是更改引用

    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;
    cout << "c = " << c <<endl;
}