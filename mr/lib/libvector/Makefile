NAME	=	libvector.a
SRCS	=	vector1.c vector2.c vector3.c
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
