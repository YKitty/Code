//函数模板实例化：隐式实例化和显式实例化

#include <iostream>
using namespace std;

template <class T>
T Add(const T& left, const T& right)
{
  return left + right;
}

int main()
{
  int a1 = 10, a2 = 20;
  double d1 = 1.0, d2 = 2.0;

  //隐式实例化

  cout << Add(a1, a2) << endl;
  cout << Add(d1, d2) << endl;

  //出错，因为不知道将T推演为int或者double
  //Add(a1, d1);

  cout << Add(a1, (int)d1) << endl;

  //显式实例化
  
  cout << Add<int>(a1, d1) << endl;
  return 0;
}
