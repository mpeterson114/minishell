/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:53:36 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:52:56 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	no_quotes(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			return (false);
		i++;
	}
	return (true);
}

bool	is_var_no_quotes(t_token *tokens, int index)
{
	t_token	*lst;

	lst = tokens;
	while (lst->next)
	{
		if (lst->index == index)
		{
			if (lst->type == VAR && no_quotes(lst->cc))
				return (true);
		}
		lst = lst->next;
	}
	return (false);
}

static void	count_new_len(const char *s, int i, int *newlen, int len)
{
	while (i < len)
	{
		if (!is_space(s[i]) || (i > 0 && !is_space(s[i - 1])))
			(*newlen)++;
		i++;
	}
}

char	*remove_extra_spaces(const char *s)
{
	char	*new_str;
	int		new_len;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	new_len = 0;
	count_new_len(s, i, &new_len, len);
	new_str = malloc((new_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!is_space(s[i]) || (i > 0 && !is_space(s[i - 1])))
		new_str[j++] = s[i];
		i++;
	}
	while (j > 0 && is_space(new_str[j - 1]))
		j--;
	new_str[j] = '\0';
	return (new_str);
}
