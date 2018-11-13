//内部类

#include <iostream>
using namespace std;

class A
{
public:
  class B//内部类，可以访问外部类的所有成员
  {
  public:
    void Print(const A& a)
    {
      cout << _k << endl;
      cout << a._a << endl;
    }
  };

private:
  static int _k;
  int _a = 2;//对于非静态成员初始化只在c++11中可以使用，需要加上-std=c++11
};

int A::_k = 1;

int main()
{
  A::B b;
  A a;
  b.Print(a);
  return 0;
}
