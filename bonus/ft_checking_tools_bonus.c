/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:18:07 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/16 11:18:11 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_surrounded_by_walls_check(t_data *data)
{
    int x;
    int y;

    x = 0;
    while(x < data->x && data->ptr[x])
    {
        y = 0;
        while (y < data->y && data->ptr[x][y])
        {
            if ((x == 0 || x == data->x - 1 || y == 0 || y == data->y - 1 ) &&
            (!data->ptr[x][y] || data->ptr[x][y] != '1'))
            {
                return (0);
            }
            y++;
        }
        x++;
    }
    return (1);
}
int  ft_check_components(t_data *data)
{
    t_param param;
    int i;
    int j;

    i = 0;
    while (data->ptr[i])
    {
        j = 0;
        while (data->ptr[i][j])
        {
            if (data->ptr[i][j] == 'P')
                param.player = true;
            if (data->ptr[i][j] == 'C')
                param.collact = true;
            if (data->ptr[i][j] == 'E')
                param.exit = true;
            if (data->ptr[i][j] == '0')
                param.space = true;
            if (data->ptr[i][j] == '1')
                param.wall = true;
            j++;
        }
        i++;
    }
    return (param.player && param.collact && param.exit && param.space && param.wall);
}
int ft_min_components(t_data *data)
{
    int i; 
    int j;
    int player;
    int exit;
    i = 0;
    player = 0;
    exit = 0;
    while (data->ptr[i])
    {
        j = 0;
        while (data->ptr[i][j])
        {
            if (data->ptr[i][j] == 'P')
                player++;
            if (data->ptr[i][j] == 'E')
                exit++;
            j++;
        }
        i++;
    }
    return (player < 2 && exit < 2);
}

int small_check(t_data *data)
{
    int x;
    int y;

    if (!data->ptr[0] || !data->ptr)
        return (0);
    x = 0;
    while (data->ptr[x])
    {
        y = 0;
        while(data->ptr[x][y])
        {
            if (data->ptr[x][y] != '1' && data->ptr[x][y] != '0' 
            && data->ptr[x][y] != 'P' && data->ptr[x][y] != 'C' 
            && data->ptr[x][y] != 'E' && data->ptr[x][y] != ' '
            && data->ptr[x][y] != '\n')
            {
                return (0);
            }
            y++;
        }
        x++;
    }
    return (1);
}
int ft_rectangular_check(t_data *data)
{
    size_t len;
    int x;

    if (!data->ptr || !data->ptr[0])
        return (0);
    len = ft_strlen(data->ptr[0]);
    x = 1;
    while(x < data->x && data->ptr[x])
    {
        if (ft_strlen(data->ptr[x]) != len)
        {
            return (0);
        }
        x++;
    }
    if (x != data->x)
        return (0);
    return (1);
}
