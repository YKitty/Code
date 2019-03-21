#include "SeqList.h"

void TestPushBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
}

TestPushFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);

}

void TestFind()
{
	int pos = -1;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 2);
	if (pos == -1)
	{
		printf("û�ҵ�\n");
	}
	else
	{
		printf("�ҵ��ˣ��±�Ϊ:%d\n", pos);
	}
}

void TestInsert()
{
	int pos = -1;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	//��ָ��λ�õ�ǰ�����
	Insert(&seq, pos, 5);//4 5 3 2 1
	PrintSeqList(&seq);
}
void TestErase()
{
	int pos = -1;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	Insert(&seq, pos, 5);//4 5 3 2 1
	pos = Find(&seq, 3);
	//ɾ��ָ��λ�õ�Ԫ��
	Erase(&seq, pos);
	PrintSeqList(&seq);
}

void TestRemove()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	//ɾ��ָ��Ԫ��
	Remove(&seq, 3);
	PrintSeqList(&seq);
}

void TestRemoveAll()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	RemoveAll(&seq, 3);
	PrintSeqList(&seq);
}

void TestSize()
{
	int ret = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	if (!Empty(&seq))
	{
		ret = Size(&seq);
		printf("���Ա�ĳ���Ϊ:%d\n", ret);
	}
}

void TestbubbleSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	BubbleSort(&seq);
	PrintSeqList(&seq);
}

void TestSelectSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	SelectSort_OP(&seq);
	PrintSeqList(&seq);
}

void TestBinarySearch()
{
	int pos = -1;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PrintSeqList(&seq);
	pos = BinarySearch_R(&seq, 0, seq.sz - 1, 4);
	if (pos == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�±�Ϊ:%d\n", pos);
	}
}

int main()
{
	//TestPushBack();//����β�����뷨
	//TestPushFront();//����ͷ�����뷨
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestRemoveAll();
	//TestSize();
	TestbubbleSort();
	//TestSelectSort();
	//TestBinarySearch();
	return 0;
}