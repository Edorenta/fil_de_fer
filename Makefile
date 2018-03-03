# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:43:59 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/03 18:10:07 by pde-rent         ###   ########.fr        #
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
LIBS		= $(LIBMLX) libft/libft.a libclr/libclr.a
#-Llibft/ -lft -Llibclr/ -llr

SRC_SUFFIX  = .c
#SRC_PREFIX =
SRC_RAW     =   main			init			drawing_toolbox			\
				sketch			txt_parser		utilities				\
				error_handle	print_ui		map_matrix				\
				arrow_move		zoom_move		rot_move				\
				depth_move		color_range		key_management			\
				color_filler	

#SRC_RAW2   = $(addprefix ${SRC_PREFIX},${SRC_RAW})
SRC_FILES   = $(addsuffix $(SRC_SUFFIX),$(SRC_RAW))
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
OK			= " $(CYAN)$(CHECK)$(WHITE)"

all : $(NAME)

$(NAME) : build_libs $(OBJ)
	@$(CC) $(LIB) $(OBJ) -o $(NAME)

build_libs :
	@$(MAKE) -C libft/
	@$(MAKE) -C libclr/
	@$(MAKE) -C $(MLX_PATH)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INCLUDE) -o $@ -c $<

clean :
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(MLX_PATH) clean
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Minilibx cleaned\t$(OK)\n"
	@$(MAKE) -C libft/ clean
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Libft cleaned\t$(OK)\n"

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(MLX_PATH) clean
	@rm -f $(MLX_PATH)libmlx.a
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Minilibx binaries erased\t$(OK)\n"
	@$(MAKE) -C libft/ fclean
	@printf "$(UP2)\r$(EOLCLR)""$(MV)Libft binaries erased\t$(OK)\n"

re : fclean $(NAME)
	@printf "$(UP9)\r$(EOLCLR)""$(GREEN)Project successfully re-compiled\t$(OK)\n"

norm : norm_fdf norm_lib

norm_fdf :
	@norminette srcs/ include/

norm_lib :
	@norminette libft/srcs/ libft/include/

.PHONY : all build_libs clean fclean re norm
