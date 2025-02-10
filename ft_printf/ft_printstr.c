/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:31:42 by eel-garo          #+#    #+#             */
/*   Updated: 2024/11/22 17:51:01 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printstr(int fd, char *s)
{
    int count = 0;

    if (s == NULL)
        count += ft_printstr(fd, "(null)");
    else if (s)
    {
        while(*s)
        {
        ft_printchar(fd, (char)*s++);
        count++;
        }
    }
    return (count);
}
