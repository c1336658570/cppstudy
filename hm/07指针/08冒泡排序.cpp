# include <iostream>
using namespace std;

void sort(int *arr, int len);

int main(void)
{
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};

    for (int i = 0; i < 10; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;

    sort(arr, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void sort(int *arr, int len)
{
    int i, j;

    for (i = 0; i < len-1; ++i)
    {
        for (j = 0; j < len-1-i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}