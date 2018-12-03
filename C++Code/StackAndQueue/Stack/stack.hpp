#ifndef __STACK_HPP__
#define __STACK_HPP__ 

#include <iostream>
#include <deque>
#include <vector>
#include <list>

namespace yk
{
  //对于适配器的使用，使用缺省参数的时候，一定要将最后的实例化的>和模板的>使用空格分开
  template <class T, class container = std::deque<T> >
  class stack 
  {
  public:
    //由于是自定义类型，所以编译器在创建这个对象的时候
    //就会自动这个自定义类型的构造函数
    //所以就不需要自己写构造函数
    //析构函数同理
    void push(const T& d)
    {
      _con.push_back(d);
    }

    void pop()
    {
      _con.pop_back();
    }

    bool empty()
    {
      return _con.empty();
    }

    size_t size()
    {
      return _con.size();
    }

    T top()
    {
      return _con.back();
    }

  private:
    container _con;
  };
}



#endif //__STACK_HPP__
