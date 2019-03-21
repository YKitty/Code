#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <assert.h>
#include "Stack.h" //Ϊ�˿�������ķǵݹ飬������ջ
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef int DataType;

//��������
//ֱ�Ӳ�������
void InsertSort(DataType* arr, int sz);
//ϣ������
void ShellSort(DataType* arr, int sz);

//ѡ������
//ֱ��ѡ������
void SelectSort(DataType* arr, int sz);
//������
void HeapSort(DataType* arr, int sz);

//��������
//ð������
void BubbleSort(DataType* arr, int sz);
//�������򣨵ݹ飩
void QuickSort(DataType* arr, int left, int right);
//�������򣨷ǵݹ飩
void QuickSortNonR(DataType* arr, int left, int right);

//�鲢����
void MergeSort(DataType* arr, int sz);

void PrintArr(DataType* arr, int sz);


#endif //__SORT_H__