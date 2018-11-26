#include "list.h"

void Test4()
{
  //测试迭代器的前置++，与后置++
  //以及迭代器自我重载的一些功能
  Mylist::mylist<int> ml;
  ml.push_back(1);
  ml.push_back(2);
  ml.push_back(3);
  ml.push_back(4);

  Mylist::ListIterator<int> it = ml.begin();
  while (it != ml.end())
  {
    //测试*
    //std::cout << *it << std::endl;
    
    //测试后置++
    //std::cout << *it++ << std::endl;
    
    //测试前置++
    std::cout << *++it << std::endl;
  }

}

void Test3()
{
  //测试erase,insert
  Mylist::mylist<int> ml;
  ml.push_back(1);
  ml.push_back(2);
  ml.push_back(3);
  ml.push_back(4);
  for (auto e : ml)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';
  
  ml.insert(ml.begin(), 4);
  for (auto e : ml)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';
  ml.erase(ml.begin());
  for (auto e : ml)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';
  
}

void Test2()
{
  //测试push_back,pop_back,push_front,pop_front,
  //empty,size
  Mylist::mylist<int> ml;
  ml.push_back(1);
  ml.push_back(2);
  ml.push_back(3);
  ml.push_back(4);

  for (auto e : ml)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  std::cout << ml.size() << std::endl;
  //ml.pop_back();
  //ml.pop_back();
  ml.pop_front();
  ml.pop_front();
  for (auto e : ml)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  ml.push_front(6);
  ml.push_front(7);

  for (auto e : ml)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  std::cout << ml.size() << std::endl;

  if (ml.empty())
  {
    std::cout << "ml is empty!" << std::endl;
  }
}

void Test1()
{
  //测试构造函数以及push_back,
  //以及拷贝构造函数，赋值运算符重载
  int array[] = { 1, 2, 3, 4, 5 };
  Mylist::mylist<int> ml;
  Mylist::mylist<int> ml1(2, 4);
  Mylist::mylist<int> ml2(ml1.begin(), ml1.end());
  Mylist::mylist<int> ml3(array, array + sizeof(array)/ sizeof(array[0]));
  Mylist::mylist<int> ml4(ml1);
  Mylist::mylist<int> ml5;
  ml5 = ml3;
  ml.push_back(1);
  ml.push_back(2);
  ml.push_back(3);
  ml.push_back(4);

  for (auto e : ml)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  for (auto e : ml1)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  for (auto e : ml2)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  for (auto e : ml3)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  for (auto e : ml4)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';

  for (auto e : ml5)
  {
    std::cout << e << " ";
  }
  std::cout << '\n';
}

int main()
{
  //Test1();
  //Test2();
  //Test3();
  Test4();
  return 0;
}


