/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initphilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:06:40 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:33:22 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_nbmeals(t_data *data, t_philo *philo)
{
	int	i;
	int	nbphilo;

	i = 0;
	nbphilo = data->nbphilo;
	pthread_mutex_lock(&data->nb_meals);
	while (i < nbphilo)
	{
		if (philo[i].nbmeals < data->nb_musteat)
		{
			pthread_mutex_unlock(&data->nb_meals);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->nb_meals);
	pthread_mutex_lock(&data->dead);
	data->all_ate = 1;
	pthread_mutex_unlock(&data->dead);
}

void	check_death(t_data *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&data->dead);
		if (data->death || data->all_ate)
		{
			pthread_mutex_unlock(&data->dead);
			break ;
		}
		pthread_mutex_unlock(&data->dead);
		if (data->nb_musteat > 0)
			check_nbmeals(data, philo);
		i = -1;
		while (++i < data->nbphilo)
		{
			pthread_mutex_lock(&data->nb_meals);
			if (get_time() - philo[i].time_lastmeal > data->time_die)
				(to_print(philo, data, "is dead"),
					pthread_mutex_lock(&data->dead), data->death = 1,
					pthread_mutex_unlock(&data->dead));
			pthread_mutex_unlock(&data->nb_meals);
		}
		usleep(100);
	}
}

int	destroy_thread(t_data *data)
{
	int	i;
	int	nbphilo;

	i = 0;
	nbphilo = data->nbphilo;
	while (i < nbphilo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_thread(t_data *data, t_philo *philo)
{
	int		i;
	int		nbphilo;

	i = 0;
	data->time_started = get_time();
	nbphilo = data->nbphilo;
	while (i < nbphilo)
	{
		philo[i].time_lastmeal = data->time_started;
		if (pthread_create(&philo[i].thread, NULL, routine, (void *)&(philo[i])))
			return (1);
		i++;
	}
	check_death(data, data->philo);
	destroy_thread(data);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;
	int	nbphilo;

	i = 0;
	nbphilo = data->nbphilo;
	data->philo = malloc(sizeof(t_philo) * nbphilo);
	if (!data->philo)
		return (1);
	while (i < nbphilo)
	{
		data->philo[i].id = i;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % nbphilo;
		data->philo[i].nbmeals = 0;
		data->philo[i].time_lastmeal = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}
