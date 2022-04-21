#include <iostream>
#include <string>
using namespace std;

class Student
{
    //类中的属性和行为 我们统一称为成员
    //属性 成员属性 成员变量
    //行为 成员函数 成员方法
public:
    string m_Name;
    int m_Id;

    void showStudent()
    {
        cout << "学生的姓名为：" << m_Name << endl;
        cout << "学生的学号为：" << m_Id << endl;
    }

    //给姓名赋值
    void setName(string name)
    {
        m_Name = name;
    }
    //给学号赋值
    void setId(int id)
    {
        m_Id = id;
    }
};

int main(void)
{
    Student s1;
    s1.m_Name = "张三";
    s1.m_Id = 1;
    s1.showStudent();

    Student s2;
    s2.m_Name = "李四";
    s2.m_Id = 2;
    s2.showStudent();

    Student s3;
    s2.setName("王五");
    s2.setId(3);
    s2.showStudent();

    return 0;
}