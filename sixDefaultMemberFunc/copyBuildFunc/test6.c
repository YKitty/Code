//测试const修饰的变量

#include <iostream>

int main()
{
  const int a = 10;
  //a = 10, //该语句编译会失败，常量不能修改
  
  int* pa = (int*)&a;
  *pa = 100;

  std::cout << *pa << std::endl;
  std::cout << a << std::endl;

  return 0;
}
