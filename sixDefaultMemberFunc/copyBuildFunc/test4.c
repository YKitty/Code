//检测系统默认生成一个拷贝构造函数和一个赋值运算符重载


#include <iostream>
using namespace std;

class Date
{
public:
  Date(int year = 2018, int month = 11, int day = 1)//缺省拷贝构造函数
  {
    _year = year;
    _month = month;
    _day = day;
  }

private:
  int _year;
  int _month;
  int _day;
};

int main()
{
  Date d(2018, 11, 11);
  Date d1 = d; //没有报错说明默认生成了一个拷贝构造函数
  Date d2;
  d2 = d;//没有报错说明生成了一个赋值运算符重载函数
  return 0;
}
