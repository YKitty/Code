//类模板

#include <cstring>
#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
  Vector(int capacity = 2)
    : _pData(new T[capacity])
    ,  _size(0)
    , _capacity(capacity)
  {}

  //析构函数，在类内声明，类外定义
  ~Vector ();

  void PushBack(const T& data)
  {
    //增容
    if (_size == _capacity)
    {
      int new_capacity = _capacity * 2;
      T* tmp = new T[new_capacity]();//后面加()表示初始化为全零

      //将以前的数据拷到新的指针
      memcpy(tmp, _pData, sizeof(T) * _capacity);
      //将_pData里面的数据进行释放
      delete[] _pData;
      _pData = tmp;
      _capacity = new_capacity;
    }

    _pData[_size++] = data;
  }

  void PopBack()
  {
    --_size;
  }

  int& Size()
  {
    return _size; 
  }
  
  //运算符重载,返回引用实现，既可以删除也可以添加
  T& operator[] (const T& data)
  {
    return _pData[data];
  }

private:
  T* _pData;
  int _size;
  int _capacity;
};

//静态数据要在类外私有化
//template <class T>
//T* Vector<T>::_pData = nullptr;

//注意：类模板中的函数放在类外进行定义的时候，需要加模板参数列表
template <class T>
Vector<T>::~Vector()
{
  if (_pData)
  {
    delete[] _pData;
  }
}

int main()
{
  Vector<int> s1;
  s1.PushBack(1);
  s1.PushBack(2);
  s1.PushBack(3);
  s1.PushBack(4);
  s1[0] = 5;

  for (int i = 0; i < s1.Size(); i++)
  {
    cout << s1[i] << " ";
  }
  cout << endl;

  s1.PopBack();
  s1.PopBack();
  for (int i = 0; i < s1.Size(); i++)
  {
    cout << s1[i] << " ";
  }
  cout << endl;


  return 0;
}
