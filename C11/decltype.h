#pragma once
#include<stdio.h>
/*decltype关键字
decltype获取表达式的类型，但是却不会执行表达式方法.和auto不同*/
namespace decltype_h
{
	/*基本用法*/
	int func_type()
	{
		printf("in func_type\n");
	}
	void test()
	{
		int num = 10;
		
		decltype(num) i;
		decltype(func_type) ii;//不会执行func_type方法.

	}
	/*含有const限定符*/
	void test_const()
	{
		int ia = 1;
		const int ib = 2;
		const int ic = 3;
		const int *const id = &ib;

		decltype(ib) dib = 4;//dib的类型为const int
		//dib = 5;//表达式必须是可修改的左值.
		decltype(id) did = &ib;//did的类型为const int *const
		
		//did = &ic;//表达式必须是可修改的左值
		//*did = 4;//表达式必须是可修改的左值

	}
	/*含有引用*/
	void test_reference()
	{
		int ia = 1;
		int &ib = ia;

		decltype(ia) ic;
		decltype(ib) id = ic;//id为引用，必须初始化
		decltype((ia))ie = ic;//ie为引用，必须初始化。双括号为引用.

	}
	/*含有指针*/
	void test_prt()
	{
		int ia = 2;
		int *ib = &ia;
		
		decltype(ia)ic;
		decltype(ib)id;//id类型为int*
		*id = 3;
		decltype(*ib)ie = ic;//ie类型为引用，必须初始化，解引用操作是ie类型为引用类型.
	}
	/*
	1.auto忽略顶层const，decltype保留顶层const；
	2.对引用操作，auto推断出原有类型，decltype推断出引用；
	3.对解引用操作，auto推断出原有类型，decltype推断出引用；
	4.auto推断时会实际执行，decltype不会执行，只做分析。
	总之在使用中过程中和const、引用和指针结合时需要特别
	*/

}