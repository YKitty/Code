#include "Queue.h"
#include "Stack.h"
#include "topic.h"

///////////////////////////////////////////////////////////////
//1.实现一个Pop出栈，Push入栈，Min求最小值的时间复杂度为O(1)的栈

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
//第二种方法：使用辅助栈
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

//空 0
//非空 1
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
//2.用两个栈实现一个队列
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
//3.用两个队列实现一个栈
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
//4.元素出栈，入栈顺序的合法性
int IsLegal(DataType* arr1, DataType* arr2, int Len)
{
	Stack s;
	//i表示入栈序列的下标
	//j表示出栈序列的下标
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
		//合法
		return 1;
	}
	else
	{
		//不合法
		return 0;
	}
}

///////////////////////////////////////////////////////////////
//5.一个数组实现两个栈(共享栈)
//采用静态栈，不能动态增加，栈顶在两侧
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

	//左边进行压栈的话，栈顶指针要加1
	pss->SStack[++pss->LeftTop] = x;
}

void ShareStackRightPush(ShareStack* pss, DataType x)
{
	assert(pss);

	//右边进行压栈的话，栈顶指针要减1
	pss->SStack[--pss->RightTop] = x;
}

void ShareStackLeftPop(ShareStack* pss)
{
	assert(pss);

	//左边进行出栈的话，栈顶指针减1
	--pss->LeftTop;
}

void ShareStackRightPop(ShareStack* pss)
{
	assert(pss);

	//右边进行出栈的话，栈顶指针加1
	++pss->RightTop;
}

//空 0
//非空 1
int ShareStackEmpty(ShareStack* pss)
{
	assert(pss);

	//栈满的话，左边的栈顶加1等于右边的栈顶
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

//可以动态增加的共享栈，奇偶共享栈
void ShareStack_TInit(ShareStack_T* pss)
{
	assert(pss);

	//表示栈是栈顶的位置就是当前位置
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

	//对栈1进行压栈
	if (which == 1)
	{
		//判断栈的存储空间是否已满
		//栈满
		if (pss->top1 == pss->capacity - 2)
		{
			//进行增容
			AddCapacityShareStack(pss);
		}
		//直接进行压栈
		pss->top1 += 2;
		pss->ShareStack[pss->top1] = x;
	}
	//对栈2进行压栈
	else
	{
		//判断栈的存储空间是否已满
		//栈满
		if (pss->top2 == pss->capacity - 1)
		{
			//进行增容
			AddCapacityShareStack(pss);
		}
		//直接进行压栈
		pss->top2 += 2;
		pss->ShareStack[pss->top2] = x;
	}
}

void ShareStack_TPop(ShareStack_T* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	//栈1
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

