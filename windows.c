#include "so_long.h"

void window_init(t_game *game)
{
	game->mlx = mlx_init();
	image_render(game);
	ft_printf("height[%d] width[%d]\n", game->map.height, game->map.width);
	game->window = mlx_new_window(game->mlx, (game->map.height * 128), (game->map.width * 128), WIN_TITLE);
	ft_printf("game->window\n");
	render_map(game);
	/*mlx_put_image_to_window(game->mlx, game->window, game->player_img, 100, 100);*/
	
	/*game->data.img = mlx_new_image(game->mlx, 1920, 1080);*/
	/*game->data.addr = mlx_get_data_addr(game->image, &game->data.bpp, &game->data.len, &game->data.endian);	*/
	/*pixel_put(game, 5, 5, 0x00FF0000);*/
	/*mlx_put_image_to_window(game->mlx, game->window, game->data.img, 0, 0);*/
	mlx_loop(game->mlx);
}

