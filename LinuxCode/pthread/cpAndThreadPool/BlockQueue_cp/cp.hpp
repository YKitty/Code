#ifndef __CP_HPP__
#define __CP_HPP__ 

#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>

template <class T>
class BlockQueue
{
public:
  BlockQueue(int cap = 20)
    : _capacity(cap)
    , water_line(cap * 2 / 3)
  {
    pthread_mutex_init(&_lock, NULL);
    pthread_cond_init(&p_cond, NULL);
    pthread_cond_init(&c_cond, NULL);
  }

  ~BlockQueue()
  {
    pthread_mutex_destroy(&_lock);
    pthread_cond_destroy(&p_cond);
    pthread_cond_destroy(&c_cond);
  }

  void PushData(const T& data)
  {
    //加锁是为了对于判断的时候对于共享资源的保护
    QueueLock();
    while (isFull())
    {
      //必须先发送信号，在等待，否则的话就有可能导致
      //生产者和消费者的线程都挂起等待，没有线程运行了
      SignalConsume();
      ProductWait();
    }

    //while(IsHighWaterLine())
    //{
    //  SignalConsume();
    //  ProductWait();
    //}

    _bq.push(data);
    QueueUnLock();
  }

  void PopData(T& data)
  {
    QueueLock();
    while (isEmpty())
    {
      SignalProduct();
      ConsumeWait();
    }

    data = _bq.front();
    _bq.pop();
    QueueUnLock();
  }
private:
    void QueueLock()
    {
      pthread_mutex_lock(&_lock);
    }
    
    void QueueUnLock()
    {
      pthread_mutex_unlock(&_lock);
    }

   void ConsumeWait()
   {
     pthread_cond_wait(&c_cond, &_lock);
   }

   void ProductWait()
   {
     pthread_cond_wait(&p_cond, &_lock);
   }

   void SignalProduct()
   {
     pthread_cond_signal(&p_cond);
   }

   void SignalConsume()
   {
     pthread_cond_signal(&c_cond);
   }

   bool IsHighWaterLine()
   {
     return _bq.size() > water_line ? true : false;
   }

   bool isEmpty()
   {
     return _bq.size() == 0 ? true : false;
   }

   bool isFull()
   {
     return _bq.size() == _capacity ? true : false;
   }

private:
  std::queue<T> _bq;
  int _capacity;
  int water_line;

  pthread_mutex_t _lock;
  pthread_cond_t p_cond;//queue empty
  pthread_cond_t c_cond;//queue full
};


#endif //__CP_HPP__
