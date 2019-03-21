#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->stack = (DataType*)malloc(sizeof(DataType)*3);
	ps->top = -1;//栈顶指向当前位置
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

	//判断栈的储存空间是否已满
	if (ps->top == ps->capacity - 1) //满了
	{
		//进行增容
		AddCapacity(ps);
		//进行存放
		ps->stack[++ps->top] = d;
	}
	else
	{
		//直接进行存放
		ps->stack[++ps->top] = d;
	}
}

void StackPop(Stack* ps)
{
	//如果栈为空的话就无法进行出栈
	assert(ps && ps->top != -1);
	
	ps->top--;
}
DataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->stack[ps->top];
}

//空 0
//非空 1
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