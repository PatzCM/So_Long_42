#include "../inc/so_long_bonus.h"

void	render_enemy(t_game *game)
{
	int i;
	t_map *m;
	m = &game->map;
	i = -1;
	while (++i < game->data.enemies)
	{
		image_render(game, &game->bg, "./img/z_idle/00.xpm", m->enemy_y[i] * game->data.tile_size, m->enemy_x[i] * game->data.tile_size);
		m->mtx[m->enemy_x[i]][m->enemy_y[i]] = 'X';
	}	
}

int	rand_enemies(t_game *game)
{
	int	x;
	int y;
	int enemies;
	int i = -1;

	game->data.enemies = game->zeros / 20;
	printf("enemies = %d\n", game->data.enemies);
	game->map.enemy_x = ft_calloc(game->data.enemies, sizeof(int ));
	game->map.enemy_y = ft_calloc(game->data.enemies, sizeof(int ));
	enemies = game->data.enemies;
		while (enemies > ++i)
	{
		y = 0;
		x = 0;
		while (game->map.mtx[y][x] != '\0' && game->map.mtx[y][x] != '0' )
		{
			y = rand() % (game->map.height );
			x = rand() % (game->map.width);
		}
		game->map.enemy_x[i] = y;
		game->map.enemy_y[i] = x;
	}
	return (1);
}

static int	moveability(t_game *game, int x, int y)
{
	if (game->map.mtx[x + 1][y] == '0')
		return (0);
	if (game->map.mtx[x - 1][y] == '0')
		return (0);
	if (game->map.mtx[x][y + 1] == '0')
		return (0);
	if (game->map.mtx[x][y - 1] == '0')
		return (0);
	return (1);
}

void	enemy_position(t_game *game, int moves)
{
	int enemies;
	int stuck;

	enemies = game->data.enemies;
	while (--enemies >= 0 && moves < game->moves)
	{
		while (moveability(game, game->map.enemy_x[enemies], game->map.enemy_y[enemies]))
		{
			enemies--;
			if (enemies < 0)
				return ;
		}
	}
	printf("enemies = %d\n", enemies);
	stuck = game->map.enemy_x[enemies] + game->map.enemy_y[enemies];
	move_enemy(game, enemies);
	if (stuck == game->map.enemy_x[enemies] + game->map.enemy_y[enemies])
		enemies++;
	printf("its working\n");
}

