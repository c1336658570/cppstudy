#include <iostream>
using namespace std;
/*
访问权限：
    公共权限 public     成员 类内可以访问 类外不可以访问
    保护权限 protected  成员 类内可以访问 类外不可以访问 儿子可以访问父亲保护的内容
    私有权限 private    成员 类内可以访问 类外不可以访问 儿子不可以访问父亲私有的内容
*/

class Person
{
    //公共权限 public
public:
    string m_Name;

    //保护权限 protected
protected:
    string m_Car; //汽车

    //私有权限 private
private:
    int m_Password; //银行卡密码

public:
    void func1()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }

private:
    void func2()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};

int main(void)
{
    Person p1;
    p1.m_Name = "李四";
    // p1.m_Car = "三蹦子"; 无法访问
    // p1.m_Password = 132; 无法访问
    p1.func1();
    // p1.func2(); 无法访问

    return 0;
}