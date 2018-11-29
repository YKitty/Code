#include "date.h"

ostream& operator<< (ostream& _cout, const Date& d)
{
  _cout << d._year << "-" << d._month << "-" << d._day << '\n';

  return _cout;
}

istream& operator>> (istream& _cin, Date& d)
{
  _cin >> d._year;
  _cin >> d._month;
  _cin >> d._day;

  return _cin;
}

void Date::Print()
{
  cout << _year << "--" << _month << "--" << _day << endl;
}

int Date::GetMonthDay(int year, int month)
{
  static const int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
  {
    return 29;
  }

  return monthDay[month];
}

//对于缺省构造函数，声明和定义分开的话只需要有一个缺省的就可以了
Date::Date (int year, int month, int day)//构造函数
{
  if (year > 0 
      && month > 0 && month < 13
      && day > 0 && day <= GetMonthDay(year, month))
  {
    _year = year;
    _month = month;
    _day = day;
  }
  else
  {
    cout << "Date Invalid!" << endl;
  }
}

Date::Date (const Date& d)//拷贝构造函数
{
  _year = d._year;
  _month = d._month;
  _day = d._day;
}


Date& Date::operator=(const Date& d)//赋值运算符重载
{
  if (this != &d)
  {
    _year = d._year;
    _month = d._month;
    _day = d._day;
  }

  return *this;
}

Date Date::operator+ (int days)
{
 // Date ret(*this);
  
  //ret._day += days; 
  //while (ret._day > GetMonthDay(ret._year, ret._month))
  //{
    //ret._day -= GetMonthDay(ret._year, ret._month);
    //++ret._month;

    //if (ret._month == 13)
    //{
      //ret._year++;
      //ret._month = 1;
    //}
  //}
  //不能使用引用，因为函数结束后，ret已经释放了不能使用引用
  //直接返回ret在外面再次进行复制
  //return ret;
  
  //复用+=
  Date ret(*this);
  ret += days;

  return ret;
}

//d1 += 100，改变this
//只要返回的时候这个对象是存在的就可以使用”引用“
Date& Date::operator+= (int days)
{
  if (days < 0)
  {
    return *this -= (-days);
  }

  _day += days;
  while (_day > GetMonthDay(_year, _month))
  {
    _day -= GetMonthDay(_year, _month);
    ++_month;

    if (_month == 13)
    {
      _year++;
      _month = 1;
    }
  }
  //不能使用引用，因为函数结束后，ret已经释放了不能使用引用
  //直接返回ret在外面再次进行复制
  return *this;
  
  //对象遇到+就会去找operator+
  //复用+，+里面一直在拷贝对象
  //*this = *this + days;
  //return *this;
}

Date Date::operator- (int days)
{
  Date ret(*this);

  ret -= days;
  return ret;
}

Date& Date::operator-= (int days)
{
  if (days < 0)
  {
    return *this += (-days);
  }

  _day -= days;
  while (_day <= 0)
  {
    _month--;
    if (_month == 0)
    {
      _month = 12;
      _year--;
    }
    _day += GetMonthDay(_year, _month);
  }

  return *this;
}

//++d，前置++直接返回当前对象
Date& Date::operator++ ()
{
  *this += 1;
  return *this;
}

//d++，后置++必须返回加1前的对象，就返回自己临时创建的对象
Date Date::operator++ (int)
{
  Date ret(*this);
  *this += 1;
  return ret;
}

//--d，前置--可以直接返回当前对象
Date& Date::operator-- ()
{
  *this -= 1;
  return *this;
}

//d--，后置--必须返回加1后的对象，就返回自己临时创建的对象
Date Date::operator-- (int)
{
  Date ret(*this);
  *this -= 1;
  return ret;
}

bool Date::operator> (const Date& d)
{
  if (_year > d._year)
  {
    return true;
  }
  else if (_year == d._year)
  {
    if (_month > d._month)
    {
      return true;
    }
    else if (_month == d._month)
    {
      if (_day > d._day)
      {
        return true;
      }
    }
  }

  return false;
}

//>= 就是等于或者大于
bool Date::operator>= (const Date& d)
{
    return *this > d || *this == d;
}

bool Date::operator< (const Date& d)
{
   return !(*this >= d);
}

bool Date::operator<= (const Date& d)
{
  return !(*this > d);
}

bool Date::operator== (const Date& d)
{
  return _year == d._year 
    && _month == d._month 
    && _day == d._day;
}

bool Date::operator!= (const Date& d)
{
  return !(*this == d);
}

//d1(this) - d2(d) 
int Date::operator- (const Date& d)
{
  Date max = *this;
  Date min = d;
  int flag = 1;
  if (*this < d)
  {
    max  = d;
    min = *this;
    flag = -1;
  }

  int n = 0;
  while (min < max)
  {
    ++min;
    ++n;
  }

  return n * flag;
}
