#include "libft.h"

int	ft_isalnum(int symbol)
{
	if (48 <= symbol && symbol <= 57)
		return (8);
	if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122))
		return (8);
	return (0);
}
