#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* routine(void* arg)
{
  pthread_detach(pthread_self());
  std::cout << (char*)arg << '\n';
  return NULL;
}

int main()
{
  pthread_t tid;
  if (pthread_create(&tid, NULL, routine, (void*)("thread 1")) > 0)
  {
    std::cout << "pthread_create error!" << '\n';
  }
  sleep(1);

  int ret = 0;
  if (pthread_join(tid, NULL) == 0)
  {
    std::cout << "wait success!" << '\n';
  }
  else 
  {
    std::cout << "waiting error!" << '\n';
    ret = 1;
  }
  

  return ret;
}
