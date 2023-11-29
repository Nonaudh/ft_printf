#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	write (1, str, i);
	return (i);
}

int	ft_num_lenght(int n)
{
	long nb;
	int len;

	nb = (long)n;
	len = 0;

	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_hexa_num_lenght(int n)
{
	long nb;
	int len;

	nb = (long)n;
	len = 0;

	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = 4294967296 + nb;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_unsigned_num_lenght(int n)
{
	long nb;
	int len;

	nb = (long)n;
	len = 0;

	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = 4294967296 + nb;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	print_number(int n)
{
	long	nb;
	nb = (long)n;

	if (nb < 0)
	{
		print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		print_number(nb / 10);
		nb = nb % 10;
	}
	print_char(nb + 48);
	return (ft_num_lenght(n));
}

int	print_unsigned(int n)
{
	long	nb;
	nb = (long)n;

	if (nb < 0)
		nb = 4294967296 + nb;
	if (nb >= 10)
	{
		print_unsigned(nb / 10);
		nb = nb % 10;
	}
	print_char(nb + 48);
	return (ft_unsigned_num_lenght(n));
}

int	print_HEXAnumber(int n)
{
	long	nb;
	nb = (long)n;

	if (nb < 0)
		nb = 4294967296 + nb;
	if (nb >= 16)
	{
		print_HEXAnumber(nb / 16);
		nb = nb % 16;
	}
	if (nb < 10)
		print_char(nb + 48);
	if (nb > 9)
		print_char(nb + 55);
	return (ft_hexa_num_lenght(n));
}

int	print_hexanumber(int n)
{
	long	nb;
	nb = (long)n;

	if (nb < 0)
		nb = 4294967296 + nb;
	if (nb >= 16)
	{
		print_hexanumber(nb / 16);
		nb = nb % 16;
	}
	if (nb < 10)
		print_char(nb + 48);
	if (nb > 9)
		print_char(nb + 87);
	return (ft_hexa_num_lenght(n));
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

	if (c == 'u')
		return (print_unsigned(va_arg(args, int)));

	if (c == 'X')
		return (print_HEXAnumber(va_arg(args, int)));

	if (c == 'x')
		return (print_hexanumber(va_arg(args, int)));

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

/*
int main ()
{
	int test = -100;

	printf("%x\n", test);
	ft_printf("%x\n", test);
	printf("%d", ft_hexa_num_lenght(test));

}
*/