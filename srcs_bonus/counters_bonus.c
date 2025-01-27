/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:37:52 by palexand          #+#    #+#             */
/*   Updated: 2024/12/20 13:37:52 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

t_game	*limits(t_game *game)
{
	game->map.width = size_column(game->map.matrix);
	game->map.height = size_row(game->map.matrix);
	return (game);
}

int	size_row(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	size_column(char **matrix)
{
	int	i;
	int	j;
	int	biggest;

	biggest = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] != '\n')
			j++;
		if (j > biggest)
			biggest = j;
		i++;
	}
	return (biggest);
}

int	number_of_elements(char **matrix, int collectibles, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '0')
				game->zeros++;
			if (matrix[i][j] == 'C')
				collectibles++;
			else if (matrix[i][j] == 'P')
				game->player++;
			else if (matrix[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (collectibles == 0 || game->player == 0 || game->exit == 0
		|| game->player > 1 || game->exit > 1)
		return (-1);
	return (game->collectibles = collectibles, collectibles);
}
