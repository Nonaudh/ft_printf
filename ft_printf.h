/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:45:21 by ahuge             #+#    #+#             */
/*   Updated: 2023/11/09 16:06:43 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#include <stdio.h>//////
#include <limits.h>/////

int	ft_printf(const char *str, ...);
int	ft_decimal_lenght(long n);
int	ft_hexadecimal_lenght(unsigned long n);
int	ft_unsigned_num_lenght(unsigned long n);
int	ft_print_character(int c);
int	ft_print_string(char *str);
int	ft_print_pointer_hexadecimal(unsigned long n);
int	ft_print_pointer(unsigned long n);
int	ft_print_integer(long n);
int	ft_print_unsigned_decimal(unsigned int n);
int	ft_print_hexadecimal_uppercase(unsigned int n);
int	ft_print_hexadecimal_lowercase(unsigned int n);
int	ft_print_percent(void);
int	set_format(va_list args, char c);
int	ft_printf(const char *str, ...);


#endif
