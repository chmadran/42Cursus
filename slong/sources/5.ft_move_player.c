/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.ft_move_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:34:39 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:14 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_fill_player_position(t_map *map)
{
	char	**mapdata;
	int		current_row;
	int		current_column;

	mapdata = map->data;
	current_row = 0;
	while (mapdata[current_row])
	{
		current_column = 0;
		while (mapdata[current_row][current_column])
		{
			if (mapdata[current_row][current_column] == 'P')
			{
				map->player_row = current_row;
				map->player_column = current_column;
				break ;
			}
			current_column++;
		}
		current_row++;
	}
}

void	ft_move_player(t_map *map, int new_row, int new_column)
{
	int	current_row;
	int	current_column;

	current_row = map->player_row;
	current_column = map->player_column;
	if ((map->data[new_row][new_column] == 'E') && (map->collectible == 0))
		ft_victory(map);
	else if ((map->data[new_row][new_column] == '0') ||
			(map->data[new_row][new_column] == 'C'))
	{
		if (map->data[new_row][new_column] == 'C')
			map->collectible = map->collectible - 1;
		map->data[current_row][current_column] = '0';
		map->player_row = new_row;
		map->player_column = new_column;
		map->data[new_row][new_column] = 'P';
		ft_create_map(map);
	}
}

int	ft_move(int keysymbol, t_map *map)
{
	ft_fill_player_position(map);
	if (keysymbol == XK_w)
		ft_move_player(map, map->player_row - 1, map->player_column);
	if (keysymbol == XK_s)
		ft_move_player(map, map->player_row + 1, map->player_column);
	if (keysymbol == XK_a)
		ft_move_player(map, map->player_row, map->player_column - 1);
	if (keysymbol == XK_d)
		ft_move_player(map, map->player_row, map->player_column + 1);
	if (keysymbol == XK_Escape)
		ft_close(map);
	return (0);
}
