#include <iostream>
#include <string>

int main()
{
  std::string str1("Everyone is very very perfect,Do you know?");
  std::string str2("Do");
  std::string str3("DO");

  //string
  size_t find = str1.find(str2, 0);
  if (find != std::string::npos)
  {
    std::cout << "str2:Do find!Index is " << find << '\n';
  }

  //c-string 
  find = str1.find("very", 17);
  if (find != std::string::npos)
  {
    std::cout << "very find!Index is " << find << '\n';
  }


  //buffer
  find = str1.find("perfect", 15, 2);
  if (find != std::string::npos)
  {
    std::cout << "pe find!Index is " << find << '\n';
  }

  //character
  find = str1.find('e', 0);
  if (find != std::string::npos)
  {
    std::cout << "e find!Index is " << find << '\n';
  }

  return 0;
}
