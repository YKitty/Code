#include "LinkLIst.h"

void TestBackLinkList()
{
	int count = 0;
	pList pList = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	count = GetLinkListLength(pList);
	printf("链表长度为:%d\n", count);
	PrintLinkList(pList);// 1 2 3 4
	PopBack(&pList);
	PrintLinkList(pList);//1 2 3
	PopBack(&pList);
	PrintLinkList(pList);//1 2 
	PopBack(&pList);
	PrintLinkList(pList);//1
	DestoryLinkList(&pList);//over
	PrintLinkList(pList);
}

void TestFrontLinkList()
{
	pList pList = NULL;
	InitLinkList(&pList);
	PushFront(&pList, 1);
	PushFront(&pList, 2);
	PushFront(&pList, 3);
	PushFront(&pList, 4);
	PrintLinkList(pList);//4 3 2 1
	PopFront(&pList);
	PrintLinkList(pList);//3 2 1
	DestoryLinkList(&pList);
	PrintLinkList(pList);
}

void TestFind()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PrintLinkList(pList);//1 2 3 4
	pos = Find(pList, 5);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}
	DestoryLinkList(&pList);

}

void TestInsert()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PrintLinkList(pList);//1 2 3 4 
	pos = Find(pList, 1);
	if (pos != NULL)
	{
		Insert(&pList, pos, 7);
		PrintLinkList(pList);//1 2 7 3 4
	}
	DestoryLinkList(&pList);
}

void TestErase()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PrintLinkList(pList);//1 2 3 4 
	pos = Find(pList, 1);
	if (pos != NULL)
	{
		Erase(&pList, pos);
		PrintLinkList(pList);//2 3 4
	}
	DestoryLinkList(&pList);
}

void TestRemove()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PushBack(&pList, 2);
	PrintLinkList(pList);//1 2 3 4 
	Remove(&pList, 1);
	PrintLinkList(pList);//2 3 4 2
	RemoveAll(&pList, 2);
	PrintLinkList(pList);//3 4 
	DestoryLinkList(&pList);
}

void TestEraseNotTailNode()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PushBack(&pList, 2);
	PrintLinkList(pList);//1 2 3 4 2
	pos = Find(pList, 2);
	if (pos != NULL)
	{
		EraseNotTailNode(pos);
		PrintLinkList(pList);//1 3 4 2
	}
	DestoryLinkList(&pList);
}

void TestReverseLinkList()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PushBack(&pList, 5);
	PrintLinkList(pList);//1 2 3 4 5
	ReverseLinkList(&pList);
	PrintLinkList(pList);//5 4 3 2 1
	DestoryLinkList(&pList);
}

void TestPrintTailToHead()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PushBack(&pList, 5);
	PrintLinkList(pList);//1 2 3 4 5
	PrintTailToHead(pList);//5 4 3 2 1
	PrintTailToHead_recursion(pList);//5 4 3 2 1
	DestoryLinkList(&pList);
}

void TestEraseNodeNotTail()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PushBack(&pList, 5);
	PrintLinkList(pList);//1 2 3 4 5
	pos = Find(pList, 2);
	if (pos != NULL)
	{
		EraseNodeNotTail(pos);
	}
	PrintLinkList(pList);//1 3 4 5 
}

void TestInsertNode()
{
	pList pList = NULL;
	pNode pos = NULL;
	InitLinkList(&pList);
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PushBack(&pList, 5);
	PrintLinkList(pList);//1 2 3 4 5
	pos = Find(pList, 2);
	if (pos != NULL)
	{
		InsertNode(pos, 3);
	}
	PrintLinkList(pList);//1 3 2 3 4 5 
}

void TestJosephusCycle()
{
	int i = 0;
	pList pList = NULL;
	pNode tail = NULL;
	InitLinkList(&pList);
	for (i = 1; i <= 5; i++)
	{
		PushBack(&pList, i);
	}

	////连成环
	//tail = pList;
	//while (tail->next != NULL)
	//{
	//	tail = tail->next;
	//}
	//tail->next = pList;

	//进行检验
	JosephusCycle(&pList, 3);
}

void TestBubbleSort()
{
	int i = 0;
	pList pList = NULL;
	for (i = 5; i >= 0; i--)
	{
		PushBack(&pList, i);
	}
	PrintLinkList(pList);//5 4 3 2 1 0
	BubbleSort(pList);
	PrintLinkList(pList);//0 1 2 3 4 5 
	DestoryLinkList(&pList);
}

void TestMerge()
{
	int i = 0;
	pList newList = NULL;
	pList pList1 = NULL;
	pList pList2 = NULL;
	for (i = 0; i < 9; i += 2)
	{
		PushBack(&pList1, i);
	}
	for (i = 1; i < 9; i += 1)
	{
		PushBack(&pList2, i);
	}
	PrintLinkList(pList1);//0 2 4 6 8 
	PrintLinkList(pList2);//1 3 5 7
	//newList = Merge(pList1, pList2);
	newList = Merge_R(pList1, pList2);
	PrintLinkList(newList);
}

