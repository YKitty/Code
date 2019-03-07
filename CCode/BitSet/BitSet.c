#include "BitSet.h"

//n代表的位的个数
void BitSetInit(bitset* phs, size_t n)
{
	assert(phs && n >= 0);

	//求出需要多少字节
	int bit = (n >> 3) + 1;

	phs->_bits = (char*)malloc(bit);
	if (phs->_bits == NULL)
	{
		perror("use malloc!\n");
	}

	memset(phs->_bits, 0, bit);
	phs->_size = n;
}

void BitSetDestory(bitset* phs)
{
	assert(phs);

	free(phs->_bits);
	phs->_bits = NULL;
	phs->_size = 0;
}

void BitSetSet(bitset* phs, size_t n)
{
	assert(phs && n >= 0);

	//先找到在那一个字节的位置
	int bit = n >> 3;
	int index = n % 8;

	phs->_bits[bit] |= (1 << index);
}

void BitSetReSet(bitset* phs, size_t n)
{
	assert(phs && n >= 0);

	int bit = n >> 3;
	int index = n % 8;

	phs->_bits[bit] &= ~(1 << index);
}

//存在 1
//不存在 0
int BitSetCheck(bitset* phs, size_t n)
{
	assert(phs && n >= 0);

	int bit = n >> 3;
	int index = n % 8;

	return (phs->_bits[bit] & (1 << index)) == 0 ? 0 : 1;
}
