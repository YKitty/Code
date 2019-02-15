#pragma once
#include "Common.hpp"
#include "ThreadCache.hpp"

void* ConcurrentAlloc(size_t size)
{
	if (size > MAXBYTES)
	{
		//大于64K直接malloc
		return malloc(size);
	}
	//在64K之内直接在线程缓存中申请内存
	else
	{
		//通过tls，获取线程自己的tls
		if (tls_threadcache == nullptr)
		{
			tls_threadcache = new ThreadCache;
			//std::cout << std::this_thread::get_id() << "->"  << tls_threadcache << std::endl;
			//std::cout << tls_threadcache << std::endl;
		}

		//返回获取的内存块的地址
		return tls_threadcache->Allocate(size);
		//return nullptr;
	}
}

//将获取到的内存块归还给自由链表
void ConcurrentFree(void* ptr, size_t size)
{
	if (size > MAXBYTES)
	{
		return free(ptr);
	}
	else
	{
		return tls_threadcache->Deallocate(ptr, size);
	}
}