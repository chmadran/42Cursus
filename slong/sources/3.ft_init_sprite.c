/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.ft_init_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:38:17 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:05 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_initialise_mlx(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		ft_error("Error\nMLX_PTR ERROR.\n", map);
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			map->columns * IMG_SIZE, map->rows * IMG_SIZE, "so_long");
	if (map->win_ptr == NULL)
		ft_error("Error\nWIN_PTR ERROR.\n", map);
}

void	ft_initialise_sprites(t_map *map)
{
	void	*mlx;

	mlx = map->mlx_ptr;
	map->wall_img = ft_new_sprite(mlx, WALL, map);
	map->floor_img = ft_new_sprite(mlx, FLOOR, map);
	map->collectible_img = ft_new_sprite(mlx, COLLECTIBLE, map);
	map->exit_img = ft_new_sprite(mlx, EXIT, map);
	map->player_img = ft_new_sprite(mlx, PLAYER, map);
}

t_image	ft_new_sprite(void *mlx, char *path, t_map *map)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error("Error\nXPM_PTR ERROR.\n", map);
	return (sprite);
}
