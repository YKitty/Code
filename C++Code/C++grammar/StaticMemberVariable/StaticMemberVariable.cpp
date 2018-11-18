//静态成员变量在类外定义

#include <iostream>
using namespace std;

class Test
{
public:
  static int GetStaticVariable()
  {
    return _a;
  }

private:
  static int _a;
};

int Test::_a = 1;

int main()
{
  Test t;
  cout << t.GetStaticVariable() << endl;
  return 0;
}
