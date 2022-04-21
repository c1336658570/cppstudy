# include <iostream>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int main(void)
{
    int a = 5, b = 10;
    cout << add(a, b) << endl;

    a = 100;
    b = 500;
    int c = add(a, b);
    cout << c << endl;

    return 0;
}