#include <iostream>

int main()
{
  std::string str1("hello world");//11
  std::string str2("hello world");
  std::string str3("hello world");
  
  std::cout << str1 << '\n';
  str1.resize(3);
  std::cout << str1 << '\n';

  std::cout << str2 << '\n';
  str2.resize(15);
  std::cout << str2 << '\n';

  std::cout << str3 << '\n';
  str3.resize(15, 'h');
  std::cout << str3 << '\n';

  return 0;
}
