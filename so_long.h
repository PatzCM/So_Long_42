/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:59:21 by palexand          #+#    #+#             */
/*   Updated: 2024/12/10 18:04:18 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries 
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "mlx/mlx.h"
# include "libs/ft_printf.h"
# include "libs/get_next_line_bonus.h"
# include "libs/libft.h"
# include <strings.h>
# include <fcntl.h>

typedef	struct s_game
{
	void	*mlx;
	void	*window;
	int		collectibles;
	int		exit;
	int		player;
}	t_game;

typedef struct s_matrix
{
	char	**matrix;
	char	*line;
	int		fd;
}	t_matrix;

typedef struct s_map
{
	int		row;
	int		column;
	int		row_end;
	int		column_end;

}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

// Parsing Map
//	int		read_map(t_game *game, char *path);
//	int		check_map(t_game *game);
//	int		check_surroundings(t_game *game, int x, int y);

void	map_validation(char *file);
int		validate_ber(char *file);
char	**matrix(char *file);
void	validate_shape(char **matrix);
int		size_row(char **matrix);
int		size_column(char **matrix);
int		number_of_elements(char **matrix, int collectibles);
int		size_row(char **matrix);
int		size_column(char **matrix);

// Pathing

void	player_position(char **matrix, t_player *player);
void	flood_fill(char **matrix,	int x, int y, t_player *player);
int	confirm_flood(char **matrix, t_player *player);
t_player	*player_alloc(char **mtx);
void	error_validation(char **matrix, t_game *collectibles, t_player *player);
// Defines
// # define MAP_PATH "maps/map.ber"
//
// Window
// # define WIN_WIDTH 800
// # define WIN_HEIGHT 600
// # define WIN_TITLE "so_long"
//
// Images
// # define IMG_PATH "images/so_long.xpm"
// # define IMG_SIZE 32
// # define IMG_PLAYER "images/player.xpm"
// # define IMG_PLAYER_SIZE 32
// # define IMG_WALL "images/wall.xpm"
// # define IMG_WALL_SIZE 32
//
// Keys
// # define KEY_ESC 53
// # define KEY_W 13
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define KEY_UP 126
//	# define KEY_DOWN 125
//	# define KEY_LEFT 123
//	# define KEY_RIGHT 124
//	# define KEY_SPACE 49
//	# define KEY_ENTER 36
//	# define KEY_SHIFT 257
//	# define KEY_CTRL 256
//
//	// Errors
//	# define ERR_MAP "Error\nInvalid map"
//	# define ERR_MAP_OPEN "Error\nCould not open map"
//	# define ERR_MAP_READ "Error\nCould not read map"
//	# define ERR_MAP_CLOSE "Error\nCould not close map"
//
//	// Structures
//	typedef struct s_map
//	{
//	char	**map;
//	int		width;
//	int		height;
//	}	t_map;
//	typedef struct s_img
//	{
//
//	void	*img;
//	char	*addr;
//	int		bpp;
//	int		line_len;
//	int		endian;
//	int		width;
//	int		height;
//	}	t_img;
//	typedef struct s_game
//	{
//	void	*mlx;
//	void	*win;
//	t_img	img;
//	t_img	player;
//	t_img	wall;
//	t_map	map;
//	int		player_x;
//	int		player_y;
//	int		moves;
//	int		collectibles;
//	int		collectibles_left;
//	int		exits;
//	int		exits_left;
//	int		running;
//	}	t_game;
//
//	// Prototypes
//	int		init_game(t_game *game);
//	int		init_map(t_game *game, char *path);
//	int		init_images(t_game *game);
//	int		init_player(t_game *game);
//	int		init_wall(t_game *game);
//	int		render(t_game *game);
//	int		key_press(int keycode, t_game *game);
//	int		key_release(int keycode, t_game *game);
//	int		close_game(t_game *game);
//	int		exit_game(t_game *game);
//	int		move_player(t_game *game, int x, int y);
//	int		check_move(t_game *game, int x, int y);
//	int		check_collectible(t_game *game, int x, int y);
//	int		check_exit(t_game *game, int x, int y);
//
//
//
//	// Utils
//	void	free_map(t_map *map);
//	void	free_img(t_img *img);
//
//	// Debug
//
//
//
//
#endif
