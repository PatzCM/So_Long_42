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

/*void	animate_zombie(t_game *game)*/
/*{*/
/*	game->map.mtx[]*/
/*}*/
/**/
void	zombie_up_animate(t_game *game, int enemies)
{
	int floor;
	printf("Zombie[%d][%d]\n", game->map.enemy_x[enemies], game->map.enemy_y[enemies]);
	floor = game->map.enemy_y[enemies];
	image_render(game, &game->bg, "./img/floor.xpm", game->map.enemy_x[enemies] * SIZE, floor * SIZE);
	game->map.enemy_y[enemies] -= 1;
	usleep(300000);
	image_render(game, &game->bg, "./img/zu/00.xpm", game->map.enemy_x[enemies] * SIZE, game->map.enemy_y[enemies] * SIZE + (SIZE / 4) * 3);
	image_render(game, &game->bg, "./img/floor.xpm", game->map.enemy_x[enemies] * SIZE, floor * SIZE);
	usleep(300000);
	image_render(game, &game->bg, "./img/zu/01.xpm", game->map.enemy_x[enemies] * SIZE, game->map.enemy_y[enemies] * SIZE + (SIZE / 4) * 2);
	image_render(game, &game->bg, "./img/floor.xpm", game->map.enemy_x[enemies] * SIZE, game->map.enemy_y[enemies] * SIZE + (SIZE / 4) * 3);
	usleep(300000);
	image_render(game, &game->bg, "./img/zu/02.xpm", game->map.enemy_x[enemies] * SIZE, game->map.enemy_y[enemies] * SIZE + (SIZE / 4));
	image_render(game, &game->bg, "./img/floor.xpm", game->map.enemy_x[enemies] * SIZE, game->map.enemy_y[enemies] * SIZE + (SIZE / 4));
	usleep(300000);
	image_render(game, &game->bg, "./img/zu/03.xpm", game->map.enemy_x[enemies] * SIZE, game->map.enemy_y[enemies] * SIZE);

}

