#pragma once
/*
thread:用于创建线程.可以传递参数.
条件变量:condition_variable可以使线程间同步.通过wait和nodify.
wait会等到下次的nodify，但是如果nodify提前触发，wait将会阻塞.
这就类似服务端和客户端关系.只有服务端先启动.
*/
#include<iostream>
#include<thread>	//线程
#include<mutex>		//Mutex
#include<condition_variable>//多线程同步
namespace thread_h {

	void Thread_Func1(int iParam, char *cParam)
	{
		std::cout << "In Tread_Func1" << std::endl;
	}
	/*unique_Lock:原理和lock_guard相同，都是RAII，区别就是更多特性,
	内部实现拷贝构造函数:explicit*/
	std::mutex mux;
	void Mux_Func1()
	{
		std::unique_lock<std::mutex> lock(mux);

		std::string i = { "MMMMMMM" };
		for (auto j : i)
			std::cout << j << std::endl;
	}
	void Mux_Func2()
	{
		std::unique_lock<std::mutex> lock(mux);

		std::string i = { "FFFFFF" };
		for (auto j : i)
			std::cout << j << std::endl;
	}
	/*condition_variable 的wait会让线程休眠.
	需要等到另一个线程调用notify即可唤醒.
	用于线程间同步.
	*/
	std::condition_variable cv;
	void Condation_Func1()
	{
		std::unique_lock<std::mutex> lock(mux);

		cv.wait(lock);
		std::cout << __func__ << std::endl;
	}
	void Condation_Func2()
	{
		std::unique_lock<std::mutex> lock(mux);

		cv.notify_one();

		std::cout << __func__ << std::endl;
	}

}

void test()
{
	/*thread,可以直接参数传递*/
	std::thread th(thread_h::Thread_Func1,1, nullptr);
	th.join();//等待
	th.detach();//结束
	/*unique_lock*/
	std::thread am1(thread_h::Mux_Func1);
	std::thread am2(thread_h::Mux_Func2);
	/*condation_variable*/
	std::thread co1(thread_h::Condation_Func1);
	std::thread co2(thread_h::Condation_Func2);
}