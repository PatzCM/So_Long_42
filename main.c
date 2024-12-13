#include "so_long.h"

int	main (int argc, char **argv)
{
	char *file = argv[1];
	if (argc == 2)
	{
		char **mtx =	matrix(file);
		validate_ber(argv[0]);
		validate_shape(mtx);
	}
}

