# include <iostream>
using namespace std;
//包含time系统时间头文件
# include <ctime>

int main(void)
{
    srand( unsigned( time(NULL) ) );
    //1.生成随机数
    int num = rand() % 100 + 1;  //生成1-100随机数

    //2.玩家进行猜测
    //3.猜对 退出游戏
    //猜错  提示猜的结果 过大或者过小 重新返回第二步骤
    int val = 0; //玩家输入的的数据
    while (1)
    {
        cin >> val;

        if (val > num)
        {
            cout << "猜测过大" << endl;
        }
        else if (val < num)
        {
            cout << "猜测过小" << endl;
        }
        else
        {
            cout << "恭喜你猜对了" << endl;
            break;
        }
    }

    return 0;
}