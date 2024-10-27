# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 13:55:35 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/07/03 15:06:02 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### VARIABLES

CC			= cc

SRCS_DIR        = ./srcs
SRCS_BONUS_DIR  = ./srcsbonus
SRCS            = $(wildcard $(SRCS_DIR)/*.c)
SRCS_BONUS      = $(wildcard $(SRCS_BONUS_DIR)/*.c)
OBJS            = $(SRCS:.c=.o)
OBJS_BONUS      = $(SRCS_BONUS:.c=.o)
NAME            = so_long
NAME_BONUS      = so_long_bonus

FT_PRINTF_DIR   = ./ft_printf
FT_PRINTF_LIB   = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR         = ./mlx
MLX             = $(MLX_DIR)/libmlx.a

CFLAGS          = -Wall -Wextra -Werror
INCLUDE         = -I$(FT_PRINTF_DIR)/include -I$(MLX_DIR)
LIBS            = -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz


################################################################################
### RULES

all : $(NAME)

$(NAME) : $(FT_PRINTF_LIB) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDE) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(FT_PRINTF_LIB) $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(INCLUDE) -o $(NAME_BONUS)

$(FT_PRINTF_LIB) :
	make -C $(FT_PRINTF_DIR)

$(MLX) :
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	make -C $(MLX_DIR)

clean :
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(FT_PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	rm -rf $(MLX_DIR)
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(FT_PRINTF_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus