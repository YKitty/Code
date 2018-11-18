#include <iostream>

int main()
{
  std::string context;
  std::string line;
  do
  {
    getline(std::cin, line);
    context += line + '\n';
  }while (!line.empty());//直到line为空
  std::cout << context;
  return 0;
}
