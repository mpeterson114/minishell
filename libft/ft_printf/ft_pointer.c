#include "ft_printf.h"

/*prints pointer's address in hexadecimal format plus the prefix string "Ox" and its total length*/
int ft_pointer(unsigned long long nb, char *base)
{
    int i;

    i = ft_printstr("0x") + ft_hex(nb, base);
    return (i);
}
