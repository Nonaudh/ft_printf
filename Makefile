# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahuge <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 13:54:46 by ahuge             #+#    #+#              #
#    Updated: 2023/11/14 17:47:58 by ahuge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SOURCES = ft_printf.c ft_lenght.c

all : $(NAME)

OBJECTS = $(SOURCES:.c=.o)


$(NAME) : $(NAME) $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean all re

