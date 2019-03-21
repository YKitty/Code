#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__


#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
//���������Ϊ�˲�α����ö�����
#include "Queue.h"
//����ջ��Ϊ�˷ǵݹ�����ö�����
#include "Stack.h"

typedef int BTDataType;

typedef struct BTNode
{
	BTDataType _data;
	struct BTNode* _left;
	struct BTNode* _right;
}BTNode;

//ǰ���������һ��������
BTNode* BinaryTreeCreat(BTDataType* arr, int* pcur);
BTNode* BinaryTreeCreat_int(BTDataType* arr, int* pcur);
void BinaryTreeDestory(BTNode** root);

//���������� �ݹ�&&�ǵݹ�

//�ݹ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

//��α���
void BinaryTreeLevelOrder(BTNode* root);

//�ǵݹ����
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

//��������Ľ����
int BinaryTreeSize(BTNode* root);
//���������Ҷ�ӽ��ĸ���
int BinaryTreeLeafSize(BTNode* root);
//��������ĵ�K��Ľڵ�ĸ���
int BinaryTreeLevelKSize(BTNode* root, int k);
//��������ĸ߶�
int BinaryTreeHeight(BTNode* root);
//�����������С���
int BinaryTreeMinHeigth(BTNode* root);
//�ж�һ������Ƿ���һ����������
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//��һ������˫�׽��
BTNode* BinaryTreeFindParentsNode(BTNode* root, BTNode* aim_node);
//�ж�һ���������ǲ�����ȫ������
int BinaryTreeIsWhole(BTNode* root);
int BinaryTreeIsWhole_T(BTNode* root);
//��������ľ���
//�ݹ�ķ�ʽ
void BinaryTreeMirrorImage(BTNode* root);
//�ǵݹ�ķ�ʽ
void BinaryTreeMirrorImageNonR(BTNode* tree);
//����ǰ�����к����������ؽ�������
BTNode* Construct(int* Prevstart, int* Prevend, int* Instart, int* Inend);
//�����ӽṹ
bool HasSubTree(BTNode* root1, BTNode* root2);
//��Ϊĳһֵ��·��
void Path(BTNode* root, int num);

#endif //__BINARYTREE_H__