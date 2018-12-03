#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__ 

#include <iostream>
#include <deque>

namespace yk
{
  template <class T, class container = std::deque<T> >
  class queue 
  {
  public:
    void push(const T& d)
    {
      _con.push_back(d);
    }

    void pop()
    {
      _con.pop_front();
    }

    bool empty()
    {
      return _con.empty();
    }

    size_t size()
    {
      return _con.size();
    }

    T& front()
    {
      return _con.front();
    }

    T& back()
    {
      return _con.back();
    }

  private:
    container _con;
  };
}
#endif //__QUEUE_HPP__
