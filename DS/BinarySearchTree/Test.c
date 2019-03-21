#include "BinarySearchTree.h"

void TestBinarySearchTree()
{
	BSTreeNode* tree = NULL;
	int arr[] = { 14, 9, 36, 28, 65, 72 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		BSTreeInsertR(&tree, arr[i]);
	}

	BSTreeNode* ret = BSTreeFindR(&tree, 9);
	if (ret)
	{
		printf("找到了:%d\n", ret->_data);
	}
	else
	{
		printf("没有找到!\n");
	}

	//对于二叉搜索树，对其进行中序遍历，就可以得到一个非递减序列
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 14);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeDestory(&tree);
	
}


int main()
{
	TestBinarySearchTree();
	return 0;
}