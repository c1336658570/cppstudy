#include <iostream>
using namespace std;

/*
    浅拷贝会导致堆区内存被重复释放
    Person p1(18, 160);
    Person p2(p1);

    p1，和p2中的m_Height指向同一块内存
*/

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
        cout << "Person的有参构造函数调用" << endl;
    }
    ~Person()
    {
        //析构代码，将堆区开辟的数据做释放操作
        //导致堆区内存重复释放
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person的析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height; //身高
};

//深拷贝
class Person1
{
public:
    Person1()
    {
        cout << "Person1的默认构造函数调用" << endl;
    }
    Person1(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
        cout << "Person1的有参构造函数调用" << endl;
    }
    //自己实现拷贝构造函数来实现浅拷贝带来的问题
    Person1(const Person1 &p)
    {
        cout << "person1拷贝构造函数的调用" << endl;
        m_Age = p.m_Age;
        // m_Height = p.m_Height; 编译器默认实现的拷贝构造函数

        //深拷贝操作
        m_Height = new int(*p.m_Height);
    }
    ~Person1()
    {
        //析构代码，将堆区开辟的数据做释放操作
        //导致堆区内存重复释放
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person1的析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height; //身高
};

void test01()
{
    Person p1(18, 160);
    cout << "p1的年龄为：" << p1.m_Age << endl;

    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_Age << endl;
}

void test02()
{
    Person1 p1(18, 160);
    cout << "p1的年龄为：" << p1.m_Age << endl;

    Person1 p2(p1);
    cout << "p2的年龄为：" << p2.m_Age << endl;
}

int main(void)
{
    // test01();

    test02();

    return 0;
}