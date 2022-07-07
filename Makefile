NAME = cub3D

SRCS = 	./sources/cub3d.c 						\
		./sources/free.c 						\
		./sources/execution/init_mlx.c 			\
		./sources/execution/dispay_screen.c 	\
		./sources/execution/mini_map.c 			\
		./sources/execution/minimap_utils.c 	\
		./sources/execution/geometry.c 			\
		./sources/execution/geometry_utils.c 	\
		./sources/execution/init_ray.c 			\
		./sources/execution/init_ray_loris.c 	\
		./sources/execution/player_action.c		\
		./sources/execution/mouvement.c			\
		./sources/execution/raycast.c			\
		./sources/parsing/init_game.c 			\
		./sources/utils.c 						\
		./sources/parsing/check_file.c 			\
		./sources/parsing/get_data_map.c 		\
		./sources/parsing/get_data_map_2.c 		\
		./sources/parsing/get_map.c				\
		./sources/parsing/check_map.c 			\
		./sources/parsing/check_open_map.c 		\
		./get_next_line/get_next_line.c 		\
		./get_next_line/get_next_line_utils.c 	\

OBJS = ${SRCS:.c=.o}

CC = gcc

LIBFT = ./libft/

MINILIBX = ./minilibx/

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

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