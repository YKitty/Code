#include "Bloom Filter.h"

size_t HashFunc1(const char* str)
{
	assert(str);

	size_t hash = 0;
	while (*str)
	{
		hash = hash * 131 + (size_t)*str;
		str++;
	}

	return hash;
}

size_t HashFunc2(const char* str)
{
	assert(str);

	size_t hash = 0;
	while (*str)
	{
		hash = hash * 31 + (size_t)*str;
		str++;
	}

	return hash;
}

size_t HashFunc3(const char* str)
{
	assert(str);

	size_t hash = 0;
	while (*str)
	{
		hash = hash * 1313 + (size_t)*str;
		str++;
	}

	return hash;
}

void BloomFilterInit(BloomFilter* pbf, size_t n)
{
	assert(pbf);

	BitSetInit(&(pbf->_bs), n);
}

void BloomFilterDestory(BloomFilter* pbf)
{
	assert(pbf);

	BitSetDestory(&(pbf->_bs));
}

void BloomFilterSet(BloomFilter* pbf, const char* str)
{
	assert(pbf);

	size_t index1 = HashFunc1(str) % 20;
	size_t index2 = HashFunc2(str) % 20;
	size_t index3 = HashFunc3(str) % 20;


	BitSetSet(&(pbf->_bs), index1);
	BitSetSet(&(pbf->_bs), index2);
	BitSetSet(&(pbf->_bs), index3);
}

//´æÔÚ 1
//²»´æÔÚ 0
int BloomFilterCheck(BloomFilter* pbf, const char* str)
{
	assert(pbf);

	size_t index1 = HashFunc1(str) % 20;
	if (BitSetCheck(&(pbf->_bs), index1))
	{
		size_t index2 = HashFunc2(str) % 20;
		if (BitSetCheck(&(pbf->_bs), index2))
		{
			size_t index3 = HashFunc3(str) % 20;
			if (BitSetCheck(&(pbf->_bs), index3))
			{
				return 1;
			}
		}
	}

	return 0;
}
