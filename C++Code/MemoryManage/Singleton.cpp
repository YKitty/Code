//单例模式：只有一个对象
//饿汉模式：饿(一上来就吃)
//直接把对象创建出来

#include <iostream>
using namespace std;

//类内都是声明
class Singleton
{
public:
  static Singleton* GetInstance()
  {
    return &_sInstance;
  }
  
  void Print()
  {
    cout << "Print():" << this << endl;
  }

private:
  Singleton()//构造函数私有化
  {}

  //加上delete是为了防止友元
  //即在类外对这个函数进行定义(实现)
  Singleton(const Singleton& sl) = delete;//拷贝构造函数初始化
  Singleton& operator=(const Singleton& d) = delete;//赋值运算符重载
  static Singleton _sInstance;//声明一个对象，类外定义
};

Singleton  Singleton::_sInstance;//定义(创建)这个对象

int main()
{
  Singleton* b = Singleton::GetInstance();
  b->Print();
  return 0;
}
