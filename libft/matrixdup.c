/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:22:36 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/04/11 15:31:38 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**matrixdup(char **arr)
{
	char	**newarr;
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	newarr = ft_calloc(sizeof(char *), i + 1);
	if (!newarr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		newarr[i] = ft_strdup(arr[i]);
		if (!newarr[i])
		{
			free_arr(newarr);
			return (NULL);
		}
		i++;
	}
	newarr[i] = NULL;
	return (newarr);
}
