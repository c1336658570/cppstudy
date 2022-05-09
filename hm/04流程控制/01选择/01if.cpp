# include <iostream>
using namespace std;

int main(void)
{
    //判断分数是否大于600，大于，视为考上一本

    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    if (score > 600)
    {
        cout << "恭喜你考上一本大学" << endl;
    }

    return 0;
}