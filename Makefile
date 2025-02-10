SRCS =  mand/so_long.c \
        get_next_line/get_next_line.c \
        mand/ft_get_map.c \
	mand/ft_tools.c \
	mand/ft_exit.c  \
        mand/ft_get_map_dimention.c \
        mand/ft_get_img_data.c \
        mand/ft_drow_map.c \
        mand/ft_first_move.c \
        mand/ft_get_player_position.c \
        mand/ft_valid_map.c \
	mand/ft_cleanup_game.c \
        mand/ft_checking_tools.c \
	mand/ft_puterror.c \
        mand/ft_put_image.c \
        libft/ft_strlen.c \
        libft/ft_strchr.c \
        libft/ft_calloc.c \
        libft/ft_memcpy.c \
        libft/ft_memset.c \
        libft/ft_bzero.c \
        libft/ft_strdup.c \

BSRCS = bonus/so_long_bonus.c \
        get_next_line/get_next_line.c \
        bonus/ft_get_map_bonus.c \
	bonus/ft_tools_bonus.c \
	bonus/ft_exit_bonus.c  \
        bonus/ft_get_map_dimention_bonus.c \
        bonus/ft_get_img_data_bonus.c \
        bonus/ft_drow_map_bonus.c \
        bonus/ft_first_move_bonus.c \
        bonus/ft_get_player_position_bonus.c \
        bonus/ft_valid_map_bonus.c \
	bonus/ft_cleanup_game_bonus.c \
        bonus/ft_checking_tools_bonus.c \
	bonus/ft_puterror_bonus.c \
        bonus/ft_put_image_bonus.c \
        libft/ft_strlen.c \
        libft/ft_strchr.c \
        libft/ft_calloc.c \
        libft/ft_memcpy.c \
        libft/ft_memset.c \
        libft/ft_bzero.c \
        libft/ft_strdup.c \
        libft/ft_itoa.c \

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror
#-fsanitize=address

MLX = -L/home/eel-garo/includes/mlx/ -lmlx -lX11 -lXext


OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)


INCLUDES = -I includes -I ft_printf -I /home/eel-garo/include/mlx/

FT_PRINTF_DIR = ft_printf
FT_GET_NEXT_LINE_DIR = get_next_line
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

NAME 	= so_long
B_NAME  = so_long_bonus

all : $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(FT_PRINTF_LIB) -o $(NAME)                      

%.o: %.c so_long.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(FT_PRINTF_LIB) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(MLX) $(FT_PRINTF_LIB) -o $(B_NAME)
clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME) $(B_NAME)

run: all clean 

re: fclean all
