#include <iostream>
using namespace std;

int main()
{
  int x = 10;
  auto a = &x;//int*
  auto* b = &x;//int*
  auto& c = x;//int,引用也是x，所以类型也是int

  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  cout << typeid(c).name() << endl;

  *a = 20;
  *b = 30;
  c = 40;

  return 0;
}
