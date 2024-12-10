# Created by: Patricia Monteiro
# Makefile for the so_long project

NAME = so_long

INCLUDES = -I./include -Imlx

OBJS = main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

# Link X11 and mlx libraries
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

$(NAME): $(OBJS)
	$(MAKE) -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
