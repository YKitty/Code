//C++11的非静态成员变量可以在初始化的时候直接进行初始化

#include <stdlib.h>
#include <iostream>
using namespace std;

class B
{
public:
  B (int b = 0)//初始化构造函数
    : _b(b)
  {}

  int _b;
};

class A
{
public:
  void Print()
  {
    cout << a << endl;
    cout << b._b << endl;
    cout << p << endl;
  }

private:
  //非静态成员变量，可以再成员声明时，直接初始化
  int a = 10;
  B b = 20;//具有单个参数的构造函数，可以进行隐式转换
  int* p = (int*)malloc(4);
  static int n;
};

int A::n = 30;//静态成员变量只能在类外进行初始化

int main()
{
  A a;
  a.Print();
  return 0;
}
