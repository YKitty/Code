//模板函数和非模板函数

#include <iostream>
using namespace std;

//非模板函数
int Add(int left, int right)
{
  return left + right;
}

//模板函数
//第一种模板函数，只自己推导一个类型
template <class T>
T Add(T left, T right)
{
  return left + right;
}

//第二种模板函数，全部类型
template <class T1, class T2>
T1 Add(T1 left, T2 right)
{
  return left + right;
}


int main()
{
  cout << Add(1, 2) << endl;//调用非模板函数
  cout << Add(1.2, 2.2) << endl;//调用模板函数，单类型
  cout << Add(1, 2.2) << endl;//调用模板函数，双类型
  cout << Add<>(1, 2) << endl;//显式调用模板函数
  return 0;
}
