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
#include "../inc/so_long.h"

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	image_render(game);
	game->window = mlx_new_window(game->mlx, (game->map.width * 64),
			(game->map.height * 64), WIN_TITLE);
	render_map(game);
	mlx_key_hook(game->window, key_code, game);
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
