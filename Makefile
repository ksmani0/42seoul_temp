CC = gcc
CFLAGS = -Wall -Wextra -Werror
RFLAGS = rm -f

NAME = libftprintf.a
LIBFT = libft

SRCS = ft_atoi.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) all -C ./$(LIBFT)/
		cp ./$(LIBFT)/$(LIBFT).a $(NAME)
		ar cru $(NAME) $(OBJS)

bonus : all

clean :
		$(MAKE) clean -C ./$(LIBFT)/
		$(RFLAGS) $(OBJS)

fclean : clean
		$(RFLAGS) ./$(LIBFT)/$(LIBFT).a
		$(RFLAGS) $(NAME)

re : fclean all

.PHONY : all $(LIBFT) bonus clean fclean re
