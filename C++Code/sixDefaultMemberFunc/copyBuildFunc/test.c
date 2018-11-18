//赋值运算符重载

#include <iostream>
using namespace std;

class Date
{
public:
  Date(int year = 2018, int month = 11, int day = 1)
  {
    _year = year;
    _month = month;
    _day = day;
  }

  Date(const Date& d)//拷贝构造函数
  { 
    _year = d._year;
    _month = d._month;
    _day = d._day;
  }

  Date& operator=(const Date& d)//赋值运算符重载
  {
    if (this != &d)
    {
      _year = d._year;
      _month = d._month;
      _day = d._day;
    }

    return *this;
  }
  
  void Print()
  {
    cout << _year << "--" << _month << "--" << _day << endl;
  }

private:
  int _year;
  int _month;
  int _day;
};

int main()
{
  Date d(2018, 11, 10);
  d.Print();
  Date d1;
  d1 = d;//调用的是赋值运算符重载
  d1.Print();
  Date d2 = d1;//调用的是拷贝构造函数
  d2.Print();
  return 0;
}
