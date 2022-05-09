# include <iostream>
using namespace std;

int main(void)
{
    int arr[5] = {300, 350, 200, 400, 250};
    int max = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "最重的小猪体重为：" << max << endl;

    return 0;
}