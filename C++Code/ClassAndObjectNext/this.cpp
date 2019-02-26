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

  A(const A& a)
  {
    std::cout << "In A(const A&)" << std::endl;
    _num = a._num;
    //对于this不可赋值说明对于this，是一个const类型的变量;
    //this = &a;
  }

  ~A()
  {
    std::cout << "In ~A()" << std::endl;
  }

  void Print()
  {
    fprintf(stdout, "this: %p\n", this);
    //将会出错，this指针可以为空，但是当this指针为空的时候，在这个成员函数中就不可以使用this指针来进行成员变量的访问
    std::cout << _num << std::endl;
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
  A* p = NULL;
  p->Print();
  p->Show();
  //A a;
  //A b(a);
  //fprintf(stdout, "a address:%p\n", &a);
  //a.Print();
  //a.Show();
  return 0;
}
//可以看到this指针就是对象的地址，所以this指针只是在传递的时候，隐式的将对象的地址传给成员函数的第一个参数this
//In A()
//a address:0x7ffd76c20e30
//this: 0x7ffd76c20e30
//In ~A()
