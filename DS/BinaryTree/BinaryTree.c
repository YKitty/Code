#include "BinaryTree_M.h"

//����һ��BTNode*���͵Ľ��ռ�
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

//����ǰ���������һ����������char��
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

//����ǰ���������һ����������int��
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

//�����������ٺ�����
//˼�룺���ڶ������������ٵĻ��������Ҷ�ӽڵ㿪ʼ�������٣�������Ҳ��������Ľ����
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}

	//���ٵĻ���Ҫȫ������,ֻ�е�root��������ָ�붼ΪNULL��ʱ�������root���
	//ֻ�е�������Ϊ�յ�ʱ�򣬲����ж����������������ٷ������������ĺ���
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free((*root));
	(*root) = NULL;
	//printf("���ٳɹ�!\n");
}

//���������� �ݹ�&&�ǵݹ�
//ǰ�����
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

//�������
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

//�������
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

//��α���
//˼�룺�Զ��������в�α������ö��еĽṹ�����о����Ƚ��ȳ����ص�,����������Ϊ�գ������е�Ԫ�ض��Ѿ����
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

//�ǵݹ����������
//ǰ����������ڵ�  ������    ��������
//˼·���Ƚ��ö���������·���ѹջ�����꣬Ȼ���ڷ��ʸ��ڵ㣬Ȼ���ٶ��ҽ����иղ�ͬ�������飬
//������·���ѹջ������Ȼ���ڷ����ҽ�㣬��������:�ýڵ���Ҷ�ӾͲ���Ҫ�ڽ���ѹջ��������г�ջ�Ϳ�����
void BinaryTreePrevOrderNonR(BTNode* root)
{
	assert(root);

	Stack s;
	StackInit(&s);
	BTNode* cur = root;

	//StackEmpty���������Ϊ�ڱ����Ĺ����У�cur�п��ܻ����NULL
	while (cur || StackEmpty(&s))
	{
		//��ÿ��������·���ȫ������ѹջ����ѹջ
		while (cur)
		{
			StackPush(&s, cur);
			printf("%c ", cur->_data);
			cur = cur->_left;
		}

		BTNode* top = StackTop(&s);
		StackPop(&s);

		//��ʼ�����Ѿ�����ջ�Ľ�����·���
		cur = top->_right;
	}

	printf("\n");
}

//���������������  ���ڵ�   ��������
//˼�룺���������ǰ���������һ����ֻ�������������ݵ�λ�ò�ͬ������������ڶԸýڵ���г�ջ��ʱ�򣬷��ʸýڵ�
void BinaryTreeInOrderNonR(BTNode* root)
{
	assert(root);

	Stack s;
	StackInit(&s);
	BTNode* cur = root;

	//StackEmpty���������Ϊ�ڱ����Ĺ����У�cur�п��ܻ����NULL
	while (cur || StackEmpty(&s))
	{
		//��ÿ��������·���ȫ������ѹջ
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}

		BTNode* top = StackTop(&s);
		printf("%c ", top->_data);
		StackPop(&s);

		//��ʼ���ʳ�ջ�Ľ���������
		cur = top->_right;
	}

	printf("\n");
}

//���������������   ������   ���ڵ㣩
//˼�룺�Ƚ���·���ȫ����ջ��Ȼ���ջ��ʱ��
//����ж��Ƿ�Ҫ���ʸý�㣬
//����ýڵ���ҽ��Ϊ�յĻ������߸ý����ҽ����ڸշ��ʵ���һ���ڵ�prev���Ǿ�ֱ�ӷ��ʸýڵ�
//������Ǹýڵ���ҽ��û�н��з����أ��Ǿͷ��ʸýڵ���ҽ��
void BinaryTreePostOrderNonR(BTNode* root)
{
	assert(root);

	Stack s;
	StackInit(&s);
	//prev��¼���ǳ�ջ�Ľ��
	BTNode* prev = NULL;
	BTNode* cur = root;

	//cur���������Ϊ��ʼҪ��cur���룬ֻ�������ڱ�����ʱ��cur���Բ������NULL
	while (cur || StackEmpty(&s))
	{
		//����·���ȫ����ջ
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}

		BTNode* top = StackTop(&s);
		//˵���ýڵ���ҽ���Ѿ����ʹ��ˣ����Խ��������
		if (top->_right == NULL || top->_right == prev)
		{
			StackPop(&s);
			prev = top;
			printf("%c ", top->_data);
		}
		//�ýڵ���ҽ��û�з��ʹ�,�Ǿͼ������ҽ�������ѭ��
		else
		{
			cur = top->_right;
		}
	}
	printf("\n");
}

