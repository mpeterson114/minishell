/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:22:36 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:34:53 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_value(char *new, char *value, int *j)
{
	int	i;

	i = 0;
	while (value[i])
	{
		new[*j] = value[i];
		i++;
		(*j)++;
	}
}

char	*get_new_str(char *old, char *value, int newsize, int p)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * newsize);
	if (!new)
		return (NULL);
	while (old[i])
	{
		if (old[i] == '$' && i == p)
		{
			copy_value(new, value, &j);
			i = i + variable_length(old + p) + 1;
			if (old[i] == '\0')
				break ;
		}
		new[j++] = old[i++];
	}
	new[j] = '\0';
	return (new);
}
