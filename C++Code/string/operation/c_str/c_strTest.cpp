#include <iostream>
#include <string>

int main()
{
  std::string str = "hello world!";
  const char* c_str = str.c_str();
  std::cout << c_str << '\n';
  return 0;
}
