#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <assert.h>
#include "Stack.h" //为了快速排序的非递归，而引用栈
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef int DataType;

//插入排序
//直接插入排序
void InsertSort(DataType* arr, int sz);
//希尔排序
void ShellSort(DataType* arr, int sz);

//选择排序
//直接选择排序
void SelectSort(DataType* arr, int sz);
//堆排序
void HeapSort(DataType* arr, int sz);

//交换排序
//冒泡排序
void BubbleSort(DataType* arr, int sz);
//快速排序（递归）
void QuickSort(DataType* arr, int left, int right);
//快速排序（非递归）
void QuickSortNonR(DataType* arr, int left, int right);

//归并排序
void MergeSort(DataType* arr, int sz);

void PrintArr(DataType* arr, int sz);


#endif //__SORT_H__