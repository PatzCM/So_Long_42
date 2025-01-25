/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:58:11 by palexand          #+#    #+#             */
/*   Updated: 2024/12/20 14:02:56 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	image_render(t_game *game, char *file, int x, int y)
{
	game->data.xpm = mlx_xpm_file_to_image(game->mlx, file,
			&game->data.tile_size, &game->data.tile_size);
	mlx_put_image_to_window(game->mlx, game->window, game->data.xpm, x, y);
	mlx_destroy_image(game->mlx, game->data.xpm);
	game->data.xpm = NULL;
}

void	render_map(t_game *game, int row, int column)
{
	while (game->map.mtx[++row])
	{
		column = -1;
		while (game->map.mtx[row][++column])
		{
			if (game->map.mtx[row][column] == '1')
				image_render(game, "img/wall.xpm",
					column * game->data.tile_size, row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'P')
				image_render(game, "img/player.xpm",
					column * game->data.tile_size, row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'C')
				image_render(game, "img/col.xpm", column * game->data.tile_size,
					row * game->data.tile_size);
			if (game->map.mtx[row][column] == '0')
				image_render(game, "img/floor.xpm", column * 64, row * 64);
			if (game->map.mtx[row][column] == 'E' && game->collectibles > 0)
			{
				image_render(game, "img/inac_exit.xpm",
					column * game->data.tile_size, row * game->data.tile_size);
				game->player_p.x_end = row;
				game->player_p.y_end = column;
			}
		}
	}
}
