#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_number(int n)
{
	char	*number;
	int	lenght;
	
	number = ft_itoa(n);
	lenght = print_str(number);
	return (lenght);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}


int	set_format(va_list args, char c)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));

	if (c == 's')
		return (print_str(va_arg(args, char *)));

	if (c == 'd' || c == 'i')
		return (print_number(va_arg(args, int)));

	if (c == '%')
		return (print_percent());

	return (1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	args;
	int	print;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print += set_format(args, str[i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			print++;
		}
	i++;
	}
	va_end(args);
	return (print);
}

int main ()
{

	printf("%u\n", 4294967293);
}
