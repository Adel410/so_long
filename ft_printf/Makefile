# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 16:07:16 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/06/10 15:44:39 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################################################
## ARGUMENTS

NAME 		= libftprintf.a

SRCS		= ./srcs/ft_printf.c \
       		  ./srcs/ft_putchar.c \
       		  ./srcs/ft_putnbr_hexa.c \
       		  ./srcs/ft_putstr.c \
       		  ./srcs/ft_putnbr.c

INCLUDE 	= -I./include

OBJS 		= ${SRCS:.c=.o}

CC 			= cc

FLAGS 		= -Wall -Werror -Wextra

######################################################################################################
## RULES

all		: ${NAME}
	
${NAME} : ${OBJS} 
	ar rcs ${NAME} ${OBJS} 

${OBJS}	: %.o: %.c
	${CC} ${FLAGS} ${INCLUDE} -c $< -o $@

clean 	: 
	rm -f ${OBJS}

fclean 	:
	rm -f ${OBJS} ${NAME}

re		: fclean all

.PHONY 	: all clean fclean re