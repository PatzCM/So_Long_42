#include "so_long.h"

char	**matrix(char *file)
{
	int		fd;
	char	*line;
	char	**matrix;
	int		i;

	i = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	matrix = (char **)malloc(sizeof(char *) * i);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		matrix[i] = line;
		line = get_next_line(fd);
		i++;
	}
	matrix[i] = NULL;
	close(fd);
	return (matrix);
}

int	validate_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	
		if (i < 4)
			return (-1);
		if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b' && file[i - 4] == '.')
			return (0);
		else
			return (-1);
}

void	validate_shape(char **matrix)
{
	int	column;
	int	row;
	int counter;

	column = 0;
	row = 0;
	counter = 0;

	while (matrix[row][column++])
		counter++;
	while(matrix[row])
	{
		column = 0;	
		while (matrix[row][column])
			column++;
		if (column != counter)
		{
			ft_printf("Error\n");
			exit(0);
		}
		row++;
	}
}
