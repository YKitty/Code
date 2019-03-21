#include "BinaryTree_M.h"

//申请一个BTNode*类型的结点空间
BTNode* BuyBTNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		perror("In order get size!");
	}

	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}

//采用前序遍历创建一个二叉树（char）
BTNode* BinaryTreeCreat(BTDataType* arr, int* pcur)
{
	assert(arr);

	if (arr[*pcur] == '#')
	{
		return NULL;
	}

	BTNode* root = BuyBTNode(arr[*pcur]);

	(*pcur)++;
	root->_left = BinaryTreeCreat(arr, pcur);
	(*pcur)++;
	root->_right = BinaryTreeCreat(arr, pcur);
	return root;
}

//采用前序遍历创建一个二叉树（int）
BTNode* BinaryTreeCreat_int(BTDataType* arr, int* pcur)
{
	assert(arr);

	if (arr[*pcur] == 0)
	{
		return NULL;
	}

	BTNode* root = BuyBTNode(arr[*pcur]);

	(*pcur)++;
	root->_left = BinaryTreeCreat_int(arr, pcur);
	(*pcur)++;
	root->_right = BinaryTreeCreat_int(arr, pcur);
	return root;
}

//二叉树的销毁函数，
//思想：对于二叉树进行销毁的话，必须从叶子节点开始进行销毁，否则就找不到其后面的结点了
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}

	//销毁的话就要全都销毁,只有当root结点的左右指针都为NULL的时候才销毁root结点
	//只有当左子树为空的时候，才能判断右子树，所以销毁放在两个遍历的后面
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free((*root));
	(*root) = NULL;
	//printf("销毁成功!\n");
}

//遍历二叉树 递归&&非递归
//前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

//后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

//层次遍历
//思想：对二叉树进行层次遍历采用队列的结构，队列具有先进先出的特点,结束：队列为空，则所有的元素都已经输出
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root == NULL)
	{
		return;
	}
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
}

//非递归遍历二叉树
//前序遍历（根节点  左子树    右子树）
//思路：先将该二叉树的左路结点压栈遍历完，然后在访问根节点，然后再对右结点进行刚才同样的事情，
//进行左路结点压栈遍历，然后在访问右结点，结束条件:该节点是叶子就不需要在进行压栈，对其进行出栈就可以了
void BinaryTreePrevOrderNonR(BTNode* root)
{
	assert(root);

	Stack s;
	StackInit(&s);
	BTNode* cur = root;

	//StackEmpty必须存在因为在遍历的过程中，cur有可能会等于NULL
	while (cur || StackEmpty(&s))
	{
		//将每个结点的左路结点全部进行压栈进行压栈
		while (cur)
		{
			StackPush(&s, cur);
			printf("%c ", cur->_data);
			cur = cur->_left;
		}

		BTNode* top = StackTop(&s);
		StackPop(&s);

		//开始访问已经进入栈的结点的右路结点
		cur = top->_right;
	}

	printf("\n");
}

//中序遍历（左子树  根节点   右子树）
//思想：中序遍历和前序遍历基本一样，只是在输出结点数据的位置不同，中序遍历是在对该节点进行出栈的时候，访问该节点
void BinaryTreeInOrderNonR(BTNode* root)
{
	assert(root);

	Stack s;
	StackInit(&s);
	BTNode* cur = root;

	//StackEmpty必须存在因为在遍历的过程中，cur有可能会等于NULL
	while (cur || StackEmpty(&s))
	{
		//将每个结点的左路结点全部进行压栈
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}

		BTNode* top = StackTop(&s);
		printf("%c ", top->_data);
		StackPop(&s);

		//开始访问出栈的结点的右子树
		cur = top->_right;
	}

	printf("\n");
}

