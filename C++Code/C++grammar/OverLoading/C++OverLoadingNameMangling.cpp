#include <iostream>
using namespace std;

class Test
{
public:
  Test (int a = 10)//构造函数
  {
    _a = a;
  }

  Test (const Test& d)//拷贝构造函数
  {
    _a = d._a;
  }

  void TestFunc(int a = 1);
  void TestFunc(char b = 1.0);
  void TestFunc(long a = 0);
  
private:
  int _a;
};

int main()
{
  Test t;
  t.TestFunc(1);
  t.TestFunc(1);
  t.TestFunc(1L);
  return 0;
}
