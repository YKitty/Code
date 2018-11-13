//常引用

#include <iostream>
using namespace std;

class Test
{
public:
  void TestFunc()
  {
    const int a = 10;
    //int& ra = a;
    const int& ra = a;//引用类型要匹配
  }
};

int main()
{
  Test t;
  t.TestFunc();
  return 0;
}
