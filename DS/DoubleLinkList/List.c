#include "List.h"

ListNode* BuyNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("BuyNode for GetMemory");
	}

	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}

//����˫��ѭ����ͷ�������
//˼·�����г�ʼ����ʱ��Ҫ����һ����㣬ʹָ�����ָ��ý�㣬����ʼ�ͳ�ʼ��һ��ͷ���
void ListInit(List* pl)
{
	assert(pl);

	//����һ��ͷ��㣬���ҳ�ʼ��
	pl->_head = BuyNode(0);
	pl->_head->_next = pl->_head;
	pl->_head->_prev = pl->_head;
}

//��������
//˼·�����������ʱ��Ҫ�ִ�ͷ������һ����㿪ʼ���٣����������ͷ���
//�����ͷ��㿪ʼ���ٵĻ�������û����ֹ������
void ListDestory(List* pl)
{
	assert(pl);

	ListNode* cur = pl->_head;
	while (cur != pl->_head)
	{
		ListNode* del = cur->_next;
		cur->_next = del->_next;
		del->_next->_prev = cur;
		cur = del->_next;
		free(del);
		del = NULL;
	}
	free(pl->_head);
	pl->_head = NULL;
}

//����Ĳ��룬����֪λ��ǰ����һ�����
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* newNode = BuyNode(x);

	//����˳��prev newNode pos
	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = pos;
	pos->_prev = newNode;
}

//��ָ��λ��ɾ��һ�����
void ListErase(List* pl, ListNode* pos)
{
	assert(pos);
	assert(pos != pl->_head);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	//����˳��prev (pos) next
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

//ͷ�巨
//˼·:Ҳ������ͷ���ĺ������һ�����ݣ�Ҳ�����ڵ�һ�����ǰ�����һ������
void ListPushFront(List* pl, LTDataType x)
{
	assert(pl);

	//ͷ�巨��Ҳ������_head�ĺ������һ�����ݣ����ڵ�һ���ڵ�ǰ�����һ������
	ListInsert(pl->_head->_next, x);
}

//β�巨
//˼·��Ҳ������ͷ���ǰ�����һ������
void ListPushBack(List* pl, LTDataType x)
{
	assert(pl);

	//β�巨��Ҳ������_head��ǰ�����һ������
	ListInsert(pl->_head, x);
}

//ͷɾ��
//˼·����ͷ������Ľ�����ɾ��
void ListPopFront(List* pl)
{
	assert(pl);

	//ͷɾ����Ҳ���ǽ�_head����Ľ�����ɾ��
	ListErase(pl, pl->_head->_next);
}

//βɾ��
//˼·����ͷ���ǰ��Ľ�����ɾ��
void ListPopBack(List* pl)
{
	assert(pl);

	//βɾ����Ҳ���ǽ�_headǰ��Ľ�����ɾ��
	ListErase(pl, pl->_head->_prev);
}

//�������С
//���������һ�α���������Ҫ�ӵ�һ���ڵ㿪ʼ������������������ͷ���
int ListSize(List* pl)
{
	int count = 0;
	assert(pl);

	//��˫��ѭ������ͷ��������ĳ�����Ҫ�ӵ�һ����ʽ�洢���ݵĽ������ۼ�
	ListNode* cur = pl->_head->_next;
	while (cur != pl->_head)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}

//�ж������ǲ��ǿ�����
//˼·�����ͷ�������н��Ͳ��ǿ�����������ǿ�����
//�� 0
//�ǿ� 1
int ListEmpty(List* pl)
{
	assert(pl);

	return pl->_head->_next == pl->_head ? 0 : 1;
}

//����һ�����(��֪������)�����в���
//˼·���ӵ�һ����㿪ʼ��������������Ȼ��߱������������ж�cur��㣬���cur�ǿյ�h���Ǿ�˵��û���ҵ��������ҵ�
ListNode* ListFind(List* pl, LTDataType x)
{
	assert(pl);

	ListNode* cur = pl->_head->_next;
	while ((cur->_data != x) || (cur == pl->_head))
	{
		cur = cur->_next;
	}
	//û���ҵ�
	if (cur == pl->_head)
	{
		return NULL;
	}
	else
	{
		return cur;
	}
}

//˫��ѭ������Ĵ�ӡ
//˼·���ӵ�һ����㿪ʼ��������������ͷ���
void PrintList(List* pl)
{
	assert(pl);

	ListNode* cur = pl->_head->_next;
	while (cur != pl->_head)
	{
		if (cur->_next == pl->_head)
		{
			printf("%d", cur->_data);
		}
		else
		{
			printf("%d<-->", cur->_data);
		}
		cur = cur->_next;
	}
	printf("\n");
}