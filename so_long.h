/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:10:52 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/10 11:10:53 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

# ifndef IMAGE_SIZE 
#  define IMAGE_SIZE 32
# endif

# define SIZE_MAX 18446744073709551615ULL
# define OPEN_MAX 1024

#include "/home/eel-garo/includes/mlx/mlx.h" 

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //!
#include <string.h> //!
#include <fcntl.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <limits.h>
#include "ft_printf.h"

typedef struct s_data
{
    void *mlx;
    void *win;
    void *img_hero;
    void *img_wall;
    void *img_floor;
    void *img_collact;
    void *img_exit;
    int img_widht; 
    int img_height;
    char **ptr;
    int x;
    int y;
    char *relative_path_hero;
    char *relative_path_wall;
    char *relative_path_floor;
    char *relative_path_collact;
    char *relative_path_exit;
    int x_p;
    int y_p;
    int cl;
} t_data;

typedef struct s_param
{
    bool player;
    bool exit;
    bool collact;
    bool wall;
    bool space;
} t_param;

char	*get_next_line(int fd);

//*mand
int		ft_get_map(char *str, t_data *data);
void	ft_get_map_dimention(t_data *data);
int		ft_get_img_data(t_data *data);
void	ft_drow_map(t_data *data);
int		ft_first_move(int keycode, t_data *data);
void	ft_get_player_position(t_data *data);
int		ft_valid_map(t_data *data);
void	ft_cleanup_game(t_data *data);
void	ft_free_map(char **ptr);
int		ft_exit(t_data *data);
int     ft_surrounded_by_walls_check(t_data *data);
int     ft_check_components(t_data *data);
int     small_check(t_data *data);
int     ft_rectangular_check(t_data *data);
int     ft_min_components(t_data *data);
int     ft_check_file_map(char *map_ber);
void    ft_puterror(int error_code);
int     ft_playable_map(t_data *data);
void    ft_put_image(t_data *data, int i, int j, char c);
void    ft_init(t_data *data);

//*bonus


//* libft
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
void    *ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *buf);
char    *ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);


#endif