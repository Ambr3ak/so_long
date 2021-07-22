# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 11:04:06 by abourdar          #+#    #+#              #
#    Updated: 2021/07/19 11:04:10 by abourdar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long

SRCS	= srcs/main.c \
			srcs/malloc_lst.c \
			srcs/parser.c \
			srcs/init.c \
			srcs/draw_all.c \
			srcs/utils.c \
			srcs/textures.c \
			srcs/handle_key.c \
			srcs/mlx_utils.c \
			srcs/render.c \
			srcs/draw_utils.c \
			./lib_cub/ft_strchr.c \
			./lib_cub/ft_strdup.c \
			./lib_cub/ft_substr.c \
			./lib_cub/ft_strjoin.c \
			./lib_cub/ft_strrchr.c \
			./lib_cub/get_next_line.c \
			./lib_cub/ft_strlen.c \
			./lib_cub/ft_putnbr_fd.c \
			./lib_cub/ft_putchar_fd.c \
			./lib_cub/ft_putstr_fd.c \
			./lib_cub/ft_lstclear.c \
			./lib_cub/ft_lstnew.c \
			./lib_cub/ft_lstadd_back.c \
			./lib_cub/ft_memset.c


OBJS= $(SRCS:.c=.o)

INC	=	-I inc -I ${MLX_D}

CC	=	clang

CFLAGS	=	-Wall -Werror -Wextra

MLX_D	=	mlx

.c.o	:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) :	${OBJS}
			make -C ${MLX_D}
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_D) -lX11 -lXext -lmlx -lm

clean	:	
			make clean -C mlx
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
