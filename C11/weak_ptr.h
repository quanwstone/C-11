#pragma once
#include<memory>
/*
weak_ptr��һ�ֲ����ƶ����������ڵ�����ָ��,Ϊ�����ã���Ӱ�����ü���.
Ϊ�����shared_ptr��ʹ��.weak_ptr ��ʹ��ǰ��Ҫ���Ϸ���.ͨ��lock
��ȡһ��share_ptr�Ķ���.ͨ��expired ���Լ������Ƿ��Ѿ��ͷ�.����
���ʷǷ��ڴ�.
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