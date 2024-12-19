# Created by: Patricia Monteiro
# Makefile for the so_long project

NAME = so_long

INCLUDES = -I./include -Imlx

# Source files

SRCS = main.c parsing.c windows.c pathing.c counters.c render.c utils.c\

OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc -g
CFLAGS = -Wall -Wextra -Werror  
LIBS = libs/libft.a
RM = rm -f
AR = ar rcs

# Link X11 and mlx libraries
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Rules

deps:
	make -C ./libs

$(NAME): $(OBJS)
	$(MAKE) -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBS) -o $(NAME)

all: deps $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C mlx clean
	$(MAKE) -C ./libs clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C mlx clean
	$(MAKE) -C ./libs fclean

re: fclean all

.PHONY: all clean fclean re
