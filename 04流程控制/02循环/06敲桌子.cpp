# include <iostream>
using namespace std;

int main(void)
{
    for (int i = 1; i <= 100; ++i)
    {
        //个为有7、十位有7、7的倍数打印敲桌子
        if ( i % 7 == 0 || i / 10 == 7 || i % 10 == 7 ) 
        {
            cout << "敲桌子" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;
}