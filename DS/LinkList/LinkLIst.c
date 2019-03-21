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
	if (pList == NULL)//�޽��
	{
		return 0;
	}
	else//�н��
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
	if (*ppList == NULL) //��һ�����Ĳ���
	{
		*ppList = newNode;
	}
	else //����һ�����
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
	if (*ppList == NULL)//��
	{
		return;
	}
	else if ((*ppList)->next == NULL)//һ�����
	{
		pNode del = *ppList;
		*ppList = del->next;
		free(del);
		del = NULL;
	}
	else//����һ�����
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
	if (*ppList == NULL)//�޽�㣬������ɾ��
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
	if (pList == NULL)//�޽��
	{
		return NULL;
	}
	else//�н��
	{
		pNode cur = pList;
		while (cur && cur->data != d)
		{
			cur = cur->next;
		}
		if (cur != NULL)//�ҵ�
		{
			return cur;
		}
		else//û�ҵ�
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
	if (*ppList == NULL)//�޽��
	{
		return;
	}
	else //�н��
	{
		pNode cur = *ppList;
		if (pos == cur)//pos�ǵ�һ�����
		{
			newNode->next = *ppList;
			*ppList = newNode;
		}
		else//�ж���һ�����
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
	if (*ppList == NULL)//�޽��
	{
		return;
	}
	else //�н��
	{

		pNode cur = *ppList;
		if (pos == cur)//pos�ǵ�һ�����
		{
			pNode del = *ppList;
			*ppList = del->next;
			free(del);
			del = NULL;
		}
		else//�ж���һ�����
		{
			while ((cur->next != NULL) && (cur->next != pos))
			{
				cur = cur->next;
			}
			if (cur->next != NULL)//�ҵ�Ҫɾ���Ľ��
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
	if (*ppList == NULL)//�޽��
	{
		return;
	}
	else//�н��
	{
		pNode cur = *ppList;
		if (cur->data == d)//��һ��������Ҫɾ���ڵ�
		{
			pNode del = cur;
			*ppList = del->next;
			free(del);
			del = NULL;
		}
		else //��һ����㲻��Ҫɾ���ڵ�
		{
			while ((cur->next != NULL) && (cur->next->data != d))
			{
				cur = cur->next;
			}
			if (cur->next != NULL)//�ҵ�Ҫɾ���Ľ��
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
	if (*ppList == NULL)//�޽��
	{
		return;
	}
	else//�н��
	{
		pNode cur = *ppList;
		while (cur != NULL)
		{
			if (cur->data == d)//�ҵ�Ҫɾ�Ľ��
			{
				pNode del = NULL;
				if (cur == *ppList)//Ҫɾ���Ľ���ǵ�һ��
				{
					del = cur;
					cur = cur->next;
					*ppList = del->next;
					free(del);
					del = NULL;
				}
				else //Ҫɾ���Ľ�㲻�ǵ�һ��
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

//�ݹ�д��
void PrintTailToHead_recursion(pList pList)
{
	if (pList == NULL)
	{
		return;
	}
	PrintTailToHead_recursion(pList->next);
	printf("%d  ", pList->data);
}

//�ǵݹ�д��
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

//����/��ת������
void ReverseLinkList(pList* ppList)
{
	pNode cur = NULL;
	pNode tmp = NULL;
	assert(ppList != NULL);
	cur = *ppList;
	tmp = cur->next;
	if ((cur == NULL) && (cur->next == NULL))//��һ��������û�нڵ�
	{
		return;
	}
	else//����һ�����
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
	//�滻ɾ����
	del = pos->next;
	pos->data = del->data;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void DeleteNode(pList* phead, pNode pos)
{
	assert(phead && pos);

	//ɾ���Ĳ���β��㣨���ҽ���������1��
	if (pos->next != NULL)
	{
		pNode del = pos->next;
		pos->data = del->data;
		pos->next = del->next;

		free(del);
		del = NULL;
	}
	//����ֻ��һ����㣬ɾ������ͷ��㣬Ҳ��β���
	else if (*phead == pos)
	{
		pNode del = pos;
		*phead = NULL;

		free(del);
		del = NULL;
	}
	//�������ж���ڵ㣬ɾ������β���
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
	//�滻���뷨
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
//	//����
//	while (tail->next != NULL)
//	{
//		tail = tail->next;
//	}
//	tail->next = *ppList;
//
//	//���Ҵ���
//	while (cur != cur->next)
//	{
//		pNode del = NULL;
//		int count = k;
//		while (--count)
//		{
//			cur = cur->next;
//		}
//		printf("��ɱ��%d\n", cur->data);
//		//�滻ɾ��
//		del = cur->next;
//		cur->data = del->data;
//		cur->next = del->next;
//		free(del);
//		del = NULL;
//	}
//	printf("�Ҵ��ߣ�%d\n", cur->data);
//}

//Լɪ�򻷣���ϰ��
void  JosephusCycle(pList* pplist, int k)
{
	pNode tail = NULL;
	pNode cur = NULL;
	assert(pplist != NULL);

	//����
	cur = *pplist;
	tail = *pplist;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = cur;

	//��������
	while (cur != cur->next)
	{
		//ɾ����k�����
		int count = k;//��֤ÿ��k����ı�
		while (--count)
		{
			cur = cur->next;
		}
		printf("��ɱ��%d  ", cur->data);
		printf("\n");
		//�滻ɾ����
		pNode del = cur->next;
		cur->data = del->data;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("�Ҵ���:%d\n", cur->data);
}

void BubbleSort(pList pList)
{
	pNode cur = NULL;
	pNode next = NULL;
	pNode tail = NULL;
	for (cur = pList; cur->next != NULL; cur = cur->next)//����
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

//����������
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
		//�������k-1��
		while (--k)
		{
			fast = fast->next;
		}
		//ͬʱ��
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
	//��ÿһ���������ټ�һ�����
	while (cur != NULL)
	{
		ComplexNode* newNode = BuyNode_Complex(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
	//����randomָ�����µĽ���randomָ��ԭ��random��next
	cur = List;
	next = cur->next;
	while (next->next != NULL)
	{
		next->random = cur->random->next;
		cur = next->next;
		next = cur->next;
	}
	//�Ͽ�ԭ�ȵĽ�������ڽ������ӣ������ڵĽ����������
	cur = List->next;
	next = cur->next;
	newList = cur;
	while (next != NULL)
	{
		cur->next = next->next;
		cur = next->next;
		next = cur->next;
	}
	//���������ظ��Ƶĸ�������
	return newList;
}

//����������Ľ���
pList Intersection(pList pList1, pList pList2)
{
	if (pList1 == NULL || pList2 == NULL)
	{
		return NULL;
	}
	pList newList = BuyNode(0);//���ͷ��㣬�����Ͳ����ں�����е�һ������ȵĽڵ��ˣ�����ͳһ����
	pNode tail = newList;
	while (pList1 != NULL && pList2 != NULL)
	{
		//������ֵ��ȣ���������ͬʱ����ƶ�һ�����
		if (pList1->data == pList2->data)
		{
			tail->next = pList1;
			tail = pList1;
			pList1 = pList1->next;
			pList2 = pList2->next;
		}
		//pList1->data < pList2->data,pList1����ƶ����
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

//����������Ĳ
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
	//ֱ�Ӹ�һ������ͷ��������ȡ�ò
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