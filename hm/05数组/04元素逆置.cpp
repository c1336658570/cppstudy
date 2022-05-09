# include <iostream>
using namespace std;

int main(void)
{
    int arr[5] = {1, 3, 2, 5, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
    for (int i = 0; i < length/2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[length-1-i];
        arr[length-1-i] = temp;
    }
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;

    return 0;
}