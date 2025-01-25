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

#include "../inc/so_long.h"

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
}

void	map_validation(char *file, t_game *game)
{
	if (validate_ber(file) == -1)
		return (ft_printf((RED"\n\
ERROR ON FILE NAME\n\n\
"RESET)), exit_game(game, 0));
	game->map.matrix = matrix(file);
	game->map.mtx = matrix(file);
	if (!game->map.matrix)
		exit_game(game, 2);
	validate_shape(game->map.matrix, game);
	game->collectibles = number_of_elements(game->map.matrix,
			game->collectibles, game);
	if (game->collectibles < 0)
		exit_game(game, 3);
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
	game->collectibles = 0;
	game->exit = 0;
	game->player = 0;
	game->floor = NULL;
	game->wall = NULL;
	game->data.img = NULL;
	game->data.tile_size = SIZE;
	game->map.width = 0;
	game->map.height = 0;
	game->map.matrix = NULL;
	game->map.mtx = NULL;
}
