#include <iostream>

int main()
{
  std::string str1("hello");
  std::string str2(" world!");

  str1 += str2; //string
  str1 += "I come!"; //c-string 
  str1 += '\n'; //character

  std::cout << str1; 
  return 0;
}
