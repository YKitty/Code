#include "Heap.h"

//交换两个数据
void Swap(HPDataType* a, HPDataType* b)
{
	assert(a && b);

	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//向下调整堆（调为大堆）
//思想：判断parent与child中较大值的结点的比较，如果parent < child，调整，
//然后在进行刚才调整过的child处的结点，直到叶子节点。结束：叶子节点的孩子结点超出数组的下标最大值
void ADJustDown(HPDataType* a, int size, int parent)
{
	assert(a);

	//左孩子结点
	int child = parent * 2 + 1;
	//左孩子结点的下标小于数组的最大下标时，堆是一个完全二叉树
	while (child < size)
	{
		//取出最大的孩子结点,只有当右孩子存在时，才能求两个中较大的一个孩子
		//在Pop的时候也有着大作用，如果没有加上的话，就有可能让Pop出现访问
		if (((child + 1) < size) && a[child + 1] > a[child])
		{
			child++;
		}

		//交换结点，向下调整
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}

		//如果要调整的的这个结点，比起的孩子结点大的话，那就不用调整了
		else
		{
			break;
		}
	}
}

//对堆进行初始化，也就是要建堆
void HeapInit(Heap* ph, HPDataType* a, int n)
{
	assert(ph && a);

	int i = 0;
	//对堆进行初始化
	ph->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	for (i = 0; i < n; i++)
	{
		ph->_a[i] = a[i];
	}
	ph->_size = n;
	ph->_capacity = n;

	//调整堆
	//思路:从最后一个非叶子结点开始调整堆(向下调整)，结束：调整到堆顶
	//双亲结点等于孩子结点减一除以二
	//构建堆的时间复杂度为O(N)
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		//向下调整
		ADJustDown(ph->_a, ph->_size, i);
	}

}

//对堆进行销毁
//思路：将size变为0，capacity变为0，数组指针指向的空间变为NULL
void HeapDestory(Heap* ph)
{
	assert(ph);

	free(ph->_a);
	ph->_a = NULL;
	ph->_capacity = 0;
	ph->_size = 0;
}

//从下到上调整堆
void ADJustUp(Heap* ph, int child)
{
	assert(ph);

	int parent = (child - 1) >> 1;
	//开始调整，直到child == 0
	while (child > 0)
	{
		if (ph->_a[parent] < ph->_a[child])
		{
			Swap(&ph->_a[parent], &ph->_a[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		//如果child小于或者等于parent的话，那就不用调整堆了
		else
		{
			break;
		}
	}
}

//对堆进行插入一个元素
//思路：首先要判断堆对的空间是否已被占满，占满增容，否则进行插入
//也就是在该堆的最后一个元素进行插入，然后在进行向上调整
void HeapPush(Heap* ph, HPDataType x)
{
	assert(ph);

	//堆的空间已经满了，进行增容
	if (ph->_capacity == ph->_size)
	{
		ph->_a = (HPDataType*)realloc(ph->_a, sizeof(HPDataType) * (ph->_capacity += 4));
	}

	//先插入，从下到上调整堆
	//插入
	ph->_a[ph->_size] = x;
	ph->_size++;
	//从下到上调整堆
	ADJustUp(ph, ph->_size - 1);
}

//取出堆顶元素
//思路：将堆顶元素与最后一个元素进行交换，然后再删除最后一个元素，对于此时的堆，进行一次，向下调整即可
void HeapPop(Heap* ph)
{
	assert(ph);

	//删除堆顶元素
	Swap(&ph->_a[0], &ph->_a[ph->_size - 1]);
	ph->_size--;

	//从堆顶位置进行一次向下调整堆的操作
	ADJustDown(ph->_a, ph->_size, 0);
}

//返回堆顶元素
HPDataType HeapTop(Heap* ph)
{
	assert(ph);

	return ph->_a[0];
}

//判断队是否为空
//空 0
//非空 1 
int HeapEmpty(Heap* ph)
{
	assert(ph);

	return ph->_size == 0 ? 0 : 1;
}

//求堆的大小
int HeapSize(Heap* ph)
{
	assert(ph);

	return ph->_size;
}

//堆的输出函数
void HeapPrint(Heap* ph)
{
	assert(ph);

	for (int i = 0; i < ph->_size; i++)
	{
		printf("%d ", ph->_a[i]);
	}
	printf("\n");
}

//堆排序（从小到大）   采用大顶堆
//思想：开始讲其变为一个大顶堆，然后每次将堆顶与最后一个元素进行交换，再令该队减少一个元素再次进行向下调整
void HeapSortSmallToBig(HPDataType* a, int size)
{
	assert(a);

	int start_size = size;
	//给进来一个数组，现将该数组进行一次建堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		ADJustDown(a, size, i);
	}

	//当size变为0的时候，那么该堆已经变为了一个有序的序列了
	while (size > 1)
	{
		Swap(&a[0], &a[size - 1]);
		size--;

		//对于新的堆进行调整，时间复杂度O(logN)
		ADJustDown(a, size, 0);
	}
	//该函数排序函数的时间复杂度为O(NlogN)
	//调整完之后size变为了0，对于这个堆，size还应该是原来的size
	size = start_size;
}

//小顶堆从上到下，调整
void ADJustDownSmallHeap(HPDataType* a, int size, int parent)
{
	assert(a);

	//左孩子结点
	int child = parent * 2 + 1;
	//左孩子结点的下标小于数组的最大下标时，堆是一个完全二叉树
	while (child < size)
	{
		//取出最大的孩子结点,只有当右孩子存在时，才能求两个中较大的一个孩子
		//在Pop的时候也有着大作用，如果没有加上的话，就有可能让Pop出现访问
		if (a[child + 1] < a[child] && ((child + 1) < size))
		{
			child++;
		}

		//交换结点，向下调整
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}

		//如果要调整的的这个结点，比起的孩子结点大的话，那就不用调整了
		else
		{
			break;
		}
	}
}


//对数组进行排序（从大到小） 采用小顶堆
void HeapSortBigToSmall(HPDataType* a, int size)
{
	assert(a);

	int start_size = size;
	//先将该数组变为一个小顶堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		ADJustDownSmallHeap(a, size, i);
	}

	while (size > 1)
	{
		Swap(&a[0], &a[size - 1]);
		size--;

		//每次交换之后就要向下调整
		ADJustDownSmallHeap(a, size, 0);
	}
	size = start_size;
}

