#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__


#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
//引入队列是为了层次遍历该二叉树
#include "Queue.h"
//引入栈是为了非递归遍历该二叉树
#include "Stack.h"

typedef int BTDataType;

typedef struct BTNode
{
	BTDataType _data;
	struct BTNode* _left;
	struct BTNode* _right;
}BTNode;

//前序遍历创建一个二叉树
BTNode* BinaryTreeCreat(BTDataType* arr, int* pcur);
BTNode* BinaryTreeCreat_int(BTDataType* arr, int* pcur);
void BinaryTreeDestory(BTNode** root);

//遍历二叉树 递归&&非递归

//递归遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

//层次遍历
void BinaryTreeLevelOrder(BTNode* root);

//非递归遍历
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

//求二叉树的结点数
int BinaryTreeSize(BTNode* root);
//求二叉树的叶子结点的个数
int BinaryTreeLeafSize(BTNode* root);
//求二叉树的第K层的节点的个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//求二叉树的高度
int BinaryTreeHeight(BTNode* root);
//求二叉树的最小深度
int BinaryTreeMinHeigth(BTNode* root);
//判断一个结点是否在一个二叉树中
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//求一个结点的双亲结点
BTNode* BinaryTreeFindParentsNode(BTNode* root, BTNode* aim_node);
//判断一个二叉树是不是完全二叉树
int BinaryTreeIsWhole(BTNode* root);
int BinaryTreeIsWhole_T(BTNode* root);
//求二叉树的镜像
//递归的方式
void BinaryTreeMirrorImage(BTNode* root);
//非递归的方式
void BinaryTreeMirrorImageNonR(BTNode* tree);
//根据前序序列和中序序列重建二叉树
BTNode* Construct(int* Prevstart, int* Prevend, int* Instart, int* Inend);
//树的子结构
bool HasSubTree(BTNode* root1, BTNode* root2);
//和为某一值的路径
void Path(BTNode* root, int num);

#endif //__BINARYTREE_H__