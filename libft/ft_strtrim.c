/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:09:10 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/22 15:48:08 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*trimmed;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i] && is_in_set(set, s1[i]))
		i++;
	while ((len - 1) && is_in_set(set, s1[len - 1]))
		len--;
	if (len < i)
		len = i;
	trimmed = malloc(sizeof(char) * (len - i) + 1);
	if (trimmed == NULL)
		return (NULL);
	while (i < len)
		trimmed[j++] = s1[i++];
	trimmed[j] = 0;
	return (trimmed);
}
