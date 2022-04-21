#include <iostream>
using namespace std;

//对象的初始化和清理
// 1.构造函数 进行初始化
class Person
{
public:
    // 1.构造函数
    // 没有返回值，不写void
    // 函数名与类名相同
    // 构造函数可以有参数，可以法生重载
    // 创建对象的时候，构造函数会自动调用，而且只调用一次
    Person()
    {
        cout << "Person构造函数的调用" << endl;
    }

    // 2.析构函数 进行清理的操作
    //没有返回值，不写oid
    //函数名与类名相同 在名称前加~
    //析构函数不可以有参数，不可以发生重载
    //对象在销毁前会自动调用析构函数，而且只会调用一次

    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }
};
//构造函数和析构函数必须实现，如果我们自己不实现，编译器会提供一个空实现的构造函数和析构函数

void test01()
{
    Person p; //在栈上的数据，test01执行完会自动释放
}

int main(void)
{
    test01();

    Person p;

    return 0;
}