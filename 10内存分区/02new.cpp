# include <iostream>
using namespace std;

int *func()
{
    //利用new关键字 可以将数据开辟到堆区

    int *p = new int(10);
    return p;
}

//在堆区创建数组
void test02()
{
    int *arr = new int[10]; // 10个元素的数组

    for (int i = 0; i < 10; ++i)
    {
        arr[i] = i+100;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << endl;
    }

    //释放堆区数组
    delete[] arr;
}

void test01()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    //释放堆区内存
    delete p;
    //cout << *p << endl;
}

int main(void)
{
    test01();
    test02();
    

    return 0;
}