NAME = minishell

SRCS = srcs/main.c \
		srcs/utils/gnl.c \
		srcs/utils/main_utils.c \
		srcs/utils/handling_signals.c \
		srcs/utils/memory_free.c \
		srcs/read_input/read_line.c	\
		srcs/parser/parser.c \
		srcs/parser/parse_util.c \
		srcs/parser/lexer_1.c \
		srcs/parser/lexer_2.c \
		srcs/parser/token_checker.c \
		srcs/parser/conversion_normal_token.c \
		srcs/parser/conversion_sq_token.c \
		srcs/parser/conversion_dq_token.c \
		srcs/parser/conversion_dq_token_backslash.c \
		srcs/parser/conversion_dq_token_env.c \
		srcs/parser/conversion_dq_token_env_util.c \
		srcs/parser/conversion_env_token.c \
		srcs/parser/init_cmd_list.c \
		srcs/parser/init_cmd_list_util.c \
		srcs/linked_list/linked_list.c \
		srcs/error/fatal_error.c \
		srcs/error/token_error.c \
		srcs/execute/execute_cmd.c \
		srcs/execute/execute_util.c \
		srcs/execute/redirection.c \
		srcs/execute/redirection_util.c \
		srcs/builtin/ft_echo.c \
		srcs/builtin/ft_cd.c \
		srcs/builtin/ft_pwd.c \
		srcs/builtin/ft_export.c \
		srcs/builtin/ft_unset.c \
		srcs/builtin/ft_env.c \
		srcs/builtin/ft_exit.c \
		srcs/utils/env_utils.c \
		srcs/utils/utils.c \
		# srcs/debugging/debugging.c

LIBFT = libft.a

LIBS = -L./libft -lft

HEADER = -I./incs

CFLAG = -Wall -Werror -Wextra

CC = gcc

RM = rm -rf

DEBUG = -g -fsanitize=address

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAG) $(HEADER) -o $@ -c $<

all : $(NAME)

$(LIBFT) :
	@$(MAKE) -C ./libft

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(SRCS) $(LIBS) $(HEADER) $(CFLAG) $(DEBUG) -o $(NAME)

clean :
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re libft
