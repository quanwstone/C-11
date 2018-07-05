#pragma once
/*Lambda���ʽ
[capture list](params list) mutable exception-> return type{ function body }
capture list�������ⲿ�����б�
params list���β��б�
mutableָʾ��������˵���Ƿ�����޸Ĳ���ı���
exception���쳣�趨
return type����������
function body��������

1:�����б��в�����Ĭ�ϲ���
2:��֧�ֿɱ����
3:���в��������в�����
*/
#include<iostream>
namespace lambda_h {
	//ֵ����,ֵ��������ʽ.�ڲ�ֻ��ͨ�����mutable�ؼ��ֽ����޸ĸñ���,������
	//Ӱ������ʹ��.
	void value_capture()
	{
		int iL = 3;
		auto f = [iL] {std::cout << "In value_capture iL:" << iL << std::endl; };
		auto fA = [iL]()mutable {std::cout << "In value_capture mutable iL:" << ++iL << std::endl; };
		f();
		fA();
	}
	//���ò���.lambda�ڲ��޸ı�����Ӱ�캯������ֵ.
	void quote_capture()
	{
		int iLL = 3;
		auto fL = [&iLL] { std::cout <<"In quote_capture lambda iLL:"<< ++iLL << std::endl; };
		fL();
		std::cout << "In quote_capture iLL:" << iLL << std::endl;
	}
	//��ʽ����
	/*��ʽ���� = :���б�����ֵ���ݣ�&���б��������ô���*/
	void implicit_capture()
	{
		int iL = 3;
		int iLL = 3;
		
		auto implicit = [=] {std::cout << "In implicit_capture value:"<<iLL << iL << std::endl; };
		auto implicit2 = [&] {std::cout << "In implicit_capture quote:"<<iLL << iL << std::endl; };
	}
}
static void lambda_test()
{
	lambda_h::value_capture();
	lambda_h::quote_capture();

}