#pragma once
/*
delete ��default��ʹ�ã�
delete�������κκ��������������������Ա������
��������Ҳ���Թ��˵�һЩ.
������ģ��������
*/
namespace delete_h {

	template<typename T>
	class CNxTemplate
	{
	public:
		void TFunc(T *num) {};
	};
	template<>
	class CNxTemplate<int>
	{
	public:
		void TFunc(int *num) = delete;
	};
	
	void Test(int num) {};

	void Test(char str) = delete;

	//c++98
	class CNxBase 
	{
	public:
		CNxBase() {};
		~CNxBase() {};
		CNxBase(const CNxBase&) = delete;//
		CNxBase & operator = (CNxBase &) {};
	};
	//c++98 ���ܿ�������
	class CNxDontCopyBase
	{
	public:
		CNxDontCopyBase() {};
		~CNxDontCopyBase() {};
	private:
		CNxDontCopyBase(const CNxDontCopyBase&) {};
		CNxDontCopyBase & operator = (CNxDontCopyBase &) {};
	};
	//c++11
	/*
	�ƶ����캯���ĵ��ã��뿽�����ƣ��ƶ�Ҳʹ��һ�������ֵ������һ�������ֵ�����ǣ�����
	������ͬ���ǣ��ƶ�ʵ�ֵ��Ƕ�����ʵ��ת�ƣ��ƶ������ķ����ǵ��ƶ�������δ�����Ķ����ʱ��
	������ʱ���������纯������ֵ��
	CNx11Base Func(){};
	CNx11Base cb = Func������//��ʱ���ǵ������ƶ����캯��
	*/
	class CNx11Base
	{
	public:
		CNx11Base() = default;
		~CNx11Base() = default;

		CNx11Base(const CNx11Base&) = delete;
		CNx11Base & operator = (CNx11Base &) = delete;

		CNx11Base(const CNx11Base &&) {};//�ƶ����캯��
		CNx11Base && operator = (CNx11Base &&) {};//�ƶ���ֵ����
		
	};
}

void test()
{
	delete_h::CNxTemplate<int>Tm;
	int num = 0;

	Tm.TFunc(&num);//����ʱ����ʾɾ������.

	delete_h::CNxBase nm;
	delete_h::CNxBase nn(nm);//����ʱ�ھͻ���ʾ���ɿ���

	delete_h::CNxDontCopyBase m;
	delete_h::CNxDontCopyBase n(m);//����ʱ�ھͻ���ʾ���ɿ���

}