/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:56:33 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 12:32:01 by bmagere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_char(int arg, int i)
{
	write(1, &arg, 1);
	i++;
	return (i);
}

int	print_nb(int arg, int i)
{
	if (arg == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (i + 11);
	}
	if (arg == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (arg < 0)
	{
		i = print_char('-', i);
		i = print_nb((-1 * arg), i);
	}
	if (0 <= arg && arg <= 9)
		i = print_char((arg + '0'), i);
	if (arg > 9)
	{
		i = print_nb(arg / 10, i);
		i = print_char(((arg % 10) + '0'), i);
	}
	return (i);
}

static int	print_str(char *arg, int i)
{
	int	j;

	j = 0;
	if (!arg)
		i = print_str("(null)", i);
	else
	{
		while (arg[j])
		{
			write(1, &(arg[j]), 1);
			j++;
			i++;
		}
	}
	return (i);
}

static int	print_analyser(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += print_char(va_arg(args, int), i);
	if (c == 's')
		i += print_str(va_arg(args, char *), i);
	if (c == 'p')
		i += print_p(va_arg(args, size_t), i);
	if (c == 'd' || c == 'i')
		i += print_nb(va_arg(args, int), i);
	if (c == 'X')
		i += print_nb_base_bigx(va_arg(args, size_t), i);
	if (c == 'x')
		i += print_nb_base_x(va_arg(args, size_t), i);
	if (c == 'u')
		i += print_nb_u(va_arg(args, unsigned int), i);
	if (c == '%')
		i += print_char('%', i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += print_analyser(format[++i], args);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
