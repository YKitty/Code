#include "Sort.h"

void TestInsertSort()
{
	int arr[] = { 6, 4, 4 , 2, 1, 78 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	/*PrintArr(arr, sz);
	InsertSort(arr, sz);
	PrintArr(arr, sz);*/

	PrintArr(arr, sz);
	ShellSort(arr, sz);
	PrintArr(arr, sz);
}

void TestSelectSort()
{
	int arr[] = { 6, 4 , 2, 1, 78 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	PrintArr(arr, sz);
	SelectSort(arr, sz);
	PrintArr(arr, sz);
}

void TestHeapSort()
{
	int arr[] = { 6, 4 , 2, 1, 78, 54, 8, 10, 11 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	PrintArr(arr, sz);
	HeapSort(arr, sz);
	PrintArr(arr, sz);
}

void TestBubbleSort()
{
	int arr[] = { 2, 1, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	PrintArr(arr, sz);
	BubbleSort(arr, sz);
	PrintArr(arr, sz);
}

void TestQuickSort()
{
	int arr[] = { 7, 8, 2, 4, 5, 1, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	/*PrintArr(arr, sz);
	QuickSort(arr, 0, sz - 1);
	PrintArr(arr, sz);*/

	PrintArr(arr, sz);
	QuickSortNonR(arr, 0, sz - 1);
	PrintArr(arr, sz);
}

void TestMergeSort()
{
	int arr[] = { 7, 8, 2, 4, 5, 1, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	PrintArr(arr, sz);
	MergeSort(arr, sz);
	PrintArr(arr, sz);
}

void TestInsertAndShellContrast()
{
	int arr1[100000] = { 0 };
	int arr2[100000] = { 0 };
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100000; i++)
	{
		arr1[i] = rand(); //rand函数对100取余表示0--99
		arr2[i] = arr1[i];
	}
	
	int start = clock();
	InsertSort(arr1, 10000);
	int end = clock();

	printf("use InsertSort time: %d\n", end - start);

	start = clock();
	ShellSort(arr2, 10000);
	end = clock();

	printf("use ShellSort time: %d\n", end - start);
}

void TestShellSort()
{
	int arr[] = { 2, 1, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	PrintArr(arr, sz);
	ShellSort(arr, sz);
	PrintArr(arr, sz);
}

int main()
{
	//TestInsertSort();
	//TestSelectSort();
	TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestMergeSort();
	//TestInsertAndShellContrast();
	//TestShellSort();
}