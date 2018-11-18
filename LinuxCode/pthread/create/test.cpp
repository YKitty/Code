#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>

void* routine(void* arg)
{
  while (1)
  {
    std::cout << "I am child " << (char*)arg << '\n';
    sleep(1);
  }
}

int main()
{
  pthread_t tid;
  int ret = 0;
  if ((ret = pthread_create(&tid, NULL, routine, (void*)"thread!")) != 0)
  {
    std::cout << "pthread_create  error" << '\n';
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    std::cout << "I am main pthread!" << '\n';
    sleep(1);
  }

  return 0;
}

