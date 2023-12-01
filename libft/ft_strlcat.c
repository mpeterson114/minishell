/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:46:16 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:47:44 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	pos;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	i = 0;
	pos = dstlen;
	while (src[i] && i < (dstsize - dstlen - 1))
	{
		dst[pos++] = src[i++];
	}
	dst[pos] = '\0';
	return (dstlen + srclen);
}

/*
int main (void) 
{
   char src1[30] = "ABCDEF";
   char dst1[30] = "123456789";
   char src2[30] = "ABCDEF";
   char dst2[30] = "123456789";
   size_t len1 = strlcat(dst1, src1, 11);
   size_t len2 = ft_strlcat(dst2, src2, 11);
   printf("Original: \n");
   printf("Source: %s\n", src1);
   printf("Destination: %s\n", dst1);
   printf("Length: %zu\n\n", len1);
   
   printf("New: \n");
   printf("Source: %s\n", src2);
   printf("Destination: %s\n", dst2);
   printf("Length: %zu\n\n", len2);
   
   return(0);
}
*/
