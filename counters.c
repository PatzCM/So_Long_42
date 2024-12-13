#include "so_long.h"
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

	i = 0;
	while (matrix[0][i] != '\n')
		i++;
	return (i);
}

int	number_of_elements(char **matrix, int collectibles)
{
	int		i;
	int		j;
	t_game	game;

	game.player = 0;
	game.exit = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C')
				collectibles++;
			else if (matrix[i][j] == 'P')
				game.player++;
			else if (matrix[i][j] == 'E')
				game.exit++;
			j++;
		}
		i++;
	}
	if (collectibles == 0 || game.player == 0 || game.exit == 0 || game.player > 1 || game.exit > 1)
		return (write(1, "Error\n", 6), -1);
	game.collectibles = collectibles;
	return (collectibles);
}
