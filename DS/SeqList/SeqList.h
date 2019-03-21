#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX 10
#define TypeData int

typedef struct SeqList
{
	TypeData data[MAX];
	int sz;//已经存放的个数
}SeqList,* pSeqList;

void InitSeqList(pSeqList pSeq);
void PushBack(pSeqList pSeq, TypeData d);
void PopBack(pSeqList pSeq);
void PushFront(pSeqList pSeq, TypeData d);
void PopFront(pSeqList pSeq);
int Find(pSeqList pSeq, TypeData d);
void Insert(pSeqList pSeq, int pos, TypeData d);
void Erase(pSeqList pSeq, int pos);
void Remove(pSeqList pSeq, TypeData d);
void RemoveAll(pSeqList pSeq, TypeData d);
int Size(pSeqList pSeq);
int Empty(pSeqList pSeq);
void BubbleSort(pSeqList pSeq);
void SelectSort(pSeqList pSeq);
void SelectSort_OP(pSeqList pSeq);
int BinarySearch(pSeqList pSeq, TypeData d);
int BinarySearch_R(pSeqList pSeq, int left, int right, TypeData d);
void PrintSeqList(pSeqList pSeq);


#endif //__SEQLIST_H__