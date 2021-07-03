# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlyessa <jlyessa@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 18:54:14 by jlyessa           #+#    #+#              #
#    Updated: 2020/06/13 10:53:37 by jlyessa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_LIBFT = libft.a
LIBFT = ./libft
FLAGS = -Wall -Wextra -Werror

HEADER = includes/ft_printf.h

SRCS = srcs/ft_printf.c srcs/distributor.c srcs/write_p.c \
	srcs/putstr.c srcs/write_d.c srcs/width.c srcs/rigor.c \
	srcs/struct.c srcs/write_c.c srcs/write_s.c srcs/ft_itoa_base.c \
	srcs/write_x.c srcs/write_percent.c srcs/error.c
OBJ = ${SRCS:.c=.o}

all: libft_all $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I$(LIBFT) -c -o $@ $<

$(NAME): $(OBJ) $(HEADER)
	@cp $(LIBFT)/$(NAME_LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean: libft_clean
	@/bin/rm -f $(OBJ)

fclean: libft_fclean clean
	@/bin/rm -f $(NAME)

bonus: all

re: fclean all

test: all
	@gcc -g -O0 -Wall -Wextra main.c libftprintf.a -I includes

libft_all:
	@$(MAKE) -C $(LIBFT) all

libft_clean:
	@$(MAKE) -C $(LIBFT) clean

libft_fclean:
	@$(MAKE) -C $(LIBFT) fclean

norminette:
	@norminette srcs/*.c includes/*.h libft/*.c libft/*.h

.PHONY: all clean fclean re bonus norminette test libft_all libft_clean libft_fclean