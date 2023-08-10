# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 13:08:49 by mnoguera          #+#    #+#              #
#    Updated: 2023/08/04 16:52:26 by mnoguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Werror -Wextra
#L_FRAME = -Lmlx -lXext -lX11
L_FRAME = -Lmlx -lmlx -framework OpenGL -framework AppKit
INCLUDE = -MMD -I./ -I libft -I mlx

#source
SRCS = main.c new_structures.c fractal.c painting_utils.c complex_nums.c \
	   colors.c events.c events_utils.c guides.c

#objects
OBJS = $(SRCS:.c=.o)

#dependences
DEPS = $(SRCS:.c=.d)

#minilibx
MLX = mlx/libmlx.a

#libft
LIBFT = libft/libft.a

#colors
GREEN = \033[1;92m
RED = \033[1;91m
DEFAULT = \033[0m

%.o : %.c Makefile
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) -C mlx
	@$(MAKE) -C libft
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(MAKE) -C mlx
	@$(MAKE) -C libft
	@$(CC) $(OBJS) $(MLX) $(LIBFT) $(FLAGS) $(L_FRAME) -o $@
	@echo "$(GREEN)\nfractol compiled correctly :)\n$(DEFAULT)"

$(NAME)::
	@echo -n

-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@$(MAKE) clean -C mlx
	@$(MAKE) clean -C libft
	@echo "$(RED)\ndestroyed :P\n$(DEFAULT)"

fclean: clean
	@rm -f $(NAME) $(MLX) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
