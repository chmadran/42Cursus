/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.ft_check_map_items.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:40:09 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:55:50 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_check_walls(t_map *map, int x, int y)
{
	while (x >= 0)
	{
		if (map->data[x][y] == '0')
			ft_error("Error\nMissing wall on the right side of the map.\n", map);
		x--;
	}
	x++;
	while (y >= 0)
	{
		if (map->data[x][y] == '0')
			ft_error("Error\nMissing wall at the top of the map.\n", map);
		y--;
	}
}

void	ft_check_surroundingwalls(t_map *map)
{
	char	**mapdata;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mapdata = map->data;
	while (mapdata[x])
	{
		if (mapdata[x][0] == '0')
			ft_error("Error\nMissing wall on the left side of the map.\n", map);
		x++;
	}
	x--;
	while (mapdata[x][y])
	{
		if (mapdata[x][y] == '0')
			ft_error("Error\nMissing wall on the bottom of the map.\n", map);
		y++;
	}
	y--;
	ft_check_walls(map, x, y);
}

void	ft_unauthorized_item(char c, t_map *map)
{
	if ((c != '0') && (c != '1') && (c != 'C') && (c != 'P') && (c != 'E'))
		ft_error("Error\nUnauthorized item found, rework the map.\n", map);
}

void	ft_missing_item(t_map *map)
{
	if (map->collectible <= 0)
		ft_error("Error\nThere must be at least one collectible.\n", map);
	else if (map->exit != 1)
	{
		ft_error("Error\nNot the right amount of exits.\n", map);
	}
	else if (map->player != 1)
	{
		ft_error("Error\nNot the right amount of players\n", map);
	}
	ft_check_toobig(map);
	ft_check_surroundingwalls(map);
	ft_check_working_map(map);
}
