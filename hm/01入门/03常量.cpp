# include <iostream>
using namespace std;

/*
1.#define 宏常量
2.const修饰变量
*/

# define DAY 7

int main(void)
{
    cout << "一周总共有：" << DAY << "天" << endl;

    const int month = 12;
    cout << "一年总共有：" << month << "月" << endl;

    return 0;
}