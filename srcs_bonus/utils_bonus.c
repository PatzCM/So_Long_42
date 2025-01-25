/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:10:23 by palexand          #+#    #+#             */
/*   Updated: 2024/12/31 03:07:11 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

void	move_up(t_game *game)
{
	if (game->map.mtx[game->player_p.x - 1][game->player_p.y] == '1')
		return ;
	move(game, game->player_p.x - 1, game->player_p.y, BACK);
}

void	move_left(t_game *game)
{
	if (game->map.mtx[game->player_p.x][game->player_p.y - 1] == '1')
		return ;
	else
		move(game, game->player_p.x, game->player_p.y - 1, LEFT);
}

void	move_down(t_game *game)
{
	if (game->map.mtx[game->player_p.x + 1][game->player_p.y] == '1')
		return ;
	else
		move(game, game->player_p.x + 1, game->player_p.y, FRONT);
}

void	move_right(t_game *game)
{
	if (game->map.mtx[game->player_p.x][game->player_p.y + 1] == '1')
		return ;
	else
		move(game, game->player_p.x, game->player_p.y + 1, RIGHT);
}

int	move(t_game *game, int to_x, int to_y, int player_sprite)
{
	game->player_sprite = player_sprite;
	if (game->collectibles == 0)
		image_render(game, &game->bg, "./img/exit.xpm",
			it_s(game->player_p.y_end * 64, game->player_p.x_end * 64));
	if (game->map.mtx[to_x][to_y] == 'E' && game->collectibles == 0)
		exit_game(game, 1);
	if (game->map.mtx[to_x][to_y] == 'C' && game->collectibles-- > -1)
	{
		game->map.mtx[to_x][to_y] = '0';
		ft_printf("Collectibles[%d]\n", game->collectibles);
	}
	if (game->map.mtx[to_x][to_y] == 'E' && game->collectibles > 0)
		return (ft_printf("You need to collect all the collectibles\n"), 1);
	if (game->map.mtx[to_x][to_y] == 'X')
	{
		aw_choice(game, player_sprite);
		animate_death(game, to_x, to_y);
	}
	aw_choice(game, player_sprite);
	nbr_of_moves(game);
	return (0);
}
