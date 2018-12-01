#include "pool.hpp"

#define count 5

int add(int x, int y)
{
  return x + y;
}

int main()
{
  ThreadPool<int> tp(count);

  tp.InitThreadPool();
  int x = 1;
  for ( ; ; )
  {
    Task t(x, x - 1, add);
    tp.addTask(t);
    x++;
    sleep(1);
  }
  return 0;
}
