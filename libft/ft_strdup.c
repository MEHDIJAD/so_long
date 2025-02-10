#include "../so_long.h"

char    *ft_strdup(const char *s1)
{
    size_t  size;
    char    *cpy;

    if (!s1) // Protect against NULL input
        return (NULL);

    size = ft_strlen(s1); 
    cpy = malloc(sizeof(char) * (size + 1));  // +1 for '\0'
    if (!cpy)
        return (NULL);

    ft_memcpy(cpy, s1, size);
    cpy[size] = '\0'; // Ensure null termination

    return (cpy);
}
