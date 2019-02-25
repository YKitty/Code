#include <iostream>
#include <string.h>
#include <assert.h>
#include <cstddef>

class StringCow
{
public:
  StringCow(const char* str = "")
    : _str(new char[strlen(str) + 1 + 4])
  {
    _str += 4;//将_str指向存放数据的起始地址
    SetUseCount() = 1;
    strcpy(_str, str);
  }

  ~StringCow()
  {
    Release();
  }

  StringCow(const StringCow& str)
    : _str(str._str)
  {
    SetUseCount()++;
  }

  StringCow& operator=(const StringCow& str)
  {
    if (this != &str)
    {
      //释放以前这个对象的内存空间
      Release();
      _str = str._str;
      SetUseCount()++;
    }

    return *this;
  }
  
  //1.判断引用计数是否为1
  //2.是1直接返回
  //3.不是1拷贝出一份_str，然后再返回
  char& operator[](int index)
  {
    assert(index >= 0);

    if (SetUseCount() == 1)
    {
      return _str[index];
    }

    SetUseCount()--;
    char* tmp = _str;
    _str = new char[strlen(_str) + 1 + 4];
    _str += 4;
    strcpy(_str, tmp);
    SetUseCount() = 1;
    return _str[index];
  }

//private:
  int& SetUseCount()
  {
    return *(int*)(_str - 4);
  }

  void Release()
  {
    if (--SetUseCount() == 0)
    {
      delete[] (_str - 4);
      _str = NULL;
    }
  }

private:
  char* _str;
};


int main()
{
  StringCow s("abc");
  std::cout << s.SetUseCount() << std::endl;
  StringCow s1(s);
  std::cout << s1.SetUseCount() << std::endl;
  StringCow s2 = "abc";
  std::cout << s2.SetUseCount() << std::endl;
  s1[0] = 'b';
  std::cout << s1.SetUseCount() << std::endl;
  return 0;
}
