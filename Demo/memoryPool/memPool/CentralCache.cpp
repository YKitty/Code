#include "CentralCache.hpp"

//对静态成员变量进行初始化
CentralCache CentralCache::_inst;

//打桩（写一段测试一段）
//从中心缓存获取一定数量的对象给thread cache，进行测试直接使用malloc进行分配
//size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num ,size_t bytes)
//{
//	//分配num个内存大小为byte的内存块
//	start = malloc(bytes * num);
//	end = (char*)start + bytes * (num - 1);
//	void* cur = start;
//
//	//将所有分配好num个内存块连接起来
//	while (cur <= end)
//	{
//		void* next = (char*)cur + bytes;
//		NEXT_OBJ(cur) = next;
//
//		cur = next;
//	}
//
//	NEXT_OBJ(end) = nullptr;
//
//	return num;
//}

Span* CentralCache::GetOneSpan(SpanList* spanlist, size_t bytes)
{
	//对于该span链表中有span不为空的span直接返回
	Span* span = spanlist->begin();
	while (span != spanlist->end())
	{
		if (span->_objlist != nullptr)
		{
			return span;
		}
		span = span->_next;
	}

	//将所有的span链表中的所有span遍历完都为空，从页缓存中申请span
}


//从中心缓存获取内存块给thread cache，中心缓存是从页缓存中申请内存（span）
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t bytes)
{
	//求出在span链表数组中的下标
	size_t index = ClassSize::Index(bytes);

	//拿出对应bytes一个span链表,并从该链表中，拿出一个span用来给thread cache进行内存分配
	SpanList* spanlist = &_spanlist[index];
	Span* span = GetOneSpan(spanlist, bytes);
	
	void* cur = span->_objlist;
	//prev是为了获得获取这个连续内存的最后一个内存块
	void* prev= cur;
	size_t fetchnum = 0;
	while (cur != nullptr && fetchnum <= num)
	{
		prev = cur;
		cur = NEXT_OBJ(cur);
		fetchnum++;
	}

	start = span->_objlist;
	//对于end是内存的最后一块，但是对于最后一块的地址存放在最后的一个内存块的前4个或者8个字节
	end = prev;

	//要将取出来的这一段连续的内存最后不需要在记录内存块
	//这是因为对于span里面有可能有多个内存块，根本就没有拿完，所以就进行赋nullptr
	NEXT_OBJ(end) = nullptr;

	//将剩下来的内存块再次链接span上
	span->_objlist = NEXT_OBJ(prev);

	span->_usecount += fetchnum;

	return fetchnum;
}