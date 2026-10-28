#include "printf.h"

static int	base_digit(char digits[20], unsigned long n, int base, int uppercase)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	while (n > 0)
	{
		if (n % base < 10)
			digits[i] = n % base + '0';
		if (n % base >= 10 && uppercase == 0)
			digits[i] = 'a' + (n % base - 10);
		if (n % base >= 10 && uppercase == 1)
			digits[i] = 'A' + (n % base - 10);
		n = n / base;
		i++;
	}
	while (i > 0)
	{
		result = write(1, &digits[--i], 1);
		if (result != 1)
			return (-1);
		count += result;
	}
	return (count);
}

int	ft_putbase(unsigned long n, int base, int uppercase)
{
	char	digits[20];
	int		count;
	int		result;

	if (base != 10 && base != 16)
		return (-1);
	if (n == 0)
	{
		result = write(1, "0", 1);
		if (result != 1)
			return (-1);
		return (result);
	}
	count = baseDigit(digits, n, base, uppercase);
	return (count);
}
