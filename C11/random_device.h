#pragma once
#include<random>
/*
������Ĳ���������Ҫsrand��ʼ�����ӵĲ���
*/
namespace random_device_h {

	void random_device()
	{
		std::random_device dv;
		int ran = dv();

	}
}