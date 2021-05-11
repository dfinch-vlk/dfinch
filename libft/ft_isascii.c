#include "libft.h"

int	ft_isascii(int symbol)
{
	if (symbol >= 0 && symbol <= 127)
		return (1);
	return (0);
}
