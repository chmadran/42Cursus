/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:54:16 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:33:17 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;
	int	nbphilo;

	i = 0;
	nbphilo = data->nbphilo;
	while (i < nbphilo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->printing);
	pthread_mutex_destroy(&data->nb_meals);
	pthread_mutex_destroy(&data->dead);
	free(data->forks);
}

int	init_mutex(t_data *data)
{
	int	i;
	int	nbphilo;

	i = 0;
	nbphilo = data->nbphilo;
	if (pthread_mutex_init(&data->printing, NULL))
		return (1);
	if (pthread_mutex_init(&data->nb_meals, NULL))
		return (1);
	if (pthread_mutex_init(&data->dead, NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * nbphilo);
	if (!data->forks)
		return (1);
	while (i < nbphilo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
