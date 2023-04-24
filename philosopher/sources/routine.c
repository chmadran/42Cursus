/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:30:36 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:33:30 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	to_print(t_philo *philo, t_data *data, char *str)
{
	pthread_mutex_lock(&data->printing);
	pthread_mutex_lock(&data->dead);
	if (data->death == 0 && data->all_ate == 0)
	{
		printf("%ld ", get_time() - data->time_started);
		printf(" %d ", philo->id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&data->dead);
	pthread_mutex_unlock(&data->printing);
}

static void	to_sleep(t_philo *philo, t_data *data)
{
	size_t	start_sleep;

	start_sleep = get_time();
	to_print(philo, data, "is sleeping");
	while (1)
	{
		pthread_mutex_lock(&data->dead);
		if (data->death || data->all_ate)
		{
			pthread_mutex_unlock(&data->dead);
			break ;
		}
		pthread_mutex_unlock(&data->dead);
		if (get_time() - start_sleep >= data->time_sleep)
			break ;
		usleep(1000);
	}
}

static void	to_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->nb_meals);
	to_print(philo, data, "is eating");
	philo->time_lastmeal = get_time();
	pthread_mutex_unlock(&data->nb_meals);
	while (1)
	{
		pthread_mutex_lock(&data->dead);
		if (data->death || data->all_ate)
		{
			pthread_mutex_unlock(&data->dead);
			break ;
		}
		pthread_mutex_unlock(&data->dead);
		if (get_time() - philo->time_lastmeal >= data->time_eat)
			break ;
		usleep(1000);
	}
	pthread_mutex_lock(&data->nb_meals);
	philo->nbmeals++;
	pthread_mutex_unlock(&data->nb_meals);
}

static int	to_grab_forks(t_philo *philo, t_data *data)
{
	if (philo->id % 2)
		pthread_mutex_lock(&data->forks[philo->left_fork]);
	else
		pthread_mutex_lock(&data->forks[philo->right_fork]);
	to_print(philo, data, "has taken a fork");
	if (data->nbphilo < 2)
	{
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		return (1);
	}
	if (philo->id % 2)
		pthread_mutex_lock(&data->forks[philo->right_fork]);
	else
		pthread_mutex_lock(&data->forks[philo->left_fork]);
	to_print(philo, data, "has taken a fork");
	to_eat(philo, data);
	if (philo->id % 2)
		(pthread_mutex_unlock(&data->forks[philo->left_fork]),
			pthread_mutex_unlock(&data->forks[philo->right_fork]));
	else
		(pthread_mutex_unlock(&data->forks[philo->right_fork]),
			pthread_mutex_unlock(&data->forks[philo->left_fork]));
	return (0);
}

void	*routine(void *p)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->id % 2)
		usleep(10000);
	while (1)
	{
		if (to_grab_forks(philo, data))
			break ;
		to_sleep(philo, data);
		to_print(philo, data, "is thinking");
		pthread_mutex_lock(&data->dead);
		if (data->death || data->all_ate)
		{
			pthread_mutex_unlock(&data->dead);
			break ;
		}
		pthread_mutex_unlock(&data->dead);
		usleep(100);
	}
	return (NULL);
}
