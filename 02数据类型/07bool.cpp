# include <iostream>
using namespace std;

int main(void)
{
    bool flag = true;
    cout << flag << endl;

    flag = false;
    cout << flag << endl;

    cout << "布尔类型所占内存空间：" << sizeof(bool) << endl;

    return 0;
}