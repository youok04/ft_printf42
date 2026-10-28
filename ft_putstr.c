#include "printf.h"

int	ft_putstr(char *st)
{
	int result;

	if (!st)
	{
		result = write(1, "(null)", 6);
		return (result);
	}
	result = write(1, st, ft_strlen(st));
	if (result == -1)
		return (-1);
	return (result);
}