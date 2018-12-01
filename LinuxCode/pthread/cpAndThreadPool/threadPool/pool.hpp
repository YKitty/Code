#ifndef __POOL_H__
#define __POOL_H__ 


#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <time.h>

//函数指针，参数为两个int，返回值为int
typedef int (*cal) (int, int);
class Task 
{ 
public:
  Task(int x, int y, cal _cal)
    : _x(x)
    , _y(y)
    , _handlerTask(_cal)
  {}

  ~Task()
  {
    //没有开辟什么东西，不需要进行进行清理工作
  }

  void run()
  {
    _result = _handlerTask(_x, _y);
  }
  
  void show()
  {
    std::cout << "thread:" << pthread_self() << " result:" << _result << std::endl;
  }

private:
  int _x;
  int _y;
  int _result;
  cal _handlerTask;
}; 

template <class T>
class ThreadPool
{
public:
  ThreadPool(int num)
    : _isStop(false)
    , _poolNums(num)
  {}

  ~ThreadPool()
  {
    pthread_cond_destroy(&_cond);
    pthread_mutex_destroy(&_lock);
  }

  void InitThreadPool()
  {
    pthread_cond_init(&_cond, NULL);
    pthread_mutex_init(&_lock, NULL);

	  int i = 0;
    for (; i < _poolNums; i++)
    {
      pthread_t tid;
      pthread_create(&tid, NULL, headler, (void*)this);
    }
  }

  void IdleThread()
  {
    if (_isStop)
    {
      unlock();
      _poolNums--;
      pthread_exit((void*)0);
      std::cout << "thread: " << pthread_self() << " quit!" << std::endl;
      return;
    }
    pthread_cond_wait(&_cond, &_lock);
  }

  void addTask(Task& t)
  {
    lock();
    if(_isStop)
    {
      unlock();
    }
    _taskQueue.push(t);
    noticeOneThread();
    unlock();
  }

  Task getTask()
  {
    Task t = _taskQueue.front();
    _taskQueue.pop();

    return t;
  }

  void stop()
  {
    lock();
    _isStop = true;
    unlock();

    while (_poolNums > 0)
    {
      noticeAllThread();
    }
  }

  bool isEmpty()
  {
    return _taskQueue.size() == 0 ? true : false;
  }

  void lock()
  {
    pthread_mutex_lock(&_lock);
  }

  void unlock()
  {
    pthread_mutex_unlock(&_lock);
  }

private:
  //对于类内线程调用的函数只有一个参数arg，所以不需要this这个隐含的参数，所以要加上static
  static void* headler(void* arg)
  {
    ThreadPool* tp = (ThreadPool*)arg;
    pthread_detach(pthread_self());

    for( ; ; )
    {
      tp->lock();
      while(tp->isEmpty())
      {
        tp->IdleThread();
      }

      Task t = tp->getTask();
      tp->unlock();

      t.run();
      t.show();
    }
  }

  void noticeOneThread()
  {
    pthread_cond_signal(&_cond);
  }

  void noticeAllThread()
  {
    pthread_cond_broadcast(&_cond);
  }

private:
  std::queue<Task> _taskQueue;
  int _poolNums;
  bool _isStop;

  pthread_mutex_t _lock;
  pthread_cond_t _cond;
};


#endif //__POOL_H__
