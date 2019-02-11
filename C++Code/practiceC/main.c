#include <stdio.h>

//int main()
//{
//	printf("hahha\n");
//	return 0;
//}

//int main()
//{
//	//while (1)
//	printf("\\");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	printf("%d\n", strlen("abcdef"));
//	//\32表示1~3个八进制的数字
//	printf("%d\n", strlen("c:\test\32\test.c"));
//	printf("\1");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(long double));
//	return 0;
//}

//int main(void)
//{
//	int num = 0;
//	const int c_num = 0;//const􀗥
//	printf("%d\n", c_num);
//	int* p = &c_num;
//	num = 20;
//	*p = 30;
//	printf("%d\n", c_num);
//	//c_num = 20;//ok?
//	return 0;
//}

//int main()
//{
//	//int arr[􁵱􁥝􀓞􀓻􀬉􁰁];
//	const int sz = 10;
//	int arr[10];//ok
//	//int arr2[sz];//ok?
//	return 0;
//}

//enum sex
//{
//	one = 8,
//	two,
//	three = 11
//};
//
//int main()
//{
//	enum sex th = one;
//	printf("%d\n", one);
//	printf("%d\n", three);
//	return 0;
//}

//静态变量只有在该进程结束的时候才会销毁该变量

//void test()
//{
//	static int num = 0;
//	num++;
//	printf("%d\n", num);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i<10; i++)
//	{
//		test();
//	}
//	return 0;
//}

//printf函数的返回值是输出字符的个数
//int main()
//{
//	int i = 43;
//	printf("%d\n", printf("%d", printf("%d", i))); return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i = i + 1;
//		if (i == 5)
//			//break;
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//		putchar(ch);
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9' )
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2, y < 5; ++x, y++)
//	{
//		printf("haha\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int k = 0;
//	//执行0次，因为对于判断条件来说，直接就是0
//	//条件为假，所以直接退出
//	for (i = 0, k = 0; k = 0; i++, k++)
//	{
//		printf("hah\n");
//		k++;
//	}
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	do
//	{
//		printf("ahha\n");
//		x++;
//	} while (x < 10);
//	return 0;
//}


//实现一个二分查找函数
//int bin_search(int* arr, int left, int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = left + (right - left) >> 1;
//
//		if (arr[mid] == key)
//		{
//			return mid;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid;
//		}
//		else
//		{
//			right = mid;
//		}
//	}
//
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	int key = 0;
//	scanf("%d", &key);
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]);
//	int ret = bin_search(arr, left, right, key);
//	if (ret)
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	else
//	{
//		printf("没有找到!\n");
//	}
//	/*int mid = 0;
//	while (left <= right)
//	{
//		mid = left + ((right - left) >> 1);
//
//		if (arr[mid] == key)
//		{
//			break;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("没有找到!\n");
//	}
//	else
//	{
//		printf("找到了!下标是:%d\n", mid);
//	}*/
//	return 0;
//}

int main()
{
	printf("\?\?\>");
	return 0;
}







