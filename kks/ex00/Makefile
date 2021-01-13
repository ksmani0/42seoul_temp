SRCS	= ./srcs/

HEADER	= ./includes/

NAME	= megaphone

CFILE	= megaphone.cpp

GCC		= -Wall -Wextra -Werror

OFILE2	= $(CFILE:.cpp=.o)

all: $(NAME)

$(NAME): $(OFILE2)
	clang++ $(GCC) $(OFILE2) -o $(NAME)

clean:
	/bin/rm -f $(OFILE2)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
