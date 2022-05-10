SRCS =	so_long.c\
			main.c

OBJS = ${SRCS:.c=.o}

PATH_MLX = minilibx-linux
CC = gcc 
CFLAGS = #-Wall -Wextra -Werror
RM = rm -f
NAME = so_long
FLAGS = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	make -C $(PATH_MLX)
	${CC} $(SRCS) $(FLAGS) -o $(NAME)

clean:
	make -C $(PATH_MLX) clean
	${RM} ${OBJS}

fclean: clean
	make -C $(PATH_MLX) clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re