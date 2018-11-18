#include <iostream>
#include <stddef.h>

using namespace std;

class A1
{
public:
  void func1( )
  {
    cout << "in func1" << endl;
    cout << _a << endl;
  }

  void func2()
  {
    cout << "in func2" << endl;
  }
public:
  char _c;
  int _a;
  int _b;
};

class A2
{
public:
  void func1()
  {

  }
};

class A3 
{
};

int main()
{
  //cout << offsetof(A1, A1::_b) << endl;
  //cout << sizeof(A1) << "--" << sizeof(A2) << "--" << sizeof(A3) << endl;
  //std::cout << "hello yk!" << std::endl;
  A1* a = NULL;
  a->func1();
  a->func2();
  return 0;
}
