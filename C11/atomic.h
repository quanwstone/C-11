#pragma once
/*
atomic:ԭ�Ӳ���,���̵߳��ò���Ҫ����.
*/
#include<atomic>
#include<thread>
namespace atomic_h {
	
	std::atomic_int atoinit = 10;

	void atomic_add()
	{
		atoinit++;
	}
	void atomic_sub()
	{
		atoinit--;
	}
}
static void atomic_test()
{
	std::thread th(atomic_h::atomic_add);
	std::thread th(atomic_h::atomic_sub);
}