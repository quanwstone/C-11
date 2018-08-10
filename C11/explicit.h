#pragma once
/*
explicit:用于修饰构造函数，防止隐式转换。
*/
#include<stdio.h>
namespace explicit_h
{
	class CNxBase
	{
	public:
		CNxBase();
		CNxBase(int i, int num = 0);
	};
	CNxBase::CNxBase()
	{
		printf("In CNxBase 1 \n");
	}
	CNxBase::CNxBase(int i, int num)
	{
		printf("In CNxBase 2 \n");
	}

	class CNxBase2
	{
	public:
		CNxBase2();
		explicit CNxBase2(int i, int num = 0);
	};
	CNxBase2::CNxBase2()
	{
		printf("In CNxBase2 1 \n");
	}
	CNxBase2::CNxBase2(int i, int num)
	{
		printf("In CNxBase2 2 \n");
	}
}
void test()
{
	explicit_h::CNxBase cb1;
	explicit_h::CNxBase cb12(1);
	explicit_h::CNxBase cb13 = 1;//执行了隐式转换，调用了CNxBase(int i, int num)
	
	explicit_h::CNxBase2 cb2;
	explicit_h::CNxBase2 cb22(1);
	explicit_h::CNxBase2 cb23 = 1;//编译提示出错，
}