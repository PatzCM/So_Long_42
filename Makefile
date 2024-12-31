# Created by: Patricia Monteiro
# Makefile for the so_long project

# Define the header of the project
# info: header

define HEADER
┌───────────────────────────────────────────────────────────────────────────────┐
│                                                                               │
│   oooooooo8                   ooooo                                           │
│  888           ooooooo         888          ooooooo  oo oooooo     oooooooo8  │
│   888oooooo  888     888       888        888     888 888   888  888    88o   │
│          888 888     888       888      o 888     888 888   888   888oo888o   │
│  o88oooo888    88ooo88        o888ooooo88   88ooo88  o888o o888o 888     888  │
│                                                                   888ooo888   │
│                                                                               │
└───────────────────────────────────────────────────────────────────────────────┘
endef
export HEADER


# Colors
NO_COLOR = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m

# Name of the executable
NAME = so_long

BONUS = so_long_bonus

INCLUDES = -I./include -Imlx

# Source files

SRCS = srcs/main.c\
			 srcs/parsing.c\
			 srcs/windows.c\
			 srcs/pathing.c\
			 srcs/counters.c\
			 srcs/render.c\
			 srcs/utils.c\
			 srcs/free.c\

SRCS_BONUS = srcs_bonus/main_bonus.c\
						 srcs_bonus/parsing_bonus.c\
						 srcs_bonus/windows_bonus.c \
						 srcs_bonus/pathing_bonus.c\
						 srcs_bonus/counters_bonus.c\
						 srcs_bonus/render_bonus.c\
						 srcs_bonus/utils_bonus.c\
						 srcs_bonus/free_bonus.c\
						 srcs_bonus/move_animation.c\

OBJS = $(SRCS:.c=.o)
B_OBJS = $(SRCS_BONUS:.c=.o)

# Compiler and flags
CC = cc -g
CFLAGS = -Wall -Wextra -Werror  
LIBS = ./libs/libft.a
RM = rm -f
AR = ar rcs

# Link X11 and mlx libraries
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Rules

all: deps $(NAME)

deps:
	make -C ./libs
	@echo	"$(CYAN)$$HEADER \n $(GREEN)Dependencies done!$(NO_COLOR)"

$(NAME): $(OBJS)
	$(MAKE) -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBS) -o $(NAME)
	@echo	"$(CYAN)$$HEADER \n $(GREEN)Compilation done!$(NO_COLOR)"

clean:
	rm -f $(OBJS) $(B_OBJS)
	$(MAKE) -C mlx clean
	$(MAKE) -C ./libs clean
	@echo	"$(YELLOW)Cleaning done!$(NO_COLOR)"

fclean: clean
	rm -f $(NAME) $(BONUS) 
	$(MAKE) -C mlx clean
	$(MAKE) -C ./libs fclean
	@echo "$(YELLOW)Cleaning done!$(NO_COLOR)"

re: fclean all

bonus: $(B_OBJS)
	$(MAKE) -C mlx
	$(MAKE) -C ./libs
	$(CC) $(CFLAGS) $(B_OBJS) $(MLX_FLAGS) $(LIBS) -o $(BONUS)
	@echo	"$(CYAN)$$HEADER \n $(GREEN)BONUS READY!$(NO_COLOR)" 

header:
	clear
	@echo	"$$HEADER"

.PHONY: all clean fclean re
