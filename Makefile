#Name
NAME 		= 	so_long

#Commands
CC			= 	gcc
DMK			=	mkdir -p
RM			=	rm -rf
AR			=	ar rc
MK			=	make -s -C

#Compilation flags
INCLUDES	=	-I$(H_DIR) -I$(LFT_DIR)includes -I$(MLX_DIR)
FLAGS		=	$(WFLAGS) $(MFLAGS)
WFLAGS		=	#-Wall -Werror -Wextra
MFLAGS		= 	-lmlx -L mlx -lXext -lX11 -lm -lz
OPT_FLAGS	=	-03
MEM_FLAGS	=	-g3 -fsanitize=address

#Directories
H_DIR		=	includes/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LFT_DIR		=	libft/
MLX_DIR		=	mlx/

#Libft
MK_LFT		=	$(MK) $(LFT_DIR)
LFT			=	$(LFT_DIR)libft.a

#MinilibX
MK_MLX		=	$(MK) $(MLX_DIR) > /dev/null 2>&1
MLX			=	$(MLX_DIR)libmlx_Linux.a

#Source files
SRC_FILES	=	so_long.c\
				sl_errors.c\
				sl_check_file.c\

OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#---------------------#

all:	${NAME}

libft:
			@echo -n "\n"
			@echo -n "COMPILING LIBFT..."
			@$(MK_LFT)
			@echo "\033[32m\t\t[OK]\033[0m\n"

mlx:
			@echo -n "\n"
			@echo -n "COMPILING MINILIBX..."
			@$(MK_MLX)
			@echo "\033[32m\t\t[OK]\033[0m\n"

$(NAME):	libft mlx $(OBJS)
			@echo -n "\n"
			@echo -n "COMPILING SO_LONG..."
			@$(CC) $(OBJS) $(LFT) -o $@ $(FLAGS) 
			@echo "\033[32m\t\t[OK]\033[0m\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@$(DMK) $(OBJ_DIR)
				@$(CC) -c  $(INCLUDES) $< -o $@ $(FLAGS)
clean:
	@$(MK_LFT) clean
	@$(MK_MLX) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(MLX) $(LFT)

re: fclean all

.PHONY: all libft mlx clean fclean re