//��������Ľ����
//�������Ľ���������������Ľ�������������Ľ����֮���ټ��ϸ��ڵ㣬 ������root == NULL
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

//���������Ҷ�ӽ��ĸ���
//˼�룺����ڵ����������Ҷ�ӽڵ�ĸ���������������Ҷ�ӽڵ�ĸ������ڽ��з��أ�
//������root->_left == NULL,root->_right == NULL, return 1;  root == NULL , return 0;
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

//��������ĵ�K��Ľڵ�ĸ���
//˼�룺����ڵ��ǵ�һ�㣬�򷽷������K�㣬������ýڵ����������K-1��ĸ�������������K-1��ĸ���������:K == 1
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

//�����ڵݹ���Ҫ���ؽ�����Ҫ�ڸõݹ麯���У����оֲ������Ķ��壬ʹ�þֲ��������з�������ա�
//������þֲ��������н��յĻ�����ô�ͻᵼ�·��صĶ�����ʧ

//��������ĸ߶�
//˼�룺���ڵ�ĸ߶ȵ�������������ĸ߶ȼ���1��������root == NULL
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

//�����������С���
//˼·�����ڵ�������ҽ���н�С��ֵ��һ
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

//�ж�һ������Ƿ���һ����������
//˼�룺�ȼ����ڵ��Ƿ���ȣ��ڼ�����������ڼ����������������root->_data == x, root == NULL
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

//��һ������˫�׽��
//˼·���Ӹ��ڵ㿪ʼ���жϸ��ڵ�������������������Ȳ����������㣬
//����ǵĻ����ͷ��ظýڵ�,�������жϸýڵ����������������
//������root == NULL
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

//�����������Ƿ��������Ԫ��
//˼·������һ����У����
//�з���1��û��0
int CheckHaveData(Queue* pq)
{
	assert(pq);

	//�Զ��н���һ�α���ֻҪ��������Ԫ�ؾͽ��з���
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

//�ж�һ���������ǲ�����ȫ������
//˼·�����Բ��ò�α��������ĳһ������ǿյĻ�Ҳ������ӣ�������#�����ֻҪ��������֣�#������Ȼ������Ԫ�أ�
//��ô�ö��оͲ�����ȫ�����������������ȫ������
//����ȫ������ 1
//������ȫ������ 0
int BinaryTreeIsWhole(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	BTNode* tmp_null = BuyBTNode('#');
	//�жϸ��ڵ��ǲ��ǿ�
	if (root == NULL)
	{
		return 0;
	}
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* ret = QueueFront(&q);
		QueuePop(&q);
		//ÿ�ζ�Ҫ���һ�£������ڶ��������ǲ��Ǻ�����Ԫ��
		if (ret->_data == '#')
		{
			if (CheckHaveData(&q))
			{
				//������ȫ���������ڴ˿̽������������ʱ����������ɻ���Ԫ�أ�����Ҫ�������٣����������ڴ�й¶
				QueueDestory(&q);
				return 0;
			}
			//����ȫ���������ڴ˿̽������������ʱ����������ɻ���Ԫ�أ�����Ҫ�������٣����������ڴ�й¶
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
	//��ȫ������
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
			//������ȫ������
			QueueDestory(&q);
			return 0;
		}
	}
	//����ȫ����������Ϊ�յĻ�ֱ���ߵ�����
	return 1;
}

//������������
void SwapLeftAndRight(BTNode** left, BTNode** right)
{
	assert(left && right);

	BTNode* tmp = (*left);
	(*left) = (*right);
	(*right) = tmp;
}

