//单例模式：只有一个对象
//懒汉模式：第一次使用对象创建对象

#include <iostream>
#include <mutex>
using namespace std;

//类内都是声明
class Singleton
{
public:
  static Singleton* GetInstance()
  {
    //二重锁，防止每一个线程过来的时候，都要加锁，解锁，浪费资源
    if (_spInstance == nullptr)
    {
      //添加锁是一重锁，只是每次让一个线程执行该段代码
      _smutex.lock();
      if (_spInstance == nullptr)
      {
        _spInstance = new Singleton;
      }
      _smutex.unlock();
    }

    return _spInstance;
  }
  
  void Print()
  {
    cout << "Print():" << this << endl;
  }

  class CGarbo
  {
  public:
    ~CGarbo()
    {
      if (_spInstance != nullptr)
      {
        delete _spInstance;
      }
    }
  };

private:
  Singleton()//构造函数私有化
  {}

  //加上delete是为了防止友元
  //即在类外对这个函数进行定义(实现)
  Singleton(const Singleton& sl) = delete;//拷贝构造函数初始化
  Singleton& operator=(const Singleton& d) = delete;//赋值运算符重载
  static CGarbo _sGarbo;
  static Singleton* _spInstance;//声明一个对象的指针，类外定义
  static mutex _smutex;
};

Singleton*  Singleton::_spInstance = nullptr;//定义(创建)这个对象
Singleton::CGarbo Singleton::_sGarbo;//在进程结束时，这个对象也会销毁，调用析构函数，释放堆空间
mutex Singleton::_smutex;

int main()
{
  Singleton* b = Singleton::GetInstance();
  b->Print();
  return 0;
}
