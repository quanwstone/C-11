#include<stdio.h>
#include<iostream>
#include<forward_list>
#include"thread.h"
//新的别名定义机制
typedef int Int;
using IInt = int;

/*宏定义返回函数名称*/
const char *Func_Name()
{
	return  __func__;
}
/*forward_list,单向List*/
void Forward_List()
{
	std::forward_list<int>numbers={0,1,2,4,5,4};
	numbers.remove(4);
	
	for (auto i : numbers)
		std::cout << i;
}

int main(int argc, char*argv[])
{
	/*别名定义机制*/
	Int i = 0;
	IInt ii = 0;

	/*static_assert,编译阶段就已经判断*/
	//static_assert(sizeof(int)==sizeof(char),"编译阶段判断");

	/*forward_list*/
	//Forward_List();
	
	test();

	system("pause");

	return 0;
}