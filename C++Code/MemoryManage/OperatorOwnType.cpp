//new和delete操作自定义类型的不同点

#include <cstdlib>
#include <iostream>
using namespace std;

class Test
{
public:
  Test ()
    : _data(0)
  {
    cout << "Test():" << this << endl; 
  }

  ~Test ()
  {
    cout << "~Test():" << this << endl;
  }

private:
  int _data;
};

void TestMallocAndFree()
{
  //申请一个int类型的空间
  int* p1 = (int*)malloc(sizeof(int));
  free(p1);

  //申请10个int类型的空间
  int* p2 = (int*)malloc(sizeof(int) * 10);
  free(p2);
}

void TestNewAndDelete()
{
  //申请一个Test类型的空间
  Test* p1 = new Test;
  delete(p1);

  //申请10个Test类型的空间
  Test* p2 = new Test[10];
  delete[] p2;
}

int main()
{
  TestMallocAndFree();
  TestNewAndDelete();
  return 0;
}