//后序遍历（左子树   右子树   根节点）
//思想：先将左路结点全部入栈，然后出栈的时候
//如何判断是否要访问该结点，
//如果该节点的右结点为空的话，或者该结点的右结点等于刚访问的上一个节点prev，那就直接访问该节点
//否则就是该节点的右结点没有进行访问呢，那就访问该节点的右结点
void BinaryTreePostOrderNonR(BTNode* root)
{
	assert(root);

	Stack s;
	StackInit(&s);
	//prev记录的是出栈的结点
	BTNode* prev = NULL;
	BTNode* cur = root;

	//cur必须存在因为开始要从cur进入，只不过是在遍历的时候，cur绝对不会等于NULL
	while (cur || StackEmpty(&s))
	{
		//将左路结点全部入栈
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}

		BTNode* top = StackTop(&s);
		//说明该节点的右结点已经访问过了，可以进行输出了
		if (top->_right == NULL || top->_right == prev)
		{
			StackPop(&s);
			prev = top;
			printf("%c ", top->_data);
		}
		//该节点的右结点没有访问过,那就继续对右结点进行子循环
		else
		{
			cur = top->_right;
		}
	}
	printf("\n");
}

//求二叉树的结点数
//二叉树的结点数等于左子树的结点数和右子树的结点数之和再加上根节点， 结束：root == NULL
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

//求二叉树的叶子结点的个数
//思想：求根节点的左子树的叶子节点的个数加上右子树的叶子节点的个数，在进行返回，
//结束：root->_left == NULL,root->_right == NULL, return 1;  root == NULL , return 0;
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if ((root->_left == NULL) && (root->_right == NULL))
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//求二叉树的第K层的节点的个数
//思想：设根节点是第一层，则方法是求第K层，就是求该节点的左子树的K-1层的个数加上右子树K-1层的个数，结束:K == 1
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//对于在递归中要返回结点必须要在该递归函数中，进行局部变量的定义，使用局部变量进行返回与接收。
//如果不用局部变量进行接收的话，那么就会导致返回的东西丢失

//求二叉树的高度
//思想：根节点的高度等于左右子树大的高度加上1，结束：root == NULL
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = BinaryTreeHeight(root->_left);
	int rightHeight = BinaryTreeHeight(root->_right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//求二叉树的最小深度
//思路：根节点等于左右结点中较小的值加一
int BinaryTreeMinHeigth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = BinaryTreeMinHeigth(root->_left);
	int rightHeight = BinaryTreeMinHeigth(root->_right);
	return leftHeight < rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//判断一个结点是否在一个二叉树中
//思想：先检测根节点是否相等，在检测左子树，在检测右子树，结束：root->_data == x, root == NULL
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}

//求一个结点的双亲结点
//思路：从根节点开始，判断根节点的左子树或者右子树等不等于所求结点，
//如果是的话，就返回该节点,否则在判断该节点的左子树和右子树
//结束：root == NULL
BTNode* BinaryTreeFindParentsNode(BTNode* root, BTNode* aim_node)
{
	if (root == NULL)
	{
		return NULL;
	}
	if ((root->_left == aim_node) || (root->_right == aim_node))
	{
		return root;
	}
	BTNode* ret = BinaryTreeFindParentsNode(root->_left, aim_node);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFindParentsNode(root->_right, aim_node);
	if (ret)
	{
		return ret;
	}
	return NULL;
}

//检测队列里面是否包含数据元素
//思路：遍历一遍队列，如果
//有返回1，没有0
int CheckHaveData(Queue* pq)
{
	assert(pq);

	//对队列进行一次遍历只要含有数据元素就进行返回
	while (pq->front)
	{
		if (pq->front->data->_data != '#')
		{
			return 1;
		}
		pq->front = pq->front->next;
	}
	return 0;
}

//判断一个二叉树是不是完全二叉树
//思路：可以采用层次遍历，如果某一个结点是空的话也进行入队，变成入队#，最后只要队列里出现，#后面仍然有数据元素，
//那么该队列就不是完全二叉树，否则就是完全二叉树
//是完全二叉树 1
//不是完全二叉树 0
int BinaryTreeIsWhole(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	BTNode* tmp_null = BuyBTNode('#');
	//判断根节点是不是空
	if (root == NULL)
	{
		return 0;
	}
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* ret = QueueFront(&q);
		QueuePop(&q);
		//每次都要检测一下，看现在队列里面是不是含数据元素
		if (ret->_data == '#')
		{
			if (CheckHaveData(&q))
			{
				//不是完全二叉树，在此刻结束这个函数的时候队列中依旧还有元素，所以要进行销毁，否则就造成内存泄露
				QueueDestory(&q);
				return 0;
			}
			//是完全二叉树，在此刻结束这个函数的时候队列中依旧还有元素，所以要进行销毁，否则就造成内存泄露
			QueueDestory(&q);
			return 1;
		}
		if (ret->_left == NULL)
		{
			QueuePush(&q, tmp_null);
		}
		else
		{
			QueuePush(&q, ret->_left);
		}
		if (ret->_right == NULL)
		{
			QueuePush(&q, tmp_null);
		}
		else
		{
			QueuePush(&q, ret->_right);
		}
	}
	//完全二叉树
	return 1;
}

