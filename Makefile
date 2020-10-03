# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/02 19:00:19 by seungmki          #+#    #+#              #
#    Updated: 2020/10/03 22:09:35 by seungmki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RFLAGS = rm -f

NAME = libft.a
SRCS = $(shell echo *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c libft.h
		$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME) : $(OBJS)
		ar cr $(NAME) $(OBJS)
			
clean :
		$(RFLAGS) $(OBJS)

fclean : clean
		$(RFLAGS) $(NAME)
			
re : fclean all

.PHONY : all clean fclean re
