/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.ft_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:03:23 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:10 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_create_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->nbmoves = map->nbmoves + 1;
	if (map->nbmoves >= 1)
	{
		ft_putnbr_fd(map->nbmoves, 1);
		ft_putstr_fd(" total player movements !\n", 1);
	}
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			ft_check_sprite(map, i, j);
			j++;
		}
		i++;
	}
}

void	ft_check_sprite(t_map *map, int row, int column)
{
	char	data;

	data = map->data[row][column];
	if (data == '1')
		ft_render_sprite(map, map->wall_img, row, column);
	else if (data == '0')
		ft_render_sprite(map, map->floor_img, row, column);
	else if (data == 'C')
		ft_render_sprite(map, map->collectible_img, row, column);
	else if (data == 'E')
		ft_render_sprite(map, map->exit_img, row, column);
	else if (data == 'P')
		ft_render_sprite(map, map->player_img, row, column);
}

void	ft_render_sprite(t_map *map, t_image sprite, int row, int column)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, sprite.xpm_ptr,
		column * sprite.x, row * sprite.y);
}
