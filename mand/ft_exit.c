#include "../so_long.h"

int ft_exit(t_data *data)
{
    ft_cleanup_game(data);
    exit(0);
} 