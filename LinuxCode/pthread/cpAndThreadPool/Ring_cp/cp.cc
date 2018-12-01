#include "cp.hpp"

#define capacity 10

void* consume(void* arg)
{
  RingQueue<int>* _rq = (RingQueue<int>*)arg;
  int data;
  for ( ; ; )
  {
    _rq->PopData(data);
  }
}

void* product(void* arg)
{
  RingQueue<int>* _rq = (RingQueue<int>*)arg;
  srand((unsigned)time(NULL));
  for ( ; ; )
  {
    int data = rand() % 100 + 1;
    _rq->PushData(data);
    //sleep(1);
  }
}

int main()
{
  RingQueue<int>* _rq = new RingQueue<int>(capacity);
  
  pthread_t c, p;
  pthread_create(&c, NULL, consume, (void*)_rq);
  pthread_create(&p, NULL, product, (void*)_rq);

  pthread_join(c, NULL);
  pthread_join(p, NULL);

  return 0;
}
