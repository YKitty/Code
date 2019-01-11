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
  //sleep(2);
  //tp.stop();
  //while(1)
  //{
  //  std::cout << "yk" << std::endl;
  //  sleep(1);
  //}

  int x = 1;
  //死循环的执行任务
  for ( ; ; )
  {
    Task t(x, x - 1, add);
    tp.addTask(t);
    x++;
    sleep(1);
    if (x == 3)
    {
      tp.stop();
      break;
    }
  }



  return 0;
}
