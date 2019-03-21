#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	
	pq->front = NULL;
	pq->back = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->front;
	while (cur)
	{
		QueueNode* del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	pq->front = NULL;
	pq->back = NULL;
}

QueueNode* BuyNode(DataType d)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("Buy newNode");
	}

	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

void QueuePush(Queue* pq, DataType d)
{
	assert(pq);

	//第一次入队
	if (pq->front == NULL)
	{
		QueueNode* newNode = BuyNode(d);
		pq->back = newNode;
		pq->front = pq->back;
	}
	else
	{
		QueueNode* newNode = BuyNode(d);
		pq->back->next = newNode;
		pq->back = newNode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);

	pq->front = pq->front->next;
}

DataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->front->data;
}

DataType QueueBack(Queue* pq)
{
	assert(pq);

	return pq->back->data;



}


//空 0
//非空 1
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL ? 0 : 1;
}

int QueueSize(Queue* pq)
{
	int size = 0;
	assert(pq);

	QueueNode* cur = pq->front;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size;
}