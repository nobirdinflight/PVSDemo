#include "DividedByZero.h"
#include <vector>
#include <iostream>
std::vector<int>::size_type test_divided_by_zero_internal(const std::vector<int>& data)	 //ָ���ջ֡�ϵ�����
{
	std::vector<int>::size_type avg = 0;
	avg /= data.size();	 //���ܷ����������
	return avg;
}
void test_divided_by_zero()
{
	std::vector<int> data;
	test_divided_by_zero_internal(data);
}