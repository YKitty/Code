#ifndef __HASHBACKET_H__
#define __HASHBACKET_H__

#include "common.h"

typedef int HTBKeyType;
typedef int HTBValueType;

typedef struct HTBNode
{
	struct HTBNode* _next;
	HTBKeyType _key;
	HTBValueType _value;
}HTBNode;

typedef struct HTBucket
{
	HTBNode** _tables;//这个数组里面存放的是HTBNode* 类型的指针 
	int _size;
	int _len;
}HTBucket;


void HTBucketInit(HTBucket* htb, int len);
void HTBucketDestory(HTBucket* htb);

int HTBucketInsert(HTBucket* htb, HTBKeyType key, HTBValueType value);
int HTBucketRemove(HTBucket* htb, HTBKeyType key);
HTBNode* HTBucketFind(HTBucket* htb, HTBKeyType key);

int HTBucketSize(HTBucket* htb);
int HTBucketEmpty(HTBucket* htb);
void HTBucketPrint(HTBucket* htb);



#endif //__HASHBACKET_H__