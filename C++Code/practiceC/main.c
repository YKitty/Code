#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

//int main()
//{
//	printf("\?\?\>");
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		exit(1);
//	}
//	else
//	{
//		printf("haha\n");
//	}
//
//	int* ptr = realloc(p, 10);
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	else
//	{
//		exit(1);
//	}
//
//	int* p1 = (int*)calloc(10, 10);
//	if (p1 == NULL)
//	{
//		exit(1);
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}


//int main()
//{
//	typedef struct student
//	{
//		int num;
//		//int arr[0];
//		int arr[];
//	}Stu;
//
//	typedef struct 
//	{
//		int num;
//		//int arr[0];
//		int* arr;
//	}Stu1;
//	printf("%d\n", sizeof(Stu1));
//
//	printf("%d\n", sizeof(struct student));
//	//方便内存释放，减少内存碎片
//	Stu* student = (Stu*)malloc(sizeof(Stu) + sizeof(int) * 100);
//	//student->num = 100;
//	//student->arr = (int*)malloc(sizeof(int) * student->num);
//	//printf("%d\n", sizeof(*student));
//
//	return 0;
//}

//大端和小端的自我判断

//int check_sys()
//{
//	int i = 1;
//	return *(char*)&i;
//}

//int check_sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//
//	un.i = 1;
//	return un.c;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret)
//	{
//		printf("小端模式\n");
//	}
//	else 
//	{
//		printf("大端模式\n");
//	}
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	return 0;
//}

//将一个整数一个一个进行输出
//void Print(int num)
//{
//	if (num > 9)
//	{
//		Print(num / 10);
//	}
//
//
//	printf("%d\t", num % 10);
//}
//
//int main()
//{
//	int num = 1234;
//	Print(num);
//	printf("\n");
//	return 0;
//}

//编写函数不允许创建临时变量，求字符串的长度
//int my_strlen(const char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else return 1 + my_strlen(str + 1);
//}
//
//int main()
//{
//	char* str = "hello world";
//	printf("%d\n", my_strlen(str));
//	return 0;
//}

//求n的阶乘
//int Print(int num)
//{
//	if (num == 1)
//	{
//		return 1;
//	}
//	else return num * Print(num - 1);
//}
//
//int main()
//{
//	int num = 5;
//	printf("%d\n", Print(num));
//	return 0;
//}


//求第n和斐波那契数
//int count = 0;
//int fib(int num)
//{
//	if (num == 3)
//	{
//		count++;
//	}
//	if (num <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib(num - 1) + fib(num - 2);
//	}
//}
//
//int main()
//{
//	int num = 100;
//	printf("%d\ncount:%d\n", fib(num), count);
//	return 0;
//}

//采用非递归的方式书写阶乘
//int main()
//{
//	int num = 30;
//	int total = 1;
//	while (num > 1)
//	{
//		total *= num;
//		num--;
//	}
//	printf("%d\n", total);
//	return 0;
//}

//采用非递归的方式书写斐波那契数
//int main()
//{
//	int frist = 1;
//	int second = 1;
//	int num = 4;
//	int result = 0;
//	while (num > 2)
//	{
//		result = frist + second;
//		frist = second;
//		second = result;
//		num--;
//	}
//	printf("%d\n", result);
//	return 0;
//}

//main函数参数列表
//int main(int argc, char* argv[], char* envp[])
//{
//	int i = 0;
//	while (envp[i] != NULL)
//	{
//		printf("%s\n", envp[i]);
//		i++;
//	}
//
//	i = 0;
//	while (i < argc)
//	{
//		printf("%s\n", argv[i]);
//		i++;
//	}
//	return 0;
//}

//实现一个函数可以求任意个参数的平均值
//#include <stdarg.h>
//
//int average(int n, ...)
//{
//	va_list arg;
//	int i = 0;
//	int sum = 0;
//	va_start(arg, n);
//	while (i < n)
//	{
//		sum += va_arg(arg, int);
//		i++;
//	}
//	return sum / n;
//	va_end(arg);
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//	printf("average1:%d\n", average(2, a, b));
//	printf("average2:%d\n", average(3, a, b, c));
//
//	return 0;
//}

//指针加减整数决定指针向前向后走一步的距离多大
//int main()
//{
//	int n = 10;
//	char* pc = (char*)&n;
//	int* pi = &n;
//
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return 0;
//}

//指针的解引用
//表明指针的类型决定了对于指针解引用有多大的权限
//int main()
//{
//	int n = 0x11223344;
//	char* pc = (char*)&n;
//	int* pi = &n;
//
//	*pc = 0x55;
//	*pi = 0;
//	return 0;
//}

