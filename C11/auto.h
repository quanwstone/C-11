#pragma once
#include<vector>
/*
�Զ������ƶϹؼ���auto,�����͵������Ƶ����ڱ���ʱ.
������ֵ������,const�������.ģ��ʹ��,forѭ��ʹ��.
*/
namespace auto_h {

	/*
	��ʹ��ģ�庯��ʱ���������ֵ�����ͺʹ����ģ������йأ�
	��ô��������auto��һ��ռλ����decltype�ؼ��ַ������������ͣ�
	�ŵ���������Ϊ��Ҫ������ǰ������
	*/
	template <typename _Tx, typename _Ty>
	auto Multiply(_Tx x, _Ty y)->decltype(x*y)
	{
		return x*y;
	}

	void FunsVector()
	{
		std::vector<int>vTemp;

		vTemp.push_back(1);
		vTemp.push_back(2);
		vTemp.push_back(3);

		for (std::vector<int>::iterator iter = vTemp.begin(); iter != vTemp.end(); iter++)
		{
			printf("vTemp = %d\n", *iter);
		}
	}
	void FuncAuto()
	{
		std::vector<int>vTemp;
		
		vTemp.push_back(1);
		vTemp.push_back(2);
		vTemp.push_back(3);

		for (auto v = vTemp.begin(); v != vTemp.end(); v++)
		{
			printf("vTmep = %d\n", *v);
		}
	}
}

static void auto_test()
{
	int i = 0;
	/*�Զ������ƶϹؼ���auto,�����͵������Ƶ����ڱ���ʱ*/
	auto j = i;
	//auto jj;/*�޷��Ƶ������ͣ���Ҫ��ʼֵ�趨��*/

	/*�����ʼ�����ʽΪ���ã����ȥ����������*/
	int ia = 1;
	int &ib = ia;
	auto ic = ib;/*ic������Ϊint����*/
	auto &id = ib;/*id������Ϊint&����*/

	/*�����ʼ�����ʽΪconst�����ȥ��const����*/
	const int cia = 10;
	auto cib = cia;
	const auto cic = cia;
	cib = 11;/*������ֵ*/
	//cic = 11;/*���ʽ�����ǿ��޸ĵ���ֵ*/

	/*ģ��ʹ��*/
	auto_h::FunsVector();
	auto_h::FuncAuto();

	auto mv = auto_h::Multiply<int,int>(1, 2);
	
}