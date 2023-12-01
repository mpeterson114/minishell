/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:34:42 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/22 15:49:10 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (start > i)
		len = 0;
	if (len > i - start)
		len = i - start;
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (len--)
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}
