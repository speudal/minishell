# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 11:05:24 by tduval            #+#    #+#              #
#    Updated: 2018/12/23 04:00:56 by tduval           ###   ########.fr        #
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
				built-ins/echo.c	\
				built-ins/cd.c

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	@gcc -c $< $(CFLAGS) $(INCLUDES) -o $@

$(LIBFT) :
	@$(MAKE) -C libft/

$(NAME) : $(LIBFT) $(OBJS)
	@gcc $(OBJS) libft/libft.a -o $(NAME)
	@echo "\x1b[36m[MINISHELL COMPILED]\x1b[0m"

clean :
	@$(MAKE) -C libft/ clean
	@echo "\x1b[33;01mminishell : cleaning...\x1b[0m"
	@rm -f $(OBJS)
	@echo "\x1b[32;01m[MINISHELL CLEANED]\x1b[0m"

fclean : clean
	@$(MAKE) -C libft/ fclean
	@echo "\x1b[33;01mminishell : fcleaning...\x1b[0m"
	@rm -f $(NAME)
	@echo "\x1b[32;01m[MINISHELL FCLEANED]\x1b[0m"

re : fclean all

.PHONY : fclean clean all re
