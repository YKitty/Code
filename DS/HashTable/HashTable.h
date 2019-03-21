#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "common.h"

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

//typedef int HTKeyType;
//typedef int HTValueType;

typedef char* HTKeyType;
typedef char* HTValueType;

typedef struct HashNode
{
	enum State _state;
	HTKeyType _key;
	HTValueType _value;
}HashNode;

typedef struct HashTable
{
	HashNode* _table; //�����ݵ�hash�ı�
	int _len;    //��
	int _size;   //��С
}HashTable;

void HTInit(HashTable* ht, int len);
void HTDestroy(HashTable* ht);

int HTInsert(HashTable* ht, HTKeyType key, HTValueType value);
HashNode* HTFind(HashTable* ht, HTKeyType key);
int HTRemove(HashTable* ht, HTKeyType key);

int HTSize(HashTable* ht);
int HTEmpty(HashTable* ht);

void HTPrint(HashTable* ht);

#endif //__HASHTABLE_H__