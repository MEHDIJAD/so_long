#include "../so_long.h"

char    *ft_strchr(const char *s, int c)
{
    if (!s) // Handle NULL input
        return (NULL);

    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }

    return ((char)c == '\0' ? (char *)s : NULL); // Ensure NULL safety
}
