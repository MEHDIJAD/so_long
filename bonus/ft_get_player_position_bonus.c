/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:05 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/16 11:20:07 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_get_player_position(t_data *data)
{
    int i;
    int j;

    i = 0;
    while(data->ptr[i])
    {
        j = 0;
        while(data->ptr[i][j])
        {
            if (data->ptr[i][j] == 'P')
            {
                data->x_p = j;
                data->y_p = i;

            }
            j++;
        }
        i++;
    }
}
