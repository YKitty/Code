#include <iostream>
#include <cstring>
//#include <gnu/stubs-32.h>
using namespace std;

int main()
{
  char str[] = "背锅";
  cout << sizeof(str) << endl;
  cout << strlen(str) << endl;
  cout << sizeof(wchar_t) << endl;
  return 0;
}

