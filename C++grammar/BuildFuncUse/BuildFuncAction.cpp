//构造函数的作用
//对于单个参数的构造函数(或者除第一个参数外，其余参数都有默认值的多参构造函数)，还具有类型转换的作用

#include <iostream>
using namespace std;

class Date
{
public:
  explicit Date (int year)//只能显示调用构造函数，不能进行隐式转换
    : _year(year)
  {}

  void Print()
  {
    cout << _year << endl; 
  }

private:
      int _year;
};

class Date1
{
public:
  Date1 (int year)//可以进行隐式转换
    : _year(year)
  {}

  void Print()
  {
    cout << _year << endl; 
  }

private:
      int _year;
};

class Date2
{
public:
  Date2 (int year, int month = 12)//可以进行隐式转换
    : _year(year)
    , _month(month)
  {}

  void Print()
  {
    cout << _year << "--" << _month << endl; 
  }

private:
      int _year;
      int _month;
};

int main()
{
  //Date d1 = 2018;//隐式调用构造函数,出错
  //d1.Print();

  Date d1(12); //调用构造函数，显式调用构造函数
  d1.Print();
  Date1 d2 = 13;//调用构造函数，隐式转换
  d2.Print();
  Date2 d3 = 11;
  d3.Print();
  return 0;
}
