#include "so_long.h"

void	free_stacks(t_game *game)
{
	printf("Destroying stacks\n");
	/*t_player *player = &game->player_p;*/
	destroy_image(game);
	free_map(game);
	free(game->map.matrix);
	free(game->map.mtx);
	free(game->mlx);
	/*free(&game->player_p);*/
	////////free(game->floor);
	free(game);
}

void	free_map(t_game *game)
{
	int i;
	i = 0;
	while(game->map.matrix[i])
	{
		free(game->map.matrix[i]);
		i++;
	}
	i = 0;
	while (game->map.mtx[i]) {
		free(game->map.mtx[i]);
		i++;
	}
}
void	destroy_image(t_game *game)
{
	ft_printf("Destroying images\n");
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);	
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->i_exit);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
}
