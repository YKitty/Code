#include <iostream>
#include <functional>

std::function<void()> myfunc;

class Basic
{
private:
  int _num;
  char _c;

public:
  Basic(): _num(10), _c('c')
  {}

  void Set()
  {
    //可以修改该类的成员变量
    myfunc = [this]()->void{
      _num = 11;
      _c = 'b';
    };
    //必须调用这个函数
    myfunc();
  }

  void Show()
  {
    std::cout << "_num: " << _num << "\n_c: " << _c << std::endl;
  }
};

int main()
{

  Basic b;
  b.Show();
  b.Set();
  b.Show();
  //std::string s = "hello world!";
  //std::function<void ()> myfunc;
  //不能捕获所在函数中的变量
  //myfunc = []()->void{
  //  //无法捕获到变量s
  //  std::cout << s << std::endl;
  //  //可以输出
  //  std::cout << "1" << std::endl;
  //};
  
  //以值传递的方式捕获
  //myfunc = [=]()->void{
  //  std::cout << s << std::endl;
  //  //s += "asd"; //出错
  //};
  //std::cout << s << std::endl;
  

  //以引用的方式捕获
  //myfunc = [&]()->void{
  //  std::cout << s << std::endl;
  //  //改变了外边的变量
  //  s += "abc";
  //  std::cout << s << std::endl;
  //};
  //myfunc();
  //std::cout << s << std::endl;
  return 0;
}
