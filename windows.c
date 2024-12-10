#include "so_long.h"
//function to close the game
int	destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

//function to close the game when the red cross is clicked
int	close_window(t_game *game)
{
	
	destroy(game);
	return (0);
}
