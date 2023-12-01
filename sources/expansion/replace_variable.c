/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:24:45 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:38:56 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	erase_variable(t_token **node, char *str, int pos)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	len = ft_strlen(str) - variable_length(str + pos);
	new_str = (char *)malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (FAILURE);
	while (str[i])
	{
		if (str[i] == '$' && i == pos)
		{
			i = i + variable_length(str + pos) + 1;
			if (str[i] == '\0')
				break ;
		}
		new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	free_ptr((*node)->content);
	(*node)->content = new_str;
	return (OK);
}

static char	*erase_and_replace(t_token **node, char *str,
			char *value, int pos)
{
	char	*new;
	int		newsize;

	newsize = (ft_strlen(str) - variable_length(str + pos)
			+ ft_strlen(value));
	new = get_new_str(str, value, newsize, pos);
	if (node && *node)
	{
		free_ptr((*node)->content);
		(*node)->content = new;
	}
	return (new);
}

int	replace_variable(t_token **node, char *value, int pos)
{
	if (!value)
	{
		if (erase_variable(node, (*node)->content, pos) == FAILURE)
		{
			free_ptr(value);
			return (FAILURE);
		}
	}
	else
	{
		if (erase_and_replace(node, (*node)->content, \
		value, pos) == NULL)
		{
			free_ptr(value);
			return (1);
		}
	}
	free_ptr(value);
	return (0);
}

char	*replace_str_heredoc(char *str, char *var_value, int index)
{
	char	*tmp;

	tmp = NULL;
	if (var_value == NULL)
		*str = '\0';
	else
	{
		tmp = str;
		str = erase_and_replace(NULL, str, var_value, index);
		free_ptr(tmp);
	}
	free_ptr(var_value);
	return (str);
}
