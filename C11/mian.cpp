#include<stdio.h>
#include<iostream>
#include<forward_list>
#include"thread.h"
//�µı����������
typedef int Int;
using IInt = int;

/*�궨�巵�غ�������*/
const char *Func_Name()
{
	return  __func__;
}
/*forward_list,����List*/
void Forward_List()
{
	std::forward_list<int>numbers={0,1,2,4,5,4};
	numbers.remove(4);
	
	for (auto i : numbers)
		std::cout << i;
}

int main(int argc, char*argv[])
{
	/*�����������*/
	Int i = 0;
	IInt ii = 0;

	/*static_assert,����׶ξ��Ѿ��ж�*/
	//static_assert(sizeof(int)==sizeof(char),"����׶��ж�");

	/*forward_list*/
	//Forward_List();
	
	test();

	system("pause");

	return 0;
}