#include "so_long.h"

int	main(int argc, char **argv)
{
	char			*file;
	int				collectives;
	char			**mtx;
	t_matrix		mtx2;
	file = argv[1];
	collectives = 0;
	if (argc == 2)
	{
		mtx = matrix(file, mtx2);
		ft_printf("Matrix is allocated\n");
		validate_ber(argv[1]);
		ft_printf("Ber is validated\n");
		validate_shape(mtx);
		ft_printf("Shape is validated\n");
		collectives = number_of_elements(mtx, collectives);
		if (collectives < 0)
			exit(EXIT_FAILURE);
		ft_printf("Number of elements is %d\n", collectives);
	}
}
