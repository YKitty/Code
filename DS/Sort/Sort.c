#include "Sort.h"

void Swap(DataType* x, DataType* y)
{
	assert(x && y);

	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//˼�룺����ÿ��һ�����֣���������һ�����ֿ�ʼ�Ƚϣ�������ǰ�Ƚ��ҵ����ʵ�λ��
//����endÿ��ȡҪ�Ƚ�Ԫ�ص�ǰһ��Ԫ�أ�Ҳ�����Ѿ�������˵����һ��Ԫ��
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

//����ϣ������Ҳ�ǲ���������ʵҲ���Ƕ��ڲ�����������˸Ľ�
//������Ԥ���򣬴Ӷ������������Чһ��
void ShellSort(DataType* arr, int sz)
{
	assert(arr);

	for (int increment = 3; increment >= 1; increment--) //����
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

	//����
	//�ӵ�һ����Ҷ�ӽ��Ľ�㿪ʼ���µ���
	for (int i = (sz - 2) >> 1; i >= 0; i--)
	{
		AdJustDown(arr, sz, i);
	}

	//����
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

//����ͬʱ���м����
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

//�ڿӷ�
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

//ǰ��ָ�뷨
//˼�룺ѡȡ�����±꣨cur��prev����һ���ǵ�һ����ֵ���±꣬��һ���ǵ�һ����ֵ��ǰһ�����±�
//����cur����Ҫÿ��++���Һ�keyֵ���бȽϡ����С��key�Ļ�������prevҲ����cur��ǰһ���±�
//��ô�ͽ�cur��prev����ֵ���н���������Ļ�ֻ��Ҫ��prev���±����++
//prev������ľ���С��keyֵ���±꣬
//cur������������б���
int portion3(DataType* arr, int left, int right)
{
	assert(arr);

	//����ȡ�з�
	//�ҵ���λ��ĩλ���м��С��ֵ��Ȼ������ĩλ����ֵ���н���
	int index = GetMidNum(arr, left, right);
	Swap(&arr[index], &arr[right]);
	int key = arr[right];
	int prev = left - 1;
	int cur = left;

	//����cur==right�������жϣ�������Ϊ���������Ҫ������һ����ֵ
	//Ҳ����keyֵ�������м��λ�ã���ѭ����������ר�ŵ�һ�ν��н��������Բ���Ҫ�����жϺͽ��н�����
	while (cur < right)
	{
		//��ֹ��һ����ֵ����С��key��ֵ�����ʱ��Ͳ���Ҫ������ֵ��prev���н���
		//������Ҫ��prev����++
		if (arr[cur] <= key && ++prev != arr[cur])
		{
			Swap(&arr[cur], &arr[prev]);
		}

		cur++;
	}
	//���м����ַ����м�
	Swap(&arr[right], &arr[++prev]);

	//�����м����ֵ���±�
	return prev;
}

void QuickSort(DataType* arr, int left, int right)
{
	assert(arr);

	if (left < right)
	{
		//�������Ϊ��С��ʱ�򣬲��ò�������
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

//˼�룺ÿ�ζ��������±��λ�ý���ѹջ������м����ֵ��Ȼ����бȽ��ٴν���ѹջ����
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

	//��ʼ������λ��
	int start = left1;

	//��¼�˴ν��кϲ������λ��
	int sLeft1 = left1;

	//��¼�´˴ν��кͲ��ĳ���
	int length = right2 - left1 + 1;

	//�ͺ�������������кϲ�һ����ԭ��
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

	//��tmp�е������ٴο���arr�Ķ�Ӧλ����
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

	//����
	PacketMerge(arr, left, mid, tmp);
	PacketMerge(arr, mid + 1, right, tmp);

	//�ϲ�
	//�ϲ���ʱ�򣬾����Ƕ�������������кϲ���������һ��
	Merge(arr, left, mid, mid + 1, right, tmp);
}


void MergeSort(DataType* arr, int sz)
{
	assert(arr);

	//���Ҫ���������
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