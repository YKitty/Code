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

//��ʼ����
void HeapInit(Heap* ph, HPDataType* a, int size);
//���ٶ�
void HeapDestory(Heap* ph);
//����������һ������(���뵽��β)
void HeapPush(Heap* ph, HPDataType x);
//ɾ��һ������(Ҳ����ɾ���Ѷ�������)
void HeapPop(Heap* ph);
//ȡ���Ѷ�Ԫ��
HPDataType HeapTop(Heap* ph);
//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap* ph);
//��ѵĴ�С
int HeapSize(Heap* ph);
//��ӡ��
void HeapPrint(Heap* ph);
//���ö����򣬴�С���󣨲��ô󶥶ѣ�
void HeapSortSmallToBig(HPDataType* a, int size);
//���ö����򣬴Ӵ�С������С���ѣ�
void HeapSortBigToSmall(HPDataType* a, int size);




#endif //__HEAP_H__