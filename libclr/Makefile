# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 02:57:04 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/03 00:07:21 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libclr.a
SRC_PATH	= srcs/
OBJ_PATH	= objs/
FLAGS		= -Wall -Werror -Wextra
CC			= gcc $(FLAGS)
NAME_P		= $(shell echo $(NAME) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRC_SUFFIX	= .c
#SRC_PREFIX	= 
SRC_RAW		=	color_mod		hex_to_rgba		rgba_to_hex		\
				parse_color

#SRC_RAW2	= $(addprefix ${SRC_PREFIX},${SRC_RAW})
SRC_FILES	= $(addsuffix $(SRC_SUFFIX),$(SRC_RAW))
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
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"
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

$(NAME) : obj_folder $(OBJ)
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"all binaries compiled\t"$(OK)'\n'
	@printf "[$(NAME_P)] running\t$(WHITE)ar rc $@$(WHITE)"
	@ar rc $(NAME) $(OBJ)
	@printf '\t\t'$(OK)'\n'
	@printf "[$(NAME_P)] running\t$(WHITE)ranlib $@$(WHITE)"
	@ranlib	$(NAME)
	@printf '\t\t'$(OK)'\n'
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

obj_folder :
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)[$(NAME_P)] compiling\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) -I./include -o $@ -c $<
	@printf '\t'$(OK)

clean :
	@printf "[$(NAME_P)] cleaning\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJ_PATH)
	@printf '\t\t'$(OK)'\n'

fclean : clean
	@printf "[$(NAME_P)] erasing\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t'$(OK)'\n'

re : fclean all

norm :
	@norminette srcs/ include/

.PHONY: all clean fclean re norm
