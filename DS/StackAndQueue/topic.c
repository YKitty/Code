#include "Queue.h"
#include "Stack.h"
#include "topic.h"

///////////////////////////////////////////////////////////////
//1.ʵ��һ��Pop��ջ��Push��ջ��Min����Сֵ��ʱ�临�Ӷ�ΪO(1)��ջ

void Stack_O1Init(Stack* s)
{
	assert(s);

	StackInit(s);
}

void Stack_O1Destory(Stack* s)
{
	assert(s);

	StackDestory(s);
}

DataType Stack_01Min(Stack* s)
{
	assert(s);

	return StackTop(s);
}

void Stack_O1Push(Stack* s, DataType x)
{
	assert(s);

	if (StackEmpty(s) == 0)
	{
		StackPush(s, x);
		StackPush(s, x);
	}
	else
	{
		int min = StackTop(s);
		if (min > x)
		{
			min = x;
		}
		StackPush(s, x);
		StackPush(s, min);
	}
}

void Stack_O1Pop(Stack* s)
{
	assert(s);

	StackPop(s);
	StackPop(s);
}

int Stack_O1Empty(Stack* s)
{
	assert(s);

	return StackEmpty(s);
}
int Stack_O1Size(Stack* s)
{
	assert(s);

	return StackSize(s) / 2;
}

DataType Stack_O1Top(Stack* s)
{
	assert(s);

	DataType min = StackTop(s);
	StackPop(s);
	DataType d = StackTop(s);
	StackPush(s, min);
	return d;
}


///////////////////////////////////////////////////////////////////////////////
//�ڶ��ַ�����ʹ�ø���ջ
void MinStackInit(MinStack* pms)
{
	assert(pms);

	StackInit(&pms->s);
	StackInit(&pms->mins);
}

void MinStackDestory(MinStack* pms)
{
	assert(pms);

	StackDestory(&pms->s);
	StackDestory(&pms->mins);
}

void MinStackPush(MinStack* pms, DataType x)
{
	assert(pms);

	StackPush(&pms->s, x);
	if ((StackEmpty(&pms->mins) == 0)
		|| (StackTop(&pms->mins) >= x))
	{
		StackPush(&pms->mins, x);
	}
}

void MinStackPop(MinStack* pms)
{
	assert(pms);

	if (StackTop(&pms->s) == StackTop(&pms->mins))
	{
		StackPop(&pms->mins);
	}
	StackPop(&pms->s);
}

DataType MinStackTop(MinStack* pms)
{
	assert(pms);

	return StackTop(&pms->s);
}

//�� 0
//�ǿ� 1
int MinStackEmpty(MinStack* pms)
{
	assert(pms);

	return StackEmpty(&pms->s);
}

int MinStackSize(MinStack* pms)
{
	assert(pms);

	return StackSize(&pms->s);
}

DataType MinStackMin(MinStack* pms)
{
	assert(pms);

	return StackTop(&pms->mins);
}



////////////////////////////////////////////////////////////////////
//2.������ջʵ��һ������
void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	assert(qts);

	StackInit(&qts->stack1);
	StackInit(&qts->stack2);
}

void QueueByTwoStackDestory(QueueByTwoStack* qts)
{
	assert(qts);

	StackDestory(&qts->stack1);
	StackDestory(&qts->stack2);
}

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x)
{
	assert(qts);

	StackPush(&qts->stack1, x);
}

void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts);

	if (StackEmpty(&qts->stack2) != 0)
	{
		StackPop(&qts->stack2);
	}
	else
	{
		while (StackEmpty(&qts->stack1))
		{
			StackPush(&qts->stack2, StackTop(&qts->stack1));
			StackPop(&qts->stack1);
		}
		StackPop(&qts->stack2);
	}
}

DataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	assert(qts);

	if (StackEmpty(&qts->stack2) != 0)
	{
		return StackTop(&qts->stack2);
	}
	else
	{
		while (StackEmpty(&qts->stack1))
		{
			StackPush(&qts->stack2, StackTop(&qts->stack1));
			StackPop(&qts->stack1);
		}
		return StackTop(&qts->stack2);
	}
}

int QueueByTwoStackEmpty(QueueByTwoStack* qts)
{
	assert(qts);

	return StackEmpty(&qts->stack1) | StackEmpty(&qts->stack2);
}

int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	assert(qts);

	return StackSize(&qts->stack1) + StackSize(&qts->stack2);
}



/////////////////////////////////////////////////////////////////////////
//3.����������ʵ��һ��ջ
void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);

	QueueInit(&stq->queue1);
	QueueInit(&stq->queue2);
}

void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	assert(stq);

	QueueDestory(&stq->queue1);
	QueueDestory(&stq->queue2);
}

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{
	assert(stq);

	if (QueueEmpty(&stq->queue1))
	{
		QueuePush(&stq->queue1, x);
	}
	else
	{
		QueuePush(&stq->queue2, x);
	}
}
void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	assert(stq);

	Queue* empty = &stq->queue1;
	Queue* nonempty = &stq->queue2;
	if (QueueEmpty(&stq->queue1))
	{
		empty = &stq->queue2;
		nonempty = &stq->queue1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	QueuePop(nonempty);
}

DataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	assert(stq);

	if (QueueEmpty(&stq->queue1))
	{
		return QueueBack(&stq->queue1);
	}
	else
	{
		return QueueBack(&stq->queue2);
	}
}

int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	assert(stq);

	return QueueEmpty(&stq->queue1) | QueueEmpty(&stq->queue2);
}

int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	assert(stq);

	return QueueSize(&stq->queue1) + QueueSize(&stq->queue2);
}

/////////////////////////////////////////////////////////////
//4.Ԫ�س�ջ����ջ˳��ĺϷ���
int IsLegal(DataType* arr1, DataType* arr2, int Len)
{
	Stack s;
	//i��ʾ��ջ���е��±�
	//j��ʾ��ջ���е��±�
	int i = 0;
	int j = 0;
	assert(arr1 && arr2);

	StackInit(&s);
	StackPush(&s, arr1[i]);
	while (i < Len)
	{
		if (StackTop(&s) == arr2[j])
		{
			StackPop(&s);
			j++;
		}
		else
		{
			StackPush(&s, arr1[++i]);
		}
	}

	if (StackEmpty(&s) == 0)
	{
		//�Ϸ�
		return 1;
	}
	else
	{
		//���Ϸ�
		return 0;
	}
}

///////////////////////////////////////////////////////////////
//5.һ������ʵ������ջ(����ջ)
//���þ�̬ջ�����ܶ�̬���ӣ�ջ��������
void ShareStackInit(ShareStack* pss)
{
	assert(pss);

	pss->LeftTop = -1;
	pss->RightTop = MAXSIZE;
}

void ShareStackDestory(ShareStack* pss)
{
	assert(pss);

	pss->LeftTop = -1;
	pss->RightTop = MAXSIZE;
}

void ShareStackLeftPush(ShareStack* pss, DataType x)
{
	assert(pss);

	//��߽���ѹջ�Ļ���ջ��ָ��Ҫ��1
	pss->SStack[++pss->LeftTop] = x;
}

void ShareStackRightPush(ShareStack* pss, DataType x)
{
	assert(pss);

	//�ұ߽���ѹջ�Ļ���ջ��ָ��Ҫ��1
	pss->SStack[--pss->RightTop] = x;
}

void ShareStackLeftPop(ShareStack* pss)
{
	assert(pss);

	//��߽��г�ջ�Ļ���ջ��ָ���1
	--pss->LeftTop;
}

void ShareStackRightPop(ShareStack* pss)
{
	assert(pss);

	//�ұ߽��г�ջ�Ļ���ջ��ָ���1
	++pss->RightTop;
}

