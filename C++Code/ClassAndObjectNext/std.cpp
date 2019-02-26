#include <iostream>

#define MAX 5

class A
{
public:
  A()
  {
    std::cout << "In A()" << std::endl;
  }

  void inline Show()
  {
    std::cout << "In Show()" << std::endl;
  }

private:
  int _num;
  char _c;
};

class B
{
public:
  void Fun()
  {
    std::cout << "In Func()" << std::endl;
  }
};

class C
{};

int main()
{
  //对于类的大小只是成员变量的大小
  std::cout << sizeof(A) << std::endl;
  std::cout << sizeof(B) << std::endl;
  std::cout << sizeof(C) << std::endl;
  //A a;
  //a.Show();
  ////hahahha
  //std::cout << MAX << std::endl;
  return 0;
}
