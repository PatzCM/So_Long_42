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

#include "so_long.h"

void	pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.addr + (y * game->data.len + x * (game->data.bpp / 8));
	*(unsigned int *)dst = color;
}

void	image_render(t_game *game)
{
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./img/player2.xpm",
			&game->data.tile_size, &game->data.tile_size);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"./img/collective_floor.xpm", &game->data.tile_size,
			&game->data.tile_size);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm",
			&game->data.tile_size, &game->data.tile_size);
	game->corner_top_left = mlx_xpm_file_to_image(game->mlx,
			"./img/corner_top_left.xpm", &game->data.tile_size,
			&game->data.tile_size);
	game->corner_top_right = mlx_xpm_file_to_image(game->mlx,
			"./img/corner_top_right.xpm", &game->data.tile_size,
			&game->data.tile_size);
	game->middle_top = mlx_xpm_file_to_image(game->mlx, "./img/middle_top.xpm",
			&game->data.tile_size, &game->data.tile_size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm",
			&game->data.tile_size, &game->data.tile_size);
	game->i_exit = mlx_xpm_file_to_image(game->mlx, "./img/inac_exit.xpm",
			&game->data.tile_size, &game->data.tile_size);
}

t_game	*data_init(t_game *game)
{
	return (game);
}

void	render_map(t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (game->map.mtx[row++])
	{
		column = 0;
		while (game->map.mtx[row][column++])
		{
			if (game->map.mtx[row][column] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall,
					column * game->data.tile_size, row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, column * game->data.tile_size,
					row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->collectible_img, column * game->data.tile_size,
					row * game->data.tile_size);
			if (game->map.mtx[row][column] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->floor,
					column * game->data.tile_size, row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'E' && game->collectibles > 0)
			{
				mlx_put_image_to_window(game->mlx, game->window, game->i_exit,
					column * game->data.tile_size, row * game->data.tile_size);
				game->player_p.x_end = row;
				game->player_p.y_end = column;
			}
		}
	}
}
