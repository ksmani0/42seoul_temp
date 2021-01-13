SRCS	= ./srcs/

HEADER	= ./includes/

NAME	= phonebook

CFILE	= phonebook.cpp main.cpp contact.cpp

GCC		= -Wall -Wextra -Werror

OFILE2	= $(CFILE:.cpp=.o)

all: $(NAME)

$(NAME): $(OFILE2)
	clang++ $(GCC) -I. $(OFILE2) -o $(NAME)

clean:
	/bin/rm -f $(OFILE2)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
