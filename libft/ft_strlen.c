#include "../so_long.h"

size_t	ft_strlen(const char *buf)
{
	size_t	len;

	if (!buf)
		return (0);
	len = 0;
	while (buf[len])
		len++;
	return (len);
}