/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:42:34 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:43:23 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*((char *)(dst + len)) = *((char *)(src + len));
	}
	return (dst);
}

/*
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int        main(void)
{
	
	
    char    src[] = "lorem ipsum dolor sit amet";
    char    *dest;
	
	dest = src + 1;
	ft_memmove(dest, src, 0);
	write(1, dest, 22);
	
	
    
    return (0);
}
*/