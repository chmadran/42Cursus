/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:44:02 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:55:45 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

t_map	*ft_initialise(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->data = NULL;
	map->c_data = NULL;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
	map->exit = 0;
	map->rows = 0;
	map->columns = 0;
	map->player_row = 0;
	map->player_column = 0;
	map->filled = 0;
	map->nbmoves = -1;
	map->collected = 0;
	return (map);
}

char	*ft_read(char *buf, int fd)
{
	char	*temp_buf;
	int		nbytes_read;

	if (!buf)
		buf = ft_calloc(1, 1);
	temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbytes_read = 1;
	while (nbytes_read > 0)
	{
		nbytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (nbytes_read == -1)
		{
			free(temp_buf);
			free(buf);
			return (NULL);
		}
		temp_buf[nbytes_read] = '\0';
		buf = ft_strcat(buf, temp_buf);
	}
	free(temp_buf);
	return (buf);
}

void	ft_check_arg(int ac, char **av, t_map *map)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		ft_error("Error\nYou need to add a map to your arguments.\n", map);
	else if (fd <= 0)
		ft_error("Error\nFile cannot be read.", map);
	else if (ft_my_strchr(av[1], ".ber") == 0)
		ft_error("Error\nIncorrect map extension, must be .ber.\n", map);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	fd = open(av[1], O_RDONLY);
	map = ft_initialise();
	ft_check_arg(ac, av, map);
	map = ft_check_map(map, fd);
	ft_initialise_mlx(map);
	ft_initialise_sprites(map);
	ft_create_map(map);
	mlx_hook(map->win_ptr, KeyPress, KeyPressMask, ft_move, map);
	mlx_hook(map->win_ptr, DestroyNotify, ButtonPressMask, ft_close, map);
	mlx_loop(map->mlx_ptr);
	ft_free_map(map);
}
