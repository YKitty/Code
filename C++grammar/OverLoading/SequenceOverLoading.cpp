//对于函数的顺序重载

#include <iostream>
using  namespace std;

class Test
{
public:
  void TestFunc(int a, float b)
  {
    cout << "int next float" << endl;
  }

  void TestFunc(float a, int b)
  {
    cout << "float next int" << endl;
  }

private:
  int _a;
};

int main()
{
  Test a;
  a.TestFunc(2, 2.1);
  a.TestFunc(2.1, 2);
  return 0;
}
