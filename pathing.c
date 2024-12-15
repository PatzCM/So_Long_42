#include "so_long.h"
void	error_validation(char **matrix, t_game *collectibles, t_player *player)
{
	flood_fill(matrix, 0, 0, player_alloc(matrix));
	if (confirm_flood(matrix, player) == -1)
	{
		ft_printf("Error, flood is -1\n");
		exit(EXIT_FAILURE);
	}
}

void	flood_fill(char **matrix,	int x, int y, t_player *player)
{
	int				i;
	char			**maps = matrix;
	ft_printf("Flood	%s\n", maps[x]);	
	if (player->x < 0 || player->y < 0)
		return ;
	if (maps[x][y]== '1' || maps[x][y] == 'F' || maps[x][y] == 'e')
		return ;
	if (maps[x][y] == 'E')
	{
		maps[x][y] = 'e';
		return ;
	}
	if (maps[x][y] != '1' && maps[x][y] != 'e')
	{
		maps[x][y] = 'F';
	}
 flood_fill(matrix, x + 1, y, player);
 flood_fill(matrix, x - 1, y, player);
 flood_fill(matrix, x, y + 1, player);
 flood_fill(matrix, x, y - 1, player);
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
				ft_printf("Player position is [%d][%d]\n", player->x, player->y);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	confirm_flood(char **matrix, t_player *player)
{
	int	i;
	int	j;
	
	i = 0;
	while (matrix[i])
	{
		j = 0;
			ft_printf("Matrix[%d][%s] \n", i,  matrix[i]);
		while (matrix[i][j])
		{
			if (matrix[i][j] != '1' && matrix[i][j] != 'F' && matrix[i][j] != 'e' && matrix[i][j] != '0')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
