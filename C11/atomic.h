#pragma once
/*
atomic:原子操作,多线程调用不需要加锁.
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