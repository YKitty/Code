#include "BinarySearchTree.h"

BSTreeNode* BuyBSTreeNode(BSTDataType x)
{
	BSTreeNode* newNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (newNode == NULL)
	{
		perror("malloc error!");
	}

	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;

	return newNode;
}

void BSTreeInsert(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	//如果树为空，则直接将其当作根节点
	if (*root == NULL)
	{
		*root = BuyBSTreeNode(x);
	}

	BSTreeNode* cur = *root;
	BSTreeNode* parent = NULL;
	//找要插入的结点		
	while (cur)
	{
		//向左插入
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		//向右插入
		else if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		//已经有该数据了，无需插入
		else
		{
			return;
		}
	}
	//cur已经到叶子节点的孩子节点了
	//在parent左边插入
	if (parent->_data > x)
	{
		parent->_left = BuyBSTreeNode(x);
	}
	else
	{
		parent->_right = BuyBSTreeNode(x);
	}
}

//思路：删除的是否是根节点（区别在于根节点的左为空或者右为空与不是根节点的删除方法不同）
//根节点：左为空或者右为空
//不是根节点：左为空或者右为空
//删除的是左右结点都不为空
//int BSTreeRemove(BSTreeNode** root, BSTDataType x)
//{
//	assert(root);
//
//	//没有数据可供删除
//	if ((*root) == NULL)
//	{
//		return 0;
//	}
//	//删除数据
//	BSTreeNode* cur = *root;
//	BSTreeNode* parent = NULL;
//	
//	while (cur)
//	{
//		if (cur->_data > x)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else if (cur->_data < x)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else
//		{
//			//1.左结点为空，或者右结点为空
//			//表示删除的不是根节点
//			if (parent != NULL)
//			{
//				//左结点为空，parent连上cur的右子树
//				if (cur->_left == NULL)
//				{
//					if (parent->_left == cur)
//					{
//						parent->_left = cur->_right;
//					}
//					else
//					{
//						parent->_right = cur->_right;
//					}
//					free(cur);
//					cur = NULL;
//					return 1;
//				}
//				//右结点为空，parent连上cur的左子树
//				else if (cur->_right == NULL)
//				{
//					if (parent->_left == cur)
//					{
//						parent->_left = cur->_left;
//					}
//					else
//					{
//						parent->_right = cur->_left;
//					}
//					free(cur);
//					cur = NULL;
//					return 1;
//				}
//			}
//			//删除的是根节点
//			else
//			{
//				//找到了，但是找到的是根节点
//				parent = cur;
//				//左子树为空
//				if (cur->_left == NULL)
//				{
//					*root = cur->_right;
//					free(cur);
//					cur = NULL;
//					return 1;
//				}
//				//右子树为空
//				if (cur->_right == NULL)
//				{
//					*root = cur->_left;
//					free(cur);
//					cur = NULL;
//					return 1;
//				}
//			}
//
//			//2.左右结点都不为空（替换删除法）
//
//			//第一种方法：令要删除的结点，替换为其右子树的最小值（左路结点）
//			//replace_right是cur右子树的最小值
//
//			//BSTreeNode* replace_right = cur->_right;
//			//while (replace_right->_left)
//			//{
//			//	replace_right = replace_right->_left;
//			//}
//			//必须要将要替换的值记录下来，因为最后就将其的空间释放了，找不到了
//
//			//这是从根结点开始删除替换结点的
//			/*int tmp = replace_right->_data;
//			BSTreeRemove(root, replace_right->_data);
//			cur->_data = tmp;*/
//
//			//或者从要删除节点的右孩子结点开始删除
//			//cur->_data = replace_right->_data;
//			//BSTreeRemove(&(cur->_right), replace_right->_data);
//
//			//第二种方法：令要删除的结点，替换为左子树上的最大值（右路结点）
//			//replace_left为左子树上的最大值
//
//			BSTreeNode* replace_left = cur->_left;
//			while (replace_left->_right)
//			{
//				replace_left = replace_left->_right;
//			}
//
//			//从根节点开始删除（左侧）
//			//int tmp = replace_left->_data;
//			//BSTreeRemove(root, replace_left->_data);
//			//cur->_data = tmp;
//
//			//从要删除结点的右孩子结点开始删除（左侧）
//			cur->_data = replace_left->_data;
//			BSTreeRemove(&(cur->_left), replace_left->_data);
//
//		}
//	}
//	//没有找到，无法进行删除
//	return 0;
//}


