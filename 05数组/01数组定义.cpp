# include <iostream>
using namespace std;

int main(void)
{
    int arr[5];

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;
    cout << endl;

    //未完全初始化，后面自动补0
    int arr2[5] = {10, 20, 30};

    cout << arr2[0] << endl;
    cout << arr2[1] << endl;
    cout << arr2[2] << endl;
    cout << arr2[3] << endl;
    cout << arr2[4] << endl;

    for (int i = 0; i < 5; ++i)
    {
        cout << arr2[i] << endl;
    }
    cout << endl;

    int arr3[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    for (int i = 0; i < 9; ++i)
    {
        cout << arr3[i] << endl;
    }

    return 0;
}