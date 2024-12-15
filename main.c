#include "so_long.h"

int	main(int argc, char **argv)
{

	if (argc == 2)
		map_validation(argv[1]);
}

void	map_validation(char *file)
{
	t_matrix		*mtrx;
	t_game			*col;
		col = malloc(sizeof(t_game));
		mtrx = malloc(sizeof(t_matrix));
		mtrx->matrix = matrix(file);
		ft_printf("Matrix is allocated\n");
		validate_ber(file);
		ft_printf("Ber is validated\n");
		validate_shape(mtrx->matrix);
		ft_printf("Shape is validated\n");
		col->collectibles = number_of_elements(mtrx->matrix, col->collectibles);
		if (col->collectibles < 0)
			exit(EXIT_FAILURE);
		ft_printf("Number of elements is %d\n", col->collectibles);
		error_validation(mtrx->matrix, col, player_alloc(mtrx->matrix));
		/*ft_printf("Path is validated\n");*/
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

