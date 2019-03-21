#include "BinaryTree_M.h"

void TestBinaryTree()
{
	int cur = 0;
	char arr[] = { 'A', 'B', 'C', '#', '#', 'D', '#', '#','E', 'F', '#', '#', 'G', 'X', '#', '#', '#' };
	BTNode* tree = BinaryTreeCreat(arr, &cur);

	printf("���������\n");
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreePrevOrderNonR(tree);

	printf("���������\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreeInOrderNonR(tree);

	printf("���������\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreePostOrderNonR(tree);

	printf("��α�����\n");
	BinaryTreeLevelOrder(tree);
	printf("\n");
	printf("�������Ľ�����:%d\n", BinaryTreeSize(tree));
	printf("��������Ҷ�ӽڵ����:%d\n", BinaryTreeLeafSize(tree));
	printf("��������3����ĸ���:%d\n", BinaryTreeLevelKSize(tree, 3));
	printf("�������ڵ�ĸ߶�:%d\n", BinaryTreeHeight(tree));
	printf("����������С���:%d\n", BinaryTreeMinHeigth(tree));

	//���Բ���һ�����
	BTNode* ret = BinaryTreeFind(tree, 'C');
	if (ret)
	{
		printf("����%c���ݣ��ҵ�\n", ret->_data);
	}
	else
	{
		printf("����%c���ݣ�û���ҵ�!\n", ret->_data);
	}

	//���Բ���һ������˫�׽��
	BTNode* parents = BinaryTreeFindParentsNode(tree, ret);
	if (parents)
	{
		printf("�ҵ�%c����˫�׽��Ϊ:%c\n", ret->_data, parents->_data);
	}
	else
	{
		printf("û���ҵ�!\n");
	}

	if (BinaryTreeIsWhole(tree))
	//if (BinaryTreeIsWhole_T(tree))
	{
		printf("�ö���������ȫ������!\n");
	}
	else
	{
		printf("�ö�����������ȫ�Ķ�����!\n");
	}

	//�������ľ���
	printf("�������ľ���:\n");
	BinaryTreeMirrorImage(tree);
	BinaryTreePrevOrder(tree);
	printf("\n");

	printf("�������ľ���:\n");
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
		printf("������!\n");
	}
	else
	{
		printf("��������!\n");
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