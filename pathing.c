#include "so_long.h"
void	error_validation(char **matrix, t_player *player, t_game *game)
{
	game = limits(game);
	game->player_p = *player;
	flood_fill(matrix, player->x, player->y, player_alloc(matrix), &game->map);
	if (confirm_flood(matrix, &game->map) == -1)
		exit(EXIT_FAILURE);
	window_init(game);
}

void	flood_fill(char **matrix,	int x, int y, t_player *player, t_map *limit)
{
	char			**maps = matrix;
	if ((player->x == 0 || player->y == 0) || (player->x == limit->width || player->y == limit->height ) )
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
 flood_fill(matrix, x + 1, y, player, limit);
 flood_fill(matrix, x - 1, y, player, limit);
 flood_fill(matrix, x, y + 1, player, limit);
 flood_fill(matrix, x, y - 1, player, limit);
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
			if (matrix[i][j] != '1' && matrix[i][j] != 'F' && matrix[i][j] != 'e' && matrix[i][j] != '0')
			{
				return (printf("Invalid path!\n"), -1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
