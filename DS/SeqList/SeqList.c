#include "SeqList.h"

void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));//对数组进行初始化
}

void PushBack(pSeqList pSeq, TypeData d)
{
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	pSeq->data[pSeq->sz] = d;
	pSeq->sz++;
}

void PrintSeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法输出\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}

void PopBack(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	pSeq->sz--;
}

void PushFront(pSeqList pSeq, TypeData d)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = d;
	pSeq->sz++;
}

void PopFront(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

int Find(pSeqList pSeq, TypeData d)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("没有元素可供查找\n");
		return -1;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}

void Insert(pSeqList pSeq, int pos, TypeData d)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->sz);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= pos; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[pos] = d;
	pSeq->sz++;
}

void Erase(pSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->sz);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (i = pos; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

void Remove(pSeqList pSeq, TypeData d)
{
	int i = 0;
	int pos = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			break;
		}
	}
	if (i == pSeq->sz)
	{
		printf("删除的元素不存在\n");
		return;
	}
	for ( ; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
#if 0
	pos = Find(pSeq, d);
	Erase(pSeq, pos);
#endif
}

void RemoveAll(pSeqList pSeq, TypeData d)
{
	int i = 0;
	int count = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != d)
		{
			pSeq->data[count++] = pSeq->data[i];
		}
	}
	pSeq->sz = count;
}

int Size(pSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

int Empty(pSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz == 0;
}
void Swap(TypeData *a, TypeData *b)
{
	assert(a != NULL);
	assert(b != NULL);
	TypeData tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	//如果不进行交换的话，那么就是序列已经有序了，不需要在进行排列
	//用flag标识确定是否进行交换了
	bool flag = true;
	for (i = 0; i < pSeq->sz - 1 && true; i++)
	{
		flag = false;
		for (j = 0; j < pSeq->sz - 1 - i; j++)
		{
			if (pSeq->data[j] > pSeq->data[j + 1])
			{
				Swap(pSeq->data + j, pSeq->data + j + 1);
				flag = true;
			}
		}
	}
}

void SelectSort(pSeqList pSeq)
{
	int end = pSeq->sz-1;
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		int max = 0;
		//找每一次最大值的下标
		for (j = 1; j < pSeq->sz - i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}
		if (max != pSeq->sz - 1 - i)
		{
			Swap(pSeq->data + max, pSeq->data + pSeq->sz - 1 - i);
		}
		//Swap(pSeq->data + max, pSeq->data + end);
		//end--;
	}
}

void SelectSort_OP(pSeqList pSeq)
{
	int start = 0;
	int end = pSeq->sz - 1;
	int i = 0;
	assert(pSeq != NULL);
	while (start < end)
	{
		int min = start;
		int max = start;
		for (i = start; i <= end; i++)
		{
			if (pSeq->data[min] > pSeq->data[i])
			{
				min = i;
			}
			if (pSeq->data[max] < pSeq->data[i])
			{
				max = i;
			}
		}
		if (min != start)
		{
			Swap(pSeq->data + min, pSeq->data + start);
		}
		if (max == start)
		{
			max = min;
		}
		if (max != end)
		{
			Swap(pSeq->data + max, pSeq->data + end);
		}
		start++;
		end--;
	}
}

int BinarySearch(pSeqList pSeq, TypeData d)
{
	int left = 0;
	int right = pSeq->sz - 1;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法查找\n");
		return -1;
	}
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (pSeq->data[mid] > d)
		{
			right = mid - 1;
		}
		else if (pSeq->data[mid] < d)
		{
			left = mid + 1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;
}

int BinarySearch_R(pSeqList pSeq, int left, int right, TypeData d)
{
	int mid = left + (right - left) / 2;
	if (left > right)
	{
		return -1;
	}
	if (pSeq->data[mid] > d)
	{
		return BinarySearch_R(pSeq, left, mid - 1, d);
	}
	else if (pSeq->data[mid] < d)
	{
		return BinarySearch_R(pSeq, mid + 1, right, d);
	}
	else
	{
		return mid;
	}
}


