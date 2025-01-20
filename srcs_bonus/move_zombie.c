#include "../inc/so_long_bonus.h"

static void	zombie_up(t_game *game, int enemies, int *x, int *y)
{
	/* its zero */
	printf("Zombie[%d][%d]\n", x[enemies], y[enemies]); 
	if (game->map.mtx[x[enemies] + 1][y[enemies]] == '1' 
		|| game->map.mtx[x[enemies] + 1][y[enemies]] == 'E'
		|| game->map.mtx[x[enemies] + 1][y[enemies]] == 'X'
		|| game->map.mtx[x[enemies] + 1][y[enemies]] == 'C')
			return ;
	game->map.mtx[x[enemies]][y[enemies]] = '0';
	zombie_up_animate(game, enemies);
	game->map.mtx[x[enemies]][y[enemies]] = 'X';
	printf("Zombie[%d][%d]\n", x[enemies], y[enemies]);
}

/*static void zombie_down(t_game *game, int enemies, int *x, int *y)*/
/*{*/
/*	if (game->map.mtx[x[enemies] - 1][y[enemies]] == '1' */
/*		|| game->map.mtx[x[enemies] - 1][y[enemies]] == 'E'*/
/*		|| game->map.mtx[x[enemies] - 1][y[enemies]] == 'X'*/
/*		|| game->map.mtx[x[enemies] - 1][y[enemies]] == 'C')*/
/*			return ;*/
/*	game->map.mtx[x[enemies]][y[enemies]] = '0';*/
/*	zombie_down_animate(game, enemies);*/
/*	game->map.mtx[x[enemies]][y[enemies]] = 'X';*/
/*}*/
/**/
/*static void zombie_left(t_game *game, int enemies, int *x, int *y)*/
/*{*/
/*	if (game->map.mtx[x[enemies]][y[enemies] - 1] == '1' */
/*		|| game->map.mtx[x[enemies]][y[enemies] - 1] == 'E'*/
/*		|| game->map.mtx[x[enemies]][y[enemies] - 1] == 'X'*/
/*		|| game->map.mtx[x[enemies]][y[enemies] - 1] == 'C')*/
/*			return ;*/
/*	game->map.mtx[x[enemies]][y[enemies]] = '0';*/
/*	zombie_left_animate(game, enemies);*/
/*	game->map.mtx[x[enemies]][y[enemies]] = 'X';*/
/*}*/
/**/
/*static void zombie_right(t_game *game, int enemies, int *x, int *y)*/
/*{*/
/*	if (game->map.mtx[x[enemies]][y[enemies] + 1] == '1' */
/*		|| game->map.mtx[x[enemies]][y[enemies] + 1] == 'E'*/
/*		|| game->map.mtx[x[enemies]][y[enemies] + 1] == 'X'*/
/*		|| game->map.mtx[x[enemies]][y[enemies] + 1] == 'C')*/
/*			return ;*/
/*	game->map.mtx[x[enemies]][y[enemies]] = '0';*/
/*	zombie_right_animate(game, enemies);*/
/*	game->map.mtx[x[enemies]][y[enemies]] = 'X';*/
/*}*/
/**/
void	move_enemy(t_game *game, int enemies)
{
	int *x;
	int *y;
	int n(void);
	enemies = game->data.enemies;
	x = game->map.enemy_x;
	y = game->map.enemy_y;
	printf("is it wrking\n");
	zombie_up(game, enemies, x, y);	
	/*n = (rand() % 4) + 1;*/
	/*if (n == 1)*/
	/*	zombie_up(game, enemies, x, y);*/
	/*if (n == 2)*/
	/*	zombie_down(game, enemies, x, y);*/
	/*if (n == 3)*/
	/*	zombie_left(game, enemies, x, y);*/
	/*if (n == 4)*/
	/*	zombie_right(game, enemies, x, y);*/
	/*if (x[enemies] == game->player_p.x && y[enemies] == game->player_p.y)*/
	/*	animate_death(game, x[enemies], y[enemies]);*/
}

