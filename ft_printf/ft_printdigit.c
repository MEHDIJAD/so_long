/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:32:00 by eel-garo          #+#    #+#             */
/*   Updated: 2024/11/22 17:50:50 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printdigit(int fd, long number, int base, char *base_symbols)
{
    unsigned long   n;
    int             count;

    count = 0;

    if (number < 0 && base == 10)
    {
        count+= ft_printchar(fd ,'-');
        n = -number;
    }
    else
    {
        n = (unsigned long)number;
    }
    if (n >= (unsigned long)base)
    {
        count += ft_printdigit(fd, (n / base), base, base_symbols);
    }
    count += ft_printchar(fd, base_symbols[n % base]);
    return (count);
}
