#include "ThreadCache.hpp"
#include "CentralCache.hpp"

//从中心缓存拿取数据
void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	//拿取的内存放在这个自由链表上
	FreeList* freelist = &_freelist[index];

	//每次从中心缓存取出10个这样大小的内存块
	size_t num = 10;

	//start，end分别表示取出来的内存的开始地址和结束地址
	//取出来的内存是一个连续的内存
	void* start, *end;

	//fetchnum表示实际取出来的内存的个数，fetchnum有可能小于num，表示中心缓存没有那么多大小的内存块
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, byte);
	if (fetchnum == 1)
	{
		return start;
	}

	//只给自由链表中放入(fetchnum - 1)个内存块，这是因为第一个内存块已经被使用了
	freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
	return start;
}

//从自由链表数组的自由链表上拿取内存
void* ThreadCache::Allocate(size_t size)
{
	assert(size < MAXBYTES);
	//size是要拿取多少个字节的内存
	size = ClassSize::RoundUp(size);
	//index是自由链表的数组的下标
	size_t index = ClassSize::Index(size);

	//可以确定要拿取的size是处于自由链表数组的哪一个自由链表
	FreeList* freelist = &_freelist[index];

	//判断链表是否为空
	//不为空，直接取内存
	if (!freelist->Empty())
	{
		//也就是从自由链表中拿内存
		return freelist->Pop();
	}
	//自由链表是空的要从中心堆中拿取内存，一次取多个防止重复取
	else 
	{
		return FetchFromCentralCache(index, size);
	}
}

//向自由链表的数组中的自由链表归还内存
void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(size < MAXBYTES);
	size_t index = ClassSize::Index(size);

	FreeList* freelist = &_freelist[index];

	freelist->Push(ptr);
}
