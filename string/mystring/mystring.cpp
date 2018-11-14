#include "mystring.h"

const size_t MyString::mystring::npos = -1;

std::ostream& MyString::operator<<(std::ostream& _cout, const MyString::mystring& str)
{ 
  _cout << str._str;
  
  return _cout;
}

std::istream& MyString::operator>>(std::istream& _cin, const MyString::mystring& str)
{
  _cin >> str._str;

  return _cin;
}

//调整字符串的大小
void MyString::mystring::resize(size_t n)
{
  if (n < this->size())
  {
    _size = n;
    _str[n + 1] = '\0';
  }
  else 
  {
    //增容
    this->reserve(n);
    //在后面补NULL
    for (size_t i = this->size(); i < this->capacity(); i++)
    {
      _str[i] = ' ';
    }
    _str[this->capacity() + 1] = '\0';
  }
}

void MyString::mystring::resize(size_t n, char c)
{
  if (n < this->size())
  {
    _size = n;
    _str[n + 1] = '\0';
  }
  else 
  {
    //增容
    reserve(n);
    //在后面补NULL
    for (size_t i = this->size(); i < this->capacity(); i++)
    {
      _str[i] = c;
    }
    _str[this->capacity() + 1] = '\0'; 
  }
}

//调整字符串的容量
//对于缺省函数，只能在声明或者定义的时候缺省一次
void MyString::mystring::reserve(size_t n)
{
  assert(n >= 0);

  _capacity = n;
  char* newstr = new char[_capacity + 1];
  strcpy(newstr, _str);
  std::swap(_str, newstr);
}

size_t MyString::mystring::Getnpos()
{
  return npos;
}

//返回当前的字符串的容量
size_t MyString::mystring::capacity() const
{
  return _capacity;
}

//清空字符串，将字符串变为一个空串
void MyString::mystring::clear()
{
  if (_str)
  {
    _str[0] = '\0';
    _size = 0;
    _capacity = 0;
  }
}

//判断字符串是否为空
bool MyString::mystring::empty() const
{
  return _size == 0 ? true : false;
}

//追加operator+=
MyString::mystring& MyString::mystring::operator+=(const MyString::mystring& str)
{
  if (_capacity < _size + str._size)
  {
    this->reserve(_size + str._size);
  }

  for (size_t i = 0; i < str._size; i++)
  {
    _str[_size++] = str[i];
  }

  return *this;
}

MyString::mystring& MyString::mystring::operator+=(const char*  str)
{
  size_t len = strlen(str);
  if (_capacity < _size + len)
  {
    this->reserve(_size + len);
  }

  for (size_t i = 0; i < len; i++)
  {
    _str[_size++] = str[i];
  }

  return *this;
}

MyString::mystring& MyString::mystring::operator+=(const char c)
{
  if (_size == _capacity)
  {
    this->reserve(_capacity * 2);
  }
  _str[_size++] = c;

  return *this;
}

//追加append
MyString::mystring& MyString::mystring::append(const MyString::mystring& str)
{
  if (_capacity < _size + str._size)
  {
    this->reserve(_size + str._size);
  }

  for (size_t i = 0; i < str._size; i++)
  {
    _str[_size++] = str[i];
  }

  return *this;
}

//尾部插入一个字符push_back
void MyString::mystring::push_back(const char c)
{
  if (_size == _capacity)
  {
    this->reserve(_capacity * 2);
  }

  _str[_size++] = c;
}

//插入字符串insert
MyString::mystring& MyString::mystring::insert(size_t pos, const MyString::mystring& str)
{
  assert (pos < _size);
  if (_capacity < _size + str._size)
  {
    reserve(_size + str._size);
  }

  //移动字符串，开辟空间
  for (int i = _size; i >= (int)pos; i--)
  {
    _str[i + 1] = _str[i];
  }

  //将插入字符串插入进去
  for (size_t i = 0; i < str._size; i++)
  {
    _str[pos++] = str[i];
  }
  _size = _size + str._size;

  return *this;
}

//删除字符串
MyString::mystring& MyString::mystring::erase(size_t pos, size_t len)
{
  if (len == npos)
  {
    _str[0] = '\0';
    _size = 0;
    _capacity = 0;
  }
  
  int start = pos;
  for (size_t i = len; i <= _size; i++)
  {
    _str[pos++] = _str[start + i];
  }
  _size = _size - len;

  return *this;

}

////++str,前置++
//MyString::mystring::reverse_iterator& MyString::mystring::operator++()
//{
//     int index = _size - 1;
//    return index;
//}
//
////str++,后置++
//reverse_iterator operator++(int);
