#include <iostream>
#include <array>

int main()
{
  std::array<int, 4> array = { 1, 2 , 3, 4 };
  for (auto e : array)
  {
    std::cout << e <<std::endl;
  }

  int array_size = sizeof(array);
  std::cout << array_size << std::endl;
  return 0;
}
