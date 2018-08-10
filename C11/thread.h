#pragma once
/*
thread:���ڴ����߳�.���Դ��ݲ���.
��������:condition_variable����ʹ�̼߳�ͬ��.ͨ��wait��nodify.
wait��ȵ��´ε�nodify���������nodify��ǰ������wait��������.
������Ʒ���˺Ϳͻ��˹�ϵ.ֻ�з����������.
*/
#include<iostream>
#include<thread>	//�߳�
#include<mutex>		//Mutex
#include<condition_variable>//���߳�ͬ��
namespace thread_h {

	void Thread_Func1(int iParam, char *cParam)
	{
		std::cout << "In Tread_Func1" << std::endl;
	}
	/*unique_Lock:ԭ���lock_guard��ͬ������RAII��������Ǹ�������,
	�ڲ�ʵ�ֿ������캯��:explicit*/
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
	/*condition_variable ��wait�����߳�����.
	��Ҫ�ȵ���һ���̵߳���notify���ɻ���.
	�����̼߳�ͬ��.
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
	/*thread,����ֱ�Ӳ�������*/
	std::thread th(thread_h::Thread_Func1,1, nullptr);
	th.join();//�ȴ�
	th.detach();//����
	/*unique_lock*/
	std::thread am1(thread_h::Mux_Func1);
	std::thread am2(thread_h::Mux_Func2);
	/*condation_variable*/
	std::thread co1(thread_h::Condation_Func1);
	std::thread co2(thread_h::Condation_Func2);
}