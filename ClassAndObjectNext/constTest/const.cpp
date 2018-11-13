#include <iostream>

class Test
{
public:
  void GetMember() const 
  {
    _a = 8;
    std::cout << _a << '\n'; 
  }

private:
  mutable int _a = 5;
};

int main()
{
  Test().GetMember();
  return 0;
}
