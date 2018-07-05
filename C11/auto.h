#pragma once
#include<vector>
/*
自动类型推断关键字auto,该类型的类型推导是在编译时.
变量赋值有引用,const特殊情况.模板使用,for循环使用.
*/
namespace auto_h {

	/*
	在使用模板函数时，如果返回值的类型和传入的模板参数有关，
	那么可以先用auto做一个占位符，decltype关键字返回真正的类型，
	放到后面是因为需要参数提前声明。
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
	/*自动类型推断关键字auto,该类型的类型推导是在编译时*/
	auto j = i;
	//auto jj;/*无法推导的类型，需要初始值设定项*/

	/*如果初始化表达式为引用，则会去除引用语义*/
	int ia = 1;
	int &ib = ia;
	auto ic = ib;/*ic的类型为int类型*/
	auto &id = ib;/*id的类型为int&类型*/

	/*如果初始化表达式为const，则会去除const语义*/
	const int cia = 10;
	auto cib = cia;
	const auto cic = cia;
	cib = 11;/*正常赋值*/
	//cic = 11;/*表达式必须是可修改的左值*/

	/*模板使用*/
	auto_h::FunsVector();
	auto_h::FuncAuto();

	auto mv = auto_h::Multiply<int,int>(1, 2);
	
}