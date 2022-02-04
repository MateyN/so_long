SRCS	= srcs/main.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/check_map.c srcs/error_handle.c srcs/map.c srcs/movements.c srcs/draw_map.c srcs/utils.c
NAME 	= so_long

all:	${NAME}

${NAME}:
	gcc -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit ${SRCS} -o so_long

clean:
	rm -f so_long

fclean:	clean

re:	fclean all