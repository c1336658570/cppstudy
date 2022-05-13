/*
    空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
    如果用到this指针，需要加以判断保证
*/

#include <iostream>
using namespace std;

//空指针调用成员函数

class Person
{
public:
    void showClassName()
    {
        cout << "this is Person class" << endl;
    }

    void showPersonAge()
    {
        if (this == NULL)
        {
            return;
        }
        //报错原因是因为传入的指针是NULL
        cout << "age = " << m_Age << endl;
        //等价于cout << "age = " << this->m_Age << endl;
    }

    int m_Age;
};

void test01()
{
    Person *p = NULL;

    p->showClassName();

    p->showPersonAge();
}

int main(void)
{
    test01();

    return 0;
}