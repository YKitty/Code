#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->stack = (DataType*)malloc(sizeof(DataType)*3);
	ps->top = -1;//ջ��ָ��ǰλ��
	ps->capacity = 3;
}

void StackDestory(Stack* ps)
{
	assert(ps);

	free(ps->stack);
	ps->stack = NULL;
	ps->top = -1;
	ps->capacity = 0;
}

void AddCapacity(Stack* ps)
{
	assert(ps);

	ps->stack = (DataType*)realloc(ps->stack, sizeof(DataType)*ps->capacity * 2);
	if (ps->stack == NULL)
	{
		perror("realloc size");
	}
	ps->capacity *= 2;
}

void StackPush(Stack* ps, DataType d)
{
	assert(ps);

	//�ж�ջ�Ĵ���ռ��Ƿ�����
	if (ps->top == ps->capacity - 1) //����
	{
		//��������
		AddCapacity(ps);
		//���д��
		ps->stack[++ps->top] = d;
	}
	else
	{
		//ֱ�ӽ��д��
		ps->stack[++ps->top] = d;
	}
}

void StackPop(Stack* ps)
{
	//���ջΪ�յĻ����޷����г�ջ
	assert(ps && ps->top != -1);
	
	ps->top--;
}
DataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->stack[ps->top];
}

//�� 0
//�ǿ� 1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == -1 ? 0 : 1;
}

int StackSize(Stack* ps)
{
	assert(ps);

	int size = ps->top + 1;
	return size;
}