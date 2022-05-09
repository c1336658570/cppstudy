# include <iostream>
using namespace std;

int max(int a, int b);

int main(void)
{
    int a = 10;
    int b = 20;

    cout << max(a, b) << endl;

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}