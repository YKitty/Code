#include "date.h"

int main()
{
  Date d1(2008, 11, 1);
  d1.Print();

  d1 += 100;
  d1.Print();
  
  Date d2;;
  d2 = d1;//赋值运算符重载
  d2 -= 100;
  d2.Print();

  Date olympicDate(2008, 8, 8);
  Date today(2018, 10, 27);
  cout << today - olympicDate << endl;
  cout << today;
  return 0;
}


