# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoukim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 02:48:44 by kyoukim           #+#    #+#              #
#    Updated: 2020/12/09 18:56:48 by kyoukim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NASM = nasm
FORMAT = -f macho64
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCS = .
ASMDIR = .
ASM = asm
AR = ar rc
RM = rm -f
SRCS = ./ft_strlen.s\
       ./ft_strcpy.s\
       ./ft_strcmp.s\
       ./ft_strdup.s\
       ./ft_write.s\
       ./ft_read.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.s.o:
	$(NASM) $(FORMAT) $< -o $@

test:
	$(CC) -I$(INCS) -L$(ASMDIR) -l$(ASM) -o result main.c
	./result > result.txt

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) result result.txt

re: fclean all

