/*
    继承中的对象模型
*/

#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C; //私有成员知识被隐藏了，但是还是会继承下去
};

//公共继承
class Son : public Base
{
public:
    int m_D;
};

//利用开发人员命令提示工具查看对象模型
//cl /d1 reportSingleClassLayout类名 文件名
//cl /d1 reportSingleClassLayoutSon  "03继承中的对象模型.cpp"

void test01()
{
    //16
    //父类中所有非静态成员属性都会被子类继承下去
    //父类中私有成员属性是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
    cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main(void)
{
    test01();

    return 0;
}