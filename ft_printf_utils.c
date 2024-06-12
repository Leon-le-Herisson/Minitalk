/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:18:28 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 12:32:07 by bmagere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_p(size_t arg, int i)
{
	char	*hexabase;
	int		length;

	hexabase = "0123456789abcdef";
	length = 0;
	if (!arg)
	{
		write(1, "(nil)", 5);
		i += 5;
		return (i);
	}
	if (arg >= 16)
		length += print_p(arg / 16, i);
	if (length == 0)
		length += write(1, "0x", 2);
	i = print_char(hexabase[arg % 16], i);
	i += length;
	return (i);
}

int	print_nb_base_x(size_t arg, int i)
{
	unsigned int	j;

	j = (unsigned int)arg;
	if (j == 0)
	{
		i = print_char('0', i);
		return (i);
	}
	if (j >= 16)
	{
		i = print_nb_base_x(j / 16, i);
		i = print_nb_base_x(j % 16, i);
	}
	else
	{
		if (j <= 9)
			i = print_char(j + '0', i);
		else
			i = print_char(j + 'a' - 10, i);
	}
	return (i);
}

int	print_nb_base_bigx(size_t arg, int i)
{
	unsigned int	j;

	j = (unsigned int)arg;
	if (j == 0)
	{
		i = print_char('0', i);
		return (i);
	}
	if (j >= 16)
	{
		i = print_nb_base_bigx(j / 16, i);
		i = print_nb_base_bigx(j % 16, i);
	}
	else
	{
		if (j <= 9)
			i = print_char(j + '0', i);
		else
			i = print_char(j + 'A' - 10, i);
	}
	return (i);
}

int	print_nb_u(unsigned int arg, int i)
{
	if (arg == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (0 < arg && arg <= 9)
		i = print_char((arg + '0'), i);
	if (arg > 9)
	{
		i = print_nb_u(arg / 10, i);
		i = print_char(((arg % 10) + '0'), i);
	}
	return (i);
}
