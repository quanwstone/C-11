#pragma once
/*shared_ptr在互相引用为强引用,引用计数会修改，有时指针不会释放.*/
#include<memory>

class shared_testB;

class shared_testA{
public:
	shared_testA() 
	{

	}
	void Release(std::shared_ptr<shared_testB>shared)
	{
		m_shared = shared;
	}
	~shared_testA() 
	{
		printf("destruct in shared_testA.");
	}
public:
	std::shared_ptr<shared_testB>m_shared;
};
class shared_testB {
public:
	shared_testB() {}
	~shared_testB() 
	{
		printf("destruct in shared_testB.");
	}

	void Release(std::shared_ptr<shared_testA>shared)
	{
		m_shared = shared;
	}
public:
	std::shared_ptr<shared_testA>m_shared;
};
static void test()
{
	std::shared_ptr<shared_testA>sharedA = std::make_shared<shared_testA>();
	std::shared_ptr<shared_testB>sharedB = std::make_shared<shared_testB>();

	sharedA->Release(sharedB);
	sharedB->Release(sharedA);
	
	printf("Test_shared sharedB=%d\n", sharedB.use_count());
}