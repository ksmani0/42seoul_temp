CC=gcc
CFLAGS=-Wall -Wextra -Werror
OBJ=ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_strchr.o \
ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_substr.o ft_tolower.o ft_toupper.o ft_strjoin.o ft_strmapi.o ft_strtrim.o ft_substr.o \
ft_split.o ft_putchar_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_strcmp.o ft_strchr_index.o ft_atoi_parse.o ft_max.o ft_min.o ft_wcharlen.o ft_wstrlen.o ft_strcat.o ft_strcpy.o ft_strncat.o ft_strncpy.o
BONUS = ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_lstsize.o ft_lstlast.o
OBJDIR=./objs/
AR=ar
ARFLAGS=rcs
NAME=libft.a

EXECOBJS=$(addprefix $(OBJDIR), $(OBJ))
EXECBONUS=$(addprefix $(OBJDIR), $(BONUS))

all: $(NAME)

$(NAME): $(EXECOBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(EXECOBJS) $(EXECBONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean:
	rm -f $(EXECOBJS) $(EXECBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
