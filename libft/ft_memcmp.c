/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:38:17 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:40:04 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_u;
	unsigned char	*s2_u;

	s1_u = (unsigned char *)s1;
	s2_u = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_u[i] != s2_u[i])
			return (s1_u[i] - s2_u[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char str1[20] = "test\200";
    char str2[20] = "test\0";
    size_t n;
    
    n = 5;

    printf("Oficial: %d\n", memcmp(str1, str2 , n));
    printf("Mine: %d\n", ft_memcmp(str1, str2 , n));

    return (0);
}
*/