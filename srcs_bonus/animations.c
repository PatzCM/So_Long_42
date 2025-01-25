#include "../inc/so_long_bonus.h"

int	player_idle(t_game *game)
{
	int x;
	int y;

	y = game->player_p.y;
	x = game->player_p.x;

	if (game->data.loop < 250000)
	{
		game->data.loop++;
		return (0);
	}
	game->data.loop = 0;
	animation_idle(game, x, y);
	return (0);
}

void	animate_death(t_game *game, int x, int y)
{
	image_render(game, &game->bg, "./img/floor.xpm", game->player_p.y * 64, game->player_p.x * 64);
	image_render(game, &game->bg, "./img/death/00.xpm", y * 64, x * 64);
	image_render(game, &game->bg, "./img/floor.xpm", y * 64, x * 64);
	usleep(300000);
	image_render(game, &game->bg, "./img/death/01.xpm", y * 64, x * 64);
	image_render(game, &game->bg, "./img/floor.xpm", y * 64, x * 64);
	usleep(300000);
	image_render(game, &game->bg, "./img/death/02.xpm", y * 64, x * 64);
	image_render(game, &game->bg, "./img/floor.xpm", y * 64, x * 64);
	usleep(300000);
	image_render(game, &game->bg, "./img/death/03.xpm", y * 64, x * 64);
	image_render(game, &game->bg, "./img/floor.xpm", y * 64, x * 64);
	usleep(300000);
	exit_game(game, 4);
}

void	render_number(t_game *game, char *file, int x, int y)
{
	game->img.xpm = mlx_xpm_file_to_image(game->mlx, file, &game->data.tile_size, &game->data.tile_size);
	game->img.img = mlx_new_image(game->mlx, game->data.tile_size, game->data.tile_size);
	mlx_put_image_to_window(game->mlx, game->window, game->img.xpm, x, y);
	if (game->img.xpm)
	{
		mlx_destroy_image(game->mlx, game->img.xpm);
		game->img.xpm = 0;
	}
	mlx_destroy_image(game->mlx, game->img.img);
}

void	nbr_of_moves(t_game *game)
{
	int i;
	int digit;
	int moves;
	game->moves++;
	moves = game->moves;
	i = 0;
	while (i < 6)
	{
		digit = moves % 10;
		moves = moves / 10;
		//esta merda 'e makumba'
		if (game->map.width % 2 != 0)
			render_number(game, game->nbr[digit], (game->map.width / 2 * 64 + 94) - i * 64, (game->map.height) * 64);
		else
			render_number(game, game->nbr[digit], (game->map.width / 2 * 64 + 94) - i * 64, (game->map.height) * 64);
	i++;
	}
}

