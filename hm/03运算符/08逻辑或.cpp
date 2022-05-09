# include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int b = 10;

    cout << (a || b) << endl;

    a = 0;
    b = 10;

    cout << (a || b) << endl;

    a = 0;
    b = 0;
    
    cout << (a || b) << endl;

    return 0;
}