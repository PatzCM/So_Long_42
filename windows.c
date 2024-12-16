#include "so_long.h"

void window_init(t_game *game)
{
	game->mlx = mlx_init();
	image_render(game);
	ft_printf("height[%d] width[%d]\n", game->map.height, game->map.width);
	game->window = mlx_new_window(game->mlx, (game->map.height * 128), (game->map.width * 128), WIN_TITLE);
	ft_printf("game->window\n");
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, 100, 100);
	
	/*game->data.img = mlx_new_image(game->mlx, 1920, 1080);*/
	/*game->data.addr = mlx_get_data_addr(game->image, &game->data.bpp, &game->data.len, &game->data.endian);	*/
	/*pixel_put(game, 5, 5, 0x00FF0000);*/
	/*mlx_put_image_to_window(game->mlx, game->window, game->data.img, 0, 0);*/
	mlx_loop(game->mlx);
}

void pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.addr + (y * game->data.len + x * (game->data.bpp / 8));
	*(unsigned int *)dst = color;
}

void	image_render(t_game *game)
{
	int x;

	x = 50;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./img/player_idle.xpm", &game->data.tile_size	, &game->data.tile_size);
	if (!game->player_img)
		exit(EXIT_FAILURE);
}

t_game	*data_init(t_game *game)
{
	return (game);
}
