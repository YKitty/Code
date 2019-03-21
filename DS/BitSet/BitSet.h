#ifndef __BITSET_H__
#define __BITSET_H__

#include "Common.h"

typedef struct bitset
{
	char* _bits;
	int _size;
}bitset;

void BitSetInit(bitset* phs, size_t n);
void BitSetDestory(bitset* phs);

//对于某一位进行赋值
void BitSetSet(bitset* phs, size_t n);
//对某一位进行删除
void BitSetReSet(bitset* phs, size_t n);
//检测某一位是否存在
int BitSetCheck(bitset* phs, size_t n);

#endif // __BITSET_H__
