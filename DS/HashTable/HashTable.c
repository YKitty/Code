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

	//�����е�hash���״̬��Ϊ��
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

//����������
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

//����
//˼�룺��������һ���µĹ�ϣ�����ɱ�����ݷ����±�Ȼ��ɾ���±�
void AddCapacity(HashTable* ht)
{
	int i = 0;
	assert(ht);

	HashTable newTable;
	newTable._len = GetNextPrime(ht->_len);
	HTInit(&newTable, newTable._len);

	//���ɵı��ֵ���±�
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

	//�ٽ��±�ֵ���ɱ�
	free(ht->_table);
	ht->_table = newTable._table;
	ht->_len = newTable._len;
	ht->_size = newTable._size;
}



int HTInsert(HashTable* ht, HTKeyType key, HTValueType value)
{
	assert(ht);

	//�ж��Ƿ���,����װ������
	if (ht->_size * 10 /ht->_len > 7)
	{
		AddCapacity(ht);
	}

	int i = 1;
	int start = 0;
	//����
	int index = HTHashFunc(key, ht->_len);

	//�����ͻ
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
			//����̽��
			index++;
			//�ҵ����һ��λ�ã�Ҫ�ص�ǰ��
			if (index == ht->_len)
			{
				index = 0;
			}

			//����̽��
			/*index = index + i * i;
			index = HTHashFunc(index, ht->_len);
			i++;*/
		}
	}

	//�ҵ�Ҫ�����λ��
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
		//�жϲ��ҵ����ݴ��ڻ���ɾ��
		if (strcmp(ht->_table[index]._key , key) == 0)
		{
			//����
			if (ht->_table[index]._state == EXIST)
			{
				return &ht->_table[index];
			}
			//ɾ��
			else
			{
				return NULL;
			}
		}
		//�������̽��
		else
		{
			//����̽��
			index++;

			if (index == ht->_len)
			{
				index = 0;
			}
		}
	}

	//û���ҵ�
	return NULL;
}

//ɾ��һ�����ֻ�ǽ����״̬��ΪDELETE�������ǽ����ݽ���ɾ����
int HTRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);

	//��ϣ��Ϊ���޷�ɾ��
	if (ht->_table == NULL)
	{
		return 0;
	}

	HashNode* aim_node = HTFind(ht, key);

	//�ҵ�Ҫɾ���Ľ��
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