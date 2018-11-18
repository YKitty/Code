#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
#include <cstring>
#include <cassert>

namespace MyString 
{
  class mystring 
  {
  //友元函数
  //对于这里的const修饰的是mystring对象的引用，只是不让改变引用所以，对于输入加上也没有事
  friend std::ostream& operator<<(std::ostream& _cout, const mystring& str);
  friend std::istream& operator>>(std::istream& _cin, const mystring& str);

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
      this->swap(tmp);
    }

    mystring& operator=(mystring str)
    {
      this->swap(str);

      return *this;
    }

    char& operator[](size_t pos)
    {
      assert(pos < _size);

      return _str[pos];//调用std的[]
    }

    const char& operator[](size_t pos) const 
    {
      assert(pos < _size);

      return _str[pos];
    }

    void swap(mystring& str2)
    {
      std::swap(_str, str2._str);
      std::swap(_size, str2._size);
      std::swap(_capacity, str2._capacity);
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
    
    //函数接口的声明
    //调整字符串的大小
    void resize(size_t n);
    void resize(size_t n, char c);

    //调整字符串的容量
    void reserve(size_t n = 0);
    
    //返回当前的字符串的容量
    size_t capacity() const;

    //清空字符串，将字符串变为一个空串
    void clear();
    
    //判断字符串是否为空
    bool empty() const;

    //追加operator+=
    mystring& operator+=(const mystring& str);
    mystring& operator+=(const char*  str);
    mystring& operator+=(const char c);

    //追加append
    mystring& append(const mystring& str);
    
    //尾部插入一个字符push_back
    void push_back(const char c);

    //插入字符串insert
    mystring& insert(size_t pos, const mystring& str);
    mystring& insert(size_t pos, const char* str);
    mystring& insert(size_t pos, const char c);

    //删除字符串erase
    mystring& erase(size_t pos = 0, size_t len = npos);
    
    //替换字符串的部分值replace
    mystring& replace(size_t pos, size_t len, mystring& str);

    //从前往后查找字符串find
    size_t find(const mystring& str, size_t pos = 0) const;
    size_t find(const char* str, size_t pos = 0) const;
    size_t find(const char c, size_t pos = 0) const;

    //从后往前查找字符串rfind
    size_t rfind(const mystring& str, size_t pos = npos) const;

    //迭代器
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef char* reverse_iterator;
    typedef const char* const_reverse_iterator;

    iterator begin()
    {
      return _str;
    }

    const_iterator begin() const 
    {
      return _str;
    }

    iterator end()
    {
      return _str + size();
    }

    const_iterator end() const 
    {
      return _str + _size;
    }

    reverse_iterator rbegin()
    {
      return _str + _size - 1;
    }

    const_reverse_iterator rbegin() const
    {
      return _str + _size - 1;
    }

    reverse_iterator rend()
    {
      return _str - 1;
    }

    const_reverse_iterator rend() const 
    {
      return _str - 1;
    }
    
    //++it,前置++
    reverse_iterator& operator++();
    //it++,后置++
    reverse_iterator operator++(int);
  
    //获取npos的值
    size_t Getnpos();
    

private:
    char* _str;//字符串数组
    size_t _size;//大小
    size_t _capacity;//容量
    static const size_t npos;
  };


std::ostream& operator<<(std::ostream& _cout, const mystring& str);
std::istream& operator>>(std::istream& _cin, const mystring& str);
  
}


#endif //__MYSTRING_H__
