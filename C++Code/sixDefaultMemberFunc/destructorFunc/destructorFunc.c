#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

typedef int DataType;

class SeqList
{
public:
  SeqList (int capacity = 10)
  {
    _pData = (DataType*)malloc(capacity * sizeof(DataType));
    assert(_pData);

    _size = 0;
    _capacity = 0;
  }

  ~SeqList()
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
  DataType* _pData;
  int _size;
  int _capacity;
};

int main()
{
  return 0;
}
