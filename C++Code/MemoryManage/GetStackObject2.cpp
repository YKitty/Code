//只能从栈上开辟对象

#include <iostream>
using namespace std;

class StackType
{
public:
  //不封构造函数
  StackType ()
  {

  }

  void Print ()
  {
    cout << "Print():" << this << endl;
  }

private:
  //为该类定制一个operator new和operator delete
  void* operator new (size_t size) = delete;
  void operator delete (void* p) = delete;
};

int main()
{
  
  StackType obj;//将匿名对象给一个对象
  obj.Print();

  return 0;
}
