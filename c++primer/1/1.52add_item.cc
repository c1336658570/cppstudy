/*
    输入：
    0-201-70355-x 3 20.00
    0-201-70355-x 2 25.00
    输出：
    0-201-70355-x 5 110 22
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;

    std::cin >> item1 >> item2;              // read a pair of transactions
    std::cout << item1 + item2 << std::endl; // print their sum

    return 0;
}
