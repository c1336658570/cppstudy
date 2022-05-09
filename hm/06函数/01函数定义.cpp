# include <iostream>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int main(void)
{
    int a = 5, b = 10;
    cout << add(a, b);

    return 0;
}