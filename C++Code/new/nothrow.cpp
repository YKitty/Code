#include <iostream>

int main()
{
  char* p = NULL;
  int i = 0;//记录申请多少内存

  do
  {
    //每次申请1M
    p = new (std::nothrow) char[1024 * 1024];
    i++;
  }while(p);

  if (NULL == p)
  {
    std::cout << "new " << i - 1 << "M memory\n" << "第 " << i << "次内存分配失败";
  }
  
  char* ptr = nullptr;

  ptr = new (std::nothrow) char[2047 * 1024 * 1024];
  if (ptr == nullptr)
  {
    std::cout << "new (std::nothrow) char[2047M] error" << std::endl;
  }
  else 
  {
    std::cout << "new (std::nothrow) char[2047M] sucessed" << std::endl;
  }

  return 0;
}
