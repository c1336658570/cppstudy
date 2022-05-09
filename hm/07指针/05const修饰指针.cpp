# include <iostream>
using namespace std;

int main(void)
{
    //1.const修饰指针  常量指针
    int a = 10;
    int b = 10;
    
    const int *p = &a;
    //*p = 20;
    p = &b;

    //2.const修饰常量，指针常量
    int * const p2 = &a;
    *p2 = 100;
    //p2 = &b;

    //3.const修饰指针和常量
    const int * const p3 = &a;
    //*p3 = 100;
    //p3 = &b;

    return 0;
}