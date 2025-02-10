/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:50:13 by eel-garo          #+#    #+#             */
/*   Updated: 2024/11/22 17:50:26 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int     ft_printf(int fd, const char *format, ...);
int     ft_print_format(int fd, char format_specifier, va_list ap);
int     ft_printchar(int fd, int c);
int     ft_printstr(int fd, char *s);
int     ft_printdigit(int fd, long number, int base, char *base_symbols);
// int     ft_printhex(unsigned long number, int base, char *base_symbols);

# endif
