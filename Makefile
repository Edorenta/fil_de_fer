# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:43:59 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/02 23:17:46 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
NAME_P		= $(shell echo $(NAME) | tr ' ' '\n' |\
				sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRCS_PATH	= srcs/
OBJS_PATH	= objs/
I_PATH		= -I libft/include -I libclr/include -Iinclude
FLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
CC			= gcc $(FLAGS)
ifeq ($(shell uname -s), Darwin)
    LIBMLX	= -framework OpenGL -framework AppKit -Lminilibx_macos/ -lmlx
	MLX_PATH = minilibx_macos/
	INCLUDE  = -Iminilibx_macos $(I_PATH)
else
	LIBMLX	= -lGL -Lminilibx11/ -lmlx -lXext -lX11
	MLX_PATH = minilibx11/
	INCLUDE  = -Iminilibx11 $(I_PATH)
endif
LIBS		= $(LIBMLX) libft/libft.a libclr/libclr.a
#-Llibft/ -lft -Llibclr/ -llr

SRCS_SUFFIX  = .c
#SRCS_PREFIX =
SRCS_RAW     =   main			init			drawing_toolbox			\
				sketch			txt_parser		utilities				\
				error_handle	print_ui		map_matrix				\
				arrow_move		zoom_move		rot_move				\
				depth_move		color_range		key_management		

#SRCS_RAW2   = $(addprefix ${SRCS_PREFIX},${SRCS_RAW})
SRCS_FILES   = $(addsuffix $(SRCS_SUFFIX),$(SRCS_RAW))
OBJS_FILES	= $(SRCS_FILES:.c=.o)
SRCS			= $(addprefix $(SRCS_PATH),$(SRCS_FILES))
OBJS		= $(addprefix $(OBJS_PATH),$(OBJS_FILES))

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"

#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(CYAN)$(CHECK)$(WHITE)"
#\033[<L>;<C>H puts the cursor at line L and column C
#\033[<N>A Move the cursor up N lines
#\033[<N>B Move the cursor down N lines
#\033[<N>C Move the cursor forward N columns
#\033[<N>D Move the cursor backward N columns
#\033[2J Clear the screen, move to (0,0)
#\033[K Erase to end of line
#\033[s Save cursor position
#\033[u Restore cursor position

TRACKER		= .project_built
#MAKEFLAGS	+= -j #multitasking

all : $(NAME)

$(NAME) : $(OBJS)
	@printf "$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"dependencies compiled\t"$(OK)'\n'
	@$(CC) $(LIBS) $(OBJS) -o $(NAME)
	@printf "$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"project built\t\t"$(OK)'\n'

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c | $(TRACKER)
	@printf "$(EOLCLR)[$(NAME_P)] compiling\t$(BOLD)$(YELLOW)$<$(WHITE)\r"
	@$(CC) $(INCLUDE) -o $@ -c $<

%.c:
	@printf "$(RED)Missing file : $@$(WHITE)\n"

$(TRACKER): $(SRCS)
	@$(MAKE) -C libft/
	@$(MAKE) -C libclr/
	@$(MAKE) -C $(MLX_PATH)
	@touch $(TRACKER)
	@mkdir -p $(OBJS_PATH)

clean :
	@printf "[$(NAME_P)] cleaning\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJS_PATH)
	@rm -f $(TRACKER)
	@$(MAKE) -C $(MLX_PATH) clean
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C libclr/ clean
	@printf '\t\t'$(OK)'\n'

fclean :
	@rm -rf $(OBJS_PATH)
	@rm -f $(TRACKER)
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C libclr/ fclean
	@$(MAKE) -C $(MLX_PATH) clean
	@rm -f $(MLX_PATH)libmlx.a
	@printf "[$(NAME_P)] Minilibx binaries erased\t\t\t"$(OK)'\n'
	@printf "[$(NAME_P)] erasing\t\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t\t'$(OK)'\n'

re : fclean
	@$(MAKE) all

norm : norm_fdf norm_lib

norm_fdf :
	@norminette SRCSs/ include/

norm_lib :
	@norminette libft/SRCSs/ libft/include/ libclr/SRCSs/ libclr/include/

.PHONY : all clean fclean re norm norm_lib norm_fdf
