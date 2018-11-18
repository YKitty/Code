#include <iostream>

int main()
{
  std::string str1("hello");
  std::string str2("world!I come....");

  str1.append(str2);//string
  str1.append(str2, 1, 2);//substring
  str1.append("haha");//c-string 
  str1.append("haha", 2);//buffer
  str1.append(5, 'x');//fill

  std::cout << str1 << '\n';
  std::cout << "std::string::npos = " << std::string::npos << '\n';
  return 0;
}
