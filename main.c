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

	game = NULL;
	game = malloc(sizeof(t_game));
	init_values(game);
	if (argc == 2)
		map_validation(argv[1], game);
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

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		exit(EXIT_FAILURE);
	player_position(mtx, player);
	return (player);
}

void	init_values(t_game *game)
{
	game = malloc(sizeof(t_game));
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
	game->floor = malloc(11 * sizeof(void *));
	game->map.width = 0;
	game->map.height = 0;
	game->map.matrix = NULL;
	game->map.mtx = NULL;
}
