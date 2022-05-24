/*
string字符存取

string中单个字符存取方式有两种
char& operator[](int n);      //通过[]方式取字符
char& at(int n);                       //通过at方法获取字符

总结：string字符串中单个字符存取有两种方式，利用 [ ] 或 at
*/

#include <iostream>
#include <string>
using namespace std;

void test01()
{
    string str = "hello world";

    //通过[]访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    //通过 at方式访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    //字符修改
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;
}

int main()
{
    test01();

    return 0;
}