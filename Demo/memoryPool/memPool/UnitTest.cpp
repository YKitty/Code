#include "Common.hpp"
#include "ConcurrentAlloc.hpp"

/*
	tls(thread local storage)线程本地存储
*/
void TestThreadCache()
{
	//测试不同线程对于tls的效果，也就是对于tls每一个线程都有着自己一个
	//std::thread tl(ConcurrentAlloc, 10);
	//std::thread t2(ConcurrentAlloc, 10);

	//tl.join();
	//t2.join();

	//测试申请内存
	//ConcurrentAlloc(10);


	std::vector<void*> v;
	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(ConcurrentAlloc(10));
		std::cout << v.back() << std::endl;
	}
	std::cout << std::endl << std::endl;

	for (size_t i = 0; i < 10; ++i)
	{
		ConcurrentFree(v[i], 10);
	}
	v.clear();

	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(ConcurrentAlloc(10));
		std::cout << v.back() << std::endl;
	}

	for (size_t i = 0; i < 10; ++i)
	{
		ConcurrentFree(v[i], 10);
	}
	v.clear();
}


int main()
{
	TestThreadCache();
	return 0;
}