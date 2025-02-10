/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:19:00 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/16 11:19:02 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_update_map(t_data *data, int old_x, int old_y, int new_x, int new_y)
{
    ft_put_image(data, old_y, old_x, '0');
    ft_put_image(data,new_y, new_x, 'P');
}


 void put_move(t_data *data, int new_y, int new_x, int *movement_count)
{
    char next_pos;
    char *movement_countstr;
    next_pos = data->ptr[new_y][new_x];
    if (next_pos == 'C')
        data->cl--;
    else if (next_pos == 'E')
    {
        if (data->cl != 0)
            return;
        if (data->cl == 0)
           ft_exit(data);
    }
    if (next_pos != '1')
    {
        ft_update_map(data, data->x_p, data->y_p, new_x, new_y);
        data->ptr[data->y_p][data->x_p] = '0';
        data->ptr[new_y][new_x] = 'P';
        data->y_p = new_y;
        data->x_p = new_x;
        (*movement_count)++;
        ft_drow_map(data);
        mlx_put_image_to_window(data->mlx, data->win, data->img_hero, data->x_p * IMAGE_SIZE, data->y_p * IMAGE_SIZE);
        mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Movements: ");
        movement_countstr = ft_itoa(*movement_count);
        mlx_string_put(data->mlx, data->win, 100, 10, 0xFFFFFF, movement_countstr);
        free(movement_countstr);
    }
}
int ft_first_move(int keycode, t_data *data)
{
    static int movement_count;

    ft_get_player_position(data);

    if (keycode == XK_Escape)
        ft_exit(data);
    if (keycode == XK_Right)
        put_move(data, data->y_p, data->x_p + 1, &movement_count);
    if (keycode == XK_Left)
        put_move(data, data->y_p, data->x_p - 1, &movement_count);
    if (keycode == XK_Down)
        put_move(data, data->y_p + 1, data->x_p, &movement_count);
    if (keycode == XK_Up)
        put_move(data, data->y_p - 1, data->x_p, &movement_count);
    return (0);
}
