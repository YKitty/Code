#include "priorityqueue.hpp"


int main()
{
  yk::priority_queue<int, std::deque<int>, less<int> > pq;
  pq.push(1);
  pq.push(2);
  pq.push(3);
  pq.push(4);

  while (!pq.empty())
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << std::endl;

  return 0;
}
