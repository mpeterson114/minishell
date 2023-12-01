/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:19:33 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/23 08:11:46 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_nbr(int *n, int *is_negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*is_negative = 1;
	}
}

static int	ft_size(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = 0;
	check_nbr(&n, &is_negative);
	size = 1 + ft_size(n);
	size += is_negative;
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	str[--size] = 0;
	while (size--)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

/*
int main(void)
{
	
	printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(1));
    printf("%s\n", ft_itoa(-1));
    printf("%s\n", ft_itoa(-10));
    printf("%s\n", ft_itoa(10));
    printf("%s\n", ft_itoa(8124));
    printf("%s\n", ft_itoa(-9874));
    printf("%s\n", ft_itoa(-2147483648LL));
    printf("%s\n", ft_itoa(214748364));
	
	
	return (0);
}
*/