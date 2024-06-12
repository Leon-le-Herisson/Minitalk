/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:06:32 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 17:09:15 by bmagere          ###   ########.fr       */
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
	char	*new_s;
	int		i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	new_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_s)
		exit (1);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		size;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1);
	i = -1;
	new_s = malloc(sizeof(char) * (size + 1) + 1);
	if (!new_s)
	{
		free(s1);
		exit(1);
	}
	while (size > ++i)
		new_s[i] = s1[i];
	new_s[i] = s2[0];
	i++;
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}
