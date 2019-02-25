#include <iostream>
#include <stdlib.h>

class A 
{
public:
  A(int a = 0)
    : _num(a)
  {}

  ~A() 
  {
    std::cout << _num << std::endl;
  }

//private:
  int _num;
};

int main()
{
  A* pa = (A*)malloc(sizeof(A) * 10);
  for (int i = 0; i < 10; i++)
  {
    new(pa + i) A(i);
  }

  for (int i = 0; i < 10; i++)
  {
    std::cout << pa[i]._num << std::endl;
  }

  for (int i = 0; i < 10; i++)
  {
    (pa + i)->~A();
  }
  
  free(pa);
  return 0;
}
