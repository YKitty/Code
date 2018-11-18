//只能从堆上开辟对象
//必须把构造函数，拷贝构造函数以及赋值运算符重载都给封起来（即私有化）

#include <iostream>
using namespace std;

class HeapType
{
public:
  //静态成员函数没有this
  static HeapType* GetHeapObject()
  {
    return new HeapType;
  }

private:
  HeapType () //构造函数初始化
  {

  }
  
  //只声明不实现，因为实现可能很麻烦，而你本身不需要
  //只声明为私有
  //(声明成公有或私有编译器编译器都可能在类外给你实现)
  //HeapType (const HeapType& ht);
  HeapType (const HeapType& ht) = delete;//声明函数但是不需要实现该函数
  //HeapType (const HeapType& ht)//拷贝构造函数私有化
  //{}
};

int main()
{

  return 0;
}

