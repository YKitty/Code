#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int BSTDataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTDataType _data;
}BSTreeNode;

void BSTreeInsert(BSTreeNode** root, BSTDataType x);
int BSTreeRendmove(BSTreeNode** root, BSTDataType x);
BSTreeNode* BSTreeFi(BSTreeNode** root, BSTDataType x);

int BSTreeInsertR(BSTreeNode** root, BSTDataType x);
int BSTreeRemoveR(BSTreeNode** root, BSTDataType x);
BSTreeNode* BSTreeFindR(BSTreeNode** root, BSTDataType x);


void BSTreeDestory(BSTreeNode** root);
void BSTreeInOrder(BSTreeNode** root);

//剑指offer
//寻找第k小的节点
BSTreeNode* KthNode(BSTreeNode** root, int k);

#endif //__BINARYSEARCHTREE_H__