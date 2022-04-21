#include <iostream>
using namespace std;

// 构造函数的分类及调用
// 1.有参构造 无参构造（默认构造）
// 2.按照类型 普通构造函数 拷贝构造函数

class Person
{
public:
    //无参
    Person()
    {
        //构造函数
        cout << "Person无参普通构造函数的调用" << endl;
    }

    //有参
    Person(int a)
    {
        age = a;
        //构造函数
        cout << "Person有参普通构造函数的调用" << endl;
    }
    //拷贝构造函数
    Person(const Person &p)
    {
        //将传入的这个人的所有属性，拷贝到我身上
        age = p.age;
        cout << "Person拷贝构造函数调用" << endl;
    }
    ~Person()
    {
        //析构函数
        cout << "Person析构函数的调用" << endl;
    }

    int age;
};

//调用
void test01()
{
    // 1.括号法
    Person p;      //默认构造函数的调用
    Person p2(10); //有参构造函数
    Person p3(p2); //拷贝构造函数

    //注意事项
    //调用默认构造函数时不要加()
    //下面这行代码编译器会认为是函数的声明
    // Person p4(); //返回值为Person类型 函数无参数 函数名为p4（不会认为是调用默认构造函数）

    cout << "p2的年龄为：" << p2.age << endl;
    cout << "p3的年龄为：" << p3.age << endl;

    // 2.显示法

    // 3.隐式转换法
}

void test02()
{
    // 2.显示法
    Person p1;
    Person p2 = Person(10); //有参构造
    Person p3 = Person(p2); //拷贝构造函数

    Person(10); //匿名对象 特点：当前结束后，系统会立即回收调匿名对象
    //有参构造和析构函数会在输出aaaaaa前被调用
    cout << "aaaaaa" << endl;

    //注意事项2
    //不要利用拷贝构造函数 初始化匿名对象
    //编译器会认为 Person(p3);等价于 Person p3;
    // Person(p3); 重定义
}

void test03()
{
    // 3.隐式转换法
    Person p4 = 10; //相当于 Person p4 = Person(10);
    Person p5 = p4; //拷贝构造
}

int main(void)
{
    test01();
    cout << endl;

    test02();
    cout << endl;

    test03();

    return 0;
}