/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:18:27 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:30:13 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handle_signal(int sig, siginfo_t *info, void *str)
{
	static int	bit;
	static int	i;

	(void)str;
	(void)info;
	if (sig == SIGUSR2)
		i = i | (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		kill(info->si_pid, SIGUSR1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Voici le PID de server.c : ", 27);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		continue ;
	}
}
