#include <iostream>
#include <string>

int main()
{
  std::string str1("hello world!");
  std::string str2("hellok world!");
  std::string str3("hellok world!");
  
  std::cout << str1 << '\n';
  str1.erase();//默认删除全部，因为该成员函数是一个缺省函数
  std::cout << str1 << '\n';

  str2.erase(0, 1);//ellok world!
  std::cout << str2 << '\n';

  std::string::iterator it = str2.erase(str2.begin() + 3);
  std::cout << "*it: "<< *it << '\n' << "str2: " << str2 << '\n';//k  ellk world!

  str3.erase(str3.begin() + 1, str3.begin() + 5);
  std::cout << str3 << '\n';//h world!


  return 0;
}
