#include <iostream>

class Date
{
  public:
        Date(int year, int month, int day)
        {
          _year = year;
          _month = month;
          _day = day;                            
        }
            
        Date (const Date& d)
        {
          _year = d._year;
          _month = d._month;
          _day = d._day;                               
        }
                
        Date& Add(int days)
        {
          _day += days;
          return *this;                            
        }

        void Print()
        {
          std::cout << this->_year << "--" << this->_month << "--" << this->_day << std::endl ;
        }
                 
private:
      int _year;
      int _month;
      int _day;
};

int main()
{
      Date d(2018, 9, 11);
      d.Print();
      d.Add(11);
      d.Print();
}
