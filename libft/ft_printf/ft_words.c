#include "ft_printf.h"

/*prints a single character*/
int	ft_putchar(char c)
{
	int	i;
	
	i = 0;
	write(1, &c, 1);
	return (i + 1);
}

/*writes string with void return value (needed for placement of null string)*/
void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

/*prints a string and its length with return value of int*/
int	ft_printstr(char *str)
{
	int	i;
	
	i = 0;
    if (str == NULL)
    {
        ft_putstr("(null)");
        return (6);
    }
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}
