/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_animations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:54 by palexand          #+#    #+#             */
/*   Updated: 2025/01/25 17:42:54 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ini_anim(t_game *game, int row, int column)
{
	image_render(game, &game->bg, "./img/idle/00.xpm", it_s(
			column * SIZE, row * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/idle/01.xpm", it_s(
			column * SIZE, row * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/idle/02.xpm", it_s(
			column * SIZE, row * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/idle/03.xpm", it_s(
			column * SIZE, row * SIZE));
	usleep(150000);
}

void	animation_idle(t_game *game, int x, int y)
{
	usleep(300000);
	image_render(game, &game->bg, "./img/floor.xpm", it_s(y * SIZE, x * SIZE));
	image_render(game, &game->bg, "./img/idle/00.xpm", it_s(
			y * SIZE, x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	usleep(300000);
	image_render(game, &game->bg, "./img/idle/01.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	usleep(300000);
	image_render(game, &game->bg, "./img/idle/02.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	usleep(300000);
	image_render(game, &game->bg, "./img/idle/03.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	usleep(300000);
	image_render(game, &game->bg, "./img/idle/00.xpm",
		it_s(y * SIZE, x * SIZE));
}
