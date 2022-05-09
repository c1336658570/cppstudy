# include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

void printStudent1(struct student s);
void printStudent2(struct student *p);

int main(void)
{
    student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;

    cout << "main函数中打印 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;

    printStudent1(s);
    printStudent2(&s);

    return 0;
}

void printStudent1(struct student s)
{
    cout << "子函数1中打印 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
}

void printStudent2(struct student *p)
{
    cout << "子函数2中打印 姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
}