int BinaryTreeIsWhole_T(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	if (root)
	{
		while (QueueEmpty(&q))
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			if (front == NULL)
			{
				break;
			}
			else
			{
				QueuePush(&q, front->_left);
				QueuePush(&q, front->_right);
			}
		}
	}
	while (QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
		{
			QueuePop(&q);
		}
		else
		{
			//不是完全二叉树
			QueueDestory(&q);
			return 0;
		}
	}
	//是完全二叉树，树为空的话直接走到这里
	return 1;
}

//交换左右子树
void SwapLeftAndRight(BTNode** left, BTNode** right)
{
	assert(left && right);

	BTNode* tmp = (*left);
	(*left) = (*right);
	(*right) = tmp;
}

//求二叉树的镜像
//交换左右子树，采用递归的方法
//交换根节点的左右子树，就交换左子树的左右子树，交换右子树的左右子树
void BinaryTreeMirrorImage(BTNode* root)
{
	//空的二叉树就是镜像与原来的都一样，无需在进行求镜像
	if (root == NULL)
	{
		return;
	}

	SwapLeftAndRight(&root->_left, &root->_right);
	BinaryTreeMirrorImage(root->_left);
	BinaryTreeMirrorImage(root->_right);
}

//求二叉树的镜像
//采用非递归的方式
//第一种方法：
//思路：就和非递归遍历后序二叉树的一样，对于根节点是最后进行二叉树的交换的，与递归的方向刚好相反。从下到上进行交换
//void BinaryTreeMirrorImageNonR(BTNode* tree)
//{
//	//空的二叉树就是镜像与原来的都一样，无需在进行求镜像
//	if (tree == NULL)
//	{
//		return;
//	}
//
//	Stack s;
//	StackInit(&s);
//
//	BTNode* cur = tree;
//	BTNode* prev = NULL;
//
//	while (cur || StackEmpty(&s))
//	{
//		//将左路结点全部入栈
//		while (cur)
//		{
//			StackPush(&s, cur);
//			cur = cur->_left;
//		}
//
//		BTNode* top = StackTop(&s);
//		if (top->_right == NULL || top->_right == prev)
//		{
//			SwapLeftAndRight(&top->_left, &top->_right);
//			prev = top;
//			StackPop(&s);
//		}
//		else
//		{
//			cur = top->_right;
//		}
//	}
//}

//第二种方法
//采用非递归前序遍历二叉树的方法，来进行调整
//就和递归的思想一样，要交换根节点的左右子树结点，就要交换左右子树结点的左右子树，就这样一直交换下去，直到叶子节点

//void BinaryTreeMirrorImageNonR(BTNode* tree)
//{
//	assert(tree);
//
//	//空的二叉树就是镜像与原来的都一样，无需在进行求镜像
//	if (tree == NULL)
//	{
//		return;
//	}
//
//	Stack k;
//	StackInit(&k);
//	StackPush(&k, tree);
//
//	while (StackEmpty(&k))
//	{
//		BTNode* top = StackTop(&k);
//		StackPop(&k);
//
//		if (top->_left != NULL || top->_right != NULL)
//		{
//			SwapLeftAndRight(&top->_left, &top->_right);
//		}
//
//		if (top->_left != NULL)
//		{
//			StackPush(&k, top->_left);
//		}
//		if (top->_right != NULL)
//		{
//			StackPush(&k, top->_right);
//		}
//
//		if (top->_left == NULL && top->_right == NULL)
//		{
//			StackPop(&k);
//		}
//	}
//	//结束
//}


