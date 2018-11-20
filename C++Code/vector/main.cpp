#include "vector.h"

void Test2()
{
  Myvector::myvector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  for (const auto& e : v)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  v.resize(1);
  for (const auto& e : v)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';
  
  //测试resize
  v.resize(5, 2);
  for (const auto& e : v)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  //测试erase
  v.erase(v.begin());
  for (const auto& e : v)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  v.push_back(3);
  for (const auto& e : v)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';
  //测试popback
  v.pop_back();
  for (const auto& e : v)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';
}

void Test1()
{
  //测试构造，拷贝构造以及赋值运算符重载
  Myvector::myvector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.insert(v.begin(), 1);
  v.insert(v.begin(), 2);
  for (const auto& vi : v)
  {
    std::cout << vi << " ";
  }
  std::cout << '\n';

  Myvector::myvector<int> v1(v);
  for (size_t i =0; i < v1.size(); i++)
  {
    std::cout << v1[i] << " ";
  }
  std::cout << '\n';

  Myvector::myvector<int> v2;
  v2 = v1;
  Myvector::myvector<int>::iterator e = v2.begin();
  for (; e != v2.end(); e++)
  {
    std::cout << *e << " ";
  }
  std::cout << '\n';
}

int main()
{
  //Test1();
  Test2();
  return 0;
}

