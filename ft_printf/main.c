#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main() 
{
    int ret1, ret2;

    // Test %c
    ret1 = ft_printf("ft_printf: %c\n", 'A');
    ret2 = printf("printf   : %c\n", 'A');
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %s
    ret1 = ft_printf("ft_printf: %s\n", "Hello, world!");
    ret2 = printf("printf   : %s\n", "Hello, world!");
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %p
    void *ptr = &ret1;
    ret1 = ft_printf("ft_printf: %p\n", ptr);
    ret2 = printf("printf   : %p\n", ptr);
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %d
    ret1 = ft_printf("ft_printf: %d\n", -12345);
    ret2 = printf("printf   : %d\n", -12345);
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %i
    ret1 = ft_printf("ft_printf: %i\n", 12345);
    ret2 = printf("printf   : %i\n", 12345);
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %u
    ret1 = ft_printf("ft_printf: %u\n", 4294967295U);
    ret2 = printf("printf   : %u\n", 4294967295U);
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %x
    ret1 = ft_printf("ft_printf: %x\n", 255);
    ret2 = printf("printf   : %x\n", 255);
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %X
    ret1 = ft_printf("ft_printf: %X\n", 255);
    ret2 = printf("printf   : %X\n", 255);
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test %%
    ret1 = ft_printf("ft_printf: %%\n");
    ret2 = printf("printf   : %%\n");
    printf("Returned: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    return 0;
}
