#include "cp.hpp"

#define num 10

void* consume(void* arg)
{
  BlockQueue<int>* _bq = (BlockQueue<int>*)arg;
  int data;
  for( ; ; )
  {
    _bq->PopData(data);
    std::cout << "consume data: " << data << std::endl;
    usleep(200000);
  }
}

void* product(void* arg)
{
  BlockQueue<int>* _bq = (BlockQueue<int>*)arg;
  srand((unsigned)time(NULL));
  for( ; ; )
  {
    int data = rand() % 100 + 1;
    _bq->PushData(data);
    std::cout << "product data: " << data << std::endl;
    //对于让生产者一个一个的生产的话，有可能导致生产者挂起，然后消费者读取数据，导致生产者生产一个消费者就消费了
    usleep(200000);
  }
}

int main()
{
  BlockQueue<int>* _bq = new BlockQueue<int>(num);
  pthread_t c, p;
  pthread_create(&c, NULL, consume, (void*)_bq);
  pthread_create(&p, NULL, product, (void*)_bq);

  pthread_join(c, NULL);
  pthread_join(p, NULL);

  return 0;
}
