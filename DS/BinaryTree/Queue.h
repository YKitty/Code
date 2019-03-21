#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//对其进行声明，表示该结构体在别的的头文件中
struct BTNode;

typedef struct BTNode* DataType;

typedef struct QueueNode
{
	DataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* back;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, DataType d);
void QueuePop(Queue* pq);
DataType QueueFront(Queue* pq);
DataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

#endif //__QUEUE_H__