#include <iostream>

int main()
{
  std::string str("hello world");
  std::cout << str << '\n';
  str.clear();
  std::cout << str << '\n';
  return 0;
}
