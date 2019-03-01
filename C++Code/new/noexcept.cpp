#include <iostream>

void Exception() noexcept 
{
  throw 1;
}

int main()
{
  Exception();
  return 0;
}
