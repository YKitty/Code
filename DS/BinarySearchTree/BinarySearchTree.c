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

	//�����Ϊ�գ���ֱ�ӽ��䵱�����ڵ�
	if (*root == NULL)
	{
		*root = BuyBSTreeNode(x);
	}

	BSTreeNode* cur = *root;
	BSTreeNode* parent = NULL;
	//��Ҫ����Ľ��		
	while (cur)
	{
		//�������
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		//���Ҳ���
		else if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		//�Ѿ��и������ˣ��������
		else
		{
			return;
		}
	}
	//cur�Ѿ���Ҷ�ӽڵ�ĺ��ӽڵ���
	//��parent��߲���
	if (parent->_data > x)
	{
		parent->_left = BuyBSTreeNode(x);
	}
	else
	{
		parent->_right = BuyBSTreeNode(x);
	}
}

//˼·��ɾ�����Ƿ��Ǹ��ڵ㣨�������ڸ��ڵ����Ϊ�ջ�����Ϊ���벻�Ǹ��ڵ��ɾ��������ͬ��
//���ڵ㣺��Ϊ�ջ�����Ϊ��
//���Ǹ��ڵ㣺��Ϊ�ջ�����Ϊ��
//ɾ���������ҽ�㶼��Ϊ��
//int BSTreeRemove(BSTreeNode** root, BSTDataType x)
//{
//	assert(root);
//
//	//û�����ݿɹ�ɾ��
//	if ((*root) == NULL)
//	{
//		return 0;
//	}
//	//ɾ������
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
//			//1.����Ϊ�գ������ҽ��Ϊ��
//			//��ʾɾ���Ĳ��Ǹ��ڵ�
//			if (parent != NULL)
//			{
//				//����Ϊ�գ�parent����cur��������
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
//				//�ҽ��Ϊ�գ�parent����cur��������
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
//			//ɾ�����Ǹ��ڵ�
//			else
//			{
//				//�ҵ��ˣ������ҵ����Ǹ��ڵ�
//				parent = cur;
//				//������Ϊ��
//				if (cur->_left == NULL)
//				{
//					*root = cur->_right;
//					free(cur);
//					cur = NULL;
//					return 1;
//				}
//				//������Ϊ��
//				if (cur->_right == NULL)
//				{
//					*root = cur->_left;
//					free(cur);
//					cur = NULL;
//					return 1;
//				}
//			}
//
//			//2.���ҽ�㶼��Ϊ�գ��滻ɾ������
//
//			//��һ�ַ�������Ҫɾ���Ľ�㣬�滻Ϊ������������Сֵ����·��㣩
//			//replace_right��cur����������Сֵ
//
//			//BSTreeNode* replace_right = cur->_right;
//			//while (replace_right->_left)
//			//{
//			//	replace_right = replace_right->_left;
//			//}
//			//����Ҫ��Ҫ�滻��ֵ��¼��������Ϊ���ͽ���Ŀռ��ͷ��ˣ��Ҳ�����
//
//			//���ǴӸ���㿪ʼɾ���滻����
//			/*int tmp = replace_right->_data;
//			BSTreeRemove(root, replace_right->_data);
//			cur->_data = tmp;*/
//
//			//���ߴ�Ҫɾ���ڵ���Һ��ӽ�㿪ʼɾ��
//			//cur->_data = replace_right->_data;
//			//BSTreeRemove(&(cur->_right), replace_right->_data);
//
//			//�ڶ��ַ�������Ҫɾ���Ľ�㣬�滻Ϊ�������ϵ����ֵ����·��㣩
//			//replace_leftΪ�������ϵ����ֵ
//
//			BSTreeNode* replace_left = cur->_left;
//			while (replace_left->_right)
//			{
//				replace_left = replace_left->_right;
//			}
//
//			//�Ӹ��ڵ㿪ʼɾ������ࣩ
//			//int tmp = replace_left->_data;
//			//BSTreeRemove(root, replace_left->_data);
//			//cur->_data = tmp;
//
//			//��Ҫɾ�������Һ��ӽ�㿪ʼɾ������ࣩ
//			cur->_data = replace_left->_data;
//			BSTreeRemove(&(cur->_left), replace_left->_data);
//
//		}
//	}
//	//û���ҵ����޷�����ɾ��
//	return 0;
//}


//˼·��(�����ת��Ϊ��Ϊ�ջ�����Ϊ��)
//��Ϊ�գ� ���ڵ���߲��Ǹ��ڵ�
//��Ϊ�գ� ���ڵ���߲��Ǹ��ڵ�
//���Ҷ���Ϊ�գ� ɾ���ķ���һ��
int BSTreeRemove(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	//��Ϊ�գ��޷�ɾ��
	if (*root == NULL)
	{
		return 0;
	}

	//parent��cur��˫�׽��
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
			//�ҵ���ɾ��
			//������Ϊ��
			if (cur->_left == NULL)
			{
				//ɾ�����ڵ�
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
			//������Ϊ��
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
			//������������Ϊ��
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
			//�Ѿ�ɾ���������ͷŽ��
			free(cur);
			cur = NULL;
			return 1;
		}
	}
	return 0;
}

//�ڶ����������в���һ������
//˼·��������ڽ������ұߣ����������ߡ�
//����������1.��Ϊ��   2.�ҵ���  3.�ҵ�Ҷ�ӽڵ����һ���������û���ҵ�
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
		//�������
		if (cur->_data > x)
		{
			cur = cur->_left;
		}
		//���Ҳ���
		else if (cur->_data < x)
		{
			cur = cur->_right;
		}
		//�ҵ���
		else
		{
			return cur;
		}
	}
	//��ʾ�Ѿ��ҵ�Ҷ�ӽڵ����һ���ڵ��ˣ�û���ҵ�
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
		//�ҵ���ɾ��
		//����Ϊ�ջ����ҽ��Ϊ��
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

			//����ֱ�ӽ��������滻�ˣ�����Ҫ����������Ϊ���ڵ����ɾ����㣬ɾ���滻��ɾ��λ�õĽ��
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

//Ѱ�ҵ�kС�Ľڵ�
//�Զ������������������������k��Ԫ�ؾ��ǵ�kС�Ľڵ���
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
