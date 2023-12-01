/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:32:43 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:37:46 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The memchr() function locates the first occurrence of c 
	(converted to an unsigned char) in string s
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}

/*
int main (void) 
{
   const char str[] = "abc.def";
   const char ch = '.';
   char *dest1;
   char *dest2;

   dest1 = memchr(str, ch, 10);
   dest2 = memchr(str, ch, 10);

   printf("String after |%c| is - |%s|\n", ch, dest1);
   printf("String after |%c| is - |%s|\n", ch, dest2);

   return(0);
}
*/
