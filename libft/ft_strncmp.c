/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:51:14 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:54:57 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_u;
	unsigned char	*s2_u;

	s1_u = (unsigned char *)s1;
	s2_u = (unsigned char *)s2;
	i = 0;
	while ((s1_u[i] || s2_u[i]) && i < n)
	{
		if (s1_u[i] != s2_u[i])
			return (s1_u[i] - s2_u[i]);
		i++;
	}
	return (0);
}
