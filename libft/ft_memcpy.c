/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:40:52 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:41:43 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/*
int main(void)
{
    char s[5]={'s','a','\0','c','h'};
    int i;

    char membuff1[5];
    char membuff2[5];
    memset(membuff1, 0, 5); // init both buffers to nulls
    memset(membuff2, 0, 5);

    memcpy(membuff1, s, 5);
    ft_memcpy(membuff2, s, 5);

    i = 0;
    while (i < 5)
    {
        printf("%c ", membuff1[i]);
        i++;
    }
    printf("\n");

    i = 0;
    while (i < 5)
    {
        printf("%c ", membuff2[i]);
        i++;
    }
    printf("\n");

    return 0;
}
*/