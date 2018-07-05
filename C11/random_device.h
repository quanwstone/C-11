#pragma once
#include<random>
/*
随机数的产生，不需要srand初始化种子的步骤
*/
namespace random_device_h {

	void random_device()
	{
		std::random_device dv;
		int ran = dv();

	}
}