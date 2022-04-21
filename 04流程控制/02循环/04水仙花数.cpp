# include <iostream>
# include <math.h>
using namespace std;

int main(void)
{
    int i, val, sum = 0;

    for (i = 100; i <= 999; ++i)
    {
        val = i;
        sum = 0;
        while (val)
        {
            sum += pow((val)%10, 3);
            val /= 10;
        }
        if (sum == i)
        {
            cout << sum << endl;
        }
    }

    return 0;
}