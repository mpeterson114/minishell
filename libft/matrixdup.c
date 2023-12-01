/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:22:36 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:56:42 by ilzhabur         ###   ########.fr       */
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
