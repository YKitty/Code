#include "BitSet.h"
#include "Bloom Filter.h"

void TestBitSet()
{
	bitset hs;
	BitSetInit(&hs, 20);

	BitSetSet(&hs, 1);
	BitSetSet(&hs, 5);
	BitSetSet(&hs, 10);

	int ret = BitSetCheck(&hs, 5);
	if (ret)
	{
		printf("存在!\n");
	}
	else
	{
		printf("不存在!\n");
	}

	BitSetReSet(&hs, 5);

	ret = BitSetCheck(&hs, 5);
	if (ret)
	{
		printf("存在!\n");
	}
	else
	{
		printf("不存在!\n");
	}

	BitSetDestory(&hs);
}

void TestBloomFilter()
{
	BloomFilter bf;
	BloomFilterInit(&bf, 20);

	BloomFilterSet(&bf, "sort");
	BloomFilterSet(&bf, "delete");
	BloomFilterSet(&bf, "size");

	int result = BloomFilterCheck(&bf, "sort");
	if (result)
	{
		printf("找到sort!\n");
	}

	result = BloomFilterCheck(&bf, "sortr");
	if (result)
	{
		printf("找到sortr!\n");
	}
	else
	{
		printf("没有找到sortr!\n");
	}

	BloomFilterDestory(&bf);
}

int main()
{
	//TestBitSet();
	TestBloomFilter();
	return 0;
}