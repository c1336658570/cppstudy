/*

多态的基本概念
    多态是C++面向对象三大特性之一
多态分为两类
    静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
    动态多态: 派生类和虚函数实现运行时多态
静态多态和动态多态区别：
    静态多态的函数地址早绑定  -  编译阶段确定函数地址
    动态多态的函数地址晚绑定  -  运行阶段确定函数地址

*/

#include <iostream>
using namespace std;

//Animal内部结构，vfptr(virtual function pointer)--虚函数（表）指针，
//指向虚函数表，vftable(virtual function table)--虚函数（表），表内部记录虚函数的地址（&Animal::speak）
//即Animal作用域下的speak函数的地址
//动物类
class Animal
{
public:
    // Speak函数就是虚函数
    //函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

//Cat内部结构，继承Animal的虚函数指针和虚函数表
//子类重写父类的虚函数时，子类中的虚函数表内部会替换为子类虚函数地址，即&Animal::speak被&cat::speak替换了
//父类中的虚函数表不发生改变
//猫类
class Cat : public Animal
{
public:
    //重写 函数返回值类型 函数名 参数列表要完全相同
    virtual void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

//狗类
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编

//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void DoSpeak(Animal &animal) //Animal &animal = cat
{
    //当父类中的指针或者引用指向子类对象时，会发生多态，在运行阶段会去通过cat的虚函数指针，
    //在cat虚函数表中找speak函数
    animal.speak();
}
//
//多态满足条件：
// 1、有继承关系
// 2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象

void test01()
{
    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
}

void test02()
{
    cout << "sizeof Animal = " << sizeof(Animal) << endl; //Animal占8字节，内部结构查看上面
}

int main()
{
    test01();

    test02();

    return 0;
}
