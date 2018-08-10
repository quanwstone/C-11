#pragma once
/*
delete 和default的使用，
delete可用于任何函数，不仅仅局限于类成员函数。
函数重载也可以过滤到一些.
还可以模板特例化
*/
namespace delete_h {

	template<typename T>
	class CNxTemplate
	{
	public:
		void TFunc(T *num) {};
	};
	template<>
	class CNxTemplate<int>
	{
	public:
		void TFunc(int *num) = delete;
	};
	
	void Test(int num) {};

	void Test(char str) = delete;

	//c++98
	class CNxBase 
	{
	public:
		CNxBase() {};
		~CNxBase() {};
		CNxBase(const CNxBase&) = delete;//
		CNxBase & operator = (CNxBase &) {};
	};
	//c++98 不能拷贝的类
	class CNxDontCopyBase
	{
	public:
		CNxDontCopyBase() {};
		~CNxDontCopyBase() {};
	private:
		CNxDontCopyBase(const CNxDontCopyBase&) {};
		CNxDontCopyBase & operator = (CNxDontCopyBase &) {};
	};
	//c++11
	/*
	移动构造函数的调用：与拷贝类似，移动也使用一个对象的值设置另一个对象的值，但是，又与
	拷贝不同的是，移动实现的是对象真实的转移，移动操作的发生是当移动对象是未命名的对象的时候，
	就是临时变量，比如函数返回值。
	CNx11Base Func(){};
	CNx11Base cb = Func（）；//此时就是调用了移动构造函数
	*/
	class CNx11Base
	{
	public:
		CNx11Base() = default;
		~CNx11Base() = default;

		CNx11Base(const CNx11Base&) = delete;
		CNx11Base & operator = (CNx11Base &) = delete;

		CNx11Base(const CNx11Base &&) {};//移动构造函数
		CNx11Base && operator = (CNx11Base &&) {};//移动赋值算子
		
	};
}

void test()
{
	delete_h::CNxTemplate<int>Tm;
	int num = 0;

	Tm.TFunc(&num);//编译时期提示删除函数.

	delete_h::CNxBase nm;
	delete_h::CNxBase nn(nm);//编译时期就会提示不可拷贝

	delete_h::CNxDontCopyBase m;
	delete_h::CNxDontCopyBase n(m);//编译时期就会提示不可拷贝

}