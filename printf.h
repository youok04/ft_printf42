#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *st);
int		ft_putnbr(int n);
int		ft_putbase(unsigned long n, int base, int uppercase);
size_t	ft_strlen(char *st);

#endif
