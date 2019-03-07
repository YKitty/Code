#include "BitSet.h"

//n�����λ�ĸ���
void BitSetInit(bitset* phs, size_t n)
{
	assert(phs && n >= 0);

	//�����Ҫ�����ֽ�
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

	//���ҵ�����һ���ֽڵ�λ��
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

//���� 1
//������ 0
int BitSetCheck(bitset* phs, size_t n)
{
	assert(phs && n >= 0);

	int bit = n >> 3;
	int index = n % 8;

	return (phs->_bits[bit] & (1 << index)) == 0 ? 0 : 1;
}
