# include <iostream>
using namespace std;

int main(void)
{
    //switch语句
    //给电影打分
    //10/9经典
    //8/7非常好
    //6/5一般
    //5以下烂片

    cout << "请给电影进行打分" << endl;
    int score = 0;
    cin >> score;
    cout << "你打的分数为：" << score << endl;

    switch(score)
    {
        case 10:
        case 9:
            cout << "你认为是经典电影" << endl;
            break;
        case 8:
        case 7:
            cout << "你认为是非常好的电影" << endl;
            break;
        case 6:
        case 5:
            cout << "你认为电影一般" << endl;
            break;
        default:
            cout << "你认为电影是烂片" << endl;
            break;
    }

    return 0;
}