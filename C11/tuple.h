#pragma once
/*tuple:����Ԫ��.���Է��ض������*/
#include<tuple>
#include<iostream>
namespace tuple_h {

	std::tuple<int, const char*> getTest() {
		
		std::tuple<int, const char *>re = std::make_tuple(1, "123");

		return re;
	}
	void Test()
	{
		//��ֵ
		std::tuple<int, const char*>t(1,"123");
		std::tuple<int, const char*>tt = std::make_tuple(1,"123");
		//��ȡԪ�ظ���
		size_t num = std::tuple_size<decltype(t)>::value;
		//��ȡ�ض�λ�õ�Ԫ��
		std::tuple_element<1, decltype(t)>::type cnt = std::get<1>(t);
		std::cout << cnt<<std::endl;
		//����ֵ����
		auto re = getTest();
		std::cout << std::get<0>(re) << std::get<1>(re);
	}
}