//第三种方法：采用层次遍历的方法
//对于每一个结点判断其左右孩子是否为空，如果有一个不为空就进行交换，并且将不为空的结点入队，
//然后出队头，再继续，直到堆为空

void BinaryTreeMirrorImageNonR(BTNode* tree)
{
	assert(tree);

	if (tree == NULL)
	{
		return;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, tree);

	//当队列不为空的时候,就进入循环
	while (QueueEmpty(&q))
	{
		//只要取出队头元素就将其进行出队，不再管其是否有用
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front->_left != NULL || front->_right != NULL)
		{
			SwapLeftAndRight(&front->_left, &front->_right);
		}

		if (front->_left != NULL)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right != NULL)
		{
			QueuePush(&q, front->_right);
		}
	}
}

//根据前序序列和中序序列重建二叉树
BTNode* Construct(int* Prevstart, int* Prevend, int* Instart, int* Inend)
{
	assert(Prevend && Prevstart && Instart && Inend);

	//创建根节点
	BTNode* root = BuyBTNode(*Prevstart);

	//判断该二叉树是不是只有一个根节点
	if (Prevend - Prevstart == 0)
	{
		if (Inend - Instart == 0 && *Prevstart == *Instart)
		{
			return root;
		}
		else
		{
			printf("请检查输入是否正确1！\n");
			exit(1);
		}
	}

	//该二叉树具有不止一个节点
	//在中序序列中，找到根节点，将其分为两个部分，在递归进行重建
	int* InOrderRoot = Instart;
	while (*InOrderRoot != *Prevstart && InOrderRoot < Inend)
	{
		InOrderRoot++;
	}

	//在中序遍历中，没有找到根节点
	if (InOrderRoot == Inend && *InOrderRoot != *Prevstart)
	{
		printf("请检查输入是否正确2!\n");
		exit(1);
	}

	//左子树的长度
	int length_right = InOrderRoot - Instart;
	//对左子树进行重建
	if (length_right > 0)
	{
		root->_left = Construct(Prevstart + 1, Prevstart + length_right, Instart, InOrderRoot - 1);
	}

	//对右子树进行重建
	if (length_right < Prevend - Prevstart)
	{
		root->_right = Construct(Prevstart + length_right + 1, Prevend, InOrderRoot + 1, Inend);
	}
	return root;
}

//树的子结构
bool DoTree1HaveTree2(BTNode* root1, BTNode* root2)
{
	if (root1 == NULL)
	{
		return false;
	}

	if (root2 == NULL)
	{
		return true;
	}

	if (root1->_data != root2->_data)
	{
		return false;
	}

	return DoTree1HaveTree2(root1->_left, root2->_left) && DoTree1HaveTree2(root1->_right, root2->_right);
}

bool HasSubTree(BTNode* root1, BTNode* root2)
{
	bool result = false;
	
	if (root2 == NULL)
	{
		return true;
	}

	if (root1 == NULL)
	{
		return false;
	}

	if (root1->_data == root2->_data)
	{
		result = DoTree1HaveTree2(root1, root2);
	}
	
	if (!result)
	{
		result = HasSubTree(root1->_left, root2);
	}

	if (!result)
	{
		result = HasSubTree(root1->_right, root2);
	}

	return result;
}

//和为某一值的路径
//传的是栈的值，所以在函数里面不会改变栈内的值
void FindPath(BTNode* root, int num, Stack s1, int count)
{
	assert(root);
	
	
	StackPush(&s1, root);
	BTNode* tmp = StackTop(&s1);
	count += tmp->_data;

	//和为要求得值，并且该节点的左右子树为空，则将该路径进行输出
	if (count == num && root->_left == NULL && root->_right == NULL)
	{
		while (StackEmpty(&s1))
		{
			printf("%d <- ", StackTop(&s1)->_data);
			StackPop(&s1);
		}
		printf("root");
		printf("\n");
	}

	if (root->_left != NULL)
	{
		FindPath(root->_left, num, s1,count);
	}

	if (root->_right != NULL)
	{
		FindPath(root->_right, num, s1,count);
	}
}

//创建一个栈，存放每次的结点
void Path(BTNode* root, int num)
{
	assert(root);

	Stack s1, s2;
	int count = 0;
	StackInit(&s1);
	FindPath(root, num, s1,count);
}