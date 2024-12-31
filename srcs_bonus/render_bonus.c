/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:58:11 by palexand          #+#    #+#             */
/*   Updated: 2024/12/31 00:11:00 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_player(t_game *game)
{
	if (game->player_sprite == FRONT)
		image_render(game, "./img/player2.xpm", game->player_p.y * 64, game->player_p.x * 64);
	else if (game->player_sprite == BACK)
		image_render(game, "./img/player_back_ns.xpm", game->player_p.y * 64, game->player_p.x * 64);	
	else if (game->player_sprite == LEFT)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_left, game->player_p.y * 64, game->player_p.x * 64);
	else if (game->player_sprite == RIGHT)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_right, game->player_p.y * 64, game->player_p.x * 64);
}
void	image_render(t_game *game, char *file, int x, int y)
{
	if (game->img.xpm)
	{
		mlx_destroy_image(game->mlx, game->img.xpm);
		game->img.xpm = 0;
	}
	game->img.xpm = mlx_xpm_file_to_image(game->mlx, 
	 file, &game->data.tile_size, &game->data.tile_size);
	if (!game->img.xpm)
	{
		ft_printf("Error\n");
	}
	mlx_put_image_to_window(game->mlx, game->window, 
		game->img.xpm, x, y);
}



void	render_map2(t_game *game, int row, int column)
{
	if (game->map.mtx[row][column] == '0')
		image_render(game, "./img/floor.xpm", column * game->data.tile_size, row * game->data.tile_size);	
	if (game->map.mtx[row][column] == 'E' && game->collectibles > 0)
	{
			image_render(game, "./img/inac_exit.xpm", column * game->data.tile_size, row * game->data.tile_size);
		game->player_p.x_end = row;
		game->player_p.y_end = column;
	}
}

void	render_map(t_game *game)
{
	int	row;
	int	column;

	row = -1;
	while (game->map.mtx[++row])
	{
		column = -1;
		while (game->map.mtx[row][++column])
		{
			if (game->map.mtx[row][column] == '1')
				image_render(game, "./img/wall.xpm", column * game->data.tile_size, row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'P')
				image_render(game, "./img/idle/00.xpm", column * game->data.tile_size,
					row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'C')
					image_render(game, "./img/collective_floor.xpm", column * game->data.tile_size,
					row * game->data.tile_size);
			else
				render_map2(game, row, column);
		}
	}
}
