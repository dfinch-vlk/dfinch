#include "libft.h"

void	ft_putnbr_fd(int nmb, int fd)
{
	unsigned int	nbr;

	if (nmb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(nmb * -1);
	}
	else
		nbr = (unsigned int)nmb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}
