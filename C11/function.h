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
		//֮ǰ���÷�ʽ
		typedef int(*Func)(int, int);

		Func func;

		func = add;
		func(1, 2);
		//����ָ�븳ֵ����Ҫ����ͬ�Ĳ����ͷ���ֵ����������
		std::function<int(int, int)>func_func;
		func_func = add;
		func_func(1, 2);
		//lambda���ʽ��ֵ
		func_func = [](int a, int b) {printf("in lambda\n"); };
		func_func(1, 2);

	}
}