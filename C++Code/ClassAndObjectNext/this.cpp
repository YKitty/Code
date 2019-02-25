#include <iostream>
#include <stdio.h>

class A
{
public:
  A(int a = 0)
    : _num(a)
  {
    std::cout << "In A()" << std::endl;
  }

  ~A()
  {
    std::cout << "In ~A()" << std::endl;
  }

  void Print()
  {
    fprintf(stdout, "this: %p\n", this);
  }
  
  static void Show()
  {
    std::cout << "In Show()" << std::endl;
  }

private:
  int _num;
};

int main()
{
  A a;
  fprintf(stdout, "a address:%p\n", &a);
  a.Print();
  a.Show();
  return 0;
}
//可以看到this指针就是对象的地址，所以this指针只是在传递的时候，隐式的将对象的地址传给成员函数的第一个参数this
//In A()
//a address:0x7ffd76c20e30
//this: 0x7ffd76c20e30
//In ~A()
