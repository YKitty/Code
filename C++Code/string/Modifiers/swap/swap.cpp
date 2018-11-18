#include <iostream>
#include <string>

int main()
{
  std::string str1("hello");
  std::string str2("nihao");

  std::cout << "str1:" << str1 << '\n';
  std::cout << "str2:" << str2 << '\n';
  str1.swap(str2);
  std::cout << "str1:" << str1 << '\n';
  std::cout << "str2:" << str2 << '\n';
  return 0;
}
