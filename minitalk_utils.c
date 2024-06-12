/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:06:32 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 12:28:24 by bmagere          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_new_s;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len_new_s = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(sizeof(char) * (len_new_s + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < len_new_s)
	{
		while (s1[i])
			new_s[k++] = s1[i++];
		while (s2[j])
			new_s[k++] = s2[j++];
	}
	new_s[k] = '\0';
	return (new_s);
}

