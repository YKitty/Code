#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__

#include "BitSet.h"
#include "Common.h"

//���������һ��λͼ��ֻ����ÿ������hash��ַ
typedef struct BloomFilter
{
	bitset _bs;
}BloomFilter;

void BloomFilterInit(BloomFilter* pbf, size_t n);
void BloomFilterDestory(BloomFilter* pbf);

void BloomFilterSet(BloomFilter* pbf, const char* str);
int BloomFilterCheck(BloomFilter* pbf, const char* str);

#endif // __BLOOMFILTER_H__


