#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void mydaemon()
{
  umask(0); //将掩码改为0，为了该守护进程创建文件的时候可以有权限
  
  pid_t id = fork();
  if (id > 0)
  {
    //parent
    exit(0);   
  }

  //接下来所有事情都是子进程做的
  setsid(); //调用setsid创建一个新的会话
  signal(SIGCHLD, SIG_IGN);//忽略SIGCHLD信号

  if (chdir("/") < 0)
  {
    std::cout << "child dir error!" << std::endl;
    return;
  }

  //关闭不在需要的文件描述符，或者重定向到/dev/null
  close(0);
  close(1);
  close(2);
}

int main()
{
  mydaemon();
  while (1)
  {
    sleep(1);
  }
  return 0;
}
