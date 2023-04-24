/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:17:10 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/05 16:12:44 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				nbmeals;
	int				right_fork;
	int				left_fork;
	size_t			time_lastmeal;
	pthread_t		thread;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nbphilo;
	int				death;
	int				all_ate;
	int				nb_musteat;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			time_started;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	pthread_mutex_t	nb_meals;
	pthread_mutex_t	dead;
	t_philo			*philo;
}				t_data;

//-----MAIN
void	check_arg(int ac, char **av);
void	init_data(t_data *data, char **av);
void	destroy_mutex(t_data *data);
int		init_mutex(t_data *data);
int		init_philo(t_data *data);
int		init_thread(t_data *data, t_philo *philo);
int		destroy_thread(t_data *data);

//----ROUTINE
void	to_print(t_philo *philo, t_data *data, char *str);
void	*routine(void *p);

//----UTILS
size_t	get_time(void);
void	ft_putstr(char *str);
void	error(char *str);

#endif 
