#include <iostream>
using namespace std;
/*
成员属性设为私有：
    1.可以自己控制读写权限
    2.对与写可以检查数据的有效性
*/

class Person
{
public:
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
    //获得年龄 可读可写 如果想修改（范围0 - 150岁）
    int getAge()
    {
        //初始化为0岁
        // m_Age = 0;
        return m_Age;
    }
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "年龄有误" << endl;
            m_Age = 0;
            return;
        }
        m_Age = age;
    }
    //设置情人
    void setLover(string lover)
    {
        m_Lover = lover;
    }

private:
    //姓名 可读可写
    string m_Name;
    //年龄 只读
    int m_Age;
    //情人 只写
    string m_Lover;
};

int main(void)
{
    Person p;
    p.setName("张三");

    p.setAge(1000);
    cout << "姓名为：" << p.getName() << endl;

    cout << "年龄为：" << p.getAge() << endl;
    p.setLover("苍井");

    return 0;
}