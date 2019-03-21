#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;

//˫��ѭ����ͷ�������Ľڵ�����
typedef struct ListNode
{
	struct ListNode* _next;
	struct ListNode* _prev;
	LTDataType _data;
}ListNode;

//����һ��ָ��˫��ѭ����ͷ��������ָ��
typedef struct List
{
	struct ListNode* _head;
}List;


//˫��ѭ����ͷ���������ص��ǲ����ɾ�����
//��Ϊ����ͷ��β��ͷɾβɾ�����ɲ����ɾ�����������
void ListInit(List* pl);
void ListDestory(List* pl);

void ListPushFront(List* pl, LTDataType x);
void ListPopFront(List* pl);
void ListPushBack(List* pl, LTDataType x);
void ListPopBack(List* pl);

//������������ָ�����posǰ�����
void ListInsert(ListNode* pos, LTDataType x);
//ɾ��ָ�����pos
void ListErase(List* pl, ListNode* pos);
//��˫������ĳ���
int ListSize(List* pl);
//�ж�˫�������Ƿ�Ϊ��
//�� 0
//�ǿ� 1
int ListEmpty(List* pl);
//����һ�����
ListNode* ListFind(List* pl, LTDataType x);
void PrintList(List* pl);


#endif //__LIST_H__