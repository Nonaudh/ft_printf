#include "ft_printf.h"

int	ft_print_unsigned_decimal(unsigned int n)
{
	int nb_lenght;

	nb_lenght = ft_decimal_lenght(n);
	if (n >= 10)
	{
		ft_print_unsigned_decimal(n / 10);
		n = n % 10;
	}
	ft_print_character(n + 48);
	return (nb_lenght);
}

int	ft_print_integer(long n)
{
	int nb_lenght;

	nb_lenght = ft_decimal_lenght(n);
	if (n < 0)
	{
		ft_print_character('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_integer(n / 10);
		n = n % 10;
	}
	ft_print_character(n + 48);
	return (nb_lenght);
}

int	ft_decimal_lenght(long n)
{
	int lenght;

	lenght = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		lenght++;
	}
	while (n > 0)
	{
		n = n / 10;
		lenght++;
	}
	return (lenght);
}

int	ft_unsigned_num_lenght(unsigned long n)
{
	int lenght;

	lenght = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		lenght++;
	}
	return (lenght);
}