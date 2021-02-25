NAME = Identifier

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp				\
	   Func.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo clean up!!

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
