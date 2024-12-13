#include "libft.h"

int	main (int argc, char **argv)
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		char *line;
		while ((line = get_next_line(fd)))
		{
			printf("%s\n", line);
			free(line);
		}
		close(fd);
	}
}
