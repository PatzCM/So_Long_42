#include "so_long.h"

void window_init(t_game *game)
{
	game->mlx = mlx_init();
	image_render(game);
	ft_printf("height[%d] width[%d]\n", game->map.height, game->map.width);
	game->window = mlx_new_window(game->mlx, (game->map.width * 64), (game->map.height * 64), WIN_TITLE);
	render_map(game);
	printf("before key_hook player[%d, %d]\n", game->player_p.x, game->player_p.y);
	mlx_key_hook(game->window, key_code, game);
	/*mlx_put_image_to_window(game->mlx, game->window, game->player_img, 100, 100);*/
	
	/*game->data.img = mlx_new_image(game->mlx, 1920, 1080);*/
	/*game->data.addr = mlx_get_data_addr(game->image, &game->data.bpp, &game->data.len, &game->data.endian);	*/
	/*pixel_put(game, 5, 5, 0x00FF0000);*/
	/*mlx_put_image_to_window(game->mlx, game->window, game->data.img, 0, 0);*/
	mlx_loop(game->mlx);
}

