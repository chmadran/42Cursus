/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.ft_close_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:44:51 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:19 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_error(char *str, t_map *map)
{
	ft_putstr_fd(str, 1);
	if (map->filled == 1)
	{
		ft_delete_map(map);
		free_copydata(map);
	}
	free(map);
	exit (EXIT_FAILURE);
}

int	ft_victory(t_map *map)
{
	ft_putstr_fd("\nVICTORY IN ", 1);
	ft_putnbr_fd(map->nbmoves, 1);
	if (map->nbmoves == 1)
		ft_putstr_fd(" MOVE !\n", 1);
	else
		ft_putstr_fd(" MOVES !\n", 1);
	ft_free_map(map);
	exit (EXIT_FAILURE);
}

int	ft_close(t_map *map)
{
	ft_putstr_fd("\nGAME CLOSED MANUALLY\n", 1);
	ft_free_map(map);
	exit (EXIT_FAILURE);
}
