#include <iostream>

void Test(const int& i)
{
  int a=10;
  int  const *p=&a;
  *p=20;
  p=NULL;
  //std::cin >> i;
  //std::cout << i;
}

int main()
{
  int i = 10;

//  scanf("%d",&i);
//  printf("%d\n", i);
//
  Test(i);
  return 0;
}

