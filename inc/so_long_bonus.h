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
# define FRONT 0
# define BACK 1
# define LEFT 2
# define RIGHT 3
// Libraries 
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <strings.h>
# include <fcntl.h>

typedef struct s_data
{
	int		len;
	int		tile_size;
	int		loop;
	int		enemies;
}				t_data;

typedef struct s_iter
{
	int		x;
	int		y;
}				t_iter;

t_iter it_s(int y, int x);

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
	int		*enemy_x;
	int		*enemy_y;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;
}	t_player;

typedef struct s_img
{
	void	*xpm;
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
	int		h;
	int		w;
}	t_img;

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
	void		*exit_img;
	void		*wall;
	void		*floor;
	void		*floor_dec;
	void		*i_exit;
	void		*enemy;
	char		**nbr;
	int			player_sprite;
	int			zeros;
	int			moves;
	t_img		img;
	t_data	data;
	t_map		map;
	t_img		bg;
}	t_game;

// Initialization & Memory
t_player	*player_alloc(char **mtx);
void		init_nbr(t_game *game);
void		init_values(t_game *game);
t_game		*data_init(t_game *game);

// Memory

void		free_map(t_game *game);
void		free_stacks(t_game *game);
void		destroy_image(t_game *game);
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
int			move(t_game *game, int to_x, int to_y, int player_sprite);

// Animations
void	ini_anim(t_game *game, int row, int column);
void	aw_choice(t_game *game, int player_sprite);
void	aw_up(t_game *game, int loc);
void	aw_down(t_game *game);
void	aw_left(t_game *game, int loc);
void	aw_right(t_game *game, int loc);
int	player_idle(t_game *game);
void animation_idle(t_game *game, int x, int y);
void	animate_death(t_game *game, int x, int y);

// Wallpapers

void	graphical(t_game *game);
void	render_bg(t_img *buffer, t_game *game, int y, int x);
void	init_pixel(t_game *game);

// Defines
// # define MAP_PATH "maps/map.ber"
// Numbers and movements

void nbr_of_moves(t_game *game);

// Enemy
int		rand_enemies(t_game *game);
void	render_enemy(t_game *game);
void enemy_position(t_game *game, int moves);
void	move_enemy(t_game *game, int enemies, int *x, int *y);
void	zombie_up_animate(t_game *game, int enemies);

// Window
void		window_init(t_game *game);

// Images

void		render_map(t_game *game);
void		render_player(t_game *game);
void		rand_collectibles(t_game *game, int row, int column);
void		rand_wall(t_game *game, int row, int column);
void		image_render(t_game *game, t_img *buffer, char *file, t_iter iter);

// Keys

int			key_code(int keycode, t_game *game);
int			kill_game(t_game *game);

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
