# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:52:57 by mlavergn          #+#    #+#              #
#    Updated: 2024/11/04 16:58:46 by mlavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex
CC 		= gcc
CFLAGS 	= -Werror -Wall -Wextra -fsanitize=address
RM 		= rm -rf
SRCS 	= srcs/pipex.c ft_printf/libftprintf.a

$(NAME) :
	make all -C ft_printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_printf

clean :
	$(RM) $(NAME)
	make clean -C ft_printf

re : fclean all

.PHONY : all bonus clean fclean re