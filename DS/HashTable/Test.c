#include "HashTable.h"
#include "HashTableBucket.h"

void TsetHashtable()
{
	HashTable table;
	HTInit(&table, 5);

	HTInsert(&table, "ɵ��", "����");
	HTInsert(&table, "delete", "ɾ��");
	HTInsert(&table, "root", "��");
	HTInsert(&table, "size", "��С");
	HTInsert(&table, "szie", "��");


	HTRemove(&table, "insert");

	HashNode* ret = HTFind(&table, "delete");
	if (ret)
	{
		printf("�ҵ�:%s,%s\n",ret->_key, ret->_value);
	}
	else
	{
		printf("û���ҵ�!\n");
	}
	printf("\n");

	HTPrint(&table);
	printf("��С:%d\n", HTSize(&table));
	printf("�Ƿ�Ϊ��:\n");
	if (HTEmpty(&table) == 1)
	{
		printf("��Ϊ��!\n");
	}
	else
	{
		printf("Ϊ��!\n");
	}

	HTPrint(&table);

	HTDestroy(&table);

}

void TestHashtableBucket()
{
	HTBucket table;
	int i = 0;
	HTBucketInit(&table, 10);

	for (i = 0; i < 3; i++)
	{
		HTBucketInsert(&table, i, 0);
	}

	HTBucketPrint(&table);

	HTBucketInsert(&table, 53, 1);
	HTBucketPrint(&table);


	HTBucketDestory(&table);
}


int main()
{
	//TsetHashtable();
	TestHashtableBucket();
	return 0;
}