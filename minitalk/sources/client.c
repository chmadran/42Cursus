/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:52:28 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:30:05 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_reception(int signal)
{
	static int	count;

	if (signal == SIGUSR1)
		count++;
	else
	{
		ft_putnbr(count);
		write(1, " message received\n", 18);
	}
}

void	ft_encoding(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3 && av[2][0] && av[1][0] != '-')
	{
		pid = atoi(av[1]);
		while (av[2][i])
		{
			signal(SIGUSR1, ft_reception);
			signal(SIGUSR2, ft_reception);
			ft_encoding(av[2][i], pid);
			i++;
		}
		ft_encoding('\n', pid);
		ft_reception(SIGUSR2);
	}
	else
	{
		write(1, "there is an error in your arguments ", 36);
		write(1, "or the string is empty, please retry\n", 37);
		return (0);
	}
}
