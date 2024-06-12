/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:55:12 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 12:31:33 by bmagere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_signal(int signal, siginfo_t *sig, void *content)
{
	static int	i;
	static char c;
	static char *str = NULL;

	i = 0;
	c = 0;
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
	kill(sig->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("The term's PID is %d\n", pid);
	sig.sa_sigaction = write_signal;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		usleep(300);
	return (0);
}
