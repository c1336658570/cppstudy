# include <iostream>
# include <bits/stdc++.h>
using namespace std;

struct student
{
    string sName;
    int score;
};

struct teacher
{
    string tName;
    struct student sArray[5];
};

void allocateSpace(struct teacher *tArray, int len);
void printfInfo(struct teacher *tArray, int len);

int main(void)
{
    srand( (unsigned int)time(NULL) );

    struct teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);
    printfInfo(tArray, len);

    return 0;
}

void allocateSpace(struct teacher *tArray, int len)
{
    string nameSeed = "ABCDE";

    for (int i = 0; i < len; ++i)
    {
        //给老师赋值
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i];

        //循环给老师的五名学生赋值
        for (int j = 0; j < 5; ++j)
        {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSeed[j];

            tArray[i].sArray[j].score = rand() % 61 + 40;
        }
    }
}

void printfInfo(struct teacher *tArray, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << "老师姓名:" << tArray[i].tName << endl;

        for (int j = 0;j < 5; ++j)
        {
            cout << "\t学生姓名：" << tArray[i].sArray[j].sName << " 学生成绩" << tArray[i].sArray[j].score << endl;
        }
    }
}