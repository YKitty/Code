//定位new表达式

#include <cstdlib>
#include <iostream>
using namespace std;

class Test
{
public:
  Test (int a = 0)
    : _data(a)
  {
    cout << _data << "Test():" << this << endl;
  }

  ~Test ()
  {
    cout << "~Test():" << this << endl;
  }

private:
  int _data;
};

int main()
{
  Test* ptr = (Test*)malloc(sizeof(Test));
  
  //定位new表达式,调用Test构造函数
  new(ptr)Test(13);
  
  return 0;
}
