#include "ft_printf.h"

/*print signed integer and its length*/
int ft_putnbr(int nb)
{
    int len;
    char *num;

    len = 0;
    num = ft_itoa(nb);
    len = ft_printstr(num);
    free(num);
    return (len);
}