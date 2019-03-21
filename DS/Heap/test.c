#include "Heap.h"

void TestHeap()
{
	Heap hp;
	HPDataType arr[] = { 34, 35, 32, 54, 65, 87, 9, 56, 90 };
	int size = sizeof(arr) / sizeof(arr[0]);

	HeapInit(&hp, arr, size);
	HeapPrint(&hp);

	HeapPush(&hp, 100);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	printf("堆的堆顶元素为:%d\n", HeapTop(&hp));

	printf("堆的大小:%d\n", HeapSize(&hp));
	
	if (HeapEmpty(&hp))
	{
		printf("堆不为空!\n");
	}
	else
	{
		printf("堆为空!\n");
	}

	//堆排序
	//从小到大（大顶堆）
	HeapSortSmallToBig(hp._a, hp._size);
	HeapPrint(&hp);
	//从大到小
	HeapSortBigToSmall(hp._a, hp._size);
	HeapPrint(&hp);

	HeapDestory(&hp);
}

int main()
{
	TestHeap();
	return 0;
}