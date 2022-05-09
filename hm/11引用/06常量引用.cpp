#include <iostream>
using namespace std;

//打印数据
void showValue(int &val)
{
    cout << "val = " << val << endl;
    val = 1000;
    cout << "val = " << val << endl;
}

void showValue2(const int &val)
{
    cout << "val = " << val << endl;
    // val = 1000; 错误val的值不能更改
    cout << "val = " << val << endl;
}

int main(void)
{
    //常量引用
    //使用场景：用来修饰形参，防止误操作

    // int a = 10;
    // int &ref = 10; //引用必须引用一块合法的内存空间
    //加上const之后 编译器将代码修改为 int temp = 10; const int & ref = temp;
    const int &ref = 10;
    // ref = 20; 加入const之后变为只读不可修改
    cout << "ref = " << ref << endl;

    int a = 100;
    showValue(a);
    cout << "a = " << a << endl;
    showValue2(a);

    return 0;
}