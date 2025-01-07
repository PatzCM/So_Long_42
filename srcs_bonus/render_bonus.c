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

void	image_render(t_game *game, t_img *buffer, char *file, int x, int y)
{
    char    *dst;
    char    *src;
    int     a;
    int     b;
    int     temp;
		
		if (game->img.xpm)
	{
		mlx_destroy_image(game->mlx, game->img.xpm);
		game->img.xpm = 0;
	}
	game->img.xpm = mlx_xpm_file_to_image(game->mlx, file, &game->data.tile_size, &game->data.tile_size);
	game->img.img = mlx_new_image(game->mlx, game->data.tile_size, game->data.tile_size);
	game->img.addr = mlx_get_data_addr(game->img.xpm, &game->img.bpp, &game->img.llen, &game->img.endian);
	
	temp = x;
    a = 0;
    b = -1;
    while (a < 64)
    {
        if (++b == 64)
        {
            a++;
            y++;
            b = 0;
            x = temp;
        }
        if (x++ && a == 64)
            break;
				dst = NULL;
				dst = buffer->addr + (y * buffer->llen + x * (buffer->bpp / 8));
        src = game->img.addr + (a * game->img.llen + b * (game->img.bpp / 8));
				if (*src)
            *(unsigned int *)dst = *(unsigned int *)src;
    }
	mlx_put_image_to_window(game->mlx, game->window, buffer->img, 0, 0);
}

int	player_idle(t_game *game)
{
	int x;
	int y;

	y = game->player_p.y;
	x = game->player_p.x;

	if (game->data.loop < 250000)
	{
		game->data.loop++;
		return (0);
	}
	game->data.loop = 0;
	animation_idle(game, x, y);
	return (0);
}

void	render_bg(t_img *buffer, t_game *game, int x, int y)
{
	int		a;
	int		b;
	char	*dst;
	char	*src;

	a = 0;
	b = 0;
	while (a < game->data.tile_size * game->map.height)
	{
		if (b == game->data.tile_size * game->map.width)
		{
			a++;
			y++;
			b = 0;
			x = 0;
		}
		
		if (a == game->data.tile_size * game->map.height)
			break ;
		dst = buffer->addr + (y * buffer->llen + x * (buffer->bpp / 8));
		src = game->bg.addr + (a * game->bg.llen + b * (game->bg.bpp / 8));
		if (*src)
			*(unsigned int *)dst = *(unsigned int *)src;
		b++;
		x++;
	}
}

void	graphical(t_game *game)
{
	t_img	buffer;
	buffer.img = mlx_new_image(game->mlx, game->data.tile_size * game->map.width,
		game->data.tile_size * game->map.height);
	buffer.addr = mlx_get_data_addr(buffer.img, &buffer.bpp, &buffer.llen, &buffer.endian);render_map(game);
	render_bg(&buffer, game, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, buffer.img, 0, 0);	
	mlx_destroy_image(game->mlx, buffer.img);
}


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
			if (game->map.mtx[row][column] == '0' || game->map.mtx[row][column] == 'C' 
				|| game->map.mtx[row][column] == 'E' || game->map.mtx[row][column] == 'P') 
				image_render(game, &game->bg, "./img/floor.xpm", column * game->data.tile_size, row * game->data.tile_size);	
			if (game->map.mtx[row][column] == '1')
			{
				image_render(game, &game->bg, "./img/floor.xpm", column * game->data.tile_size, row * game->data.tile_size);
				rand_wall(game, row, column);	
			}/*rand_wall(game, row, column);*/
			if (game->map.mtx[row][column] == 'P')
				image_render(game, &game->bg, "./img/idle/00.xpm", column * game->data.tile_size, row * game->data.tile_size);
			if (game->map.mtx[row][column] == 'C')
				rand_collectibles(game, row, column);
			if (game->map.mtx[row][column] == '0')
				image_render(game, &game->bg,"./img/floor.xpm", column * game->data.tile_size, row * game->data.tile_size);	
			if (game->map.mtx[row][column] == 'E' && game->collectibles > 0)
			{
			image_render(game, &game->bg,"./img/inac_exit.xpm", column * game->data.tile_size, row * game->data.tile_size);
			game->player_p.x_end = row;
			game->player_p.y_end = column;
			}
			/*else*/
			/*		render_map2(game, row, column);*/
		}
	}
}

void	rand_collectibles(t_game *game, int row, int column)
{
	int i;
	i = rand() % 3;
	if (i == 0)
		image_render(game, &game->bg, "./img/col00.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (i == 1)
		image_render(game, &game->bg, "./img/col01.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (i == 2)
		image_render(game, &game->bg, "./img/col02.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (i == 3)
		image_render(game, &game->bg, "./img/col03.xpm", column * game->data.tile_size, row * game->data.tile_size);
}

void	rand_enemies(t_game *game)
{
	int	x;
	int y;
	int enemies;

	game->data.enemies = game->zeros / 20;
	game->map.enemy_x = ft_calloc(game->data.enemies, sizeof(int));
	game->map.enemy_y = ft_calloc(game->data.enemies, sizeof(int));
	enemies = game->data.enemies;
	while (--enemies >= 0)
	{
		y = 0;
		x = 0;
		while (game->map.mtx[y][x] != '0')
		{
			x = rand() % game->map.height - 1;
			y = rand() % game->map.width - 1;
		}
		game->map.enemy_x[enemies] = x;
		game->map.enemy_y[enemies] = y;
	}
}

/*void	render_enemy(t_game *game)*/
/*{*/
/*	int i;*/
/*	t_map *m;*/
/*	m = &game->map;*/
/*	i = -1;*/
/*	while (++i < game->data.enemies)*/
/*	{*/
/*		image_render(game, &game->bg, "./img/enemy.xpm", m->enemy_y[i] * game->data.tile_size, m->enemy_x[i] * game->data.tile_size);*/
/*		m->mtx[m->enemy_x[i]][m->enemy_y[i]] = 'X';*/
/*	}	*/
/*}*/
void rand_wall(t_game *game, int row, int column)
{
	int i;
	i = rand() % 4;
	if (row == 0 && column == 0)
		image_render(game, &game->bg, "./img/wall0_0.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row == 0 && column > 0 && column < game->map.width - 1)
		image_render(game, &game->bg, "./img/wall0_1.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row > 0 && row < (game->map.height - 1) && column == 0)
		image_render(game, &game->bg, "./img/wall1_0.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row == game->map.height - 1 && column == 0)
		image_render(game, &game->bg, "./img/wall1_1.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row > 0 && row < game->map.height - 1 && column == 0)
		image_render(game, &game->bg, "./img/wall2_0.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row == game->map.height - 1 && column == game->map.width - 1)
			image_render(game, &game->bg, "./img/wall2_2.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row > 0 && row < game->map.height - 1 && column == game->map.width - 1)
		image_render(game, &game->bg, "./img/wall1_2.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row == 0 && column == game->map.width - 1)
		image_render(game, &game->bg, "./img/wall2_0.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (row == game->map.height - 1 && column > 0 && column < game->map.width - 1)
		image_render(game, &game->bg, "./img/wall0_2.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (i == 0)
		image_render(game, &game->bg, "./img/wall.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (i == 1)
		image_render(game, &game->bg, "./img/wall00.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (i == 2)
		image_render(game, &game->bg, "./img/wall01.xpm", column * game->data.tile_size, row * game->data.tile_size);
	else if (i == 3)
		image_render(game, &game->bg, "./img/wall02.xpm", column * game->data.tile_size, row * game->data.tile_size);
}
