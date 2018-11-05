//自己实现operator new和operator delete函数

#include <cctype>
#include <iostream>
using namespace std;

void* operator new(size_t size, const char* strFileName, const char* strFuncName, size_t lineNo)
{
    void* p = ::operator new(size);//调用全局的new来进行动态内存空间的分配
    cout<<strFileName<<"--"<<lineNo<<"-- "<<strFuncName<<" new:"<<size<<" "<<p<<endl;
    return p;

}

void operator delete(void* p, const char* strFileName, const char* strFuncName, size_t lineNo)
{
    cout<<strFileName<<"--"<<lineNo<<"-- "<<strFuncName<<" delete:"<<p<<endl;
    ::operator delete(p);//调用全局的delete来进行动态内存空间的删除

}

#define _DEBUG 1
#ifdef _DEBUG
#define new new(__FILE__, __FUNCTION__, __LINE__)
#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
#endif

int main()
{
    int* p = new int;
    delete(p);
    return 0;
}


