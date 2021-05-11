#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srs;
	size_t			i;

	dest = (unsigned char *)d;
	srs = (unsigned char *)s;
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
