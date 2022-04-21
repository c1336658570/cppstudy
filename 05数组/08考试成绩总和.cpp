# include <iostream>
# include <string>
using namespace std;

int main(void)
{
    int scores[3][3] = 
    {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}
    };
    string names[3] = {"张三", "李四", "王五"};
    for (int i = 0; i < 3; ++i)
    {
        int sum = 0;
        for (int j = 0; j < 3; ++j)
        {
            sum += scores[i][j];
        }
        cout << "第" << i+1 << "个人的成绩" << sum << endl;
        cout << names[i] << "的成绩为：" << sum << endl;
    }

    return 0;
}