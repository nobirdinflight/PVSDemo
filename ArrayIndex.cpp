#include "ArrayIndex.h"
#include <vector>
#include <iostream>
void test_array_index_error_internal(const std::vector<int>& data)
{
	int value = data[data.size() - 1];	// data为空时数组越界访问
	std::cerr << value;
}

void test_array_index_error()
{
	std::vector<int> data;
	data.reserve(1);  //为data分配内存但不使用，不影响测试，仅防止seh捕获不到异常
	std::cout << data.data();
	test_array_index_error_internal(data);
}