#ifndef __TOPIC_H__
#define __TOPIC_H__

#include "Queue.h"
#include "Stack.h"

///////////////////////////////////////////////////////////////
//1.ʵ��һ��Pop��ջ��Push��ջ��Min����Сֵ��ʱ�临�Ӷ�ΪO(1)��ջ
//����һ������ÿһ��Push��ʱ��Push����Ԫ�أ�һ����ҪPush��ȥ��Ԫ�أ�һ������Сֵ
//Pop��ʱ��ҲҪPop����Ԫ�أ����������Сֵ���������ҪPop��Ԫ��
//��������ʹ��һ������ջ����ջֻ�����С��ֵ
//ÿ��ҪPush��ʱ�������Ԫ��С�ڸ���ջ�е�ջ��Ԫ�أ��ͽ���Ԫ��ͬʱPush��ջ1�У�ҲҪPush������ջ��
//����ֻ��ҪPush��ջ1��
//Pop��ʱ�򣬽�ջ1�и�Ԫ���븨��ջ��ջ��Ԫ�ؽ��бȽϣ������Ԫ�ص��ڸ���ջ��ջ��Ԫ���Ǿ�ͬʱPop
//����ֻ��Ҫ��ջ1����Pop����
//�������Сֵ�����ջ�Ļ����Ͷ���minstackҲҪ�����ջ



///////////////////////////////////////////////////////////
//��һ�ַ�����ֻ��Ҫһ��ջ
void Stack_O1Init(Stack* s);
void Stack_O1Destory(Stack* s);
DataType Stack_01Min(Stack* s);
void Stack_O1Push(Stack* s, DataType x);
void Stack_O1Pop(Stack* s);
int Stack_O1Empty(Stack* s);
int Stack_O1Size(Stack* s);
DataType Stack_O1Top(Stack* s);

////////////////////////////////////////////////////////////
//�ڶ��ַ���������һ������ջ����ջֻ�����Сֵ��MinStack
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
//2.������ջʵ�ֶ���
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
//3.����������ʵ��ջ
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
//4.Ԫ�س�ջ����ջ˳��ĺϷ���
//�Լ�write
int IsLegal(DataType* arr1, DataType* arr2, int Len);

///////////////////////////////////////////////////////////////
//5.һ������ʵ������ջ(����ջ)

//write��̬ջ�����������м���
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

//�����ݵ���ż����ջ
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