//��������ľ���
//�����������������õݹ�ķ���
//�������ڵ�������������ͽ�����������������������������������������
void BinaryTreeMirrorImage(BTNode* root)
{
	//�յĶ��������Ǿ�����ԭ���Ķ�һ���������ڽ�������
	if (root == NULL)
	{
		return;
	}

	SwapLeftAndRight(&root->_left, &root->_right);
	BinaryTreeMirrorImage(root->_left);
	BinaryTreeMirrorImage(root->_right);
}

//��������ľ���
//���÷ǵݹ�ķ�ʽ
//��һ�ַ�����
//˼·���ͺͷǵݹ���������������һ�������ڸ��ڵ��������ж������Ľ����ģ���ݹ�ķ���պ��෴�����µ��Ͻ��н���
//void BinaryTreeMirrorImageNonR(BTNode* tree)
//{
//	//�յĶ��������Ǿ�����ԭ���Ķ�һ���������ڽ�������
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
//		//����·���ȫ����ջ
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

//�ڶ��ַ���
//���÷ǵݹ�ǰ������������ķ����������е���
//�ͺ͵ݹ��˼��һ����Ҫ�������ڵ������������㣬��Ҫ��������������������������������һֱ������ȥ��ֱ��Ҷ�ӽڵ�

//void BinaryTreeMirrorImageNonR(BTNode* tree)
//{
//	assert(tree);
//
//	//�յĶ��������Ǿ�����ԭ���Ķ�һ���������ڽ�������
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
//	//����
//}


//�����ַ��������ò�α����ķ���
//����ÿһ������ж������Һ����Ƿ�Ϊ�գ������һ����Ϊ�վͽ��н��������ҽ���Ϊ�յĽ����ӣ�
//Ȼ�����ͷ���ټ�����ֱ����Ϊ��

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

	//�����в�Ϊ�յ�ʱ��,�ͽ���ѭ��
	while (QueueEmpty(&q))
	{
		//ֻҪȡ����ͷԪ�ؾͽ�����г��ӣ����ٹ����Ƿ�����
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

//����ǰ�����к����������ؽ�������
BTNode* Construct(int* Prevstart, int* Prevend, int* Instart, int* Inend)
{
	assert(Prevend && Prevstart && Instart && Inend);

	//�������ڵ�
	BTNode* root = BuyBTNode(*Prevstart);

	//�жϸö������ǲ���ֻ��һ�����ڵ�
	if (Prevend - Prevstart == 0)
	{
		if (Inend - Instart == 0 && *Prevstart == *Instart)
		{
			return root;
		}
		else
		{
			printf("���������Ƿ���ȷ1��\n");
			exit(1);
		}
	}

	//�ö��������в�ֹһ���ڵ�
	//�����������У��ҵ����ڵ㣬�����Ϊ�������֣��ڵݹ�����ؽ�
	int* InOrderRoot = Instart;
	while (*InOrderRoot != *Prevstart && InOrderRoot < Inend)
	{
		InOrderRoot++;
	}

	//����������У�û���ҵ����ڵ�
	if (InOrderRoot == Inend && *InOrderRoot != *Prevstart)
	{
		printf("���������Ƿ���ȷ2!\n");
		exit(1);
	}

	//�������ĳ���
	int length_right = InOrderRoot - Instart;
	//�������������ؽ�
	if (length_right > 0)
	{
		root->_left = Construct(Prevstart + 1, Prevstart + length_right, Instart, InOrderRoot - 1);
	}

	//�������������ؽ�
	if (length_right < Prevend - Prevstart)
	{
		root->_right = Construct(Prevstart + length_right + 1, Prevend, InOrderRoot + 1, Inend);
	}
	return root;
}

//�����ӽṹ
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

//��Ϊĳһֵ��·��
//������ջ��ֵ�������ں������治��ı�ջ�ڵ�ֵ
void FindPath(BTNode* root, int num, Stack s1, int count)
{
	assert(root);
	
	
	StackPush(&s1, root);
	BTNode* tmp = StackTop(&s1);
	count += tmp->_data;

	//��ΪҪ���ֵ�����Ҹýڵ����������Ϊ�գ��򽫸�·���������
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

//����һ��ջ�����ÿ�εĽ��
void Path(BTNode* root, int num)
{
	assert(root);

	Stack s1, s2;
	int count = 0;
	StackInit(&s1);
	FindPath(root, num, s1,count);
}