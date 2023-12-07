#include "ft_printf.h"


int	set_format(va_list args, char format)
{
	if (format == 'c')
		return (ft_print_character(va_arg(args, int)));

	if (format == 's')
		return (ft_print_string(va_arg(args, char *)));

	if (format == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long)));

	if (format == 'd' || format == 'i')
		return (ft_print_integer(va_arg(args, int)));

	if (format == 'u')
		return (ft_print_unsigned_decimal(va_arg(args, int)));

	if (format == 'X')
		return (ft_print_hexadecimal(va_arg(args, int), format));

	if (format == 'x')
		return (ft_print_hexadecimal(va_arg(args, int), format));

	if (format == '%')
		return (ft_print_character('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	args;
	int	printed_characters;

	i = 0;
	printed_characters = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			printed_characters += set_format(args, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			printed_characters++;
		}
	i++;
	}
	va_end(args);
	return (printed_characters);
}

/*
int main ()
{
	int test = 4269;

	int number;

	printf("%X\n", test);
	number = ft_printf("%X\n", test);
	printf("num; %d", number);
}
*/