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

	printf("�ѵĶѶ�Ԫ��Ϊ:%d\n", HeapTop(&hp));

	printf("�ѵĴ�С:%d\n", HeapSize(&hp));
	
	if (HeapEmpty(&hp))
	{
		printf("�Ѳ�Ϊ��!\n");
	}
	else
	{
		printf("��Ϊ��!\n");
	}

	//������
	//��С���󣨴󶥶ѣ�
	HeapSortSmallToBig(hp._a, hp._size);
	HeapPrint(&hp);
	//�Ӵ�С
	HeapSortBigToSmall(hp._a, hp._size);
	HeapPrint(&hp);

	HeapDestory(&hp);
}

int main()
{
	TestHeap();
	return 0;
}