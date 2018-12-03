#include "queue.hpp"

int main()
{
  yk::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  
  std::cout << q.back() << std::endl;
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
  return 0;
}

