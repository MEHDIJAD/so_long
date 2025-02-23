/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:14:06 by eel-garo          #+#    #+#             */
/*   Updated: 2024/11/22 17:50:40 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_format(int fd, char format_specifier, va_list ap)
{
    int count;

    count = 0;
    if (format_specifier == 'c')
       count+= ft_printchar(fd, va_arg(ap, int));
    else if (format_specifier == 's')
        count+= ft_printstr(fd, va_arg(ap, char *));
    // else if (format_specifier == 'p')
    // {
    //     unsigned long ptr = (unsigned long)(va_arg(ap, void *));
    //     count += ft_printstr(fd,"0x");
    //     count += ft_printdigit(ptr, 16, "0123456789abcdef");
    // }
    else if (format_specifier == 'd' || format_specifier == 'i')
        count+= ft_printdigit(fd, va_arg(ap, int), 10, "0123456789");
    // else if (format_specifier == 'u')
    //     count+= ft_printdigit(va_arg(ap, unsigned int), 10, "0123456789");
    // else if (format_specifier == 'x')
    //     count+= ft_printdigit(va_arg(ap, unsigned int), 16, "0123456789abcdef");
    // else if (format_specifier == 'X')
    //     count+= ft_printdigit(va_arg(ap, unsigned int), 16, "0123456789ABCDEF");
    // else if (format_specifier == '%')
    //     count += ft_printchar(fd , '%');
    return (count);

}

