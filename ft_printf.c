#include "printf.h"

static int	format_unsigned(char spec, va_list *args)
{
	int				base;
	int				uppercase;
	unsigned int	uvalue;
	int				result;

	if (spec == 'u')
	{
		base = 10;
		uppercase = 0;
	}
	if (spec == 'x')
	{
		base = 16;
		uppercase = 0;
	}
	if (spec == 'X')
	{
		base = 16;
		uppercase = 1;
	}
	uvalue = va_arg(*args, unsigned int);
	result = ft_putbase(uvalue, base, uppercase);
	return (result);
}

static int	format_basic(char spec, va_list *args)
{
	int		value;
	int		result;
	char	*str;

	if (spec == 'd' || spec == 'i')
	{
		value = va_arg(*args, int);
		result = ft_putnbr(value);
		return (result);
	}
	if (spec == 'c')
	{
		value = va_arg(*args, int);
		result = ft_putchar(value);
		return (result);
	}
	if (spec == 's')
	{
		str = va_arg(*args, char *);
		result = ft_putstr(str);
		return (result);
	}
	return (-1);
}

static int	format_pointer(void *ptr)
{
	int	count;
	int	result;

	count = 0;
	if (ptr == NULL)
	{
		result = ft_putstr("(nil)");
		if (result == -1)
			return (-1);
		count += result;
	}
	else
	{
		result = ft_putstr("0x");
		if (result == -1)
			return (-1);
		count += result;
		result = ft_putbase((unsigned long)ptr, 16, 0);
		if (result == -1)
			return (-1);
		count += result;
	}
	return (count);
}

static int	format_update(char spec, va_list *args)
{
	int	result;

	if (spec == 'd' || spec == 'i' || spec == 'c' || spec == 's')
		result = format_basic(spec, args);
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		result = format_unsigned(spec, args);
	else if (spec == 'p')
		result = format_pointer(va_arg(*args, void *));
	else if (spec == '%')
		result = ft_putchar('%');
	else
		result = -1;
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		result;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			result = format_update(format[++i], &args);
		else
			result = write(1, &format[i], 1);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}
