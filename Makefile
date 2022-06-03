NAME = cub3D

SRCS = ./sources/cub3d.c

OBJS = ${SRCS:.c=.o}

CC = gcc

LIBFT = ./libft/

MINILIBX = ./minilibx/

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ./includes/cub3d.h libft/libft.a Makefile/
		${CC} ${CFLAGS} -c $< -o $@

all:	libft ${NAME}

$(NAME): ${OBJS}
		make -C ${MINILIBX}
		${CC} ${CFLAGS} libft/libft.a -framework OpenGL -framework AppKit -o $@ $^ minilibx/libmlx.a

libft:
	make -C $(LIBFT)

clean:
		make clean -C ${MINILIBX}
		make clean -C ${LIBFT}
		${RM} ${OBJS}
 
fclean:	clean
		make fclean -C ${LIBFT}
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re libft