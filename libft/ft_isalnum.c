#include "libft.h"

int	ft_isalnum(int c)
{
	if (48 <= c && c <= 57)
		return (8);
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (8);
	return (0);
}
