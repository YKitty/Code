//这两个函数不支持重载，由于这两个函数都相当于是缺省参数的函数，是一模一样的
//
#include <iostream>

using namespace std;

class Test
{
public:
  void TestFunc(int a = 9) 
  {
    cout << "haveParameter:" << a <<  endl;
  }

  void TestFunc(int a)
  {
    cout << "noHaveParameter" << a << endl;
  }

private:
  int _a;
};

int main()
{
  Test t;
  t.TestFunc(10);
  return 0;
}
