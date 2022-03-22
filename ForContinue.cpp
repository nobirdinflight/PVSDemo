#include "ForContinue.h"
#include <array>
void test_for_continue_internal(int value)
{
	std::array<int, 2> data = { 0, 1 };
	std::array<int, 2>::const_iterator cit = data.cbegin();
	while (cit != data.cend())
	{
		if (value == 0)
		{
			continue;  // ���valueΪ0����������Զ��������
		}
		++cit;
	}
}
void test_for_continue()
{
	int control_value = 0;
	test_for_continue_internal(control_value);
}