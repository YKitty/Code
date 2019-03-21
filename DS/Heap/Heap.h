#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//初始化堆
void HeapInit(Heap* ph, HPDataType* a, int size);
//销毁堆
void HeapDestory(Heap* ph);
//向堆里面插入一个数据(插入到堆尾)
void HeapPush(Heap* ph, HPDataType x);
//删除一个数据(也就是删除堆顶的数据)
void HeapPop(Heap* ph);
//取出堆顶元素
HPDataType HeapTop(Heap* ph);
//判断堆是否为空
int HeapEmpty(Heap* ph);
//求堆的大小
int HeapSize(Heap* ph);
//打印堆
void HeapPrint(Heap* ph);
//采用堆排序，从小到大（采用大顶堆）
void HeapSortSmallToBig(HPDataType* a, int size);
//采用堆排序，从大到小（采用小顶堆）
void HeapSortBigToSmall(HPDataType* a, int size);




#endif //__HEAP_H__