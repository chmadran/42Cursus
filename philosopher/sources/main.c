/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:10:16 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:33:26 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	get_time(void)
{
	struct timeval	time;
	size_t			ms;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 5 || ac > 6)
		error("Wrong number of arguments.\n");
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				error("Error in the input, there is an invalid character.\n");
			j++;
		}
	i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	check_arg(ac, av);
	memset(&data, 0, sizeof(data));
	init_data(&data, av);
	if (init_mutex(&data))
	{
		destroy_mutex(&data);
		error("Error at mutex initialisation");
	}
	if (init_philo(&data))
	{
		destroy_mutex(&data);
		error("Error at philo initialisation");
	}
	init_thread(&data, data.philo);
	destroy_mutex(&data);
	free(data.philo);
	return (0);
}
