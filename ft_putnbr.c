#include "printf.h"

static int	putnbr_digits(long nb)
{
	int		count;
	int		result;
	char	c;

	count = 0;
	if (nb >= 10)
	{
		result = putnbr_digits(nb / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	c = nb % 10 + '0';
	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		result;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		result = write(1, "-", 1);
		if (result == -1)
			return (-1);
		nb = -nb;
		count += result;
	}
	result = putnbr_digits(nb);
	return (count + result);
}
