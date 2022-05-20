/*
案例描述：
利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
排序规则从大到小，排序算法为选择排序
分别利用char数组和int数组进行测试

总结：模板可以提高代码复用，需要熟练掌握
*/

#include <iostream>
using namespace std;

//实现通用对数组排序的函数
//规则 从大到小
//算法 选择
//测试 char 数组， int 数组

//交换函数模板
template <class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//排序算法
template <typename T>
void mySort(T arr[], int len)
{
    int max;
    for (int i = 0; i < len; ++i)
    {
        max = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            //交换max和i下标的元素
            mySwap(arr[max], arr[i]);
        }
    }
}

//提供打印数组模板
template <class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    //测试char数组
    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}

void test02()
{
    //测试int数组
    int intArr[] = {7, 5, 1, 3, 9, 2, 4, 6, 8};
    int num = sizeof(intArr) / sizeof(int);

    mySort(intArr, num);
    printArray(intArr, num);
}

int main(void)
{
    test01();

    test02();

    return 0;
}