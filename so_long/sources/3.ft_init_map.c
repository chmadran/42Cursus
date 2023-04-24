/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.ft_init_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:18:58 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:02 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_copy_mapdata(t_map *map, char *onelign)
{
	char		**c_mapdata;
	char		*c_onelign;

	c_onelign = malloc(ft_strlen(onelign) + 1);
	ft_strlcpy(c_onelign, onelign, ft_strlen(onelign) + 1);
	c_mapdata = ft_split(c_onelign, '\n');
	map->c_data = c_mapdata;
	free(c_onelign);
}

t_map	*ft_intialise_rows_columns(t_map *map)
{
	int		i;
	int		j;
	char	**mapdata;

	i = 0;
	j = 0;
	mapdata = map->data;
	while (mapdata[i])
	{
		j = 0;
		while (mapdata[i][j])
		{
			if (i == 0)
				map->columns = map->columns + 1;
			j++;
		}
		map->rows = map->rows + 1;
		i++;
	}
	return (map);
}

t_map	*ft_fill_map(t_map *map, char c)
{
	if (c == 'C')
		map->collectible = map->collectible + 1;
	if (c == 'E')
		map->exit = map->exit + 1;
	if (c == 'P')
		map->player = map->player + 1;
	return (map);
}
