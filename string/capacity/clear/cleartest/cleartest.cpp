#include <iostream>

int main()
{
  char c;
  std::string str;
  do 
  {
    c = std::cin.get();
    str += c;
    if (c == '\n')
    {
      std::cout << str;
      str.clear();
    }
  }while (c != '.');
  return 0;
}
