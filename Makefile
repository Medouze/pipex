# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:52:57 by mlavergn          #+#    #+#              #
#    Updated: 2024/11/14 16:13:43 by mlavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex
CC 		= gcc
CFLAGS 	= -Werror -Wall -Wextra -fsanitize=address
RM 		= rm -rf
SRCS 	= srcs/pipex.c srcs/pipex_utils.c libft/libft.a

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

.PHONY : all clean fclean re