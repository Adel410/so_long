# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 13:55:35 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/06/27 12:49:08 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### ARGUMENTS

NAME	= 	so_long

SRCS	=	./srcs/main.c \
			./srcs/ft_utils.c \
			./srcs/ft_utils2.c \
			./srcs/ft_check_map.c \
			./srcs/ft_error.c \
			./srcs/get_next_line.c \
			./srcs/get_next_line_utils.c \
			./srcs/ft_data_map.c \
			./srcs/ft_check_close.c \
			./srcs/ft_display.c \
			./srcs/ft_floodfill.c \
			./srcs/ft_move.c \
			./srcs/ft_animation.c \
			./ft_printf/ft_printf.c \
			./ft_printf/ft_putchar.c \
			./ft_printf/ft_putnbr.c \
			./ft_printf/ft_putnbr_hexa.c \
			./ft_printf/ft_putstr.c \
			
INCLUDE =  include/so_long.h

OBJS 		= ${SRCS:.c=.o}

LIBS        = -L./mlx -lmlx_Linux -lXext -lX11 -lm -lz

MLX			= mlx/libmlx_linux.a

CC			= cc

CFLAGS		= -Wall -Werror -Wextra 

################################################################################
### RULES

all	: ${NAME}

$(NAME) : $(MLX) $(OBJS) $(INCLUDE)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

${MLX}	: 
	git clone https://github.com/42Paris/minilibx-linux.git mlx
	make -C mlx
	
clean	:
		rm -f ${OBJS}

fclean	:
		rm -rf mlx
		rm -f ${OBJS} ${NAME}

re	: fclean all

.PHONY : all fclean clean re