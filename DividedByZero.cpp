#include "DividedByZero.h"
#include <vector>
#include <iostream>
std::vector<int>::size_type test_divided_by_zero_internal(const std::vector<int>& data)	 //指向非栈帧上的数据
{
	std::vector<int>::size_type avg = 0;
	avg /= data.size();	 //可能发生除零错误
	return avg;
}
void test_divided_by_zero()
{
	std::vector<int> data;
	test_divided_by_zero_internal(data);
}