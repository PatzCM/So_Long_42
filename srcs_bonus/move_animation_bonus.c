/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:58:46 by palexand          #+#    #+#             */
/*   Updated: 2024/12/31 03:07:08 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	aw_up(t_game *game, int loc)
{
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * 64, loc * 64));
	game->player_p.x -= 1;
	image_render(game, &game->bg, "./img/wu/00.xpm", it_s(
			game->player_p.y * 64, game->player_p.x * SIZE + ((SIZE / 4) * 3)));
	image_render(game, &game->bg, "./img/floor.xpm",
		it_s(game->player_p.y * SIZE, loc * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/wu/01.xpm",
		it_s(game->player_p.y * 64, game->player_p.x * 64 + ((SIZE / 4) * 2)));
	image_render(game, &game->bg, "./img/floor.xpm",
		it_s(game->player_p.y * 64, game->player_p.x * 64 + ((SIZE / 4) * 3)));
	usleep(150000);
	image_render(game, &game->bg, "./img/wu/02.xpm",
		it_s(game->player_p.y * SIZE, game->player_p.x * SIZE + (SIZE / 4)));
	image_render(game, &game->bg, "./img/floor.xpm",
		it_s(game->player_p.y * SIZE, game->player_p.x * SIZE + ((SIZE / 4))));
	usleep(150000);
	image_render(game, &game->bg, "./img/wu/03.xpm",
		it_s(game->player_p.y * SIZE, game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm",
		it_s(game->player_p.y * SIZE, loc * SIZE));
	usleep(150000);
}

void	aw_down(t_game *game)
{
	t_img	buffer;
	int		loc;

	loc = game->player_p.x;
	buffer = game->bg;
	image_render(game, &buffer, "./img/floor.xpm",
		it_s(game->player_p.y * SIZE, loc * SIZE));
	game->player_p.x += 1;
	image_render(game, &buffer, "./img/wd/00.xpm",
		it_s(game->player_p.y * 64, game->player_p.x * 64 - ((SIZE / 3) * 2)));
	image_render(game, &buffer, "./img/floor.xpm",
		it_s(game->player_p.y * SIZE, loc * SIZE));
	usleep(150000);
	image_render(game, &buffer, "./img/wd/01.xpm",
		it_s(game->player_p.y * SIZE, game->player_p.x * SIZE - ((SIZE / 3))));
	image_render(game, &buffer, "./img/floor.xpm",
		it_s(game->player_p.y * SIZE, game->player_p.x * SIZE - ((SIZE / 3))));
	usleep(150000);
	image_render(game, &buffer, "./img/wd/02.xpm",
		it_s(game->player_p.y * SIZE, game->player_p.x * SIZE));
	image_render(game, &buffer, "./img/floor.xpm",
		it_s(game->player_p.y * SIZE, loc * SIZE));
	usleep(150000);
}

void	aw_left(t_game *game, int loc)
{
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			loc * 64, game->player_p.x * 64));
	game->player_p.y -= 1;
	image_render(game, &game->bg, "./img/wl/00.xpm", it_s(
			game->player_p.y * 64 + ((SIZE / 4) * 3), game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			loc * SIZE, game->player_p.x * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/wl/01.xpm", it_s(
			game->player_p.y * 64 + ((SIZE / 4) * 2), game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * 64 + ((SIZE / 4) * 3), game->player_p.x * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/wl/02.xpm", it_s(
			game->player_p.y * SIZE + (SIZE / 4), game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * SIZE + ((SIZE / 4)), game->player_p.x * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/wl/03.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			loc * SIZE, game->player_p.x * SIZE));
	usleep(150000);
}

void	aw_right(t_game *game, int loc)
{
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			loc * SIZE, game->player_p.x * SIZE));
	game->player_p.y += 1;
	image_render(game, &game->bg, "./img/wr/00.xpm", it_s(
			game->player_p.y * 64 - ((SIZE / 4) * 3), game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			loc * SIZE, game->player_p.x * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/wr/01.xpm", it_s(
			game->player_p.y * 64 - ((SIZE / 4) * 2), game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * 64 - ((SIZE / 4) * 3), game->player_p.x * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/wr/02.xpm", it_s(
			game->player_p.y * SIZE - (SIZE / 4), game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			game->player_p.y * SIZE - ((SIZE / 4)), game->player_p.x * SIZE));
	usleep(150000);
	image_render(game, &game->bg, "./img/wr/03.xpm", it_s(
			game->player_p.y * SIZE, game->player_p.x * SIZE));
	image_render(game, &game->bg, "./img/floor.xpm", it_s(
			loc * SIZE, game->player_p.x * SIZE));
	usleep(150000);
}

void	aw_choice(t_game *game, int player_sprite)
{
	if (player_sprite == BACK)
		aw_up(game, game->player_p.x);
	if (player_sprite == FRONT)
		aw_down(game);
	else if (player_sprite == LEFT)
		aw_left(game, game->player_p.y);
	else if (player_sprite == RIGHT)
		aw_right(game, game->player_p.y);
}
