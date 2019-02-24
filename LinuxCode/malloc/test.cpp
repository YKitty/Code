#include <unistd.h>
#include <stdio.h>
#include <iostream>



void* GetCurBreakPoint()
{
  //获取系统当前的中断点
  void* last_valid_address = sbrk(0);
  //fprintf(stdout, "%p\n", last_valid_address);

  return last_valid_address;
}

int main()
{
  return 0;
}
