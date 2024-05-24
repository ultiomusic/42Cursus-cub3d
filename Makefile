SRCS	= check.c check_map.c check_map_helper.c check_map_stars.c draw.c draw_helper.c draw_sp.c init.c init_helper.c init_helper2.c load.c main.c mlx_funcs.c move.c move_helper.c render.c split_new_lines.c texture.c utils.c wall_check.c
OBJS	= $(SRCS:.c=.o)

# Path: src/Makefile
NAME	= cub3D
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror  -g -o3 -fsanitize=address
RM		= rm -f
MLX		= ./mlx/libmlx.a
MLX_DIR	= ./mlx
LIBFT	= ./libft/libft.a
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -o $(NAME) 

$(LIBFT):
	make -j16 -C ./libft

$(MLX):
	make -j16 -C ./mlx 2> /dev/null

clean:
	$(RM) $(OBJS)
	make clean -C ./libft
	make clean -C ./mlx

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

shutup:
	killall afplay 2> /dev/null || true

.PHONY: all clean fclean re