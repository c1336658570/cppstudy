# include <iostream>
# include <string>
using namespace std;

//1.设计英雄结构体
struct hero
{
    string name;
    int age;
    string sex;
};

void bubbleSort(struct hero * heroArray, int len);
void printHero(struct hero *heroArray, int len);

int main(void)
{
    //2.创建数组存放5个英雄
    struct hero heroArray[5] = 
    {
        {"刘备", 23, "男"},
        {"关于", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"}
    };

    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    printHero(heroArray, len);
    cout << endl;
    
    bubbleSort(heroArray, len);
    printHero(heroArray, len);

    //3.对数组排序，按升序

    return 0;
}

void bubbleSort(struct hero * heroArray, int len)
{
    for (int i = 0; i < len-1; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (heroArray[j].age < heroArray[j+1].age)
            {
                struct hero temp = heroArray[j];
                heroArray[j] = heroArray[j+1];
                heroArray[j+1] = temp;
            }
        }
    }
}

void printHero(struct hero *heroArray, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << "姓名：" << heroArray[i].name << " 年龄：" << heroArray[i].age
        << " 性别：" << heroArray[i].sex << endl;
    }
}