void TestFindMidNode()
{
	int i = 0;
	pNode pos = NULL;
	pList pList = NULL;
	for (i = 0; i < 1; i++)
	{
		PushBack(&pList, i + 1);
	}
	PrintLinkList(pList);
	pos = FindMidNode(pList);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}
	DestoryLinkList(&pList);
}

void TestFindLastKNode()
{
	int i = 0;
	int k = 0;
	pList pList = NULL;
	pNode pos = NULL;
	for (i = 0; i < 5; i++)
	{
		PushBack(&pList, i + 1);
	}
	PrintLinkList(pList);
	pos = FindLastKNode(pList, 6);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}
}

void TestCheckCycle()
{
	int i = 0;
	int length = 0;
	pNode start = NULL;
	pNode meet = NULL;
	pNode tmp1 = NULL;
	pNode tmp2 = NULL;
	pList pList = NULL;
	for (i = 1; i < 9; i++)
	{
		PushBack(&pList, i);
	}
	PrintLinkList(pList);
	//构成环
	tmp1 = Find(pList, 3);
	tmp2 = Find(pList, 6);
	tmp2->next = tmp1;
	meet = CheckCycle(pList);
	if (meet != NULL)
	{
		printf("该单链表有环！\n");
		length = GetCycleLength(meet);
		printf("环的长度为:%d\n", length);
		start = StartCycle(pList, meet);
		printf("环的入口点:%d\n", start->data);
	}
}

void TestCheckMeet()
{
	int i = 0;
	bool flag = true;
	pNode meet = NULL;
	pNode tmp1 = NULL;
	pNode tmp2 = NULL;
	pList pList1 = NULL;
	pList pList2 = NULL;
	for (i = 1; i < 9; i++)
	{
		PushBack(&pList1, i);
		if (i <= 5)
		{
			PushBack(&pList2, i);
		}
	}
	//构建相交链表
	tmp1 = Find(pList2, 5);
	tmp2 = Find(pList1, 6);
	tmp1->next = tmp2;
	//判断两个链表是否相交，并且求交点
	flag = CheckMeet(pList1, pList2);
	if (flag == true)
	{
		printf("两个链表相交!\n");
		meet = GetMeet(pList1, pList2);
		printf("交点为:%d\n", meet->data);
	}
}

void TestComplexListCopyList()
{
	ComplexNode* copyList = NULL;
	ComplexNode* node1 = BuyNode_Complex(1);
	ComplexNode* node2 = BuyNode_Complex(2);
	ComplexNode* node3 = BuyNode_Complex(3);
	ComplexNode* node4 = BuyNode_Complex(4);
	ComplexNode* node5 = BuyNode_Complex(5);

	//连接各个结点的next域
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	
	//设置各个结点的random域
	node1->random = node3;
	node2->random = node4;
	node3->random = node2;
	node4->random = node5;
	node5->random = NULL;

	PrintComplexList(node1);
	copyList = CopyComplexList(node1);//node1为该复杂链表的起始结点
	PrintComplexList(copyList);
}

void TestIntersection()
{
	int i = 0;
	pList IntersectionList = NULL;
	pList DifsetList = NULL;
	pList pList1 = NULL;
	pList pList2 = NULL;
	PushBack(&pList1, 1);
	PushBack(&pList1, 3);
	PushBack(&pList1, 4);
	PushBack(&pList1, 6);
	PushBack(&pList1, 7);

	PushBack(&pList2, 1);
	PushBack(&pList2, 2);
	PushBack(&pList2, 4);
	PushBack(&pList2, 5);
	PushBack(&pList2, 7);
	//IntersectionList = Intersection(pList1, pList2);
	DifsetList = Difset(pList1, pList2);
	//PrintLinkList(IntersectionList);
	PrintLinkList(DifsetList);
}

void TestDeleteNode()
{
	pList plist;
	InitLinkList(&plist);

	for (int i = 0; i < 5; i++)
	{
		PushBack(&plist, i + 1);
	}

	pNode del = Find(plist, 1);
	if (del)
	{
		DeleteNode(&plist, del);
		PrintLinkList(plist);
	}
	else
	{
		exit(1);
	}

	del = Find(plist, 5);
	if (del)
	{
		DeleteNode(&plist, del);
		PrintLinkList(plist);
	}
	else
	{
		exit(1);
	}

	PrintLinkList(plist);
}

int main()
{
	//TestBackLinkList();
	//TestFrontLinkList();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestEraseNotTailNode();
	//TestReverseLinkList();
	//TestPrintTailToHead();
	//TestEraseNodeNotTail();
	//TestInsertNode();
	//TestJosephusCycle();
	//TestBubbleSort();
	//TestMerge();
	//TestFindMidNode();
	//TestFindLastKNode();
	//TestCheckCycle();
	//TestCheckMeet();
	//TestComplexListCopyList();
	//TestIntersection();
	TestDeleteNode();
	return 0;
}