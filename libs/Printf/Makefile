# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 16:05:38 by palexand          #+#    #+#              #
#    Updated: 2024/11/08 16:05:40 by palexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## FILES ##
SRCS = ft_printf.c ft_unbr_printf.c ft_pointer_printf.c ft_hexa_printf.c ft_nbr_printf.c \
			 ft_str_printf.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
			 libft/ft_putnbr_fd.c libft/ft_strlen.c 
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

## ALIAS ##

RM = rm -f
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft/
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS) $(LIBFT)

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR)
	
%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

clean: 
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all
#To not allow overlap of rules
.PHONY: re fclean clean all deps 

