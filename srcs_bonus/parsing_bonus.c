/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:07:19 by palexand          #+#    #+#             */
/*   Updated: 2024/12/15 00:07:19 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

static int	size_map(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**matrix(char *file)
{
	int			i;
	t_map		mtrx;

	i = size_map(file);
	mtrx.fd = open(file, O_RDONLY);
	mtrx.matrix = (char **)ft_calloc(sizeof(char *), i);
	i = 0;
	mtrx.line = get_next_line(mtrx.fd);
	while (mtrx.line)
	{
		mtrx.matrix[i] = mtrx.line;
		mtrx.line = get_next_line(mtrx.fd);
		i++;
	}
	mtrx.matrix[i] = NULL;
	close(mtrx.fd);
	return (mtrx.matrix);
}

int	validate_ber(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
		return (-1);
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
		&& file[i - 3] == 'b' && file[i - 4] == '.' && file[i - 5] != '/')
		return (0);
	else
		return (-1);
}

void	validate_shape(char **matrix, t_game *game)
{
	t_map	map;

	map.row = 0;
	map.row_end = size_row(matrix);
	map.column_end = size_column(matrix);
	while (matrix[map.row] && map.row < map.row_end)
	{
		map.column = 0;
		while (matrix[map.row][map.column] && map.column < map.column_end)
		{
			if ((matrix[map.row][map.column] != '1'
				&& matrix[map.row][map.column] != '0'
				&& matrix[map.row][map.column] != 'P'
				&& matrix[map.row][map.column] != 'E'
				&& matrix[map.row][map.column] != 'C'
				&& matrix[map.row][map.column] != '\n')
				|| (matrix[map.row][map.column_end - 1] != '1'
				|| matrix[map.row_end - 1][map.column] != '1'))
				exit_game(game, 2);
			map.column++;
		}
		if (map.column != map.column_end)
			exit_game(game, 2);
		map.row++;
	}
}
