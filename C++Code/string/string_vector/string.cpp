#include <iostream>
#include <vector>
using namespace std;

void test()
{
  string num("1234");
  string::iterator it = num.begin();
  while (it != num.end())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;



  vector<int> v;
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  vector<int>::iterator vit = v.begin(); 
  while (vit != v.end())
  {
    cout << *vit << endl;
    ++vit;
  }
}

int main()
{
  test();
  return 0;
}
