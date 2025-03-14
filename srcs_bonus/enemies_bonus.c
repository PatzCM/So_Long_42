/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:51:40 by palexand          #+#    #+#             */
/*   Updated: 2025/01/25 17:51:40 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_enemy(t_game *game)
{
	int		i;
	t_map	*m;

	m = &game->map;
	i = -1;
	while (++i < game->data.enemies)
	{
		image_render(game, &game->bg, "./img/z_idle/00.xpm",
			it_s(m->enemy_y[i] * 64, m->enemy_x[i] * 64));
		m->mtx[m->enemy_x[i]][m->enemy_y[i]] = 'X';
	}
}

int	rand_enemies(t_game *game)
{
	int	x;
	int	y;
	int	enemies;

	game->data.enemies = game->zeros / 20;
	game->map.enemy_x = ft_calloc(game->data.enemies, sizeof(int ));
	game->map.enemy_y = ft_calloc(game->data.enemies, sizeof(int ));
	enemies = game->data.enemies;
	while (--enemies >= 0)
	{
		y = 0;
		x = 0;
		while (game->map.mtx[x][y] != '\0' && game->map.mtx[x][y] != '0' )
		{
			x = rand() % (game->map.height - 1);
			y = rand() % (game->map.width - 1);
		}
		game->map.enemy_x[enemies] = x;
		game->map.enemy_y[enemies] = y;
	}
	return (1);
}
