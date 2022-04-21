# include <iostream>
using namespace std;

int main(void)
{
    //选择结构多条件if语句

    int score = 0;
    cout << "请输入考试分数：" << endl;
    cin >> score;
    cout << "您输入的考试分数为" << score << endl;

    if (score > 600)
    {
        cout << "恭喜你考上了一本大学" << endl;
    }
    else if(score > 500)
    {
        cout << "恭喜你考上了二本大学" << endl;
    }
    else if(score > 450)
    {
        cout << "恭喜你考上了三百大学" << endl;
    }
    else
    {
        cout << "未考上本科大学，请再接再厉" << endl;
    }

    return 0;
}