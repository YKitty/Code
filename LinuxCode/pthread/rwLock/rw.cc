#include <iostream>
#include <pthread.h>
#include <unistd.h>

int book = 0;
pthread_rwlock_t rwlock;


void* read(void* arg)
{
  while(1)
  {
    pthread_rwlock_rdlock(&rwlock);
    std::cout << "thread: " << pthread_self() <<  "read:" << book << std::endl;
    pthread_rwlock_unlock(&rwlock);
    usleep(300000);
  }
}

void* write(void* arg)
{
  while(1)
  {
    pthread_rwlock_wrlock(&rwlock);
    std::cout << "thread: " << pthread_self() <<  "write:" << ++book << std::endl;
    pthread_rwlock_unlock(&rwlock);
    sleep(1);
  }
}

int main()
{
  pthread_rwlock_init(&rwlock, NULL);
  pthread_t r[5], w[3];

  for (int i = 0; i < 3; i++)
  {
    pthread_create(&w[i], NULL, write, NULL);
  }
  
  for (int i = 0; i < 5; i++)
  {
    pthread_create(&r[i], NULL, read, NULL);
  }

  for (int i = 0; i < 3; i++)
  {
    pthread_join(w[i], NULL);
  }
  
  for (int i = 0; i < 5; i++)
  {
    pthread_join(r[i], NULL);
  }


  pthread_rwlock_destroy(&rwlock);
  return 0;
}
