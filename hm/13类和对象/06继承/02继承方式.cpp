/*
    继承方式
    语法：class 子类:继承方式 父类
    继承方式一共有三种
        公共继承
        保护继承
        私有继承
*/

#include <iostream>
using namespace std;

//公共继承
class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class son1 : public Base1
{
public:
    void func()
    {
        m_A = 10; //父类的公共权限成员到子类中依然是公共权限
        m_B = 10; //父类的保护权限成员到子类中依然是保护权限
        // m_C = 10; //父类的私有权限成员到子类中访问到
    }
};

void test01()
{
    son1 s1;
    s1.m_A = 100;
    // s1.m_B = 100;//到son1中m_B是保护权限 类外访问不到
}

//保护继承
class Base2
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son2 : protected Base2
{
public:
    void func()
    {
        m_A = 100; //父类的公共权限成员到子类中是保护权限
        m_B = 100; //父类的保护权限成员到子类中依然是保护权限
        // m_C = 100; //父类的私有权限成员到子类中访问到
    }
};

void test02()
{
    Son2 s1;
    // s1.m_A = 1000; //在Son2中m_A变为保护权限，因此类外访问不到
    // s1.m_B = 1000; //访问不到
}

//私有继承
class Base3
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son3 : private Base3
{
public:
    void func()
    {
        m_A = 100; //父类的公共权限成员到子类中是私有权限
        m_B = 100; //父类的保护权限成员到子类中是私有权限
        // m_C = 100; //父类的私有权限成员到子类中访问到
    }
};

void test03()
{
    Son2 s1;
    // s1.m_A = 1000; //在Son3中m_A变为私有权限，因此类外访问不到
    // s1.m_B = 1000; //访问不到
}

class GrandSon3 : public Son3
{
public:
    void func()
    {
        // m_A = 1000; //在Son3中 m_A变为私有成员，即使儿子也访问不到
        // m_B = 1000; //在Son3中 m_A变为私有成员，即使儿子也访问不到
    }
};

int main(void)
{
    return 0;
}