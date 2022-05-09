# include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

void printfStudents(struct student s);
void printStudentp(struct student *p);

int main(void)
{
    struct student s = {"张三", 15, 70};

    printfStudents(s);
    printStudentp(&s);

    return 0;
}

void printfStudents(struct student s)
{
    cout << "姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
}

void printStudentp(const struct student * p)
{
    //p->age = 20;
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
}