#include "ft_printf.h"

int	ft_print_pointer_hexadecimal(unsigned long n)
{
	int nb_lenght;

	nb_lenght = ft_hexadecimal_lenght(n) + 2;
	if (n >= 16)
	{
		ft_print_pointer_hexadecimal(n / 16);
		n = n % 16;
	}
	if (n < 10)
		ft_print_character(n + 48);
	if (n > 9)
		ft_print_character(n + 87);
	return (nb_lenght);
}

int	ft_print_pointer(unsigned long n)
{
	if (!n)
		return (0);
	write(1, "0x", 2);
	return (ft_print_pointer_hexadecimal(n));
}

int	ft_print_hexadecimal_uppercase(unsigned int n)
{
	int nb_lenght;

	nb_lenght = ft_hexadecimal_lenght(n);
	if (n >= 16)
	{
		ft_print_hexadecimal_uppercase(n / 16);
		n = n % 16;
	}
	if (n < 10)
		ft_print_character(n + 48);
	if (n > 9)
		ft_print_character(n + 55);
	return (nb_lenght);
}

int	ft_print_hexadecimal_lowercase(unsigned int n)
{
	int nb_lenght;

	nb_lenght = ft_hexadecimal_lenght(n);
	if (n >= 16)
	{
		ft_print_hexadecimal_lowercase(n / 16);
		n = n % 16;
	}
	if (n < 10)
		ft_print_character(n + 48);
	if (n > 9)
		ft_print_character(n + 87);
	return (nb_lenght);
}