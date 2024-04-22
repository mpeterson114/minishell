#include "ft_printf.h"

/*get length of unsigned number*/
int ft_unsigned_len(unsigned int nb)
{
    int length;

    length = 0;
    if (nb == 0)
        length = 1;
    while (nb != 0)
    {
        length++;
        nb = nb / 10; 
    }
    return (length);
}

/*convert unsigned number to string to count length*/
char    *ft_uitoa(unsigned int nb)
{
	int	len;
	char			*num;

	len = ft_unsigned_len(nb);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	if (nb == 0)
		num[0] = '0';
	num[len] = '\0';
	while (nb != 0)
	{
		num[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (num);
}

/*print unsigned integer and length*/
int ft_unsigned(unsigned int nb)
{
    int len;
    char    *num;

    len = 0;
    num = ft_uitoa(nb);
    len = ft_printstr(num);
    free(num);
    return (len);
}
