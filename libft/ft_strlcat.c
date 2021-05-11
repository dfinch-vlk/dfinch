#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (dst[i] != '\0')
		i++;
	res = 0;
	while (src[res] != '\0')
		res++;
	if (dstsize <= i)
		res = res + dstsize;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
