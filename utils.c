#include "so_long.h"

int	key_code(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

void move_up(t_game *game)
{
	if (game->map.mtx[game->player_p.x - 1][game->player_p.y] == '1')
		return ; 
	/*else	*/
	/*	move(game, game->player_p.x - 1, game->player_p.y);	*/
	move(game, game->player_p.x - 1, game->player_p.y);
}

void	move_left(t_game *game)
{
	if (game->map.mtx[game->player_p.x][game->player_p.y - 1] == '1')
		return ;
	else
		move(game, game->player_p.x, game->player_p.y - 1);
}

void	move_down(t_game *game)
{
	if (game->map.mtx[game->player_p.x + 1][game->player_p.y] == '1')
		return ;
	else
		move(game, game->player_p.x + 1, game->player_p.y);
}

void	move_right(t_game *game)
{
	if (game->map.mtx[game->player_p.x][game->player_p.y + 1] == '1')
		return ;
	else
		move(game, game->player_p.x, game->player_p.y + 1);
}

int	move(t_game *game, int to_x, int to_y)
{
	static int moves = 1;
	
	if (game->collectibles == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->exit_img, game->player_p.y_end * 64, game->player_p.x_end * 64);	
	}
	if (game->map.mtx[to_x][to_y] == 'E' && game->collectibles == 0)
	{
		ft_printf("You win\n: %d\n", game->moves);
		exit(EXIT_SUCCESS);
	}
		if (game->map.mtx[to_x][to_y] == 'C')
	{
		game->map.mtx[to_x][to_y] = '0';
		game->collectibles--;
		ft_printf("Collectibles[%d]\n", game->collectibles);
	}
	if (game->map.mtx[to_x][to_y] == 'E' && game->collectibles > 0)
	{
		ft_printf("You need to collect all the collectibles\n");
		return (1);
	}
	if (to_x == 1 && to_y == 1)
		mlx_put_image_to_window(game->mlx, game->window, game->corner_top_left, 1 * 64, 1 * 64);
	if (to_x == 1 && to_y < game->map.width)
		mlx_put_image_to_window(game->mlx, game->window, game->middle_top, to_y * 64, 1 * 64);
	if (to_x == 1 && to_y == game->map.width)
		mlx_put_image_to_window(game->mlx, game->window, game->corner_top_right, game->map.width * 64, 1 * 64);
	else 
	{
		mlx_put_image_to_window(game->mlx, game->window, game->floor, game->player_p.y * 64, game->player_p.x * 64);
	}
	game->player_p.x = to_x;
	game->player_p.y = to_y;
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, game->player_p.y * 64, game->player_p.x * 64);
	printf("Number of moves[%d]\n", moves++);
	return (0);
}
