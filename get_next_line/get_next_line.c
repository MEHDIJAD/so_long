/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:21:14 by eel-garo          #+#    #+#             */
/*   Updated: 2024/12/05 11:19:10 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_filljoin(char *line, const char *str_buf, const char *buf) //* join two strings
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str_buf[i])
	{
		line[i] = str_buf[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		line[i] = buf[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (line);
}

static char *ft_add(char  *map, char  *buffer)
{
    char *new_buff;
    size_t len;

    if (!map && !buffer)
        return (NULL);
    if (!map)
        return (ft_strdup(buffer)); //!
    if (!buffer)
        return (ft_strdup(map)); //!
    len = ft_strlen(map) + ft_strlen(buffer); //!
    new_buff = malloc((len + 1) * sizeof(char));
    if (!new_buff)
        return (NULL);
    new_buff = ft_filljoin(new_buff, map, buffer);
    free(map);
    return (new_buff);
}


static char	*ft_process_line(char **map_line) //* takes the stat-variable
{
	char		*newline_pos;
	char		*line;
	char		*remaining;

	//!
	newline_pos = ft_strchr(*map_line, '\n'); //* check again for new line  
	if (newline_pos) //* if we have new line == newline_pos != NULL
	{
		*newline_pos = '\0'; //??
		line = ft_strdup(*map_line); //* copy the line befor '\n'
		remaining = ft_strdup(newline_pos + 1); //* copy the reaning str after '\n'
		free(*map_line); //* free the part of stat-variable after coping 
		*map_line = remaining; //* so we can give it the remaining part of string  
		return (line); //* we return the line 
	}
	//* the second conditin in case we do not have a new line but we stel have someting remaining 
	if (*map_line && **map_line) //! check if *map_line != NULL (sroting something) && **map_line != NULL string not empty == ""
	{
		line = ft_strdup(*map_line); 
		free(*map_line);
		*map_line = NULL;
		return (line);
	}
	return (free(*map_line), *map_line = NULL, NULL);
}

static int	ft_read_and_store(int fd, char **map_line, char *buffer) //TODO fd to read from, static variable, and buffer to read from 
{
	ssize_t	bytes_read;
	char	*newline_pos; //! a variable to determen if we fond new line or not !!

	while (1)
	{
		if (*map_line) //* if we have i something 
			newline_pos = ft_strchr(*map_line, '\n');  //* returns a pointer to the first occurrence of '\n' in *map_line
		else
			newline_pos = NULL; //* if we do not have static variable it will set the newline_pos to NULL 
		if (newline_pos) //* == not NULL ==> it did find '\n' in static variable it return 1 == line is done reading 
			return (1);
		bytes_read = read(fd, buffer, BUFFER_SIZE); //* we read into buffer
		if (bytes_read <= 0) //* if we get to EOF or error return bytes read 
			return (bytes_read); //* were are we in reading  //?
		buffer[bytes_read] = '\0'; //* put '\0' at the end 
		*map_line = ft_add(*map_line, buffer); //* add the part read to stat-variable
	}
	return (0); //?
}

char	*get_next_line(int fd)
{
	static char	*map_line;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //* allocat for static variable
	if (!buffer)
		return (NULL); //* if allcation faild
	bytes_read = ft_read_and_store(fd, &map_line, buffer); //* read and store into map_line
	free(buffer); //? we free buffer after finish ??
	if (bytes_read < 0 || !map_line) //?
		return (free(map_line), map_line = NULL, NULL); //?we finish reading the line ??
	return (ft_process_line(&map_line)); //* seperat to line and left over 
}