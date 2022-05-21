/*
容器算法迭代器初识
了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力
STL中最常用的容器为Vector，可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器

vector存放内置数据类型
容器：     vector
算法：     for_each
迭代器： vector<int>::iterator
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MyPrint(int val)
{
    cout << val << endl;
}

void test01()
{

    //创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
    vector<int> v;
    //向容器中放数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
    // v.begin()起始迭代器，这个迭代器指向容器中第一个数据
    // v.end()结束迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
    // vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();

    //第一种遍历方式：
    while (pBegin != pEnd)
    {
        cout << *pBegin << endl;
        pBegin++;
    }
    cout << endl;

    //第二种遍历方式：
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;

    //第三种遍历方式：
    //使用STL提供标准遍历算法  头文件 algorithm
    for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
    test01();

    return 0;
}