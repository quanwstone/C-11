#pragma once
/*tuple:容器元组.可以返回多个类型*/
#include<tuple>
#include<iostream>
namespace tuple_h {

	std::tuple<int, const char*> getTest() {
		
		std::tuple<int, const char *>re = std::make_tuple(1, "123");

		return re;
	}
	void Test()
	{
		//赋值
		std::tuple<int, const char*>t(1,"123");
		std::tuple<int, const char*>tt = std::make_tuple(1,"123");
		//获取元素个数
		size_t num = std::tuple_size<decltype(t)>::value;
		//获取特定位置的元素
		std::tuple_element<1, decltype(t)>::type cnt = std::get<1>(t);
		std::cout << cnt<<std::endl;
		//返回值函数
		auto re = getTest();
		std::cout << std::get<0>(re) << std::get<1>(re);
	}
}