/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:15:39 by palexand          #+#    #+#             */
/*   Updated: 2024/12/28 01:15:42 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	exit_game(t_game *game, int status)
{
	if (status == 1)
	{
		ft_printf(GREEN"\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
"RESET);
	}
	if (status == 2)
		ft_printf(RED"\n ERROR\n MAP NOT VALID OR 404\n\n"RESET);
	if (status == 3)
		ft_printf(RED"\n ERROR \n WRONG MAP ELEMENTS\n\n"RESET);
	else
		ft_printf(RED"\n EXITING GAME\n\n"RESET);
	free_stacks(game);
	exit(EXIT_SUCCESS);
}

int	kill_game(t_game *game)
{
	exit_game(game, 0);
	return (0);
}

void	free_stacks(t_game *game)
{
	if (game->map.matrix && game->map.mtx)
	{
		free_map(game);
		free(game->map.matrix);
		free(game->map.mtx);
	}
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.matrix[i])
	{
		free(game->map.matrix[i]);
		i++;
	}
	i = 0;
	while (game->map.mtx[i])
	{
		free(game->map.mtx[i]);
		i++;
	}
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->i_exit);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	(void)game;
}
