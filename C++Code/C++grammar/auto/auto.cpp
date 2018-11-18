#include <iostream>
#include <typeinfo>
using namespace std;

int TestAuto()
{
  return 10;
}

class Test 
{
public:
  Test (int a = 0)
    : _a(a)
  {}

private:
  int _a = 1;//c++11支持非静态成员变量的初始化
};

int main()
{
  int a = 10;
  auto b = a;
  auto c = 'a';
  auto d = TestAuto();
  Test e;
  //auto f = e;//支持对于一个参数的构造函数的隐式转换
  
  cout << typeid(b).name() << endl;
  cout << typeid(c).name() << endl;
  cout << typeid(d).name() << endl;

  cout << typeid(e).name() << endl;//引用类型，运行时候
  //cout << typeid(d).name() << endl;

  //auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化

  return 0;
}
