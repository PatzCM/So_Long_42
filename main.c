#include "mlx/mlx.h"
#include "so_long.h"

int	main (void)
{
	t_game *game;

	game = NULL;
	game = (t_game *)malloc(sizeof(t_game));
game->mlx = mlx_init();
game->window = mlx_new_window(game->mlx, 800, 600, "so_long");
mlx_loop(game->mlx);
return (0);
}
