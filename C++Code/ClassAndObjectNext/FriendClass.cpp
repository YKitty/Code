//友元类

#include <iostream>
using namespace std;

class Date;//前置声明
class Time
{
//声明Date类是Time类的友元类，那么在Date类中就可以直接访问Time类中的私有成员了
friend class Date;
public:
  Time (int hour = 11, int minute = 40, int Second = 20)
    : _hour(hour)
    , _minute(minute)
    , _second(Second)
  {}

private:
  int _hour;
  int _minute;
  int _second;
};

class Date 
{
public:
  Date (int year = 2018, int month = 11, int day = 3)
    : _year(year)
    , _month(month)
    , _day(day)
  {}
  
  //可以直接访问Time类中的私有数据
  void SetTimeOfDate(int hour = 11, int minute = 20, int Second = 12)
  {
    _t._hour = hour;
    _t._minute = minute;
    _t._second = Second;
  }

  void Print()
  {
    cout << _year << "-" << _month << "-" << _day << endl;
    cout << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
  }

private:
  int _year;
  int _month;
  int _day;
  Time _t;
};



int main()
{
  Date d;
  d.Print();
  return 0;
}
