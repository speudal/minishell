# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 11:05:24 by tduval            #+#    #+#              #
#    Updated: 2018/12/23 03:47:35 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

INCLUDES	=	-I . -I libft/

CFLAGS		=	-Wall -Werror -Wextra -g

LIBFT		=	libft.a

SRCS		=	srcs/minishell.c	\
				srcs/hub.c			\
				srcs/get_path.c		\
				srcs/free_split.c	\
				srcs/act_prog.c		\
				built-ins/env.c		\
				built-ins/setenv.c	\
				built-ins/echo.c

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	gcc -c $< $(CFLAGS) $(INCLUDES) -o $@

$(LIBFT) :
	$(MAKE) -C libft/

$(NAME) : $(LIBFT) $(OBJS)
	gcc $(OBJS) libft/libft.a -o $(NAME)

clean :
	$(MAKE) -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft/ fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all

.PHONY : fclean clean all re
