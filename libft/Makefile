# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 02:57:04 by pde-rent          #+#    #+#              #
#    Updated: 2017/11/30 18:37:30 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libft.a

CC    = gcc

FLAGS = -Wall -Wextra -Werror

HDDIRS= -I includes/

SRC   = ft_swap.c \
		ft_bzero.c \
		ft_print_bits.c \
		ft_to{lower,upper}.c \
		ft_str{lower,upper}.c \
		ft_{atoi,atoi_base,itoa,itoa_base}.c \
		ft_{abs,pow,fibo,sqrt,fact,rand,gcd}.c \
		ft_str{dup,new,equ,nequ,iter,iteri,len}.c \
		ft_str{map,mapi,trim,split,clr,del,sub,rev}.c \
		ft_str{str,nstr,chr,rchr,cmp,ncmp,cspn,tok}.c \
		ft_str{cat,ncat,lcat,cpy,ncpy,join,joinfree}.c \
		ft_array{min,max,mean,median,sort,rev,print}.c \
		ft_mem{alloc,dup,ccpy,chr,cmp,cpy,del,move,set}.c \
		ft_is{alnum,alpha,ascii,digit,prime,print,operator}.c \
		ft_lst{add,del,delone,delif,find,iter,iterif,map,new}.c \
		ft_put{char,char_fd,endl,endl_fd,nbr,nbr_fd,nbr_base,str,str_fd}.c \
		ft_lst{clr,at,last,merge,pusharg,pushback,pushfront,rev,size,sort}.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):

	$(CC) $(FLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#.PHONY: all clean fclean re