//三种方式实现my_strlen函数
//int my_strlen(char* str)
//{
//	int sum = 0;
//	while (*str != '\0')
//	{
//		sum++;
//		str++;
//	}
//
//	return sum;
//}

//int my_strlen(char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//
//}

//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//
//	return str - start;
//}
//
//int main()
//{
//	char* str = "asdghas";
//	printf("%d\n", my_strlen(str));
//	return 0;
//}

//实现strcpy函数
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}

//实现strcat函数
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}

//实现strstr函数
//char* my_strstr(const char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//
//	char* start = src;
//	char* begin = dest;
//	for ( ; begin; begin++)
//	{
//		char* tmp = begin;
//		for (start = src; start && tmp; start++, tmp++)
//		{
//			if (*start != *tmp)
//			{
//				break;
//			}
//		}
//
//		if (*start == '\0')
//		{
//			return begin;
//		}
//	}
//
//	return NULL;
//}

//实现strcmp函数
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//
//	while (*str1 && *str2)
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return 0;
//		}
//		else
//		{
//			str1++;
//			str2++;
//			continue;
//		}
//	}
//
//	if (*str1)
//	{
//		return 1;
//	}
//	else if (*str2)
//	{
//		return 0;
//	}
//	else
//	{
//		return 0;
//	}
//
//}

//实现memcpy函数
//void* my_memcpy(void* dst, const void* src, size_t size)
//{
//	assert(dst);
//	assert(src);
//
//	void* ret = dst;
//	while (size--)
//	{
//		*(char*)dst = *(char*)src;
//		dst = (char*)dst + 1;
//		src = (char*)src + 1;
//	}
//
//	return ret;
//}

//实现memmove函数
//void* my_memmove(void* dest, const void* src, size_t size)
//{
//	assert(dest);
//	assert(src);
//
//	void* ret = dest;
//	//分为两种情况，一种可覆盖，一种不会覆盖
//	//覆盖的只是考虑dest
//	//不会覆盖
//	if (src >= dest || ((char*)dest > (char*)src + size))
//	{
//		while (size--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//
//	else
//	{
//		while (size--)
//		{
//			*((char*)dest + size - 1) = *((char*)src + size - 1);
//		}
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char* src = "aaa";
//	char str[10] = "abcdef";
//	//printf("%s\n", my_strcpy(str, src));
//	//printf("%s\n", my_strcat(str, src));
//	//printf("%s\n", my_strstr(str, src));
//	//printf("%d\n", my_strcmp(str, src));
//	//printf("%s\n", my_memcpy(str, src, 4));
//	printf("%s\n", my_memmove(str, str + 2, 4));
//	return 0;
//}

//int main()
//{
//	int arr[2] = { 0 };
//	
//	//&arr是数组的地址，所以使用数组指针存放比较合适
//	int* p1 = &arr;
//	int(*p2)[10] = &arr;
//	printf("%p\n", p1);
//	printf("%p\n", p1 + 1);
//	printf("%p\n", p2);
//	printf("%p\n", p2 + 1);
//	/*printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr + 1);*/
//	return 0;
//}


//void print(int **arr)
//{
//}

//void print(int(*arr)[3])
//{
//}
//
//int main()
//{
//	int arr[5][3] = { 0 };
//	print(arr);
//	return 0;
//}


//extern char* arr1;
//extern char arr[];
//extern char p;
//
//int main()
//{
//	/*printf("%s\n", arr);
//	printf("%s\n", arr1);*/
//	printf("%s\n", (char*)*(int*)p);
//}

//(*(void(*)())0)();//函数的调用
//void(*signal(int, void(*)(int))))(int);//函数的声明

//typedef void(*ptr)(int);
//重命名一个函数指针

//函数指针
//void(*ptr)(int);
//函数指针数组
//void(*ptr[10])(int);
//函数指针数组的指针
//void(*(*ptr)[10])(int);

//函数指针数组的作用，转移表

//回调函数就是使用函数指针来调用函数
//回调函数实现bubble_sort

//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 > *(int*)p2);
//}
//
//void swap(void* p1, void* p2, size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		char tmp = *((char*)p1 + i);
//		*((char*)p1 + i) = *((char*)p2 + i);
//		*((char*)p2 + i) = tmp;
//	}
//}
//
//void bubble(int* base, int count, int size, int (*cmp)(const void*, const void*))
//{
//	for (size_t i = 0; i < count - 1; i++)
//	{
//		for (size_t j = 0; j < count - 1 - i; j++)
//		{
//			if ((cmp((void*)((char*)base + j * size), (void*)((char*)base + (j + 1) * size)) > 0))
//			{
//				swap((void*)((char*)base + j * size), (void*)((char*)base + (j + 1) * size), size);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1, 5, 4, 9, 8, 6, 4 };
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d\t", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

