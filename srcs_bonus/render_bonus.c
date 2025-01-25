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

void	pixel_rendering(t_game *game, t_img *buffer, int x, int y);

t_iter	it_s(int y, int x)
{
	t_iter	iter;

	iter.x = y;
	iter.y = x;
	return (iter);
}

void	image_render(t_game *game, t_img *buffer, char *file, t_iter iter)
{
	game->img.xpm = mlx_xpm_file_to_image(game->mlx,
			file, &game->data.tile_size, &game->data.tile_size);
	game->img.addr = mlx_get_data_addr(game->img.xpm,
			&game->img.bpp, &game->img.llen, &game->img.endian);
	pixel_rendering(game, buffer, iter.x, iter.y);
	mlx_put_image_to_window(game->mlx, game->window, buffer->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img.xpm);
	game->img.xpm = NULL;
}

void	pixel_rendering(t_game *game, t_img *buffer, int x, int y)
{
	char	*dst;
	char	*src;
	int		a;
	int		b;
	int		temp;

	temp = x;
	a = 0;
	b = -1;
	while (a < 64)
	{
		if (++b == 64 && a++ > -66)
		{
			y++;
			b = 0;
			x = temp;
		}
		if (x++ && a == 64)
			break ;
		dst = NULL;
		dst = buffer->addr + (y * buffer->llen + x * (buffer->bpp / 8));
		src = game->img.addr + (a * game->img.llen + b * (game->img.bpp / 8));
		if (*src)
			*(unsigned int *)dst = *(unsigned int *)src;
	}
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

	buffer.img = mlx_new_image(game->mlx, 64 * game->map.width,
			game->data.tile_size * game->map.height);
	buffer.addr = mlx_get_data_addr(buffer.img,
			&buffer.bpp, &buffer.llen, &buffer.endian);
	render_map(game);
	render_bg(&buffer, game, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, buffer.img, 0, 0);
	mlx_destroy_image(game->mlx, buffer.img);
	nbr_of_moves(game);
}
