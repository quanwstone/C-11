#pragma once
/*
NULL������Ϊ0L�������غ���ʱ���ܻ��������
*/
#include<stdio.h>
namespace nullptr_h {

	void Funs(int i)
	{
		printf("in Funs Paramete int\n");
	}
	void Funs(void *p)
	{
		printf("in Func Paramete void*\n");
	}
}
static void nullptr_test()
{
	nullptr_h::Funs(NULL);
	nullptr_h::Funs(nullptr);
}