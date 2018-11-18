#include <iostream>
using namespace std;

//int Add(int left, int right);
extern "C" int Sub(int left, int right);

int main()
{
  //Add(2, 3);
  Sub(3, 2);
  return 0;
}
