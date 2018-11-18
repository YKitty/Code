//测试浅拷贝与深拷贝
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int DateType;
class SeqList
{
public:
  SeqList (int capacity = 0)//缺省的构造函数
  {
    _capacity = capacity;
  }

  ~SeqList()//析构函数
  {
    if (_pData)
    {
      free(_pData);
      _pData = NULL;
      _size = 0;
      _capacity = 0;
    }
  }

private:
  int* _pData;
  int _size;
  int _capacity;
};

int main()
{
  SeqList s1(10);
  SeqList s2(s1);//使用拷贝构造函数

  SeqList s3;
  s3 = s2;//使用赋值运算符重载
  return 0;
}
