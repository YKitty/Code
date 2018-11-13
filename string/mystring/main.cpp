#include <iostream>
#include "mystring.h"

int main()
{
  MyString::mystring str("hello world");
  //对于"hello"这是一个operator=的重载,对于该函数调用operator之后，发现其形参是mystring& str就会到调用构造函数的隐式转换，
  //将"hello "进行隐式转换，将其转化为一个mystring& tmp对象，然后用该对象对当前对象进行赋值操作
  //解决办法：将构造函数的隐式转换开着就行了，也就是不需要增加explicit关键字
  str = "hello";
  std::cout << str << '\n';
  std::cout << "size:" << str.size() << "capacity:" << str.capacity() << '\n';

  MyString::mystring str1 = str;
  std::cout << str1 << '\n';
  std::cout << "size:" << str1.size() << "capacity:" << str1.capacity() << '\n';
  return 0;
}
