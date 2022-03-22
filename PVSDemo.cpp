#include "DividedByZero.h"
#include "ArrayIndex.h"
#include "ForContinue.h"
#include <Windows.h>
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
int print_exception(int code, PEXCEPTION_POINTERS ex)
{
	std::cout << "Exception Code: " << std::hex << code << std::endl;
	return EXCEPTION_EXECUTE_HANDLER;
}
void test_divided_by_zero_seh()
{
	// 触发除零错误
	__try
	{
		test_divided_by_zero();
	}
	__except (print_exception(GetExceptionCode(), GetExceptionInformation()))
	{
	}
}
void test_array_index_error_seh()
{
	// 触发数组越界错误
	__try
	{
		test_array_index_error();
	}
	__except (print_exception(GetExceptionCode(), GetExceptionInformation()))
	{
	}
}
void test_for_continue_endless_loop()
{
	// 测试死循环
	auto future = std::async(std::launch::async, &test_for_continue);
	auto status = future.wait_for(std::chrono::seconds(2));
	if (status != std::future_status::ready)
	{
		std::cout << "Endless Loop." << std::endl;
	}
	// XXX: 强制退出进程
	TerminateProcess(GetCurrentProcess(), 0);
}

int main()
{
	test_divided_by_zero_seh();
	test_array_index_error_seh();

	// main函数里malloc函数未free
	int* p = (int*)malloc(sizeof(int));
	if (p != nullptr)
	{
		*p = 1;
	}

	test_for_continue_endless_loop();
	return 0;
}