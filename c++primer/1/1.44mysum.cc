#include <iostream>

int main()
{
	int sum = 0, value = 0;

	// read until end-of-file, calculating a running total of all values read
	//当我们使用一个istream对象做条件时，其效果时检测流的状态，如果流是有效的，即未遇到错误，检测成功，如果遇到文件结尾，或者无效输入，流对象的状态会变成无效的
	while (std::cin >> value)
		sum += value; // equivalent to sum = sum + value

	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
