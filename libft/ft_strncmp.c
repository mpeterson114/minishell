/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:56:46 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/20 10:45:14 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares the first 'n' bytes of the given strings 's1' and 's2'
	Returns 0 if the two strings are identical, otherwise returns the 
	difference between the first two differing bytes (treated as unsigned char) */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0 || (!s1 && !s2))
	{
		return (0);
	}
	while (i < n -1 && (s1[i] == s2[i]) && s1[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
