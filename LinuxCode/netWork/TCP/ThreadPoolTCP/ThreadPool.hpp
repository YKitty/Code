#pragma once 

#include <pthread.h>
#include <iostream>
#include <queue>
#include <functional>

//typedef std::function< void(int)> Handler;//该函数指针是为了进行通信，已经连接好了

typedef void (*Handler) (int);
class Task 
{
private: 
  Handler handler;
  int sock;

public:
  Task(int sock_, Handler handler_)
    : handler(handler_)
    , sock(sock_)
  {}

  void run()
  {
    handler(sock);
  }

  ~Task()
  {}
};

class Pool
{
private:
  std::queue<Task> task_queue;
  int thread_nums;
  pthread_mutex_t lock;
  pthread_cond_t cond;

public:
  Pool(int thread_nums_)
    : thread_nums(thread_nums_)
  {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
  }

  ~Pool()
  {
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
  }

  void InitPool()
  {
    pthread_t tid;
    for (int i = 0; i < thread_nums; i++)
    {
      pthread_create(&tid, NULL, ThreadRoutine, (void*)this);
    }
  }

  void AddTask(Task& task_)
  {
    LockQueue();
    task_queue.push(task_);
    NoticeOneThread();
    UnlockQueue();
  }

private:
  void LockQueue()
  {
    pthread_mutex_lock(&lock);
  }

  void UnlockQueue()
  {
    pthread_mutex_unlock(&lock);
  }

  void NoticeOneThread()
  {
    pthread_cond_signal(&cond);
  }

  void NoticeAllThread()
  {
    pthread_cond_broadcast(&cond);
  }

  bool IsEmpty()
  {
    return task_queue.size() == 0;
  }

  void IdleThread()
  {
    pthread_cond_wait(&cond, &lock);
  }
  
  Task GetTask()
  {
    Task t = task_queue.front();
    task_queue.pop();

    return t;
  }

  static void* ThreadRoutine(void* arg)
  {
    Pool* p = (Pool*)arg;
    pthread_detach(pthread_self());
    for ( ; ; )
    {
      p->LockQueue();
      while(p->IsEmpty())
      {
        p->IdleThread();
      }

      Task t = p->GetTask();
      p->UnlockQueue();
      t.run();//必须要在外面执行任务，否则就没有多线程的优点了，变成了串行执行
    }

    return NULL;
  }
};
