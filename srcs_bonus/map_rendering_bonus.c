/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:54:35 by palexand          #+#    #+#             */
/*   Updated: 2025/01/25 21:54:40 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	render_map2(t_game	*game, int row, int column);

void	render_map(t_game *game)
{
	int	row;
	int	column;

	row = -1;
	while (game->map.height > ++row)
	{
		column = -1;
		while (game->map.width > ++column)
		{
			if (game->map.mtx[row][column] == '0'
				|| game->map.mtx[row][column] == 'C'
				|| game->map.mtx[row][column] == 'E'
				|| game->map.mtx[row][column] == 'P')
				image_render(game, &game->bg, "./img/floor.xpm",
					it_s(column * 64, row * 64));
			if (game->map.mtx[row][column] == '1')
			{
				image_render(game, &game->bg, "./img/floor.xpm",
					it_s(column * 64, row * 64));
				rand_wall(game, row, column);
			}
			else
				render_map2(game, row, column);
		}
	}
}

static void	render_map2(t_game	*game, int row, int column)
{
	if (game->map.mtx[row][column] == 'P')
		image_render(game, &game->bg, "./img/idle/00.xpm",
			it_s(column * 64, row * 64));
	if (game->map.mtx[row][column] == 'C')
		rand_collectibles(game, row, column);
	if (game->map.mtx[row][column] == '0')
		image_render(game, &game->bg, "./img/floor.xpm",
			it_s(column * 64, row * 64));
	if (game->map.mtx[row][column] == 'E' && game->collectibles > 0)
	{
		image_render(game, &game->bg, "./img/inac_exit.xpm",
			it_s(column * game->data.tile_size, row * SIZE));
		game->player_p.x_end = row;
		game->player_p.y_end = column;
	}
}

void	rand_collectibles(t_game *game, int row, int column)
{
	int	i;

	i = rand() % 3;
	if (i == 0)
		image_render(game, &game->bg, "./img/col00.xpm", it_s(
				column * game->data.tile_size, row * game->data.tile_size));
	else if (i == 1)
		image_render(game, &game->bg, "./img/col01.xpm", it_s(
				column * game->data.tile_size, row * game->data.tile_size));
	else if (i == 2)
		image_render(game, &game->bg, "./img/col02.xpm", it_s(
				column * game->data.tile_size, row * game->data.tile_size));
	else if (i == 3)
		image_render(game, &game->bg, "./img/col03.xpm", it_s(
				column * game->data.tile_size, row * game->data.tile_size));
}

static void	rand_wall2(t_game *game, int row, int column)
{
	int	i;

	i = rand() % 4;
	if (row > 0 && row < game->map.height - 1 && column == game->map.width - 1)
		image_render(game, &game->bg, "./img/wall1_2.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (row == 0 && column == game->map.width - 1)
		image_render(game, &game->bg, "./img/wall2_0.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (row == game->map.height - 1
		&& column > 0 && column < game->map.width - 1)
		image_render(game, &game->bg, "./img/wall0_2.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (i == 0)
		image_render(game, &game->bg, "./img/wall.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (i == 1)
		image_render(game, &game->bg, "./img/wall00.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (i == 2)
		image_render(game, &game->bg, "./img/wall01.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (i == 3)
		image_render(game, &game->bg, "./img/wall02.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
}

void	rand_wall(t_game *game, int row, int column)
{
	if (row == 0 && column == 0)
		image_render(game, &game->bg, "./img/wall0_0.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (row == 0 && column > 0 && column < game->map.width - 1)
		image_render(game, &game->bg, "./img/wall0_1.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (row > 0 && row < (game->map.height - 1) && column == 0)
		image_render(game, &game->bg, "./img/wall1_0.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (row == game->map.height - 1 && column == 0)
		image_render(game, &game->bg, "./img/wall1_1.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (row > 0 && row < game->map.height - 1 && column == 0)
		image_render(game, &game->bg, "./img/wall2_0.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else if (row == game->map.height - 1 && column == game->map.width - 1)
		image_render(game, &game->bg, "./img/wall2_2.xpm",
			it_s(column * game->data.tile_size, row * game->data.tile_size));
	else
		rand_wall2(game, row, column);
}
