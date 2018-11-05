//只能从栈上开辟对象

#include <iostream>
using namespace std;

class StackType
{
public:
  static StackType GetSatckObject ()
  {
    StackType obj;
    //不会返回obj对象，因为obj是局部变量
    //返回的话就会调用拷贝构造函数
    return obj;
  }

  void Print ()
  {
    cout << "Print():" << this << endl;
  }

private:
  StackType ()//构造函数私有化
  {

  }
};

int main()
{
  StackType::GetSatckObject();//匿名对象
  
  StackType obj = StackType::GetSatckObject();//将匿名对象给一个对象
  obj.Print();

  return 0;
}