//�� 0
//�ǿ� 1
int ShareStackEmpty(ShareStack* pss)
{
	assert(pss);

	//ջ���Ļ�����ߵ�ջ����1�����ұߵ�ջ��
	return (pss->LeftTop + 1) == pss->RightTop ? 1 : 0;
}

int ShareStackSize(ShareStack* pss)
{
	assert(pss);

	return (pss->LeftTop + 1 + MAXSIZE - pss->RightTop);
}
DataType ShareStackLeftTop(ShareStack* pss)
{
	assert(pss);

	return pss->SStack[pss->LeftTop];
}

DataType ShareStackRightTop(ShareStack* pss)
{
	assert(pss);

	return pss->SStack[pss->RightTop];
}

//���Զ�̬���ӵĹ���ջ����ż����ջ
void ShareStack_TInit(ShareStack_T* pss)
{
	assert(pss);

	//��ʾջ��ջ����λ�þ��ǵ�ǰλ��
	pss->ShareStack = (DataType*)malloc(sizeof(DataType) * 2);
	pss->capacity = 2;
	pss->top1 = -2;
	pss->top2 = -1;
}

void ShareStack_TDestory(ShareStack_T* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1)
	{
		pss->top1 = -2;
		if (pss->top2 == -1)
		{
			free(pss->ShareStack);
			pss->ShareStack = NULL;
		}
	}
	else
	{
		pss->top2 = -1;
		if (pss->top1 == -2)
		{
			free(pss->ShareStack);
			pss->ShareStack = NULL;
		}
	}
}

void AddCapacityShareStack(ShareStack_T* pss)
{
	assert(pss);

	pss->ShareStack = (DataType*)realloc(pss->ShareStack, sizeof(DataType) * (pss->capacity + 2));
	if (pss->ShareStack == NULL)
	{
		perror("Add Capacity for ShareStack");
	}
	pss->capacity += 2;
}


void ShareStack_TPush(ShareStack_T* pss, DataType x, int which)
{
	assert(pss && (which == 1 || which == 2));

	//��ջ1����ѹջ
	if (which == 1)
	{
		//�ж�ջ�Ĵ洢�ռ��Ƿ�����
		//ջ��
		if (pss->top1 == pss->capacity - 2)
		{
			//��������
			AddCapacityShareStack(pss);
		}
		//ֱ�ӽ���ѹջ
		pss->top1 += 2;
		pss->ShareStack[pss->top1] = x;
	}
	//��ջ2����ѹջ
	else
	{
		//�ж�ջ�Ĵ洢�ռ��Ƿ�����
		//ջ��
		if (pss->top2 == pss->capacity - 1)
		{
			//��������
			AddCapacityShareStack(pss);
		}
		//ֱ�ӽ���ѹջ
		pss->top2 += 2;
		pss->ShareStack[pss->top2] = x;
	}
}

void ShareStack_TPop(ShareStack_T* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	//ջ1
	if (which == 1)
	{
		assert(pss->top1 != -2);
		pss->top1 -= 2;
	}
	else
	{
		assert(pss->top1 != -1);
		pss->top2 -= 2;
	}
}

DataType ShareStack_TTop(ShareStack_T* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1)
	{
		return pss->ShareStack[pss->top1];
	}
	else
	{
		return pss->ShareStack[pss->top2];
	}
}

int ShareStack_TEmpty(ShareStack_T* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1)
	{
		return pss->top1 == -2 ? 0 : 1;
	}
	else
	{
		return pss->top2 == -1 ? 0 : 1;
	}
}

int ShareStack_TSize(ShareStack_T* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1)
	{
		if (pss->top1 == -2)
		{
			return 0;
		}
		else 
		{
			return (pss->top1 / 2 + 1);
		}
	}
	else
	{
		if (pss->top2 == -1)
		{
			return 0;
		}
		else 
		{
			return (pss->top2 + 1) / 2;
		}
	}
}

