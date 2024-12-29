/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:14:10 by palexand          #+#    #+#             */
/*   Updated: 2024/12/28 01:14:10 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

void	error_validation(char **matrix, t_player *player, t_game *game)
{
	game = limits(game);
	game->player_p = *player;
	flood_fill(matrix, player->x, player->y, &game->map);
	free(player);
	if ((confirm_flood(matrix, &game->map)) == -1)
		exit_game(game, 0);
}

void	flood_fill(char **matrix,	int x, int y, t_map *limit)
{
	char			**maps;

	maps = matrix;
	if ((x == 0 || y == 0)
		|| (x == limit->height || y == limit->width))
		return ;
	if (maps[x][y] == '1' || maps[x][y] == 'F' || maps[x][y] == 'e')
		return ;
	if (maps[x][y] == 'E')
	{
		maps[x][y] = 'e';
		return ;
	}
	if (maps[x][y] != '1' && maps[x][y] != 'e')
		maps[x][y] = 'F';
	flood_fill(matrix, x + 1, y, limit);
	flood_fill(matrix, x - 1, y, limit);
	flood_fill(matrix, x, y + 1, limit);
	flood_fill(matrix, x, y - 1, limit);
}

void	player_position(char **matrix, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				player->x = i;
				player->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	confirm_flood(char **matrix, t_map *limit)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] && i < limit->height)
	{
		j = 0;
		while (matrix[i][j] && j < limit->width)
		{
			if (matrix[i][j] != '1' && matrix[i][j] != 'F'
				&& matrix[i][j] != 'e' && matrix[i][j] != '0')
				return (ft_printf("Invalid path!\n"), -1);
			j++;
		}
		i++;
	}
	return (0);
}
