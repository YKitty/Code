#include <iostream>
#include <string>

int main()
{
  std::string str1("the people is super people...");
  std::string str2("people");

  size_t find = str1.rfind(str2, str1.size());
  if (find != std::string::npos)
  {
    std::cout << "str2:people find!Index in " << find << '\n';
    str1.replace(find, str2.size(), "man");
    std::cout << str1 << '\n';
  }

  return 0;
}
