#pragma once
/*
explicit:�������ι��캯������ֹ��ʽת����
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
	explicit_h::CNxBase cb13 = 1;//ִ������ʽת����������CNxBase(int i, int num)
	
	explicit_h::CNxBase2 cb2;
	explicit_h::CNxBase2 cb22(1);
	explicit_h::CNxBase2 cb23 = 1;//������ʾ����
}