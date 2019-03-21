#include "HashTable.h"
#include "HashTableBucket.h"

void TsetHashtable()
{
	HashTable table;
	HTInit(&table, 5);

	HTInsert(&table, "傻逼", "插入");
	HTInsert(&table, "delete", "删除");
	HTInsert(&table, "root", "根");
	HTInsert(&table, "size", "大小");
	HTInsert(&table, "szie", "大");


	HTRemove(&table, "insert");

	HashNode* ret = HTFind(&table, "delete");
	if (ret)
	{
		printf("找到:%s,%s\n",ret->_key, ret->_value);
	}
	else
	{
		printf("没有找到!\n");
	}
	printf("\n");

	HTPrint(&table);
	printf("大小:%d\n", HTSize(&table));
	printf("是否为空:\n");
	if (HTEmpty(&table) == 1)
	{
		printf("不为空!\n");
	}
	else
	{
		printf("为空!\n");
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