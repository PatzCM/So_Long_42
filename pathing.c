#include "so_long.h"

void	*validate_path(char **matrix,	int x, int y, t_game *collectibles)
{
	char			**copy;
	int				i;
	t_player		**player;
// Trying to validate the path of the player position using matrix, x, y, and collectibles
	i = collectibles->collectibles;
	copy = matrix;
	player = player_position;
	if (player->x < 0 || player->y < 0)
		return (NULL);
	else if (copy[player->x][player->y] != '1' && copy[player->x][player->y] == 'C')
	{
		ft_printf("[%d] collectibles left out of [%d]\n", i, collectibles->collectibles);
		i--;
	}
	else if (copy[player->x][player->y] != '1' && copy[player->x][player->y] == 'F')
		return (NULL);
	else if (copy[player->x][player->y] == 'E')
	{
		copy[player->x][player->y] = 'e';
		return ;
	}
		validate_path(copy, player->x + 1, player->y, collectibles);
}

t_player	*player_position(char **matrix, t_player **player)
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
			}
			j++;
		}
		i++;
	}
}
