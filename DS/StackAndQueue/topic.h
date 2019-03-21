#ifndef __TOPIC_H__
#define __TOPIC_H__

#include "Queue.h"
#include "Stack.h"

///////////////////////////////////////////////////////////////
//1.实现一个Pop出栈，Push入栈，Min求最小值的时间复杂度为O(1)的栈
//方法一：可以每一下Push的时候Push两个元素，一个是要Push进去的元素，一个是最小值
//Pop的时候也要Pop两个元素，上面的是最小值，下面就是要Pop的元素
//方法二：使用一个辅助栈，该栈只存放最小的值
//每次要Push的时候，如果该元素小于辅助栈中的栈顶元素，就将改元素同时Push到栈1中，也要Push到辅助栈中
//否则只需要Push到栈1中
//Pop的时候，将栈1中该元素与辅助栈的栈顶元素进行比较，如果该元素等于辅助栈的栈顶元素那就同时Pop
//否则只需要对栈1进行Pop操作
//如果将最小值多次入栈的话，就对于minstack也要多次入栈



///////////////////////////////////////////////////////////
//第一种方法，只需要一个栈
void Stack_O1Init(Stack* s);
void Stack_O1Destory(Stack* s);
DataType Stack_01Min(Stack* s);
void Stack_O1Push(Stack* s, DataType x);
void Stack_O1Pop(Stack* s);
int Stack_O1Empty(Stack* s);
int Stack_O1Size(Stack* s);
DataType Stack_O1Top(Stack* s);

////////////////////////////////////////////////////////////
//第二种方法，采用一个辅助栈，该栈只存放最小值，MinStack
typedef struct MinStack
{
	Stack s;
	Stack mins;
}MinStack;

void MinStackInit(MinStack* pms);
void MinStackDestory(MinStack* pms);

void MinStackPush(MinStack* pms, DataType x);
void MinStackPop(MinStack* pms);
DataType MinStackTop(MinStack* pms);
int MinStackEmpty(MinStack* pms);
int MinStackSize(MinStack* pms);
DataType MinStackMin(MinStack* pms);

/////////////////////////////////////////////////////////////
//2.用两个栈实现队列
typedef struct QueueByTwoStack
{
	Stack stack1;
	Stack stack2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);
void QueueByTwoStackDestory(QueueByTwoStack* qts);

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x);
void QueueByTwoStackPop(QueueByTwoStack* qts);
DataType QueueByTwoStackFront(QueueByTwoStack* qts);
int QueueByTwoStackEmpty(QueueByTwoStack* qts);
int QueueByTwoStackSize(QueueByTwoStack* qts);

////////////////////////////////////////////////////////////
//3.用两个队列实现栈
typedef struct StackByTwoQueue
{
	Queue queue1;
	Queue queue2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x);
void StackByTwoQueuePop(StackByTwoQueue* stq);
DataType StackByTwoQueueTop(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);

/////////////////////////////////////////////////////////////
//4.元素出栈，入栈顺序的合法性
//自己write
int IsLegal(DataType* arr1, DataType* arr2, int Len);

///////////////////////////////////////////////////////////////
//5.一个数组实现两个栈(共享栈)

//write静态栈，从两侧向中间走
#define MAXSIZE 100
typedef struct ShareStack
{
	DataType SStack[MAXSIZE];
	int LeftTop;
	int RightTop;
}ShareStack;

void ShareStackInit(ShareStack* pss);
void ShareStackDestory(ShareStack* pss);

void ShareStackLeftPush(ShareStack* pss, DataType x);
void ShareStackRightPush(ShareStack* pss, DataType x);
void ShareStackLeftPop(ShareStack* pss);
void ShareStackRightPop(ShareStack* pss);

int ShareStackEmpty(ShareStack* pss);
int ShareStackSize(ShareStack* pss);
DataType ShareStackLeftTop(ShareStack* pss);
DataType ShareStackRightTop(ShareStack* pss);

//可增容的奇偶共享栈
typedef struct ShareStack_T
{
	DataType* ShareStack;
	int capacity;
	int top1;
	int top2;
}ShareStack_T;

void ShareStack_TInit(ShareStack_T* pss);
void ShareStack_TDestory(ShareStack_T* pss, int which);

void ShareStack_TPush(ShareStack_T* pss, DataType x, int which);
void ShareStack_TPop(ShareStack_T* pss, int which);
DataType ShareStack_TTop(ShareStack_T* pss, int which);
int ShareStack_TEmpty(ShareStack_T* pss, int which);
int ShareStack_TSize(ShareStack_T* pss, int which);






#endif //__TOPIC_H__