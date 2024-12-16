#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	init_values(&game);
	if (argc == 2)
		map_validation(argv[1], &game);
	ft_printf("Map validated\n");
}

void	map_validation(char *file, t_game *game)
{
	t_map		*mtrx;
	
		mtrx = malloc(sizeof(t_map));
		mtrx->matrix = matrix(file);
		validate_ber(file);
		validate_shape(mtrx->matrix);
		game->collectibles = number_of_elements(mtrx->matrix, game->collectibles);
		if (game->collectibles < 0)
			exit(EXIT_FAILURE);
		error_validation(mtrx->matrix, player_alloc(mtrx->matrix), game);
}

t_player	*player_alloc(char **mtx)
{
	t_player	*player;
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		exit(EXIT_FAILURE);
	player_position(mtx, player);
	return (player);
}

void	init_values(t_game *game)
{
	game = malloc(sizeof(t_game));
	game->mlx = NULL;
	game->window = NULL;
	game->image = NULL;
	game->player_img = NULL;
	game->collectibles = 0;
	game->collectible_img = NULL;
	game->exit = 0;
	game->exit_img = NULL;
	game->player = 0;
	game->floor = NULL;
	game->map = NULL;
	game->wall = NULL;
	game->data.tile_size = SIZE;
	game->floor = malloc(11 * sizeof(void *));

}
