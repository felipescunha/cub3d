CC = cc 
#-fsanitize=address 
NAME = cub3D
LIBFT_A	= libft.a
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE_L = -L ./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS =	src/main.c src/map/free_map.c src/map/copy_file.c src/map/copy_map.c src/map/read_map.c src/utils/print_error.c \
		src/validations/validation_map_name.c src/validations/validation_char.c \
		src/utils/split_comma.c src/validations/check_color_floor.c src/validations/check_color_ceiling.c \
		src/utils/ft_atoi_digit.c src/utils/ft_array_size.c src/utils/ft_free_array.c  \
		src/validations/check_ceiling_floor.c \
		src/map/get_range.c src/validations/validations.c

OBJS = $(SRCS:.c=.o)
LIBFT = make -C libft && cp libft/libft.a ./
CLIBFT = make -C libft clean
FCLIBFT = make -C libft fclean
MLX_L = make -C mlx_linux
CMLX_L = make -C mlx_linux clean

all: $(NAME) 

$(NAME):  $(OBJS)
	@$(MLX_L)
	@$(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE_L) $(LIBFT_A) -o $(NAME) 
	@echo "\033[1;32m ..::::: Cub3d Create  :::::.. \033[0m"

clean:
	@rm -f $(OBJS)
	@$(CLIBFT)
	@$(CMLX_L)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_A)
	@rm -rf cub3d.dSYM
	@$(FCLIBFT)
	@echo "\033[1;35m ..::::: Cub3d Deleted  :::::.. \033[0m"

re: fclean all


.PHONY: all clean fclean re re_linux l
