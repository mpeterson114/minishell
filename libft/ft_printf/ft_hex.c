#include "ft_printf.h"

/*get length of number*/
int ft_hex_length(unsigned long long nb)
{
    int len;

    len = 0;
    if (nb == 0)
        len = 1;
    while (nb != 0)
    {
        len++;
        nb = nb / 16;
    }
    return (len);
}

/*convert number to hexadecimal format*/
void ft_convert_hex(unsigned long long nb, char *base)
{
    if (nb >= 16)
    {
        ft_convert_hex(nb / 16, base);
        ft_convert_hex(nb % 16, base);
    }
    else
        write(1, &base[nb], 1);
}

/*prints hexadecimal representation of number and its length*/
int ft_hex(unsigned long long nb, char *base)
{
    if (nb == 0)
        write(1, "0", 1);
    else
        ft_convert_hex(nb, base);
    return (ft_hex_length(nb));  
}
