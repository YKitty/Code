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

//����ĳһλ���и�ֵ
void BitSetSet(bitset* phs, size_t n);
//��ĳһλ����ɾ��
void BitSetReSet(bitset* phs, size_t n);
//���ĳһλ�Ƿ����
int BitSetCheck(bitset* phs, size_t n);

#endif // __BITSET_H__
