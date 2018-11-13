#include <stdio.h>

int check(int a)
{
  //return ((*(&a)) & 0x1);
  return (*(char *)&a);
}

int main()
{
  if (check(1) == 1)
  {
    printf("该机器是小端!\n");
  }
  else
  {
    printf("该机器是大端!\n");
  }

  return 0;
}
