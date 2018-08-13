#pragma once
#include<stdio.h>
/*decltype�ؼ���
decltype��ȡ���ʽ�����ͣ�����ȴ����ִ�б��ʽ����.��auto��ͬ*/
namespace decltype_h
{
	/*�����÷�*/
	int func_type()
	{
		printf("in func_type\n");
	}
	void test()
	{
		int num = 10;
		
		decltype(num) i;
		decltype(func_type) ii;//����ִ��func_type����.

	}
	/*����const�޶���*/
	void test_const()
	{
		int ia = 1;
		const int ib = 2;
		const int ic = 3;
		const int *const id = &ib;

		decltype(ib) dib = 4;//dib������Ϊconst int
		//dib = 5;//���ʽ�����ǿ��޸ĵ���ֵ.
		decltype(id) did = &ib;//did������Ϊconst int *const
		
		//did = &ic;//���ʽ�����ǿ��޸ĵ���ֵ
		//*did = 4;//���ʽ�����ǿ��޸ĵ���ֵ

	}
	/*��������*/
	void test_reference()
	{
		int ia = 1;
		int &ib = ia;

		decltype(ia) ic;
		decltype(ib) id = ic;//idΪ���ã������ʼ��
		decltype((ia))ie = ic;//ieΪ���ã������ʼ����˫����Ϊ����.

	}
	/*����ָ��*/
	void test_prt()
	{
		int ia = 2;
		int *ib = &ia;
		
		decltype(ia)ic;
		decltype(ib)id;//id����Ϊint*
		*id = 3;
		decltype(*ib)ie = ic;//ie����Ϊ���ã������ʼ���������ò�����ie����Ϊ��������.
	}
	/*
	1.auto���Զ���const��decltype��������const��
	2.�����ò�����auto�ƶϳ�ԭ�����ͣ�decltype�ƶϳ����ã�
	3.�Խ����ò�����auto�ƶϳ�ԭ�����ͣ�decltype�ƶϳ����ã�
	4.auto�ƶ�ʱ��ʵ��ִ�У�decltype����ִ�У�ֻ��������
	��֮��ʹ���й����к�const�����ú�ָ����ʱ��Ҫ�ر�
	*/

}