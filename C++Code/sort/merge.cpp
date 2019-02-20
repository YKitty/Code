#include <iostream>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void _merge(int* arr, size_t start1, size_t end1, size_t start2, size_t end2, int* tmp)
{
  assert(arr && tmp);
  

  size_t begin = start1;
  size_t length = end2 - start1 + 1;
  size_t i  = start1;
  //就像两个链表合并一样
  while (start1 <= end1 && start2 <= end2)
  {
    if (arr[start1] < arr[start2])
    {
      tmp[i++] = arr[start1++];
    }
    else 
    {
      tmp[i++] = arr[start2++];
    }
  }

  while (start1 <=  end1)
    tmp[i++] = arr[start1++];


  while (start2 <= end2)
    tmp[i++] = arr[start2++];
    
  memcpy(arr + begin, tmp + begin, length * sizeof(int));
}

void detached(int* arr, size_t start, size_t end, int* tmp)
{
  assert(arr && tmp);


  if (start == end)
  {
    //进行合并
    return ;
  }
   
  size_t mid = start + ((end - start) >> 1);

  detached(arr, start, mid, tmp);
  detached(arr, mid + 1, end, tmp);

  _merge(arr, start, mid, mid + 1, end, tmp);
}

void merge(int* arr, size_t len)
{
  int* tmp = (int*)malloc(len * sizeof(int));
  
  detached(arr, 0, len - 1, tmp);

  free(tmp);
  tmp = NULL;
}

int main()
{
  int arr[] = { 2, 1, 4, 6, 8, 2, 7 };
  size_t len = sizeof(arr) / sizeof(arr[0]);
  for (size_t i = 0; i < len; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  merge(arr, len);
  for (size_t i = 0; i < len; i++)
  {
    if (i == len - 1)
    {
      std::cout << arr[i];
      break;
    }
    std::cout << arr[i] << "<";
  }
  std::cout << std::endl;
  return 0;
}
