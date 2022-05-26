/*
set_intersection

功能描述：
求两个容器的交集

函数原型：
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
  // 求两个集合的交集
  // 注意:两个集合必须是有序序列
  // beg1 容器1开始迭代器
  // end1 容器1结束迭代器
  // beg2 容器2开始迭代器
  // end2 容器2结束迭代器
  // dest 目标容器开始迭代器

总结：
求交集的两个集合必须的有序序列
目标容器开辟空间需要从两个容器中取小值
set_intersection返回值既是交集中最后一个元素的位置
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);     // 0~9
        v2.push_back(i + 5); // 5~14
    }

    vector<int> vTarget;
    //目标容器需要提前开辟空间，取两个里面较小的值给目标容器开辟空间
    vTarget.resize(min(v1.size(), v2.size()));

    //返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd =
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    //使用set_intersection的返回值作为结束迭代器，因为vTarget的容量可能大于元素个数
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
    for_each(vTarget.begin(), vTarget.end(), myPrint());
    cout << endl;
}

int main()
{
    test01();

    return 0;
}