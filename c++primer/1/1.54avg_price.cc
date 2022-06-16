/*
    从一个文件中读取销售记录，生成每本书的销售报告，显示售出测试，总销售额和平均价格。
    我们假定每个ISBN书号的所有销售记录在文件中是聚在一起的。

    将每个ISBN的所有数据合并起来，存入total中，使用trans变量保存读取的每条销售记录，
    如果total和trans的ISBN相同，更新total的值，否则打印total的值
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total; // variable to hold data for the next transaction

    // read the first transaction and ensure that there are data to process
    if (std::cin >> total)
    {
        Sales_item trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans)
        {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total += trans; // update the running total
            else
            {
                // print results for the previous book
                std::cout << total << std::endl;
                total = trans; // total now refers to the next book
            }
        }
        std::cout << total << std::endl; // print the last transaction
    }
    else
    {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }

    return 0;
}
