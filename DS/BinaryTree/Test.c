#include "BinaryTree_M.h"

void TestBinaryTree()
{
	int cur = 0;
	char arr[] = { 'A', 'B', 'C', '#', '#', 'D', '#', '#','E', 'F', '#', '#', 'G', 'X', '#', '#', '#' };
	BTNode* tree = BinaryTreeCreat(arr, &cur);

	printf("先序遍历：\n");
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreePrevOrderNonR(tree);

	printf("中序遍历：\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreeInOrderNonR(tree);

	printf("后序遍历：\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreePostOrderNonR(tree);

	printf("层次遍历：\n");
	BinaryTreeLevelOrder(tree);
	printf("\n");
	printf("二叉树的结点个数:%d\n", BinaryTreeSize(tree));
	printf("二叉树的叶子节点个数:%d\n", BinaryTreeLeafSize(tree));
	printf("二叉树第3层结点的个数:%d\n", BinaryTreeLevelKSize(tree, 3));
	printf("二叉树节点的高度:%d\n", BinaryTreeHeight(tree));
	printf("二叉树的最小深度:%d\n", BinaryTreeMinHeigth(tree));

	//测试查找一个结点
	BTNode* ret = BinaryTreeFind(tree, 'C');
	if (ret)
	{
		printf("查找%c数据，找到\n", ret->_data);
	}
	else
	{
		printf("查找%c数据，没有找到!\n", ret->_data);
	}

	//测试查找一个结点的双亲结点
	BTNode* parents = BinaryTreeFindParentsNode(tree, ret);
	if (parents)
	{
		printf("找到%c结点的双亲结点为:%c\n", ret->_data, parents->_data);
	}
	else
	{
		printf("没有找到!\n");
	}

	if (BinaryTreeIsWhole(tree))
	//if (BinaryTreeIsWhole_T(tree))
	{
		printf("该二叉树是完全二叉树!\n");
	}
	else
	{
		printf("该二叉树不是完全的二叉树!\n");
	}

	//二叉树的镜像
	printf("二叉树的镜像:\n");
	BinaryTreeMirrorImage(tree);
	BinaryTreePrevOrder(tree);
	printf("\n");

	printf("二叉树的镜像:\n");
	BinaryTreeMirrorImageNonR(tree);
	BinaryTreePrevOrder(tree);
	printf("\n");

	BinaryTreeDestory(&tree);
}

void TestConstruct()
{
	int prev[] = { 1,2,4,7,3,5,6,8 };
	int in[] = { 4,7,2,1,5,3,8,6 };
	BTNode* root = Construct(prev, prev + sizeof(prev) / sizeof(int) - 1, in, in + sizeof(in) / sizeof(int) - 1);

	BinaryTreePrevOrder(root);
	printf("\n");

	BinaryTreeDestory(&root);
}

void TestHasSubTree()
{
	int cur = 0;
	char arr1[] = { 'A', 'B', 'C', '#', '#', 'D', '#', '#','E', 'F', '#', '#', 'G', 'X', '#', '#', '#' };
	BTNode* tree1 = BinaryTreeCreat(arr1, &cur);

	cur = 0;
	char arr2[] = { 'A', 'B', '#', '#', 'E', '#', '#' };
	BTNode* tree2 = BinaryTreeCreat(arr2, &cur);

	bool result = HasSubTree(tree1, tree2);
	if (result == true)
	{
		printf("是子树!\n");
	}
	else
	{
		printf("不是子树!\n");
	}

	BinaryTreeDestory(&tree1);
	BinaryTreeDestory(&tree2);
}

void TestFindPath()
{
	int cur = 0;
	int arr[] = { 1, 2, 4, 0, 0, 4, 0, 0, 3, 8, 0, 0, 3, 0, 0 };
	BTNode* tree = BinaryTreeCreat_int(arr, &cur);
	Path(tree, 7);

	printf("\n");
	BinaryTreeDestory(&tree);
}


int main()
{
	//TestBinaryTree();
	//TestConstruct();
	//TestHasSubTree();
	TestFindPath();
	return 0;
}