/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:37:48 by chmadran          #+#    #+#             */
/*   Updated: 2023/02/12 10:18:10 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define BUFFER_SIZE 10
# define IMG_SIZE 32

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WALL "sprites/wall.xpm"
# define FLOOR "sprites/floor.xpm"
# define COLLECTIBLE "sprites/collectible.xpm"
# define EXIT "sprites/exit.xpm"
# define PLAYER "sprites/player.xpm"

typedef struct image_s
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct map_s
{
	char	**data;
	char	**c_data;
	void	*mlx_ptr;
	void	*win_ptr;
	int		rows;
	int		columns;
	int		collectible;
	int		exit;
	int		player;
	int		error;
	int		player_row;
	int		player_column;
	int		filled;
	int		nbmoves;
	int		collected;
	int		**coin;
	t_image	wall_img;
	t_image	floor_img;
	t_image	collectible_img;
	t_image	exit_img;
	t_image	player_img;
}	t_map;

//--------------------In main----------------------------------------------

t_map	*ft_initialise(void);
void	ft_check_arg(int ac, char **av, t_map *map);
char	*ft_read(char *buf, int fd);

//--------------------In check map-----------------------------------------

void	ft_check_walls(t_map *map, int x, int y);
void	ft_check_surroundingwalls(t_map *map);
void	ft_check_toobig(t_map *map);
void	ft_unauthorized_item(char c, t_map *map);
void	ft_missing_item(t_map *map);
t_map	*ft_check_map_size(int fd, t_map *map);
t_map	*ft_fill_map(t_map *map, char c);
t_map	*ft_intialise_rows_columns(t_map *map);
t_map	*ft_check_map(t_map *map, int fd);

//--------------------In init map-----------------------------------------

void	ft_copy_mapdata(t_map *map, char *onelign);
void	ft_initialise_mlx(t_map *map);
void	ft_initialise_sprites(t_map *map);
t_image	ft_new_sprite(void *mlx, char *path, t_map *map);

//--------------------In render map---------------------------------------

void	ft_create_map(t_map *map);
void	ft_check_sprite(t_map *map, int row, int column);
void	ft_render_sprite(t_map *map, t_image sprite, int row, int column);

//--------------------In move player--------------------------------------

void	ft_fill_player_position(t_map *map);
void	ft_move_player(t_map *map, int new_row, int new_column);
int		ft_move(int keysymbol, t_map *map);

//--------------------In close map----------------------------------------

int		ft_error(char *str, t_map *map);
int		ft_victory(t_map *map);
int		ft_close(t_map *map);
void	ft_delete_images(t_map *map);
void	ft_delete_map(t_map *map);
void	ft_free_map(t_map *map);

//--------------------In utils--------------------------------------------

int		ft_my_strchr(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *buff, char *temp_buf);

void	free_mapdata(char **mapdata);
void	flood_map(t_map *map, int row, int column);
void	ft_check_working_map(t_map *map);
void	free_copydata(t_map *map);

#endif