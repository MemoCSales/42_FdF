NAME	= fdf

#LIBFT
LIBFT_DIRECTORY  = ./libft/
LIBFT	= $(LIBFT_DIRECTORY)libft.a

# MINILIBX
# MINILIBX_DIRECTORY = ./mlx_linux/
# MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
#MINILIBX
MINILIBX_DIRECTORY = ./mlx_macos/
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

#SUPPORT FILES
SUPPORT_DIRECTORY = ./srcs/
SUPPORT = $(SUPPORT_DIRECTORY)/srcs.a

OBJ_DIR	= obj/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
# MLX_FLAGS = -L/usr/X11/lib -lX11 -lXext -lm
MLX_FLAGS = -L./mlx_macos -lmlx -framework OpenGL -framework AppKit



SRC = 	main.c \
		draw.c \
		fdf.c \
		map_data.c \
		points.c \
		utils.c \

all: $(NAME)

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))


$(LIBFT):
		make -C $(LIBFT_DIRECTORY)

$(SUPPORT):
		make -C $(SUPPORT_DIRECTORY)

$(MINILIBX):
		make -C $(MINILIBX_DIRECTORY)

$(NAME): $(OBJ) $(LIBFT) $(SUPPORT) $(MINILIBX)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(SUPPORT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
#			@echo "DO NOT FORGET TO UNCOMMENT THE CC FLAGS"

$(OBJ_DIR)%.o: %.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -I$(LIBFT_DIRECTORY) -I$(SUPPORT_DIRECTORY) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT_DIRECTORY)
		@make clean -C $(MINILIBX_DIRECTORY)
		@make clean -C $(SUPPORT_DIRECTORY)

fclean: clean
		@rm -f ./$(NAME)
		@rm -f ./$(LIBFT)
		@rm -f ./$(MINILIBX)
		@rm -f ./$(SUPPORT)

re: fclean all

.PHONY: all clean fclean re