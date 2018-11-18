//引用返回的局部变量
#include <iostream>

using namespace std;

class Test
{
public:
  int& Add(int left, int right)
  {
    int c = left + right;
    return c;
  }
};

int main()
{
  Test t;
  cout << t.Add(2, 3) << endl;
  return 0;
}
