#include <iostream>

double Division(int x, int y) throw(const char*)
{
  if (y == 0)
  {
    throw "Division by zero condition!";
  }
  return (double)x / (double)y;
}

void Func()
{
  int x;
  int y;
  std::cin >> x >> y;
  std::cout << Division(x, y) << std::endl;
}

int main()
{
  try 
  {
    Func();
  }
  catch (const char* errmsg)
  {
    std::cout << errmsg << std::endl;
  }
  catch (...)
  {
    std::cout << "unkown " << std::endl;
  }

  return 0;
}
