#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

pthread_t main_tid;
int retval;


void* routine(void* arg)
{
  //设置取消状态，有可取消的，和不可取消的
  //设置为不可取消的
  //pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
  //设置为可取消的
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  //设置取消类型是异步的，也就是可以立马取消
  //pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
  //设置为默认取消类型，也就是推迟取消，必须要有取消点才可以取消
  pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
  //pthread_detach(pthread_self());//自我分离
    pthread_testcancel();
  while (1)
  {
    //pthread_testcancel();
    //nanosleep(1);
    //std::cout << (char*)arg << ":" << i <<'\n';
  }
  //pthread_exit((void*)&retval);
  return NULL;//线程终止
}

int main()
{
  void* retval;
  //main_tid = pthread_self();
  pthread_t tid;
  int ret = pthread_create(&tid, NULL, routine, (void*)("thread1"));
  if (ret > 0)
  {
    std::cout << "pthread_create error!" << '\n';
  }

  //sleep(1);
  //pthread_kill(tid, 9);
  if (pthread_cancel(tid) > 0)
  {
    std::cout << "error !" << '\n';
  }
  pthread_join(tid, &retval);
 
  //std::cout << *((int*)retval) << '\n';
  //std::cout << *((int *)retval) << '\n';
  if  ((retval) == PTHREAD_CANCELED)
  {
    std::cout << "PTHREAD_CANCELED" << '\n';
  }

  else 
  {
    std::cout << "thread return, return code:NULL" << '\n';
  }

  return 0;
}
