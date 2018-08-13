#pragma once
#include<stdio.h>
#include<functional>
namespace function_h
{
	int add(int i, int j)
	{
		printf("in add\n");
	}
	void test_function()
	{
		//之前调用方式
		typedef int(*Func)(int, int);

		Func func;

		func = add;
		func(1, 2);
		//函数指针赋值必须要有相同的参数和返回值，可以重载
		std::function<int(int, int)>func_func;
		func_func = add;
		func_func(1, 2);
		//lambda表达式赋值
		func_func = [](int a, int b) {printf("in lambda\n"); };
		func_func(1, 2);

	}
}