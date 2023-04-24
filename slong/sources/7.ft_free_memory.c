/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.ft_free_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:37:03 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:23 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	free_mapdata(char **mapdata)
{
	int		i;

	i = 0;
	while (mapdata[i])
	{
		free(mapdata[i]);
		i++;
	}
	free(mapdata);
}

void	ft_delete_images(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->wall_img.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->floor_img.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->collectible_img.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->exit_img.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->player_img.xpm_ptr);
}

void	ft_delete_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	ft_delete_images(map);
	ft_delete_map(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	free(map);
}

void	free_copydata(t_map *map)
{
	int	i;

	i = 0;
	while (map->c_data[i])
	{
		free(map->c_data[i]);
		i++;
	}
	free(map->c_data);
}
