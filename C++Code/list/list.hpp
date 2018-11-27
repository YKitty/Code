#ifndef __LIST_HPP__
#define __LIST_HPP__ 

#include <iostream>

namespace Mylist
{
  //双向循环带头结点
  //对于struct内部默认都是public类型的访问权限
  //struct要将其当做一个类，来看，
  //如果new一个该类的话，就会调用构造函数
  template <class T>
  struct ListNode
  {

    //对于T()，这是一个匿名对象，T也是一个类
    ListNode (const T& d = T())
      : _data(d)
      , _next(nullptr)
      , _prev(nullptr)
    {
    }

    T _data;
    ListNode<T>* _next;
    ListNode<T>* _prev;

  };
  
  //迭代器本质上还是一个指针，只不过对于该指针的操作不一样了
  template <class T, class Ref, class Ptr>
  struct ListIterator 
  {
    typedef ListNode<T> Node;
    typedef ListIterator<T, Ref, Ptr> Self;
    ListIterator (Node* node)
      : _node(node)
    {
    }

    ListIterator (const Node& d)
      : _node(d._node)
    {
    }

    Ref operator* ()
    {
      return _node->_data;
    }

    Ptr operator-> ()
    {
      return &(operator*());
    }

    //后置++
    //拷贝一份当前迭代器，然后返回拷贝好的迭代器
    Self operator++ (int)
    {
      Self temp(*this);
      _node = _node->_next;

      return temp;
    }

    //前置++
    Self& operator++ ()
    {
      _node = _node->_next;

      return *this;
    }
    
    //后置--
    //拷贝一份当前迭代器，然后返回拷贝好的迭代器
    Self operator-- (int)
    {
      Self temp(*this);
      _node = _node->_prev;

      return temp;
    }

    //前置--
    Self& operator-- ()
    {
      _node = _node->_prev;

      return *this;
    }

    bool operator!= (const Self& it)
    {
      //两个不相等返回true，相等返回false
      return _node != it._node;
    }


    Node* _node;
  };


  template <class T>
  class mylist 
  {
    typedef ListNode<T> Node;
  public:

    typedef ListIterator<T, T&, T*> iterator;
    typedef ListIterator<T, const T&, const T*> const_iterator;
    

    /////////////////////////////////////////////////////////////////////////////////////////////
    //迭代器
    iterator begin()
    {
      return iterator(_head->_next);
    }

    iterator end()
    {
      //返回的时候要返回最后一个元素的下一个位置
      return iterator(_head);
    }

    const_iterator cbegin() const
    {
      return const_iterator(_head->_next);
    }
    
    const_iterator cend() const
    {
      return const_iterator(_head);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    //构造函数
    //开辟头结点并且在Node中默认初始化
    mylist ()
      : _head(new Node)
    {
      _head->_next = _head;
      _head->_prev = _head;
    }
    
    template <class Iterator>
    mylist (Iterator First, Iterator end)
      : _head(new Node)
    {
      _head->_next = _head;
      _head->_prev = _head;
      while (First != end)
      {
        push_back(*First);
        //++First;
        First++;
      }
    }

    mylist (int n, const T d = T())
      : _head(new Node)
    {
      _head->_next = _head;
      _head->_prev = _head;
      for (int i = 0; i < n; i++)
      {
        push_back(d);
      }
    }

    ~mylist ()
    {
      clear();
      delete _head;
      _head = nullptr;
    }

    //现代写法
    mylist (const mylist<T>& ml)
      : _head(new Node)
    {
      _head->_next = _head;
      _head->_prev = _head;
      //对于const类型的对象只能调用const类型的函数
      mylist<T> temp(ml.cbegin(), ml.cend());
      swap(temp);
    }

    //拷贝的时候判断一下是不是自己给自己拷贝
    mylist<T>& operator= (mylist<T>& ml)
    {
      if (this != &ml)
      {
        mylist<T> temp(ml);//拷贝构造
        swap(temp);
      }

      return *this;
    }
    

    ////////////////////////////////////////////////////////////////////////////////////////////
    //容量
    bool empty()
    {
      return _head->_next == _head;
    }

    //时间复杂度为O(N)
    size_t size()
    {
      size_t num = 0;
      Node* ret = _head->_next;
      while (ret != _head)
      {
        num++;
        ret = ret->_next;
      }

      return num;
    }

    ///////////////////////////////////////////////////////////////////////////
    //插入删除操作
    //考虑复用，直接复用insert或者erase
    void push_back(const T& d)
    {
      insert(end(), d);
    }

    void pop_back()
    {
      erase(--end());
    }

    void push_front(const T& d)
    {
      insert(begin(), d);
    }

    void pop_front()
    {
      erase(begin());
    }

    void insert(iterator pos,const T& d)
    {
      Node* front = pos._node->_prev;
      Node* posNode = pos._node;
      Node* newNode = new Node(d);

      //front newNode pos 
      front->_next = newNode;
      newNode->_prev = front;
      newNode->_next= posNode;
      posNode->_prev = newNode;
    }

    void erase(iterator pos)
    {
      Node* front = pos._node->_prev;
      Node* posNode = pos._node;
      Node* back = posNode->_next;

      //front pos back 
      front->_next = back;
      back->_prev = front;
      delete posNode;
    }
    
    void clear()
    {
      Node* ret = _head->_next;
      while (ret != _head)
      {
        Node* tmp = ret->_next;
        delete ret;
        ret = tmp;
      }

      _head->_next = _head;
      _head->_prev = _head;
    }

    void swap(mylist<int>& ml)
    {
      //对于系统自己实现的swap,只是浅拷贝，对于交换指针，已经够了
      std::swap(_head, ml._head);
    }

  private:
    Node* _head;
  };

}

#endif //__LIST_HPP__
