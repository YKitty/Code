#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

//signo表示要处理的信号编号，执行用户自定义的函数，对于捕捉到该信号
void handler(int signo)
{
  cout << "catch 1 signal. signo: " << signo << "pid: " << getpid() << endl;
}

int main()
{
  
  //对于信号SIGINT，进行忽略,ignore
  //忽略也就是接收到信号，但是信号递达的时候，不做任何处理
  //signal(SIGINT, SIG_IGN);
  
  //对信号SIGINT进行默认处理,default
  //一般情况下，默认处理都是终止该进程
  //signal(SIGINT, SIG_DFL);
  
  signal(SIGINT, handler);

  while(1)
  {
    cout << "pid: " << getpid() << endl;
    cout << "SIGINT not work!" << endl;
    sleep(1);
  }
  return 0;
}


