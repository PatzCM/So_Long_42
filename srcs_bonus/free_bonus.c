/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:15:39 by palexand          #+#    #+#             */
/*   Updated: 2024/12/28 01:15:42 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

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
		ft_printf(RED"\n ERROR VALIDATING MAP\n\n"RESET);
	if (status == 3)
		ft_printf(RED"\n ERROR COLLECTIBLES\n\n"RESET);
	if (status == 4)
		ft_printf(RED"\n\
__   __                _ _          _ _  \n\
\\ \\ / /               | (_)        | | | \n\
 \\ V /___  _   _    __| |_  ___  __| | | \n\
  \\ // _ \\| | | |  / _` | |/ _ \\/ _` | | \n\
  | | (_) | |_| | | (_| | |  __/ (_| |_| \n\
  \\_/\\___/ \\__,_|  \\__,_|_|\\___|\\__,_(_) \n\
																				 \n\n\
"RESET);
	else
		ft_printf(RED"\n EXITING GAME\n\n"RESET);
	free_stacks(game);
	exit(EXIT_SUCCESS);
}

void	free_stacks(t_game *game)
{
	ft_printf("Destroying stacks\n");
	if (game->map.matrix || game->map.mtx)
	{
		free_map(game);
		free(game->map.matrix);
		free(game->map.mtx);
	}
	if (game->map.enemy_x)
		free(game->map.enemy_x);
	if (game->map.enemy_y)
		free(game->map.enemy_y);
	if (game->nbr)
		free(game->nbr);
	if (game->bg.img)
		mlx_destroy_image(game->mlx, game->bg.img);
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
