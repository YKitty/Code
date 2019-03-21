#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//ËØÊý±í
static int GetNextPrime(int len)
{
	unsigned long PrimeSize = 28;
	unsigned long i = 0;

	unsigned long PrimeList[28] = {
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 20132611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
	};
	while (len >= PrimeList[i] && i < PrimeSize)
	{
		i++;
	}
	if (i == 28)
	{
		return PrimeList[27];
	}
	else
	{
		return PrimeList[i];
	}
}


#endif //__COMMON_H__