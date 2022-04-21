#include <iostream>
using namespace std;

//占位参数
//返回值类型 函数名(数据类型){}
//目前阶段的占位参数用不到
//占位参数 还可以有默认参数
void func(int a, int)
{
    cout << "this is func" << endl;
}

//占位参数有默认值
void func2(int a, int = 10)
{
    cout << "this is func" << endl;
}

int main(void)
{
    // func(10);  错误
    func(10, 10); //必须这样

    //两种均可
    func2(10);
    func2(10, 20);

    return 0;
}