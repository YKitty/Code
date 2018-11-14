#include "mystring.h"

int main()
{
  MyString::mystring str = "hello world";//隐式转换
  MyString::mystring str1 = "!";//隐式转换

  //测试operator+=
  str += str1;
  std::cout << str << '\n';//hello world!
  str += "i love yo";
  str += 'u';
  std::cout << str << '\n';//hello world!i love you

  //测试append
  str.append(str1);
  std::cout << str << '\n';//hello world!i love you!

  //测试push_back
  str.push_back('X');
  std::cout << str << '\n';//hello world!i love you!X

  //测试insert
  str.insert(0, str1);
  std::cout << str << '\n';//!hello world!i love you!X

  //测试erase
  str.erase();
  std::cout << str << '\n';//


  ////测试capacity和clear
  //std::cout << "str capacity:" << str.capacity() << '\n';
  //str.clear();
  //std::cout << "str:" << str << "str capacity:" << str.capacity() << "str size:" << str.size() << '\n';

  ////测试begin和end
  //for (MyString::mystring::iterator it = str.begin(); it != str.end(); it++)
  //{
  //  std::cout << *it << " ";
  //}
  //std::cout << '\n';

  ////测试rbegin和rend
  //for (MyString::mystring::iterator it = str.rbegin(); it != str.rend(); it--)
  //{
  //  std::cout << *it << " ";
  //}
  //std::cout << '\n';

  //测试operator>>和operator<<,operator[]等重载
  //MyString::mystring str("hello world");
  //MyString::mystring str1("hello world");
  //MyString::mystring str2("hello world");
  ////对于"hello"这是一个operator=的重载,对于该函数调用operator之后，发现其形参是mystring& str就会到调用构造函数的隐式转换，
  ////将"hello "进行隐式转换，将其转化为一个mystring& tmp对象，然后用该对象对当前对象进行赋值操作
  ////解决办法：将构造函数的隐式转换开着就行了，也就是不需要增加explicit关键字
  //str = "hello";
  //std::cout << str << '\n';
  //std::cout << "size:" << str.size() << "capacity:" << str.capacity() << '\n';

  //MyString::mystring str3 = str;
  //std::cout << str3 << '\n';
  //std::cout << "size:" << str3.size() << "capacity:" << str3.capacity() << '\n';


  //for (size_t i = 0; i < str.size(); i++)
  //{
  //  std::cout << str[i] << " ";
  //}
  //std::cout << '\n';

  //str.resize(2);
  //std::cout << str1 << '\n';

  //str1.resize(6);
  //std::cout << str1 << '\n';

  //str1.resize(10, 'X');
  //std::cout << "str1:" << str1 << "str1.capacity:" << str1.capacity() <<  '\n';

  //str1.reserve(100);
  //std::cout << "str1.capacity:" << str1.capacity() << '\n';

  ////std::cin >> str2;
  ////std::cout << str2;
  //std::cout << str2.Getnpos();
  return 0;
}
