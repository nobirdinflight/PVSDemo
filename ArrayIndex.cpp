#include "ArrayIndex.h"
#include <vector>
#include <iostream>
void test_array_index_error_internal(const std::vector<int>& data)
{
	int value = data[data.size() - 1];	// dataΪ��ʱ����Խ�����
	std::cerr << value;
}

void test_array_index_error()
{
	std::vector<int> data;
	data.reserve(1);  //Ϊdata�����ڴ浫��ʹ�ã���Ӱ����ԣ�����ֹseh���񲻵��쳣
	std::cout << data.data();
	test_array_index_error_internal(data);
}