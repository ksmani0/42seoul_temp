# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 19:00:19 by seungmki          #+#    #+#              #
#    Updated: 2021/07/02 19:35:42 by seungmki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phillo

CC := gcc
CFLAGS = -Wall -Wextra -Werror -lpthread
#CFLAGS = -Wall -Wextra -Werror -g
INCLUDE := -I./includes
AR := ar -rcs
RM := rm -rf
.SUFFIXES : .c .o

SRCS := main.c
OBJ_DIR := ./obj
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all : $(NAME)
	@echo "(つ ◕▽◕)つ checker, push_swap is complete! c(◕▽◕ c)"

$(NAME) : $(OBJS1) $(LIBFT_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS1) $(INCLUDE) $(LIBFT_DIR)/$(LIBFT) -o $(NAME1)
	@echo "(つ >_<)つ    checker has been created!    c(>_< c)"

$(OBJ_DIR)/%.o : ./%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) all -C $(LIBFT_DIR)
	@echo "(つ 0◇0)つ    libft.a has been created!    c(0◇0 c)"

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(RM) $(OBJ_DIR)/*.o

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@$(RM) $(NAME1) $(NAME2)

re : fclean all

.PHONY : all bonus clean fclean re