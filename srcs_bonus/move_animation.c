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

void	aw_up(t_game *game)
{
	int loc = game->player_p.x;
		// create function for dying animation
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	game->player_p.x-= 1;
	image_render(game, "./img/wu/00.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE + ((SIZE / 4) * 3));
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	usleep(100000);
	image_render(game, "./img/wu/01.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE + ((SIZE / 4) * 2));
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	usleep(100000);
	image_render(game, "./img/wu/02.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE + (SIZE / 4));
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	usleep(100000);
	image_render(game, "./img/wu/03.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	usleep(100000);
}

void	aw_down(t_game *game)
{
	int loc = game->player_p.x;
	printf("Player[%d][%d]\n", game->player_p.y, game->player_p.x);
		// create function for dying animation
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	game->player_p.x+= 1;
	image_render(game, "./img/wd/00.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE + ((SIZE / 3) * 2));
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	usleep(100000);
	image_render(game, "./img/wd/01.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE + ((SIZE / 3)));
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	usleep(100000);
	image_render(game, "./img/wd/02.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", game->player_p.y * SIZE, loc * SIZE);
	usleep(100000);
}

void	aw_left(t_game *game)
{
	int loc = game->player_p.y;
		// create function for dying animation
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	game->player_p.y-= 1;
	image_render(game, "./img/wl/00.xpm", game->player_p.y * SIZE + ((SIZE / 4) * 3), game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
	image_render(game, "./img/wl/01.xpm", game->player_p.y * SIZE + ((SIZE / 4) * 2), game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
	image_render(game, "./img/wl/02.xpm", game->player_p.y * SIZE + (SIZE / 4), game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
	image_render(game, "./img/wl/03.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
}

void	aw_right(t_game *game)
{
	int loc = game->player_p.y;
		// create function for dying animation
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	game->player_p.y+= 1;
	image_render(game, "./img/wr/00.xpm", game->player_p.y * SIZE + ((SIZE / 4) * 3), game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
	image_render(game, "./img/wr/01.xpm", game->player_p.y * SIZE + ((SIZE / 4) * 2), game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
	image_render(game, "./img/wr/02.xpm", game->player_p.y * SIZE + (SIZE / 4), game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
	image_render(game, "./img/wr/03.xpm", game->player_p.y * SIZE, game->player_p.x * SIZE);
	image_render(game, "./img/floor.xpm", loc * SIZE, game->player_p.x * SIZE);
	usleep(100000);
}

void	aw_choice(t_game *game, int player_sprite)
{
	if (player_sprite == BACK)
		aw_up(game);
	else if (player_sprite == FRONT)
		aw_down(game);
	else if (player_sprite == LEFT)
		aw_left(game);
	else if (player_sprite == RIGHT)
		aw_right(game);

}
void	ini_anim(t_game *game, int row, int column)
{
	image_render(game, "./img/idle/00.xpm", column * SIZE, row * SIZE);
	usleep(300000);
	image_render(game, "./img/idle/01.xpm", column * SIZE, row * SIZE);
	usleep(300000);
	image_render(game, "./img/idle/02.xpm", column * SIZE, row * SIZE);
	usleep(300000);
	image_render(game, "./img/idle/03.xpm", column * SIZE, row * SIZE);
	usleep(300000);

}
