#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

void headler(int signo)
{
  pid_t id;
  int Status;
  while ((id = waitpid(-1, &Status, 1)) > 0)
  {
    cout << "wait child process success,pid：" << id << endl;
  }
  //进程的退出信息
  if (Status & 0x7F)
  {
    cout << "child process abnormal quit!" << endl;
  }
  else 
  {
    cout << ((Status >> 8) & 0xFF) << endl;
  }
  cout << "child is quit!" << endl;
}


int main()
{
  signal(SIGCHLD, headler);  

  pid_t id = fork();
  if (id == 0)
  {
    cout << "child pid: " << getpid() << endl;
    sleep(3);
    exit(2);
  }
  
  while (1)
  {
    cout << "father process is doing some thing!" << endl;
    sleep(1);
  }

  return 0;
}
