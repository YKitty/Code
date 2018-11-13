#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
#include <cstring>
#include <cassert>

namespace MyString 
{
  class mystring 
  {
  friend std::ostream& operator<<(std::ostream& _cout, const mystring& str);
  friend std::istream& operator>>(std::istream& _cin, mystring& str);

  public:
    //给空字符串是为了，对于一个未初始化的对象，它的size(大小)应该是0，而不应该不存在
    //没有加explicit关键字也就是可以进行隐式转换
    mystring(const char* str = "")
      : _str(new char[strlen(str) + 1])
      {
        assert(str);
        strcpy(_str, str);
        //在初始化的时候就已经有大小和容量了
        _size = strlen(str);
        _capacity = _size;
      }
    
    //传统写法
    //拷贝构造需要开辟空间，由于当前对象还没有创建
    //mystring(const mystring& str)
    //  : _str(new char[strlen(str._str) + 1])
    //{
    //    strcpy(_str, str._str);
    //    _size = str._size;
    //    _capacity = str._capacity;
    //}
    //
    //const mystring& operator=(const mystring& str)
    //{
    //  //不是自己给自己赋值
    //  if (this != &str)
    //  {
    //    delete[] _str;
    //    _str = new char[strlen(str._str) + 1];
    //    strcpy(_str, str._str);
    //  }

    //  return *this;
    //}
    //
    //现代写法,使用swap全局函数
    mystring(const mystring& str)
      : _str(nullptr)
    {
      //构造一个临时对象
      mystring tmp(str._str);
      swap(*this, tmp);
    }

    mystring& operator=(mystring str)
    {
      swap(*this, str);

      return *this;
    }

    void swap(mystring& str1, mystring& str2)
    {
      std::swap(str1._str, str2._str);
      std::swap(str1._size, str2._size);
      std::swap(str1._capacity, str2._capacity);
    }

    const char* c_str()
    {
      return _str;
    }


    ~mystring()
    {
       if (_str)
       {
         delete[] _str;
         _str = nullptr;
         _size = 0;
         _capacity = 0;
       }
    }
  
    size_t size()
    {
      return _size;
    }
    
    size_t capacity()
    {
      return _capacity;
    }

  private:
    char* _str;//字符串数组
    size_t _size;//大小
    size_t _capacity;//容量
  };
  
  std::ostream& operator<<(std::ostream& _cout, const mystring& str)
  { 
    _cout << str._str;
    
    return _cout;
  }

  std::istream& operator>>(std::istream& _cin, mystring& str)
  {
    _cin >> str._str;

    return _cin;
  }
}


#endif //__MYSTRING_H__
