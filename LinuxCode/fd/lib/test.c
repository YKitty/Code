#include "operator.h"
#include "stdio.h"

int main()
{
  int a = 5;
  int b = 3;
  printf("%d\n", add(a, b));
  printf("%d\n", sub(a, b));
  printf("%d\n", mul(a, b));
  printf("%d\n", div(a, b));
}
