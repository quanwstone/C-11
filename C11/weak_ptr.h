#pragma once
#include<memory>
/*
weak_ptr是一种不控制对象生命周期的智能指针,为弱引用，不影响引用计数.
为了配合shared_ptr的使用.weak_ptr 在使用前需要检查合法性.通过lock
获取一个share_ptr的对象.通过expired 可以检测对象是否已经释放.避免
访问非法内存.
*/
class weak_testB;

class weak_testA {
public:
	weak_testA()
	{

	}
	void Release(std::shared_ptr<weak_testB>shared)
	{
		m_shared = shared;
	}
	~weak_testA()
	{
		printf("destruct in weak_testA.\n");
	}
public:
	std::weak_ptr<weak_testB>m_shared;
};
class weak_testB {
public:
	weak_testB() {}
	~weak_testB()
	{
		printf("destruct in weak_testB.\n");
	}

	void Release(std::shared_ptr<weak_testA>shared)
	{
		m_shared = shared;

	}
public:
	std::weak_ptr<weak_testA>m_shared;
};
static void test_weak()
{
	std::shared_ptr<weak_testA>sharedA = std::make_shared<weak_testA>();
	std::shared_ptr<weak_testB>sharedB = std::make_shared<weak_testB>();

	sharedA->Release(sharedB);
	sharedB->Release(sharedA);

	printf("Test_weak sharedB=%d\n", sharedB.use_count());
}