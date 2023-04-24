/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:38:33 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:33:13 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(char *str)
{
	long	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && res < 2147483649)
		res = res * 10 + str[i++] - '0';
	if (res * sign == 0)
		error("There is a 0 in the arguments.\n");
	if ((res * sign > INT_MAX) || (res * sign < INT_MIN))
		error("Number is too small or too big, please amend\n");
	return (res * sign);
}

static void	verif_data(t_data *data)
{
	if (data->nbphilo > 200)
		error("There are too many philosophers.");
	if (data->time_die < 60)
		error("Time to die must be increased.");
	if (data->time_eat < 60)
		error("Time to eat must be increased.");
	if (data->time_sleep < 60)
		error("Time to sleep must be increased.");
	if (data->nb_musteat == 0)
		error("Philosophers cant eat, increase the argument.");
}

void	init_data(t_data *data, char **av)
{
	data->nbphilo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_musteat = ft_atoi(av[5]);
	else
		data->nb_musteat = -1;
	verif_data(data);
}
