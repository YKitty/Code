#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;

//双向循环带头结点链表的节点类型
typedef struct ListNode
{
	struct ListNode* _next;
	struct ListNode* _prev;
	LTDataType _data;
}ListNode;

//创建一个指向双向循环带头结点链表的指针
typedef struct List
{
	struct ListNode* _head;
}List;


//双向循环带头结点链表的重点是插入和删除结点
//因为对于头插尾插头删尾删均可由插入和删除操作来完成
void ListInit(List* pl);
void ListDestory(List* pl);

void ListPushFront(List* pl, LTDataType x);
void ListPopFront(List* pl);
void ListPushBack(List* pl, LTDataType x);
void ListPopBack(List* pl);

//插入数据是在指定结点pos前面插入
void ListInsert(ListNode* pos, LTDataType x);
//删除指定结点pos
void ListErase(List* pl, ListNode* pos);
//求双向链表的长度
int ListSize(List* pl);
//判断双向链表是否为空
//空 0
//非空 1
int ListEmpty(List* pl);
//查找一个结点
ListNode* ListFind(List* pl, LTDataType x);
void PrintList(List* pl);


#endif //__LIST_H__