#ifndef __PRIORITYQUEUE_HPP__
#define __PRIORITYQUEUE_HPP__ 

#include <iostream>
#include <deque>
#include <vector>
#include <list>

template <class T>
class greater 
{
public:
  //重载()
  bool operator() (const T& d1, const T& d2)
  {
    return d1 > d2;
  }
};

namespace yk
{
  template <class T, class container = std::deque<T>, class compare = greater<T> >
  class priority_queue 
  {
  public:
    void AdJustUp(size_t child)
    {
      size_t parent = (child - 1) >> 1;

      while (child > 0)
      {
        if (_con[parent] < _con[child])
        {
          std::swap(_con[parent], _con[child]);
          child = parent;
          parent = (child - 1) >> 1;
        }
        else 
        {
          return;
        }
      }
    }

    void AdJustDown(size_t parent)
    {
      size_t child = parent * 2 + 1; 

      while (child < _con.size())
      {
        //寻找左右孩子中大的一个
        if ((child + 1 < _con.size() && (_con[child + 1] > _con[child])))
          {
            ++child; 
          }
        
        if (_con[parent] < _con[child])
        {
          std::swap(_con[parent], _con[child]);
          parent = child;
          child = parent * 2 + 1;
        }
        else 
        {
          return;
        }
      }
    }

    void push(const T& d)
    {
      _con.push_back(d);

      //向上调整
      AdJustUp(_con.size() - 1);
    }

    void pop()
    {
      std::swap(_con[0], _con[_con.size() - 1]);
      _con.pop_back();

      //向下调整
      AdJustDown(0);
    }
    
    bool empty()
    {
      return _con.empty();
    }

    size_t size()
    {
      return _con.size();
    }

    T& top()
    {
      return _con.front();
    }

  private:
    container _con;
  };
}

#endif //__PRIORITYQUEUE_HPP__
