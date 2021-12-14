# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 14:04:07 by pprussen          #+#    #+#              #
#    Updated: 2021/12/14 21:46:18 by pprussen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_eval_specs.c  \
	ft_handle_str.c \
	ft_handle_decimal.c \
	ft_itoa_with_sign.c \
	ft_helpers.c \
	ft_handle_udecimal.c \
	ft_uitoa.c \
	ft_handle_hex.c \
	ft_ultohex.c \
	ft_handle_char.c \
	ft_handle_p.c

OBJS = ${SRCS:.c=.o}

CC = clang

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	@make  -C ./libft
	@cp libft/libft.a $(NAME)
	@ar -rcs ${NAME} ${OBJS}

all: ${NAME}

re: fclean all

bonus: all

test: all
	@${CC} -g main.c libftprintf.a libft/libft.a
	@make clean

test_run : test
	@./a.out
	@make fclean

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}
	@rm -f ${BOBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}
	@rm a.out

.PHONY: all, bonus, clean, fclean, re
