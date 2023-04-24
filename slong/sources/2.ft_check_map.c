/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.ft_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:20:21 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:55:58 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_check_toobig(t_map *map)
{
	if ((map->columns > 80) || (map->rows > 43))
		ft_error("Error\nMap is too big to be rendered correctly.\n", map);
}

t_map	*ft_check_map_size(int fd, t_map *map)
{
	size_t		lignlen;
	char		**mapdata;
	char		*onelign;
	int			i;

	i = 0;
	onelign = calloc(1, 1);
	onelign = ft_read(onelign, fd);
	mapdata = ft_split(onelign, '\n');
	ft_copy_mapdata(map, onelign);
	lignlen = ft_strlen(mapdata[0]);
	free(onelign);
	while (mapdata[i])
	{
		if (ft_strlen(mapdata[i]) != lignlen)
		{
			free_mapdata(mapdata);
			free_copydata(map);
			ft_error("Error\nMap is not a rectangle\n", map);
		}
		i++;
	}
	map->data = mapdata;
	map->filled = 1;
	return (map);
}

void	flood_map(t_map *map, int row, int column)
{
	char	**mapdata;
	int		i;
	int		j;

	i = row;
	j = column;
	mapdata = map->c_data;
	if (i > map->rows - 1 || j > map->columns - 1 || j < 0 || i < 0)
		return ;
	if (mapdata[i][j] == '1' || mapdata[i][j] == '2')
		return ;
	if (mapdata[i][j] == 'C')
			map->collected += 1;
	mapdata[i][j] = '2';
	flood_map(map, i + 1, j);
	flood_map(map, i, j + 1);
	flood_map(map, i - 1, j);
	flood_map(map, i, j - 1);
}

void	ft_check_working_map(t_map *map)
{
	int		i;
	int		j;
	int		collected;

	ft_fill_player_position(map);
	i = map->player_row;
	j = map->player_column;
	flood_map(map, i, j);
	collected = map->collected;
	if (collected != map->collectible)
		ft_error("Error\nMap cannot be completed\n", map);
}

t_map	*ft_check_map(t_map *map, int fd)
{
	char	**mapdata;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_check_map_size(fd, map);
	map = ft_intialise_rows_columns(map);
	mapdata = map->data;
	while (mapdata[i])
	{
		j = 0;
		while (mapdata[i][j])
		{
			ft_unauthorized_item(mapdata[i][j], map);
			map = ft_fill_map(map, mapdata[i][j]);
			j++;
		}
		i++;
	}
	ft_missing_item(map);
	free_copydata(map);
	return (map);
}
