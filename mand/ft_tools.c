/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:30 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/16 11:20:32 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_init(t_data *data)
{
    data->mlx = NULL; 
    data->win = NULL; 
    data->img_hero = NULL;
    data->img_wall = NULL; 
    data->img_floor = NULL; 
    data->img_collact = NULL; 
    data->img_exit = NULL; 
    data->img_widht = 0; 
    data->img_height = 0; 
    data->ptr = NULL ;
    data->relative_path_hero = "/home/eel-garo/Desktop/so_long/textures/1.xpm";
    data->relative_path_wall = "/home/eel-garo/Desktop/so_long/textures/block.xpm";
    data->relative_path_collact = "/home/eel-garo/Desktop/so_long/textures/collectible.xpm";
    data->relative_path_exit = "/home/eel-garo/Desktop/so_long/textures/exit.xpm"; 
    data->relative_path_floor = "/home/eel-garo/Desktop/so_long/textures/space.xpm"; 
    data->x_p = 0;
    data->y_p = 0;
    data->cl = 0;
}

void ft_free_map(char **ptr)
{
    int i;
    if (!ptr)
        return ;
    i = 0;
    while (ptr[i])
    {
        free(ptr[i]);
        ptr[i] = NULL;
        i++;
    }
    free(ptr);
    ptr = NULL;
}


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (i < len && haystack[i])
	{
		j = 0;
		while ((i + j) < len && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
 int ft_check_file_map(char *map_ber)
{
    if (!ft_strnstr(map_ber, ".ber", strlen(map_ber)))
        return (0);
    return (1);
}




