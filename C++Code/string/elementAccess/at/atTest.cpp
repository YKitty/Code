#include <iostream>

int main()
{
  std::string str("hello world");
  for (size_t i = 0; i <= str.size(); i++)
  {
    std::cout << str.at(i) << " ";
  }
  std::cout << '\n';

  return 0;
}
