#include <iostream>

int main()
{
  std::string str("hello world");
  //iterator相当于一个指针,
  for (std::string::iterator it = str.begin(); it != str.end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << '\n';
  return 0;
}
