#include "HashTable.h"

void HTInit(HashTable* ht, int len)
{
	assert(ht);

	len = GetNextPrime(len);

	ht->_table = (HashNode*)malloc(sizeof(HashNode) * len);
	if (ht->_table == NULL)
	{
		perror("use malloc!");
	}

	memset(ht->_table, 0, sizeof(HashNode) * len);

	//将所有的hash结点状态置为空
	for (int i = 0; i < len; i++)
	{
		ht->_table[i]._state = EMPTY;
	}

	ht->_len = len;
	ht->_size = 0;
}

void HTDestroy(HashTable* ht)
{
	assert(ht);

	ht->_table = NULL;
	ht->_len = 0;
	ht->_size = 0;
}

//除留余数法
//int HTHashFunc(HTKeyType key, int len)
//{
//	return key % len;
//}

int HTHashFunc(HTKeyType key, int len)
{
	int i = 0;
	int count = 0;
	while (key[i] != '\0')
	{
		count = count  + key[i++];
	}

	return (unsigned int)count % len;
}

//增容
//思想：重新申请一个新的哈希表，将旧表的数据放在新表，然后删除新表
void AddCapacity(HashTable* ht)
{
	int i = 0;
	assert(ht);

	HashTable newTable;
	newTable._len = GetNextPrime(ht->_len);
	HTInit(&newTable, newTable._len);

	//将旧的表的值给新表
	for (i = 0; i < ht->_len; i++)
	{
		if (ht->_table[i]._state == EXIST)
		{
			int index = HTHashFunc(ht->_table[i]._key, newTable._len);
			newTable._table[index]._key = ht->_table[i]._key;
			newTable._table[index]._value = ht->_table[i]._value;
			newTable._table[index]._state = EXIST;
			newTable._size++;
		}
	}

	//再将新表赋值给旧表
	free(ht->_table);
	ht->_table = newTable._table;
	ht->_len = newTable._len;
	ht->_size = newTable._size;
}



int HTInsert(HashTable* ht, HTKeyType key, HTValueType value)
{
	assert(ht);

	//判断是否满,运用装载因子
	if (ht->_size * 10 /ht->_len > 7)
	{
		AddCapacity(ht);
	}

	int i = 1;
	int start = 0;
	//插入
	int index = HTHashFunc(key, ht->_len);

	//解决冲突
	while (ht->_table[index]._state == EXIST)
	{
		/*if (ht->_table[index]._key == key)
		{
			return 0;
		}*/
		if (strcmp(ht->_table[index]._key, key) == 0)
		{
			return 0;
		}
		else
		{
			//线性探测
			index++;
			//找到最后一个位置，要回到前面
			if (index == ht->_len)
			{
				index = 0;
			}

			//二次探测
			/*index = index + i * i;
			index = HTHashFunc(index, ht->_len);
			i++;*/
		}
	}

	//找到要插入的位置
	ht->_table[index]._key = key;
	ht->_table[index]._value = value;
	ht->_table[index]._state = EXIST;
	ht->_size++;
	return 1;
}

HashNode* HTFind(HashTable* ht, HTKeyType key)
{
	assert(ht);

	int index = HTHashFunc(key, ht->_len);
	int i = 1;

	while (ht->_table[index]._state != EMPTY)
	{
		//判断查找的数据存在还是删除
		if (strcmp(ht->_table[index]._key , key) == 0)
		{
			//存在
			if (ht->_table[index]._state == EXIST)
			{
				return &ht->_table[index];
			}
			//删除
			else
			{
				return NULL;
			}
		}
		//继续向后探测
		else
		{
			//线性探测
			index++;

			if (index == ht->_len)
			{
				index = 0;
			}
		}
	}

	//没有找到
	return NULL;
}

//删除一个结点只是将结点状态变为DELETE，而不是将数据进行删除了
int HTRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);

	//哈希表为空无法删除
	if (ht->_table == NULL)
	{
		return 0;
	}

	HashNode* aim_node = HTFind(ht, key);

	//找到要删除的结点
	if (aim_node)
	{
		aim_node->_state = DELETE;
		ht->_size--;
		return 1;
	}

	return 0;
}

int HTSize(HashTable* ht)
{
	assert(ht);

	return ht->_size;
}

int HTEmpty(HashTable* ht)
{
	assert(ht);

	return ht->_size == 0 ? 0 : 1;
}

void HTPrint(HashTable* ht)
{
	assert(ht);

	char* state[] = { "EMPTY", "EXIST", "DELETE" };


	for (int i = 0; i < ht->_len; i++)
	{
		printf("%s:[%s:%s]\n", state[ht->_table[i]._state], ht->_table[i]._key, ht->_table[i]._value);
	}

	printf("\n");
}