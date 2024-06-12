/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:57:17 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 12:27:58 by bmagere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_flag = 0;

static void	signal_handler(int pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		g_flag = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_flag != 1)
			pause();
	}
}

static void	waiting_signal(int signal)
{
	(void)signal;
	g_flag = 1;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3 || argv[2][0] == '\0')
	{
		ft_printf("Error : Issue with arguments");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0))
	{
		ft_printf("Error : Invalid PID");
		return (1);
	}
	signal(SIGUSR1, waiting_signal);
	while (argv[2][i])
	{
		signal_handler(pid, argv[2][i]);
		i++;
	}
	signal_handler(pid, '\n');
	signal_handler(pid, '\0');
	return (0);
}
