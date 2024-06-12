/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:55:12 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 16:48:27 by bmagere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_signal(int signal, siginfo_t *signals, void *content)
{
	static int	i = 0;
	static char	c = 0;
	static char	*str = NULL;

	(void)content;
	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		str = ft_strjoin(str, &c);
		i = -1;
		if (c == '\0')
		{
			while (str[++i])
				write(1, &str[i], 1);
			free(str);
			str = NULL;
		}
		i = 0;
		c = 0;
	}
	kill(signals->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	signals;

	signals.sa_sigaction = write_signal;
	signals.sa_flags = SA_SIGINFO;
	sigemptyset(&signals.sa_mask);
	pid = getpid();
	ft_printf("The term's PID is %d\n", pid);
	sigaction(SIGUSR1, &signals, NULL);
	sigaction(SIGUSR2, &signals, NULL);
	while (1)
		pause();
	return (0);
}
