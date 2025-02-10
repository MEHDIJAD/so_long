/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:55:56 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/10 12:55:58 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int helper_function(t_data *data , int map_height, char *str)
{
    int i;
    char *line;
    int fd;

    data->ptr = malloc(sizeof(char *) * (map_height + 1));
    if (!data->ptr)
        return (ft_printf(2, "💀Error\nMemory allocation failed"), free(data->ptr), exit(0), 1);
    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (ft_printf(2, "💀Error reopening file"), free(data->ptr), 1);
    i = 0;
    while ((line = get_next_line(fd)))
    {
        data->ptr[i] = line;
        if (!data->ptr[i])
        {
            ft_printf(2, "Memory allocation failed during reading");
            close(fd);
            ft_exit(data);
        }
        i++;
    }
    data->ptr[i] = NULL;
    return (close(fd), 0);
}

int ft_get_map(char *str, t_data *data)
{
    int fd;
    int map_height;
    char *line;
    
    map_height = 0; 
    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (ft_printf(2, "💀Error\ncan't opening file\n"), 0);
    while ((line = get_next_line(fd)))
    {
        map_height++;
        free(line);
    }
    close(fd);
    if (map_height == 0)
        return (ft_printf(2, "💀Error\nEmpty map file\n"),0);
    if (!helper_function(data, map_height, str))
        return (1);
    return (0);
}
