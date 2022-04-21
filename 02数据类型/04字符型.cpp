# include <iostream>
using namespace std;

int main(void)
{
    char ch = 'a';
    cout << "ch = " << ch;
    cout << "字符型变量所占内存：" << sizeof(char) << endl;

    //常见错误
    //char ch2 = "b";
    //char ch2 = "abcdef";

    cout << "字符型的ASCII" << (int)ch << endl;

    return 0;
}