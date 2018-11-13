#include <iostream>

using namespace std;

class Date
{
public:
  Date()
  {
    _year = 2018;
    _month = 10;
    _day = 26;
  }

  Date(int year = 2018, int month = 10, int day = 26)
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
  Date d1;
}
