#include <iostream>
#include <string>

int main()
{
  std::string str1("hello world!");
  std::string str2("I love you!");

  str1.assign(str2);
  std::cout << str1 << '\n';//I love you!

  str1.assign(str1, 0, 5);
  std::cout << str1 << '\n';//I lov

  str1.assign("hello world!");
  std::cout << str1 << '\n';//hello world!

  str1.assign("hello world!", 5);
  std::cout << str1 << '\n';//hello

  str1.assign(10, 'h');
  std::cout << str1 << '\n';//hhhhhhhhhh

  return 0;
}
