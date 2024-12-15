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

#include "so_long.h"

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
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**matrix(char *file, t_matrix mtx)
{
	int			i;

	i = size_map(file);
	mtx.fd = open(file, O_RDONLY);
	mtx.matrix = (char **)malloc(sizeof(char *) * i);
	i = 0;
	mtx.line = get_next_line(mtx.fd);
	while (mtx.line)
	{
		mtx.matrix[i] = mtx.line;
		mtx.line = get_next_line(mtx.fd);
		i++;
	}
	mtx.matrix[i] = NULL;
	close(mtx.fd);
	return (mtx.matrix);
}

int	validate_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 4)
		return (-1);
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
		&& file[i - 3] == 'b' && file[i - 4] == '.')
		return (0);
	else
		return (NULL, write(1, "Error\n", 6));
}

void	validate_shape(char **matrix)
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
			if (matrix[map.row][map.column] != '1'
				&& matrix[map.row][map.column] != '0'
				&& matrix[map.row][map.column] != 'P'
				&& matrix[map.row][map.column] != 'E'
				&& matrix[map.row][map.column] != 'C'
				&& matrix[map.row][map.column] != '\n'
				|| matrix[map.row][map.column_end - 1] != '1'
				|| matrix[map.row_end - 1][map.column] != '1')
				exit(0);
			map.column++;
		}
		if (map.column != map.column_end)
			exit(0);
		map.row++;
	}
}
