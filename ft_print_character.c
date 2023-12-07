#include "ft_printf.h"

int	ft_print_character(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_string("(null)"));
	while (str[i])
		i++;
	write (1, str, i);
	return (i);
}
