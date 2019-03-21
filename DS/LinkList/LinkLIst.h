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

//链表面试题
//1.逆序输出链表
void PrintTailToHead(pList pList);
void PrintTailToHead_recursion(pList pList);
//2.逆序链表(遍历一次，时间复杂度:O(n))
void ReverseLinkList(pList* ppList);
//3.没有头指针删除一个不是尾结点的结点(替换删除)
void EraseNodeNotTail(pNode pos);
//在时间复杂度为O(1)删除一个结点
void DeleteNode(pList* phead, pNode pos);
//4.没有头指针插入一个结点(替换插入)
void InsertNode(pNode pos, DataType d);
//5.约瑟夫环
void JosephusCycle(pList* ppList, int k);
//6.单链表的排序(冒泡排序)
void BubbleSort(pList pList);
//7.合并两个有序链表，合并后依然有序
pList Merge(pList pList1, pList pList2);
//递归
pList Merge_R(pList pList1, pList pList2);
//8.查找链表的中间结点，要求只能遍历一次链表
pNode FindMidNode(pList pList);
//9.查找单链表的倒数第k个结点，要求只能遍历一次链表
pNode FindLastKNode(pList pList, int k);
//10.判断单链表是否带环？若带环，求环的长度？求环的入口点
pNode CheckCycle(pList pList);
int GetCycleLength(pList meet);
pNode StartCycle(pList pList, pNode meet);
//11.判断两个链表是否相交，若相交，求交点
bool CheckMeet(pList pList1, pList pList2);
pNode GetMeet(pList pList1, pList pList2);
//12.复杂链表的复制 
//一个链表的每个节点，有一个指向next指针指向下一个节点，
//还有一个random指针指向这个链表中的一个随机结点或者NULL
//现在要求实现复制这个链表，返回复制后的新链表
ComplexNode* BuyNode_Complex(DataType d);
void PrintComplexList(ComplexNode* node1);
ComplexNode* CopyComplexList(ComplexNode* List);
//13.求两个有序单链表的交集以及差集
//交集
pList Intersection(pList pList1, pList pList2);
//差集
pList Difset(pList pList1, pList pList2);

#endif //__LINKLIST_H__