/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:43 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/16 11:20:46 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

static void ft_free_copy(char **copy, int i)
{
    if (!copy)
        return ;

    while (i >= 0)
    {
        if (copy[i])
        {
            free(copy[i]);
            copy[i] = NULL;
        }
        i--;
    }
    free(copy);
    copy = NULL;
}

static int ft_flood_fill(char **map,int x, int y)
{
    int  i; 

    i = 0;
    if (map[x][y] == '1')
        return (0);
    if (map[x][y] == 'E')
        return (map[x][y] = '1', 1);
    if (map[x][y] == 'C')
        i++;
    map[x][y] = '1';
    i += ft_flood_fill(map, x + 1, y);
    i += ft_flood_fill(map, x - 1, y);
    i +=  ft_flood_fill(map, x, y + 1);
    i +=  ft_flood_fill(map, x, y - 1);
    return (i);
}
int ft_playable_map(t_data *data)
{
    char **map_copy;
    int i;

    i = 0;
    map_copy = ft_calloc(sizeof(char *) , data->x + 1); //?
    if (!map_copy)
        return (0);
    while(i < data->x && data->ptr[i])
    {
        map_copy[i] = strdup(data->ptr[i]);
        if (!map_copy[i])
            return (ft_free_copy(map_copy, i), 0);
        i++;
    }
    map_copy[data->x] = NULL;
    ft_get_player_position(data);
    int h = ft_flood_fill(map_copy,data->y_p, data->x_p);

    if ( h != data->cl + 1)
    {
        return (ft_free_map(map_copy),0);
    }
    i = 0;
    while (i < data->x)
        free(map_copy[i++]);
    free(map_copy);
    return (1);
}
int ft_valid_map(t_data *data)
{
    if (data->x > 25 || data->y > 61)
        return (ft_puterror(1), 0);
    if (!ft_check_components(data))
        return (ft_puterror(2), 0); 
    if (!ft_min_components(data))
        return (ft_puterror(3), 0);
    if (!small_check(data))
        return (ft_puterror(4), 0);
    if (!ft_rectangular_check(data))
        return (ft_puterror(5), 0);
    if (!ft_surrounded_by_walls_check(data))
        return (ft_puterror(6), 0);
    if (!ft_playable_map(data))
        return (ft_puterror(7), 0);
    return (1);    
}