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
	MLX_PATH= minilibx_macos/
    LIBMLX	= -framework OpenGL -framework AppKit -Lminilibx_macos -lmlx
	INCLUDES= -Iinclude -Iminilibx_macos -Ilibft/include -Ilibclr/include

else
	LIBMLX	= -lGL -Lminilibx_linux -lmlx -lXext -lX11
	INCLUDES= -Iinclude -Iminilibx_linux -Ilibft/include -Ilibclr/include
endif
LIBS		= $(LIBMLX) -lm -Llibclr -lclr -Llibft -lft
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
EOLCLR		= "\\033[0K"
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

all: directory $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(MAKE) -C libft/
	@$(MAKE) -C libclr/
	@$(MAKE) -C $(MLX_PATH)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)


directory: $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) -c $< $(INCLUDES) -o $@

clean :
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(MLX_PATH) clean
#	@printf "$(UP2)\r$(EOLCLR)""$(MV)Minilibx cleaned\t$(OK)\n"
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C libclr/ clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(MLX_PATH) clean
#	@rm -f $(MLX_PATH)libmlx.a
#	@printf "$(UP2)\r$(EOLCLR)""$(MV)Minilibx binaries erased\t$(OK)\n"
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C libclr/ fclean

re : fclean $(NAME)

norm : norm_fdf norm_lib

norm_fdf :
	@norminette srcs/ include/

norm_lib :
	@norminette libft/srcs/ libft/include/

.PHONY : all build_libs clean fclean re norm
