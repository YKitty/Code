#include <iostream>
#include <string>

int main()
{
  std::string str1("hello world!");
  std::string str2("I love you!");

  str1.insert(0, str2);
  std::cout << str1 << '\n';//I love you!hello world!

  str1.insert(str1.size(), str2, 0, std::string::npos);
  std::cout << str1 << '\n';//I love you!hello world!I love you!

  str1.insert(str1.size(), "haha");
  std::cout << str1 << '\n';//I love you!hello world!I love you!haha

  str2.insert(str2.size(), "haha", 2);
  std::cout << str2 << '\n';//I love you!ha

  str2.insert(str2.size(), 2, 'X');
  std::cout << str2 << '\n';//I love you!haXX

  str2.insert(str2.end(), 2, 'X');
  std::cout << str2 << '\n';//I love you!haXXXX
  std::string::iterator it = str2.insert(str2.begin() + 1, 'F');
  std::cout << *it << '\n';
  return 0;
}
