#include "Heap.h"

//������������
void Swap(HPDataType* a, HPDataType* b)
{
	assert(a && b);

	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//���µ����ѣ���Ϊ��ѣ�
//˼�룺�ж�parent��child�нϴ�ֵ�Ľ��ıȽϣ����parent < child��������
//Ȼ���ڽ��иղŵ�������child���Ľ�㣬ֱ��Ҷ�ӽڵ㡣������Ҷ�ӽڵ�ĺ��ӽ�㳬��������±����ֵ
void ADJustDown(HPDataType* a, int size, int parent)
{
	assert(a);

	//���ӽ��
	int child = parent * 2 + 1;
	//���ӽ����±�С�����������±�ʱ������һ����ȫ������
	while (child < size)
	{
		//ȡ�����ĺ��ӽ��,ֻ�е��Һ��Ӵ���ʱ�������������нϴ��һ������
		//��Pop��ʱ��Ҳ���Ŵ����ã����û�м��ϵĻ������п�����Pop���ַ���
		if (((child + 1) < size) && a[child + 1] > a[child])
		{
			child++;
		}

		//������㣬���µ���
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}

		//���Ҫ�����ĵ������㣬����ĺ��ӽ���Ļ����ǾͲ��õ�����
		else
		{
			break;
		}
	}
}

//�Զѽ��г�ʼ����Ҳ����Ҫ����
void HeapInit(Heap* ph, HPDataType* a, int n)
{
	assert(ph && a);

	int i = 0;
	//�Զѽ��г�ʼ��
	ph->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	for (i = 0; i < n; i++)
	{
		ph->_a[i] = a[i];
	}
	ph->_size = n;
	ph->_capacity = n;

	//������
	//˼·:�����һ����Ҷ�ӽ�㿪ʼ������(���µ���)���������������Ѷ�
	//˫�׽����ں��ӽ���һ���Զ�
	//�����ѵ�ʱ�临�Ӷ�ΪO(N)
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		//���µ���
		ADJustDown(ph->_a, ph->_size, i);
	}

}

//�Զѽ�������
//˼·����size��Ϊ0��capacity��Ϊ0������ָ��ָ��Ŀռ��ΪNULL
void HeapDestory(Heap* ph)
{
	assert(ph);

	free(ph->_a);
	ph->_a = NULL;
	ph->_capacity = 0;
	ph->_size = 0;
}

//���µ��ϵ�����
void ADJustUp(Heap* ph, int child)
{
	assert(ph);

	int parent = (child - 1) >> 1;
	//��ʼ������ֱ��child == 0
	while (child > 0)
	{
		if (ph->_a[parent] < ph->_a[child])
		{
			Swap(&ph->_a[parent], &ph->_a[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		//���childС�ڻ��ߵ���parent�Ļ����ǾͲ��õ�������
		else
		{
			break;
		}
	}
}

//�Զѽ��в���һ��Ԫ��
//˼·������Ҫ�ж϶ѶԵĿռ��Ƿ��ѱ�ռ����ռ�����ݣ�������в���
//Ҳ�����ڸöѵ����һ��Ԫ�ؽ��в��룬Ȼ���ڽ������ϵ���
void HeapPush(Heap* ph, HPDataType x)
{
	assert(ph);

	//�ѵĿռ��Ѿ����ˣ���������
	if (ph->_capacity == ph->_size)
	{
		ph->_a = (HPDataType*)realloc(ph->_a, sizeof(HPDataType) * (ph->_capacity += 4));
	}

	//�Ȳ��룬���µ��ϵ�����
	//����
	ph->_a[ph->_size] = x;
	ph->_size++;
	//���µ��ϵ�����
	ADJustUp(ph, ph->_size - 1);
}

//ȡ���Ѷ�Ԫ��
//˼·�����Ѷ�Ԫ�������һ��Ԫ�ؽ��н�����Ȼ����ɾ�����һ��Ԫ�أ����ڴ�ʱ�Ķѣ�����һ�Σ����µ�������
void HeapPop(Heap* ph)
{
	assert(ph);

	//ɾ���Ѷ�Ԫ��
	Swap(&ph->_a[0], &ph->_a[ph->_size - 1]);
	ph->_size--;

	//�ӶѶ�λ�ý���һ�����µ����ѵĲ���
	ADJustDown(ph->_a, ph->_size, 0);
}

//���ضѶ�Ԫ��
HPDataType HeapTop(Heap* ph)
{
	assert(ph);

	return ph->_a[0];
}

//�ж϶��Ƿ�Ϊ��
//�� 0
//�ǿ� 1 
int HeapEmpty(Heap* ph)
{
	assert(ph);

	return ph->_size == 0 ? 0 : 1;
}

//��ѵĴ�С
int HeapSize(Heap* ph)
{
	assert(ph);

	return ph->_size;
}

//�ѵ��������
void HeapPrint(Heap* ph)
{
	assert(ph);

	for (int i = 0; i < ph->_size; i++)
	{
		printf("%d ", ph->_a[i]);
	}
	printf("\n");
}

//�����򣨴�С����   ���ô󶥶�
//˼�룺��ʼ�����Ϊһ���󶥶ѣ�Ȼ��ÿ�ν��Ѷ������һ��Ԫ�ؽ��н���������öӼ���һ��Ԫ���ٴν������µ���
void HeapSortSmallToBig(HPDataType* a, int size)
{
	assert(a);

	int start_size = size;
	//������һ�����飬�ֽ����������һ�ν���
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		ADJustDown(a, size, i);
	}

	//��size��Ϊ0��ʱ����ô�ö��Ѿ���Ϊ��һ�������������
	while (size > 1)
	{
		Swap(&a[0], &a[size - 1]);
		size--;

		//�����µĶѽ��е�����ʱ�临�Ӷ�O(logN)
		ADJustDown(a, size, 0);
	}
	//�ú�����������ʱ�临�Ӷ�ΪO(NlogN)
	//������֮��size��Ϊ��0����������ѣ�size��Ӧ����ԭ����size
	size = start_size;
}

//С���Ѵ��ϵ��£�����
void ADJustDownSmallHeap(HPDataType* a, int size, int parent)
{
	assert(a);

	//���ӽ��
	int child = parent * 2 + 1;
	//���ӽ����±�С�����������±�ʱ������һ����ȫ������
	while (child < size)
	{
		//ȡ�����ĺ��ӽ��,ֻ�е��Һ��Ӵ���ʱ�������������нϴ��һ������
		//��Pop��ʱ��Ҳ���Ŵ����ã����û�м��ϵĻ������п�����Pop���ַ���
		if (a[child + 1] < a[child] && ((child + 1) < size))
		{
			child++;
		}

		//������㣬���µ���
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}

		//���Ҫ�����ĵ������㣬����ĺ��ӽ���Ļ����ǾͲ��õ�����
		else
		{
			break;
		}
	}
}


//������������򣨴Ӵ�С�� ����С����
void HeapSortBigToSmall(HPDataType* a, int size)
{
	assert(a);

	int start_size = size;
	//�Ƚ��������Ϊһ��С����
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		ADJustDownSmallHeap(a, size, i);
	}

	while (size > 1)
	{
		Swap(&a[0], &a[size - 1]);
		size--;

		//ÿ�ν���֮���Ҫ���µ���
		ADJustDownSmallHeap(a, size, 0);
	}
	size = start_size;
}

