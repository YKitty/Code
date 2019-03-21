#include "HashTableBucket.h"

void HTBucketInit(HTBucket* htb, int len)
{
	assert(htb);

	len = GetNextPrime(len);

	htb->_tables = (HTBNode**)malloc(sizeof(HTBNode*) * len);
	if (htb->_tables == NULL)
	{
		perror("use malloc!\n");
		exit(1);
	}
	
	memset(htb->_tables, 0, sizeof(HTBNode*) * len);
	htb->_len = len;
	htb->_size = 0;
}

void HTBucketDestory(HTBucket* htb)
{
	assert(htb);

	int i = 0;
	HTBNode* cur = NULL;
	HTBNode* next = NULL;
	//��Ҫ�Ƚ�Ͱ����ҵĽ�����ɾ����Ȼ���ٽ�һά��������ÿ�
	for (i = 0; i < htb->_len; i++)
	{
		if (htb->_tables[i])
		{
			cur = htb->_tables[i];
			while (cur)
			{
				next = cur->_next;
				free(cur);
				cur = next;
			}
			//��һλ�����ÿ�
			htb->_tables[i] = NULL;
		}
	}
	free(htb->_tables);
	htb->_tables = NULL;
	htb->_len = 0;
	htb->_size = 0;
}

int HTBHashFunc(HTBKeyType key, int len)
{
	return key % len;
}

void HTBAddCapacity(HTBucket* htb)
{
	assert(htb);

	HTBucket newTable;
	HTBNode* cur = NULL;
	int len = GetNextPrime(htb->_len);
	HTBucketInit(&newTable, len);

	//���ɱ�Ľ����±�
	for (int i = 0; i < htb->_len; i++)
	{
		//��ÿ������Ԫ�ض�������
		cur = htb->_tables[i];
		while (cur)
		{
			int index = HTBHashFunc(cur->_key, newTable._len);
			
			//ͷ�巨
			cur->_next = newTable._tables[index];
			newTable._tables[index] = cur;

			cur = cur->_next;
			newTable._size++;
		}
	}

	//�ͷžɱ���ڴ�ռ䣬���±���ɱ�
	HTBucketDestory(htb);
	htb->_tables = newTable._tables;
	htb->_size = newTable._size;
	htb->_len = newTable._len;
}

HTBNode* HTBBuyNode(HTBKeyType key, HTBValueType value)
{
	HTBNode* newNode = (HTBNode*)malloc(sizeof(HTBNode));
	if (newNode == NULL)
	{
		perror("use malloc!\n");
	}

	newNode->_key = key;
	newNode->_value = value;
	newNode->_next = NULL;
	return newNode;
}

//1 �ɹ� 
//0 ʧ��
int HTBucketInsert(HTBucket* htb, HTBKeyType key, HTBValueType value)
{
	int i = 0;
	assert(htb);

	HTBNode* cur = NULL;
	//����
	if (htb->_len == htb->_size)
	{
		HTBAddCapacity(htb);
	}

	int index = HTBHashFunc(key, htb->_len);

	//����У��Ͳ��ڲ���
	cur = htb->_tables[index];
	while (cur)
	{		
		if (cur->_key == key)
		{
			return 0;
		}
		cur = cur->_next;
	}
	//û�У����в���
	cur = HTBBuyNode(key, value);
	cur->_next = htb->_tables[index];
	htb->_tables[index]= cur;
	htb->_size++;
	return 1;
}

//�ɹ� 1
//ʧ�� 0
int HTBucketRemove(HTBucket* htb, HTBKeyType key)
{	
	assert(htb);

	int index = HTBHashFunc(key, htb->_len);
	HTBNode* cur = NULL;
	HTBNode* prev = NULL;
	//����Ԫ��Ϊ��
	if (htb->_tables[index] == NULL)
	{
		return 0;
	}
	//��Ϊ��
	else
	{
		cur = htb->_tables[index];
		while (cur)
		{
			//�ҵ�
			if (cur->_key == key)
			{
				//ɾ����һ�����
				if (prev == NULL)
				{
					htb->_tables[index] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}
				htb->_size--;
				free(cur);
				cur = NULL;
				return 1;
			}
			prev = cur;
			cur = cur->_next;
		}
		return 0;
	}
}

HTBNode* HTBucketFind(HTBucket* htb, HTBKeyType key)
{
	assert(htb);

	int index = HTBHashFunc(key, htb->_len);
	HTBNode* cur = NULL;
	if (htb->_tables[index] == NULL)
	{
		return NULL;
	}
	else
	{
		cur = htb->_tables[index];

		while (cur)
		{
			if (cur->_key == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
	}
	return NULL;
}

int HTBucketSize(HTBucket* htb)
{
	assert(htb);
	return htb->_size;
}

int HTBucketEmpty(HTBucket* htb)
{
	assert(htb);

	return htb->_size == 0 ? 0 : 1;
}

void HTBucketPrint(HTBucket* htb)
{
	assert(htb);

	for (int i = 0; i < htb->_len; i++)
	{
		int count = 0;
		HTBNode* cur = htb->_tables[i];
		while (cur)
		{
			printf("[%d:%d]->", cur->_key, cur->_value);
			cur = cur->_next;
			count++;
		}
		printf("%d", count);
		printf("\n");
	}
	printf("\n");
}