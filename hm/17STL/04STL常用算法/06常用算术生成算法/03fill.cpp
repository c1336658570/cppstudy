/*
fill

功能描述：
向容器中填充指定的元素

函数原型：
fill(iterator beg, iterator end, value);
  // 向容器中填充元素
  // beg 开始迭代器
  // end 结束迭代器
  // value 填充的值

总结：利用fill可以将容器区间内元素填充为 指定的值
*/

#include <iostream>
#include <numeric>
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
    vector<int> v;
    v.resize(10);
    //后期重新填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main()
{
    test01();

    return 0;
}