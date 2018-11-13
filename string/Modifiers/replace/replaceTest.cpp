#include <iostream>
#include <string>


int main()
{
  std::string str1("hello world!");
  std::string str2("replace str!");
  std::string str3("replace str1!");
  std::string str4("replace str2!");
  std::string str5("replace str3!");
  
  //string
  str1.replace(0, 1, str2);
  std::cout << str1 << '\n';//replace str!ello world!
  str1.replace(str1.begin(), str1.begin() + 15, str2);
  std::cout << str1 << '\n';//replace str!o world!

  //substring 
  str2.replace(0, 1, str3, 0, 5);
  std::cout << str2 << '\n';//replaeplace str!

  //c-string 
  str3.replace(0, 1, "haha");
  std::cout << str3 << '\n';//hahaeplace str1!
  str3.replace(str3.begin(), str3.begin() + 10, "haha");
  std::cout << str3 << '\n';//haha str1!

  //buffer
  str4.replace(0, 1, "haha", 2);
  std::cout << str4 << '\n';//haeplace str2!
  str4.replace(str4.begin(), str4.begin() + 8, "haha", 4);
  std::cout << str4 << '\n';//haha str2!

  //fill
  str5.replace(0, 1, 5, 'X');
  std::cout << str5 << '\n';//XXXXXeplace str3!
  str5.replace(0, 11, 11, 'A');
  std::cout << str5 << '\n';//AAAAAAAAAAA str3!

  return 0;
}
