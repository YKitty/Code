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

//创建双向循环带头结点链表
//思路：进行初始化的时候要申请一个结点，使指针可以指向该结点，即开始就初始化一个头结点
void ListInit(List* pl)
{
	assert(pl);

	//给予一个头结点，并且初始化
	pl->_head = BuyNode(0);
	pl->_head->_next = pl->_head;
	pl->_head->_prev = pl->_head;
}

//销毁链表
//思路：销毁链表的时候要现从头结点的下一个结点开始销毁，最后在销毁头结点
//如果从头结点开始销毁的话，最后就没有终止条件了
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

//链表的插入，在已知位置前插入一个结点
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* newNode = BuyNode(x);

	//插入顺序prev newNode pos
	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = pos;
	pos->_prev = newNode;
}

//在指定位置删除一个结点
void ListErase(List* pl, ListNode* pos)
{
	assert(pos);
	assert(pos != pl->_head);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	//连接顺序prev (pos) next
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

//头插法
//思路:也就是在头结点的后面插入一个数据，也就是在第一个结点前面插入一个数据
void ListPushFront(List* pl, LTDataType x)
{
	assert(pl);

	//头插法：也就是在_head的后面插入一个数据，即在第一个节点前面插入一个数据
	ListInsert(pl->_head->_next, x);
}

//尾插法
//思路：也就是在头结点前面插入一个数据
void ListPushBack(List* pl, LTDataType x)
{
	assert(pl);

	//尾插法：也就是在_head的前面插入一个数据
	ListInsert(pl->_head, x);
}

//头删法
//思路：将头结点后面的结点进行删除
void ListPopFront(List* pl)
{
	assert(pl);

	//头删法：也就是将_head后面的结点进行删除
	ListErase(pl, pl->_head->_next);
}

//尾删法
//思路：将头结点前面的结点进行删除
void ListPopBack(List* pl)
{
	assert(pl);

	//尾删法：也就是将_head前面的结点进行删除
	ListErase(pl, pl->_head->_prev);
}

//求链表大小
//对链表进行一次遍历，但是要从第一个节点开始遍历。结束：遍历到头结点
int ListSize(List* pl)
{
	int count = 0;
	assert(pl);

	//求双向循环具有头结点的链表的长度需要从第一个正式存储数据的结点进行累加
	ListNode* cur = pl->_head->_next;
	while (cur != pl->_head)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}

//判断链表是不是空链表
//思路：如果头结点后面有结点就不是空链表，否则就是空链表
//空 0
//非空 1
int ListEmpty(List* pl)
{
	assert(pl);

	return pl->_head->_next == pl->_head ? 0 : 1;
}

//查找一个结点(已知数据域)来进行查找
//思路：从第一个结点开始遍历，当数据相等或者遍历结束进行判断cur结点，如果cur是空的h话那就说明没有找到，否则找到
ListNode* ListFind(List* pl, LTDataType x)
{
	assert(pl);

	ListNode* cur = pl->_head->_next;
	while ((cur->_data != x) || (cur == pl->_head))
	{
		cur = cur->_next;
	}
	//没有找到
	if (cur == pl->_head)
	{
		return NULL;
	}
	else
	{
		return cur;
	}
}

//双向循环链表的打印
//思路：从第一个结点开始遍历，结束到达头结点
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