//思路：(最后都是转化为左为空或者右为空)
//左为空： 根节点或者不是根节点
//右为空： 根节点或者不是根节点
//左右都不为空： 删除的方法一样
int BSTreeRemove(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	//树为空，无法删除
	if (*root == NULL)
	{
		return 0;
	}

	//parent是cur的双亲结点
	BSTreeNode* cur = *root;
	BSTreeNode* parent = NULL;

	while (cur)
	{
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			//找到，删除
			//左子树为空
			if (cur->_left == NULL)
			{
				//删除根节点
				if (parent == NULL)
				{
					*root = (*root)->_right;
				}
				else
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
			}
			//右子树为空
			else if (cur->_right == NULL)
			{
				if (parent == NULL)
				{
					*root = (*root)->_left;
				}
				else
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
			}
			//左右子树都不为空
			else   
			{
				BSTreeNode* replace_right = cur->_right;
				while (replace_right->_left)
				{
					replace_right = replace_right->_left;
				}

				cur->_data = replace_right->_data;

				return BSTreeRemove(&cur->_right, replace_right->_data);
			}
			//已经删除，进行释放结点
			free(cur);
			cur = NULL;
			return 1;
		}
	}
	return 0;
}

//在二叉搜索树中查找一个数据
//思路：如果大于结点就在右边，否则就在左边。
//结束条件：1.树为空   2.找到了  3.找到叶子节点的下一个结点依旧没有找到
BSTreeNode* BSTreeFind(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	BSTreeNode* cur = *root;
	if (cur == NULL)
	{
		return NULL;
	}
	
	while (cur)
	{
		//向左查找
		if (cur->_data > x)
		{
			cur = cur->_left;
		}
		//向右查找
		else if (cur->_data < x)
		{
			cur = cur->_right;
		}
		//找到了
		else
		{
			return cur;
		}
	}
	//表示已经找到叶子节点的下一个节点了，没有找到
	return NULL;
}

void BSTreeInOrder(BSTreeNode** root)
{
	assert(root);
	
	if (*root == NULL)
	{
		return;
	}

	BSTreeInOrder(&((*root)->_left));
	printf("%d ", (*root)->_data);
	BSTreeInOrder(&((*root)->_right));
}

void BSTreeDestory(BSTreeNode** root)
{
	if (*root == NULL)
	{
		return;
	}

	BSTreeDestory(&(*root)->_left);
	BSTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

int BSTreeInsertR(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	if (*root == NULL)
	{
		*root = BuyBSTreeNode(x);
		return 1;
	}

	if ((*root)->_data > x)
	{
		return BSTreeInsertR(&(*root)->_left, x);
	}
	else if ((*root)->_data < x)
	{
		return BSTreeInsertR(&(*root)->_right, x);
	}
	else
	{
		return 0;
	}
}

int BSTreeRemoveR(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	if (*root == NULL)
	{
		return 0;
	}

	if ((*root)->_data > x)
	{
		return BSTreeRemoveR(&(*root)->_left, x);
	}
	else if ((*root)->_data < x)
	{
		return BSTreeRemoveR(&(*root)->_right, x);
	}
	else
	{
	    BSTreeNode* del = *root;
		//找到，删除
		//左结点为空或者右结点为空
		if ((*root)->_left == NULL)
		{
			*root = (*root)->_right;
			free(del);
			del = NULL;
		}
		else if ((*root)->_right == NULL)
		{
			*root = (*root)->_left;
			free(del);
			del = NULL;
		}
		else
		{
			BSTreeNode* replace = (*root)->_right;
			while (replace->_left)
			{
				replace = replace->_left;
			}

			//这里直接进行数据替换了，所以要从以右子树为根节点进行删除结点，删除替换到删除位置的结点
			(*root)->_data = replace->_data;
			return BSTreeRemoveR(&(*root)->_right, replace->_data);
		}
	}
	return 1;
}

BSTreeNode* BSTreeFindR(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	if (*root == NULL)
	{
		return NULL;
	}

	if ((*root)->_data > x)
	{
		return BSTreeFindR(&(*root)->_left, x);
	}
	else if ((*root)->_data < x)
	{
		return BSTreeFindR(&(*root)->_right, x);
	}
	else
	{
		return *root;
	}
}

BSTreeNode* BSTreeNodeInOrder_K(BSTreeNode** root, int* k)
{
	assert(root);
	BSTreeNodeInOrder_K();
	
}

//寻找第k小的节点
//对二叉搜索树进行中序遍历，第k个元素就是第k小的节点了
BSTreeNode* KthNode(BSTreeNode** root, int k)
{
	assert(root);

	BSTreeNode* ret = BSTreeNodeInOrder_K(root, &k);
	if (ret)
	{
		return ret;
	}
	return NULL;
}
