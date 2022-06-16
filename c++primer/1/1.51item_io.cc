/*
    输入：0-201-70353-x 4 24.99
    输出：0-201-7035-x 4 99.96 24.99
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;

    // read ISBN, number of copies sold, and sales price
    std::cin >> book;
    // write ISBN, number of copies sold, total revenue, and average price
    std::cout << book << std::endl;

    return 0;
}
