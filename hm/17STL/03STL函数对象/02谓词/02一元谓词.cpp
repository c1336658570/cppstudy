/*
一元谓词

总结：参数只有一个的谓词，称为一元谓词
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1.一元谓词
struct GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{

    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //查找容器中，有没有大于5的数
    // GreaterFive()，匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "没找到!" << endl;
    }
    else
    {
        cout << "找到:" << *it << endl;
    }
}

int main()
{
    test01();

    return 0;
}