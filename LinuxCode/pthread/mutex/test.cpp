#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <mutex>

pthread_mutex_t _mutex;
int ticket = 2000;
//出现6的情况是这样的，有可能下面创建线程创建到第六个出错的时候，i已经变成6了，然后对于buyTicket函数再次从内存中取值的时候，所以取到的就是6了
//多个线程来的时候是对这个函数的重入
void* buyTicket(void *arg)
{
  //定义在这里的话，这个变量就不可以被共享了，也就是被每一个线程都存放在自己的运行时栈了
  //int ticket = 20;
  while (1)
  {
    usleep(1000);
    pthread_mutex_lock(&_mutex);
    if (ticket > 0)
    { 
      //挂起是为了可以让其他的线程也都运行到加锁的哪里，
      //防止该线程解锁之后，没有其他的线程，也就是该线程执行代码
      usleep(1000);
      ticket--;
      std::cout << (char*)(arg) << "buy ticket!Have Ticket:" << ticket << std::endl;
      pthread_mutex_unlock(&_mutex);
    }
    else 
    {
      pthread_mutex_unlock(&_mutex);
      break;
    }
  }
  
  return NULL;//线程结束
}

int main()
{

  pthread_mutex_init(&_mutex, NULL);
  pthread_t tid[6];
  //不能用这种方法创建，因为buyTicket读取的是地址值，就会导致，每次读取的都是最新的i值，不会看到以前的线程了
  //创建了五个子线程
  //for (int i = 1; i < 6; i++)
  //{
  //  if (pthread_create(tid + i, NULL, buyTicket, (void*)(&(i))) > 0)
  //  {
  //    std::cout << "pthread_create error!" << std::endl;
  //  }

  //  sleep(1);
  //}
  if (pthread_create(tid + 1, NULL, buyTicket, (void*)("1")) > 0)
  {
    std::cout << "pthread_create error!" << std::cout;
  }
  if (pthread_create(tid + 2, NULL, buyTicket, (void*)("2")) > 0)
  {
    std::cout << "pthread_create error!" << std::cout;
  }
  if (pthread_create(tid + 3, NULL, buyTicket, (void*)("3")) > 0)
  {
    std::cout << "pthread_create error!" << std::cout;
  }
  if (pthread_create(tid + 4, NULL, buyTicket, (void*)("4")) > 0)
  {
    std::cout << "pthread_create error!" << std::cout;
  }
  if (pthread_create(tid + 5, NULL, buyTicket, (void*)("5")) > 0)
  {
    std::cout << "pthread_create error!" << std::cout;
  }
 

  //主线程必须休眠，如果主线程不休眠的话，有可能他在新线程还没运行的时候就会退出，
  //而导致进程退出，这样新线程就没有运行的机会了（依赖于操作系统中的线程实现和调度算法）
  //sleep(1);
  for (int i = 1; i <= 5; i++)
  {
    if (pthread_join(tid[i], NULL) == 0)
    {
      std::cout << i << " thread quit!" << std::endl;
    }
    sleep(1);
  }
  pthread_mutex_destroy(&_mutex); 
  return 0;
}
  
