/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:38:39 by palexand          #+#    #+#             */
/*   Updated: 2024/12/20 13:38:39 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	init_values(game);
	map_validation(argv[1], game);
	window_init(game);
	printf("Destroying images\n");
}

void	map_validation(char *file, t_game *game)
{
	game->map.matrix = matrix(file);
	game->map.mtx = matrix(file);
	validate_ber(file);
	validate_shape(game->map.matrix);
	game->collectibles = number_of_elements(game->map.matrix,
			game->collectibles, game);
	if (game->collectibles < 0)
		exit(EXIT_FAILURE);
	error_validation(game->map.matrix, player_alloc(game->map.matrix), game);
}

t_player	*player_alloc(char **mtx)
{
	t_player	*player;

	player = (t_player *)ft_calloc(sizeof(t_player), 1);
	if (!player)
		exit(EXIT_FAILURE);
	player_position(mtx, player);
	return (player);
}

void	init_values(t_game *game)
{
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
	game->wall = NULL;
	game->data.img = NULL;
	game->data.addr = NULL;
	game->data.bpp = 0;
	game->data.len = 0;
	game->data.endian = 0;
	game->data.tile_size = SIZE;
	game->map.width = 0;
	game->map.height = 0;
	game->map.matrix = NULL;
	game->map.mtx = NULL;
}
