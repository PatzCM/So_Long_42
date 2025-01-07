/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:36:20 by palexand          #+#    #+#             */
/*   Updated: 2024/12/20 13:36:20 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (game->map.width * 64),
			(game->map.height * 64), WIN_TITLE);
	mlx_key_hook(game->window, key_code, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, &key_code, game);	
	init_pixel(game);
	render_map(game);
	graphical(game);
	mlx_loop_hook(game->mlx, &player_idle, game);
	mlx_loop(game->mlx);

}

int	key_code(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_ESC)
		exit_game(game, 0);
	return (0);
}

void	init_pixel(t_game *game)
{
	game->bg.img = mlx_new_image(game->mlx, game->map.width * game->data.tile_size, game->map.height * game->data.tile_size);
	game->bg.addr = mlx_get_data_addr(game->bg.img,
			&game->bg.bpp, &game->bg.llen, &game->bg.endian);
}

