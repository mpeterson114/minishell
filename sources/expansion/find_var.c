/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:22:10 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:38:08 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	char_is_accept_for_var(char c)
{
	if (ft_isalnum(c) == 0 && c != '_')
		return (false);
	else
		return (true);
}

int	variable_length(char *str)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '$')
		i++;
	i++;
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '?')
		return (cnt + 1);
	while (str[i])
	{
		if (char_is_accept_for_var(str[i]) == false)
			break ;
		cnt++;
		i++;
	}
	return (cnt);
}

char	*find_variable(char *str)
{
	char	*var;
	char	*tmp;
	int		start;
	int		len;
	int		i;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			start = i + 1;
			break ;
		}
		i++;
	}
	len = variable_length(str);
	var = ft_substr(str, start, len);
	if (!var)
		return (NULL);
	tmp = ft_strjoin(var, "=");
	free_ptr(var);
	var = tmp;
	return (var);
}
