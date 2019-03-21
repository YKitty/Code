#include "Sort.h"

void Swap(DataType* x, DataType* y)
{
	assert(x && y);

	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//思想：对于每次一个数字，都从最后的一个数字开始比较，依次向前比较找到合适的位置
//对于end每次取要比较元素的前一个元素，也就是已经排序好了的最后一个元素
void InsertSort(DataType* arr, int sz)
{
	assert(arr);

	int end = sz - 1;

	for (int i = 1; i < sz; i++)
	{
		end = i - 1;
		while (end >= 0 && arr[end + 1] < arr[end])
		{
			Swap(&(arr[end + 1]), &(arr[end]));
			end--;
		}
	}
}

//对于希尔排序也是插入排序，其实也就是对于插入排序进行了改进
//增加了预排序，从而可以让排序高效一点
void ShellSort(DataType* arr, int sz)
{
	assert(arr);

	for (int increment = 3; increment >= 1; increment--) //增量
	{
		for (int i = increment; i < sz; i++)
		{
			int end = i - increment;
			while (end >= 0 && arr[end + increment] < arr[end])
			{
				Swap(&(arr[end + increment]), &(arr[end]));
				end -= increment;
			}
		}
	}
}

void SelectSort(DataType* arr, int sz)
{
	assert(arr);

	int begin = 0; 
	int end = sz - 1;

	while (begin < end)
	{
		int minIndex = begin;
		int maxIndex = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[minIndex] > arr[i])
			{
				minIndex = i;
			}

			if (arr[maxIndex] < arr[i])
			{
				maxIndex = i;
			}
		}

		Swap(&arr[minIndex], &arr[begin]);
		if (begin == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&arr[maxIndex], &arr[end]);

		begin++;
		end--;
	}
}

void AdJustDown(DataType* arr, int sz, int parent)
{
	assert(arr);

	int child = parent * 2 + 1;

	while (child < sz)
	{
		if (child + 1 < sz && arr[child + 1] > arr[child])
		{
			child += 1;
		}

		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(DataType* arr, int sz)
{
	assert(arr);

	//调堆
	//从第一个非叶子结点的结点开始向下调堆
	for (int i = (sz - 2) >> 1; i >= 0; i--)
	{
		AdJustDown(arr, sz, i);
	}

	//排序
	for (int i = 0; i < sz; i++)
	{
		Swap(&arr[0], &arr[sz - i - 1]);

		AdJustDown(arr, sz - i - 1, 0);
	}
}

void BubbleSort(DataType* arr, int sz)
{
	assert(arr);

	for (int i = 0; i < sz - 1; i++)
	{
		int check = 0;
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				check = 1;
			}
		}

		if (check == 0)
		{
			break;
		}
	}
}

//左右同时向中间进行
int portion1(DataType* arr, int left, int right)
{
	assert(arr);

	int begin = left;
	int end = right;
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
		{
			begin++;
		}

		while (begin < end && arr[end] >= key)
		{
			end--;
		}

		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[right]);

	return begin;
}

//挖坑法
int portion2(DataType* arr, int left, int right)
{
	assert(arr);

	int key = arr[right];

	while (left < right)
	{
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[right] = arr[left];

		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[left] = arr[right];
	}
	arr[left] = key;

	return left;
}

