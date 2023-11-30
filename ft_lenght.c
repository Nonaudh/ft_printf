#include "ft_printf.h"

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

int	ft_hexadecimal_lenght(unsigned long n)
{
	int lenght;

	lenght = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
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
