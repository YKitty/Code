#include "List.h"

void TestDoubleLinkList()
{
	List head;
	ListInit(&head);
	ListPushBack(&head, 1);
	ListPushBack(&head, 2);
	ListPushFront(&head, 3);
	ListPushFront(&head, 4);

	ListNode* ret = ListFind(&head, 2);
	if (ret)
	{
		printf("�ҵ���!\n");
	}
	else
	{
		printf("û�ҵ�!\n");
	}

	printf("Size:%d\n", ListSize(&head));
	PrintList(&head);//4 3 1 2

	ListPopBack(&head);
	PrintList(&head);//4 3 1

	ListPopFront(&head);
	PrintList(&head);//3 1

	ListPopBack(&head);
	ListPopBack(&head);

	if (ListEmpty(&head) == 0)
	{
		printf("List is free!\n");
	}


	ListDestory(&head);
}


int main()
{
	TestDoubleLinkList();
	return 0;
}