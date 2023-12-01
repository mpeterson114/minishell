/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:24:23 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/22 12:28:09 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
		*((unsigned char *)(b + i++)) = (unsigned char)c;
	return (b);
}

/*
int main(void)
{
    char str1[50] = "12345678912345678123456789";
    char str2[50] = "12345678912345678123456789";

    printf("\nBefore memset(): %s\n", str1);
    memset(str1 + 9, '.', 8 * sizeof(char));
    printf("After memset():  %s", str1);

    printf("\nBefore memset(): %s\n", str2);
    ft_memset(str2 + 9, '.', 8 * sizeof(char));
    printf("After memset():  %s", str2);

    return 0;
}
*/