# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:43:59 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/02 18:27:48 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
SRC_PATH	= srcs/
OBJ_PATH	= objs/
FLAGS		= -Wall -Werror -Wextra -g
CC			= gcc $(FLAGS)
ifeq ($(shell uname -s), Darwin)
    LIBMLX	= -framework OpenGL -framework AppKit -Lminilibx_macos/ -lmlx
	MLX_PATH = minilibx_macos/
	INCLUDES = -Iminilibx_macos -Iinclude -Ilibft/include
else
	LIBMLX	= -lGL -Lminilibx11/ -lmlx -lXext -lX11
	MLX_PATH = minilibx11/
	INCLUDES = -Iminilibx11 -Iinclude -Ilibft/include
endif
LIBFT		= -Llibft/ -lft
SRC_FILES	= {}.c

OBJ_FILES	= $(SRC_FILES:.c=.o)
SRC			= $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ			= $(addprefix $(OBJ_PATH),$(OBJ_FILES))

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"

#command
BOLD		= "\\033[1m"
UP2			= "\\033[2A"
UP9			= "\\033[9A"
EOLCLR		= "\\033[K"
MV			= "\\033[1;30m"
#\033[<L>;<C>H puts the cursor at line L and column C
#\033[<N>A Move the cursor up N lines
#\033[<N>B Move the cursor down N lines
#\033[<N>C Move the cursor forward N columns
#\033[<N>D Move the cursor backward N columns
#\033[2J Clear the screen, move to (0,0)
#\033[K Erase to end of line
#\033[s Save cursor position
#\033[u Restore cursor position

#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(GRE)$(CHE)$(WHITE)"

all : $(NAME)

$(NAME) : libft mlx $(OBJ)
	@$(CC) $(LIB) $(OBJ) -o $(NAME)

libft :
	@$(MAKE) -C libft/

mlx :
	@$(MAKE) -C $(MLX_PATH)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -Iminilibx_macos -Iinclude -Ilibft/include -o $@ -c $<

clean :
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(MLX_PATH) clean
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Minilibx cleaned$(OK)\n"
	@$(MAKE) -C libft/ clean
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Libft cleaned$(OK)\n"

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(MLX_PATH) clean
	@rm -f $(MLX_PATH)libmlx.a
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Minilibx binaries erased$(OK)\n"
	@$(MAKE) -C libft/ fclean
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Libft binaries erased$(OK)\n"

re : fclean $(NAME)
	@printf "$(UP9)\r$(EOLCLR)""$(GREEN)Project successfully re-compiled$(OK)\n"

norm : norm_fdf norm_lib

norm_fdf :
	@norminette srcs/ include/

norm_lib :
	@norminette libft/srcs/ libft/include/

.PHONY : all libft mlx clean fclean re norm
