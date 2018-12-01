#ifndef __CP_HPP__
#define __CP_HPP__ 

#include <iostream>
#include <pthread.h>
#include <vector>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

template <class T>
class RingQueue 
{
public:
  RingQueue(const int& cap)
    : _capacity(cap)
    , _rq(cap)
  {
    p_step = c_step = 0;
    //0表示线程间共享，cap表示创建几个共享资源
    sem_init(&block_sem, 0, cap);
    sem_init(&data_sem, 0, 0);
  }

  ~RingQueue()
  {
    sem_destroy(&block_sem);
    sem_destroy(&data_sem);
  }

  void PushData(const T& data)
  {
    P(block_sem);
    _rq[p_step] = data;
    std::cout << "product data: " << data << std::endl;
    V(data_sem);
    p_step++;
    p_step %= _capacity;
  }

  void PopData(T& data)
  {
    P(data_sem);
    data = _rq[c_step];
    std::cout << "consume data: " << data << std::endl;
    V(block_sem);
    c_step++;
    c_step %= _capacity;
  }

private:
  void P(sem_t& sem)
  {
    sem_wait(&sem);
  }

  void V(sem_t& sem)
  {
    sem_post(&sem);
  }

private:
  std::vector<T> _rq;
  int _capacity;

  sem_t block_sem;
  sem_t data_sem;
  int c_step;
  int p_step;
};


#endif //__CP_HPP__
