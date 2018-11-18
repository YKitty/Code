#include <iostream>

int main()
{
  std::string str1("hello world");
  std::string str2("hello world");
  std::string str3("hello world");
 
  std::cout << str1 << '\n';
  std::cout << "the capacity of str1: " << str1.capacity() << '\n';
  str1.reserve(4);
  std::cout << str1 << '\n';
  std::cout << "the capacity of str1: " << str1.capacity() << '\n';
  
  std::cout << str2 << '\n';
  std::cout << "the capacity of str2: " << str2.capacity() << '\n';
  str2.reserve(20);
  std::cout << str2 << '\n';
  std::cout << "the capacity of str2: " << str2.capacity() << '\n';
  
  
  return 0;
}
