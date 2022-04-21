# include <iostream>
using namespace std;

int main(void)
{
    int score = 0;
    
    cout << "请输入考试分数：" << endl;
    cin >> score;
    cout << "您输入的分数为" << score << endl;

    if (score > 600)
    {
        cout << "恭喜你考上了一本大学" << endl;
        if (score > 700)
        {
            cout << "你能考入xupt" << endl;
        }
        else if (score > 650)
        {
            cout << "您能考入清华" << endl;
        }
        else 
        {
            cout << "你能考入北大" << endl;
        }
    }
    else if (score > 500)
    {
        cout << "恭喜你考上了二本大学" << endl;
    }
    else if (score > 450)
    {
        cout << "恭喜你考上了三本大学" << endl;
    }
    else
    {
        cout << "未考上本科大学，请再接再厉";
    }

    return 0;
}