#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srs;
	size_t			i;

	dest = (unsigned char *)dst;
	srs = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = srs[i];
		if (dest[i] == (unsigned char)c)
			return ((void *)dest + i + 1);
		i++;
	}
	return (NULL);
}
