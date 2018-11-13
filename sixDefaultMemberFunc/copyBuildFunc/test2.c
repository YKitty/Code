#include <iostream>
using namespace std;

class Date 
{
public:
  Date(int year, int month, int day)//构造函数
  {
    _year = year;
    _month = month;
    _day = day;
  }

  Date (const Date& d)//拷贝构造函数
  {
    _year = d._year;
    _month = d._month;
    _day = d._day;
  }
  
  Date operator+(int days)//运算符重载
  {
    Date temp(*this);
    temp._day += days;
    //Date& d1 = *this;
    //d1._day += days;
    Print();
    return temp;
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
  Date d(2018, 11, 1);
 // d.Print();
  d = d + 10;
  d.Print();
  return 0;
}
