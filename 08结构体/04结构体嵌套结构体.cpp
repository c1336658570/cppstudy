# include <iostream>
# include <string>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

struct teacher
{
    int id; // 教师编号
    string name;
    int age; // 年龄
    struct student stu; //辅导学生
};

int main(void)
{
    teacher t;
    t.id = 10000;
    t.name = "老王";
    t.age = 50;
    t.stu.name = "小王";
    t.stu.age = 20;
    t.stu.score = 60;

    cout << "老师姓名：" << t.name << " 老师编号：" << t.id << " 老师年龄：" << t.age
    << " 老师辅导的学生姓名：" << t.stu.name << " 学生年龄：" << t.stu.age 
    << " 学生考试分数：" << t.stu.score << endl;

    return 0;
}