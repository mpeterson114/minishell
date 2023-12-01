/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:28:22 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/23 11:28:25 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}

/*
#include <stdio.h>

void	my_func(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
		printf("index = %d and the string = %s\n", i, c);
	}
	else if (*c >= 'A' && *c <= 'Z')
	{
		*c += 32;
		printf("index = %d and the string = %s\n", i, c);
	}
}

int main(void)
{
	char str[10] = "hELL0.";
	printf("The original string is %s\n", str);
	ft_striteri(str, my_func);
	printf("The result string is %s\n", str);
	return 0;
}
*/
