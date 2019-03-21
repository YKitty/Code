#include "Stack.h"
#include "Queue.h"
#include "topic.h"

void TestStack()
{
	Stack s = { NULL };
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("栈的容量:%d\n", StackSize(&s));
	while (StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	StackDestory(&s);
	printf("\n");
}

void TestQueue()
{
	Queue q = { NULL };
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("队列的大小:%d\n", QueueSize(&q));
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
	printf("\n");
}

void TestQueueByTwoStack()
{
	QueueByTwoStack queue;

	QueueByTwoStackInit(&queue);
	QueueByTwoStackPush(&queue, 1);
	QueueByTwoStackPush(&queue, 2);
	QueueByTwoStackPush(&queue, 3);
	QueueByTwoStackPush(&queue, 4);

	while (QueueByTwoStackEmpty(&queue))
	{
		printf("%d ", QueueByTwoStackFront(&queue));
		QueueByTwoStackPop(&queue);
	}
	printf("\n");
	QueueByTwoStackDestory(&queue);
}
	

void TestStackByTwoQueue()
{
	StackByTwoQueue stack;
	StackByTwoQueueInit(&stack);
	StackByTwoQueuePush(&stack, 1);
	StackByTwoQueuePush(&stack, 2);
	StackByTwoQueuePush(&stack, 3);
	StackByTwoQueuePush(&stack, 4);

	while (StackByTwoQueueEmpty(&stack))
	{
		printf("%d ", StackByTwoQueueTop(&stack));
		StackByTwoQueuePop(&stack);
	}
	printf("\n");
	StackByTwoQueueDestory(&stack);
}

void TestIsLegal()
{
	int arr1[5] = { 1 };
	int arr2[5] = { 1 };
	int flag = 0;
	flag = IsLegal(arr1, arr2, 5);
	if (flag == 0)
	{
		printf("不合法!\n");
	}
	else
	{
		printf("合法!\n");
	}
}

void TestStack_O1()
{
	Stack s;
	Stack_O1Init(&s);
	Stack_O1Push(&s, 5);
	Stack_O1Push(&s, 3);
	Stack_O1Push(&s, 4);
	Stack_O1Push(&s, 6);
	Stack_O1Push(&s, 7);

	printf("最小值为:%d\n", Stack_01Min(&s));
	
	Stack_O1Destory(&s);
}

void TestShareStack()
{
	ShareStack ss;
	ShareStackInit(&ss);
	ShareStackLeftPush(&ss, 1);
	ShareStackLeftPush(&ss, 2);
	ShareStackLeftPush(&ss, 3);
	ShareStackLeftPush(&ss, 4);

	while (ss.LeftTop != -1)
	{
		printf("%d ", ShareStackLeftTop(&ss));
		ShareStackLeftPop(&ss);
	}
	printf("\n");

	ShareStackRightPush(&ss, 4);
	ShareStackRightPush(&ss, 3);
	ShareStackRightPush(&ss, 2);
	ShareStackRightPush(&ss, 1);

	while (ss.RightTop != MAXSIZE)
	{
		printf("%d ", ShareStackRightTop(&ss));
		ShareStackRightPop(&ss);
	}
	printf("\n");


	ShareStackDestory(&ss);

}

void TestMinStack()
{
	MinStack ms;

	MinStackInit(&ms);
	MinStackPush(&ms, 2);
	MinStackPush(&ms, 1);
	MinStackPush(&ms, 1);
	MinStackPush(&ms, 8);
	MinStackPush(&ms, 1);
	printf("Size:%d\n", MinStackSize(&ms));
	printf("Top:%d\n", MinStackTop(&ms));
	printf("empty:%d\n", MinStackEmpty(&ms));

	printf("min:%d\n", MinStackMin(&ms));
	
	MinStackPop(&ms);
	printf("min:%d\n", MinStackMin(&ms));

	MinStackPop(&ms);
	printf("min:%d\n", MinStackMin(&ms));
	
	MinStackPop(&ms);
	printf("min:%d\n", MinStackMin(&ms));
	
	MinStackPop(&ms);
	printf("min:%d\n", MinStackMin(&ms));

	MinStackDestory(&ms);
}

void TestShareStack_T()
{
	ShareStack_T sst;
	ShareStack_TInit(&sst);
	ShareStack_TPush(&sst, 1, 1);
	ShareStack_TPush(&sst, 2, 1);
	ShareStack_TPush(&sst, 3, 1);
	ShareStack_TPush(&sst, 4, 1);
	ShareStack_TPush(&sst, 1, 2);
	ShareStack_TPush(&sst, 2, 2);
	ShareStack_TPush(&sst, 3, 2);

	printf("size1:%d\n", ShareStack_TSize(&sst, 1));
	printf("size2:%d\n", ShareStack_TSize(&sst, 2));

	while (ShareStack_TEmpty(&sst, 1))
	{
		printf("%d ", ShareStack_TTop(&sst, 1));
		ShareStack_TPop(&sst, 1);
	}
	printf("\n");

	while (ShareStack_TEmpty(&sst, 2))
	{
		printf("%d ", ShareStack_TTop(&sst, 2));
		ShareStack_TPop(&sst, 2);
	}
	printf("\n");

	ShareStack_TDestory(&sst, 1);
	ShareStack_TDestory(&sst, 2);
}


int main()
{
	//TestStack();
	//TestQueue();
	//TestQueueByTwoStack();
	//TestStackByTwoQueue();
	//TestIsTrue();
	//TestStack_O1();
	//TestShareStack();
	//TestMinStack();
	TestShareStack_T();
	return 0;
}