int GetMidNum(DataType* arr, int left, int right)
{
	assert(arr);

	int mid = left + ((right - left) >> 1);

	if (arr[mid] > arr[left])
	{
		if (arr[mid] < arr[right])
		{
			return mid;
		}
		else if (arr[left] > arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if (arr[right] < arr[left])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}

//前后指针法
//思想：选取两个下标（cur，prev），一个是第一个数值的下标，另一个是第一个数值的前一个的下标
//对于cur，需要每次++并且和key值进行比较。如果小于key的话，并且prev也不是cur的前一个下标
//那么就将cur和prev的数值进行交换，否则的话只需要将prev的下标进行++
//prev：保存的就是小于key值的下标，
//cur：对于数组进行遍历
int portion3(DataType* arr, int left, int right)
{
	assert(arr);

	//三数取中法
	//找到首位，末位，中间较小的值，然后将其与末位的数值进行交换
	int index = GetMidNum(arr, left, right);
	Swap(&arr[index], &arr[right]);
	int key = arr[right];
	int prev = left - 1;
	int cur = left;

	//对于cur==right不进行判断，这是因为对于最后还是要将最后的一个数值
	//也就是key值，放在中间的位置，在循环外面有着专门的一次进行交换，所以不需要进行判断和进行交换了
	while (cur < right)
	{
		//防止第一个数值就是小于key的值，这个时候就不需要将该数值和prev进行交换
		//但是需要将prev进行++
		if (arr[cur] <= key && ++prev != arr[cur])
		{
			Swap(&arr[cur], &arr[prev]);
		}

		cur++;
	}
	//将中间数字放在中间
	Swap(&arr[right], &arr[++prev]);

	//返回中间的数值的下标
	return prev;
}

void QuickSort(DataType* arr, int left, int right)
{
	assert(arr);

	if (left < right)
	{
		//当区域分为较小的时候，采用插入排序
		if ((right - left + 1) < 10)
		{
			InsertSort(arr + left, right - left + 1);
		}
		else 
		{
			//int div = portion1(arr, left, right);
			//int div = portion2(arr, left, right);
			int div = portion3(arr, left, right);

			QuickSort(arr, left, div - 1);
			QuickSort(arr, div + 1, right);
		}
	}
}

//思想：每次都将左右下标的位置进行压栈，求出中间的数值，然后进行比较再次进行压栈处理
void QuickSortNonR(DataType* arr, int left, int right)
{
	assert(arr);

	Stack s;
	StackInit(&s);

	StackPush(&s, left);
	StackPush(&s, right);

	while (StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);

		int div = portion3(arr, begin, end);

		if (div - 1 > begin)
		{
			StackPush(&s, left);
			StackPush(&s, div - 1);
		}
		if (div + 1 < end)
		{
			StackPush(&s, div + 1);
			StackPush(&s, end);
		}
	}
}

void Merge(DataType* arr, int left1, int right1, int left2, int right2, DataType* tmp)
{
	assert(arr && tmp);

	//开始拷贝的位置
	int start = left1;

	//记录此次进行合并的起点位置
	int sLeft1 = left1;

	//记录下此次进行和并的长度
	int length = right2 - left1 + 1;

	//就和两条单链表进行合并一样的原理
	while (left1 <= right1 && left2 <= right2)
	{
		if (arr[left1] < arr[left2])
		{
			tmp[start++] = arr[left1++];
		}
		else
		{
			tmp[start++] = arr[left2++];
		}
	}

	while (left1 <= right1)
	{
		tmp[start++] = arr[left1++];
	}

	while (left2 <= right2)
	{
		tmp[start++] = arr[left2++];
	}

	//将tmp中的数据再次拷到arr的对应位置中
	memcpy(arr + sLeft1, tmp + sLeft1, sizeof(DataType) * length);
}

void PacketMerge(DataType* arr, int left, int right, DataType* tmp)
{
	assert(arr && tmp);

	if (left == right)
	{
		return;
	}

	int mid =left + ((right - left) >> 1);

	//分组
	PacketMerge(arr, left, mid, tmp);
	PacketMerge(arr, mid + 1, right, tmp);

	//合并
	//合并的时候，就像是对于两条链表进行合并并且排序一样
	Merge(arr, left, mid, mid + 1, right, tmp);
}


void MergeSort(DataType* arr, int sz)
{
	assert(arr);

	//存放要分组的数据
	DataType* tmp = (DataType*)malloc(sizeof(DataType) * sz);

	PacketMerge(arr, 0, sz - 1, tmp);

	free(tmp);
	tmp = NULL;

}

void PrintArr(DataType* arr, int sz)
{
	assert(arr);

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}