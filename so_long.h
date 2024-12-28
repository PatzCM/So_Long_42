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
# define WIN_TITLE "so_long"
# define SIZE 64
# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		tile_size;
}				t_data;

typedef struct s_map
{
	char	**mtx;
	char	**matrix;
	char	*line;
	int		fd;
	int		row;
	int		column;
	int		row_end;
	int		column_end;
	int		height;
	int		width;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;
}	t_player;

typedef struct s_game
{
	t_player	player_p;
	void		*mlx;
	void		*window;
	void		*image;
	int			collectibles;
	int			exit;
	int			player;
	void		*player_img;
	void		*collectible_img;
	void		*exit_img;
	void		*wall;
	void		*floor;
	void		*corner_top_left;
	void		*corner_top_right;
	void		*corner_bottom_left;
	void		*corner_bottom_right;
	void		*middle_top;
	void		*middle_bottom;
	void		*floor_dec;
	void		*i_exit;
	int			moves;
	t_data		data;
	t_map		map;
}	t_game;

// Initialization & Memory
t_player	*player_alloc(char **mtx);
void		free_stacks(t_game *game);
void		destroy_image(t_game *game);
void		free_map(t_game *game);
void		exit_game(t_game *game, int status);
// Parsing Map

void		map_validation(char *file, t_game *game);
int			validate_ber(char *file);
char		**matrix(char *file);
void		validate_shape(char **matrix, t_game *game);
int			size_row(char **matrix);
int			size_column(char **matrix);
int			number_of_elements(char **matrix, int collectibles, t_game *game);
int			size_row(char **matrix);
int			size_column(char **matrix);
t_game		*limits(t_game *game);

// Pathing

void		player_position(char **matrix, t_player *player);
void		flood_fill(char **matrix,	int x, int y, t_map *limit);
int			confirm_flood(char **matrix, t_map *limit);
void		error_validation(char **matrix, t_player *player, t_game *game);

// Movement

void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			move(t_game *game, int to_x, int to_y);
// Defines
// # define MAP_PATH "maps/map.ber"
//
// Window
void		init_values(t_game *game);
void		window_init(t_game *game);

// Images
t_game		*data_init(t_game *game);

void		render_map(t_game *game);
void		pixel_put(t_game *game, int x, int y, int color);
void		image_render(t_game *game);
void		render_map2(t_game *game, int row, int column);

// Keys

int			key_code(int keycode, t_game *game);

# define KEY_ESC 65307 
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_SPACE 32
# define KEY_ENTER 65293
# define KEY_SHIFT 65505
# define KEY_CTRL 65507
//
//	// Errors
//	# define ERR_MAP "Error\nInvalid map"
//	# define ERR_MAP_OPEN "Error\nCould not open map"
//	# define ERR_MAP_READ "Error\nCould not read map"
//	# define ERR_MAP_CLOSE "Error\nCould not close map"
//

#endif
