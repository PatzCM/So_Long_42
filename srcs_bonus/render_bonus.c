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

#include "../inc/so_long_bonus.h"

void	render_player(t_game *game)
{
	if (game->player_sprite == FRONT)
		image_render(game, "../img/player2.xpm", game->player_p.y * 64, game->player_p.x * 64);
	else if (game->player_sprite == BACK)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_back, game->player_p.y * 64, game->player_p.x * 64);
	/*else if (game->player_sprite == LEFT)*/
	/*	mlx_put_image_to_window(game->mlx, game->window,*/
	/*		game->player_left, game->player_p.y * 64, game->player_p.x * 64);*/
	/*else if (game->player_sprite == RIGHT)*/
	/*	mlx_put_image_to_window(game->mlx, game->window,*/
	/*		game->player_right, game->player_p.y * 64, game->player_p.x * 64);*/
}
void	image_render(t_game *game, char *file, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr, 
	 file, &game->data.tile_size, &game->data.tile_size);
	mlx_put_image_to_window(game->data.mlx_ptr, game->data.mlx_win, 
		game->img.mlx_img, x, y);
}


/*void	image_render(t_game *game)*/
/*{*/
/*	game->player_img = mlx_xpm_file_to_image(game->mlx, "./img/player2.xpm",*/
/*			&game->data.tile_size, &game->data.tile_size);*/
/*	game->collectible_img = mlx_xpm_file_to_image(game->mlx,*/
/*			"./img/collective_floor.xpm", &game->data.tile_size,*/
/*			&game->data.tile_size);*/
/*	game->floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm",*/
/*			&game->data.tile_size, &game->data.tile_size);*/
/*	game->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm",*/
/*			&game->data.tile_size, &game->data.tile_size);*/
/*	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm",*/
/*			&game->data.tile_size, &game->data.tile_size);*/
/*	game->i_exit = mlx_xpm_file_to_image(game->mlx, "./img/inac_exit.xpm",*/
/*			&game->data.tile_size, &game->data.tile_size);*/
/*	game->player_back = mlx_xpm_file_to_image(game->mlx, "./img/player_back_ns.xpm",*/
/*			&game->data.tile_size, &game->data.tile_size);	*/
/*}*/

void	render_map2(t_game *game, int row, int column)
{
	if (game->map.mtx[row][column] == '0')
		image_render(game, "../img/floor.xpm", column * game->data.tile_size, row * game->data.tile_size);	
	if (game->map.mtx[row][column] == 'E' && game->collectibles > 0)
	{
			image_render(game, "../img/i_exit.xpm", column * game->data.tile_size, row * game->data.tile_size);
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
				image_render(game, "../img/wall.xpm", column * game->data.tile_size, row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'P')
				image_render(game, "../img/player2.xpm", column * game->data.tile_size,
					row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'C')
					image_render(game, "../img/collective_floor.xpm", column * game->data.tile_size,
					row * game->data.tile_size);
			else
				render_map2(game, row, column);
		}
	}
}
