#ifndef __DATE_H__
#define __DATE_H__  


#include <iostream>
using namespace std;

class Date 
{
friend  ostream& operator<< (ostream& _cout, const Date& d); 
friend  istream& operator>> (istream& _cin, Date& d);
public:
  Date (int year = 1998, int month = 11, int day = 10);//构造函数
  Date (const Date& d);//拷贝构造函数
  Date& operator=(const Date& d);
  Date operator+ (int days);
  Date& operator+= (int days);
  Date operator- (int days);
  Date& operator-= (int days);
  //减去一个日期
  int operator- (const Date& d);
  Date& operator++ ();//++d
  Date operator++ (int);//d++
  Date& operator-- ();//--d
  Date operator-- (int);//d--
  //设为内联函数直接展开，可以减少开销
  inline bool operator> (const Date& d);
  inline bool operator>= (const Date& d);
  inline bool operator< (const Date& d);
  inline bool operator<= (const Date& d);
  inline bool operator== (const Date& d);
  inline bool operator!= (const Date& d);
  inline int GetMonthDay(int year, int month);
  void Print();

private:
  int _year;
  int _month;
  int _day;
};


#endif //__DATE_H__
