# include <iostream>
using namespace std;

int main(void)
{
    int a1 = 10;
    int b1 = 3;
    cout << a1 % b1 << endl;

    int a2 = 10;
    int b2 = 20;
    cout << a2 % b2 << endl;

    int a3 = 10;
    int b3 = 0;
    //两个数相除除数不为0，不能取模
    //cout << a3 % b3 << endl;

    double d1 = 3.14;
    double d2 = 1.1;
    //俩小数不能取模
    //cout << d1 % d2 << endl;

    return 0;
}