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
		printf("����!\n");
	}
	else
	{
		printf("������!\n");
	}

	BitSetReSet(&hs, 5);

	ret = BitSetCheck(&hs, 5);
	if (ret)
	{
		printf("����!\n");
	}
	else
	{
		printf("������!\n");
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
		printf("�ҵ�sort!\n");
	}

	result = BloomFilterCheck(&bf, "sortr");
	if (result)
	{
		printf("�ҵ�sortr!\n");
	}
	else
	{
		printf("û���ҵ�sortr!\n");
	}

	BloomFilterDestory(&bf);
}

int main()
{
	//TestBitSet();
	TestBloomFilter();
	return 0;
}