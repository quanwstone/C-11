#pragma once
/*Lambda表达式
[capture list](params list) mutable exception-> return type{ function body }
capture list：捕获外部变量列表
params list：形参列表
mutable指示符：用来说用是否可以修改捕获的变量
exception：异常设定
return type：返回类型
function body：函数体

1:参数列表中不能有默认参数
2:不支持可变参数
3:所有参数必须有参数名
*/
#include<iostream>
namespace lambda_h {
	//值捕获,值拷贝的形式.内部只能通过添加mutable关键字进行修改该变量,但不会
	//影响外面使用.
	void value_capture()
	{
		int iL = 3;
		auto f = [iL] {std::cout << "In value_capture iL:" << iL << std::endl; };
		auto fA = [iL]()mutable {std::cout << "In value_capture mutable iL:" << ++iL << std::endl; };
		f();
		fA();
	}
	//引用捕获.lambda内部修改变量会影响函数外数值.
	void quote_capture()
	{
		int iLL = 3;
		auto fL = [&iLL] { std::cout <<"In quote_capture lambda iLL:"<< ++iLL << std::endl; };
		fL();
		std::cout << "In quote_capture iLL:" << iLL << std::endl;
	}
	//隐式捕获
	/*隐式捕获 = :所有变量的值传递，&所有变量的引用传递*/
	void implicit_capture()
	{
		int iL = 3;
		int iLL = 3;
		
		auto implicit = [=] {std::cout << "In implicit_capture value:"<<iLL << iL << std::endl; };
		auto implicit2 = [&] {std::cout << "In implicit_capture quote:"<<iLL << iL << std::endl; };
	}
}
static void lambda_test()
{
	lambda_h::value_capture();
	lambda_h::quote_capture();

}