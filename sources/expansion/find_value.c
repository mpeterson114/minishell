/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:51:37 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:58:26 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	var_exists(t_shell *sh, char *var)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], var, len) == 0)
			return (true);
		i++;
	}
	return (false);
}

static char	*search_env_var_value(t_shell *sh, char *var)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], var, len) == 0)
			break ;
		i++;
	}
	str = ft_strdup(sh->env[i] + len);
	return (str);
}

char	*find_value(t_token *token, char *str, t_shell *sh)
{
	char	*value;
	char	*var;

	var = find_variable(str);
	if (var && var_exists(sh, var) == true)
	{
		if (token)
			token->is_var = true;
		value = search_env_var_value(sh, var);
	}
	else if (var && var[0] == '?' && var[1] == '=')
		value = ft_itoa(g_sig);
	else
		value = NULL;
	free_ptr(var);
	return (value);
}
