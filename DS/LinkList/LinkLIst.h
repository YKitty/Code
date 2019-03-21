#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;

typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;

void InitLinkList(pList* ppList);
void DestoryLinkList(pList* ppList);
void PushBack(pList* ppList, DataType d);
void PopBack(pList* ppList);
void PushFront(pList* ppList, DataType d);
void PopFront(pList* ppList);

pNode Find(pList pList, DataType d);
void Insert(pList* ppList, pNode pos,DataType d);
void Erase(pList* ppList, pNode pos);
void Remove(pList* ppList, DataType d);
void RemoveAll(pList* ppList, DataType d);
void EraseNotTailNode(pNode pos);


void PrintLinkList(pList pList);
int GetLinkListLength(pList pList);

//����������
//1.�����������
void PrintTailToHead(pList pList);
void PrintTailToHead_recursion(pList pList);
//2.��������(����һ�Σ�ʱ�临�Ӷ�:O(n))
void ReverseLinkList(pList* ppList);
//3.û��ͷָ��ɾ��һ������β���Ľ��(�滻ɾ��)
void EraseNodeNotTail(pNode pos);
//��ʱ�临�Ӷ�ΪO(1)ɾ��һ�����
void DeleteNode(pList* phead, pNode pos);
//4.û��ͷָ�����һ�����(�滻����)
void InsertNode(pNode pos, DataType d);
//5.Լɪ��
void JosephusCycle(pList* ppList, int k);
//6.�����������(ð������)
void BubbleSort(pList pList);
//7.�ϲ��������������ϲ�����Ȼ����
pList Merge(pList pList1, pList pList2);
//�ݹ�
pList Merge_R(pList pList1, pList pList2);
//8.����������м��㣬Ҫ��ֻ�ܱ���һ������
pNode FindMidNode(pList pList);
//9.���ҵ�����ĵ�����k����㣬Ҫ��ֻ�ܱ���һ������
pNode FindLastKNode(pList pList, int k);
//10.�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ�
pNode CheckCycle(pList pList);
int GetCycleLength(pList meet);
pNode StartCycle(pList pList, pNode meet);
//11.�ж����������Ƿ��ཻ�����ཻ���󽻵�
bool CheckMeet(pList pList1, pList pList2);
pNode GetMeet(pList pList1, pList pList2);
//12.��������ĸ��� 
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬
//����һ��randomָ��ָ����������е�һ�����������NULL
//����Ҫ��ʵ�ָ�������������ظ��ƺ��������
ComplexNode* BuyNode_Complex(DataType d);
void PrintComplexList(ComplexNode* node1);
ComplexNode* CopyComplexList(ComplexNode* List);
//13.��������������Ľ����Լ��
//����
pList Intersection(pList pList1, pList pList2);
//�
pList Difset(pList pList1, pList pList2);

#endif //__LINKLIST_H__