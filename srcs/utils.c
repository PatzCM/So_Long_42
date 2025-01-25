/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:10:23 by palexand          #+#    #+#             */
/*   Updated: 2024/12/20 13:35:27 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	move_up(t_game *game)
{
	if (game->map.mtx[game->player_p.x - 1][game->player_p.y] == '1')
		return ;
	move(game, game->player_p.x - 1, game->player_p.y);
}

void	move_left(t_game *game)
{
	if (game->map.mtx[game->player_p.x][game->player_p.y - 1] == '1')
		return ;
	else
		move(game, game->player_p.x, game->player_p.y - 1);
}

void	move_down(t_game *game)
{
	if (game->map.mtx[game->player_p.x + 1][game->player_p.y] == '1')
		return ;
	else
		move(game, game->player_p.x + 1, game->player_p.y);
}

void	move_right(t_game *game)
{
	if (game->map.mtx[game->player_p.x][game->player_p.y + 1] == '1')
		return ;
	else
		move(game, game->player_p.x, game->player_p.y + 1);
}

int	move(t_game *game, int to_x, int to_y)
{
	static int	moves = 1;

	if (game->collectibles == 0)
		image_render(game, "img/exit.xpm", game->player_p.y_end * 64,
			game->player_p.x_end * 64);
	if (game->map.mtx[to_x][to_y] == 'E' && game->collectibles == 0)
		exit_game(game, 1);
	if (game->map.mtx[to_x][to_y] == 'C' && game->collectibles-- > -1)
	{
		game->map.mtx[to_x][to_y] = '0';
		ft_printf("Collectibles[%d]\n", game->collectibles);
	}
	if (game->map.mtx[to_x][to_y] == 'E' && game->collectibles > 0)
		return (ft_printf("You need to collect all the collectibles\n"), 1);
	image_render(game, "img/floor.xpm", game->player_p.y * 64,
		game->player_p.x * 64);
	game->player_p.x = to_x;
	game->player_p.y = to_y;
	image_render(game, "img/player.xpm", game->player_p.y * 64,
		game->player_p.x * 64);
	return (ft_printf("Number of moves[%d]\n", moves++), 0);
}
