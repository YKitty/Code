//重载operator<< 和 operator>>

#include <iostream>
using namespace std;


class Date
{
friend ostream& operator<< (ostream& _cout, const Date& d);
friend istream& operator>> (istream& _cin,  Date& d);

public:
  Date (int year = 2018, int month = 11, int day = 3)
    : _year(year)//初始化，而不是赋初值
    , _month(month)
    , _day(day)
  {}
 
private:
  int _year;
  int _month;
  int _day;
};

ostream& operator<< (ostream& _cout, const Date& d)
{
  _cout << d._year << "-" << d._month << "-" << d._day << endl;

  //返回_cout(cout)，目的是让可以多次输出，连接输出
  return _cout;
}

istream& operator>> (istream& _cin, Date& d) 
{ 
  _cin >> d._year;
  _cin >> d._month;
  _cin >> d._day;

  return _cin;
}


int main()
{
  Date d;
  cin >> d;
  cout << d << endl;
  return 0;
}
