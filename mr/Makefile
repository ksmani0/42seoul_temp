NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

FILES	=	minirt.c \
			parse.c \
			parse_meta.c \
			parse_elements.c \
			parse_utils.c \
			parse_utils2.c \
			render.c \
			render_utils.c \
			camera.c \
			mlx_utils.c \
			sphere_intersection.c \
			intersections.c \
			cylinder_intersection.c \
			light.c \
			color.c \
			error_handling.c \
			wrapper.c \
			save_bmp.c \
			rotate.c \
			translate.c

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

FLAGS = -L $(LIB)ft_printf -lftprintf -L $(LIB)libvector -lvector 

MACOS_MACRO = -D MACOS

MACOS_FLAGS	= -lmlx -framework OpenGL -framework AppKit

CFLAGS += $(MACOS_MACRO)

FLAGS += $(MACOS_FLAGS)

MLXNAME	= libmlx.dylib

${NAME}:	${OBJS} ${MLXNAME}
			make -C $(LIB)libvector
			make -C $(LIB)ft_printf
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o $@ ${MLXNAME}


.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${MLXNAME}:
			make -C $(LIB)minilibx_mms_20200219
			cp $(LIB)minilibx_mms_20200219/$@ $@

clean:
			make clean -C $(LIB)minilibx_mms_20200219
			make clean -C $(LIB)libvector
			make clean -C $(LIB)ft_printf
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)libvector
			make fclean -C $(LIB)ft_printf
			${RM} ${NAME} ${MLXNAME}

re:			fclean all

bonus:		${NAME}

PHONY:		all clean fclean re bonus