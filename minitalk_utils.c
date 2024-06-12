/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:06:32 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 16:48:06 by bmagere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	stock;
	int		i;

	i = 0;
	stock = 0;
	sign = 1;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		stock = stock * 10 + (nptr[i] - '0');
		if (!(-2147483648 <= (stock * sign) && (stock * sign) <= 2147483647))
			return (0);
		i++;
	}
	return (stock * sign);
}

static int	ft_strlen(const char *s)
{
	static int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	char	*tab;
	int		i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		exit (1);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		lens1;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	lens1 = ft_strlen(s1);
	i = -1;
	tab = malloc(sizeof(char) * (lens1 + 1) + 1);
	if (!tab)
	{
		free(s1);
		exit(1);
	}
	while (lens1 > ++i)
		tab[i] = s1[i];
	tab[i] = s2[0];
	tab[++i] = '\0';
	free(s1);
	return (tab);
}
