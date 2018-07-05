#pragma once
#include<iostream>
namespace for_h {
	
	/*
	列表初始化机制
	std::string p = { "1234" }
	int x(0);
	int x = {0};
	*/
	void FuncFor()
	{
		//std::string p = { "1234" };
		std::string p("1234");

		for (auto r : p)
		{
			std::cout << r << std::endl;
		}
	}
}