#include <iostream>

int main()
{
  std::string str = "hello world";
  for (std::string::reverse_iterator it = str.rbegin(); it != str.rend(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << '\n';
  return 0;
}
