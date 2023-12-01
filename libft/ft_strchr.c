/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:44:15 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:45:45 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main (void) 
{
   const char str[] = "This is just a String"; 
   const char ch = 'b'; 
   char *p;
   char *p2;
   p = strchr(str, ch);
   p2 = strchr(str, ch);
   printf("%s\n", p);
   printf("%s\n", p2);
   return 0;
}
*/