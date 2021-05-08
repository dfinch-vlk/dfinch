#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *test_calloc()
{
	int *arr = calloc(sizeof(int), 10);
	int	*arr1 = (int *)ft_calloc(sizeof(int), 10);
	for (int i = 0; i < 10; i++)
		if (arr[i] != arr1[i])
			return ("Fail");
	return ("Success");
}

char *test_memcpy()
{
	char src[10] = {"123456"};
	char dst[10] = {""};
	char src1[10] = {"123456"};
	char dst1[10] = {""};	
	memcpy (dst, src, 6);
	ft_memcpy (dst1, src1, 6);
	return (strcmp(dst1, dst) == 0 ? "Success" : "Fail");
}

char *test_memset()
{
	char src[15] = {"1234567890"};
	char src1[15] = {"1234567890"};
	memset(src, '1', 10);
	ft_memset(src1, '1', 10);
	return (strcmp(src1, src) == 0 ? "Success" : "Fail");
}

int main()
{
	printf("memset: %s\n", test_memset());
	printf("memcpy: %s\n", test_memcpy());
	printf("calloc: %s\n", test_calloc());
	return 0;
}