#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	ft_putstr_fd(ft_itoa(nbr), fd);
}
