#include "LinkLIst.h"

void InitLinkList(pList* ppList)
{
	assert(ppList != NULL);
	*ppList = NULL;
}

void DestoryLinkList(pList* ppList)
{
	pNode del = NULL;
	pNode cur = NULL;
	assert(ppList != NULL);
	cur = *ppList;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*ppList = NULL;
}

void PrintLinkList(pList pList)
{
	pNode cur = pList;
	while (cur != NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}

int GetLinkListLength(pList pList)
{
	int count = 0;
	if (pList == NULL)//无结点
	{
		return 0;
	}
	else//有结点
	{
		while (pList != NULL)
		{
			count++;
			pList = pList->next;
		}
		return count;
	}
}


pList BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

void PushBack(pList* ppList, DataType d)
{
	pNode newNode = NULL;
	assert(ppList != NULL);
	newNode = BuyNode(d);
	if (*ppList == NULL) //第一个结点的插入
	{
		*ppList = newNode;
	}
	else //多于一个结点
	{
		pNode cur = *ppList;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void PopBack(pList* ppList)
{
	assert(ppList != NULL);
	if (*ppList == NULL)//空
	{
		return;
	}
	else if ((*ppList)->next == NULL)//一个结点
	{
		pNode del = *ppList;
		*ppList = del->next;
		free(del);
		del = NULL;
	}
	else//大于一个结点
	{
		pNode cur = *ppList;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void PushFront(pList* ppList, DataType d)
{
	pNode newNode = NULL;
	assert(ppList != NULL);
	newNode = BuyNode(d);
	newNode->next = *ppList;
	*ppList = newNode;
}

void PopFront(pList* ppList)
{
	assert(ppList != NULL);
	if (*ppList == NULL)//无结点，不进行删除
	{
		return;
	}
	else
	{
		pNode del = *ppList;
		*ppList = del->next;
		free(del);
		del = NULL;
	}
}

pNode Find(pList pList, DataType d)
{
	if (pList == NULL)//无结点
	{
		return NULL;
	}
	else//有结点
	{
		pNode cur = pList;
		while (cur && cur->data != d)
		{
			cur = cur->next;
		}
		if (cur != NULL)//找到
		{
			return cur;
		}
		else//没找到
		{
			return NULL;
		}
	}
}

void Insert(pList* ppList, pNode pos, DataType d)
{
	pNode newNode = NULL;
	assert(ppList != NULL);
	assert(pos != NULL);
	newNode = BuyNode(d);
	if (*ppList == NULL)//无结点
	{
		return;
	}
	else //有结点
	{
		pNode cur = *ppList;
		if (pos == cur)//pos是第一个结点
		{
			newNode->next = *ppList;
			*ppList = newNode;
		}
		else//有多于一个结点
		{
			while (cur->next != pos)
			{
				cur = cur->next;
			}
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}
}

void Erase(pList* ppList, pNode pos)
{
	assert(ppList != NULL);
	assert(pos != NULL);
	if (*ppList == NULL)//无结点
	{
		return;
	}
	else //有结点
	{

		pNode cur = *ppList;
		if (pos == cur)//pos是第一个结点
		{
			pNode del = *ppList;
			*ppList = del->next;
			free(del);
			del = NULL;
		}
		else//有多于一个结点
		{
			while ((cur->next != NULL) && (cur->next != pos))
			{
				cur = cur->next;
			}
			if (cur->next != NULL)//找到要删除的结点
			{
				cur->next = pos->next;
				free(pos);
				pos = NULL;
			}
		}
	}
}

void Remove(pList* ppList, DataType d)
{
	assert(ppList != NULL);
	if (*ppList == NULL)//无结点
	{
		return;
	}
	else//有结点
	{
		pNode cur = *ppList;
		if (cur->data == d)//第一个结点就是要删除节点
		{
			pNode del = cur;
			*ppList = del->next;
			free(del);
			del = NULL;
		}
		else //第一个结点不是要删除节点
		{
			while ((cur->next != NULL) && (cur->next->data != d))
			{
				cur = cur->next;
			}
			if (cur->next != NULL)//找到要删除的结点
			{
				pNode del = cur->next;
				cur->next = del->next;
				free(del);
				del = NULL;
			}
		}
	}
}

void RemoveAll(pList* ppList, DataType d)
{
	assert(ppList != NULL);
	if (*ppList == NULL)//无结点
	{
		return;
	}
	else//有结点
	{
		pNode cur = *ppList;
		while (cur != NULL)
		{
			if (cur->data == d)//找到要删的结点
			{
				pNode del = NULL;
				if (cur == *ppList)//要删除的结点是第一个
				{
					del = cur;
					cur = cur->next;
					*ppList = del->next;
					free(del);
					del = NULL;
				}
				else //要删除的结点不是第一个
				{
					pNode prev = *ppList;
					while (prev->next != cur)
					{
						prev = prev->next;
					}
					del = cur;
					cur = cur->next;
					prev->next = del->next;
					free(del);
					del = NULL;
				}
			}
			else
			{
				cur = cur->next;
			}
		}
	}
}

void EraseNotTailNode(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	del = pos->next;
	pos->data = del->data;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//递归写法
void PrintTailToHead_recursion(pList pList)
{
	if (pList == NULL)
	{
		return;
	}
	PrintTailToHead_recursion(pList->next);
	printf("%d  ", pList->data);
}

//非递归写法
void PrintTailToHead(pList pList)
{
	pNode cur = NULL;
	pNode tail = NULL;
	while (tail != pList)
	{
		cur = pList;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		tail = cur;
		printf("%d-->", cur->data);
	}
	printf("over\n");
}

//逆置/反转单链表
void ReverseLinkList(pList* ppList)
{
	pNode cur = NULL;
	pNode tmp = NULL;
	assert(ppList != NULL);
	cur = *ppList;
	tmp = cur->next;
	if ((cur == NULL) && (cur->next == NULL))//有一个结点或者没有节点
	{
		return;
	}
	else//大于一个结点
	{
		pNode head = NULL;
		while (cur != NULL)
		{
			cur->next = head;
			head = cur;
			cur = tmp;
			if (tmp != NULL)
			{
				tmp = tmp->next;
			}
		}
		*ppList = head;
	}
}

void EraseNodeNotTail(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	//替换删除法
	del = pos->next;
	pos->data = del->data;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void DeleteNode(pList* phead, pNode pos)
{
	assert(phead && pos);

	//删除的不是尾结点（并且结点个数大于1）
	if (pos->next != NULL)
	{
		pNode del = pos->next;
		pos->data = del->data;
		pos->next = del->next;

		free(del);
		del = NULL;
	}
	//链表只有一个结点，删除的是头结点，也是尾结点
	else if (*phead == pos)
	{
		pNode del = pos;
		*phead = NULL;

		free(del);
		del = NULL;
	}
	//链表中有多个节点，删除的是尾结点
	else
	{
		pNode cur = *phead;

		while (cur->next != pos)
		{
			cur = cur->next;
		}

		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void InsertNode(pNode pos, DataType d)
{
	pNode newNode = NULL;
	assert(pos != NULL);
	//替换插入法
	newNode = BuyNode(pos->data);
	newNode->next = pos->next;
	pos->next = newNode;
	pos->data = d;
}

//void JosephusCycle(pList* ppList, int k)
//{
//	pNode tail = NULL;
//	pNode cur = NULL;
//	assert(ppList != NULL);
//	tail = *ppList;
//	cur = *ppList;
//
//	//建环
//	while (tail->next != NULL)
//	{
//		tail = tail->next;
//	}
//	tail->next = *ppList;
//
//	//求幸存者
//	while (cur != cur->next)
//	{
//		pNode del = NULL;
//		int count = k;
//		while (--count)
//		{
//			cur = cur->next;
//		}
//		printf("自杀：%d\n", cur->data);
//		//替换删除
//		del = cur->next;
//		cur->data = del->data;
//		cur->next = del->next;
//		free(del);
//		del = NULL;
//	}
//	printf("幸存者：%d\n", cur->data);
//}

//约瑟夫环（练习）
void  JosephusCycle(pList* pplist, int k)
{
	pNode tail = NULL;
	pNode cur = NULL;
	assert(pplist != NULL);

	//建环
	cur = *pplist;
	tail = *pplist;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = cur;

	//进行运算
	while (cur != cur->next)
	{
		//删除第k个结点
		int count = k;//保证每次k不会改变
		while (--count)
		{
			cur = cur->next;
		}
		printf("自杀：%d  ", cur->data);
		printf("\n");
		//替换删除法
		pNode del = cur->next;
		cur->data = del->data;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("幸存者:%d\n", cur->data);
}

void BubbleSort(pList pList)
{
	pNode cur = NULL;
	pNode next = NULL;
	pNode tail = NULL;
	for (cur = pList; cur->next != NULL; cur = cur->next)//次数
	{
		for (next = pList; next->next != tail; next = next->next)
		{
			if (next->data > next->next->data)
			{
				DataType tmp = next->data;
				next->data = next->next->data;
				next->next->data = tmp;
			}
		}
		tail = next;
	}
}

pList Merge(pList pList1, pList pList2)
{
	pList newList = NULL;
	pNode tail = NULL;
	pNode cur1 = pList1;
	pNode cur2 = pList2;
	if (cur1->data < cur2->data)
	{
		newList = cur1;
		tail = cur1;
		cur1 = cur1->next;
	}
	else
	{
		newList = cur2;
		tail = cur2;
		cur2 = cur2->next;
	}
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			tail->next = cur1;
			tail = cur1;
			cur1 = cur1->next;
		}
		else
		{
			tail->next = cur2;
			tail = cur2;
			cur2 = cur2->next;
		}
	}
	if (cur1 != NULL)
	{
		tail->next = cur1;
	}
	else
	{
		tail->next = cur2;
	}
	return newList;
}

pList Merge_R(pList pList1, pList pList2)
{
	pNode newList = NULL;

	if (pList1 == NULL)
	{
		return pList2;
	}
	else if (pList2 == NULL)
	{
		return pList1;
	}
	else 
	{
		if (pList1->data > pList2->data)
		{
			newList = pList2;
			newList->next = Merge_R(pList1, pList2->next);
		}
		else
		{
			newList = pList1;
			newList->next = Merge_R(pList1->next, pList2);
		}
		return newList;
	}
}

//快慢遍历法
pNode FindMidNode(pList pList)
{
	pNode fast = pList;
	pNode slow = pList;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

pNode FindLastKNode(pList pList, int k)
{
	pNode fast = pList;
	pNode slow = pList;
	if (GetLinkListLength(pList) < k)
	{
		return NULL;
	}
	else
	{
		//快的先走k-1次
		while (--k)
		{
			fast = fast->next;
		}
		//同时走
		while (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
}

pNode CheckCycle(pList pList)
{
	pNode fast = pList;
	pNode slow = pList;
	fast = fast->next->next;
	slow = slow->next;
	while (slow != fast && fast != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	if (fast == NULL)
	{
		return NULL;
	}
	return slow;
}

int GetCycleLength(pList meet)
{
	int len = 1;
	pNode cur = meet->next;
	while (cur != meet)
	{
		cur = cur->next;
		len++;
	}
	return len;
}

pNode StartCycle(pList pList, pNode meet)
{
	while (pList != meet)
	{
		pList = pList->next;
		meet = meet->next;
	}
	return pList;
}

bool CheckMeet(pList pList1, pList pList2)
{
	bool flag = true;
	while (pList1->next != NULL)
	{
		pList1 = pList1->next;
	}
	while (pList2->next != NULL)
	{
		pList2 = pList2->next;
	}
	if (pList1 == pList2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

pNode GetMeet(pList pList1, pList pList2)
{
	int len1 = GetLinkListLength(pList1);
	int len2 = GetLinkListLength(pList2);
	int d = len1 - len2 > 0 ? len1 - len2 : len2 - len1;
	if (len1 > len2)
	{
		while (d--)
		{
			pList1 = pList1->next;
		}
	}
	else
	{
		while (d--)
		{
			pList2 = pList2->next;
		}
	}
	while (pList1 != pList2)
	{
		pList1 = pList1->next;
		pList2 = pList2->next;
	}
	return pList1;
}

ComplexNode* BuyNode_Complex(DataType d)
{
	ComplexNode* newNode = (ComplexNode*)malloc(sizeof(ComplexNode));
	if (newNode == NULL)
	{
		printf("error!");
	}
	newNode->data = d;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;
}

void PrintComplexList(ComplexNode* node1)
{
	while (node1 != NULL)
	{
		printf("%d:", node1->data);
		if (node1->random != NULL)
		{
			printf("%d-->", node1->random->data);
		}
		else
		{
			printf("NULL-->");
		}
		node1 = node1->next;
	}
	printf("over!\n");
}

ComplexNode* CopyComplexList(ComplexNode* List)
{
	ComplexNode* cur = List;
	ComplexNode* next = NULL;
	ComplexNode* newList = NULL;
	//给每一个结点后面再加一个结点
	while (cur != NULL)
	{
		ComplexNode* newNode = BuyNode_Complex(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
	//增加random指针域，新的结点的random指向原先random的next
	cur = List;
	next = cur->next;
	while (next->next != NULL)
	{
		next->random = cur->random->next;
		cur = next->next;
		next = cur->next;
	}
	//断开原先的结点与现在结点的连接，将现在的结点连接起来
	cur = List->next;
	next = cur->next;
	newList = cur;
	while (next != NULL)
	{
		cur->next = next->next;
		cur = next->next;
		next = cur->next;
	}
	//结束，返回复制的复杂链表
	return newList;
}

//求两个链表的交集
pList Intersection(pList pList1, pList pList2)
{
	if (pList1 == NULL || pList2 == NULL)
	{
		return NULL;
	}
	pList newList = BuyNode(0);//添加头结点，这样就不用在后面进行第一次找相等的节点了，可以统一查找
	pNode tail = newList;
	while (pList1 != NULL && pList2 != NULL)
	{
		//两个数值相等，两个链表同时向后移动一个结点
		if (pList1->data == pList2->data)
		{
			tail->next = pList1;
			tail = pList1;
			pList1 = pList1->next;
			pList2 = pList2->next;
		}
		//pList1->data < pList2->data,pList1向后移动结点
		else if (pList1->data < pList2->data)
		{
			pList1 = pList1->next;
		}
		else
		{
			pList2 = pList2->next;
		}
	}
	return newList;
}

//求两个链表的差集
pList Difset(pList pList1, pList pList2)
{
	if (pList1 == NULL)
	{
		return pList2;
	}
	if (pList2 == NULL)
	{
		return pList1;
	}
	//直接给一个带有头结点的链表，取得差集
	pList newList = BuyNode(0);
	pNode tail = newList;
	while (pList1 != NULL && pList2 != NULL)
	{
		if (pList1->data == pList2->data)
		{
			pList1 = pList1->next;
			pList2 = pList2->next;
		}
		else if (pList1->data < pList2->data)
		{
			tail->next = pList1;
			tail = pList1;
			pList1 = pList1->next;
		}
		else
		{
			tail->next = pList2;
			tail = pList2;
			pList2 = pList2->next;
		}
	}
	if (pList1 != NULL)
	{
		tail->next = pList1;
	}
	else
	{
		tail->next = pList2;
	}
	return newList;
}