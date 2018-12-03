/*
 * 对于进程组以及作业的区别
 * 如果作业中的某个进程创建了一个进程那么该进程不属于这个作业，属于进程组
*/
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  int i = 5;
  pid_t id = fork();
  if (id < 0)
  {
    std::cout << "fork error!" << std::endl;
  }
  else if (id > 0)//parent
  {
    while (i > 0)
    {
      std::cout << "parent running..." << std::endl;
      i--;
      sleep(1);
    }
    exit(0);
  }
  else 
  {
    while (1)
    {
      std::cout << "child running..." << std::endl;
      sleep(1);
    }
  }
  return 0;
}
