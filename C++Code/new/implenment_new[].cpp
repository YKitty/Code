#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class A 
{
public:
  A(int a = 0)
    : _num(a)
  {
    std::cout << "In A()" << std::endl;
  }

  ~A() 
  {
    std::cout << "In ~A()" << std::endl;
  }

//private:
  int _num;
};

int main()
{
  //在调用new[]的时候会多开辟4字节来存储，开辟对象的个数
  //operator new[]() -> malloc() -> constructor -> ptr
  A* a = new A[10]; 

  //destrutor -> operator delete[]() -> free()
  delete[] a;
  //A* p = (A*)malloc(sizeof(A));
  //new(p)A();
  //fprintf(stdout, "use new()A()");
  //p->~A();
  //free(p);

  //A* pa = (A*)malloc(sizeof(A) * 10);
  //for (int i = 0; i < 10; i++)
  //{
  //  new(pa + i) A(i);
  //}

  //for (int i = 0; i < 10; i++)
  //{
  //  std::cout << pa[i]._num << std::endl;
  //}

  //for (int i = 0; i < 10; i++)
  //{
  //  (pa + i)->~A();
  //}
  //
  //free(pa);
  return 0;
}
